//express framework for web server/routes
const express = require('express');
//.verbose() gives more detailed error messages (debugging)
const sqlite3 = require('sqlite3').verbose();

const app = express();
//server port
const PORT = 3000;

//parses JSON request so req.body works
app.use(express.json());

//status values
const ALLOWED_STATUS = ['to-read', 'reading', 'completed'];

//open/creates database file (creates if no db file)
const db = new sqlite3.Database('./database.db', (err) => {
    if (err) {
        //if failed connection -> logs error message in terminal
        console.error('Error opening database:', err.message);
    } else {
        //if valid connection -> confirms in terminal
        console.log('Connected to SQLite database.');
    }
});

//books table created when server starts
db.run(`
    CREATE TABLE IF NOT EXISTS books (
        id INTEGER PRIMARY KEY AUTOINCREMENT,
        title TEXT NOT NULL,
        author TEXT NOT NULL,
        year INTEGER,
        status TEXT NOT NULL CHECK(status IN ('to-read', 'reading', 'completed'))
    )
`, (err) => {
    if (err) {
        //log error if table creation fails
        console.error('Error creating table:', err.message);
    } else {
        //confirm table is ready in terminal
        console.log('Books table ready.');
    }
});

//GET /books returns all books from database
//GET /books?status=reading filters by status if query given
app.get('/books', (req, res) => {
    //reads status from URL if it exists
    const {status} = req.query;

    if (status) {
        //if a status provided, checks if valid value before querying
        if (!ALLOWED_STATUS.includes(status)) {
            return res.status(400).json({error: 'Invalid status value. Must be to-read, reading, or completed.'});
        }
        //filters books by given status
        //"?" -> placeholder (prevents SQL injection)
        db.all('SELECT * FROM books WHERE status = ?', [status], (err, rows) => {
            if (err) return res.status(500).json({ error: err.message });
            //sends filtered results as JSON
            res.json(rows);
        });
    } else {
        //if no status filter provided -> select/return every book in table
        db.all('SELECT * FROM books', [], (err, rows) => {
            if (err) return res.status(500).json({ error: err.message });
            //send all results as JSON
            res.json(rows);
        });
    }
});

//GET /books/:id (retrieves book using its id from request URL)
app.get('/books/:id', (req, res) => {
    //extracts id from URL parameters
    const { id } = req.params;
    db.get('SELECT * FROM books WHERE id = ?', [id], (err, row) => {
        //if error -> error display
        if (err) return res.status(500).json({ error: err.message });
        //if no row returned -> book doesnt exist -> book not found
        if (!row) return res.status(404).json({ error: '404 Book not found.' });
        //sends found book as JSON
        res.json(row);
    });
});

//POST /books (adds new book to database from request)
app.post('/books', (req, res) => {
    //read book fields from request
    const { title, author, year, status } = req.body;

    //check all required fields (title, author, status) present before inserting
    if (!title || !author || !status) {
        return res.status(400).json({ error: 'title, author, and status are required.' });
    }

    //checks if status value allowed
    if (!ALLOWED_STATUS.includes(status)) {
        return res.status(400).json({ error: 'Invalid status value. Must be to-read, reading, or completed.' });
    }

    //parameterised INSERT query
    db.run('INSERT INTO books (title, author, year, status) VALUES (?, ?, ?, ?)', [title, author, year, status], function(err) {
        if (err) return res.status(500).json({ error: err.message });
        //this.lastID gives auto generated id of row that was just inserted
        //return 201 (created with new books id)
        res.status(201).json({ id: this.lastID });
    });
});

//PUT /books/:id (updates existing book (only title, year, status))
app.put('/books/:id', (req, res) => {
    //get book id
    const { id } = req.params;
    //update request fields 
    const { title, year, status } = req.body;

    //if status included in request -> validate it FIRST
    if (status && !ALLOWED_STATUS.includes(status)) {
        return res.status(400).json({ error: 'Invalid status value. Must be to-read, reading, or completed.' });
    }

    //check book with this id exists in database
    db.get('SELECT * FROM books WHERE id = ?', [id], (err, row) => {
        if (err) return res.status(500).json({ error: err.message });
        //if no book was found -> return error 404
        if (!row) return res.status(404).json({ error: 'Book not found.' });

        //update one field without wiping the others (if field not provided in request -> keep value from database)
        const updatedTitle = title !== undefined ? title : row.title;
        const updatedYear = year !== undefined ? year : row.year;
        const updatedStatus = status !== undefined ? status : row.status;

        //update specific book
        db.run('UPDATE books SET title = ?, year = ?, status = ? WHERE id = ?', [updatedTitle, updatedYear, updatedStatus, id], function(err) {
            if (err) return res.status(500).json({ error: err.message });
            //send success message & id of new updated book
            res.json({ message: 'Book updated successfully.', id: Number(id) });
        });
    });
});

//DELETE /books/:id (deletes book from database through its id)
app.delete('/books/:id', (req, res) => {
    //get book id
    const { id } = req.params;

    //check book exists before deleting
    db.get('SELECT * FROM books WHERE id = ?', [id], (err, row) => {
        if (err) return res.status(500).json({ error: err.message });
        //if no book was found with this id -> return error 404
        if (!row) return res.status(404).json({ error: 'Book not found.' });

        //DELETE specific book
        db.run('DELETE FROM books WHERE id = ?', [id], function(err) {
            if (err) return res.status(500).json({ error: err.message });
            //sends success message confirming deletion
            res.json({ message: 'Book deleted successfully.' });
        });
    });
});

//start server to accept requests (port 3000)
app.listen(PORT, () => {
    console.log(`Server running on http://localhost:${PORT}`);
});