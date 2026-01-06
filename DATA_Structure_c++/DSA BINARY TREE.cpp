#include <iostream> 
#include <string> 
using namespace std; 
 
struct BSTNodeType { 
    int item; 
    string subject; 
    BSTNodeType *leftchild; 
    BSTNodeType *rightchild; 
}; 
 
class binarySearchTree { 
private: 
    BSTNodeType *root; 
public: 
    binarySearchTree(); 
    ~binarySearchTree(); 
    bool isTreeEmpty(); 
    bool searchBST(int); 
    void insertBST(int, string); 
    void deleteBST(int); 
    void deleteItem(BSTNodeType* &p); 
    void inorderTraversal(BSTNodeType *p); 
    void inorder(); 
    void preorderTraversal(BSTNodeType *p); 
    void preorder(); 
    void postorderTraversal(BSTNodeType *p); 
    void postorder(); 
    int heightOfTree(); 
    int height(BSTNodeType *p); 
    int findMin(); 
    int small(BSTNodeType *p); 
    int findMax(); 
    int large(BSTNodeType *p); 
    int numberofNode(); 
    int countNode(BSTNodeType *p); 
    int numberofChild(); 
    int countChild(BSTNodeType *p); 
    void destroy(BSTNodeType *p); 
}; 
 
binarySearchTree::binarySearchTree() { 
    root = NULL; 
} 
binarySearchTree::~binarySearchTree() { 
    destroy(root); 
} 
void binarySearchTree::destroy(BSTNodeType *node) { 
    if (node != NULL) { 
        destroy(node->leftchild); 
        destroy(node->rightchild); 
        delete node; 
    } 
} 
bool binarySearchTree::isTreeEmpty() { 
    return root == NULL; 
} 
 
void binarySearchTree::insertBST(int newitem, string subject) { 
    BSTNodeType *temp = new BSTNodeType; 
    BSTNodeType *current, *prevcurrent; 
 
    temp->item = newitem; 
    temp->subject = subject; 
    temp->leftchild = NULL; 
    temp->rightchild = NULL; 
 
    if (isTreeEmpty()) { 
        root = temp; 
    } else { 
        current = root; 
        while (current != NULL) { 
            prevcurrent = current; 
            if (current->item == newitem) { 
                cout << "\nDuplicate difficulty/due date not allowed.\n"; 
                return; 
            } else if (current->item > newitem) 
                current = current->leftchild; 
            else 
                current = current->rightchild; 
        } 
        if (prevcurrent->item > newitem) 
            prevcurrent->leftchild = temp; 
        else 
            prevcurrent->rightchild = temp; 
    } 
    cout << "\nStudy task added successfully!\n"; 
} 
 
bool binarySearchTree::searchBST(int key) { 
    BSTNodeType *current = root; 
    while (current != NULL) { 
        if (current->item == key) { 
            cout << "\nTask found: " << current->subject << " (Key: " << key << ")\n"; 
            return true; 
        } else if (current->item > key) 
            current = current->leftchild; 
        else 
            current = current->rightchild; 
    } 
    cout << "\nTask with key " << key << " not found.\n"; 
    return false; 
} 
 
void binarySearchTree::deleteBST(int delete_key) { 
    BSTNodeType *current = root, *prevcurrent = root; 
    bool found = false; 
    while (current != NULL && !found) { 
        if (current->item == delete_key) { 
            found = true; 
        } else { 
            prevcurrent = current; 
            if (current->item > delete_key) 
                current = current->leftchild; 
            else 
                current = current->rightchild; 
        } 
    } 
    if (found) { 
        if (current == root) 
            deleteItem(root); 
        else if (prevcurrent->item > delete_key) 
            deleteItem(prevcurrent->leftchild); 
        else 
            deleteItem(prevcurrent->rightchild); 
        cout << "\nTask deleted successfully.\n"; 
    } else { 
        cout << "\nTask not found.\n"; 
    } 
} 
 
void binarySearchTree::deleteItem(BSTNodeType* &removeNode) { 
    BSTNodeType *current, *prevcurrent, *temp; 
    if (removeNode->leftchild == NULL && removeNode->rightchild == NULL) { 
        delete removeNode; 
        removeNode = NULL; 
    } else if (removeNode->leftchild == NULL) { 
        temp = removeNode; 
        removeNode = temp->rightchild; 
        delete temp; 
    } else if (removeNode->rightchild == NULL) { 
        temp = removeNode; 
        removeNode = temp->leftchild; 
        delete temp; 
    } else { 
        current = removeNode->leftchild; 
        prevcurrent = NULL; 
        while (current->rightchild != NULL) { 
            prevcurrent = current; 
            current = current->rightchild; 
        } 
        removeNode->item = current->item; 
        removeNode->subject = current->subject; 
        if (prevcurrent == NULL) 
            removeNode->leftchild = current->leftchild; 
        else 
            prevcurrent->rightchild = current->leftchild; 
        delete current; 
    } 
} 
 
void binarySearchTree::inorder() { 
    inorderTraversal(root); 
} 
void binarySearchTree::inorderTraversal(BSTNodeType *parent) { 
    if (parent != NULL) { 
        inorderTraversal(parent->leftchild); 
        cout << parent->item << " -> " << parent->subject << endl; 
        inorderTraversal(parent->rightchild); 
    } 
} 
 
