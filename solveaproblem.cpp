#include<iostream>
using namespace std ;

void solve(int arr[] , int sz , int k){
    for(int i = 0 ; i < sz-1 ;i++){
        for(int j = i+1 ; j < sz ;j++){
            if(arr[i]+arr[j] == k){
                cout << "found :)" << endl; 
                return ; 
            }
        }
    }
    cout <<"not found :(" << endl; 
}
int main(){
    int arr[] = {1,2,3,4,5,6,7,8} ;
    int sz = sizeof(arr)/sizeof(arr[0]) ;
    solve(arr,sz,16) ;


    return 0; 
}