const image = document.getElementById('cover'),
    title = document.getElementById('music-title'),
    artist = document.getElementById('music-artist'),
    currentTimeEl = document.getElementById('current-time'),
    durationEl = document.getElementById('duration'),
    progress = document.getElementById('progress'),
    playerProgress = document.getElementById('player-progress'),
    prevBtn = document.getElementById('prev'),
    nextBtn = document.getElementById('next'),
    playBtn = document.getElementById('play'),
    background = document.getElementById('bg-img');

const music = new Audio();

const songs = [
    {
        path: 'BIG DAWG THING.mp3',
        displayName: 'BIG DAWG THING',
        cover: 'assets/umair.jpg',
        artist: 'Umair, JJ47, Talha Anjum, Shamoon Ismail, Talhah Yunus'
    },
    {
        path: 'Faasla.mp3',
        displayName: 'Faasla',
        cover: 'assets/ali.jpeg',
        artist: 'Ali Taqi Wajid & ASAD'
    },
    {
        path: '6AM IN ISLAMABAD.mp3',
        displayName: '6AM IN ISLAMABAD',
        cover: 'assets/umair.jpg',
        artist: 'Umair, Shamoon Ismail & Talhah Yunus'
    },
    {
        path: 'DOMINOS.mp3',
        displayName: 'DOMINOS',
        cover: 'assets/umair.jpg',
        artist: 'Umair, Talha Anjum & Encore ABJ'
    },
    {
        path: 'Waaday.mp3',
        displayName: 'Waaday',
        cover: 'assets/ali.jpeg',
        artist: 'Ali Taqi Wajid, ASAD, Shakeel Afzal'
    },
    {
        path: 'Imperfect.mp3',
        displayName: 'Imperfect',
        cover: 'assets/ali.jpeg',
        artist: 'Ali Taqi Wajid'
    },
    {
        path: 'BROKE FLEX.mp3',
        displayName: 'BROKE FLEX',
        cover: 'assets/umair.jpg',
        artist: 'Umair, AHSAN & Ab 17'
    },
    {
        path: 'OBVIOUS.mp3',
        displayName: 'OBVIOUS',
        cover: 'assets/umair.jpg',
        artist: 'Umair & Hasan Raheem'
    },
]

let musicIndex = 0;
let isPlaying = false;

function togglePlay() {
    if (isPlaying) {
        pauseMusic();
    } else {
        playMusic();
    }
}

function playMusic() {
    isPlaying = true;
    // Change play button icon
    playBtn.classList.replace('fa-play', 'fa-pause');
    // Set button hover title
    playBtn.setAttribute('title', 'Pause');
    music.play();
}

function pauseMusic() {
    isPlaying = false;
    // Change pause button icon
    playBtn.classList.replace('fa-pause', 'fa-play');
    // Set button hover title
    playBtn.setAttribute('title', 'Play');
    music.pause();
}

function loadMusic(song) {
    music.src = "music.php/?song=" + song.path;
    title.textContent = song.displayName;
    artist.textContent = song.artist;
    image.src = song.cover;
    background.src = song.cover;
}

function changeMusic(direction) {
    musicIndex = (musicIndex + direction + songs.length) % songs.length;
    loadMusic(songs[musicIndex]);
    playMusic();
}

function updateProgressBar() {
    const { duration, currentTime } = music;
    const progressPercent = (currentTime / duration) * 100;
    progress.style.width = `${progressPercent}%`;

    const formatTime = (time) => String(Math.floor(time)).padStart(2, '0');
    durationEl.textContent = `${formatTime(duration / 60)}:${formatTime(duration % 60)}`;
    currentTimeEl.textContent = `${formatTime(currentTime / 60)}:${formatTime(currentTime % 60)}`;
}

function setProgressBar(e) {
    const width = playerProgress.clientWidth;
    const clickX = e.offsetX;
    music.currentTime = (clickX / width) * music.duration;
}

playBtn.addEventListener('click', togglePlay);
prevBtn.addEventListener('click', () => changeMusic(-1));
nextBtn.addEventListener('click', () => changeMusic(1));
music.addEventListener('ended', () => changeMusic(1));
music.addEventListener('timeupdate', updateProgressBar);
playerProgress.addEventListener('click', setProgressBar);

loadMusic(songs[musicIndex]);