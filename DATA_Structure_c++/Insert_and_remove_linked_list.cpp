#include<iostream>
using namespace std;

struct node{
    int data;
    node *next;
};
node *head,*newnode, *temp;

void Insert_Node_At_Start(){
    newnode= new node;
    cout<<"please enter data : ";
    cin>>newnode->data;
    if(head == NULL){
        head = newnode;
    }else{
    newnode->next=head;
    head=newnode;
    }
}

void Insert_Node_At_Specific_Position(int pos){
    newnode =new node;
    cout<<"please enter a data : ";
    cin>>newnode->data;
    newnode->next=NULL;

    if(head == NULL){
        head =newnode;   
    }else{
        node *pre,*cur;
        cur=head;
        for(int i=1; i<pos; i++){
            pre=cur;
            cur=cur->next;
        }
        newnode->next=cur;
        pre->next= newnode;
    }
}

void Insert_Node_At_End(){
    newnode = new node;
    cout<<"please enter a data :";
    cin>>newnode->data;
    newnode->next=NULL;

    if(head == NULL){
        head=newnode;
    }else{
        temp=head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next=newnode;
    }
}

void Remove_From_Start(){
    if(head == NULL){
        cout<<" list is empty "<<endl;
     }else{
       temp = head;
       head = head ->next;
       delete temp;
     }
}

void Remove_From_Specific_position(int pos){
    if(head == NULL){
        cout<<"list is empty"<<endl;
    }else{
        node *pre,*cur;
        cur = head;
        for(int i=1; i<pos; i++){
            pre=cur;
            cur=cur->next;
        }
        pre->next=cur->next;
        delete cur;
    }
}

void Remeove_From_End(){
    if(head == NULL){
       cout<<"list is empty"<<endl; 
    }else{
        node *pre,*cur;
        cur= head;
        while(cur != NULL){
            pre=cur;
            cur=cur->next;
        }
        pre->next=NULL;
        delete cur;
    }
}

void Display(){
if(head == NULL){
    cout<<"list is empty"<<endl;
}else{
    temp = head;
    while(temp != NULL){
        cout<<temp->data<<"  ";
        temp=temp->next;
    }

}
}

int main(){
    int choice;
    cout<<"\n    Welcome To Single Lnked List Operations \n"<<endl;
    menu:
    	
cout<<"\n press 1 To add node at start"<<endl;
cout<<"press 2 To add node at specific position"<<endl;
cout<<"press 3 To add node at end"<<endl;
cout<<"press 4 To remove node from start"<<endl;
cout<<"press 5 To remove node from specific position"<<endl;
cout<<"press 6 To remove node from end"<<endl;
cout<<"press 7 To Display a list"<<endl;
cout<<"press 8 To Exit"<<endl;

cout<<"\n please enter your option : ";
cin>>choice;

switch(choice){
case 1:
    Insert_Node_At_Start();
break;
case 2:
    int pos;
    cout<<"please enter a position :";
    cin>>pos;
    Insert_Node_At_Specific_Position(pos);
break;
case 3:
    Insert_Node_At_End();
break;
case 4:
    Remove_From_Start();
break;
case 5:
    int posi;
    cout<<"please enter a position :";
    cin>>posi;
   Remove_From_Specific_position(posi);
break;
case 6:
   Remeove_From_End();
break;
case 7:
  Display();
  break;
case 8:
    return 0;
    break;
default:
    cout<<"Invalid input try again "<<endl;
}
goto menu;
 
}
