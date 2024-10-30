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
    TreeNode* root ;
    public:
        BinarySearchTree() : root(NULL){  }
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
        void preorder(TreeNode* start){
            if(start){
            cout<< start->value << " ";
            preorder(start->left);
            preorder(start->right);
            }
        }
        void inorder(TreeNode* start){
            if(start){
            preorder(start->left);
            cout<< start->value << " ";
            preorder(start->right);
            }
        }
        void postorder(TreeNode* start){
            if(start){
            preorder(start->left);
            preorder(start->right);
            cout<< start->value << " ";
            }
        }



};   

int main(){
    TreeNode* root ;
    root = new TreeNode(30);
    BinarySearchTree tree;
    tree.insert(root,5);
    tree.insert(root,35);
    tree.insert(root->left,4);
    tree.insert(root->left,10);
    tree.insert(root->right,32);
    tree.insert(root->right,70);
    cout << "preorder: ";
    tree.preorder(root);
    cout<<endl;
    cout<<endl;
    cout << "postorder: ";
    tree.postorder(root);
    cout<<endl;
    cout<<endl;
    cout << "inorder: ";
    tree.inorder(root);
    
    

    return 0;
}

