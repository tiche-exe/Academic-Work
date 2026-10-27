//base URL for all API requests
const API = 'http://localhost:5000';

//show a brief toast message at the bottom of the screen
function toast(msg) {
    const el = document.getElementById('toast');
    el.textContent = msg;
    el.classList.add('show');
    setTimeout(() => el.classList.remove('show'), 2500);
}

//toggle the inline edit row open or closed
function toggleEdit(prefix, id) {
    const row = document.getElementById(prefix + '-edit-' + id);
    row.style.display = row.style.display === 'table-row' ? 'none' : 'table-row';
}

//switch the visible page and update the active nav button
function showPage(name) {
    //hide all pages
    document.querySelectorAll('.page').forEach(p => p.classList.remove('active'));
    //remove active from all nav buttons
    document.querySelectorAll('.nav-links .nav-btn').forEach(a => a.classList.remove('active'));
    //show the selected page
    document.getElementById('page-' + name).classList.add('active');
    //highlight the selected nav button
    document.getElementById('nav-' + name).classList.add('active');
    //load the correct data for the selected page
    if (name === 'home') loadHome();
    if (name === 'artists') loadArtists();
    if (name === 'albums') { loadAlbums(); populateArtistSelect(); }
    if (name === 'songs') { loadSongs(); populateAlbumSelect(); }
}








//HOME
//fetch counts from all three endpoints and display on the home page
async function loadHome() {
    const artists = await fetch(API + '/artists').then(r => r.json());
    const albums  = await fetch(API + '/albums').then(r => r.json());
    const songs   = await fetch(API + '/songs').then(r => r.json());
    document.getElementById('stat-artists').textContent = artists.length;
    document.getElementById('stat-albums').textContent  = albums.length;
    document.getElementById('stat-songs').textContent   = songs.length;
}



















//ARTISTS
//fetch all artists from the API and build the table rows
async function loadArtists() {
    const tbody = document.getElementById('artists-tbody');
    const artists = await fetch(API + '/artists').then(r => r.json());

    //show empty message if no artists exist yet
    if (!artists.length) {
        tbody.innerHTML = '<tr><td colspan="5" class="empty">No artists yet.</td></tr>';
        return;
    }

    //build one display row and one hidden edit row per artist
    tbody.innerHTML = artists.map((a, i) => `
        <tr>
            <td style="color:var(--muted)">${i + 1}</td>
            <td><strong>${a.name}</strong></td>
            <td style="color:var(--muted)">${a.genre}</td>
            <td style="color:var(--muted)">${a.monthly_listeners.toLocaleString()}</td>
            <td>
                <div class="actions">
                    <button class="btn btn-ghost btn-sm" onclick="toggleEdit('ar',${a.id})">Edit</button>
                    <button class="btn btn-danger btn-sm" onclick="deleteArtist(${a.id})">Delete</button>
                </div>
            </td>
        </tr>
        <tr class="edit-row" id="ar-edit-${a.id}">
            <td colspan="5">
                <div class="edit-form">
                    <input id="ear-name-${a.id}" value="${a.name}" placeholder="Name">
                    <input id="ear-genre-${a.id}" value="${a.genre}" placeholder="Genre">
                    <input type="number" id="ear-listeners-${a.id}" value="${a.monthly_listeners}" placeholder="Listeners">
                    <button class="btn btn-save btn-sm" onclick="updateArtist(${a.id})">Save</button>
                    <button class="btn btn-ghost btn-sm" onclick="toggleEdit('ar',${a.id})">Cancel</button>
                </div>
            </td>
        </tr>
    `).join('');
}

//read form values and POST a new artist
async function createArtist() {
    const name = document.getElementById('artist-name').value.trim();
    const genre = document.getElementById('artist-genre').value.trim();
    //Number.parseInt used instead of parseInt (sonarqube fix)
    const monthly_listeners = Number.parseInt(document.getElementById('artist-listeners').value) || 0;
    //validate before sending
    if (!name || !genre) return toast('Name and genre are required.');
    await fetch(API + '/artists', {
        method: 'POST',
        headers: { 'Content-Type': 'application/json' },
        body: JSON.stringify({ name, genre, monthly_listeners })
    });
    //clear form and reload table
    toast('Artist added');
    document.getElementById('artist-name').value = '';
    document.getElementById('artist-genre').value = '';
    document.getElementById('artist-listeners').value = '';
    loadArtists();
}

