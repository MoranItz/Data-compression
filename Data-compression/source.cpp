#include "encoding_huffmans.h"



int main() {
	map<char, vector<bool>> codeMap;
	map<char, unsigned long long> freqMap;
	vector<char> data_v;
	data_v = getUserInput();
	freqMap = getFreq(data_v);
	codeMap = mapCodesAndLetters(freqMap);

	cout << endl;
	for (const auto& key : codeMap) {
		cout << key.first << " : ";
		for (int i = 0; i < key.second.size(); i++) {
			if (key.second[i] == false) {
				cout << 0;
			}
			else {
				cout << 1;
			}
		}
		cout << endl;
	}
	return 0;
}