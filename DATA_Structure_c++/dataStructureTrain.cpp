

#include <iostream>
using namespace std;

const int max_size = 100;

struct Booking {
     string name;
     int ticketNumber;
};

Booking queue[max_size];
int front = -1;
int rear = -1;
int size = 0;
int ticketCounter = 1001; // Starts from ticket #1001

// Enqueue: Book a ticket
void enqueue(string name) {
     if (rear == max_size - 1) {
         cout << "Queue is full! No more tickets can be booked.\n";
         return;
        
    }

     rear++;
     queue[rear].name = name;
     queue[rear].ticketNumber = ticketCounter++;
     size++;

     if (front == -1)
         front = 0;

     cout << "Ticket booked successfully for " << name
                 << ". Ticket Number: " << queue[rear].ticketNumber << endl;
}

void dequeue() {
    if (front == -1  || front > rear) {
         cout << "No customers in queue.\n";
         return;
    }

     cout << "Now serving: " << queue[front].name<< " (Ticket No: " << queue[front].ticketNumber << ")\n";
     front++;
     size--;
    if (front > rear) {
        front = rear = -1; // Reset queue
        
    }
}


void displayQueue() {
     if (front == -1  || front > rear) {
         cout << "Queue is empty.\n";
         return;
        
    }

     cout << "\n--- Current Booking Queue ---\n";
     for (int i = front; i <= rear; i++) {
         cout << i - front + 1 << ". " << queue[i].name
                             << " (Ticket No: " << queue[i].ticketNumber << ")\n";
        
    }
}

int main() {
     int choice;
     string name;

     do {
         cout << "\n==== Ticket Booking System ====\n";
         cout << "1. Book Ticket\n";
         cout << "2. Serve Customer\n";
         cout << "3. Show Booking Queue\n";
         cout << "4. Exit\n";
         cout << "Enter your choice: ";
         cin >> choice;

         switch (choice) {
         case 1:
             cout << "Enter customer name: ";
             cin >> name;
             enqueue(name);
            break;
         case 2:
             dequeue();
             break;
         case 3:
             displayQueue();
             break;
         case 4:
             cout << "Thank you! Exiting system.\n";
             break;
         default:
             cout << "Invalid choice. Try again.\n";
            
        }
        
    }
    while (choice != 4);

     return 0;
}
