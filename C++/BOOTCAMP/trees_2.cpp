#include <iostream>
using namespace std;

class TreeNode {
    public:
    int value;          
    TreeNode* left;             
    TreeNode* right;
    TreeNode(int value=0,TreeNode* left = NULL , TreeNode* right = NULL ) : value(value) ,left(left) ,right(right) {}
};
  
class BinaryTree{                // Binary Tree yapısı.
    TreeNode* root = new TreeNode(1);
    public :  
        BinaryTree() : root(NULL){    }
        
        bool isEmpty() const{   return root == NULL;    }     // root değeri boş ise bool fonksiyonu ile 1 değerini verir . eğer boş değilse 0 verir.
        
        
        TreeNode* getRoot() const{  return root;    }         // root değerini verir.  
};

int main(){
    BinaryTree btree ; 
   
    cout << btree.isEmpty() << endl;
    cout << btree.getRoot() << endl;

return 0;}