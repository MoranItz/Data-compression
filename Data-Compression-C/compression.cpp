#include "compression.h"

void writeHeader(std::ofstream& outputStream, std::map<char, std::string> codeMap) {
	for (const auto& item : codeMap) {
		outputStream << item.first << CHARACTER_CODE_SEPERATOR << item.second << HEADER_ENTRY_SEPERATOR;
	}
	outputStream << HEADER_TEXT_SEPERATOR;
}

void compressToFile(std::string inputFilePath, std::string outputFilePath, std::map<char, std::string> codeMap) {
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
