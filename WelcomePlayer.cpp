//
//  WelcomePlayer.cpp
//  HangMan
//
//  Created by Minh Tống on 13/04/2022.
//

#include "WelcomePlayer.hpp"

using namespace std;

void welcome()
{
    cout << "Welcome to the Hangman 3.0. Are you ready for the challenge!!! \n \n"
            "Before enter to the game please input your name"
         << endl;
}

void rule()
{
    cout << "Hey! Here are the rules: (In Vietnamese) \n"
            "1. Có 3 chế độ chơi: Dễ, Trung bình, Khó \n"
            "2. Khi nào bạn muốn có gợi ý hay type help \n"
            "3. Chế độ gợi ý (help) chỉ áp dụng khi bạn chơi chế độ Khó \n"
            "4. Bạn sẽ có 2 chế độ gợi ý (help): \n"
            "               - Gợi ý thêm 1 chữ \n"
            "               - Gợi ý bằng tiếng Việt \n"
            "5. Khi bắt đầu game, bạn sẽ có tổng 100 điểm \n"
            "6. Mỗi khi bạn trả lời đúng, bạn sẽ được cộng 5 điểm, nếu trả lời sai bạn bị trừ 15 điểm \n";
    cout << endl;
}

void coutHint()
{
    cout << "Hiện giờ bạn đang chơi chế độ Khó. Đây là chế độ duy nhất có trợ giúp. \n"
            "Bạn sẽ được chọn 2 kiểu trợ giúp : \n"
            "1. Hiện một chữ cái. \n"
            "2. Nghĩa tiếng Việt của từ ngữ bạn đang tìm kiếm. \n"
            "LƯU Ý:  Mỗi lần sử dụng hội ý bạn sẽ mất 30 điểm";
    cout << endl;
    cout << "Chọn số chế độ help theo số tương ứng \n";
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

int take()
{
    int chooseHelp;
    cin >> chooseHelp;
    return chooseHelp;
}

string ReadGuess()
{
    string guess;
    cin >> guess;
    int len = guess.length();
    for (int i = 0; i < len; i++)
    {
        if (guess[i] >= 'A' && guess[i] <= 'Z')
            guess[i] = tolower(guess[i]);
    }
    return guess;
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

string InputName()
{
    string name;
    getline(cin, name);
    return name;
}

void DuplicateWord()
{
    cout << endl << "YOU HAVE ALREADY GUESSED THIS LETTER" << endl;
}
