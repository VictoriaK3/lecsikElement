#include "diholTable.h"
#include <string.h>

DiholTable::DiholTable() {
	number = 0;
}

DiholTable::~DiholTable (){

}

int DiholTable::search(char* pIdentificator)
{
	int min = 0;
	int max = number;
	int middle =0;
	while (max >= min) {
		middle = (min + max) / 2;
		if (strcmp(pIdentificator, Table[middle].getIdentificator()) == 0) {
			return middle;
		}
		else if (strcmp(pIdentificator, Table[middle].getIdentificator()) == 1) {
			min = middle + 1;
			middle = (min + max) / 2;
		}
		else if (strcmp(pIdentificator, Table[middle].getIdentificator()) ==-1) {
			max = middle - 1;
			middle = (min + max) / 2;
		}
	}  
	return middle + 100;
}

int DiholTable::add(lexicalUnit &lu) {
	
	
	if (number < 100) {
		int index = search(lu.getIdentificator());
		if (index > 100) {
			index = index - 100;
			for (int j = number; j > index; j--) 
				Table[j] = Table[j - 1];
			Table[index] = lu;
			number++;
			return 1;
		}
	}
	return 0;
}

int DiholTable::dell(char* pIdentificator) {
	if (number != 0) {
		int index = search(pIdentificator);
		if (index < 100) {
			for (int i = index; i < number - 1; i++)
			{
				Table[i] = Table[i + 1];
			}
			number--;
			return 1;
		}
		return 0;
	}
	return 0;
}

void DiholTable::print() {
	for (int i = 0; i < number; i++)
	{
		Table[i].Print();
	}
}