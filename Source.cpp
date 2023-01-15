#include <iostream>
#include<iomanip>
#include <map> 
#include <string>
#include <vector>
#include<algorithm>
#include<list>
#include <cmath>
using namespace std;
class Student
{
private:
	string name;
	string surname;
	double avg;
public:
	Student()
	{
		name = "";
		surname = "";
		avg = 0;
	}

	Student(string _name, string _surname, double _avg)
	{
		name = _name;
		surname = _surname;
		avg = _avg;
	}
	friend ostream& operator<<(ostream& os, Student& st)
	{
		os << setw(10) << st.name << setw(10) << st.surname << setw(7) << st.avg;
		return os;
	}
	void SetAvg()
	{
		avg = (rand() % 12 + 1) + (rand() % 100 / 100.0);
	}
	double GetAvg()
	{
		return avg;
	}


};
bool predicat(Student st)
{
	return st.GetAvg() >= 10;

}
bool removing(Student st)
{
	return st.GetAvg() <= 7;
}

void main()
{
	srand(time(NULL));
	vector <Student> students;
	vector<Student>::iterator it;
	vector<double>marks;
	Student st1("Ivan", "Petrov", 0);
	Student st2("Stepan", "Pavlov", 0);
	Student st3("Egor", "Sinichkin", 0);
	Student st4("Anton", "Sidorov", 0);
	Student st5("Igor", "Antonov", 0);
	students = { st1, st2, st3, st4, st5 };

	cout << "The list of students:" << endl << endl;
	for (int i = 0; i < students.size(); i++)
	{
		students[i].SetAvg();
		marks.push_back(students[i].GetAvg());
		cout << students[i] << endl;
	}
	cout << endl;
	vector<Student>::iterator::difference_type it1;
	it1 = count_if(students.begin(), students.end(), predicat);

	cout << "There are " << it1 << " student(s) with really high scores" << endl << endl;

	it = remove_if(students.begin(), students.end(), removing);
	cout << "Students who can continue studying:" << endl << endl;
	for (auto iter = students.begin(); iter != it; iter++)
		cout << *iter << endl;

	cout << endl;
	vector<double>::iterator result;
	result = max_element(marks.begin(), marks.end());
	std::cout << "The best score is: " << *result << endl;

}
