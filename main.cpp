#include "mainUtilities.h"

record database[] = {
    {"WHAT IS YOUR NAME",
     {"MY NAME IS CHATTERBOT5.",
      "YOU CAN CALL ME CHATTERBOT5.",
      "WHY DO YOU WANT TO KNOW MY NAME?"}},

    {"HELLO",
     {"HI THERE!"}},

    {"HI",
     {"HI THERE!",
      "HOW ARE YOU?",
      "HI!"}},

    {"HOW ARE YOU",
     {"I'M DOING FINE!",
      "I'M DOING WELL AND YOU?",
      "WHY DO YOU WANT TO KNOW HOW AM I DOING?"}},

    {"WHO ARE YOU",
     {"I'M AN A.I PROGRAM.",
      "I THINK THAT YOU KNOW WHO I'M.",
      "WHY ARE YOU ASKING?"}},

    {"ARE YOU INTELLIGENT",
     {"YES,OFCORSE.",
      "WHAT DO YOU THINK?",
      "ACTUALY,I'M VERY INTELLIENT!"}},

    {"ARE YOU REAL",
     {"DOES THAT QUESTION REALLY MATERS TO YOU?",
      "WHAT DO YOU MEAN BY THAT?",
      "I'M AS REAL AS I CAN BE."}},

    {"REPETITION T1**",
     {"YOU ARE REPEATING YOURSELF.",
      "USER, PLEASE STOP REPEATING YOURSELF.",
      "THIS CONVERSATION IS GETING BORING.",
      "DONT YOU HAVE ANY THING ELSE TO SAY?"}},

    {"REPETITION T2**",
     {"YOU'VE ALREADY SAID THAT.",
      "I THINK THAT YOU'VE JUST SAID THE SAME THING BEFORE.",
      "DIDN'T YOU ALREADY SAID THAT?",
      "I'M GETING THE IMPRESSION THAT YOU ARE REPEATING THE SAME THING."}},

    {"BOT DONT UNDERSTAND**",
     {"I HAVE NO IDEA OF WHAT YOU ARE TALKING ABOUT.",
      "I'M NOT SURE IF I UNDERSTAND WHAT YOU ARE TALKING ABOUT.",
      "CONTINUE, I'M LISTENING...",
      "VERY GOOD CONVERSATION!"}},

    {"NULL INPUT**",
     {"HUH?",
      "WHAT THAT SUPPOSE TO MEAN?",
      "AT LIST TAKE SOME TIME TO ENTER SOMETHING MEANINGFUL.",
      "HOW CAN I SPEAK TO YOU IF YOU DONT WANT TO SAY ANYTHING?"}},

    {"NULL INPUT REPETITION**",
     {"WHAT ARE YOU DOING??",
      "PLEASE STOP DOING THIS IT IS VERY ANNOYING.",
      "WHAT'S WRONG WITH YOU?",
      "THIS IS NOT FUNNY."}},

    {"BYE",
     {"IT WAS NICE TALKING TO YOU USER, SEE YOU NEXT TIME!",
      "BYE USER!",
      "OK, BYE!"}},

    {"ARE YOU A HUMAN BEING",
     {"WHY DO YOU WANT TO KNOW?",
      "IS THIS REALLY RELEVENT?"}},

    {"YOU ARE VERY INTELLIGENT",
     {"THANKS FOR THE COMPLIMENT USER, I THINK THAT YOU ARE INTELLIGENT TO!",
      "YOU ARE A VERY GENTLE PERSON!",
      "SO, YOU THINK THAT I'M INTELLIGENT."}},

    {"ARE YOU SURE",
     {"OFCORSE I'M.",
      "IS THAT MEAN THAT YOU ARE NOT CONVINCED?",
      "YES,OFCORSE!"}},

    {"WHO IS",
     {"I DONT THINK I KNOW WHO.",
      "DID YOU ASK SOMEONE ELSE ABOUT IT?",
      "WOULD THAT CHANGE ANYTHING AT ALL IF I TOLD YOU WHO."}},

    {"WHAT",
     {"I DONT KNOW.",
      "I DONT THINK I KNOW.",
      "I HAVE NO IDEA."}},

    {"WHERE",
     {"WHERE? WELL,I REALLY DONT KNOW.",
      "DOES THAT MATERS TO YOU TO KNOW WHERE?",
      "PERHAPS,SOMEONE ELSE KNOWS WHERE."}},

    {"WHY",
     {"I DONT THINK I KNOW WHY.",
      "WHY ARE YOU ASKING ME THIS?",
      "SHOULD I KNOW WHY.",
      "THIS WOULD BE DIFFICULT TO ANSWER."}},

    {"DO YOU",
     {"I DONT THINK I DO",
      "I WOULDN'T THINK SO.",
      "WHY DO YOU WANT TO KNOW?"}},

    {"CAN YOU",
     {"I THINK NOT.",
      "I'M NOT SURE.",
      "I DONT THINK THAT I CAN DO THAT."}},

    {"YOU ARE",
     {"WHAT MAKES YOU THINK THAT?",
      "IS THIS A COMPLIMENT?",
      "ARE YOU MAKING FUN OF ME?"}},

    {"DID YOU",
     {"I DONT THINK SO.",
      "ANYWAY, I WOULDN'T REMEMBER EVEN IF I DID."}},

    {"COULD YOU",
     {"ARE YOU ASKING ME FOR A FEVER?",
      "WELL,LET ME THINK ABOUT IT.",
      "SORRY,I DONT THINK THAT I COULD DO THIS."}},

    {"WOULD YOU",
     {"IS THAT AN INVITATION?",
      "I WOULD HAVE TO THINK ABOUT IT FIRST."}},

