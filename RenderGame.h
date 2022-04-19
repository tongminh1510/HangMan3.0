//
//  Header.hpp
//  HangMan
//
//  Created by Minh Tống on 13/04/2022.
//

#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <thread>
#include <chrono>
#include <string>
#include <cstdlib>
#include <cstring>


using namespace std;

void RenderGame(string &GuessWord, int &badguess, string word, int &TotalPoints, vector<char> &righ, vector<char> &wrong);
const string &getNextDancingMan();
const string &getNextHangman();
void displayFinalResult(bool won, const string &word, int TotalPoints, bool congrat, string name);
