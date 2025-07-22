#include<iostream>
using namespace std ;

template<class t>
class node{
    public :
    t value ;
    node* next ;
    node(t value){
        this->value = value ;
        next = nullptr ;
    }
};
template<class t>
class stack {
    int sz ;
    node<t>* head = nullptr ;
    public:
    void push(t val) {
        node<t>* newnode = new node<t>(val) ;
        if(head == nullptr){
            head = newnode ;
        }
        else {
            newnode->next = head ;
            head = newnode ;
        }
        sz++ ;
    }
    void pop(){
        if(head == nullptr){
            cout << "Stack is empty!" << endl; 
            return ;
        }
        node<t>* temp = head ;
        head = head->next ;
        delete temp ;
        sz-- ;
    }
    bool isempty(){
        return head == nullptr ;
    }
    t top(){
        if(head == nullptr){
            cout << "Stack is empty!" << endl; 
            return t() ;
        } 
        return head->value ;
    }
    int getsize(){
        return sz ;
    }
    void display(){
        node<t>*temp = head ;
        while(temp != nullptr){
            cout << temp->value << " " ;
            temp = temp -> next ;
        }

    }
};
void addLargeNummbers(string n1 , string n2){
    stack<char> s1 ;
    stack<char> s2 ;
    for(int i = 0 ; i < n1.size() ;i++){
        s1.push(n1[i]) ;
    }
    for(int i = 0 ; i < n2.size() ; i++){
        s2.push(n2[i]) ;
    }
    long long sum = 0 ;
    long long mult = 1 ; 
    while (!s1.isempty() && !s2.isempty())
    {
        int num1 = s1.top() - '0' ;
        int num2 = s2.top() - '0' ;
        sum += num1*mult + num2*mult ;
        mult*=10 ;
        s1.pop() ;
        s2.pop() ;
    }
    while(!s1.isempty()){
        int num1 = s1.top() -'0' ;
        sum += num1*mult ;
        mult*=10 ;
        s1.pop() ;
    }
    while(!s2.isempty()){
        int num2 = s2.top() -'0' ;
        sum += num2*mult ;
        mult*=10 ;
        s2.pop() ;
    }
    cout << "Sum of "<< n1 << " and " << n2 << " = " << sum << endl; 
} 
bool checkBrackets(string str){
    stack<char> s ;
    for(char c : str){
        if(c == '(' || c == '[' || c == '{'){
        s.push(c) ;
        }
        if(s.isempty()){
            return false ;
        }
        char tp = s.top() ;
        if(c == ')' && tp == '('){
            s.pop() ;
        }
        else if(c == ']' && tp == '['){
            s.pop() ;
        }
        else if (c == '}' && tp == '{'){
            s.pop() ;
        }
    }
    return s.isempty();
}
void calculatePostfix(string exp){
    stack<int> s ;
    for(int i = 0 ; i < exp.size() ; i++){
        if(isdigit(exp[i])){
            s.push(exp[i]-'0') ;
        }
        else if (exp[i] == '*' || exp[i] == '/' || exp[i] == '+' || exp[i] == '-'){
            int result = 0 ;
            int num1 = s.top() ;
            s.pop() ;
            int num2 = s.top();
            s.pop() ;
            if(exp[i] == '*') {
                result = num1*num2 ;
                s.push(result) ;
            }
            else if(exp[i] == '+'){
                result = num1+num2 ;
                s.push(result) ;
            }
            else if(exp[i] == '-'){
                result = num2-num1 ;
                s.push(result) ;
            }
            else if(exp[i] == '/'){
                result = num2/num1 ;
                s.push(result) ;
            }
        }
    }
    cout << "Answer = " << s.top() << endl; 
}
int main(){
    // string n1 ;
    // string n2 ;
    // cout << "Enter two values -> " ;
    // cin >> n1 >> n2 ;
    // addLargeNummbers(n1,n2) ;
    // stack<char> s ;
    // s.push('6') ;
    // s.push('1') ;
    // s.push('2') ;
    // s.push('3') ;
    // s.push('4') ;
    // cout << s.isempty() << endl; 
   // cout << checkBrackets("[5+4]({10/2}-3)") ;
   //calculatePostfix("342*+5-");



    return 0 ;
}
