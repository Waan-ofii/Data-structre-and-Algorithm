#include <iostream>
#include <cstring>
using namespace std;

int inc = 0;

class StudentType {
private:
    char name[30];
    char id[10];
    int age;
    char department[30];
    float gpa;

public:
    
    StudentType() {
        strcpy(name, "");
        strcpy(id, "");
        age = 0;
        strcpy(department, "");
        gpa = 0.0;
    }

   
    StudentType(const char* NAME, const char* ID, int AGE, const char* DEPT, float GPA) {
        strcpy(name, NAME);
        strcpy(id, ID);
        age = AGE;
        strcpy(department, DEPT);
        gpa = GPA;
    }

    
    StudentType(const StudentType &obj2) {
        strcpy(name, obj2.name);
        strcpy(id, obj2.id);
        age = obj2.age;
        strcpy(department, obj2.department);
        gpa = obj2.gpa;
    }

    void setData() {
        cin.ignore();
        cout << "Please enter your name: ";
        cin.getline(name, 30);
        cout << "Please enter your ID: ";
        cin.getline(id, 10);
        cout << "Please enter your age: ";
        cin >> age;
        cin.ignore();
        cout << "Please enter your department: ";
        cin.getline(department, 30);
        cout << "Please enter your GPA: ";
        cin >> gpa;
        cin.ignore();
        cout << "Data stored successfully.\n";
    }

    void print() const {
        cout << "Name: " << name << endl;
        cout << "ID: " << id << endl;
        cout << "Age: " << age << endl;
        cout << "Department: " << department << endl;
        cout << "GPA: " << gpa << endl << endl;
    }

    const char* getName() const {
        return name;
    }

    const char* getId() const {
        return id;
    }

    int getAge() const {
        return age;
    }

    const char* getDepartment() const {
        return department;
    }

    float getGpa() const {
        return gpa;
    }

    void copyFrom(const StudentType &s) {
        strcpy(name, s.name);
        strcpy(id, s.id);
        age = s.age;
        strcpy(department, s.department);
        gpa = s.gpa;
    }
};


void printData(StudentType stud[]) {
    for (int i = 0; i < inc; i++) {
        stud[i].print();
    }
}


void SortStudentByName(StudentType stud[]) {
    StudentType temp;
    bool flag;
    for (int i = 0; i < inc - 1; i++) {
        flag = false;
        for (int j = 0; j < inc - i - 1; j++) {
            if (strcmp(stud[j].getName(), stud[j + 1].getName()) > 0) {
                temp.copyFrom(stud[j]);
                stud[j].copyFrom(stud[j + 1]);
                stud[j + 1].copyFrom(temp);
                flag = true;
            }
        }
        if (!flag) break;
    }
    cout << "Data sorted by name successfully.\n";
}


void SortStudentId(StudentType stud[]) {
    int smallest;
    StudentType temp;
    for (int i = 0; i < inc - 1; i++) {
        smallest = i;
        for (int j = i + 1; j < inc; j++) {
            if (strcmp(stud[j].getId(), stud[smallest].getId()) < 0) {
                smallest = j;
            }
        }
        if (smallest != i) {
            temp.copyFrom(stud[smallest]);
            stud[smallest].copyFrom(stud[i]);
            stud[i].copyFrom(temp);
        }
    }
    cout << "Data sorted by ID successfully.\n";
}


void searchStudentById(StudentType stud[], const char key[]) {
    bool flag = false;
    for (int i = 0; i < inc; i++) {
        if (strcmp(stud[i].getId(), key) == 0) {
            cout << "Data found:\n";
            stud[i].print();
            flag = true;
            break;
        }
    }
    if (!flag) {
        cout << "Student not found.\n";
    }
}


void deleteStudentById(StudentType stud[], const char key[]) {
    int index = -1;
    for (int i = 0; i < inc; i++) {
        if (strcmp(stud[i].getId(), key) == 0) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        cout << "Student not found.\n";
    } else {
        for (int i = index; i < inc - 1; i++) {
            stud[i].copyFrom(stud[i + 1]);
        }
        inc--;
        cout << "Student deleted successfully.\n";
    }
}


int main() {
    int choice;
    StudentType stud[10];

    while (true) {
        cout << "\n\nSIMPLE SORTING AND SEARCHING ALGORITHMS\n";
        cout << "1: Insert student information\n";
        cout << "2: Print student information\n";
        cout << "3: Sort students by name\n";
        cout << "4: Sort students by ID\n";
        cout << "5: Search student by ID\n";
        cout << "6: Delete student by ID\n";
        cout << "7: Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                if (inc < 10) {
                    stud[inc].setData();
                    inc++;
                } else {
                    cout << "Student list is full.\n";
                }
                break;
            case 2:
                printData(stud);
                break;
            case 3:
                SortStudentByName(stud);
                break;
            case 4:
                SortStudentId(stud);
                break;
            case 5: {
                char k[10];
                cout << "Enter the ID of the student to search: ";
                cin >> k;
                searchStudentById(stud, k);
                break;
            }
            case 6: {
                char k[10];
                cout << "Enter the ID of the student to delete: ";
                cin >> k;
                deleteStudentById(stud, k);
                break;
            }
            case 7:
                cout << "Exiting program...\n";
                return 0;
            default:
                cout << "Invalid choice! Try again.\n";
        }
    }

    return 0;
}
