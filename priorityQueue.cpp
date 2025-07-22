#include<iostream>
using namespace std ;

class node{
    public :
    int value ;
    int priority ;
    node* next ; 
    node(int value , int priority){
        this->value = value ;
        this->priority = priority ;
        next = nullptr ;
    }
};

class priorityQueue {
    node* head = nullptr ;
    public :
    void enqueue(int val , int p){
        node* newnode = new node(val,p) ;
        if(head == nullptr){
            head = newnode ;
        }
        else if(newnode->priority > head->priority){
            newnode->next = head ;
            head = newnode ;
        }
        else {
            node* temp = head ;
            node* prev = temp ;
            while(temp != nullptr && temp->priority >= p){
                prev = temp ;
                temp = temp->next ;
            }
            if(temp == nullptr){
                prev->next = newnode ;
            }
            else {
                prev->next = newnode ;
                newnode->next = temp ;
            }
        }
    }
    void dequeue(){
        if(head == nullptr){
            cout << "Queue is empty " << endl; 
            return ;
        }
        node* temp = head ;
        head = head->next ;
        delete temp ;
    }
    void display(){
        node* temp = head ;
        while(temp != nullptr){
            cout << "[" << temp->value << " , " << temp->priority << "] " << "-> " ;
            temp = temp -> next ;
        }
        cout << " NULL" << endl; 
    }

};

int main(){
    priorityQueue p ;
    cout << "priority with highest :) " << endl; 
    cout << " [value , priority] " << endl; 
    p.enqueue(50 , 77) ;
    p.enqueue(80,80) ;
    p.enqueue(500,99) ;
    p.enqueue(800,1) ;
    p.enqueue(8,1000) ;
    p.display() ;
    p.dequeue() ;
    p.display() ;


    return 0 ;
}




