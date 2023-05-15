#pragma once

#include <iostream>
#include <string>
#include <stack>

using namespace std;

// �������, ������� ���������� ��������� ��������
int priority(char op) {
    switch (op) {
    case '+':
    case '-':
        return 1;
    case '*':
    case '/':
        return 2;
    case '^':
        return 3;
    default:
        return 0;
    }
}

// ������� ��� �������������� ��������� ��������� � �������� �������� ������
string InfixToPostfix(string infix) {
    stack<char> opStack; // ���� ����������
    string postfix = ""; // ������ � �������� �������� �������
    for (int i = 0; i < infix.length(); i++) {
        if (isdigit(infix[i])) { // ���� ������ - �����, �� ��������� �� � �������� ������
            while (isdigit(infix[i])) {
                postfix += infix[i];
                i++;
            }
            i--;
        }
        else if (infix[i] == '(') { // ���� ������ - ����������� ������, �� �������� �� � ����
            opStack.push('(');
        }
        else if (infix[i] == ')') { // ���� ������ - ����������� ������, �� ����������� ��� ��������� �� ����� �� ����������� ������
            while (opStack.top() != '(') {
                postfix += opStack.top();
                opStack.pop();
            }
            opStack.pop();
        }
        else { // ���� ������� ������ - ��������
            while (!opStack.empty() && priority(opStack.top()) >= priority(infix[i])) {
                postfix += opStack.top();
                opStack.pop();
            }
            opStack.push(infix[i]);
        }
    }
    while (!opStack.empty()) { // ����������� ��� ��������� �� �����
        postfix += opStack.top();
        opStack.pop();
    }
    return postfix;
}

class Node {
public:
    char data;
    Node* left;
    Node* right;
};

bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

Node* newNode(char c) {
    Node* node = new Node;
    node->data = c;
    node->left = NULL;
    node->right = NULL;
    return node;
}

void inorderTraversal(Node* node) {
    if (node) {
        inorderTraversal(node->left);
        cout << node->data;
        inorderTraversal(node->right);
    }
}

Node* buildTree(string postfix) {
    stack<Node*> st;
    stack<char> operand;

    for (int i = 0; i < postfix.length(); i++) {
        char c = postfix[i];

        if (!isOperator(c)) {
            Node* node = newNode(c);
            st.push(node);
            operand.push(c);
        }
        else {
            Node* t = newNode(c);
            t->right = st.top();
            st.pop();
            t->left = st.top();
            st.pop();
            char op = operand.top();
            operand.pop();
            st.push(t);
            operand.push(op);
        }
    }

    return st.top();
}

int evaluate(Node* root) {
    if (!root) {
        return 0;
    }

    if (!root->left && !root->right) {
        return (int)(root->data - '0');
    }

    int l = evaluate(root->left);
    int r = evaluate(root->right);

    if (root->data == '+') {
        return l + r;
    }

    if (root->data == '-') {
        return l - r;
    }

    if (root->data == '*') {
        return l * r;
    }

    if (root->data == '/') {
        return l / r;
    }

    if (root->data == '^') {
        return pow(l, r);
    }

    return 0;
}

