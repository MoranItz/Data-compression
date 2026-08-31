#include "encoding_huffmans.h"



vector<char> getUserInput() {
	string data_s = "";

	cout << "Enter data string: ";
	getline(cin, data_s);
	cout << endl << data_s;

	return vector<char>(data_s.begin(), data_s.end());
}

vector<char> getMapKeys(map<char, long> freqMap) {
	vector<char> keys;

	for (auto i = freqMap.begin(); i != freqMap.end(); i++) {
		keys.push_back(i->first);
	}
	return keys;
}

map<char, unsigned long long> getFreq(vector<char> data_v) {
	map<char, unsigned long long> freqMap;

	for (int i = 0; i < data_v.size(); i++) {
		freqMap[data_v[i]]++;
	}
	return freqMap;
}

vector<bool> insertCurr(vector<bool> curr, bool code) {
	curr.push_back(code);
	return curr;
}

bool freqCmp(pair<char, unsigned long long> &A, pair<char, unsigned long long> &B) {
	return A.second < B.second;
}

vector<pair<char, unsigned long long>> sortMap(map<char, unsigned long long> &freqMap) {
	vector<pair<char, unsigned long long>> tempFreqVector;

	for (auto& it : freqMap) {
		tempFreqVector.push_back(it);
	}
	sort(tempFreqVector.begin(), tempFreqVector.end(), [](auto& left, auto& right) {
		return left.second < right.second;
	});
	return tempFreqVector;
}

void calculateCodes(Node root, vector<bool> curr, vector<vector<bool>> *encodedFile) {
	try {
		if (root.left == nullptr && root.right == nullptr) {
			if (curr.size() == NULL) {
				curr.push_back(false);
			}
			encodedFile->push_back(curr);
			return;
		}
		calculateCodes(*root.left, insertCurr(curr, false), encodedFile);
		calculateCodes(*root.right, insertCurr(curr, true), encodedFile);
	}
	catch (int e) { // Root == NULL
		return;
	}
}

Node* pop(vector<Node*>& minHeap) {
	Node* temp;
	temp = minHeap[0];
	minHeap.erase(minHeap.begin());
	return temp;
}

void pushByFreq(vector<Node*>& minHeap, Node* newNode) {
	vector<Node*> temp;
	bool insertedFlag = false;
	if (minHeap.size() < 1) {
		temp.push_back(newNode);
		minHeap = temp;
		return;
	}
	for (const auto& node : minHeap) {
		if (node->freq > newNode->freq && insertedFlag != true) {
			temp.push_back(newNode);
			insertedFlag = true;
		}
		temp.push_back(node);
	}
	if (insertedFlag != true) {
		temp.push_back(newNode);
	}
	minHeap = temp;
}

map<char, vector<bool>> mapCodesAndLetters(map<char, unsigned long long> freqMap) {
	map<char, vector<bool>> codeMap;
	vector<vector<bool>> codeVector;
	
	vector<Node*> minHeap;

	vector<pair<char, unsigned long long>> freqVector = sortMap(freqMap);
	vector<pair<char, unsigned long long>> freqVectorCopy = freqVector;
	for (int i = 0; i < freqVector.size(); i++) {
		Node* tempNode = new Node(freqVectorCopy.front().second, i, freqVectorCopy.front().first);
		freqVectorCopy.erase(freqVectorCopy.begin());
		minHeap.emplace_back(tempNode);
	}
	if (minHeap.size() == 0) {
		map<char, vector<bool>> codeMap2;
		return codeMap2;
	}
	while (minHeap.size() >= 2) {
		Node* left = pop(minHeap);
		Node* right = pop(minHeap);
		Node* newNode = new Node((left->freq + right->freq), min(left->indx, right->indx), '_', left, right); // '_' is fine since the newNode has predececors
		pushByFreq(minHeap, newNode);
	}
	Node* root = minHeap[0];
	vector<bool> curr;
	calculateCodes(*root, curr, &codeVector);

	//sort(freqVector.begin(), freqVector.end(), [](auto& left, auto& right) {
	//	return left.second < right.second;
	//});

	for (const auto& val : freqVector) {
		codeMap[val.first] = codeVector.back();
		codeVector.erase(codeVector.end() - 1);
	}
	return codeMap;
}

//map<char, vector<bool>> mapCodesAndLetters(map<char, unsigned long long> freqMap)
//{
//	map<char, vector<bool>> codeMap;
//	vector<vector<bool>> codeVector;
//	vector<CharNode> minHeap;
//	
//	unsigned long long freq_left, freq_right;
//	unsigned int index_left, index_right;
//	int index = 0;
//
//	vector<pair<char, unsigned long long>> freqVector = sortMap(freqMap);
//	for (const auto& val : freqVector) {
//		Node tempNode = Node(val.second, index);
//		minHeap.emplace(minHeap.begin(), CharNode(tempNode.freq, tempNode.indx, tempNode));
//		index++;
//	}
//
//	if (index == 0) {
//		map<char, vector<bool>> codeMap2;
//		return codeMap2;
//	}
//
//	while (minHeap.size() >= 2) {
//		//CharNode tempCharNode1 = pop(minHeap);
//		//CharNode left = tempCharNode;
//		//left.node = tempCharNode.node;
//		//CharNode tempCharNode2 = pop(minHeap);
//		//CharNode right = tempCharNode;
//		//right.node = tempCharNode.node;
//
//		Node newNode = Node(minHeap[0].freq + minHeap[1].freq, min(minHeap[0].indx, minHeap[1].indx), &minHeap[0].node, &minHeap[1].node);
//		pop(minHeap);
//		pop(minHeap);
//		minHeap.emplace(minHeap.begin(), CharNode(newNode.freq, newNode.indx, newNode));
//	}
//	Node root = minHeap[0].node;
//	vector<bool> curr;
//	calculateCodes(root, curr, &codeVector);
//	index = -1;
//	for (const auto& val : freqMap) {
//		codeMap[val.first] = codeVector[index];
//		index--;
//	}
//	return codeMap;
//}



