#include "encoding_huffmans.h"

int main() {
	map<char, unsigned long long> freqMap;
	vector<char> data_v;
	data_v = getUserInput();
	freqMap = getFreq(data_v);

	return 0;
}