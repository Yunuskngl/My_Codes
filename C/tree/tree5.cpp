#include <iostream>
using namespace std;

class TreeNode {
    public:
    int value;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int value= 0 , TreeNode* left = NULL , TreeNode* right = NULL) : value(value) , left(left) ,right(right) {}

 
};


class BinarySearchTree{
    TreeNode* Root ;
    public:
        BinarySearchTree() : Root(NULL){  }
        TreeNode* insert(TreeNode *start , int data){
            if(start){
                if(data< start->value) start->left = insert(start->left,data);
                else start->right = insert(start->right,data);
            }
            else{
                return new TreeNode(data);
            }
            return start;

        }
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

    BinarySearchTree tree;
    tree.insert(root,5);
    tree.insert(root,35);
    tree.insert(root->left,10);
    tree.insert(root->left->right,15);
    cout << tree.depth(root,root->left->right)<< endl;
    return 0;
}

