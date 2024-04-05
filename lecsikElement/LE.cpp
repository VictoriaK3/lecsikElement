#include "LE.h"
#include <string.h>
void lexicalUnit::setAddress(char* type) {
	address = newAddress;
	int size = 0;
	if (strcmp(type, "int") == 0)
		size = 2;
	if (strcmp(type, "char") == 0)
		size = 1;
	if (strcmp(type, "float") == 0)
		size = 4;
	if (strcmp(type, "double") == 0)
		size = 8;

	newAddress += size;
}

void lexicalUnit::setDescriptor()
{
	sprintf_s(descriptor, "V%d", newDescriptor);
	newDescriptor++;
}

lexicalUnit::lexicalUnit()
{
	identificator[0] = '\0';
	type[0] = '\0';
	descriptor[0] = '\0';
	address = 0;

}

lexicalUnit::lexicalUnit(char* pIdentificator, char* pType)
{
	strcpy_s(identificator, pIdentificator);
	strcpy_s(type, pType);
	setDescriptor();
	setAddress(pType);
}

lexicalUnit& lexicalUnit :: operator= (lexicalUnit& lu)
{
	strcpy_s(identificator, lu.identificator);
	strcpy_s(type, lu.type);
	strcpy_s(descriptor, lu.descriptor);
	address = lu.address;
	return *this;
}

char* lexicalUnit::getIdentificator()
{
	return identificator;
}

void lexicalUnit::Print()
{
	printf_s("Identificator: %s\n", identificator);
	printf_s("Type: %s\n", type);
	printf_s("Descriptor: %s\n", descriptor);
	printf_s("Address: %d\n", address);
}

lexicalUnit::~lexicalUnit()
{
	
}

char* lexicalUnit::getType() {
	return type;
}