//read edit form values and PUT the updated artist
async function updateArtist(id) {
    const name = document.getElementById('ear-name-' + id).value.trim();
    const genre = document.getElementById('ear-genre-' + id).value.trim();
    //Number.parseInt used instead of parseInt (sonarqube fix)
    const monthly_listeners = Number.parseInt(document.getElementById('ear-listeners-' + id).value) || 0;
    await fetch(API + '/artists/' + id, {
        method: 'PUT',
        headers: { 'Content-Type': 'application/json' },
        body: JSON.stringify({ name, genre, monthly_listeners })
    });
    toast('Artist updated');
    loadArtists();
}

//DELETE an artist by id (cascades to albums and songs on the backend)
async function deleteArtist(id) {
    if (!confirm('Delete this artist? All their albums and songs will also be deleted.')) return;
    await fetch(API + '/artists/' + id, { method: 'DELETE' });
    toast('Artist deleted');
    loadArtists();
}

















// ALBUMS
//fill the artist dropdown in the add album form
async function populateArtistSelect() {
    const sel = document.getElementById('album-artist');
    const artists = await fetch(API + '/artists').then(r => r.json());
    sel.innerHTML = '<option value="">Select...</option>' +
        artists.map(a => `<option value="${a.id}">${a.name}</option>`).join('');
}

//fetch all albums from the API and build the table rows
async function loadAlbums() {
    const tbody = document.getElementById('albums-tbody');
    const albums  = await fetch(API + '/albums').then(r => r.json());
    const artists = await fetch(API + '/artists').then(r => r.json());

    //show empty message if no albums exist yet
    if (!albums.length) {
        tbody.innerHTML = '<tr><td colspan="6" class="empty">No albums yet.</td></tr>';
        return;
    }

    //build artist options string for the inline edit dropdowns
    const aopts = artists.map(a => `<option value="${a.id}">${a.name}</option>`).join('');

    tbody.innerHTML = albums.map((a, i) => `
        <tr>
            <td style="color:var(--muted)">${i + 1}</td>
            <td><strong>${a.name}</strong></td>
            <td style="color:var(--muted)">${a.artist_name}</td>
            <td style="color:var(--muted)">${a.release_year}</td>
            <td style="color:var(--muted)">${a.listens.toLocaleString()}</td>
            <td>
                <div class="actions">
                    <button class="btn btn-ghost btn-sm" onclick="toggleEdit('al',${a.id})">Edit</button>
                    <button class="btn btn-danger btn-sm" onclick="deleteAlbum(${a.id})">Delete</button>
                </div>
            </td>
        </tr>
        <tr class="edit-row" id="al-edit-${a.id}">
            <td colspan="6">
                <div class="edit-form">
                    <input id="eal-name-${a.id}" value="${a.name}" placeholder="Name">
                    <input type="number" id="eal-year-${a.id}" value="${a.release_year}" placeholder="Year">
                    <input type="number" id="eal-listens-${a.id}" value="${a.listens}" placeholder="Listens">
                    <select id="eal-artist-${a.id}">${aopts.replace(`value="${a.artist_id}"`, `value="${a.artist_id}" selected`)}</select>
                    <button class="btn btn-save btn-sm" onclick="updateAlbum(${a.id})">Save</button>
                    <button class="btn btn-ghost btn-sm" onclick="toggleEdit('al',${a.id})">Cancel</button>
                </div>
            </td>
        </tr>
    `).join('');
}

//read form values and POST a new album
async function createAlbum() {
    const name = document.getElementById('album-name').value.trim();
    //Number.parseInt used instead of parseInt (sonarqube fix)
    const release_year = Number.parseInt(document.getElementById('album-year').value);
    const listens = Number.parseInt(document.getElementById('album-listens').value) || 0;
    const artist_id = Number.parseInt(document.getElementById('album-artist').value);
    //validate before sending
    if (!name || !release_year || !artist_id) return toast('Name, year and artist are required.');
    await fetch(API + '/albums', {
        method: 'POST',
        headers: { 'Content-Type': 'application/json' },
        body: JSON.stringify({ name, release_year, listens, artist_id })
    });
    //clear form and reload table
    toast('Album added');
    document.getElementById('album-name').value = '';
    document.getElementById('album-year').value = '';
    document.getElementById('album-listens').value = '';
    loadAlbums();
}

//read edit form values and PUT the updated album
async function updateAlbum(id) {
    const name = document.getElementById('eal-name-' + id).value.trim();
    //Number.parseInt used instead of parseInt (sonarqube fix)
    const release_year = Number.parseInt(document.getElementById('eal-year-' + id).value);
    const listens = Number.parseInt(document.getElementById('eal-listens-' + id).value) || 0;
    const artist_id = Number.parseInt(document.getElementById('eal-artist-' + id).value);
    await fetch(API + '/albums/' + id, {
        method: 'PUT',
        headers: { 'Content-Type': 'application/json' },
        body: JSON.stringify({ name, release_year, listens, artist_id })
    });
    toast('Album updated');
    loadAlbums();
}

