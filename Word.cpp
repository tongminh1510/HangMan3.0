//
//  Word.cpp
//  HangMan
//
//  Created by Minh Tống on 13/04/2022.
//

#include "Word.hpp"

using namespace std;

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

bool check(string read, string word)
{
    int readlen = read.length();
    // int wordlen = word.length();
    int count = 0;
    for (int i = 0; i < read.length(); i++)
    {
        if (read[i] != word[i])
            count++;
    }
    if (count <= 2)
        return true;
    else
        return false;
}

bool alreadyExisted(char n, vector<char> check)
{
    for (int i = 0; i < check.size(); i++)
    {
        if (n == check.at(i))
            return false;
    }
    return true;
}
