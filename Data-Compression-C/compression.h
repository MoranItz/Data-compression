#pragma once

#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
#include <sstream>
#include <bitset>

#include "minheap.h"
#include "hufftree.h"
#include "frequency.h"



void writeHeader(std::ofstream& outputStream, std::map<char, std::string> codeMap);
void compressToFile(std::string inputFilePath, std::string outputFilePath, std::map<char, std::string> codeMap);