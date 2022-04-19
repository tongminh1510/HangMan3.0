//
//  Header.cpp
//  HangMan
//
//  Created by Minh Tống on 13/04/2022.
//

#include "RenderGame.hpp"

using namespace std;

void RenderGame(string &GuessWord, int &badguess, string word, int &TotalPoints, vector<char> &righ, vector<char> &wrong)
{
    if (badguess == 0)
    {
        cout << "CURRENTLY YOUR POINT IS: " << TotalPoints << endl
             << endl;
        cout << "THERE ARE TOTAL " << word.length() << " IN THIS WORD" << endl;
        cout << "-------------- "
             << "            " << GuessWord << endl;
        cout << "|            |" << endl;
        cout << "|" << endl;
        cout << "|" << endl;
        cout << "|" << endl;
        cout << "_" << endl;
        for (int i = 0; i < 2; i++)
        {
            cout << endl;
        }
        cout << "Những chữ cái không có là: ";
        for (int i = 0; i < wrong.size(); i++)
        {
            cout << wrong.at(i) << " ";
        }
        cout << endl;
        cout << "Những chữ cái đúng là: ";
        for (int i = 0; i < righ.size(); i++)
        {
            cout << righ.at(i) << " ";
        }
        for (int i = 0; i < 3; i++) cout << endl;
        cout << "My guess is: ";
    }
    else if (badguess == 1)
    {
        cout << "CURRENTLY YOUR POINT IS: " << TotalPoints << endl
             << endl;
        cout << "THERE ARE TOTAL " << word.length() << " IN THIS WORD" << endl;
        cout << "-------------- "
             << "            " << GuessWord << endl;
        cout << "|            |" << endl;
        cout << "|            0" << endl;
        cout << "|" << endl;
        cout << "|" << endl;
        cout << "_" << endl;
        for (int i = 0; i < 2; i++)
        {
            cout << endl;
        }
        cout << "Những chữ cái không có là: ";
        for (int i = 0; i < wrong.size(); i++)
        {
            cout << wrong.at(i) << " ";
        }
        cout << endl;
        cout << "Những chữ cái đúng là: ";
        for (int i = 0; i < righ.size(); i++)
        {
            cout << righ.at(i) << " ";
        }
        for (int i = 0; i < 3; i++) cout << endl;
        cout << "My guess is: ";
    }

    else if (badguess == 2)
    {
        cout << "CURRENTLY YOUR POINT IS: " << TotalPoints << endl
             << endl;
        cout << "THERE ARE TOTAL " << word.length() << " IN THIS WORD" << endl;
        cout << "-------------- "
             << "            " << GuessWord << endl;
        cout << "|            |" << endl;
        cout << "|            0" << endl;
        cout << "|            |" << endl;
        cout << "|" << endl;
        cout << "_" << endl;
        for (int i = 0; i < 2; i++)
        {
            cout << endl;
        }
        cout << "Những chữ cái không có là: ";
        for (int i = 0; i < wrong.size(); i++)
        {
            cout << wrong.at(i) << " ";
        }
        cout << endl;
        cout << "Những chữ cái đúng là: ";
        for (int i = 0; i < righ.size(); i++)
        {
            cout << righ.at(i) << " ";
        }
        for (int i = 0; i < 3; i++) cout << endl;
        cout << "My guess is: ";
    }

    else if (badguess == 3)
    {
        cout << "CURRENTLY YOUR POINT IS: " << TotalPoints << endl
             << endl;
        cout << "THERE ARE TOTAL " << word.length() << " IN THIS WORD" << endl;
        cout << "-------------- "
             << "            " << GuessWord << endl;
        cout << "|            |" << endl;
        cout << "|            0" << endl;
        cout << "|            |" << endl;
        cout << "|" << endl;
        cout << "_" << endl;
        for (int i = 0; i < 2; i++)
        {
            cout << endl;
        }
        cout << "Những chữ cái không có là: ";
        for (int i = 0; i < wrong.size(); i++)
        {
            cout << wrong.at(i) << " ";
        }
        cout << endl;
        cout << "Những chữ cái đúng là: ";
        for (int i = 0; i < righ.size(); i++)
        {
            cout << righ.at(i) << " ";
        }
        for (int i = 0; i < 3; i++) cout << endl;
        cout << "My guess is: ";
    }

    else if (badguess == 4)
    {
        cout << "CURRENTLY YOUR POINT IS: " << TotalPoints << endl
             << endl;
        cout << "THERE ARE TOTAL " << word.length() << " IN THIS WORD" << endl;
        cout << "-------------- "
             << "            " << GuessWord << endl;
        cout << "|            |" << endl;
        cout << "|            0" << endl;
        cout << "|           /|" << endl;
        cout << "|" << endl;
        cout << "_" << endl;
        for (int i = 0; i < 2; i++)
        {
            cout << endl;
        }
        cout << "Những chữ cái không có là: ";
        for (int i = 0; i < wrong.size(); i++)
        {
            cout << wrong.at(i) << " ";
        }
        cout << endl;
        cout << "Những chữ cái đúng là: ";
        for (int i = 0; i < righ.size(); i++)
        {
            cout << righ.at(i) << " ";
        }
        for (int i = 0; i < 3; i++) cout << endl;
        cout << "My guess is: ";
    }

    else if (badguess == 5)
    {
        cout << "CURRENTLY YOUR POINT IS: " << TotalPoints << endl
             << endl;
        cout << "THERE ARE TOTAL " << word.length() << " IN THIS WORD" << endl;
        cout << "-------------- "
             << "            " << GuessWord << endl;
        cout << "|            |" << endl;
        cout << "|            0" << endl;
        cout << "|           /|\\ " << endl;
        cout << "|" << endl;
        cout << "_" << endl;
        for (int i = 0; i < 2; i++)
        {
            cout << endl;
        }
        cout << "Những chữ cái không có là: ";
        for (int i = 0; i < wrong.size(); i++)
        {
            cout << wrong.at(i) << " ";
        }
        cout << endl;
        cout << "Những chữ cái đúng là: ";
        for (int i = 0; i < righ.size(); i++)
        {
            cout << righ.at(i) << " ";
        }
        for (int i = 0; i < 3; i++) cout << endl;
        cout << "My guess is: ";
    }

    else if (badguess == 6)
    {
        cout << "CURRENTLY YOUR POINT IS: " << TotalPoints << endl
             << endl;
        cout << "THERE ARE TOTAL " << word.length() << " IN THIS WORD" << endl;
        cout << "-------------- "
             << "            " << GuessWord << endl;
        cout << "|            | " << endl;
        cout << "|            0 " << endl;
        cout << "|           /|\\ " << endl;
        cout << "|           /" << endl;
        cout << "_" << endl;
        for (int i = 0; i < 2; i++)
        {
            cout << endl;
        }
        cout << "Những chữ cái không có là: ";
        for (int i = 0; i < wrong.size(); i++)
        {
            cout << wrong.at(i) << " ";
        }
        cout << endl;
        cout << "Những chữ cái đúng là: ";
        for (int i = 0; i < righ.size(); i++)
        {
            cout << righ.at(i) << " ";
        }
        for (int i = 0; i < 3; i++) cout << endl;
        cout << "My guess is: ";
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


void displayFinalResult(bool won, const string &word, int TotalPoints, bool congrat, string name)
{
    int i = 0;
    while (i < 20)
    {
        for (int i = 0; i < 30; i++)
            cout << endl;

        if (won == true && congrat == true)
        {
            cout << "YOUR ARE A GENIUS!!! CONGRATS " << name << endl
                 << endl;
            cout << "Congrats mtf!" << endl
                 << endl;
            cout << "YOUR TOTAL POINT IS: " << TotalPoints << endl
                 << endl;
            cout << "THE WORD IS: " << word << endl
                 << endl;
            cout << getNextDancingMan();
        }
        else if (won)
        {
            // cout << "YOUR ARE A GENIUS!!! CONGRATS " << name << endl << endl;
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
            cout << "THE WORD IS: " << word << endl
                 << endl;
            cout << "The correct word is " << word << endl
                 << getNextHangman();
        }
        // cout << (won ? getNextDancingMan() : getNextHangman());
        this_thread::sleep_for(chrono::milliseconds(1000));
        i++;
    }
}
