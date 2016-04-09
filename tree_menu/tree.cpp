#include "stdafx.h"
#include "tree.h"

tree::tree()
{
	root = NULL;
}

tree::~tree()
{
	clear();
}

//добаление элемента по ключу
void tree::add(int key)
{
	node* (tree::*f)(node*, int) = add;
	root = search(root, key, f);
}

//удаление элемента по ключу
void tree::remove(int key)
{
	node* (tree::*f)(node*, int) = remove;
	root = search(root, key, f);
}

//поиск элемента
bool tree::find(int key)
{
	node* (tree::*f)(node*, int) = find;
	try
	{
		root = search(root, key, f);
	}
	catch (char* exc)
	{
		if (exc == "элемент не найден")
			return false;
		else if (exc == "элемент найден")
			return true;
		else throw exc;
	}
}

//ищет элемент по ключу, вызывает нужный метод (удаление, вставка, ...)
tree::node* tree::search(node* subroot, int key, 
						node* (tree::*func)(node* subroot, int key))
{
	if (key < subroot->key)
		subroot = subroot->left;
	else if (key > subroot->key)
		subroot = subroot->right;
	else
		return func(subroot, key);
	return subroot;
}

//собствено вставка элемента
tree::node* tree::add(node* subroot, int key)
{
	if (!subroot)
	{
		node* adding_node = new node();
		adding_node->key = key;
		adding_node->left = adding_node->right = NULL;
		return adding_node;
	}
	throw "существующий элемент";
}

//собственно удаление
tree::node* tree::remove(node* subroot, int key)
{
	if (!subroot)
		throw "несуществующий элемент";

	node* r = subroot->right;
	node* l = subroot->left;
	delete subroot;

	node* tmp = l;
	while (tmp->right)
		tmp = tmp->right;
	tmp->right = r;

	return l;
}

//нужно для поиска
tree::node * tree::find(node * subroot, int key)
{
	if (!subroot)
		throw "элемент не найден";
	throw "элемент найден";
}