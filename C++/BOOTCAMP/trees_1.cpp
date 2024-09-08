#include <iostream>
using namespace std;

class TreeNode {                //eğer C programlama dilinde yazıyor olsaydık struct kullanırdık.
    public:                     //public tanımladık çünkü bu değerlere erişmemiz lazım. 
    int value;                  //class içinde root ve leaf değerlerini yazdırırken kullanırız.
    TreeNode* left;             //Ağaç yapımızın sol tarafında değer tutması için bir pointer tanımladık.
    TreeNode* right;            //Ağaç yapımızın sağ tarafında değer tutması için bir pointer tanımladık.
    
    TreeNode(int value=0,TreeNode* left = NULL , TreeNode* right = NULL ) : value(value) ,left(left) ,right(right) {}
    /*
      Üstteki satır program hata vermesin diye kendiliğinden 0 ve NULL değerlerini atar. Ve ":" işaretinden sonraki yer ise value,left ve right için 
      gelen değerleri oralara atar.
    */
};

int main(){
    TreeNode* root = NULL;
    root  = new TreeNode(5);            // root değerine atama işlemi yapar.
    cout << "root: " << root->value << endl;
    root->left = new TreeNode(6);       //root'un left değerine atama işlemi yapar.
    cout <<"left: "<< root->left->value << endl;
    root->right = new TreeNode(10);     //root'un right değerine atama işlemi yapar.
    cout << "right: "<< root->right->value << endl;
}