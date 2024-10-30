#include <iostream>
using namespace std;

class TreeNode {
    public:
    int value;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int value= 0 , TreeNode* left = NULL , TreeNode* right = NULL) : value(value) , left(left) ,right(right) {}

 
};
int main() {
    TreeNode* root = NULL;
    root = new TreeNode(5);
    cout << "Root: " << root->value << endl;
    root->left = new TreeNode(6);
    cout << "Left: " << root->left->value << endl;
    root->right = new TreeNode(10);
    cout << "Right: " << root->right->value << endl;
    return 0; 
}