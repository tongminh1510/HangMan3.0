#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <thread>
#include <chrono>
#include <string>
#include <cstdlib>

using namespace std;

string name;

void welcome()
{
    cout << "Welcome to the Hangman 3.0. Are you ready for the challenge!!! \n \n"
            "Before enter to the game please input your name" << endl;
}

void rule () {
    cout << "Hey! Here is the rule: (In Vietnamese) \n" 
            "1. Có 3 chế độ chơi: Dễ, Trung bình, Khó \n"
            "2. Khi nào bạn muốn có gợi ý hay type help \n"
            "3. Chế độ gợi ý (help) chỉ áp dụng khi bạn chơi chế độ Khó \n"
            "4. Bạn sẽ có 2 chế độ gợi ý (help): \n"
            "               - Gợi ý thêm 1 chữ \n"
            "               - Gợi ý bằng tiếng Việt \n"
            "5. Khi bắt đầu game, bạn sẽ có tổng 100 điểm \n"
            "6. Mỗi khi bạn trả lời đúng, bạn sẽ được cộng 5 điểm, nếu trả lời sai bạn bị trừ 10 điểm \n";
    cout << endl;
}

bool check(string read, string word) {
    int readlen = read.length();
    //int wordlen = word.length();
    int count = 0;
    for(int i = 0; i < read.length(); i++) {
        if(read[i] != word[i]) count++; 
    }
    if(count <= 2) return true;
    else return false;
}

string InputName() {
    string name;
    cin >> name;
    return name;
}

string getLowerCaseString(const string &s)
{
    string res = s;
    int sz = s.size();
    for (int i = 0; i < sz; i++)
    {
        res[i] = tolower(s[i]);
    }
    return res;
}

string chooseword(const char *fileName)
{
    vector<string> wordList;
    ifstream file(fileName);
    if (file.is_open())
    {
        string word;
        while (getline(file, word))
        {
            wordList.push_back(word);
        }
        file.close();
    }
    if (wordList.size() > 0)
    {
        int randomIndex = rand() % wordList.size();
        return getLowerCaseString(wordList[randomIndex]);
    }
    else
        return "";

    /*int n = rando();
    string s[6] = {"hello", "bravo", "check", "Ielts", "nigga", "comprehensive"};
    string ss = s[n];
    return ss;*/
}

string ReadGuess()
{
    string guess;
    cin >> guess;
    return guess;
}

void RenderGame(string &GuessWord, int &badguess, string word, int& TotalPoints)
{
    if (badguess == 0)
    {
        cout << "CURRENTLY YOUR POINT IS: " << TotalPoints << endl << endl;
        cout << "THERE ARE TOTAL " << word.length() << " IN THIS WORD" << endl;
        cout << "-------------- "
             << "            " << GuessWord << endl;
        cout << "|            |" << endl;
        cout << "|" << endl;
        cout << "|" << endl;
        cout << "|" << endl;
        cout << "_" << endl;
    }
    else if (badguess == 1)
    {
        cout << "CURRENTLY YOUR POINT IS: " << TotalPoints << endl << endl;
        cout << "THERE ARE TOTAL " << word.length() << " IN THIS WORD" << endl;
        cout << "-------------- "
             << "            " << GuessWord << endl;
        cout << "|            |" << endl;
        cout << "|            0" << endl;
        cout << "|" << endl;
        cout << "|" << endl;
        cout << "_" << endl;
    }

    else if (badguess == 2)
    {
        cout << "CURRENTLY YOUR POINT IS: " << TotalPoints << endl << endl;
        cout << "THERE ARE TOTAL " << word.length() << " IN THIS WORD" << endl;
        cout << "-------------- "
             << "            " << GuessWord << endl;
        cout << "|            |" << endl;
        cout << "|            0" << endl;
        cout << "|            |" << endl;
        cout << "|" << endl;
        cout << "_" << endl;
    }

    else if (badguess == 3)
    {
        cout << "CURRENTLY YOUR POINT IS: " << TotalPoints << endl << endl;
        cout << "THERE ARE TOTAL " << word.length() << " IN THIS WORD" << endl;
        cout << "-------------- "
             << "            " << GuessWord << endl;
        cout << "|            |" << endl;
        cout << "|            0" << endl;
        cout << "|            |" << endl;
        cout << "|" << endl;
        cout << "_" << endl;
    }

    else if (badguess == 4)
    {
        cout << "CURRENTLY YOUR POINT IS: " << TotalPoints << endl << endl;
        cout << "THERE ARE TOTAL " << word.length() << " IN THIS WORD" << endl;
        cout << "-------------- "
             << "            " << GuessWord << endl;
        cout << "|            |" << endl;
        cout << "|            0" << endl;
        cout << "|           /|" << endl;
        cout << "|" << endl;
        cout << "_" << endl;
    }

    else if (badguess == 5)
    {
        cout << "CURRENTLY YOUR POINT IS: " << TotalPoints << endl << endl;
        cout << "THERE ARE TOTAL " << word.length() << " IN THIS WORD" << endl;
        cout << "-------------- "
             << "            " << GuessWord << endl;
        cout << "|            |" << endl;
        cout << "|            0" << endl;
        cout << "|           /|\\ " << endl;
        cout << "|" << endl;
        cout << "_" << endl;
    }

    else if (badguess == 6)
    {
        cout << "CURRENTLY YOUR POINT IS: " << TotalPoints << endl << endl;
        cout << "THERE ARE TOTAL " << word.length() << " IN THIS WORD" << endl;
        cout << "-------------- "
             << "            " << GuessWord << endl;
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

bool contain(string &word, char read)
{
    bool check = false;
    int len = word.length();
    for (int i = 0; i < len; i++)
    {
        if (word[i] == read)
        {
            check = true;
            break;
        }
    }
    return check;
}

string Update(string &GuessWord, char read, string &word)
{
    int len = word.length();
    for (int i = 0; i < len; i++)
    {
        if (word[i] == read)
            GuessWord[i] = read;
    }
    return GuessWord;
}

const string &getNextHangman()
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

const string &getNextDancingMan()
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
        "       \n"};
    const int Number_Of_Figures = sizeof(figure) / sizeof(string);
    static int currentFigure = 0;
    return figure[(currentFigure)++ % 4];
}

