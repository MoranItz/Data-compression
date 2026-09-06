#include "minheap.h"


std::vector<Node*> buildMinheap(std::vector<std::pair<char, unsigned long long>> frequencyVec) {
	std::vector<Node*> minheap;
	int frequencyVecLen = frequencyVec.size();

	for (int i = 0; i < frequencyVecLen; i++) {
		Node* tempNode = new Node(frequencyVec.front().second, i, frequencyVec.front().first);
		frequencyVec.erase(frequencyVec.begin());
		minheap.emplace_back(tempNode);
	}

	return minheap;
}

void pushByFrequency(std::vector<Node*>& minheap, Node* newNode) {
	std::vector<Node*> temp;
	bool insertedFlag = false;

	if (minheap.size() < 1) {
		temp.push_back(newNode);
		minheap = temp;
		return;
	}
	for (const auto& node : minheap) {
		if (node->frequency > newNode->frequency && insertedFlag != true) {
			temp.push_back(newNode);
			insertedFlag = true;
		}
		temp.push_back(node);
	}
	if (insertedFlag != true) {
		temp.push_back(newNode);
	}
	minheap = temp;
}

Node* pop(std::vector<Node*>& minheap) {
	Node* temp;

	temp = minheap[0];
	minheap.erase(minheap.begin());

	return temp;
}