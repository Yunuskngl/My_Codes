#include <iostream>
using namespace std;

class TreeNode {
public:
    int value;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int value = 0, TreeNode* left = NULL, TreeNode* right = NULL) : value(value), left(left), right(right) {}
};

class BinarySearchTree {
    TreeNode* root;

public:
    BinarySearchTree() : root(NULL) {}

    TreeNode* insert(TreeNode* start, int data) {
        if (!start)
            return new TreeNode(data);
        if (data < start->value)
            start->left = insert(start->left, data);
        else if (data > start->value)
            start->right = insert(start->right, data);
        return start;
    }

    TreeNode* remove(TreeNode* start, int data) {        // eğer aradığımız değer varsa onu çıkartır ve ağacı döndürür
        if (!start)
            return start;
        if (data < start->value)
            start->left = remove(start->left, data);
        else if (data > start->value)
            start->right = remove(start->right, data);
        else {
            if (!start->left) {
                TreeNode* temp = start->right;
                delete start;
                return temp;
            } else if (!start->right) {
                TreeNode* temp = start->left;
                delete start;
                return temp;
            }
            TreeNode* temp = minValueNode(start->right);
            start->value = temp->value;
            start->right = remove(start->right, temp->value);
        }
        return start;
    }

    TreeNode* minValueNode(TreeNode* node) {
        TreeNode* current = node;
        while (current && current->left != NULL)
            current = current->left;
        return current;
    }
};

int main() {
    TreeNode* root = new TreeNode(30);
    BinarySearchTree tree;
    tree.insert(root, 5);
    tree.insert(root, 35);
    tree.insert(root, 4);
    tree.insert(root, 10);
    tree.insert(root, 32);
    tree.insert(root, 70);

    cout << root->value << endl;
    cout << root->right->value << endl;

    tree.remove(root, 30);
    tree.remove(root, 35);

    cout << root->value << endl;
    cout << root->right->value << endl;

    return 0;
}
