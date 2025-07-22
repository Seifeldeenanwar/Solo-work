#include<iostream>
using namespace std ;

class node{
    public:
    int value ;
    node* next ;
    node(int value){
        this->value = value ;
        next = nullptr ;
    }
};

class CircularLinkedList{
    node* head = nullptr ;
    node* tail = nullptr ;
    public :
    bool isempty(){
        return head == nullptr ;
    }
    void insert_back(int val){ // o(1) 
        node* newnode = new node(val) ;
        if(head == nullptr){
            head = tail = newnode ;
        }
        else {
            tail->next = newnode ;
            tail = newnode ;
            tail->next = head ;
        }
    }
    void insert_front(int val){ // o(1)
        node* newnode = new node(val) ;
        if(head == nullptr){
            head = tail = newnode ;
        }
        else{
            newnode->next = head ;
            head = newnode ;
            tail->next = head ;
        }
    }
    void insert_after(int val , int prev) { // o(n)
        node* newnode = new node(val) ;
        if(head == nullptr){
            head = tail = newnode ;
        }
        else {
            node*temp = head ;
            while(temp != tail && temp->value != prev){
                temp = temp->next ;
            }
            if(temp == tail && tail->value != prev){
                cout << prev << " does not exist!" <<endl; 
            }
            else if(tail->value == prev){
                tail->next = newnode ;
                tail = newnode ;
                tail->next = head ;
            }
            else {
                newnode->next = temp->next ;
                temp->next = newnode ;
            }
        }
    }
    void clear(){ //o(n)
        node* temp = head ;
        while(temp != tail){
            node* prev = temp ;
            temp = temp->next ;
            delete prev ;
        }
        head = tail = nullptr ;
    }
    void displaylist(){ //o(n)
        if(isempty()){
            cout << "list is already empty !" << endl; 
            return ;
        }
        node*temp = head ;
        while(temp != tail){
            cout << temp->value << " " ;
            temp = temp ->next ;
        }
        cout << tail->value << " " ;
        cout << endl; 
    }
    void deletefront(){
        if(isempty()){
            cout << "list is already empty !" << endl; 
            return ;
        }
        else if (head == tail){
            node* temp = head ;
            head = tail = nullptr ;
            delete temp ;

        }
        else {
            node* temp = head ;
            head = head->next ;
            delete temp ;
            tail->next = head ;
        }
    }
    ~CircularLinkedList() {
        clear();
    }


};

int main(){
    CircularLinkedList c ;
    c.insert_front(15) ;
    c.insert_front(16) ;
    c.insert_front(1) ;
    c.insert_back(11) ;
    c.insert_back(18) ;
    c.displaylist() ;
    c.insert_after(22,16) ;
    c.insert_after(25,15) ;
    c.deletefront() ;
    c.displaylist() ;



    return 0;
}