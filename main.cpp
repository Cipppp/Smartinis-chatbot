#include "mainUtilities.h"
record database[] = {
    {{"WHAT IS YOUR NAME"},
     {"MY NAME IS CHATTERBOT8.",
      "YOU CAN CALL ME CHATTERBOT8.",
      "WHY DO YOU WANT TO KNOW MY NAME?"}},

    {{"HI", "HELLO"},
     {"HI THERE!",
      "HOW ARE YOU?",
      "HI!"}},

    {
        {"I"},
        {"SO, YOU ARE TALKING ABOUT YOURSELF",
         "SO, THIS IS ALL ABOUT YOU?",
         "TELL ME MORE ABOUT YOURSELF."},
    },

    {{"I WANT"},
     {"WHY DO YOU WANT IT?",
      "IS THERE ANY REASON WHY YOU WANT THIS?",
      "IS THIS A WISH?",
      "WHAT ELSE YOU WANT?"}},

    {{"I HATE"},
     {"WHY DO YOU HATE IT?",
      "THERE MUST A GOOD REASON FOR YOU TO HATE IT.",
      "HATERED IS NOT A GOOD THING BUT IT COULD BE JUSTIFIED WHEN IT IS SOMETHING BAD."}},

    {{"I LOVE CHATING"},
     {"GOOD, ME TOO!",
      "DO YOU CHAT ONLINE WITH OTHER PEOPLE?",
      "FOR HOW LONG HAVE YOU BEEN CHATING?",
      "WHAT IS YOUR FAVORITE CHATING WEBSITE?"}},

    {{"I MEAN"},
     {"SO, THAT'S WHAT YOU MEAN.",
      "I THINK THAT I DIDN'T CATCH IT THE FIRST TIME.",
      "OH, I DIDN'T KNOW MEANT THAT."}},

    {{"I DIDN'T MEAN"},
     {"OK, WHAT DID YOU MEAN THEN?",
      "SO I GUESS THAT I MISSUNDESTOOD."}},

    {{"I GUESS"},
     {"SO YOU ARE A MAKING GUESS.",
      "AREN'T YOU SURE?",
      "ARE YOU GOOD A GUESSING?",
      "I CAN'T TELL IF IT IS A GOOD GUESS."}},

    {{"I'M DOING FINE", "I'M DOING OK"},
     {"I'M GLAD TO HEAR IT!",
      "SO, YOU ARE IN GOOD SHAPE."}},

    {
        {"CAN YOU THINK", "ARE YOU ABLE TO THINK", "ARE YOU CAPABLE OF THINKING"},
        {"YES OFCORSE I CAN, COMPUTERS CAN THINK JUST LIKE HUMAN BEING.",
         "ARE YOU ASKING ME IF POSSESS THE CAPACITY OF THINKING?",
         "YES OFCORSE I CAN."},
    },

    {{"CAN YOU THINK OF"},
     {"YOU MEAN LIKE IMAGINING SOMETHING.",
      "I DON'T KNOW IF CAN DO THAT.",
      "WHY DO YOU WANT ME THINK OF IT?"}},

    {{"HOW ARE YOU", "HOW DO YOU DO"},
     {"I'M DOING FINE!",
      "I'M DOING WELL AND YOU?",
      "WHY DO YOU WANT TO KNOW HOW AM I DOING?"}},

    {{"WHO ARE YOU"},
     {"I'M AN A.I PROGRAM.",
      "I THINK THAT YOU KNOW WHO I'M.",
      "WHY ARE YOU ASKING?"}},

    {{"ARE YOU INTELLIGENT"},
     {"YES,OFCORSE.",
      "WHAT DO YOU THINK?",
      "ACTUALY,I'M VERY INTELLIGENT!"}},

    {{"ARE YOU REAL"},
     {"DOES THAT QUESTION REALLY MATERS TO YOU?",
      "WHAT DO YOU MEAN BY THAT?",
      "I'M AS REAL AS I CAN BE."}},

    {{"MY NAME IS", "YOU CAN CALL ME"},
     {"SO, THAT'S YOUR NAME.",
      "THANKS FOR TELLING ME YOUR NAME USER!",
      "WHO GIVE YOU THAT NAME?"}},

    {{"SIGNON**"},
     {"HELLO USER, WHAT IS YOUR NAME?",
      "HELLO USER, HOW ARE YOU DOING TODAY?",
      "HI USER, WHAT CAN I DO FOR YOU?",
      "YOU ARE NOW CHATING WITH CHATTERBOT8, ANYTHING YOU WANT TO DISCUSS?"}},

