#pragma once
#include <stack>

using namespace std;

class tree
{
	struct node
	{
		int key;
		node* left;
		node* right;
	};

	node* root;

	typedef node* (*function)(node* subroot, int key);

	node* add(node* subroot, int key);
	node* remove(node* subroot, int key);
	node* search(node* subroot, int key, function func);
	node* find(node* subroot, int key);
	int height(node* subroot);
	void clear(node*subroot);

public:
	tree();
	~tree();

	void add(int key);
	void remove(int key);
	bool find(int key);
	int height();
	void clear();

	class iterator
	{
		node* data;
		stack<node*> stack;

	public:
		iterator(tree tree);

		int operator[](iterator& iterator);
		iterator direct();
		void direct_constructor();
		iterator inverse();
		iterator symmetric();
		iterator width();
	};
};