void displayFinalResult(bool won, const string &word, int TotalPoints,bool congrat)
{
    int i = 0;
    while (i < 5)
    {
        for (int i = 0; i < 30; i++)
            cout << endl;
        
        if (won == true && congrat == true)
        {
            cout << "YOUR ARE A GENIUS!!! CONGRATS " << name << endl << endl; 
            cout << "Congrats mtf!" << endl
                 << endl;
            cout << "YOUR TOTAL POINT IS: " << TotalPoints << endl
                 << endl;
            cout << getNextDancingMan();
        }
        else if(won)
        {
            cout << "YOUR ARE A GENIUS!!! CONGRATS " << name << endl << endl; 
            cout << "Congrats mtf!" << endl
                 << endl;
            cout << "YOUR TOTAL POINT IS: " << TotalPoints << endl
                 << endl;
            cout << getNextDancingMan();
        }
        else
        {
            cout << "YOU LOST. BETTER LUCK NEXT TIME " << endl
                 << endl;
            cout << "YOUR TOTAL POINT IS: " << TotalPoints << endl
                 << endl;
            cout << "The correct word is " << word << endl
                 << getNextHangman();
        }
        // cout << (won ? getNextDancingMan() : getNextHangman());
        this_thread::sleep_for(chrono::milliseconds(500));
        i++;
    }
}

