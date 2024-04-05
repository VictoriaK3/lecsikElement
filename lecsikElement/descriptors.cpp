#include "descriptors.h"
#include <stdio.h>
#include <stdlib.h>
#include "string.h"

descriptors::descriptors()
{
	number = 0;
}

int descriptors::add(lexicalUnit& lu)
{
	if (number < 100) {
		if ((search(lu.getIdentificator())) == -1) {
			Table[number] = lu;
			number++;
			return 1;
		}
	}
	return 0;
}



int descriptors::search(char* pIdentificator)
{
	for (int i = 0; i < number; i++)
	{
		if (strcmp(pIdentificator, Table[i].getIdentificator()) == 0)
			return i;
	}
	return -1;
}

int descriptors::dell(char* pIdentificator)
{
	int index = 0;

	if (number != 0)
	{
		index = search(pIdentificator);
		if (index != -1)
		{
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

void descriptors::print()
{
	for (int i = 0; i < number; i++)
	{
		Table[i].Print();
	}
}

descriptors::~descriptors() {

}