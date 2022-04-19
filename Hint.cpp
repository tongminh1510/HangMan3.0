//
//  Hint.cpp
//  HangMan
//
//  Created by Minh Tống on 13/04/2022.
//

#include "Hint.hpp"
#include <vector>
#include <algorithm>
#include <iostream>


using namespace std;

string GivePlayerHint(string &GuessWord, string word)
{
    int len = GuessWord.length();
    // cout << endl;
    // cout << len << endl << endl;
    // cout << GuessWord << endl;
    string tmp;
    tmp = GuessWord;
    int count = 0;
    int arr[count];
    for (int i = 0; i < len; i++)
    {
        if (tmp[i] == '-')
        {
            count++;
            // cout << count << endl;
            arr[count - 1] = i;
        }
    }
    int rado = rand() % count;

    int final = arr[rado];

    tmp[final] = word[final];
    char check = tmp[final];

    for (int i = 0; i < len; i++)
    {
        if (tmp[i] == '-' && word[i] == check)
        {
            tmp[i] = check;
        }
    }
    return tmp;
}

