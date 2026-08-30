#pragma once

#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <bitset>
#include <algorithm>

#define INPUT_SIZE 30
#define EMPTY_CHAR ""

using namespace std;

struct Node {
	unsigned long long freq = NULL;
	unsigned int indx = NULL;
	char letter;
	struct Node* left = nullptr;
	struct Node* right = nullptr;
};

vector<char> getUserInput();
vector<char> getMapKeys(map<char, long> freqMap);
map<char, unsigned long long> getFreq(vector<char> data_v);
vector<bool> insertCurr(vector<bool> curr, bool code);
bool freqCmp(pair<char, unsigned long long> A, pair<char, unsigned long long> B);
vector<pair<char, unsigned long long>> sortMap(map<char, unsigned long long> &freqMap);
void calculateCodes(Node root, vector<bool>, vector<vector<bool>> *encodedFile);
Node* pop(vector<Node*>& minHeap);
void pushByFreq(vector<Node*>& minHeap, Node* newNode);
map<char, vector<bool>> mapCodesAndLetters(map<char, unsigned long long> freqMap);