#include<iostream>
#include<cstring>
using namespace std;


class BookType {
private:
    char bookTitle[80];
    char bookAuthor[80];
    char bookISBN[80];
    char bookEdition[80];
    double bookPrice;

public:
    BookType* next;

    
    BookType() {
        next = nullptr;
    }

    // SETTERS TO USE PRIATE VARIABL
    void setBookTitle(const char* title) {
        strncpy(bookTitle, title, sizeof(bookTitle));
    }

    void setBookAuthor(const char* author) {
        strncpy(bookAuthor, author, sizeof(bookAuthor));
    }

    void setBookISBN(const char* isbn) {
        strncpy(bookISBN, isbn, sizeof(bookISBN));
    }

    void setBookEdition(const char* edition) {
        strncpy(bookEdition, edition, sizeof(bookEdition));
    }

    void setBookPrice(double price) {
        bookPrice = price;
    }

    // GETTERS FUNCTION TO PRINT PRIVATE VARIABLE
    const char* getBookTitle() const {
        return bookTitle;
    }

    const char* getBookAuthor() const {
        return bookAuthor;
    }

    const char* getBookISBN() const {
        return bookISBN;
    }

    const char* getBookEdition() const {
        return bookEdition;
    }

    double getBookPrice() const {
        return bookPrice;
    }
};


BookType* head = nullptr;
BookType* current;

void Add_Book_at_Start() {
    BookType* temp = new BookType;

    char title[80], author[80], isbn[80], edition[80];
    double price;

    cout << "Enter book Title: ";
    cin >> title;
    cout << "Enter book Author: ";
    cin >> author;
    cout << "Enter book ISBN: ";
    cin >> isbn;
    cout << "Enter book Edition: ";
    cin >> edition;
    cout << "Enter book Price: ";
    cin >> price;

    temp->setBookTitle(title);
    temp->setBookAuthor(author);
    temp->setBookISBN(isbn);
    temp->setBookEdition(edition);
    temp->setBookPrice(price);

    temp->next = head;
    head = temp;

    cout << "\nBook successfully stored at the start.\n";
}

void Add_Book_at_End() {
    BookType* temp = new BookType;

    char title[80], author[80], isbn[80], edition[80];
    double price;

    cout << "Enter book Title: ";
    cin >> title;
    cout << "Enter book Author: ";
    cin >> author;
    cout << "Enter book ISBN: ";
    cin >> isbn;
    cout << "Enter book Edition: ";
    cin >> edition;
    cout << "Enter book Price: ";
    cin >> price;

    temp->setBookTitle(title);
    temp->setBookAuthor(author);
    temp->setBookISBN(isbn);
    temp->setBookEdition(edition);
    temp->setBookPrice(price);
    temp->next = nullptr;

    if (head == nullptr) {
        head = temp;
    } else {
        current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = temp;
    }

    cout << "\nBook successfully stored at the end.\n";
}

void Add_Book_at_specificPosition(int position) {
    if (position <= 0) {
        cout << "Invalid position.\n";
        return;
    }

    BookType* temp = new BookType;

    char title[80], author[80], isbn[80], edition[80];
    double price;

    cout << "Enter book Title: ";
    cin >> title;
    cout << "Enter book Author: ";
    cin >> author;
    cout << "Enter book ISBN: ";
    cin >> isbn;
    cout << "Enter book Edition: ";
    cin >> edition;
    cout << "Enter book Price: ";
    cin >> price;

    temp->setBookTitle(title);
    temp->setBookAuthor(author);
    temp->setBookISBN(isbn);
    temp->setBookEdition(edition);
    temp->setBookPrice(price);
    temp->next = nullptr;

    if (position == 1 || head == nullptr) {
        temp->next = head;
        head = temp;
    } else {
        BookType* prev = head;
        for (int i = 1; i < position - 1 && prev->next != nullptr; ++i) {
            prev = prev->next;
        }
        temp->next = prev->next;
        prev->next = temp;
    }

    cout << "Book successfully stored at specific position.\n";
}

void Remove_Book_at_Start() {
    if (head == nullptr) {
        cout << "\nList is empty.\n";
    } else {
        BookType* temp = head;
        head = head->next;
        delete temp;
        cout << "\nBook successfully deleted from start.\n";
    }
}

