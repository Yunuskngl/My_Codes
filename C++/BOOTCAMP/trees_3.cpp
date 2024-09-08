#include <iostream>
using namespace std;
class TreeNode {
    public:
    int value;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int value = 0 , TreeNode* left = NULL, TreeNode* right = NULL) : value(value) , left(left) ,right(right) {     }
};

class BinaryTree{
    TreeNode* root;
    public:
    BinaryTree() : root(NULL) {}
    bool isEmpty() const{   return root == NULL;    }
    TreeNode* getRoot()  const{    return root;     }
    int height(TreeNode* Node){                           //Uzunluk(height) bulmamızı sağlar.
        if(Node){
            int left = height(Node->left);                //recursive fonksiyon kullanıyoruz.
            int right = height(Node->right);
            return 1 + max(left,right);
        }
        else{
            return -1;
        }
    }
};

int main(){
    TreeNode* root;
    root = new TreeNode(20);
   
    root->left = new TreeNode(10);
    root->right = new TreeNode(15);
    root->right->right = new TreeNode(17);
    root->right->right->left = new TreeNode(18);
    BinaryTree tree;
    cout << tree.height(root) << endl;

}
