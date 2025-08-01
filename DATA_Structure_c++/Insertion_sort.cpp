#include<iostream>
using namespace std;

void Insertion_sort(int list[], int n){
    int temp,i,j;
    for(i = 1; i < n; i++){
        temp = list[i];
        j = i-1;

        while(j >= 0 && list[j] > temp){
            list[j+1] = list[j];
            j--;
        }
        list[j+1] = temp;
    }
}

int main(){
int n=6;
int list[] ={10,5,15,20,30,25};

for(int i=0; i<n; i++){
    cout<<list[i]<<" ";    
}

Insertion_sort(list, n);
cout<<"\n sorted one"<<endl;
for(int i=0; i<n; i++){
    cout<<list[i]<<" ";    
}


    return 0;
}