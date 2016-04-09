#pragma once
class tree
{
	struct node
	{
		int key;
		node* left;
		node* right;
	};

	node* root;

	node* add(node* subroot, int key);
	node* remove(node* subroot, int key);
	node* search(node* subroot, int key, node* (tree::*func)(node* subroot, int key));
	node* find(node* subroot, int key);

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
		node* pointer;
	public:
		iterator(tree tree);

		iterator forward();
		iterator backward();
		iterator symmetric();

		int get_key();
	};
};


