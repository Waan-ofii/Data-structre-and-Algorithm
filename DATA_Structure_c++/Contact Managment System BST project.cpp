#include <iostream>
#include <string>
using namespace std;

struct Contact {
    string name;
    string phone;
    string email;
    Contact* left;
    Contact* right;

    Contact(string n, string p, string e) {
        name = n;
        phone = p;
        email = e;
        left = NULL;
        right = NULL;
    }
};

class ContactBST {
private:
    Contact* root;

    Contact* insert(Contact* node, string name, string phone, string email) {
        if (!node) {
            cout << "\n Adding new contact into the list: " << name;
            return new Contact(name, phone, email);
        }
        if (name < node->name) {
            node->left = insert(node->left, name, phone, email);
        } else if (name > node->name) {
            node->right = insert(node->right, name, phone, email);
        } else {
            cout << "\n Contact with the name " << name << " already exists";
        }
        return node;
    }

    Contact* search(Contact* node, string name) {
        if (!node || node->name == name) {
            return node;
        }
        if (name < node->name) {
            return search(node->left, name);
        } else {
            return search(node->right, name);
        }
    }

    Contact* findMin(Contact* node) {
        while (node && node->left) {
            node = node->left;
        }
        return node;
    }

    Contact* findMax(Contact* node) {
        while (node && node->right) {
            node = node->right;
        }
        return node;
    }

    Contact* remove(Contact* node, string name) {
        if (!node) {
            return node;
        }
        if (name < node->name) {
            node->left = remove(node->left, name);
        } else if (name > node->name) {
            node->right = remove(node->right, name);
        } else {
            if (!node->left) {
                Contact* temp = node->right;
                delete node;
                cout << "\n Contact " << name << " successfully deleted";
                return temp;
            } else if (!node->right) {
                Contact* temp = node->left;
                delete node;
                cout << "\n Contact " << name << " successfully deleted";
                return temp;
            }
            Contact* temp = findMin(node->right);
            node->name = temp->name;
            node->phone = temp->phone;
            node->email = temp->email;
            node->right = remove(node->right, temp->name);
        }
        return node;
    }

    void clear(Contact* node) {
        if (node) {
            clear(node->left);
            clear(node->right);
            delete node;
        }
    }

    void display(Contact* node) {
        if (!node) return;
        display(node->left);
        cout << "\n Name: " << node->name << ", Phone: " << node->phone << ", Email: " << node->email;
        display(node->right);
    }

    int countContacts(Contact* node) {
        if (!node) return 0;
        return 1 + countContacts(node->left) + countContacts(node->right);
    }

    void preorder(Contact* node) {
        if (!node) return;
        cout << "\n Name: " << node->name << ", Phone: " << node->phone << ", Email: " << node->email;
        preorder(node->left);
        preorder(node->right);
    }

    void inorder(Contact* node) {
        if (!node) return;
        inorder(node->left);
        cout << "\n Name: " << node->name << ", Phone: " << node->phone << ", Email: " << node->email;
        inorder(node->right);
    }

    void postorder(Contact* node) {
        if (!node) return;
        postorder(node->left);
        postorder(node->right);
        cout << "\n Name: " << node->name << ", Phone: " << node->phone << ", Email: " << node->email;
    }

public:
    ContactBST() : root(NULL) {}
    ~ContactBST() { clear(root); }

    void addContact(string name, string phone, string email) {
        root = insert(root, name, phone, email);
    }

    void deleteContact(string name) {
        root = remove(root, name);
    }
    void findContact(string name) {
        Contact* found = search(root, name);
        if (found) {
            cout << "\n Contact found - Name: " << found->name << ", Phone: " << found->phone << ", Email: " << found->email;
        } else {
            cout << "\n Contact " << name << " not found";
        }
    }

    void printAllContacts() {
        cout << "\n Contact List: ";
        if (!root) {
            cout << "\n No contacts to display.";
        } else {
            display(root);
        }
        cout << "\n";
    }

    int getTotalContacts() {
        return countContacts(root);
    }

    void showMaxContact() {
        Contact* maxContact = findMax(root);
        if (maxContact) {
            cout << "\n Max contact - Name: " << maxContact->name;
        } else {
            cout << "\n No contacts in the list.";
        }
    }

    void showMinContact() {
        Contact* minContact = findMin(root);
        if (minContact) {
            cout << "\n Min contact - Name: " << minContact->name;
        } else {
            cout << "\n No contacts in the list.";
        }
    }

    void showPreorder() { 
        cout << "\n Preorder Traversal:";
        preorder(root);
        cout << "\n";
    }

    void showInorder() {
        cout << "\n Inorder Traversal:";
        inorder(root);
        cout << "\n";
    }

    void showPostorder() {
        cout << "\n Postorder Traversal:";
        postorder(root);
        cout << "\n";
    }
};

int main() {
    ContactBST addressBook;
    string name, phone, email;
    int op;

    cout << "\n  CONTACT MANAGEMENT SYSTEM - using binary search tree in DSA";
    
    while (true) {
        cout << "\n Enter your choice: ";
        cout << "\n press 1 to Add contact into the list";
        cout << "\n press 2 to Delete contact from the list";
        cout << "\n press 3 to Search a contact in the list";
        cout << "\n press 4 to print all contacts";
        cout << "\n press 5 to Count total contacts";
        cout << "\n press 6 to Find maximum contact";
        cout << "\n press 7 to Find minimum contact";
        cout << "\n press 8 for Preorder traversal";
        cout << "\n press 9 for Inorder traversal";
        cout << "\n press 10 for Postorder traversal";
        cout << "\n press 11 to exit";
        
        cout << "\n select the operation you want to choose: ";
        cin >> op;
        cin.ignore();
        switch (op) {
            case 1:
                cout << "\n Enter name: ";
                getline(cin, name);
                cout << "\n Enter phone: ";
                getline(cin, phone);
                cout << "\n Enter email: ";
                getline(cin, email);
                addressBook.addContact(name, phone, email);
                break;
            case 2:
                cout << "\n Enter name to delete: ";
                getline(cin, name);
                addressBook.deleteContact(name);
                break;
            case 3:
                cout << "\n Enter name to search: ";
                getline(cin, name);
                addressBook.findContact(name);
                break;
            case 4:
                addressBook.printAllContacts();
                break; 
            case 5:
                cout << "\n Total contacts: " << addressBook.getTotalContacts();
                break; 
            case 6:
                addressBook.showMaxContact();
                break;  
            case 7:
                addressBook.showMinContact();
                break;
            case 8:
                addressBook.showPreorder();
                break;
            case 9:
                addressBook.showInorder();
                break;
            case 10:
                addressBook.showPostorder();
                break;
            case 11:
                return 0; 
            default:
                cout << "\n Incorrect choice, Try again";
        }
    }
    return 0;
}
