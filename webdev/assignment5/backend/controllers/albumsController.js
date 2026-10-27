const db = require('../db');

//GET /albums -> fetch all albums joined with artist name
const getAllAlbums = (req, res) => {
db.all(
    'SELECT albums.*, artists.name AS artist_name FROM albums JOIN artists ON albums.artist_id = artists.id ORDER BY albums.listens DESC',
        [],
        (err, rows) => {
            if (err) return res.status(500).json({ error: err.message });
            res.json(rows);
        }
    );
};

//GET /albums/:id -> fetch a single album by id
const getAlbumById = (req, res) => {
    const { id } = req.params;
    db.get(
        'SELECT albums.*, artists.name AS artist_name FROM albums JOIN artists ON albums.artist_id = artists.id WHERE albums.id = ?',
        [id],
        (err, row) => {
            if (err) return res.status(500).json({ error: err.message });
            if (!row) return res.status(404).json({ error: 'Album not found.' });
            res.json(row);
        }
    );
};

//POST /albums -> create a new album
const createAlbum = (req, res) => {
    const { name, release_year, listens, artist_id } = req.body;
    //validate that required fields are present
    if (!name || !release_year || !artist_id) {
        return res.status(400).json({ error: 'name, release_year, and artist_id are required.' });
    }
    //check artist exists before inserting
    db.get('SELECT id FROM artists WHERE id = ?', [artist_id], (err, row) => {
        if (err) return res.status(500).json({ error: err.message });
        if (!row) return res.status(404).json({ error: 'Artist not found.' });
        db.run(
            'INSERT INTO albums (name, release_year, listens, artist_id) VALUES (?, ?, ?, ?)',
            [name, release_year, listens || 0, artist_id],
            function(err) {
                if (err) return res.status(500).json({ error: err.message });
                //return the newly created album with artist name
                db.get(
                    'SELECT albums.*, artists.name AS artist_name FROM albums JOIN artists ON albums.artist_id = artists.id WHERE albums.id = ?',
                    [this.lastID],
                    (err, row) => {
                        if (err) return res.status(500).json({ error: err.message });
                        res.status(201).json(row);
                    }
                );
            }
        );
    });
};

//PUT /albums/:id -> update an existing album
const updateAlbum = (req, res) => {
    const { id } = req.params;
    const { name, release_year, listens, artist_id } = req.body;
    db.get('SELECT * FROM albums WHERE id = ?', [id], (err, row) => {
        if (err) return res.status(500).json({ error: err.message });
        if (!row) return res.status(404).json({ error: 'Album not found.' });
        //fall back to existing values for any fields not provided
        const updatedName = name ?? row.name;
        const updatedYear = release_year ?? row.release_year;
        const updatedListens = listens ?? row.listens;
        const updatedArtistId = artist_id ?? row.artist_id;
        db.run(
            'UPDATE albums SET name = ?, release_year = ?, listens = ?, artist_id = ? WHERE id = ?',
            [updatedName, updatedYear, updatedListens, updatedArtistId, id],
            function(err) {
                if (err) return res.status(500).json({ error: err.message });
                //return the updated album with artist name
                db.get(
                    'SELECT albums.*, artists.name AS artist_name FROM albums JOIN artists ON albums.artist_id = artists.id WHERE albums.id = ?',
                    [id],
                    (err, updated) => {
                        if (err) return res.status(500).json({ error: err.message });
                        res.json(updated);
                    }
                );
            }
        );
    });
};

//DELETE /albums/:id -> delete an album (cascades to songs)
const deleteAlbum = (req, res) => {
    const { id } = req.params;
    db.get('SELECT * FROM albums WHERE id = ?', [id], (err, row) => {
        if (err) return res.status(500).json({ error: err.message });
        if (!row) return res.status(404).json({ error: 'Album not found.' });
        db.run('DELETE FROM albums WHERE id = ?', [id], function(err) {
            if (err) return res.status(500).json({ error: err.message });
            res.json({ message: 'Album deleted successfully.' });
        });
    });
};

module.exports = { getAllAlbums, getAlbumById, createAlbum, updateAlbum, deleteAlbum };