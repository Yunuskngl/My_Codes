#include <iostream>
using namespace std;

class TreeNode{
    public:
    int value;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int value=0 ,TreeNode* left = NULL,TreeNode* right = NULL) : value(value), right(right) , left(left) {     }
};

class Binarytree{
    TreeNode* root;                           
    public:
    Binarytree() : root(NULL) {};
    int depth(TreeNode* start ,TreeNode* finish){        //burada derinlik bulmamızı sağlayan bir kod yazıyoruz.
        if(start){
            if(start == finish){
                return 0;
            }
            int left = depth(start->left,finish);          //recursive fonksiyonu kullanıyoruz .
            int right = depth(start->right,finish);        //recursive fonksiyonu kullanıyoruz .
            return 1 + max(left,right);
        }
        else
            return INT_MIN;                                  
            //  Bu bağlamda INT_MIN döndürmek, bir "geçersiz" veya "imkansız" derinlik değerini temsil etmek için bir 
            //  tasarım tercihidir ve bu özel durumu uygun şekilde ele almak için çağırma kodunun sorumluluğundadır.           
        
    }
};

int main(){
    TreeNode* root;
    root = new TreeNode(30);
    root->left = new TreeNode(25);
    root->left->right = new TreeNode(27);
    root->left->left = new TreeNode(23);
    root->right  = new TreeNode(34);
    root->right->right = new TreeNode(35);
    root->right->right->right = new TreeNode(36);
    Binarytree tree;
    cout<< tree.depth(root,root->right->right->right)<< endl;
}