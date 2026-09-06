#include "frequency.h"
#include "hufftree.h"

#define FILE_PATH "C:\\Users\\jbt\\Desktop\\haha.txt"

std::string getUserInput() {
	std::string data_s = "";

	std::cout << "Enter data string: ";
	std::getline(std::cin, data_s);

	return data_s;
}

int main() {
	std::vector<std::pair<char, std::vector<char>>> codeVec;
	std::vector<char> curr;
	Node* root;
	std::vector<Node*> minheap;
	std::vector<std::pair<char, unsigned long long>> freqVec;
	std::map<char, unsigned long long> freqMap;
	//std::string temp = getUserInput();
	scanFrequency(freqMap, FILE_PATH);
	freqVec = sortFrequency(freqMap);
	minheap = buildMinheap(freqVec);
	root = buildHuffTree(minheap);
	calculateHuffCodes(root, codeVec, curr);

	std::cout << std::endl;
	for (const auto& pair : codeVec) {
		std::cout << pair.first << " : ";
		for (int i = 0; i < pair.second.size(); i++) {
			std::cout << pair.second[i];
		}
		std::cout << std::endl;
	}

	return 0;
}