#include<iostream>
#include<fstream>
using namespace std ;

template <class t>
class node{
    public:
    t value ;
    node<t>* next ;
    node(t value){
        this->value = value ;
        this->next = nullptr;
    }  
};
template<class t>
class stack {
    node<t>* head = nullptr ;
    int size = 0 ;
    public:
    void push(t data){
        node<t> *newnode = new node<t>(data) ;
        newnode->next = head ;
        head = newnode ;
        size++ ;
    }
    void pop(){
        if(head != nullptr){
            node<t> *temp = head ;
            head = head->next ;
            delete temp ;
            size-- ;
        }
        else {
            cout << "Stack is empty you cannot pop !" << endl; 
        }
    }
    bool isempty(){
        return head == nullptr ;
    }
    t top(){
        if(!isempty()){
         return head->value ;
        }
        else {
            cout << "Stack already empty !" << endl; 
            return t() ;
        }
    }
    int getsize(){
        return size ;
    }
    void print(){
        node<t> *temp = head ;
        while(temp != nullptr){
            cout << temp->value << " " ;
            temp = temp->next ;
        }
        cout << endl ;
    }
    void clear(){
        node<t> *pre = head ;
        while(pre != nullptr){
            node<t>* curr = pre ;
            pre = pre->next ;
            delete curr ;
        }
        head = nullptr ;
        size = 0 ;
    }
};

class BrowserHistorySystem {
    stack<string> back ;
    stack<string> forward ;
    string currentsite ;
public:
    void visit(string sitename){
        back.push(sitename) ;
        currentsite = back.top() ;
        forward.clear() ;
        cout << "Visit new site : " << endl;
        cout << "The current site -> " << currentsite << endl;
        cout << endl; 
    }
    void goback(){
    if(back.getsize() > 1) {
        cout << "Go back : " << endl; 
        forward.push(back.top());
        back.pop() ;
        currentsite = back.top() ;
    }
    else {
        cout << "it's impossible to go backward !" << endl; 
    }
    cout << "The current site -> " << currentsite << endl;
    cout << endl; 
}
    void goforward(){
    if(!forward.isempty()){
        cout << "Go forward : " << endl; 
        back.push(forward.top());
        forward.pop() ;
        currentsite = back.top() ;
    }
    else {
        cout << "it's immpossible to go forward !" << endl;
    }
    cout << "The current site -> " << currentsite << endl;
    cout << endl; 
}
void printstacks(){
    cout << "back stack : " ;
    back.print() ; 
    cout << "forward stack : " ;
    forward.print() ;
}
};

int main(){
    BrowserHistorySystem bhs ;
    // bhs.visit("google.com") ;
    // bhs.goback() ;
    // bhs.visit("wikipedia.org") ;
    // bhs.visit("youtube.com");
    // bhs.goback();
    // bhs.goback() ;
    // bhs.goforward();
    // bhs.visit("facebook.com") ;
    // bhs.goforward() ;
    // bhs.printstacks() ;
    ifstream file("pb1.txt");
    string word ;
    while(file >> word){
        if(word == "visit"){
            string nxtword ;
            file >> nxtword ;
            bhs.visit(nxtword) ;
        }
        else if(word == "goback"){
            bhs.goback() ;
        }
        else if(word == "goforward"){
            bhs.goforward();
        }
    }

    return 0 ;
}
