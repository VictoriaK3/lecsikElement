#pragma once
#include "LE.h"
class DiholTable {
	lexicalUnit Table[100];
	int number;
public:
	DiholTable();
	int search(char* pIdentificator);
	int add(lexicalUnit& lu);
	int dell(char* pIdentificator);
	void print();
	~DiholTable();
};
