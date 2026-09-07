#include "hufftree.h"


Node* buildHuffTree(std::vector<Node*>& minheap) {
	while (minheap.size() >= 2) {
		Node* left = pop(minheap);
		Node* right = pop(minheap);
		// INTERNAL_NODE_CHARACTER is a psuedo eof char to identify a non leaf node
		Node* newNode = new Node((left->frequency + right->frequency), std::min(left->index, right->index), INTERNAL_NODE_CHARACTER, left, right);
		pushByFrequency(minheap, newNode);
	}

	return minheap[ROOT_NODE];
}

void calculateHuffCodes(Node* root, std::map<char, std::string>& codeMap, std::string curr) {
	if (root == nullptr) { // If the tree is empty
		return;
	}
	if (root->left == nullptr && root->right == nullptr) { // When we reached a letter
		if (curr.size() == NULL) { // If its the only letter push back the code 0
			curr.push_back('0');
		}
		codeMap[root->letter] = curr;
		return;
	}
	calculateHuffCodes(root->left, codeMap, insertCarried(curr, '0')); // Go left
	calculateHuffCodes(root->right, codeMap, insertCarried(curr, '1')); // Go right
}

std::string insertCarried(std::string codeStr, char carried) {
	codeStr.push_back(carried);
	return codeStr;
}
