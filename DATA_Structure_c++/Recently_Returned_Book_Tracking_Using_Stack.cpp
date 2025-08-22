#include<iostream>
using namespace std;
struct Book {
    string title;
    string author;
    string returned_time;
Book* next; // acts like the 'next' in stack   
};
// this pointer represent the top of the stack
Book* top = NULL;

// Function to return a new book, it is like pushing book  to stack.
void return_book() {
    Book* New_returned_book = new Book;

    cout << "Enter Title of the Book:";
    cin.ignore(); 
    getline(cin, New_returned_book->title);
    cout << "Enter Author Name :";
    getline(cin, New_returned_book->author);
    cout << "Enter the Time at which the book is returned:";
    getline(cin, New_returned_book->returned_time);

    // this line Links the new book to the stack
    New_returned_book->next = top;
    top = New_returned_book;

    cout << "\nthe Book is successfully returned to library.\n";
}

//here we pop books from the stack
void book_On_Top() {
    if(top!= NULL) {
        Book* temp;
        cout << "Book On The Top: \n";
        cout << "Title        : " << top->title << endl;
        cout << "Author       : " << top->author << endl;
        cout << "Returned Time: " << top->returned_time << endl;
        temp=top;
        top=top->next;
        delete temp;
           
    }
   else {
        cout << "\nNo book has been returned yet.\n_";
    }

    
    
}



// Function to view recent books, we will Traverse the stack.
void view_recent_books() {
    if (top == NULL) {
        cout << "\nNo book has been returned yet.\n_";
        return;
    }
    cout << "\nRecently Returned Books:\n_";
    Book* temp = top;

    int count = 1;//this is used to print book with number
    while (temp != NULL) {
        cout << "\nBook :" << count++ << ":\n";
        cout << "Title        : " << temp->title << endl;
        cout << "Author       : " << temp->author << endl;
        cout << "Returned Time: " << temp->returned_time << endl;
        temp = temp->next;
    }
}



// Function to clear the entire return log
void remove_all_returned_book() {
    Book* temp;
    while (top != NULL) {
        temp = top;
        top = top->next;
        delete temp;
    }
    cout << "\n  Returned book  cleared.\n";
}


int main(){

int choice;

menu:
cout << "\n|______Book Tracking__________|\n";
cout <<"\n|--------------Menu------------|\n";
cout << "\n______________________________\n";
    cout << "press 1. To Return a Book to library\n";
    cout << "press 2. To Display all recently Returned Books\n";
    cout << "press 3. To See (pop) book on the top\n";
    cout << "press 4. To clear all Returned books \n";
    cout << "press 5. To Exit\n";
    cout<<"\n please enter your choice :";
    cin>>choice;
switch (choice)
{
    case 1:
	return_book(); 
    break;
    case 2:
	view_recent_books();
    break;
    case 3:
	book_On_Top();
    break;
    case 4: 
	remove_all_returned_book();
    break;
    case 6:
    	return 0;
    	break;
    default: cout<<" Please Enter valid choice";
    
}
goto menu;
    
}
