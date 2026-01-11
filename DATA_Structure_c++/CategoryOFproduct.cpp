#include <iostream>
#include <string>
using namespace std;

struct ProductNode {
    int id;
    string name;
    double price;
    ProductNode* left;
    ProductNode* right;
};

class ProductOrganizer {
private:
    ProductNode* root;
    void destroyTree(ProductNode* node);
    void insertHelper(ProductNode* &node, int id, string name, double price);
    ProductNode* searchHelper(ProductNode* node, int id);
    void inOrderTraversal(ProductNode* node);
    void preOrderTraversal(ProductNode* node);
    void postOrderTraversal(ProductNode* node);
    ProductNode* findMin(ProductNode* node);
    ProductNode* removeHelper(ProductNode* &node, int id);
    int countProducts(ProductNode* node);
    int countCategories(ProductNode* node); // Counts non-leaf nodes
    int treeHeight(ProductNode* node);

public:
    ProductOrganizer();
    ~ProductOrganizer();

    void addProduct(int id, string name, double price);
    bool searchProduct(int id);
    void removeProduct(int id);
    void displayProducts();
    void displayCategories();
    void showProductDetails(int id);
    int totalProducts();
    int totalCategories();
    int getTreeHeight();
    void updateProduct(int id, string newName, double newPrice);
};

ProductOrganizer::ProductOrganizer() {
    root = nullptr;
}

ProductOrganizer::~ProductOrganizer() {
    destroyTree(root);
}

void ProductOrganizer::destroyTree(ProductNode* node) {
    if (node != nullptr) {
        destroyTree(node->left);
        destroyTree(node->right);
        delete node;
    }
}

void ProductOrganizer::addProduct(int id, string name, double price) {
    insertHelper(root, id, name, price);
}

void ProductOrganizer::insertHelper(ProductNode* &node, int id, string name, double price) {
    if (node == nullptr) {
        node = new ProductNode;
        node->id = id;
        node->name = name;
        node->price = price;
        node->left = nullptr;
        node->right = nullptr;
        cout << "Product added successfully!\n";
    } else if (id < node->id) {
        insertHelper(node->left, id, name, price);
    } else if (id > node->id) {
        insertHelper(node->right, id, name, price);
    } else {
        cout << "Product with ID " << id << " already exists!\n";
    }
}

bool ProductOrganizer::searchProduct(int id) {
    return searchHelper(root, id) != nullptr;
}

ProductNode* ProductOrganizer::searchHelper(ProductNode* node, int id) {
    if (node == nullptr) {
        return nullptr;
    } else if (id < node->id) {
        return searchHelper(node->left, id);
    } else if (id > node->id) {
        return searchHelper(node->right, id);
    } else {
        return node;
    }
}

void ProductOrganizer::removeProduct(int id) {
    root = removeHelper(root, id);
}

ProductNode* ProductOrganizer::removeHelper(ProductNode* &node, int id) {
    if (node == nullptr) {
        cout << "Product not found!\n";
        return nullptr;
    }

    if (id < node->id) {
        node->left = removeHelper(node->left, id);
    } else if (id > node->id) {
        node->right = removeHelper(node->right, id);
    } else {
        if (node->left == nullptr) {
            ProductNode* temp = node->right;
            delete node;
            cout << "Product removed successfully!\n";
            return temp;
        } else if (node->right == nullptr) {
            ProductNode* temp = node->left;
            delete node;
            cout << "Product removed successfully!\n";
            return temp;
        }
        
        ProductNode* temp = findMin(node->right);
        node->id = temp->id;
        node->name = temp->name;
        node->price = temp->price;
        node->right = removeHelper(node->right, temp->id);
    }
    return node;
}

ProductNode* ProductOrganizer::findMin(ProductNode* node) {
    while (node->left != nullptr) {
        node = node->left;
    }
    return node;
}

void ProductOrganizer::displayProducts() {
    cout << "\nProducts List (In-Order):\n";
    inOrderTraversal(root);
}

void ProductOrganizer::inOrderTraversal(ProductNode* node) {
    if (node != nullptr) {
        inOrderTraversal(node->left);
        cout << "ID: " << node->id << ", Name: " << node->name 
             << ", Price: $" << node->price << endl;
        inOrderTraversal(node->right);
    }
}

