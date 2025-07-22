#include<iostream>
using namespace std ;

void max_heapify(int arr[] ,int sz ,int pos){//log(n)
    int l = 2*pos +1 ;
    int r = 2*pos +2 ;
    int max = pos  ;
    if(l < sz && arr[l] > arr[max]){
        max = l ;
    }
    if(r < sz && arr[r] > arr[max]){
        max = l ;
    }
    if(max != pos){
        swap(arr[max] , arr[pos]) ;
        max_heapify(arr,sz,max) ;
    }

}
void build_max(int arr[] , int sz){//n
    for(int i = sz/2 - 1 ; i >= 0 ;i--){
        max_heapify(arr,sz,i) ;
    }
}
void maxheapSort(int arr[] , int sz){//nlogn 
    build_max(arr,sz) ;
    for(int i = sz-1 ; i > 0 ;i--){
        swap(arr[0] , arr[i]) ;
        max_heapify(arr,i ,0) ;
    }
}

void min_heapify(int arr[] , int sz , int pos){
    int l = 2*pos +1 ;
    int r = 2*pos +2 ;
    int min = pos ;
    if(l < sz && arr[l] < arr[min]){
        min = l ;
    }
    if(r < sz && arr[r] < arr[min]){
        min = r ;
    }
    if(min != pos){
        swap(arr[pos] , arr[min]);
        min_heapify(arr,sz,min) ;
    }
}
void build_min(int arr[] , int sz){
    for(int i = sz/2 -1 ; i >=0 ;i--){
        min_heapify(arr,sz,i) ;
    }
}
void minHeapSort(int arr[] , int sz){//extra space
    build_min(arr,sz) ;
    int arr2[sz] ;
    for(int i = 0 ; i < sz ; i++){
        min_heapify(arr,sz,i) ;
        arr2[i] = arr[i] ;
    }
    for(int i = 0 ; i < sz ; i++){
        cout << arr2[i] << " " ;
    }
    cout << endl;
}

int main(){
    int arr[] = {6,5,4,3,2,1,9,11} ;
    int size = sizeof(arr)/sizeof(arr[0]) ;
    // maxheapSort(arr,size) ;
    // for(int i = 0 ; i < size ; i++){
    //     cout << arr[i] << " " ;
    // }
    minHeapSort(arr,size) ;



    return 0 ;
}