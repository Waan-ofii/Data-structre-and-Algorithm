#include <iostream>
#include <string>
using namespace std;

class Queue {
private:
    int front, rear, size, maxSize;
    string* queueArray;
public:
    
    Queue(int maxQueueSize) {
        maxSize = maxQueueSize;
        size = 0;
        front = -1;
        rear = -1;
        queueArray = new string[maxSize];
    }

    
    ~Queue() {
        delete[] queueArray;
    }

   
    bool isQueueEmpty() {
        return size == 0;
    }

    
    bool isQueueFull() {
        return size == maxSize;
    }

    
    void enqueue(const string& customerName) {
        if (isQueueFull()) {
            cout << "Queue is full, cannot enqueue more customers" << endl;
        }
        if (front == -1) front = 0;
        rear = (rear + 1) % maxSize;
        queueArray[rear] = customerName;
        size++;
        cout << "Customer added to the queue: " << customerName << endl;
    }

   
    void dequeue() {
        if (isQueueEmpty()) {
            cout << "Queue is empty, no customers to serve" << endl;
        }
        cout << "Customer " << queueArray[front] << " is being served" << endl;
        front = (front + 1) % maxSize;
        size--;
    }

    
    void displayQueue() {
        if (isQueueEmpty()) {
            cout << "No customers to display" << endl;
        }
        cout << "Current queue: ";
        for (int i = 0; i < size; i++) {
            int index = (front + i) % maxSize;
            cout << queueArray[index] << " ";
        }
        cout <<endl;
    }
};

int main() {
    Queue customerQueue(10); 
    string customerName;
    char option;

    while (true) {
        cout << "\nCustomer Service System Menu:\n";
        cout << "press 1 to Add a customer to the queue\n";
        cout << "press 2 to Serve (dequeue) a customer\n";
        cout << "press 3 to Display customers in queue\n";
        cout << "press 4 to Exit\n";
        cout << "Choose an option: ";
        cin >> option;
        cin.ignore();  

        switch (option) {
            case '1':
                if (customerQueue.isQueueFull()) {
                    cout << "The queue is full, cannot add more customers!" << endl;
                } else {
                    cout << "Enter customer name: ";
                    getline(cin, customerName);
                    customerQueue.enqueue(customerName);
                }
                break;
            case '2':
                customerQueue.dequeue();
                break;
            case '3':
                customerQueue.displayQueue();
                break;
            case '4':
                cout << "system exited" << endl;
                exit(0);
               
            default:
                cout << "Invalid option" << endl;
        }
    }

    return 0;

}
