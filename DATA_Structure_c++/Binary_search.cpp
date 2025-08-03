#include<iostream>
using namespace std;


int Binary_search(int list[],int n,int key){
    int left = 0;
    int right = n-1;
    while(left <= right){
        int mid = (left + right)/2;

        if(key == list[mid]){
            return mid;
        }else if(key < list[mid]){
            right = mid - 1;
        }else{
            left = mid + 1;
        }
         }
    return -1;
}

    

int main(){
    int key;
    int list[] = {10,15,20,25,30,40,50,70,100};
    int n = sizeof(list) / sizeof(list[0]);
    cout<<" please enter the key you looking for : ";
    cin>>key;
    int result = Binary_search(list, n, key);

    if (result != -1) {
        cout << "Key " << key << " found at index: " << result << endl;
    } else {
        cout << "Key " << key << " not found in the list." << endl;
    }
   
   return 0;
}
/*
#include<iostream>
using namespace std;

int Binary_search(int list[], int n, int key) {
    int left = 0;
    int right = n - 1;

    while (left <= right) {
        int mid = (left + right) / 2;

        if (key == list[mid]) {
            return mid;
        } else if (key < list[mid]) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    return -1;
}

int main() {
    int list[] = {10, 15, 20, 25, 30, 40, 50, 70, 100}; // Sorted array
    int n = sizeof(list) / sizeof(list[0]); // Safer way to get size
    int key;

    cout << "Please enter the key you are looking for: ";
    cin >> key;

    int result = Binary_search(list, n, key);

    if (result != -1) {
        cout << "Key " << key << " found at index: " << result << endl;
    } else {
        cout << "Key " << key << " not found in the list." << endl;
    }

    return 0;
}*/
