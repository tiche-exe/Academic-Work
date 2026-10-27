const db = require('../db');

//GET /songs -> fetch all songs joined with album and artist name
const getAllSongs = (req, res) => {
    db.all(
        `SELECT songs.*, albums.name AS album_name, artists.name AS artist_name
        FROM songs
        JOIN albums ON songs.album_id = albums.id
        JOIN artists ON albums.artist_id = artists.id
        ORDER BY albums.listens DESC, songs.id ASC`,
        [],
        (err, rows) => {
            if (err) return res.status(500).json({ error: err.message });
            res.json(rows);
        }
    );
};

//GET /songs/:id -> fetch a single song by id
const getSongById = (req, res) => {
    const { id } = req.params;
    db.get(
        `SELECT songs.*, albums.name AS album_name, artists.name AS artist_name
         FROM songs
         JOIN albums ON songs.album_id = albums.id
         JOIN artists ON albums.artist_id = artists.id
         WHERE songs.id = ?`,
        [id],
        (err, row) => {
            if (err) return res.status(500).json({ error: err.message });
            if (!row) return res.status(404).json({ error: 'Song not found.' });
            res.json(row);
        }
    );
};

//POST /songs -> create a new song
const createSong = (req, res) => {
    const { name, release_year, album_id } = req.body;
    //validate that required fields are present
    if (!name || !release_year || !album_id) {
        return res.status(400).json({ error: 'name, release_year, and album_id are required.' });
    }
    //check album exists before inserting
    db.get('SELECT id FROM albums WHERE id = ?', [album_id], (err, row) => {
        if (err) return res.status(500).json({ error: err.message });
        if (!row) return res.status(404).json({ error: 'Album not found.' });
        db.run(
            'INSERT INTO songs (name, release_year, album_id) VALUES (?, ?, ?)',
            [name, release_year, album_id],
            function(err) {
                if (err) return res.status(500).json({ error: err.message });
                //return the newly created song with album and artist name
                db.get(
                    `SELECT songs.*, albums.name AS album_name, artists.name AS artist_name
                     FROM songs
                     JOIN albums ON songs.album_id = albums.id
                     JOIN artists ON albums.artist_id = artists.id
                     WHERE songs.id = ?`,
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

//PUT /songs/:id -> update an existing song
const updateSong = (req, res) => {
    const { id } = req.params;
    const { name, release_year, album_id } = req.body;
    db.get('SELECT * FROM songs WHERE id = ?', [id], (err, row) => {
        if (err) return res.status(500).json({ error: err.message });
        if (!row) return res.status(404).json({ error: 'Song not found.' });
        //fall back to existing values for any fields not provided
        const updatedName = name ?? row.name;
        const updatedYear = release_year ?? row.release_year;
        const updatedAlbumId = album_id ?? row.album_id;
        db.run(
            'UPDATE songs SET name = ?, release_year = ?, album_id = ? WHERE id = ?',
            [updatedName, updatedYear, updatedAlbumId, id],
            function(err) {
                if (err) return res.status(500).json({ error: err.message });
                //return the updated song with album and artist name
                db.get(
                    `SELECT songs.*, albums.name AS album_name, artists.name AS artist_name
                     FROM songs
                     JOIN albums ON songs.album_id = albums.id
                     JOIN artists ON albums.artist_id = artists.id
                     WHERE songs.id = ?`,
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

//DELETE /songs/:id -> delete a song
const deleteSong = (req, res) => {
    const { id } = req.params;
    db.get('SELECT * FROM songs WHERE id = ?', [id], (err, row) => {
        if (err) return res.status(500).json({ error: err.message });
        if (!row) return res.status(404).json({ error: 'Song not found.' });
        db.run('DELETE FROM songs WHERE id = ?', [id], function(err) {
            if (err) return res.status(500).json({ error: err.message });
            res.json({ message: 'Song deleted successfully.' });
        });
    });
};

module.exports = { getAllSongs, getSongById, createSong, updateSong, deleteSong };