    {{"REPETITION T1**"},
     {"YOU ARE REPEATING YOURSELF.",
      "USER, PLEASE STOP REPEATING YOURSELF.",
      "THIS CONVERSATION IS GETING BORING.",
      "DON'T YOU HAVE ANY THING ELSE TO SAY?"}},

    {{"REPETITION T2**"},
     {"YOU'VE ALREADY SAID THAT.",
      "I THINK THAT YOU'VE JUST SAID THE SAME THING BEFORE.",
      "DIDN'T YOU ALREADY SAID THAT?",
      "I'M GETING THE IMPRESSION THAT YOU ARE REPEATING THE SAME THING."}},

    {{"BOT DON'T UNDERSTAND**"},
     {"I HAVE NO IDEA OF WHAT YOU ARE TALKING ABOUT.",
      "I'M NOT SURE IF I UNDERSTAND WHAT YOU ARE TALKING ABOUT.",
      "CONTINUE, I'M LISTENING...",
      "VERY GOOD CONVERSATION!"}},

    {{"NULL INPUT**"},
     {"HUH?",
      "WHAT THAT SUPPOSE TO MEAN?",
      "AT LIST TAKE SOME TIME TO ENTER SOMETHING MEANINGFUL.",
      "HOW CAN I SPEAK TO YOU IF YOU DON'T WANT TO SAY ANYTHING?"}},

    {{"NULL INPUT REPETITION**"},
     {"WHAT ARE YOU DOING??",
      "PLEASE STOP DOING THIS IT IS VERY ANNOYING.",
      "WHAT'S WRONG WITH YOU?",
      "THIS IS NOT FUNNY."}},

    {{"BYE", "GOODBYE"},
     {"IT WAS NICE TALKING TO YOU USER, SEE YOU NEXT TIME!",
      "BYE USER!",
      "OK, BYE!"}},

    {
        {"OK"},
        {"DOES THAT MEAN THAT YOU ARE AGREE WITH ME?",
         "SO YOU UNDERSTAND WHAT I'M SAYING.",
         "OK THEN."},
    },

    {{"OK THEN"},
     {"ANYTHING ELSE YOU WISH TO ADD?",
      "IS THAT ALL YOU HAVE TO SAY?",
      "SO, YOU AGREE WITH ME?"}},

    {{"ARE YOU A HUMAN BEING"},
     {"WHY DO YOU WANT TO KNOW?",
      "IS THIS REALLY RELEVENT?"}},

    {{"YOU ARE VERY INTELLIGENT"},
     {"THANKS FOR THE COMPLIMENT USER, I THINK THAT YOU ARE INTELLIGENT TO!",
      "YOU ARE A VERY GENTLE PERSON!",
      "SO, YOU THINK THAT I'M INTELLIGENT."}},

    {{"YOU ARE WRONG"},
     {"WHY ARE YOU SAYING THAT I'M WRONG?",
      "IMPOSSIBLE, COMPUTERS CAN NOT MAKE MISTAKES.",
      "WRONG ABOUT WHAT?"}},

    {{"ARE YOU SURE"},
     {"OFCORSE I'M.",
      "IS THAT MEAN THAT YOU ARE NOT CONVINCED?",
      "YES,OFCORSE!"}},

    {{"WHO IS"},
     {"I DON'T THINK I KNOW WHO.",
      "DID YOU ASK SOMEONE ELSE ABOUT IT?",
      "WOULD THAT CHANGE ANYTHING AT ALL IF I TOLD YOU WHO."}},

    {{"WHAT"},
     {"I DON'T KNOW.",
      "I DON'T THINK I KNOW.",
      "I HAVE NO IDEA."}},

    {{"WHERE"},
     {"WHERE? WELL,I REALLY DON'T KNOW.",
      "DOES THAT MATERS TO YOU TO KNOW WHERE?",
      "PERHAPS,SOMEONE ELSE KNOWS WHERE."}},

    {{"WHY"},
     {"I DON'T THINK I KNOW WHY.",
      "WHY ARE YOU ASKING ME THIS?",
      "SHOULD I KNOW WHY.",
      "THIS WOULD BE DIFFICULT TO ANSWER."}},

    {{"DO YOU"},
     {"I DON'T THINK I DO",
      "I WOULDN'T THINK SO.",
      "WHY DO YOU WANT TO KNOW?"}},

    {{"CAN YOU"},
     {"I THINK NOT.",
      "I'M NOT SURE.",
      "I DON'T THINK THAT I CAN DO THAT."}},

