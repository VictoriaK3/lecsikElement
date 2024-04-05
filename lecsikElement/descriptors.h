#pragma once
#include "LE.h"
class descriptors {
	lexicalUnit Table[100];
	int number;
public:
	descriptors();
	~descriptors();
	int add(lexicalUnit& lu);
	int dell(char* pIdentificator);
	int search(char* pIdentificator);
	void print();

};