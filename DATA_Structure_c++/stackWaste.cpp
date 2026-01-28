#include <iostream>
#include <stack>
using namespace std;

struct Waste {
    string type;
    string material;
    string process;
};
void displayStack(stack<Waste> recycleStack) {
    if (recycleStack.empty()) {
        cout << "No waste items available for recycling!" << endl;
        return;
    }
    cout << "\n--- Recycling Waste Items ---" << endl;
    stack<Waste> tempStack = recycleStack;
    while (!tempStack.empty()) {
        Waste item = tempStack.top();
        cout << "Type: " << item.type << ", Material: " << item.material
             << ", Process: " << item.process << endl;
        tempStack.pop();
    }
}
int main() {
    stack<Waste> recycleStack;
    int choice;

    do {
        cout << "\n--- Recycling System ---" << endl;
        cout << "1. Add waste item" << endl;
        cout << "2. Process last collected waste item" << endl;
        cout << "3. View all waste items" << endl;
        cout << "4. Exit\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                Waste newItem;
                cout << "Enter waste type (Plastic, Metal, Paper, etc.): ";
                cin >> newItem.type;
                cout << "Enter waste material (Bottle, Can, Newspaper, etc.): ";
                cin >> newItem.material;
                cout << "Enter recycling process (Melt, Shred, Compress, etc.): ";
                cin >> newItem.process;
                recycleStack.push(newItem);
                cout << "Waste item added to recycling system!" << endl;
                break;
            }
            case 2:
                if (!recycleStack.empty()) {
                    Waste processedItem = recycleStack.top();
                    cout << "Processing waste item: Type - " << processedItem.type
                         << ", Material - " << processedItem.material
                         << ", Process - " << processedItem.process << endl;
                    recycleStack.pop();
                } else {
                    cout << "No waste items available for recycling!" << endl;
                }
                break;
            case 3:
                displayStack(recycleStack);
                break;
            case 4:
                cout << "Exiting recycling system..." << endl;
                break;
            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    } while (choice != 4);

    return 0;
}
