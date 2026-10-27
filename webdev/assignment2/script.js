//waits until html is fully loaded before running javascript (defer used in index at top instead of bottom to make it not run before the html has fully gone through)
document.addEventListener('DOMContentLoaded', function() {
    
    //set student name variable
    const studentName = "Mateo";
    //set where welcomeMsg will appear
    const welcomeMsg = document.getElementById('welcomeMsg');
    //print welcomeMsg
    welcomeMsg.textContent = "Welcome, " + studentName + "!";
    
    //variable to count study sessions
    let count = 0;
    
    //get element that displays the session number
    const sessionSpan = document.getElementById('count');
    //get addSessionButton
    const addBtn = document.getElementById('addSessionButton');
    //get resetSessionButton
    const resetBtn = document.getElementById('resetSessionButton');
    
    //if addSessionButton clicked, count increases
    addBtn.addEventListener('click', function() {
        count++;
        sessionSpan.textContent = count; //update count
    });

    //when resetSessionButton clicked, count = 0
    resetBtn.addEventListener('click', function() {
        count = 0;
        sessionSpan.textContent = count;
    });

    //goals array storing a more specific text for the goals
    const goals = [
        "Finish College and start working as soon as possible",
        "Get my drivers licence after saying I would as soon as I could",
        "Learn piano as it is an instrument that I'd really like to get onto",
        "Learn sign language in both Spanish and English as I think it is a unique way of communicating and seems very interesting"
    ];

    //print goals to console
    for (let i = 0; i < goals.length; i++) {
        console.log(goals[i]);
    }

    //get showGoalsButton
    const showBtn = document.getElementById('showGoalsButton');
    //get displayGoals
    const goalList = document.getElementById('displayGoals');


    //when showGoalsButton clicked, goals appear on the page
    showBtn.addEventListener('click', function() {
        //clear list before adding goals
        goalList.innerHTML = "";

        for (let i = 0; i < goals.length; i++) {

            //creates a new list item element
            let li = document.createElement("li");
            //adds the goal text to the list item
            li.textContent = goals[i];
            //adds the list item to the list on the page
            goalList.appendChild(li);
        }
    });

    //hours studied variable
    const hoursStudied = 3;

    //prints hoursStudied
    console.log("Hours studied: " + hoursStudied);

    //checks if enough hours were studied and outputs if it was good or not
    if (hoursStudied >= 3) {
        console.log("Good progress");
    } else {
        console.log("You should study more");
    }
});