#pragma once
#include <stdio.h>
#include <stdlib.h>
#include "LE.h"
#include <string.h>

class node {
public:
	lexicalUnit* key;
	 node* left;
	 node* right;

	 node(lexicalUnit* lu) {
		 key = lu;
		 left = NULL;
		 right = NULL;
	 }
	 ~node() {

	 }
};



class BinTree {
private:
	node* search(node* pnode, char* pIdentificator);
	void add( node*& pnode, lexicalUnit* lu);
	void dell(node*& pnode, char* pIdentificator);
	void print(node* pnode);
	node* root;
public:
	BinTree();
	~BinTree();
	int add(lexicalUnit* lu);
	node* search(char* pIdentificator);
	int dell(char* pIdentificator);
	void print();

};
