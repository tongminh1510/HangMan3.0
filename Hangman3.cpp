#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <thread>
#include <chrono>

using namespace std;


string getLowerCaseString(const string& s)
{
    string res = s;
    int sz = s.size();
    for(int i = 0; i < sz; i++) {
        res[i] = tolower(s[i]);
    }
    return res;
}

string chooseword(const char* fileName) {
    vector<string> wordList;  
    ifstream file(fileName);
    if(file.is_open()) {
        string word;
        while(file >> word) {
            wordList.push_back(word);
        }
        file.close();
    }
    if(wordList.size() > 0) {
        int randomIndex = rand() % wordList.size();
        return getLowerCaseString(wordList[randomIndex]);
    } else return "";

    /*int n = rando();
    string s[6] = {"hello", "bravo", "check", "Ielts", "nigga", "comprehensive"};
    string ss = s[n];
    return ss;*/
}

char ReadGuess() {
    char guess;
    cin >> guess;
    return guess;
}

void RenderGame(string &GuessWord, int &badguess, string word) {
    if(badguess == 0) {
        cout << "THERE ARE TOTAL " << word.length() << " IN THIS WORD" << endl;
        cout << "-------------- " << "            " << GuessWord << endl;
        cout << "|            |" << endl;
        cout << "|" << endl;
        cout << "|" << endl;
        cout << "|" << endl;
        cout << "_" << endl;
    }
    else if(badguess == 1) {
        cout << "THERE ARE TOTAL " << word.length() << " IN THIS WORD" << endl;
        cout << "-------------- " << "            " << GuessWord << endl;
        cout << "|            |" << endl;
        cout << "|            0" << endl;
        cout << "|" << endl;
        cout << "|" << endl;
        cout << "_" << endl;
    } 

    else if(badguess == 2) {
        cout << "THERE ARE TOTAL " << word.length() << " IN THIS WORD" << endl;
        cout << "-------------- " << "            " << GuessWord << endl;
        cout << "|            |" << endl;
        cout << "|            0" << endl;
        cout << "|            |" << endl;
        cout << "|" << endl;
        cout << "_" << endl;
    } 

    else if(badguess == 3) {
        cout << "-------------- " << "            " << GuessWord << endl;
        cout << "|            |" << endl;
        cout << "|            0" << endl;
        cout << "|            |" << endl;
        cout << "|" << endl;
        cout << "_" << endl;
    } 

    else if(badguess == 4) {
        cout << "THERE ARE TOTAL " << word.length() << " IN THIS WORD" << endl;
        cout << "-------------- " << "            " << GuessWord << endl;
        cout << "|            |" << endl;
        cout << "|            0" << endl;
        cout << "|           /|" << endl;
        cout << "|" << endl;
        cout << "_" << endl;
    } 
    

    else if(badguess == 5) {
        cout << "THERE ARE TOTAL " << word.length() << " IN THIS WORD" << endl;
        cout << "-------------- " << "            " << GuessWord << endl;
        cout << "|            |" << endl;
        cout << "|            0" << endl;
        cout << "|           /|\\ " << endl;
        cout << "|" << endl;
        cout << "_" << endl;
    } 

    else if(badguess == 6) {
        cout << "THERE ARE TOTAL " << word.length() << " IN THIS WORD" << endl;
        cout << "-------------- " << "            " << GuessWord << endl;
        cout << "|            | " << endl;
        cout << "|            0 " << endl;
        cout << "|           /|\\ " << endl;
        cout << "|           /" << endl; 
        cout << "_" << endl;
    } 

    /*else if(badguess == 7) {
        cout << "-------------- " << "            " << GuessWord << endl;
        cout << "|            | " << endl;
        cout << "|            0 " << endl;
        cout << "|           /|\\ " << endl;
        cout << "|           / \\" << endl; 
        cout << "_" << endl;
    }*/

}

bool contain(string &word, char read) {
    bool check = false;
    int len = word.length();
    for(int i = 0; i < len; i++) {
        if(word[i] == read) {
            check = true;
            break;
        }
    }
    return check;
}

string Update(string &GuessWord, char read, string &word) {
    int len = word.length();
    for(int i = 0; i < len; i++) {
        if(word[i] == read) GuessWord[i] = read;
    }
    return GuessWord;
}


const string& getNextHangman()
{
    const static string figure[] = {
        "--------------     \n"
        "|            /         \n"
        "|           0          \n"
        "|          /|\\        \n"
        "|          / \\       \n"
        "-----        \n",
        "--------------      \n"
        "|              |     \n"
        "|              0     \n"
        "|             /|\\        \n"
        "|             /  \\       \n"
        "-----        \n",

         "--------------      \n"
        "|              \\     \n"
        "|                0     \n"
        "|               /|\\        \n"
        "|               /  \\       \n"
        "-----        \n",

           "--------------      \n"
        "|              |     \n"
        "|              0     \n"
        "|             /|\\        \n"
        "|             /  \\       \n"
        "-----        \n",

    };
    const int Number_Of_Figures = sizeof(figure) / sizeof(string);
    static int currentFigure = 0;
    return figure[(currentFigure)++ % 4];

}

