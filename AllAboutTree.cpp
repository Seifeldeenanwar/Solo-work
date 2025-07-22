#include<iostream>
using namespace std ;

class node{
    public:
    int value ;
    node* left ;
    node* right ;
    node(int value){
        this->value = value ;
        this->left = nullptr ;
        this->right = nullptr ;
    }
};
class BST {
    node* root = nullptr ;
    public :
    void insert(int val) {
        node* newnode = new node(val) ;
        if(root == nullptr){
            root = newnode ;
        }
        else {
            node*temp = root ;
            node* pretemp ;
            while(temp != nullptr){
                pretemp = temp ;
                if(temp->value > val){
                    temp = temp->left ;
                }
                else {
                    temp = temp->right ;
                }   
            }
            if(pretemp->value > val){
                pretemp->left = newnode ;
            }
            else {
                pretemp->right = newnode ;
            }
        }
    }
    node* search(int val){
        node* temp = root ;
        while(temp != nullptr && temp->value != val){
            if(temp->value > val){
                temp = temp->left ;
            }
            else {
                temp = temp->right ;
            }
        }
        if(temp != nullptr){
            return temp ;
        }
        else{
            cout << "Node does not exist !" << endl; 
            return nullptr ;
        }
    }
    void inorderTravers(node* n){
        if(n == nullptr){
            return ;
        }
        inorderTravers(n->left) ;
        cout << n->value << " " ;
        inorderTravers(n->right) ;
    }
    void displayTree(){
        inorderTravers(root) ;
        cout << endl; 
    }
    int calculateHeight(node* n){
        if(n == nullptr){
            return -1 ;
        }
        return 1 + max(n->left,n->right) ;

    }
};
    BST bst ;
    bst.insert(10) ;
    bst.insert(8) ;
    bst.insert(11) ;
    bst.insert(2) ;
    bst.displayTree() ;


    return 0 ;
}
