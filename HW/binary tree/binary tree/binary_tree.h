#pragma once
#include <iostream>
using namespace std;

class Node {
public:
	int root_data;
	Node* left_child;
	Node* right_child;

	Node(int value) {
		root_data = value;
		left_child = nullptr;
		right_child = nullptr;
	}
};

class Binary_Tree {
public:
	Node* root;

	Binary_Tree() {
		root = nullptr;
	}

	void insert(int value) {
		Node* current = root;
		if (root == nullptr)
			root = new Node(value);
		while (current && current->root_data != value) {
			if (current->root_data > value && current->left_child == NULL) {
				current->left_child = new Node(value);
				return;
			}
			if (current->root_data < value && current->right_child == NULL) {
				current->right_child = new Node(value);
				return;
			}
			if (current->root_data > value)
				current = current->left_child;
			else
				current = current->right_child;
		}
	}

	void remove(int value) {
		Node* current = root;
		Node* parent = NULL;
		while (current && current->root_data != value)
		{
			parent = current;
			if (current->root_data > value)
			{
				current = current->left_child;
			}
			else
			{
				current = current->right_child;
			}
		}
		if (!current)
			return;
		if (current->left_child == NULL)
		{
			// Вместо curr подвешивается его правое поддерево
			if (parent && parent->left_child == current)
				parent->left_child = current->right_child;
			if (parent && parent->right_child == current)
				parent->right_child = current->right_child;
			delete current;
			return;
		}
		if (current->right_child == NULL)
		{
			// Вместо curr подвешивается его левое поддерево
			if (parent && parent->left_child == current)
				parent->left_child = current->left_child;
			if (parent && parent->right_child == current)
				parent->right_child = current->left_child;
			delete current;
			return;
		}
		// У элемента есть два потомка, тогда на место элемента поставим
		// наименьший элемент из его правого поддерева
		Node* replace = current->right_child;
		while (replace->left_child)
			replace = replace->left_child;
		int replace_value = replace->root_data;
		remove(replace_value);
		current->root_data = replace_value;
	}

	bool find(int value) {
		Node* current = root;
		while (current && current->root_data != value)
		{
			if (current->root_data > value)
				current = current->left_child;
			else
				current = current->right_child;
		}
		return current != NULL;
	}

	void print_tree(Node* current) {
		if (current) {
			print_tree(current->left_child);
			cout << current->root_data << " ";
			print_tree(current->right_child);
		}
	}
	
};