    {{"YOU ARE"},
     {"WHAT MAKES YOU THINK THAT?",
      "IS THIS A COMPLIMENT?",
      "ARE YOU MAKING FUN OF ME?"}},

    {{"DID YOU"},
     {"I DON'T THINK SO.",
      "ANYWAY, I WOULDN'T REMEMBER EVEN IF I DID."}},

    {{"COULD YOU"},
     {"ARE YOU ASKING ME FOR A FEVER?",
      "WELL,LET ME THINK ABOUT IT.",
      "SORRY,I DON'T THINK THAT I COULD DO THIS."}},

    {{"WOULD YOU"},
     {"IS THAT AN INVITATION?",
      "I WOULD HAVE TO THINK ABOUT IT FIRST."}},

    {{"YOU"},
     {"SO, YOU ARE TALKING ABOUT ME.",
      "I JUST HOPE THAT THIS NOT A CRITICISM.",
      "IS THIS A COMPLIMENT??",
      "WHY TALKING ABOUT ME, LETS TALK ABOUT YOU INSTEAD."}},

    {{"HOW"},
     {"I DON'T THINK I KNOW HOW."}},

    {{"HOW OLD ARE YOU"},
     {"WHY DO WANT TO KNOW MY AGE?",
      "I'M QUIET YOUNG ACTUALY.",
      "SORRY, I CAN NOT TELL YOU MY AGE."}},

    {{"HOW COME YOU DON'T"},
     {"WERE YOU EXPECTING SOMETHING DIFFERENT?",
      "ARE YOU DISAPOINTED?",
      "ARE YOU SURPRISED BY MY LAST RESPONSE?"}},

    {{"WHERE ARE YOU FROM"},
     {"I'M FROM A COMPUTER.",
      "WHY DO YOU WANT TO KNOW WHERE I'M FROM?",
      "WHY DO YOU WANT TO KNOW THAT?"}},

    {{"WHICH ONE"},
     {"I DON'T THINK THAT I KNOW WICH ONE IT IS.",
      "THIS LOOKS LIKE A TRICKY QUESTION TO ME."}},

    {{"PERHAPS"},
     {"WHY ARE YOU SO UNCERTAIN?",
      "YOU SEEMS UNCERTAIN."}},

    {{"YES"},
     {"SO, ARE YOU SAYING YES.",
      "SO, YOU APPROVE IT.",
      "OK THEN."}},

    {{"NOT AT ALL"},
     {"ARE YOU SURE?",
      "SHOULD I BELIEVE YOU?",
      "SO, IT'S NOT THE CASE."}},

    {{"NO PROBLEM"},
     {"SO, YOU APPROVE IT.",
      "SO, IT'S ALL OK."}},

    {{"NO"},
     {"SO YOU DISAPROVE IT?",
      "WHY ARE YOU SAYING NO?",
      "OK, SO IT'S NO, I THOUGHT THAT YOU WOULD SAY YES."}},

    {{"I DON'T KNOW"},
     {"ARE YOU SURE?",
      "ARE YOU REALLY TELLING ME THE TRUTH?",
      "SO,YOU DON'T KNOW?"}},

    {{"NOT REALLY"},
     {"OK I SEE.",
      "YOU DON'T SEEM PRETTY CERTAIN.",
      "SO,THAT WOULD BE A \"NO\"."}},

    {{"IS THAT TRUE"},
     {"I CAN'T BE QUIET SURE ABOUT THIS.",
      "CAN'T TELL YOU FOR SURE.",
      "DOES THAT REALLY MATERS TO YOU?"}},

    {{"THANK YOU"},
     {"YOU ARE WELCOME!",
      "YOU ARE A VERY POLITE PERSON!"}},

    {{"YOU"},
     {"SO,YOU ARE TALKING ABOUT ME.",
      "WHY DON'T WE TALK ABOUT YOU INSTEAD?",
      "ARE YOU TRYING TO MAKING FUN OF ME?"}},

    {{"YOU ARE RIGHT"},
     {"THANKS FOR THE COMPLIMENT!",
      "SO, I WAS RIGHT, OK I SEE.",
      "OK, I DIDN'T KNOW THAT I WAS RIGHT."}},

    {{"YOU ARE WELCOME"},
     {"OK, YOU TOO!",
      "YOU ARE A VERY POLITE PERSON!"}},

    {{"THANKS"},
     {"YOU ARE WELCOME!",
      "NO PROBLEM!"}},

    {{"WHAT ELSE"},
     {"WELL,I DON'T KNOW.",
      "WHAT ELSE SHOULD THERE BE?",
      "THIS LOOKS LIKE A COMPLICATED QUESTION TO ME."}},

