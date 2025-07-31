#include<iostream>
using namespace std;


void selection_sort(int list[], int n){
    int smallest, temp ,i,j;
for( i = 0; i<n-1; i++){
    smallest = i;
    for( j = i+1; j<n; j++){
        if(list[j]< list[smallest]){
            smallest = j;
        }
    }

if(smallest != i){
    temp = list[smallest];
    list[smallest] = list[i];
    list[i] = temp;
}
}
}

int main(){
    int n = 6;
    int list[n] = {6,3,5,4,9,2,7};
    for(int i = 0; i < n; i++){
        cout<<list[i]<<" ";
    }
    selection_sort(list,n);
    cout<<"\n sorted"<<endl;
    for(int i = 0; i < n; i++){
        cout<<list[i]<<" ";
    }
    
    return 0;
}