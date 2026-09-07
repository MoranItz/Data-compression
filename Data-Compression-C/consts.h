#pragma once

#define END_OF_LINE '\n'
#define INTERNAL_NODE_CHARACTER char(128)
#define PSEUDO_EOF char(129)
#define CHARACTER_CODE_SEPERATOR char(130)
#define HEADER_ENTRY_SEPERATOR char(131)
#define HEADER_TEXT_SEPERATOR char(132)
#define ROOT_NODE 0

struct Node {
	unsigned long long frequency;
	int index;
	char letter;
	Node* left;
	Node* right;
};