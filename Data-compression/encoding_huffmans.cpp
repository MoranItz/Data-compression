#include "encoding_huffmans.h"



vector<char> getUserInput() {
	string data_s = "";

	cout << "Enter data string: ";
	getline(cin, data_s);
	cout << endl << data_s;

	return vector<char>(data_s.begin(), data_s.end());
}

vector<char> getMapKeys(map<char, long> freqMap) {
	vector<char> keys;

	for (auto i = freqMap.begin(); i != freqMap.end(); i++) {
		keys.push_back(i->first);
	}
	return keys;
}

map<char, unsigned long long> getFreq(vector<char> data_v) {
	map<char, unsigned long long> freqMap;

	for (int i = 0; i < data_v.size(); i++) {
		freqMap[data_v[i]]++;
	}
	return freqMap;
}

vector<bool> insertCurr(vector<bool> curr, bool code) {
	curr.push_back(code);
	return curr;
}

void calculateCodes(Node root, vector<bool> curr, vector<vector<bool>> &encodedFile) {
	try {
		if (root.left == nullptr && root.right == nullptr) {
			if (curr.size() == NULL) {
				curr.push_back(false);
			}
			encodedFile.push_back(curr);
			return;
		}
		calculateCodes(*root.left, insertCurr(curr, false), encodedFile);
		calculateCodes(*root.right, insertCurr(curr, true), encodedFile);
	}
	catch (int e) { // Root == NULL
		return;
	}
}

map<char, vector<bool>> mapCodesAndLetters(map<char, unsigned long long> freqMap)
{
	map<char, vector<bool>> codeMap;

	return map<char, vector<bool>>();
}



