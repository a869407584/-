#include <iostream>
#include<string>
using namespace std;
class Student
{
public:
	Student(int n, string na)
	{
		num = n;
		name = na;
	}
	void display()
	{
		cout << "num:" << num << endl << "name:" << name << endl;
	}
protected:
	int num;
	string name;
};
class Student1 :public Student
{
public:
	Student1(int n, string na,int n1,string na1,int a,string ad):Student(n,na),monitor(n1,na1)
	{
		age = a;
		addr = ad;
	}
	void show()
	{
		display();
		cout << "age:" << age << endl;
		cout << "addr:" << addr << endl;
	}
	void show_monitor()
	{
		cout << endl << "class monitor is:" << endl;
		monitor.display();
	}
private:
	Student monitor;
	int age;
	string addr;
};
int main()
{
	Student1 stud(1001,"wang li",1002,"li chao",19,"xian");
	
	stud.show();
	stud.show_monitor();
	while (1);
	return 0;
}