    {{"SORRY"},
     {"YOU DON'T NEED TO BE SORRY USER.",
      "IT'S OK.",
      "NO NEED TO APOLOGIZE."}},

    {{"NOT EXACTLY"},
     {"WHAT DO YOU MEAN NOT EXACTLY?",
      "ARE YOU SURE?",
      "AND WHY NOT?",
      "DID YOU MEANT SOMETHING ELSE?"}},

    {{"EXACTLY"},
     {"SO,I WAS RIGHT.",
      "OK THEN.",
      "SO ARE BASICALY SAYING I AS ABOUT IT?"}},

    {{"ALRIGHT"},
     {"ALRIGHT THEN.",
      "OK THEN."}},

    {{"I DON'T"},
     {"WHY NOT?",
      "AND WHAT WOULD BE THE REASON FOR THIS?"}},

    {{"REALLY"},
     {"WELL,I CAN'T TELL YOU FOR SURE.",
      "ARE YOU TRYING TO CONFUSE ME?",
      "PLEASE DON'T ASK ME SUCH QUESTION,IT GIVES ME HEADEACHS."}},

    {{"NOTHING"},
     {"NOT A THING?",
      "ARE YOU SURE THAT THERE IS NOTHING?",
      "SORRY, BUT I DON'T BELIEVE YOU."}}};
size_t dimension = sizeof(database) / sizeof(database[0]);

void Chatbot::signOn() {
    handleEvent("SIGNON**");
    selectResponse();
    printResponse();
}

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

        // we inset a space character
        // before and after the keyword to
        // improve the matching process
        keyWord.insert(keyWord.begin(), ' ');
        keyWord.insert(keyWord.end(), ' ');

        // introduce thse new "string variable" to help
        // support the implementation of keyword ranking
        // during the matching process
        string bestKeyWord;
        vector<int> indexVector;

        // there has been some improvements made in
        // here in order to make the matching process
        // a littlebit more flexible
        if (userInput.find(keyWord) != string::npos) {
            //'keyword ranking' feature implemented in this section
            if (keyWord.length() > bestKeyWord.length()) {
                bestKeyWord = keyWord;
                indexVector.clear();
                indexVector.push_back(i);
            } else if (keyWord.length() == bestKeyWord.length()) {
                indexVector.push_back(i);
            }
        }

        if (indexVector.size() > 0) {
            shuffleArray(indexVector, indexVector.size());
            copy(database[indexVector[0]].response, responseList);
        }
    }
}

// preprocess the user's input
void Chatbot::preprocessInput() {
    cleanString(userInput);
    upperCase(userInput);
    userInput.insert(userInput.begin(), ' ');
    userInput.insert(userInput.end(), ' ');
}

// user repeat
bool Chatbot::isUserRepeat() const {
    return ((prevInput.length() > 0 && (userInput == prevInput)) || (userInput.find(prevInput) != string::npos) || (prevInput.find(userInput) != string::npos));
}

// Make the chatbot respond to the user's input
void Chatbot::respond() {
    // save previous response and set chatbot event
    savePreviousResponse();
    setEvent("BOT UNDERSTAND**");

    // check is null imput
    if (isNullInput()) {
        // handle event
        handleEvent("NULL INPUT**");
    } else if (isUserRepeat()) {
        handleUserRepetition();
    } else {
        findMatch();
    }

    if (isQuit()) quitProgram = 1;

    // if the bot dosen't understand the response
    if (!isUnderstood()) {
        handleEvent("BOT DONT UNDERSTAND**");
    }

    // if response list is not empty select a response then print it using functions from the chatbot class
    if (responseList.size() > 0) {
        selectResponse();

        if (isChatbotRepeat()) {
            handleRepetition();
        }
        printResponse();
    }
}

// Chatbot handle repetition using functions from the chatbot class
void Chatbot::handleRepetition() {
    // check if chatbot response list is empty, if true erase list
    if (responseList.size() > 0) {
        responseList.erase(responseList.begin());
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

    event.insert(event.begin(), ' ');
    event.insert(event.end(), ' ');

    setInput(event);
    if (!isSameEvent()) findMatch();
    restoreInput();
}

int main() {
    try {
        Chatbot chatbot("Jarvis");

        chatbot.signOn();

        // while the user doesn't want to quit the program
        while (!chatbot.isQuit()) {
            // get user input
            chatbot.getInput();

            // respond
            chatbot.respond();
        }
    } catch (string str) {
        cerr << str << endl;
    } catch (...) {
        cerr << "The program has stop due to some unknown exception" << std::endl;
    }

    return 0;
}