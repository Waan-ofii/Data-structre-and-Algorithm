package Data_Structure_inJava;

import java.util.Scanner;

class node{
    int data;
    node next;
}

public class SingleLinkedList {
    node head , temp;
    Scanner numb=new Scanner(System.in);

    public void Insert_node_at_start(){
        node newnode=new node();
        System.out.print("\n please insert data : ");
        newnode.data=numb.nextInt();
        if(head == null){
            head = newnode;
        }else{
            head.next = newnode;
            head = newnode;
        }

        System.out.println("data inserted at front succesfully! ");
    }

    public void Insert_node_at_specific_position(int pos){
        node newnode=new node();
        System.out.print("\n please insert data : ");
        newnode.data=numb.nextInt();
        newnode.next=null;

        if(head == null){
            head = newnode;
        }else{
            node cur;
            node pre = null;
            cur = head;
            for(int i=1; i<pos; i++){
                pre=cur;
                cur=cur.next;
            }
            newnode.next=cur;
            pre.next=newnode;
        }
        System.out.println("data inserted at specific position succesfully! ");
    }

    public void Insert_node_at_end(){
        node newnode=new node();
        System.out.print("\n please enter a data : ");
        newnode.data=numb.nextInt();
        newnode.next= null;

        if(head == null){
          head =newnode;
        }else{
            node cur;
            cur = head;
            while(cur.next != null){
                cur=cur.next;
            }
            cur.next=newnode;
        }
        System.out.println("data inserted at end succesfully! ");
    }

    public void Remove_data_from_start(){
        if(head == null){
            System.out.println("List is empty");
        }else{
            node cur;
            cur=head;
            head=head.next;
            cur=null;
        }
        System.out.println("data is removed from start succesfully! ");
    }
    public void Remove_data_from_specific_position(int pos){
        if(head == null){
            System.out.println("List is empty");
        }else{
            node current;
            node pre = null;
            current = head;
            for(int i=0; i<pos; i++){

                    pre = current;
                    current = current.next;
            }
            if(current == null){
                System.out.println("current is out of bound ");
            }else {
                pre.next = current.next;
            }
        }
        System.out.println("data is removed from specific position succesfully! ");
    }
    public void Remove_data_from_end(){
        if(head == null){
            System.out.println("List is empty");
        }else{
            node cur;
            node pre=null;
            cur=head;
            while(cur.next != null){
                pre=cur;
                cur=cur.next;
            }
            pre.next=null;
            cur=null;
        }
        System.out.println("data is removed from end succesfully! ");
    }

    public void display(){
        if(head == null) {
            System.out.println("list is empty");
        }else {
            node cur ;
            cur= head;
            System.out.println("Here is a list of data");
            while (cur != null) {
                System.out.print(cur.data + "  ");
                cur = cur.next;
            }
        }
    }

    public static void main(String[] args) {
        Scanner opt=new Scanner(System.in);
        SingleLinkedList obj = new SingleLinkedList();
        int choice;
        boolean again = true;
        while (again) {
            System.out.println(" \n Welcome to Single Linked List Operation");
            System.out.println("press 1: To add node at start ");
            System.out.println("press 2: To add node at specific position ");
            System.out.println("press 3: To add node at end ");
            System.out.println("press 4: To remove node from start ");
            System.out.println("press 5: To remove node from specific position ");
            System.out.println("press 6: To remove node from end ");
            System.out.println("press 7: To Display a list ");
            System.out.println("press 8: To Exit ");

            System.out.print("\n please enter your option : ");
            choice=opt.nextInt();

            switch(choice){
                case 1:
                   obj.Insert_node_at_start();
                    break;
                case 2:
                    int pos;
                    System.out.print("please enter a position : ");
                    pos=opt.nextInt();
                    obj.Insert_node_at_specific_position(pos);
                    break;
                case 3:
                    obj.Insert_node_at_end();
                    break;
                case 4:
                    obj.Remove_data_from_start();
                    break;
                case 5:
                    int posi;
                    System.out.print("please enter a position : ");
                    posi=opt.nextInt();
                    obj.Remove_data_from_specific_position(posi);
                    break;
                case 6:
                    obj.Remove_data_from_end();
                    break;
                case 7:
                    obj.display();
                    break;
                case 8:
                    System.out.println("Good Bye !");
                    again = false;
                    break;
                default:
                    System.out.println("Invalid option");
            }
        }




    }
}
