//waits until html is fully loaded before running javascript (defer used in index at top instead of bottom to make it not run before the html has fully gone through)
document.addEventListener('DOMContentLoaded', function() {

    //timer variables
    const timerDisplay = document.getElementById('timer');
    const startBtn = document.getElementById('startBtn');
    const pauseBtn = document.getElementById('pauseBtn');
    const stopBtn = document.getElementById('stopBtn');

    let timeRemaining = 60; // 60 seconds = 1 minute
    let intervalId = null; // holds setInterval id so it can be cleared
    let isPaused = false; // track whether timer is currently paused

    //format time as mm:ss
    function formatTime(seconds) {
        const mins = Math.floor(seconds / 60);
        const secs = seconds % 60;
        return `${mins.toString().padStart(2, '0')}:${secs.toString().padStart(2, '0')}`;
    }

    //update timer display and apply low time style (red) if 15 seconds or less
    function updateDisplay() {
        timerDisplay.textContent = formatTime(timeRemaining);
        //when <= 15 seconds, change to red text and background
        if (timeRemaining <= 15) {
            timerDisplay.classList.add('low-time');
            //swap to red apple image when low time
            document.getElementById('appleImg').src = 'apple1.png';
        } else {
            timerDisplay.classList.remove('low-time');
            // swap back to original apple image
            document.getElementById('appleImg').src = 'apple.png';
        }
    }

    //show initial time on page load
    updateDisplay();

    //clear the interval to stop the countdown
    function stopTimer() {
        if (intervalId) {
            clearInterval(intervalId);
            intervalId = null;
        }
        isPaused = false;
    }

    //handle when countdown reaches 0
    function handleFinish() {
        stopTimer();
        //alert user to take a break as required
        alert('Take a short break!');
        timeRemaining = 0;
        updateDisplay();
        //revert buttons to initial state: start enabled, pause and stop disabled
        startBtn.disabled = false;
        pauseBtn.disabled = true;
        stopBtn.disabled = true;
        //reset pause button text in case it was showing Resume
        pauseBtn.textContent = 'Pause';
    }

    //start or resume the countdown
    function startCountdown() {
        //if timer already at 0, restart from 60
        if (timeRemaining <= 0) {
            timeRemaining = 60;
            updateDisplay();
        }

        //clear any existing interval before starting a new one to avoid duplicates
        if (intervalId) clearInterval(intervalId);

        intervalId = setInterval(() => {
            //decrease time by 1 each second
            timeRemaining--;
            updateDisplay();

            //if time has run out, handle finish
            if (timeRemaining <= 0) {
                handleFinish();
            }
        }, 1000);
    }

    //START button
    startBtn.addEventListener('click', function() {
        //if timer is at 0, reset before starting
        if (timeRemaining <= 0) {
            timeRemaining = 60;
            updateDisplay();
        }

        startCountdown();

        //start disabled, pause and stop enabled after start clicked
        startBtn.disabled = true;
        pauseBtn.disabled = false;
        stopBtn.disabled = false;
        //ensure pause button text shows Pause not Resume when freshly started
        pauseBtn.textContent = 'Pause';
        isPaused = false;
    });

    //PAUSE/RESUME button
    pauseBtn.addEventListener('click', function() {
        if (pauseBtn.textContent === 'Pause') {
            //currently running, so pause the timer
            stopTimer();
            //switch button text to Resume as required
            pauseBtn.textContent = 'Resume';
            isPaused = true;
        } else {
            //currently paused, so resume the timer
            startCountdown();
            //switch button text back to Pause as required
            pauseBtn.textContent = 'Pause';
            isPaused = false;
        }
        //start stays disabled, pause and stop stay enabled
    });

    //STOP button
    stopBtn.addEventListener('click', function() {
        stopTimer();
        //reset time back to 60 seconds
        timeRemaining = 60;
        updateDisplay();
        //revert buttons to initial state: start enabled, pause and stop disabled
        startBtn.disabled = false;
        pauseBtn.disabled = true;
        stopBtn.disabled = true;
        //reset pause button text in case it was showing Resume
        pauseBtn.textContent = 'Pause';
        isPaused = false;
    });

});