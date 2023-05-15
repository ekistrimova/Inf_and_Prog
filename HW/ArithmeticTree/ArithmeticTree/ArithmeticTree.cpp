#include "ArithmeticTree.h"
#include <iostream>

using namespace std;

int main() {

    setlocale(LC_ALL, "Russian");

    string infix = "7+(3+4)*2"; // a+b*c-(d/e+f^g)*h

    cout << "��������� �����: ";
    cout << infix << endl;

    string postfix = InfixToPostfix(infix);
 //   cout << postfix << endl; // ������� a b c * + d e / f g ^ + h * -
    Node* root = buildTree(InfixToPostfix(infix));
    
    cout << "����������� �����: ";
    inorderTraversal(root);

    cout << "\n��������� ���������� ������ ���������: " << evaluate(root);
    
    return 0;
}


