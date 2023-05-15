#pragma once

#include <iostream>
#include <string>
#include <stack>

using namespace std;

// функция, которая определяет приоритет операций
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

// функция для преобразования исходного выражения в обратную польскую запись
string InfixToPostfix(string infix) {
    stack<char> opStack; // стек операторов
    string postfix = ""; // строка с обратной польской записью
    for (int i = 0; i < infix.length(); i++) {
        if (isdigit(infix[i])) { // если символ - цифра, то добавляем ее к выходной строке
            while (isdigit(infix[i])) {
                postfix += infix[i];
                i++;
            }
            i--;
        }
        else if (infix[i] == '(') { // если символ - открывающая скобка, то помещаем ее в стек
            opStack.push('(');
        }
        else if (infix[i] == ')') { // если символ - закрывающая скобка, то выталкиваем все операторы из стека до открывающей скобки
            while (opStack.top() != '(') {
                postfix += opStack.top();
                opStack.pop();
            }
            opStack.pop();
        }
        else { // если текущий символ - оператор
            while (!opStack.empty() && priority(opStack.top()) >= priority(infix[i])) {
                postfix += opStack.top();
                opStack.pop();
            }
            opStack.push(infix[i]);
        }
    }
    while (!opStack.empty()) { // выталкиваем все операторы из стека
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

