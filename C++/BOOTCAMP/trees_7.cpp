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

    TreeNode* insert(TreeNode *start , int data){        
        if(start){
            if(data < start->value) 
                start->left = insert(start->left,data);    
            else 
                start->right = insert(start->right,data);  
        }
        else
            return new TreeNode(data);
        return start;
    }
//------------------------------------------------------------------------        


    TreeNode find(TreeNode* start , int data){              // eğer aradığımız değer varsa onu döndürür yoksa -1 döndürür
        if(start){
            if(start->value == data) return *start;
            else if(data < start->value) return find(start->left,data);
            else return find(start->right,data);
        }
        else return TreeNode(-1);
    }

//------------------------------------------------------------------------        
    TreeNode getmin(TreeNode* start){                       // en küçük değeri döndürür
        if(start->left) return getmin(start->left);
        else return *start;
    }
    TreeNode getmax(TreeNode* start){                       // en büyük değeri döndürür
        if(start->right) return getmax(start->right);
        else return *start;
    }
    



    
};

int main(){
    TreeNode* root;
    root = new TreeNode(30);
    BinarySearchtree tree;
    tree.insert(root,5);
    tree.insert(root,35);
    tree.insert(root->left,4);
    tree.insert(root->left,10);
    tree.insert(root->right,32);
    tree.insert(root->right,70);
    cout << tree.find(root , 10).value<<endl;
    cout << tree.find(root , 66).value<<endl;

    cout << tree.getmin(root).value<<endl;
    cout << tree.getmax(root).value<<endl;
   
    return 0;
}