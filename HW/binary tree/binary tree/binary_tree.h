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

	void insert(int value) {   // метод вставки в дерево
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

	void remove(int value) { // метод который принимает указатель на узел и значение которое удаляется
		root = removeNode(root, value);
	}

	Node* removeNode(Node* node, int value) { // метод удаление узла
		if (node == nullptr) {
			return nullptr;
		}
		else if (value < node->root_data) {
			node->left_child = removeNode(node->left_child, value);
		}
		else if (value > node->root_data) {
			node->right_child = removeNode(node->right_child, value);
		}
		else {
			if (node->left_child == nullptr && node->right_child == nullptr) {
				delete node;
				return nullptr;
			}
			else if (node->left_child == nullptr) {
				Node* temp = node->right_child;
				delete node;
				return temp;
			}
			else if (node->right_child == nullptr) {
				Node* temp = node->left_child;
				delete node;
				return temp;
			}
		}
		return node;
	}

	bool find(int value) { // метод поиска
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

	void print_tree(Node* current) { // вывод дерева
		if (current) {
			print_tree(current->left_child);
			cout << current->root_data << " ";
			print_tree(current->right_child);
		}
	}
	
};


