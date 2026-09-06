#include "frequency.h"


void scanFrequency(std::map<char, unsigned long long>& frequencyMap, std::string data) {
	for (int i = 0; i < data.length(); i++) { // For character in string add 1 to the count
		frequencyMap[data[i]]++;
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
