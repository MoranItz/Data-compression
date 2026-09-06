#include "hufftree.h"


Node* buildHuffTree(std::vector<Node*>& minheap) {
	while (minheap.size() >= 2) {
		Node* left = pop(minheap);
		Node* right = pop(minheap);
		// '_' is fine since the newNode has predececors
		Node* newNode = new Node((left->frequency + right->frequency), std::min(left->index, right->index), '_', left, right);
		pushByFrequency(minheap, newNode);
	}

	return minheap[ROOT_NODE];
}

void calculateHuffCodes(Node* root, std::vector<std::pair<char, std::vector<char>>>& codeVector, std::vector<char> curr) {
	if (root == nullptr) { // If the tree is empty
		return;
	}
	if (root->left == nullptr && root->right == nullptr) { // When we reached a letter
		if (curr.size() == NULL) { // If its the only letter push back the code 0
			curr.push_back('0');
		}
		std::pair<char, std::vector<char>> tempPair = { root->letter, curr };
		codeVector.push_back(tempPair);
		return;
	}
	calculateHuffCodes(root->left, codeVector, insertCarried(curr, '0')); // Go left
	calculateHuffCodes(root->right, codeVector, insertCarried(curr, '1')); // Go right
}

std::vector<char> insertCarried(std::vector<char> codeVector, char carried) {
	codeVector.push_back(carried);
	return codeVector;
}
