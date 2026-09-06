#pragma once

#include <iostream>
#include <vector>

struct Node {
	unsigned long long frequency;
	int index;
	char letter;
	Node* left;
	Node* right;
};

/// std::vector<std::pair<char, unsigned long long>> frequencyVec - sorted vector that holds pairs of the letters and their matching frequencies
/// This function builds the crucial minheap, the object that will hold the huffman tree inside it and now holds all of the nodes
/// for the tree to be built in later. It gets a vector sorted with pairs of all letters appearing in the file and all of their frequencies.
/// Eventualy the function returns the minheap as a vector with pointers to all of the new tree nodes inside it.
std::vector<Node*> buildMinheap(std::vector<std::pair<char, unsigned long long>> frequencyVec);

/// std::vector<Node*>& minheap - The ordered minheap with all of the letter nodes inside
/// Node* newNode - The new node that gets pushed into the heap by its frequency
/// This function pushes the new node inside the heap by its frequency.
/// This functions use is to help insert the newly created combined nodes when creating
/// the huffman tree into the right position so the tree algorithm works well.
void pushByFrequency(std::vector<Node*>& minheap, Node* newNode);

/// std::vector<Node*>& minheap - The ordered minheap with all of the letter nodes inside
/// This function gets the reference to a minheap and it pops the first element
/// from the heap. It removes it from the heap and returns it.
Node* pop(std::vector<Node*>& minheap);