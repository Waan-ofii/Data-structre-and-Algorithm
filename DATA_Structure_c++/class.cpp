#include<iostream>
using namespace std;

class student{
string name;
string id;
int age;
string dept;
string year;

public:
student(){//default consrtuctor
name="";
id="";
age=0;
dept="";
year="";
}

student(string NAME, string ID, int AGE, string DEPT, string YEAR){//PARAMETERIZEd CONSTRUCTOR
name=NAME;
id=ID;
age=AGE;
dept=DEPT;
year=YEAR;
}

void getdata(){
cout<<"enter student information"<<endl;
cout<<"enter student name: ";
cin>>name;

cout<<"enter student id: ";
cin>>id;

cout<<"enter student age: ";
cin>>age;

cout<<"enter student dept: ";
cin>>dept;

cout<<"enter student year: ";
cin>>year;
}

void display(){
cout<<"name :"<<name<<endl;
cout<<"id :"<<id<<endl;
cout<<"age :"<<age<<endl;
cout<<"department :"<<dept<<endl;
cout<<"year :"<<year<<endl;
}

student(student &s)//copy constructor
{
name=s.name;
id=s.id;
age=s.age;
dept=s.dept;
year=s.year;
}



};

int main(){

student st1;
st1.getdata();
st1.display();
cout<<"______________________"<<endl;
student st2("sifen","Ru/0834/16",19,"software","second year");//initialize parametirized constructor
st2.display();
cout<<"______________________"<<endl;
student s=st2;//by using copy consructor copy info of st2
s.display();
return 0;
}