const string& getNextDancingMan()
{
    const static string figure[] = {
        "           0          \n"
        "          /|\\        \n"
        "          | |       \n"
        "       \n",
        "           0          \n"
        "          /|\\        \n"
        "          / \\       \n"
        "       \n",

        "           0          \n"
        "         --|--        \n"
        "          / \\       \n"
        "       \n",

        "          \\0/          \n"
        "           |        \n"
        "          / \\       \n"
        "       \n"
    };
    const int Number_Of_Figures = sizeof(figure) / sizeof(string);
    static int currentFigure = 0;
    return figure[(currentFigure)++ % 4];
}

void displayFinalResult(bool won, const string& word, int TotalPoints) {
    int i = 0;
    while(i < 30) {
        for(int i = 0; i < 30; i++) cout << endl;
        if(won) {
            cout << "Congrats mtf!" << endl << endl;
            cout << "YOUR TOTAL POINT IS: " << TotalPoints << endl << endl;
            cout << getNextDancingMan();
        }
        else{
            cout << "YOU LOST. BETTER LUCK NEXT TIME " << endl << endl;
            cout << "YOUR TOTAL POINT IS: " << TotalPoints << endl << endl;
            cout << "The correct word is " << word << endl << getNextHangman() ;
        }  
        //cout << (won ? getNextDancingMan() : getNextHangman());
        this_thread::sleep_for(chrono::milliseconds(500));
        i++;
    }
}


int choosemode() {
    int mode;
    cout << "Input the mode of game that you want to play : \n"
            "1. Hard \n"
            "2. Medium \n"
            "3. Easy \n";
    cout << endl;
    cin >> mode;
    return mode;
}

int chooseTopic()
{
    int n;

    cout << "Let's choose the topic of words that you want to guess about \n "
            "Input the number of the topic that you want to chooose: \n"
            "1. Animals \n"
            "2. Brand \n"
            "3. Sports \n ";
    cout << endl;
    cin >> n;

    return n;
}


string pickup(int x, int n) {
    string word;
    if(x == 1) {
        if(n == 1) word = chooseword("AnimalsHard.txt");
        else if(n == 2) word = chooseword("BrandHard.txt");
        else if(n == 3) word = chooseword("SportsHard.txt"); 
    }
    if(x == 2) {
        if(n == 1) word = chooseword("AnimalsMedium.txt");
        else if(n == 2) word = chooseword("BrandMedium.txt");
        else if(n == 3) word = chooseword("SportsMedium.txt"); 
    }
    if(x == 3) {
        if(n == 1) word = chooseword("AnimalsEasy.txt");
        else if(n == 2) word = chooseword("BrandEasy.txt");
        else if(n == 3) word = chooseword("SportsEasy.txt"); 
    }
    return word;
}

int main ()
{
    int TotalPoints = 50;
    string again;


    do {
    srand(time(0));
    cout << "Welcome to the Hangman 3.0. Are you ready for the challenge !!! " << endl;

    int x = choosemode(); // chon do kho 
    int n = chooseTopic(); // chon chu de
    string word = pickup(x, n); // đưa ra word
    
    int badguess = 0;

    string GuessWord = string(word.length(), '_');
    //cout << "THERE ARE TOTAL " << word.length() << " IN THIS WORD" << endl;
    const int Max_Bad_Guess = 7;
    
    do {
        RenderGame(GuessWord, badguess, word); // hiển thị giá treo cổ, chữ đã đoán đc
        char read = ReadGuess(); // hàm nhập chữ cái mình đoán

        if(contain(word, read) == true) { // có bao gồm chữ trong chuỗi không
            GuessWord = Update(GuessWord, read, word); // update chữ 
            TotalPoints += 10;
            cout << endl;
            cout << TotalPoints << endl;
        }else {
            badguess++;
            TotalPoints -= 10;
            cout << endl;
            cout << TotalPoints << endl;
        } 
    }while(badguess < Max_Bad_Guess && word != GuessWord);

    RenderGame(GuessWord, badguess, word);
    bool won = false;
    if(badguess < 7) won = true;
    displayFinalResult(won, word, TotalPoints);
    cout << "DO YOU WANT TO PLAY AGAIN MATE? y/n " << endl << endl;

    cin >> again;

    }while(again == "y");

    return 0;
}