//DELETE an album by id (cascades to songs on the backend)
async function deleteAlbum(id) {
    if (!confirm('Delete this album? All its songs will also be deleted.')) return;
    await fetch(API + '/albums/' + id, { method: 'DELETE' });
    toast('Album deleted');
    loadAlbums();
}













//SONGS
//fill the album dropdown in the add song form
async function populateAlbumSelect() {
    const sel = document.getElementById('song-album');
    const albums = await fetch(API + '/albums').then(r => r.json());
    sel.innerHTML = '<option value="">Select...</option>' +
        albums.map(a => `<option value="${a.id}">${a.name} - ${a.artist_name}</option>`).join('');
}

//fetch all songs from the API and build the table rows
async function loadSongs() {
    const tbody = document.getElementById('songs-tbody');
    const songs  = await fetch(API + '/songs').then(r => r.json());
    const albums = await fetch(API + '/albums').then(r => r.json());

    //show empty message if no songs exist yet
    if (!songs.length) {
        tbody.innerHTML = '<tr><td colspan="6" class="empty">No songs yet.</td></tr>';
        return;
    }

    //build album options string for the inline edit dropdowns
    const aopts = albums.map(a => `<option value="${a.id}">${a.name} - ${a.artist_name}</option>`).join('');

    tbody.innerHTML = songs.map((s, i) => `
        <tr>
            <td style="color:var(--muted)">${i + 1}</td>
            <td><strong>${s.name}</strong></td>
            <td style="color:var(--muted)">${s.album_name}</td>
            <td style="color:var(--muted)">${s.artist_name}</td>
            <td style="color:var(--muted)">${s.release_year}</td>
            <td>
                <div class="actions">
                    <button class="btn btn-ghost btn-sm" onclick="toggleEdit('so',${s.id})">Edit</button>
                    <button class="btn btn-danger btn-sm" onclick="deleteSong(${s.id})">Delete</button>
                </div>
            </td>
        </tr>
        <tr class="edit-row" id="so-edit-${s.id}">
            <td colspan="6">
                <div class="edit-form">
                    <input id="eso-name-${s.id}" value="${s.name}" placeholder="Name">
                    <input type="number" id="eso-year-${s.id}" value="${s.release_year}" placeholder="Year">
                    <select id="eso-album-${s.id}">${aopts.replace(`value="${s.album_id}"`, `value="${s.album_id}" selected`)}</select>
                    <button class="btn btn-save btn-sm" onclick="updateSong(${s.id})">Save</button>
                    <button class="btn btn-ghost btn-sm" onclick="toggleEdit('so',${s.id})">Cancel</button>
                </div>
            </td>
        </tr>
    `).join('');
}

//read form values and POST a new song
async function createSong() {
    const name = document.getElementById('song-name').value.trim();
    //Number.parseInt used instead of parseInt (sonarqube fix)
    const release_year = Number.parseInt(document.getElementById('song-year').value);
    const album_id = Number.parseInt(document.getElementById('song-album').value);
    //validate before sending
    if (!name || !release_year || !album_id) return toast('Name, year and album are required.');
    await fetch(API + '/songs', {
        method: 'POST',
        headers: { 'Content-Type': 'application/json' },
        body: JSON.stringify({ name, release_year, album_id })
    });
    //clear form and reload table
    toast('Song added');
    document.getElementById('song-name').value = '';
    document.getElementById('song-year').value = '';
    document.getElementById('song-album').value = '';
    loadSongs();
}

//read edit form values and PUT the updated song
async function updateSong(id) {
    const name = document.getElementById('eso-name-' + id).value.trim();
    //Number.parseInt used instead of parseInt (sonarqube fix)
    const release_year = Number.parseInt(document.getElementById('eso-year-' + id).value);
    const album_id = Number.parseInt(document.getElementById('eso-album-' + id).value);
    await fetch(API + '/songs/' + id, {
        method: 'PUT',
        headers: { 'Content-Type': 'application/json' },
        body: JSON.stringify({ name, release_year, album_id })
    });
    toast('Song updated');
    loadSongs();
}

//DELETE a song by id
async function deleteSong(id) {
    if (!confirm('Delete this song?')) return;
    await fetch(API + '/songs/' + id, { method: 'DELETE' });
    toast('Song deleted');
    loadSongs();
}

//load home stats when the page first opens wrapped in DOMContentLoaded (sonarqube fix)
document.addEventListener('DOMContentLoaded', () => {
    loadHome();
});