void Remove_Book_at_End() {
    if (head == nullptr) {
        cout << "No item to delete.\n";
        return;
    }

    if (head->next == nullptr) {
        delete head;
        head = nullptr;
    } else {
        BookType* temp1 = head, * temp2 = nullptr;
        while (temp1->next != nullptr) {
            temp2 = temp1;
            temp1 = temp1->next;
        }
        temp2->next = nullptr;
        delete temp1;
    }

    cout << "\nBook successfully deleted from end.\n";
}

void Remove_Book_at_SpecificPosition(int position) {
    if (head == nullptr) {
        cout << "\nList is empty.\n";
        return;
    }

    if (position == 1) {
        BookType* temp = head;
        head = head->next;
        delete temp;
    } else {
        BookType* prev = nullptr, * curr = head;
        for (int i = 1; i < position && curr != nullptr; ++i) {
            prev = curr;
            curr = curr->next;
        }
        if (curr == nullptr) {
            cout << "\nInvalid position.\n";
            return;
        }
        prev->next = curr->next;
        delete curr;
    }

    cout << "\nBook successfully removed from specific position.\n";
}

void printBookInformation() {
    if (head == nullptr) {
        cout << "\nList is empty.\n";
    } else {
        current = head;
        cout << "\nBook List:\n";
        while (current != nullptr) {
            cout << "---------------------------\n";
            cout << "Book Title: " << current->getBookTitle() << endl;
            cout << "Book Author: " << current->getBookAuthor() << endl;
            cout << "Book ISBN: " << current->getBookISBN() << endl;
            cout << "Book Edition: " << current->getBookEdition() << endl;
            cout << "Book Price: " << current->getBookPrice() << endl;
            current = current->next;
        }
    }
}

void Search_Book_ByName() {
    if (head == nullptr) {
        cout << "\nList is empty.\n";
        return;
    }

    char searchName[80];
    cout << "Enter the Book Name(Tittle) to search: ";
    cin >> searchName;

    BookType* temp = head;
    bool found = false;

    while (temp != nullptr) {
        if (strcmp(temp->getBookTitle(), searchName) == 0) {
            cout << "\nBook Found:\n";
            cout << "Book Title: " << temp->getBookTitle() << endl;
            cout << "Book Author: " << temp->getBookAuthor() << endl;
            cout << "Book ISBN: " << temp->getBookISBN() << endl;
            cout << "Book Edition: " << temp->getBookEdition() << endl;
            cout << "Book Price: " << temp->getBookPrice() << endl;
            found = true;
            break;
        }
        temp = temp->next;
    }

    if (!found) {
        cout << "\nBook with title \"" << searchName << "\" not found.\n";
    }
}

int main() {
    int choice;

    menu:
        cout << "\n\n   LINKED LIST PROJECT  \n";
        cout << "1. ADD Book at START\n";
        cout << "2. ADD Book at END\n";
        cout << "3. ADD Book at SPECIFIC POSITION\n";
        cout << "4. REMOVE Book at START\n";
        cout << "5. REMOVE Book at END\n";
        cout << "6. REMOVE Book at SPECIFIC POSITION\n";
        cout << "7. PRINT All Books\n";
        cout << "8. SEARCH Book by NAME\n";
        cout << "9. Exit\n";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
			 Add_Book_at_Start(); 
			 break;
            case 2:
			 Add_Book_at_End(); break;
            case 3: 
                int add_pos;
                cout << "Enter position: ";
                cin >> add_pos;
                Add_Book_at_specificPosition(add_pos);
                break;
            
            case 4:
			 Remove_Book_at_Start();
			  break;
            case 5: 
			Remove_Book_at_End(); 
			break;
            case 6: 
                int rem_pos;
                cout << "Enter position: ";
                cin >>rem_pos;
                Remove_Book_at_SpecificPosition(rem_pos);
                break;
            
            case 7:
			 printBookInformation();
			  break;
            case 8: 
			Search_Book_ByName(); 
			break;
            case 9:
			 return 0;
			 break;
            default:
			 cout << "Invalid choice! Try again.\n";
        }
    goto menu;
}
