-- enable foreign key enforcement in sqlite
PRAGMA foreign_keys = ON;

-- artists table
CREATE TABLE IF NOT EXISTS artists (
    id INTEGER PRIMARY KEY AUTOINCREMENT,
    name TEXT NOT NULL,
    genre TEXT NOT NULL,
    monthly_listeners INTEGER NOT NULL DEFAULT 0
);

-- albums table
-- ON DELETE CASCADE deletes albums when artist is deleted
CREATE TABLE IF NOT EXISTS albums (
    id INTEGER PRIMARY KEY AUTOINCREMENT,
    name TEXT NOT NULL,
    release_year INTEGER NOT NULL,
    listens INTEGER NOT NULL DEFAULT 0,
    artist_id INTEGER NOT NULL,
    FOREIGN KEY (artist_id) REFERENCES artists(id) ON DELETE CASCADE
);

-- songs table
-- ON DELETE CASCADE deletes songs when album is deleted
CREATE TABLE IF NOT EXISTS songs (
    id INTEGER PRIMARY KEY AUTOINCREMENT,
    name TEXT NOT NULL,
    release_year INTEGER NOT NULL,
    album_id INTEGER NOT NULL,
    FOREIGN KEY (album_id) REFERENCES albums(id) ON DELETE CASCADE
);

-- set 2 artists
INSERT OR IGNORE INTO artists (id, name, genre, monthly_listeners) VALUES
(1, 'Michael Jackson', 'Pop', 45000000),
(2, 'The Jackson 5', 'Soul', 18000000);

-- set 5 albums (3 of michael jackson, 2 of the jackson 5)
INSERT OR IGNORE INTO albums (id, name, release_year, listens, artist_id) VALUES
(1, 'Thriller', 1982, 2000000000, 1),
(2, 'Bad', 1987, 1200000000, 1),
(3, 'Off the Wall', 1979, 800000000, 1);

INSERT OR IGNORE INTO albums (id, name, release_year, listens, artist_id) VALUES
(4, 'ABC', 1970, 700000000, 2),
(5, 'Diana Ross Presents The Jackson 5', 1969, 500000000, 2);

-- set 10 songs
-- 5 songs from michael jackson albums and 5 from the jackson 5
INSERT OR IGNORE INTO songs (id, name, release_year, album_id) VALUES
(1,  'Thriller',         1982, 1),
(2,  'Billie Jean',      1982, 1),
(3,  'Beat It',          1982, 1),
(4,  'Bad',              1987, 2),
(5,  'Smooth Criminal',  1987, 2);

INSERT OR IGNORE INTO songs (id, name, release_year, album_id) VALUES
(6,  'ABC',               1970, 4),
(7,  'The Love You Save', 1970, 4),
(8, 'I Found That Girl', 1970, 4),
(9,  'I Want You Back',   1969, 5),
(10,  'Who Is It',         1969, 5);
