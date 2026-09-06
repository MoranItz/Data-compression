#include "frequency.h"


void scanFrequency(std::map<char, unsigned long long>& frequencyMap, std::string path) {
	std::ifstream file(path);
	std::string line;
	if (file.is_open()) {
		while (getline(file, line)) {
			for (int i = 0; i < line.length(); i++) { // For character in string add 1 to the count
				frequencyMap[line[i]]++;
			}
		}
		file.close();
	}
	else {
		std::cout << "Failed to open file!";
		exit(NULL);
	}
}

std::vector<std::pair<char, unsigned long long>> sortFrequency(std::map<char, unsigned long long> frequencyMap) {
	std::vector<std::pair<char, unsigned long long>> frequencyVector;

	for (auto& it : frequencyMap) { // For key in frequencyMap
		frequencyVector.push_back(it);
	}
	sort(frequencyVector.begin(), frequencyVector.end(), [](auto& left, auto& right) { // Sort vector from lowest frequency to biggest
		return left.second < right.second;
		});
	return frequencyVector;
}
