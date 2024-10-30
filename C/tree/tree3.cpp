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
    TreeNode* Root ;
    public:
        BinaryTree() : Root(NULL){  }
        bool isEmpty() const{   return Root== NULL;     }
        TreeNode* getRoot() const{ return Root; }
        int Height(TreeNode* Node){
            if(Node){
                int left = Height(Node->left);
                int right = Height(Node->right);
                return 1 + max(left,right);
            }
            else {
                return -1;
            }
        }
};   

int main(){
    TreeNode* root ;
    root = new TreeNode(5);

    root->left  = new TreeNode(10);
    root->right = new TreeNode(15);
    root->right->right = new TreeNode(17);
    root->right->right->left = new TreeNode(18);
    root->right->right->left->left = new TreeNode(25);
    BinaryTree Btree;
    cout << Btree.Height(root) << endl;



}