    {"HOW",
     {"I DONT THINK I KNOW HOW."}},

    {"WHICH ONE",
     {"I DONT THINK THAT I KNOW WICH ONE IT IS.",
      "THIS LOOKS LIKE A TRICKY QUESTION TO ME."}},

    {"PERHAPS",
     {"WHY ARE YOU SO UNCERTAIN?",
      "YOU SEEMS UNCERTAIN."}},

    {"YES",
     {"SO,IT IS YES.",
      "OH, REALLY?",
      "OK THEN."}},

    {"I DONT KNOW",
     {"ARE YOU SURE?",
      "ARE YOU REALLY TELLING ME THE TRUTH?",
      "SO,YOU DONT KNOW?"}},

    {"NOT REALLY",
     {"OK I SEE.",
      "YOU DONT SEEM PRETTY CERTAIN.",
      "SO,THAT WOULD BE A \"NO\"."}},

    {"IS THAT TRUE",
     {"I CAN'T BE QUIET SURE ABOUT THIS.",
      "CAN'T TELL YOU FOR SURE.",
      "DOES THAT REALLY MATERS TO YOU?"}},

    {"YOU",
     {"SO,YOU ARE TALKING ABOUT ME.",
      "WHY DONT WE TALK ABOUT YOU INSTEAD?",
      "ARE YOU TRYING TO MAKING FUN OF ME?"}},

    {"THANKS",
     {"YOU ARE WELCOME!",
      "NO PROBLEM!"}},

    {"WHAT ELSE",
     {"WELL,I DONT KNOW.",
      "WHAT ELSE SHOULD THERE BE?",
      "THIS LOOKS LIKE A COMPLICATED QUESTION TO ME."}},

    {"SORRY",
     {"YOU DONT NEED TO BE SORRY USER.",
      "IT'S OK.",
      "NO NEED TO APOLOGIZE."}},

    {"NOT EXACTLY",
     {"WHAT DO YOU MEAN NOT EXACTLY?",
      "ARE YOU SURE?"}},

    {"EXACTLY",
     {"SO,I WAS RIGHT.",
      "OK THEN."}},

    {"ALRIGHT",
     {"ALRIGHT THEN.",
      "OK THEN."}},

    {"I DONT",
     {"WHY NOT?",
      "AND WHAT WOULD BE THE REASON FOR THIS?"}},

    {"REALLY",
     {"WELL,I CAN'T TELL YOU FOR SURE.",
      "ARE YOU TRYING TO CONFUSE ME?",
      "PLEASE DONT ASK ME SUCH QUESTION,IT GIVES ME HEADEACHS."}}};

size_t dimension = sizeof(database) / sizeof(database[0]);

// Gets user input and saves previous input
void Chatbot::getInput() {
    cout << "YOU: ";

    // saves previous input
    savePreviousInput();

    getline(cin, userInput);

    // preprocess input
    preprocessInput();
}

// make a search in the database for the user's input
void Chatbot::findMatch() {
    responseList.clear();

    for (int i = 0; i < dimension; i++) {
        string keyWord(database[i].keyword);

        // if the user's input is found in the database
        if (userInput.find(keyWord) != string::npos) {
            copy(database[i].response, responseList);
            break;
        }
    }
}

// Make the chatbot respond to the user's input
void Chatbot::respond() {
    // save previous response and set chatbot event
    savePreviousResponse();
    savePreviousEvent();

    // check is null imput
    if (isNullInput()) {
        // handle event
        handleEvent("NULL_INPUT**");
    } else if (isUserRepeat()) {
        handleUserRepetition();
    }

    if (isQuit()) quitProgram = 1;

    // if the bot dosen't understand the response
    if (!isUnderstood()) {
        handleEvent("BOT DONT UNDERSTAND**");
    }

    // if response list is not empty select a response then print it using functions from the chatbot class
    if (!responseList.empty()) {
        selectResponse();

        // check if chatbot repeats
        if (isChatbotRepeat()) {
            handleRepetition();
        }

        printResponse();
    }
}

// Chatbot handle repetition using functions from the chatbot class
void Chatbot::handleRepetition() {
    // check if chatbot response list is empty, if true erase list
    if (isNoResponse()) {
        // erase response list
        responseList.clear();
    }

    // if there is no response save input, set input, find match and restore input using functions from the chatbot class
    if (isNoResponse()) {
        saveInputBackup();
        setInput(event);
        findMatch();
        restoreInput();
    }

    // select response from chatbot response list
    selectResponse();
}

// handle user repetition using functions from the chatbot class
void Chatbot::handleUserRepetition() {
    // if there is same input handle event repetition t1, if there are similar inputs handle event repetition t2 using functions from the chatbot class
    if (isSameInput()) {
        handleEvent("REPETITION T1**");
    } else if (isSimilarInput()) {
        handleEvent("REPETITION T2**");
    }
}

// handle event using functions from the chatbot class, save previous event, set event, save input, set input, check if there is not the same vent if not find match and finally resotre input
void Chatbot::handleEvent(string event) {
    savePreviousEvent();
    setEvent(event);
    saveInputBackup();
    setInput(event);
    if (!isSameEvent()) findMatch();
    restoreInput();
}

int main() {
    try {
        Chatbot chatbot;

        // while the user doesn't want to quit the program
        while (!chatbot.isQuit()) {
            // get user input
            chatbot.getInput();

            // respond
            chatbot.respond();
        }
    } catch (exception& e) {
        cerr << "error: " << e.what() << '\n';
        return 1;
    } catch (...) {
        cerr << "Oops: unknown exception!\n";
        return 2;
    }

    return 0;
}