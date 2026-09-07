#include <chrono>

#include "compression.h"

#define FILE_INPUT_PATH "C:\\Users\\jbt\\Desktop\\haha.txt"
#define FILE_OUTPUT_PATH "C:\\Users\\jbt\\Desktop\\haha.huff"
#define FILE_OUTPUT2_PATH "C:\\Users\\jbt\\Desktop\\haha2.txt"

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

	std::string input = getUserInput();

	if (input == "C") {
		clock_t tStart = clock();

		scanFrequency(freqMap, FILE_INPUT_PATH);
		freqVec = sortFrequency(freqMap);
		minheap = buildMinheap(freqVec);
		root = buildHuffTree(minheap);
		calculateHuffCodes(root, codeMap, curr);

		compressFile(FILE_INPUT_PATH, FILE_OUTPUT_PATH, codeMap);

		std::cout << "Time taken: " << (1.0 * (clock() - tStart) / CLOCKS_PER_SEC) << "sec" << std::endl;
		//std::cout << "Input File Size : " << filesize("../input.txt") << " bytes." << std::endl;
		//std::cout << "Compressed File Size : " << filesize("../output.txt") << " bytes." << std::endl;
		//std::cout << "Compression Ratio : " << (1.0 * filesize("../output.txt") / filesize("../input.txt")) << std::endl;
	}
	else {
		clock_t tStart = clock();

		dehuffer(codeMap, FILE_OUTPUT_PATH, FILE_OUTPUT2_PATH);
		std::cout << "Time taken: " << (1.0 * (clock() - tStart) / CLOCKS_PER_SEC) << "sec" << std::endl;
	}
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