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

//��������� �������� �� �����
void tree::add(int key)
{
	node* (tree::*f)(node*, int) = add;
	root = search(root, key, f);
}

//�������� �������� �� �����
void tree::remove(int key)
{
	node* (tree::*f)(node*, int) = remove;
	root = search(root, key, f);
}

//����� ��������
bool tree::find(int key)
{
	node* (tree::*f)(node*, int) = find;
	try
	{
		root = search(root, key, f);
	}
	catch (char* exc)
	{
		if (exc == "������� �� ������")
			return false;
		else if (exc == "������� ������")
			return true;
		else throw exc;
	}
}

//���� ������� �� �����, �������� ������ ����� (��������, �������, ...)
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

//��������� ������� ��������
tree::node* tree::add(node* subroot, int key)
{
	if (!subroot)
	{
		node* adding_node = new node();
		adding_node->key = key;
		adding_node->left = adding_node->right = NULL;
		return adding_node;
	}
	throw "������������ �������";
}

//���������� ��������
tree::node* tree::remove(node* subroot, int key)
{
	if (!subroot)
		throw "�������������� �������";

	node* r = subroot->right;
	node* l = subroot->left;
	delete subroot;

	node* tmp = l;
	while (tmp->right)
		tmp = tmp->right;
	tmp->right = r;

	return l;
}

//����� ��� ������
tree::node * tree::find(node * subroot, int key)
{
	if (!subroot)
		throw "������� �� ������";
	throw "������� ������";
}