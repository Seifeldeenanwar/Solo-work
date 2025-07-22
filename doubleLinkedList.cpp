#include<iostream>
using namespace std ;

class node{
public :
int value ;
node* next ;
node* past ;
node(int value) {
    this->value = value ;
    next = nullptr ;
    past = nullptr ;
}
};

class DoubleList {
    node* head = nullptr ;
    node* tail = nullptr ;
    public :
    void insert(int val){//o(1) , in worst case o(n)
        node* newnode = new node(val) ;
        if(head == nullptr){
            head = newnode ;
            tail = newnode ;
        }
        else {
            node*temp = head ;
            while(temp != nullptr && temp->value < val){
                temp = temp->next ;
            }
            if(temp == nullptr){
            tail->next = newnode ;
            newnode->past = tail ;
            tail = newnode ;
            }
            else if (temp == head){
                newnode->next = head ;
                head->past = newnode ;
                head = newnode ;
            }
            else{
                temp->past->next = newnode ;
                newnode->past = temp->past ;
                newnode->next = temp ;
                temp->past = newnode ;  
            }
        }
    }
    void displayForward(){//o(n)
        node* temp = head ;
        while(temp != nullptr){
            cout << temp->value << " -> " ;
            temp = temp->next ;
        }
        cout << "NULL" << endl;
    }
    void displayBackward(){//o(n)
        node* temp = tail ;
        while(temp!= nullptr){
            cout << temp->value << " -> " ;
            temp = temp->past ;
        }
        cout << "NULL" << endl; 
    }
    void del(int val){
        node* temp = head ;
        while(temp != nullptr && temp->value != val){
            temp = temp->next ;
        }
        if(temp != nullptr){
        temp->past->next = temp->next ;
        temp->next->past = temp->past ;
        }
        else {
            cout << val << " not found!" << endl; 
        }
        delete temp ;
    }
    void search(int val){
        node* temp = head ;
        while(temp != nullptr && temp->value != val){
            temp = temp->next ;
        }
        if(temp != nullptr){
            cout << val << " Found :)" << endl; 
        }
        else {
            cout << val << " Not found :( " << endl; 
        }
    }

}; 

int main(){
    DoubleList d ;
    d.insert(5) ;
    d.insert(7) ;
    d.insert(6) ;
    d.insert(3) ;
    d.insert(8) ;
    d.insert(-1) ;
    d.insert(77) ;
    d.insert(44) ;
    d.displayForward() ;
    d.displayBackward() ;
    d.del(44) ;
    d.displayForward() ;
    d.search(1) ;
    d.search(5) ;



    return 0 ;
}