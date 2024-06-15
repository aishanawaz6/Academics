$(document).ready(function() {

            let seconds = 300; // 5 minutes = 300 seconds
            const timerElement = $("#timer");

            function updateTimer() {
                const minutes = Math.floor(seconds / 60);
                const remainingSeconds = seconds % 60;

                // Display the minutes and seconds with leading zeros if necessary
                $("#minutes").text(minutes < 10 ? "0" + minutes : minutes);
                $("#seconds").text(remainingSeconds < 10 ? "0" + remainingSeconds : remainingSeconds);

                seconds--;

                if (seconds >= 0) {
                    // Schedule the next update
                    setTimeout(updateTimer, 1000);
                } else {
                    timerElement.html("Time's up!");
                }
            }

            // Initially set the timer
            updateTimer();

  var n = 0;
  var attemptedQ=0;
  $('#prev').hide();
  $('#dialog').hide();
  var questions = [
    "How are you?",
    "What is your name?",
    "What are your hobbies?",
    "What is your age?",
    "What is your favourite color?"
  ];

  function showQuestion() {
    $('#Question').html(questions[n]);
      n=n+1;
    $('#QuestionNum').html(n); 
    if (n > 1) {
      $('#prev').show();
    }
    if (n === questions.length) {
      $('#next').hide();
    }
  }

  function showPrevQuestion() {
    if (n > 0) {
      n = n - 1;
      $('#Question').html(questions[n-1]);
      $('#QuestionNum').html(n);
      $('#next').show(); 
      if (n <= 1) {
      $('#prev').hide();
    }
}
  }

  $('#submit').on('click', function() {
      showQuestion();
      showDialog();
  });

  $('#next').on('click', function() {
      showQuestion();
  });

  $('#prev').on('click', function() {
    showPrevQuestion();
  });
function showDialog(){
 attemptedQ=attemptedQ+1
 $('#num').html(attemptedQ)
  $('#dialog').dialog({
    modal: true,
    resizable: false,
    buttons: [
      {
        text: 'Ok got it',
        click: function() {
          $(this).dialog('close');
        }
      }
    ]
  });
}

  // Initializing the first question
  showQuestion();
});
