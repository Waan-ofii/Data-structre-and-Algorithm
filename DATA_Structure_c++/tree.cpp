#include <iostream>
#include <string>
using namespace std;
struct StudentRecord {
    int studentID;
    string name;
    float gpa;

    StudentRecord() : studentID(0), name(""), gpa(0.0f) {}
    StudentRecord(int id, string n, float gp) : studentID(id), name(n), gpa(gp) {}
};

struct bstnodetype {
    StudentRecord record;
    bstnodetype *leftchild;
    bstnodetype *rightchild;
};

class binarysearchtreetype {
private:
    bstnodetype *root;

    void destroy(bstnodetype *node);
    void preordertraversal(bstnodetype *node);
    void inordertraversal(bstnodetype *node);
    void postordertraversal(bstnodetype *node);

public:
    binarysearchtreetype();
    ~binarysearchtreetype();

    void insertItembst(StudentRecord);
    void deleteitembst(int);
    void deletenode(bstnodetype*&);
    bool searchItembst(int);
    bool istreeEmpty();

    void inorder();
    void preorder();
    void postorder();

    int countNodes();
    int countNodesHelper(bstnodetype*);

    int treeHeight();
    int treeHeightHelper(bstnodetype*);

    StudentRecord findMin();
    StudentRecord findMax();
};

// Constructor
binarysearchtreetype::binarysearchtreetype() {
    root = NULL;
}

// Destructor
binarysearchtreetype::~binarysearchtreetype() {
    destroy(root);
}

void binarysearchtreetype::destroy(bstnodetype *node) {
    if (node != NULL) {
        destroy(node->leftchild);
        destroy(node->rightchild);
        delete node;
    }
}

bool binarysearchtreetype::istreeEmpty() {
    return root == NULL;
}

// Insert Item
void binarysearchtreetype::insertItembst(StudentRecord newRecord) {
    bstnodetype *temp = new bstnodetype;
    temp->record = newRecord;
    temp->leftchild = NULL;
    temp->rightchild = NULL;

    if (root == NULL) {
        root = temp;
        cout << "\nStudent inserted successfully.";
    } else {
        bstnodetype *current = root;
        bstnodetype *prevcurrent = NULL;

        while (current != NULL) {
            prevcurrent = current;
            if (current->record.studentID == newRecord.studentID) {
                cout << "\nStudent ID already exists.";
                delete temp; // Avoid memory leak
                return;
            } else if (current->record.studentID > newRecord.studentID)
                current = current->leftchild;
            else
                current = current->rightchild;
        }

        if (prevcurrent->record.studentID > newRecord.studentID)
            prevcurrent->leftchild = temp;
        else
            prevcurrent->rightchild = temp;

        cout << "\nStudent inserted successfully.";
    }
}

// Delete Item
void binarysearchtreetype::deleteitembst(int deletekey) {
    bstnodetype *current = root;
    bstnodetype *prevcurrent = root;
    bool found = false;

    if (istreeEmpty()) {
        cout << "\nTree is empty.";
        return;
    }

    while (current != NULL && !found) {
        if (current->record.studentID == deletekey) {
            found = true;
        } else {
            prevcurrent = current;
            if (current->record.studentID > deletekey)
                current = current->leftchild;
            else
                current = current->rightchild;
        }
    }

    if (found) {
        if (current == root)
            deletenode(root);
        else if (prevcurrent->record.studentID > deletekey)
            deletenode(prevcurrent->leftchild);
        else
            deletenode(prevcurrent->rightchild);
        cout << "\nStudent deleted successfully.";
    } else {
        cout << "\nStudent not found.";
    }
}

void binarysearchtreetype::deletenode(bstnodetype *&removenode) {
    bstnodetype *temp = removenode;

    if (removenode->leftchild == NULL && removenode->rightchild == NULL) {
        removenode = NULL;
        delete temp;
    } else if (removenode->leftchild == NULL) {
        removenode = temp->rightchild;
        delete temp;
    } else if (removenode->rightchild == NULL) {
        removenode = temp->leftchild;
        delete temp;
    } else {
        bstnodetype *current = removenode->leftchild;
        bstnodetype *prevcurrent = removenode;

        while (current->rightchild != NULL) {
            prevcurrent = current;
            current = current->rightchild;
        }

        removenode->record = current->record;
        if (prevcurrent == removenode)
            prevcurrent->leftchild = current->leftchild;
        else
            prevcurrent->rightchild = current->leftchild;

        delete current;
    }
}

// Search Item
bool binarysearchtreetype::searchItembst(int searchkey) {
    if (istreeEmpty()) {
        cout << "\nTree is empty.";
        return false;
    }

    bstnodetype *current = root;
    while (current != NULL) {
        if (current->record.studentID == searchkey)
            return true;
        else if (current->record.studentID > searchkey)
            current = current->leftchild;
        else
            current = current->rightchild;
    }
    return false;
}

