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
        int depth(TreeNode* start, TreeNode* Finish){
            if(start){
                if(start == Finish){
                    return 0;
                }
                int left =  depth(start->left,Finish);
                int right = depth(start->right,Finish);
                return 1 + max(left,right);
            }
            else {
                return INT_MIN;
            }
        }
};   

int main(){
    TreeNode* root ;
    root = new TreeNode(30);

    root->left  = new TreeNode(25);
    root->left->right = new TreeNode(27);
    root->left->left = new TreeNode(23);
    root->right = new TreeNode(34);
    root->right->right = new TreeNode(35);
    root->right->right->right = new TreeNode(36);
    BinaryTree Btree;
    cout << Btree.depth(root,root->left->right) << endl;
    return 0;
}


