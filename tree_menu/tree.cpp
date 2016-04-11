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
	node* (tree::*f)(node*, int) = &remove;
	root = search(root, key, f);
}

//поиск элемента
bool tree::find(int key)
{
	node* (tree::*f)(node*, int) = &find;
	try
	{
		search(root, key, f);
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
tree::node* tree::search(node* subroot, int key, function func)
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

	if (r)
	{
		node* tmp = l;
		while (tmp->right)
			tmp = tmp->right;
		tmp->right = r;
	}
	return l;
}

//нужно для поиска
tree::node * tree::find(node * subroot, int key)
{
	if (!subroot)
		throw "элемент не найден";
	throw "элемент найден";
}

//нахождение высоты дерева
int tree::height()
{
	return height(root);
}

//рекурсивное нахождение высоты дерева
int tree::height(node* subroot)
{
	int left_height = 0;
	int right_height = 0;

	if(subroot->left)
		left_height += height(subroot->left);

	if(subroot->right)
		right_height += height(subroot->right);

	if (right_height >= left_height)
		return right_height + 1;
	else
		return left_height + 1;
}

//очистка дерева
void tree::clear()
{
	clear(root);
	root = NULL;
}

void tree::clear(node* subroot)
{
	if (subroot->right)
		clear(subroot->right);
	if (subroot->left)
		clear(subroot->left);
	delete subroot;
}

tree::iterator::iterator(tree tree)
{
	data = tree.root;
	stack.push(data);
}

int tree::iterator::operator[](iterator & iterator)
{
	return data->key;
}

void tree::iterator::direct_constructor()
{
	data = stack.top();
	stack.pop();

	direct_constructor(data);
}

tree::iterator tree::iterator::direct()
{
	if (stack.empty())
	{
		data = NULL;
		return  *this;
	}

	data = stack.top();
	stack.pop();

	if (data->right)
		stack.push(data->right);
	if (data->left)
		stack.push(data->left);

	return *this;
}

tree::iterator tree::iterator::inverse()
{
	if (stack.empty())
	{
		data = NULL;
		return  *this;
	}

	data = stack.top();
	stack.pop();

	while(data->left)


	if (data->right)
		stack.push(data->right);
	if (data->left)
		stack.push(data->left);

	return *this;
}