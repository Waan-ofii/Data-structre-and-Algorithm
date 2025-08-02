#include<iostream>
using namespace std;

void Linear_search(int list[] ,int n, int data){
    int flag = 0;
    for(int i=0; i<n; i++){
        if(list[i] == data){
            cout<<"yes, data is found at index : "<<i<<endl;
            flag = 1;
            break;
         }
    }
    if(flag == 0){
        cout<<"No, data is not found "<<endl;
    }
}

int main(){
int n =6;
int list[n] = {33,22,55,17,39,88};
int data;
cout<<"please enter the data are you saerching for :";
cin>>data;
cout<<"is there is "<<data<<" in the array : ";
Linear_search(list,n,data);



    return 0;
}