#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <thread>
#include <chrono>
#include <string>
#include <cstdlib>
#include <cstring>
#include "RenderGame.hpp"
#include "WelcomePlayer.hpp"
#include "Hint.hpp"
#include "Word.hpp"
#include <SDL2/SDL.h>


using namespace std;

int numberHint;

bool checkPoint(int n)
{
    if (n <= 0)
    {
        return false;
    }
    return true;
}

string chooseHint(const char *fileName)
{
    vector<string> wordList;
    ifstream file(fileName);
    if (file.is_open())
    {
        string hint;
        while (getline(file, hint))
        {
            wordList.push_back(hint);
        }
        file.close();
    }
    if (wordList.size() > 0)
    {
        int randomIndex = numberHint;
        return wordList[randomIndex];
    }
    else
        return "";
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
        numberHint = randomIndex;
        return getLowerCaseString(wordList[randomIndex]);
    }
    else
        return "";

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

string pickupHint(int x, int n)
{
    string hint;
    string no = "no";
    if (x == 1)
    {
        if (n == 1)
            hint = chooseHint("AnimalsHardHint.txt");
    }
    else if (x == 2)
    {
        // cout << "R???t ti???c ch??? ????? ch??i Medium kh??ng h??? tr??? g???i ??" << endl << endl;
        return no;
    }
    else
    {
        // cout << "R???t ti???c ch??? ????? ch??i Easy kh??ng h??? tr??? g???i ??" << endl << endl;
        return no;
    }
    return hint;
}

int main()
{
    // int TotalPoints = 100;
    char again;

    welcome(); // chao mung nguoi choi
    cout << endl;
    string name;
    name = InputName(); // nhap ten nguoi choi

    do
    {
        srand(time(0));

        int TotalPoints = 100;

        if (checkPoint(TotalPoints) == false)
        {
            cout << "YOU RAN OUT OF POINT!!" << endl
                 << endl
                 << "YOU ARE DEAD";
            return 0;
        }

        rule(); // luat choi
        cout << endl;

        int x = choosemode();       // chon do kho
        int n = chooseTopic();      // chon chu de
        string word = pickup(x, n); // m??y ????a ra word

        string choooseHint;             // goi y bang tieng Viet
        string hint = pickupHint(x, n); // goi y
        int badguess = 0;

        string GuessWord = makeBlank(word);
        cout << word << endl;

        const int Max_Bad_Guess = 7;
        cout << "YOUR CURRENT POINT IS: " << TotalPoints << endl;
        bool congrat = false;

        vector<char> wrong; // tat ca chu cai doan sai
        vector<char> righ;  // tat ca chu cai doan dung
        vector<char> all; // tat ca cac chu cai da doan
        int len = all.size();

        do
        {
            RenderGame(GuessWord, badguess, word, TotalPoints, righ, wrong); // hi???n th??? gi?? treo c???, ch??? ???? ??o??n ??c

            string read = ReadGuess(); // h??m nh???p ch??? c??i m??nh ??o??n
            cout << endl;

            char help = read[0]; // neu nguoi choi nhap 1 chu cai thi doan, nhap do dai thi check, nhap help thi dua ra tro giup
            cout << endl;

            // all.push_back(help);
            if (alreadyExisted(help, all) == true)
                all.push_back(help);

            for (int i = 0; i < all.size(); i++)
                cout << all.at(i) << " ";
            cout << endl;

            // bool checktrung = true; // h??m check xem ch??? c??i ???? ??o??n ch??a, n???u ??o??n r???i th?? kh??ng ??c c???ng ??i???m
            bool hello = false;
            if (read.size() == 1)
            {
                if (contain(word, help) == true) // c?? bao g???m ch??? trong chu???i kh??ng
                {
                    if (alreadyExisted(help, righ) == true)
                    {
                        righ.push_back(help);
                        hello = true;
                    }
                    if (hello == true) // check xem co trung voi nhung tu da doan khong
                    {
                        // cout << checktrung(help) << endl;
                        TotalPoints += 5;
                    }
                    else
                    {
                        TotalPoints += 0;
                        cout << endl << "YOU HAVE ALREADY GUESSED THIS LETTER" << endl;
                    }
                    hello = false;
                    GuessWord = Update(GuessWord, help, word); // update ch???
                    cout << endl;
                }
                else
                {
                    if (alreadyExisted(help, wrong) == true)
                    {
                        wrong.push_back(help);
                        hello = true;
                    }
                    badguess++; // cong so lan doan sai

                    if (hello == true) // check xem co trung voi nhun tu da doan khong
                    {
                        // cout << checktrung(help) << endl;
                        TotalPoints -= 15;
                    }
                    else
                    {
                        TotalPoints += 0;
                        DuplicateWord();
                        badguess--;
                    }
                    hello = false;
                    cout << endl;
                }
            }
            else if (read != "help")
            { // n???u ng?????i ch??i ??o??n c??? ch??? m?? kh??ng c???n g???i ??
                if (read == word)
                {
                    // cout << "YOUR ARE A GENIUS!!! CONGRATS " << name << endl;
                    congrat = true;
                    break;
                }
                else
                {
                    TotalPoints -= 50;
                    if (TotalPoints > 0)
                    {
                        cout << endl;
                        if (check(read, word) == true)
                            cout << "SO CLOSE! JUST A LITTLE BIT MORE !!" << endl
                                 << endl; // check xem ket qua co "gan dung" hay khong
                        else
                            cout << "WRONG" << endl;
                    }
                }
            }
            else if(read == "help") // ng?????i ch??i c???n s??? tr??? gi??p
            {
                int chooseHelp;
                if (x == 1)
                {
                    TotalPoints -= 30;
                    if (checkPoint(TotalPoints) == false)
                    {
                        cout << "YOU RAN OUT OF POINT!!" << endl
                             << endl
                             << "YOU ARE DEAD";
                        break;
                    }
                    int checkHint;
                    coutHint();

                    chooseHelp = take();

                    if (chooseHelp == 1)
                    {
                        GuessWord = GivePlayerHint(GuessWord, word); // ????a ra hint cho ng?????i ch??i b???ng c??ch show 1 ch??? c??i cho ng?????i ch??i
                    }
                    else
                        cout << "\nG???i ?? c???a b???n b???ng ti???ng Vi???t l??: " << pickupHint(x, n) << endl
                             << endl;
                }
                else
                    cout << "G???i ?? kh??ng ??p d???ng cho ch??? ????? ch??i n??y.";
                // GuessWord = GivePlayerHint(GuessWord, word); // ????a ra hint cho ng?????i ch??i b???ng c??ch show 1 ch??? c??i cho ng?????i ch??i
                if (GuessWord == word)
                    break;
            }
            if (TotalPoints <= 0)
            {
                cout << "YOU RAN OUT OF POINT!!" << endl
                     << endl
                     << "YOU ARE DEAD";
                break;
            }
        } while (badguess < Max_Bad_Guess && word != GuessWord);

        // RenderGame(GuessWord, badguess, word);
        bool won = false;

        if (GuessWord == word)
            won = true;

        // if(congrat == true) cout << "YOUR ARE A GENIUS!!! CONGRATS " << name << endl << endl;
        if (badguess < 7 && congrat == true)
            won = true;
        displayFinalResult(won, word, TotalPoints, congrat, name);
        cout << "DO YOU WANT TO PLAY AGAIN MATE? y/n " << endl
             << endl;

        cin >> again;
        again = tolower(again);
        cout << endl;

    } while (again == 'y');

    cout << "HAVE A GREAT DAY";

    return 0;

    
    return 0;
}

