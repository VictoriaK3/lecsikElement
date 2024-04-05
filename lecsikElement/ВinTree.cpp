#include "BinTree.h"


BinTree::BinTree() {
	root = NULL;
}

BinTree::~BinTree() {
	delete root;
}



int BinTree::add(lexicalUnit* lu) {
	add(root, lu);
	return 1;
}

void BinTree::add(node*& pnode, lexicalUnit* lu) {
	if (pnode == NULL) {
		//leaf = (struct node*)malloc(sizeof(*leaf));
		pnode = new node(lu);
	
	} 
	else if (strcmp(lu->getIdentificator(),pnode->key->getIdentificator())<0) {
		//if (leaf->left != NULL)
			add(pnode->left, lu);
	}
	else {
		add(pnode->right, lu);
	}
}

node* BinTree::search( char* pIdentificator) {
	return search(root, pIdentificator);
}

node* BinTree::search(node* pnode, char* pIdentificator) {
	if (pnode != NULL) {
		if (strcmp(pIdentificator, pnode->key->getIdentificator()) == 0) {
			return pnode;
		}
	}
		if (strcmp(pIdentificator, pnode->key->getIdentificator())  < 0) {
			return search(pnode->left,pIdentificator);
		}
		else {
			return search(pnode->right, pIdentificator);
		}
}
	


int BinTree::dell( char* pIdentificator) {
	dell(root, pIdentificator);
	return 1;
}

void BinTree::dell(node*& pnode, char* pIdentificator) {
	if (pnode == NULL)
		printf("Error!No such element\n");
	if (strcmp(pIdentificator, pnode->key->getIdentificator()) == 0) {
		if (pnode->left != NULL && pnode->right != NULL) {
			node* temp = pnode->right;
			while (temp->left != NULL)
				temp = temp->left;
			pnode->key = temp->key;
			dell(pnode->right, pnode->key->getIdentificator());
		}
		else {
			node* tmp = pnode;
			if (pnode->left)
				pnode = pnode->left;
			else
				pnode = pnode->right;
			delete pnode;
		}
	}
	else if (strcmp(pIdentificator, pnode->key->getIdentificator()) < 0)
		dell(pnode->left, pIdentificator);
	else if (strcmp(pIdentificator, pnode->key->getIdentificator()) > 0)
		dell(pnode->right, pIdentificator);

}

void BinTree::print() {
	print(root);
}

void BinTree::print(node* pnode) {
	if (pnode != NULL) {
		print(pnode->left);
		//printf("%s\n", leaf->key.getIdentificator());
		print(pnode->right);
	}
}


