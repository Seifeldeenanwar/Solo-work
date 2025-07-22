#include<iostream>
using namespace std ;

int partition(int arr[],int l , int r){
int p = arr[l] ;
int i = l ;
for(int j = l+1 ; j < r ; j++){
    if(arr[j] < p){
        i++ ;
        swap(arr[i] , arr[j]) ;
    }
}
swap(arr[i] , arr[l]) ;
return i ;
}
void quicksort(int arr[] ,  int l , int r){
    if(l >= r){
        return ;
    }
    else {
        int i = partition(arr , l, r) ;
        quicksort(arr,l , i-1) ;
        quicksort(arr ,i+1 , r) ;
    }
}



int main(){
    int arr[8] = {3,2,1,0,9,8,6,7} ;
    quicksort(arr,0,7) ;
    for(int i = 0 ; i < 8 ; i++) {
        cout << arr[i] << " " ;
    }

    return 0 ;
}