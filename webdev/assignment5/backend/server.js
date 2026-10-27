const express = require('express');
const cors = require('cors');
const path = require('node:path');

//import route files
const artistsRouter = require('./routes/artists');
const albumsRouter = require('./routes/albums');
const songsRouter = require('./routes/songs');

const app = express();
const PORT = 5000;

//middleware: parse incoming JSON so req.body works
app.use(express.json());

//middleware: allow the frontend to call the API
app.use(cors());

//serve the frontend folder as static files so the UI loads at localhost:5000
app.use(express.static(path.join(__dirname, '..', 'frontend')));

//register route files at their base paths
app.use('/artists', artistsRouter);
app.use('/albums', albumsRouter);
app.use('/songs', songsRouter);

//start the server on port 5000
app.listen(PORT, () => {
    console.log(`Server running on http://localhost:${PORT}`);
});