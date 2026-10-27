const db = require('../db');

//GET /artists -> fetch and return all artists
const getAllArtists = (req, res) => {
    db.all('SELECT * FROM artists ORDER BY monthly_listeners DESC', [], (err, rows) => {
        if (err) return res.status(500).json({ error: err.message });
        res.json(rows);
    });
};

//GET /artists/:id -> fetch a single artist by id
const getArtistById = (req, res) => {
    const { id } = req.params;
    db.get('SELECT * FROM artists WHERE id = ?', [id], (err, row) => {
        if (err) return res.status(500).json({ error: err.message });
        //return 404 if no artist found with that id
        if (!row) return res.status(404).json({ error: 'Artist not found.' });
        res.json(row);
    });
};

//POST /artists -> create a new artist
const createArtist = (req, res) => {
    const { name, genre, monthly_listeners } = req.body;
    //validate that required fields are present
    if (!name || !genre) {
        return res.status(400).json({ error: 'name and genre are required.' });
    }
    db.run(
        'INSERT INTO artists (name, genre, monthly_listeners) VALUES (?, ?, ?)',
        [name, genre, monthly_listeners || 0],
        function(err) {
            if (err) return res.status(500).json({ error: err.message });
            //fetch and return the newly created artist
            db.get('SELECT * FROM artists WHERE id = ?', [this.lastID], (err, row) => {
                if (err) return res.status(500).json({ error: err.message });
                res.status(201).json(row);
            });
        }
    );
};

//PUT /artists/:id -> update an existing artist
const updateArtist = (req, res) => {
    const { id } = req.params;
    const { name, genre, monthly_listeners } = req.body;
    //check artist exists before updating
    db.get('SELECT * FROM artists WHERE id = ?', [id], (err, row) => {
        if (err) return res.status(500).json({ error: err.message });
        if (!row) return res.status(404).json({ error: 'Artist not found.' });
        //fall back to existing values for any fields not provided
        const updatedName = name ?? row.name;
        const updatedGenre = genre ?? row.genre;
        const updatedListeners = monthly_listeners ?? row.monthly_listeners;
        db.run(
            'UPDATE artists SET name = ?, genre = ?, monthly_listeners = ? WHERE id = ?',
            [updatedName, updatedGenre, updatedListeners, id],
            function(err) {
                if (err) return res.status(500).json({ error: err.message });
                //return the updated artist
                db.get('SELECT * FROM artists WHERE id = ?', [id], (err, updated) => {
                    if (err) return res.status(500).json({ error: err.message });
                    res.json(updated);
                });
            }
        );
    });
};

//DELETE /artists/:id -> delete an artist (cascades to albums and songs)
const deleteArtist = (req, res) => {
    const { id } = req.params;
    db.get('SELECT * FROM artists WHERE id = ?', [id], (err, row) => {
        if (err) return res.status(500).json({ error: err.message });
        if (!row) return res.status(404).json({ error: 'Artist not found.' });
        db.run('DELETE FROM artists WHERE id = ?', [id], function(err) {
            if (err) return res.status(500).json({ error: err.message });
            res.json({ message: 'Artist deleted successfully.' });
        });
    });
};

module.exports = { getAllArtists, getArtistById, createArtist, updateArtist, deleteArtist };