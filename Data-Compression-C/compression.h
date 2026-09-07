#pragma once

#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
#include <sstream>
#include <bitset>

#include "minheap.h"
#include "hufftree.h"


void writeHeader(std::ofstream& outputStream, std::map<char, std::string> codeMap);
void compressFile(std::string inputFilePath, std::string outputFilePath, std::map<char, std::string> codeMap);

void dehuffer(std::map<char, std::string>& codeMap, std::string compressedFilePath, std::string decompressedFilePath);
void decompressFile(std::string codeString, Node* root, std::string decompressedFilePath);
Node* buildDecodingTree(std::map<char, std::string>& codeMap);
void readHeader(std::ifstream& inputStream, std::map<char, std::string>& codeMap);