#pragma once

#include <map>
#include <vector>

/// std::vector<std::pair<char, unsigned long long>>& frequencyMap - map of all frequencies
/// char** data - list data the vector gets in chunks
/// Function gets a reference to a map and a string of chars (data), and it enters all of the
/// letters frequencies into the map so each key is the letter and the value is the matching
/// letter frequency (amount of times the letter has shown up in the file.
void scanFrequency(std::map<char, unsigned long long>& frequencyMap, char** data);

/// std::map<char, unsigned long long> frequencyMap - map of all frequencies
/// Function gets a map of all of the appearing letters as keys and the matching frequency
/// as the value. It sorts all of the letters from smallest frequency -> biggest frequency letters
/// inside a vector of pairs <char, unsigned long long> and returns it.
/// crucial for making the minheap.
std::vector<std::pair<char, unsigned long long>> sortFrequency(std::map<char, unsigned long long> frequencyMap);