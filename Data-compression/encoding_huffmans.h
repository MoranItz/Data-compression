#pragma once

#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <bitset>

#define INPUT_SIZE 30
#define EMPTY_CHAR ""

using namespace std;

struct Node {
	unsigned int freq = NULL;
	unsigned int indx = NULL;
	struct Node* left = nullptr;
	struct Node* right = nullptr;
};

vector<char> getUserInput();
vector<char> getMapKeys(map<char, long> freqMap);
map<char, unsigned long long> getFreq(vector<char> data_v);
vector<bool> insertCurr(vector<bool> curr, bool code);
void calculateCodes(Node root, vector<bool>, vector<vector<bool>> &encodedFile);
map<char, vector<bool>> mapCodesAndLetters(map<char, unsigned long long> freqMap);