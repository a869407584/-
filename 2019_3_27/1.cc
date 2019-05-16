#include<iostream>
using namespace std;
class Time
{
public:
	Time(int m = 0, int s = 0)
	{
		minute = m;
		second = s;
	}
	Time operator++();
	Time operator++(int);
	void display();
private:
	int minute;
	int second;
};
Time Time::operator++()
{
	second = second + 1;
	if (second >= 60)
	{
		second = 0;
		minute = minute + 1;
	}
	return(*this);
}
Time Time::operator++(int)
{
	Time temp(*this);
	second = second + 1;
	if (second >= 60)
	{
		second = 0;
		minute = minute + 1;
	}
	return temp;
}
void Time::display()
{
	cout << minute << ":" << second << endl;
}
int mian()
{
	Time time1(29, 58);
	Time &time2 = time1;
	Time time3;
	time1.display(); 
	time2.display();
	time3.display();
	time3 = time1++;
	time1.display();
	time2.display();
	time3.display();
	++time1;
	time1.display();
	time2.display();
	time3.display();
	system("pause");
	return 0;
}