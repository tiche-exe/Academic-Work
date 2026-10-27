const sqlite3 = require('sqlite3').verbose();
const path = require('node:path');
const fs = require('node:fs');

//path to the database file inside the data folder
const DB_PATH = path.join(__dirname, 'data', 'app.db');

//path to the sql file that creates tables and inserts seed data
const MODEL_PATH = path.join(__dirname, 'model.sql');

//open or create the database file
//sqlite creates the file automatically if it does not exist
const db = new sqlite3.Database(DB_PATH, (err) => {
    if (err) {
        console.error('Error connecting to database:', err.message);
    } else {
        console.log('Connected to SQLite database at', DB_PATH);
    }
});

//enable foreign key support (required for ON DELETE CASCADE to work in sqlite)
db.run('PRAGMA foreign_keys = ON');

//read the model.sql file as a string
const sql = fs.readFileSync(MODEL_PATH, 'utf8');

//run all the sql statements in model.sql
//this creates the tables and inserts the seed data
db.exec(sql, (err) => {
    if (err) {
        console.error('Error running model.sql:', err.message);
    } else {
        console.log('model.sql executed - tables and seed data ready.');
    }
});

//export the database connection so other files can use it
module.exports = db;