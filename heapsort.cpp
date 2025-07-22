#include<iostream>
using namespace std ;

void maxheapify(int arr[] , int sz , int target){
    int l = 2*target + 1 ;
    int r = 2*target + 2 ;
    int largest = target ;
    if(l < sz && arr[l] > arr[largest]) {
        largest = l ;
    }
    if (r < sz && arr[r] > arr[largest]){
        largest = r ;
    }
    if(largest != target){
        swap(arr[largest] , arr[target]) ;
        maxheapify(arr , sz , largest);
    }
}
void buildmaxheapify(int arr[] ,int sz){
    for(int i = (sz/2) - 1 ; i >= 0 ;i--){
        maxheapify(arr,sz,i) ;
    }
}
void heapsort(int arr[] , int sz){
    buildmaxheapify(arr,sz) ;
    cout << "here " << endl; 
    for(int i = sz-1 ; i > 0 ;i--){
        swap(arr[0] , arr[i]);
        maxheapify(arr,i,0) ;
    }
    for(int i = 0 ; i < sz  ; i++){
        cout << arr[i] << " " ;
    }
}

int main(){

    int arr[8] = {5,4,3,8,2,10,1,0} ;
    heapsort(arr,8) ;


    return 0 ; 
}