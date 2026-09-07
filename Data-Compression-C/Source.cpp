#include "frequency.h"
#include "hufftree.h"
#include "compression.h"

#define FILE_INPUT_PATH "C:\\Users\\jbt\\Desktop\\haha.txt"
#define FILE_OUTPUT_PATH "C:\\Users\\jbt\\Desktop\\haha.huff"

std::string getUserInput() {
	std::string data_s = "";

	std::cout << "Enter data string: ";
	std::getline(std::cin, data_s);

	return data_s;
}

int main() {
	std::map<char, std::string> codeMap;
	std::string curr;
	Node* root;
	std::vector<Node*> minheap;
	std::vector<std::pair<char, unsigned long long>> freqVec;
	std::map<char, unsigned long long> freqMap;

	scanFrequency(freqMap, FILE_INPUT_PATH);
	freqVec = sortFrequency(freqMap);
	minheap = buildMinheap(freqVec);
	root = buildHuffTree(minheap);
	calculateHuffCodes(root, codeMap, curr);

	compressToFile(FILE_INPUT_PATH, FILE_OUTPUT_PATH, codeMap);

	return 0;
}

//std::cout << std::endl;
//for (const auto& key : codeMap) {
//	std::cout << key.first << " : ";
//	for (int i = 0; i < key.second.size(); i++) {
//		std::cout << key.second[i];
//	}
//	std::cout << std::endl;
//}