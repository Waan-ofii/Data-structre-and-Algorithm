#include<iostream>
using namespace std;

struct node{
    int data;
    node *next;   
};
node *head,*temp;
int main(){
int choice = 0;

while(!choice){
    node *newnode=new node;
    cout<<"please enter a data : ";
    cin>>newnode->data;
    newnode->next = NULL;

    if(head == NULL){
        head = temp = newnode;    
    }else{
        temp->next = newnode;
        temp = newnode;
    }
cout<<"if you want to CONTINUE enter :0 \n To STOP enter a number EXCEPT(0) : ";
cin>>choice;
}
temp = head;
while(temp != NULL){
    cout<<temp->data<<"  ";
    temp=temp->next;
}


return 0;
}