int choosemode()
{
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

string pickup(int x, int n)
{
    string word;
    if (x == 1)
    {
        if (n == 1)
            word = chooseword("AnimalsHard.txt");
        else if (n == 2)
            word = chooseword("BrandHard.txt");
        else if (n == 3)
            word = chooseword("SportsHard.txt");
    }
    if (x == 2)
    {
        if (n == 1)
            word = chooseword("AnimalsMedium.txt");
        else if (n == 2)
            word = chooseword("BrandMedium.txt");
        else if (n == 3)
            word = chooseword("SportsMedium.txt");
    }
    if (x == 3)
    {
        if (n == 1)
            word = chooseword("AnimalsEasy.txt");
        else if (n == 2)
            word = chooseword("BrandEasy.txt");
        else if (n == 3)
            word = chooseword("SportsEasy.txt");
    }
    return word;
}

string makeBlank(string answer)
{
    string word = "";
    for (int i = 0; i < answer.length(); i++)
    {
        if (answer[i] == ' ')
            word += " ";
        else
            word += "-";
    }
    return word;
}

string GivePlayerHint(string &GuessWord, string word) {
    int len = GuessWord.length();
    //cout << endl;
    //cout << len << endl << endl;
    //cout << GuessWord << endl;
    int count = 0;
    int arr[count]; 
    for(int i = 0; i < len; i++) {
        if(GuessWord[i] == '-') {
            count++;
            //cout << count << endl;
            arr[count - 1] = i;
        }
    }
    int rado = rand() % count;

    int final = arr[rado];

    GuessWord[final] = word[final];
    char check = GuessWord[final];

    for(int i = 0; i < len; i++) {
        if(GuessWord[i] == '-' &&  word[i] == check) {
            GuessWord[i] = check;
        }
    }
    return GuessWord;
}

int take()
{
    int chooseHelp;
    cin >> chooseHelp;
    return chooseHelp;
}

int main()
{
    int TotalPoints = 100;
    string again;

    welcome(); //chao mung nguoi choi
    cout << endl;
    name = InputName(); //nhap ten nguoi choi

    do
    {
        srand(time(0)); 

        rule(); //luat choi
        cout << endl;

        int x = choosemode();       // chon do kho
        int n = chooseTopic();      // chon chu de
        string word = pickup(x, n); // máy đưa ra word

        int badguess = 0;

        string GuessWord = makeBlank(word);

        // cout << "THERE ARE TOTAL " << word.length() << " IN THIS WORD" << endl;
        const int Max_Bad_Guess = 7;
        cout << "YOUR CURRENT POINT IS: " << TotalPoints << endl;
        bool congrat = false;
        do
        {
            //int minute = 90;
            // this_thread::sleep_for(chrono::milliseconds(1000));
            //cout << minute;
            RenderGame(GuessWord, badguess, word, TotalPoints); // hiển thị giá treo cổ, chữ đã đoán đc

            string read = ReadGuess(); // hàm nhập chữ cái mình đoán

            char help = read[0]; //neu nguoi choi nhap 1 chu cai thi doan, nhap do dai thi check, nhap help thi dua ra tro giup

            if(read.size() == 1) {
                if (contain(word, help) == true)   // có bao gồm chữ trong chuỗi không
                {                                              
                    GuessWord = Update(GuessWord, help, word); // update chữ
                    TotalPoints += 5;
                    cout << endl;
                    cout << TotalPoints << endl;
                }
                else
                {
                    badguess++;
                    TotalPoints -= 10;
                    cout << endl;
                    cout << TotalPoints << endl;
                }
            }
            else if(read != "help") { //nếu người chơi đoán cả chữ mà không cần gợi ý 
                if(read == word) {
                    //cout << "YOUR ARE A GENIUS!!! CONGRATS " << name << endl;
                    congrat = true;
                    break;
                }
                else {
                    TotalPoints -= 50;
                    if(TotalPoints > 0) {
                        cout << endl;
                        if(check(read, word) == true) cout << "SO CLOSE! JUST A LITTLE BIT MORE !!" << endl << endl;  //check xem ket qua co "gan dung" hay khong 
                        else cout << "WRONG" << endl;
                    }
                }
            }
            else // người chơi cần sự trợ giúp
            {
                /*if(x == 1) {
                    cout << "Hiện giờ bạn đang chơi chế độ Khó. Đây là chế độ duy nhất có trợ giúp. \n"
                            "Bạn sẽ được chọn 2 kiểu trợ giúp : \n"
                            "1. Hiện một chữ cái. \n"
                            "2. Nghĩa tiếng Việt của từ ngữ bạn đang tìm kiếm. \n";
                    cout << endl;
                    cout << "Chọn số chế độ help theo số tương ứng \n";
                    int chooseHelp = take();
                    if(chooseHelp == 1) {
                        GuessWord = GivePlayerHint(GuessWord, word); // đưa ra hint cho người chơi bằng cách show 1 chữ cái cho người chơi
                    }
                }*/   
                GuessWord = GivePlayerHint(GuessWord, word); // đưa ra hint cho người chơi bằng cách show 1 chữ cái cho người chơi
                if(GuessWord == word) break;         
            }
            if (TotalPoints <= 0)
            {
                cout << "YOU RAN OUT OF POINT!!" << endl << endl << "YOU ARE DEAD";
                break;
            }
        } while (badguess < Max_Bad_Guess && word != GuessWord);

        // RenderGame(GuessWord, badguess, word);
        bool won = false;

        if(GuessWord == word) won = true;

        //if(congrat == true) cout << "YOUR ARE A GENIUS!!! CONGRATS " << name << endl << endl; 
        if (badguess < 7 && congrat == true)
            won = true;
        displayFinalResult(won, word, TotalPoints, congrat);
        cout << "DO YOU WANT TO PLAY AGAIN MATE? y/n " << endl
             << endl;

        cin >> again;

    } while (again == "y");

    cout << "HAVE A GREAT DAY";

    return 0;
}
