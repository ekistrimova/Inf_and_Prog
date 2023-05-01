#include "binary_tree.h"
 

int main() {

    Binary_Tree tree;

    tree.insert(5);
    tree.insert(10);
    tree.insert(7);
    tree.insert(3);
    tree.insert(15);
    tree.insert(1);

    cout << "Tree now: ";
    tree.print_tree(tree.root);
    cout << endl;
    
    tree.remove(7);
    cout << "Tree after remove : ";
    tree.print_tree(tree.root);
    cout << endl;
    
    return 0;

}
