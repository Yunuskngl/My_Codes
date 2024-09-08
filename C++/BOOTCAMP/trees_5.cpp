#include <iostream>
using namespace std;

class TreeNode{
    public:
    int value;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int value=0 ,TreeNode* left = NULL,TreeNode* right = NULL) : value(value), right(right) , left(left) {     }
};

class BinarySearchtree{
    TreeNode* root;                           
    public:
    BinarySearchtree() : root(NULL) {};

    TreeNode* insert(TreeNode *start , int data){        //bu şekilde eleman ekleme işlemini gerçekleştirebilirsiniz.
        if(start){
            if(data < start->value) 
                start->left = insert(start->left,data);    //eğer eklencek değer start value değerinden küçükse sola eklenir.
            else 
                start->right = insert(start->right,data);  //büyükse sağa eklenir.
        }
        else
            return new TreeNode(data);
        return start;
    }
    int depth(TreeNode* start ,TreeNode* finish){       
        if(start){
            if(start == finish){
                return 0;
            }
            int left = depth(start->left,finish);          
            int right = depth(start->right,finish);        
            return 1 + max(left,right);
        }
        else
            return INT_MIN;                                  
            
    }

};

int main(){
    TreeNode* root;
    root = new TreeNode(30);
    BinarySearchtree tree;
    tree.insert(root,5);
    tree.insert(root,35);
    tree.insert(root->left,10);
    tree.insert(root->left->right,15);
    cout<< tree.depth(root,root->left->right)<< endl;
    return 0;
}