void binarySearchTree::preorder() { 
    preorderTraversal(root); 
} 
void binarySearchTree::preorderTraversal(BSTNodeType *parent) { 
    if (parent != NULL) { 
        cout << parent->item << " -> " << parent->subject << endl; 
        preorderTraversal(parent->leftchild); 
        preorderTraversal(parent->rightchild); 
    } 
} 
 
void binarySearchTree::postorder() { 
    postorderTraversal(root); 
} 
void binarySearchTree::postorderTraversal(BSTNodeType *parent) { 
    if (parent != NULL) { 
        postorderTraversal(parent->leftchild); 
        postorderTraversal(parent->rightchild); 
        cout << parent->item << " -> " << parent->subject << endl; 
    } 
} 
 
int binarySearchTree::numberofNode() { 
    return countNode(root); 
} 
int binarySearchTree::countNode(BSTNodeType *node) { 
    if (node == NULL) 
        return 0; 
    return 1 + countNode(node->leftchild) + countNode(node->rightchild); 
} 
 
int binarySearchTree::numberofChild() { 
    return countChild(root); 
} 
int binarySearchTree::countChild(BSTNodeType *node) { 
    if (node == NULL) 
        return 0; 
    if (node->leftchild == NULL && node->rightchild == NULL) 
        return 1; 
    return countChild(node->leftchild) + countChild(node->rightchild); 
} 
 
int binarySearchTree::heightOfTree() { 
    return height(root); 
} 
int binarySearchTree::height(BSTNodeType *node) { 
    if (node == NULL) 
        return 0; 
    int left = height(node->leftchild); 
    int right = height(node->rightchild); 
    return 1 + max(left, right); 
} 
 
int binarySearchTree::findMin() { 
    return small(root); 
} 
int binarySearchTree::small(BSTNodeType *node) { 
    if (node == NULL) return -1; 
    while (node->leftchild != NULL) 
        node = node->leftchild; 
    return node->item; 
} 
 
int binarySearchTree::findMax() { 
    return large(root); 
} 
int binarySearchTree::large(BSTNodeType *node) { 
    if (node == NULL) return -1; 
    while (node->rightchild != NULL) 
        node = node->rightchild; 
    return node->item; 
} 
 
 
int main() { 
    binarySearchTree planner; 
    int op; 
    do { 
        cout << "\n StudyBuddy: BST-Based Study Planner \n"; 
        cout << "1. Add Study Task (subject + difficulty/due date)\n"; 
        cout << "2. Remove Study Task by Key\n"; 
        cout << "3. Search Task by Key\n"; 
        cout << "4. Display Tasks (Inorder)\n"; 
        cout << "5. Display Tasks (Preorder)\n"; 
        cout << "6. Display Tasks (Postorder)\n"; 
        cout << "7. Show Easiest/Nearest Due Task\n"; 
        cout << "8. Show Hardest/Farthest Due Task\n"; 
        cout << "9. Show Tree Height\n"; 
        cout << "10. Total Number of Tasks\n"; 
        cout << "11. Number of Leaf Tasks\n"; 
        cout << "12. Show Group Members\n"; 
        cout << "0. Exit\n"; 
        cout << "Choose an option: "; 
        cin >> op; 
 
        int key; 
        string subject; 
 
        switch (op) { 
            case 1: 
                cout << "Enter difficulty or due date (as integer): "; 
                cin >> key; 
                cin.ignore(); 
                cout << "Enter subject name: "; 
                getline(cin, subject); 
                planner.insertBST(key, subject); 
                break; 
            case 2: 
                cout << "Enter the key to delete: "; 
                cin >> key; 
                planner.deleteBST(key); 
                break; 
            case 3: 
                cout << "Enter key to search: "; 
                cin >> key; 
                planner.searchBST(key); 
                break; 
            case 4: 
                cout << "\nInorder Traversal:\n"; 
                planner.inorder(); 
                break; 
            case 5: 
                cout << "\nPreorder Traversal:\n"; 
                planner.preorder(); 
                break; 
            case 6: 
                cout << "\nPostorder Traversal:\n"; 
                planner.postorder(); 
                break; 
            case 7: 
                cout << "Easiest/Nearest Due: " << planner.findMin() << endl; 
                break; 
            case 8: 
                cout << "Hardest/Farthest Due: " << planner.findMax() << endl; 
                break; 
            case 9: 
                cout << "Tree Height: " << planner.heightOfTree() - 1 << endl; 
                break; 
            case 10: 
                cout << "Total Tasks: " << planner.numberofNode() << endl; 
                break; 
            case 11: 
                cout << "Number of Leaf Tasks: " << planner.numberofChild() << endl; 
                break; 
            case 12: 
                cout << "\nGroup Members:\n"; 
                cout << " 1.Tsebel Tsigemeskel....RU1018/16\n"; 
                cout << " 2.Yabsira Wondimu.......RR1924/15\n"; 
                cout << " 3.Soreti Daba...........RU1933/15\n"; 
                break; 
            case 0: 
            cout << "Exiting program. Have a good time studying!\n"; 
                break; 
            default: 
            cout << "Invalid option. Please Try again.\n"; 
        } 
    } while (op != 0); 
 
    return 0; 
} 
 
