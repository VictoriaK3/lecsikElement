#pragma once
#include "descriptors.h"
#include "LE.h"
class HashTable {
	lexicalUnit Table[100];
public:
	HashTable();
	int HashFunc(char* Identificator);
	int search(char* Identificator);
	int add(lexicalUnit &lu);
	int dell(char* Identificator);
	void print();
	~HashTable();
};