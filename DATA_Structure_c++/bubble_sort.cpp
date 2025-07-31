#include<iostream>
using namespace std;

void bubble_sort(int list[], int n){
int temp;
bool flag;

for(int i=0; i<n-i; i++){
    flag = false;
    for(int j = 0;  j < n - 1 - i; i++){
        if(list[j] > list[j+1]){
            temp = list[j];
            list[j] = list[j+1]; 
            list[j+1] = temp;

            flag = true;
        }
    }
    if(flag == false){
        break;
    }
}
} 

int main(){

 int n = 6;   
int list [n] = {10,5,20,15,30,25};

for(int i = 0; i < n-1; i++){
    cout<<list[i]<<" ";
}
cout<<"\n sorted one"<<endl;
bubble_sort(list , n);
for(int i = 0; i < n; i++){
    cout<<list[i]<<" ";
}

return 0;
}