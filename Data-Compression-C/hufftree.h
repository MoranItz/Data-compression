#pragma once

#include "minheap.h"
#include <map>

/// std::vector<Node*>& minheap - The ordered minheap with all of the letter nodes inside
/// This function gets the minheap with all of the letter nodes already inside and it builds
/// the huffman tree by creating new nodes for the connection of the frequencies of 2 different nodes.
/// The function returns a pointer to the root of the tree which will hold the pointers to the rest of the nodes
/// by either left or right turn.
Node* buildHuffTree(std::vector<Node*>& minheap);

/// Node* root - The root of the huffman tree
/// std::vector<std::pair<char, std::vector<char>>>& codeVector - The holder for the codes
/// This function traverses the huffman tree and when it gets to a character it calculates its code
/// recursively and pushes the code with the letter into the vector.
std::map<char, std::vector<char>> calculateHuffCodes(Node* root, std::vector<std::pair<char, std::vector<char>>>& codeVector);

/// std::vector<std::pair<char, std::vector<char>>>& codeVector - The holder for the codes
/// char carried - The carried code into the next recursive call
/// This function helps insert the next code (either 0 or 1) into the code vector.
void insertCarried(std::vector<std::pair<char, std::vector<char>>>& codeVector, char carried);