void ProductOrganizer::displayCategories() {
    cout << "\nCategories Structure (Pre-Order):\n";
    preOrderTraversal(root);
}

void ProductOrganizer::preOrderTraversal(ProductNode* node) {
    if (node != nullptr) {
        cout << "Category ID: " << node->id << " (" << node->name << ")\n";
        preOrderTraversal(node->left);
        preOrderTraversal(node->right);
    }
}

void ProductOrganizer::showProductDetails(int id) {
    ProductNode* product = searchHelper(root, id);
    if (product != nullptr) {
        cout << "\nProduct Details:\n";
        cout << "ID: " << product->id << endl;
        cout << "Name: " << product->name << endl;
        cout << "Price: $" << product->price << endl;
    } else {
        cout << "Product not found!\n";
    }
}

int ProductOrganizer::totalProducts() {
    return countProducts(root);
}

int ProductOrganizer::countProducts(ProductNode* node) {
    if (node == nullptr) {
        return 0;
    }
    return 1 + countProducts(node->left) + countProducts(node->right);
}

int ProductOrganizer::totalCategories() {
    return countCategories(root);
}

int ProductOrganizer::countCategories(ProductNode* node) {
    if (node == nullptr || (node->left == nullptr && node->right == nullptr)) {
        return 0;
    }
    return 1 + countCategories(node->left) + countCategories(node->right);
}

int ProductOrganizer::getTreeHeight() {
    return treeHeight(root);
}

int ProductOrganizer::treeHeight(ProductNode* node) {
    if (node == nullptr) {
        return 0;
    }
    int leftHeight = treeHeight(node->left);
    int rightHeight = treeHeight(node->right);
    return 1 + max(leftHeight, rightHeight);
}

void ProductOrganizer::updateProduct(int id, string newName, double newPrice) {
    ProductNode* product = searchHelper(root, id);
    if (product != nullptr) {
        product->name = newName;
        product->price = newPrice;
        cout << "Product updated successfully!\n";
    } else {
        cout << "Product not found!\n";
    }
}

int main() {
    ProductOrganizer organizer;
    int choice, id;
    string name;
    double price;

    do {
        cout << "\n===== Product Category Organizer =====\n";
        cout << "1. Add Product\n";
        cout << "2. Remove Product\n";
        cout << "3. Search Product\n";
        cout << "4. Display All Products\n";
        cout << "5. Display Category Structure\n";
        cout << "6. Show Product Details\n";
        cout << "7. Update Product\n";
        cout << "8. Total Products Count\n";
        cout << "9. Total Categories Count\n";
        cout << "10. Tree Height\n";
        
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter Product ID: ";
                cin >> id;
                cout << "Enter Product Name: ";
                cin.ignore();
                getline(cin, name);
                cout << "Enter Product Price: ";
                cin >> price;
                organizer.addProduct(id, name, price);
                break;
            case 2:
                cout << "Enter Product ID to remove: ";
                cin >> id;
                organizer.removeProduct(id);
                break;
            case 3:
                cout << "Enter Product ID to search: ";
                cin >> id;
                if (organizer.searchProduct(id)) {
                    cout << "Product found in the system!\n";
                } else {
                    cout << "Product not found!\n";
                }
                break;
            case 4:
                organizer.displayProducts();
                break;
            case 5:
                organizer.displayCategories();
                break;
            case 6:
                cout << "Enter Product ID to view details: ";
                cin >> id;
                organizer.showProductDetails(id);
                break;
            case 7:
                cout << "Enter Product ID to update: ";
                cin >> id;
                cout << "Enter New Name: ";
                cin.ignore();
                getline(cin, name);
                cout << "Enter New Price: ";
                cin >> price;
                organizer.updateProduct(id, name, price);
                break;
            case 8:
                cout << "Total Products: " << organizer.totalProducts() << endl;
                break;
            case 9:
                cout << "Total Categories: " << organizer.totalCategories() << endl;
                break;
            case 10:
                cout << "Tree Height: " << organizer.getTreeHeight() << endl;
                break;
            
            case 0:
                cout << "Exiting system...\n";
                break;
            default:
                cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != 0);

    return 0;
}
