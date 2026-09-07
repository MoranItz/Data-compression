#include "compression.h"

void writeHeader(std::ofstream& outputStream, std::map<char, std::string> codeMap) {
	for (const auto& item : codeMap) {
		outputStream << item.first << CHARACTER_CODE_SEPERATOR << item.second << HEADER_ENTRY_SEPERATOR;
	}
	outputStream << HEADER_TEXT_SEPERATOR;
}

void compressFile(std::string inputFilePath, std::string outputFilePath, std::map<char, std::string> codeMap) {
	char letter;
	std::string file;
	std::ifstream inputStream;
	std::ofstream outputStream;

	outputStream.open(outputFilePath);
	inputStream.open(inputFilePath);
	writeHeader(outputStream, codeMap);
	while (inputStream.get(letter)) {
		file += codeMap[letter];
	}
	inputStream.close();
	file += codeMap[PSEUDO_EOF];
	unsigned long remainder = (file.size() - 1) % 8;
	for (int i = 0; i < 8 - remainder; ++i)
		file += '0';
	std::stringstream stringStream(file);

	while (stringStream.good()) {
		std::bitset<8> bits;
		stringStream >> bits;
		char c = char(bits.to_ulong());
		outputStream << c;
	}


	outputStream.flush();
	outputStream.close();

}

void dehuffer(std::map<char, std::string>& codeMap, std::string compressedFilePath, std::string decompressedFilePath) {
	std::string line;
	std::string codeString;

	std::ifstream inputStream;
	inputStream.open(compressedFilePath);
	readHeader(inputStream, codeMap);

	while (getline(inputStream, line)) {
		for (int i = 0; i < line.size(); ++i) {
			std::bitset<8> bits(line[i]);
			codeString.append(bits.to_string());
		}
	}
	Node* root = buildDecodingTree(codeMap);
	decompressFile(codeString, root, decompressedFilePath);
}

void decompressFile(std::string codeString, Node* root, std::string decompressedFilePath) {
	std::ofstream outputStream;
	outputStream.open(decompressedFilePath, std::ios::out);

	Node* traversingNode = root;
	for (int i = 0; i < codeString.size(); ++i) {
		if (codeString[i] == '0') {
			traversingNode = traversingNode->left;
		}
		else {
			traversingNode = traversingNode->right;
		}

		if (traversingNode->letter != INTERNAL_NODE_CHARACTER) {
			if (traversingNode->letter == PSEUDO_EOF) {
				break;
			}
			outputStream << traversingNode->letter;
			traversingNode = root;
		}
	}
	outputStream.flush();
	outputStream.close();
}

Node* buildDecodingTree(std::map<char, std::string>& codeMap) {
	Node* root = new Node(NULL, NULL, INTERNAL_NODE_CHARACTER);
	Node* previousNode;

	for (const auto& item : codeMap) {
		previousNode = root;
		Node* newNode = new Node(NULL, NULL, item.first);
		std::string letterCode = item.second;

		for (int i = 0; i < letterCode.size(); ++i) {
			if (letterCode[i] == '0') {
				if (i == letterCode.size() - 1) {
					previousNode->left = newNode;
				}
				else {
					if (!previousNode->left) {
						previousNode->left = new Node(NULL, NULL, INTERNAL_NODE_CHARACTER);
						previousNode = previousNode->left;
					}
					else {
						previousNode = previousNode->left;
					}
				}
			}

			else {
				if (i == letterCode.size() - 1) {
					previousNode->right = newNode;
				}
				else {
					if (!previousNode->right) {
						previousNode->right = new Node(NULL, NULL, INTERNAL_NODE_CHARACTER);
						previousNode = previousNode->right;
					}
					else {
						previousNode = previousNode->right;
					}
				}
			}
		}
	}
	return root;
}

void readHeader(std::ifstream& inputStream, std::map<char, std::string>& codeMap) {
	codeMap.clear();
	char letter;
	
	inputStream.get(letter);
	char key = letter;

	while (letter != HEADER_TEXT_SEPERATOR) {
		if (letter == CHARACTER_CODE_SEPERATOR) {
			inputStream.get(letter);
			while (letter != HEADER_ENTRY_SEPERATOR) {
				codeMap[key] += letter;
				inputStream.get(letter);
			}
		}
		else {
			key = letter;
			inputStream.get(letter);
		}
	}
}
