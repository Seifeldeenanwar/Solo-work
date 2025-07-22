#include <iostream>
using namespace std;

template <typename T>
struct node {
    T item;
    node* next;
    node* prev ;
};

template <class T>
class linkedlist {
    node<T>* head;
    node<T>* tail;
    int size;

public:
    linkedlist() {
        size = 0;
        head = tail = NULL;
    }

    void insertionfront(T element) {
        node<T>* newnode = new node<T>();
        newnode->item = element;
        newnode->next = NULL; 
        newnode->prev = NULL ;

        if (size == 0) {
            head = tail = newnode ;
        }
        newnode->next = head ;
        head = newnode ;
        size++;
    }

    bool isempty() {
        return size == 0;
    }

    void insertmiddle(int indx, T element) {
        if (indx < 0 || indx > size) {
            cout << "Index out of bounds!" << endl;
            return;
        }

        if (indx == 0) {
            insertionfront(element);
            return;
        }

        node<T>* newnode = new node<T>(); // Allocate memory
        newnode->item = element;

        node<T>* currentnode = head;
        for (int i = 1; i < indx; i++) {
            currentnode = currentnode->next;
        }

        newnode->next = currentnode->next; // Correct linking
        currentnode->next = newnode;

        if (newnode->next == NULL) {
            tail = newnode; // Update tail if inserted at the end
        }

        size++;
    }
    void insertback(T element){
        node<T>*newnode = new node<T>() ;
        newnode->item = element ;
        if(size == 0){
        head = tail = newnode ;
        newnode->next = NULL ;
        }
        else {
            tail->next = newnode ;
            newnode->next = NULL ;
            tail = newnode ;
        }
        size++ ;
    }
    void display() {
        node<T>* curr = head;
        while (curr != NULL) {
            cout << curr->item << " ";
            curr = curr->next;
        }
        cout << endl;
    }
    void sort(){
        node<T>*pass = new node<T>() ;
        pass = head ;
        while(pass != NULL){
            if((pass->item) > (pass->next->item)){
                head = pass->next ;
                pass->next = pass;
                pass = pass->next->next ;
                
            }
            pass = pass->next ;
        }
    }

    ~linkedlist() { // Destructor to avoid memory leaks
        node<T>* curr = head;
        while (curr != NULL) {
            node<T>* temp = curr;
            curr = curr->next;
            delete temp;
        }
    }
};

int main() {
    linkedlist<int> l;
    l.insertionfront(5);
    l.insertionfront(6);
    l.insertmiddle(1, 7); 
    l.insertback(18) ;
    l.sort() ;
    l.display();
    return 0;
}
