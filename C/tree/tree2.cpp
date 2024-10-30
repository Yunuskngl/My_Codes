#include <iostream>
using namespace std;


class TreeNode {
    public:
    int value;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int value= 0 , TreeNode* left = NULL , TreeNode* right = NULL) : value(value) , left(left) ,right(right) {}
};

class BinaryTree{
    TreeNode* root = new TreeNode(1);
    public:
        BinaryTree() : root(NULL){  }

        bool isEmpty() const{   return root== NULL;     }

        TreeNode* getRoot() const{ return root; }
};

int main(){
    BinaryTree btree;

    cout << btree.getRoot()<<endl;
    cout<< btree.isEmpty() << endl;
    return 0;
}

