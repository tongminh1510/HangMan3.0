//
//  Word.hpp
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

string makeBlank(string answer);
bool check(string read, string word);
bool alreadyExisted(char n, vector<char> check);