// Traversals
void binarysearchtreetype::inorder() {
    cout << "\nIn-order Traversal:\n";
    inordertraversal(root);
}
void binarysearchtreetype::inordertraversal(bstnodetype *node) {
    if (node != NULL) {
        inordertraversal(node->leftchild);
        cout << "ID: " << node->record.studentID
             << ", Name: " << node->record.name
             << ", GPA: " << node->record.gpa << endl;
        inordertraversal(node->rightchild);
    }
}

void binarysearchtreetype::preorder() {
    cout << "\nPre-order Traversal:\n";
    preordertraversal(root);
}
void binarysearchtreetype::preordertraversal(bstnodetype *node) {
    if (node != NULL) {
        cout << "ID: " << node->record.studentID
             << ", Name: " << node->record.name
             << ", GPA: " << node->record.gpa << endl;
        preordertraversal(node->leftchild);
        preordertraversal(node->rightchild);
    }
}

void binarysearchtreetype::postorder() {
    cout << "\nPost-order Traversal:\n";
    postordertraversal(root);
}
void binarysearchtreetype::postordertraversal(bstnodetype *node) {
    if (node != NULL) {
        postordertraversal(node->leftchild);
        postordertraversal(node->rightchild);
        cout << "ID: " << node->record.studentID
             << ", Name: " << node->record.name
             << ", GPA: " << node->record.gpa << endl;
    }
}

// Count Nodes
int binarysearchtreetype::countNodes() {
    return countNodesHelper(root);
}
int binarysearchtreetype::countNodesHelper(bstnodetype *node) {
    if (!node) return 0;
    return 1 + countNodesHelper(node->leftchild) + countNodesHelper(node->rightchild);
}

// Tree Height
int binarysearchtreetype::treeHeight() {
    return treeHeightHelper(root);
}
int binarysearchtreetype::treeHeightHelper(bstnodetype *node) {
    if (!node) return -1;
    int left = treeHeightHelper(node->leftchild);
    int right = treeHeightHelper(node->rightchild);
    return max(left, right) + 1;
}

// Find min&max
StudentRecord binarysearchtreetype::findMin() {
    bstnodetype *current = root;
    while (current && current->leftchild)
        current = current->leftchild;
    return current ? current->record : StudentRecord();
}
StudentRecord binarysearchtreetype::findMax() {
    bstnodetype *current = root;
    while (current && current->rightchild)
        current = current->rightchild;
    return current ? current->record : StudentRecord();
}

// Main Menu
int main() {
    binarysearchtreetype obj;
    int choice;

menu:
    cout << "\n--- STUDENT RECORD MANAGEMENT SYSTEM ---\n";
    cout << "1. Insert Student\n";
    cout << "2. Delete Student\n";
    cout << "3. Search Student\n";
    cout << "4. In-order Traversal\n";
    cout << "5. Pre-order Traversal\n";
    cout << "6. Post-order Traversal\n";
    cout << "7. Find Minimum ID\n";
    cout << "8. Find Maximum ID\n";
    cout << "9. Tree Height\n";
    cout << "10. Total Number of Students\n";
    cout << "0. Exit\n";
    cout << "Enter your choice: ";
    cin >> choice;

    switch (choice) {
        case 1: {
            int id;
            string name;
            float gpa;
            cout << "Enter Student ID: ";
            cin >> id;
            cout << "Enter Name: ";
            cin.ignore();
            getline(cin, name);
            cout << "Enter GPA: ";
            cin >> gpa;
            obj.insertItembst(StudentRecord(id, name, gpa));
            break;
        }
        case 2: {
            int id;
            cout << "Enter Student ID to delete: ";
            cin >> id;
            obj.deleteitembst(id);
            break;
        }
        case 3: {
            int id;
            cout << "Enter Student ID to search: ";
            cin >> id;
            if (obj.searchItembst(id))
                cout << "Student found!";
            else
                cout << "Student NOT found!";
            break;
        }
        case 4: obj.inorder(); break;
        case 5: obj.preorder(); break;
        case 6: obj.postorder(); break;
        case 7: {
            StudentRecord minRec = obj.findMin();
            if (minRec.studentID != 0)
                cout << "Minimum ID Student: " << minRec.name << " (ID: " << minRec.studentID << ")";
            else
                cout << "No students in the system.";
            break;
        }
        case 8: {
            StudentRecord maxRec = obj.findMax();
            if (maxRec.studentID != 0)
                cout << "Maximum ID Student: " << maxRec.name << " (ID: " << maxRec.studentID << ")";
            else
                cout << "No students in the system.";
            break;
        }
        case 9:
            cout << "Tree Height: " << obj.treeHeight();
            break;
        case 10:
            cout << "Total Students: " << obj.countNodes();
            break;
        case 0:
            exit(0);
        default:
            cout << "Invalid option. Try again.";
    }

    cout << "\nPress any key to continue...";
    cin.ignore();
    cin.get();
    goto menu;

    return 0;
}

