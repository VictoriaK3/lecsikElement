#include "HashTable.h"
#include <string.h>

HashTable::HashTable() {
}
 int HashTable::HashFunc(char* Identificator) {
	 int index=0;
	 for (int i = 0; Identificator[i] != 0; i++) {
		 index += Identificator[i];
	 }
	 return index % 128;
}

 int HashTable::search(char* Identificator) {
	 int j = HashFunc(Identificator);
	 int i = j;
	 for (; ; i++) {
		 if (strcmp(Table[i].getIdentificator(), Identificator) == 0) {
			 return i;
		 }
		 if (Table[i].getIdentificator()[0] == 0) {
			 return i + 200;
		 }
		 if (i = 127)
			 i = 0;
		 if (i == j - 1) {
			 return -1;
		 }
	 }
	 
 }

 int HashTable::add(lexicalUnit& lu) {
	 int index = search(lu.getIdentificator());
	 if (index < 0)
		 return -1;
	 if (index > 200) {
		 index -= 200;

	 }
	 Table[index] = lu;
	 return 1;

 }

 int HashTable::dell(char* Idenrificator) {
	 int index = search(Idenrificator);
	 if (index > 200|| index<0) {
		 return -1;
		 Table[index].getIdentificator()[0] = 0;
		 return 1;

	 }
 }

 void HashTable::print() {
	 for (int i = 0; i < 127; i++) {
		 if (Table[i].getIdentificator()[0]) {
			 Table[i].Print();
		 }
	 }
 }

 HashTable::~HashTable() {

 }