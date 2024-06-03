#include <iostream>
#include <iomanip>
#include <string>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <dos.h>
#include <fstream>

using namespace std;

class Course
{
	protected:
		static int i;
		string CourseName[5];
		string CourseID[5];
		int CreditHour[5];
		string Instructor;
		
	public:
		Course(string C_Name = "" , string C_ID = "")
		{
			for (int i=0 ; i<5 ; i++)
			{
				CourseName[i] = C_Name[i];
				CourseID[i] = C_ID[i];
				
			}
		}
		
		void getCourseInfo(string Course_Name)
		{
			int i;
			for (i=0 ; i<5 ; i++)
			{
				if (CourseName[i] == Course_Name)
				{
					break;
				}
			}
		}
		
		int viewCourseInfo()
		{
			int i = 1;
			string str;
			ifstream course("Courses.txt" , ios :: out);
			cout << " Course ID\tCourse Name" << endl << endl;
			if (course.is_open())
			{
				while(getline(course , str))
				{
					
					cout << i << ". ";
					cout << str << endl;
					i++;
				}
				int choose;
				cout << endl << endl;
				cout << "Enter choice: ";
				cin >> choose;
				return choose;
			}
			else
			{
				cout << endl << endl;
				cout << "File does not exist" << endl;
			}
		}
		void oop(int Choice)
		{
			switch (Choice)
			{
				case 1:
				{
					ifstream inAttendance("OOP Attendance.txt" , ios :: in);
					if (inAttendance)
					{
						string str;
						while (getline(inAttendance , str))
						{
							cout << str << endl;
						}
					}
					else
					cout << "Could not open file!." << endl;
				}
					break;
				case 2:
				{
					ifstream inGrades("OOP Grades.txt" , ios :: in);
					if (inGrades)
					{
						string str;
						while (getline(inGrades , str))
						{
							cout << str << endl;
						}
					}
					else
					cout << "Could not open file!." << endl;
				}
					break;
			}
			getch();
		}
		void dld(int Choice)
		{

			switch (Choice)
			{
				case 1:
				{
					ifstream inAttendance("DLD Attendance.txt" , ios :: in);
					if (inAttendance)
					{
						string str;
						while (getline(inAttendance , str))
						{
							cout << str << endl;
						}
					}
					else
					cout << "Could not open file!." << endl;
					}
					break;
				case 2:
				{
					ifstream inGrades("DLD Grades.txt" , ios :: in);
					if (inGrades)
					{
						string str;
						while (getline(inGrades , str))
						{
							cout << str << endl;
						}
					}
					else
					cout << "Could not open file!." << endl;
					}
					break;
			}
			getch();
		}
		void de(int Choice)
		{
			switch (Choice)
			{
				case 1:
				{
					ifstream inAttendance("DE Attendance.txt" , ios :: in);
					if (inAttendance)
					{
						string str;
						while (getline(inAttendance , str))
						{
							cout << str << endl;
						}
					}
					else
					cout << "Could not open file!." << endl;
				}
					break;
				case 2:
				{
					ifstream inGrades("DE Grades.txt" , ios :: in);
					if (inGrades)
					{
						string str;
						while (getline(inGrades , str))
						{
							cout << str << endl;
						}
					}
					else
					cout << "Could not open file!." << endl;
				}
					break;
			}
			getch();
		}
		void pst(int Choice)
		{
			switch (Choice)
			{
				case 1:
				{
					ifstream inAttendance("PST Attendance.txt" , ios :: in);
					if (inAttendance)
					{
						string str;
						while (getline(inAttendance , str))
						{
							cout << str << endl;
						}
					}
					else
					cout << "Could not open file!." << endl;
				}
					break;
				case 2:
				{
					ifstream inGrades("PST Grades.txt" , ios :: in);
					if (inGrades)
					{
						string str;
						while (getline(inGrades , str))
						{
							cout << str << endl;
						}
					}
					else
					cout << "Could not open file!." << endl;
				}
					break;
			}
			getch();
		}
		void cps(int Choice)
		{
			switch (Choice)
			{
				case 1:
				{
					ifstream inAttendance("CPS Attendance.txt" , ios :: in);
					if (inAttendance)
					{
						string str;
						while (getline(inAttendance , str))
						{
							cout << str << endl;
						}
					}
					else
					cout << "Could not open file!." << endl;
				}
					break;
				case 2:
				{
					ifstream inGrades("CPS Grades.txt" , ios :: in);
					if (inGrades)
					{
						string str;
						while (getline(inGrades , str))
						{
							cout << str << endl;
						}
					}
					else
					cout << "Could not open file!." << endl;
				}
					break;
			}
			getch();
		}
		void showTimetable()
		{
			cout << setw(15) << left << " " << setw(15) << "Monday" << setw(15) << "Tuesday" << setw(15) << "Wednesday" << setw(15) << "Thursday" << setw(15) << "Friday" << setw(15) << "Saturday" << endl<<endl<<endl;
		    cout << setw(15) << "1" << setw(15) << "OOP-THEORY" << setw(15) << "-" << setw(15) << "OOP-THEORY" << setw(15) << "PAK STUDIES" << setw(15) << "OFF" << setw(15) << "OFF" << endl;
		    cout << setw(15) << "08:00-09:00" << setw(15) << "E5" << setw(15) << "-" << setw(15) << "E3" << setw(15) << "A6" << setw(15) << "" << setw(15) << "" << endl<<endl;
		    cout << setw(15) << "2" << setw(15) << "DLD-THEORY" << setw(15) << "DE" << setw(15) << "DE" << setw(15) << "OOP-THEORY" << setw(15) << "OFF" << setw(15) << "OFF" << endl;
		    cout << setw(15) << "09:00-10:00" << setw(15) << "E6" << setw(15) << "R12" << setw(15) << "E3" << setw(15) << "A6" << setw(15) << "" << setw(15) << "" << endl<<endl;
		    cout << setw(15) << "3" << setw(15) << "-" << setw(15) << "CPS-THEORY" << setw(15) << "DLD-THEORY" << setw(15) << "-" << setw(15) << "OFF" << setw(15) << "OFF" << endl;
		    cout << setw(15) << "10:00-11:00" << setw(15) << "-" << setw(15) << "R12" << setw(15) << "R10" << setw(15) << "-" << setw(15) << "" << setw(15) << "" << endl<<endl;
		    cout << setw(15) << "4" << setw(15) << "PAK STUDIES" << setw(15) << "PAK STUDIES" << setw(15) << "CPS-THEORY" << setw(15) << "-" << setw(15) << "OFF" << setw(15) << "OFF" << endl;
		    cout << setw(15) << "11:00-12:00" << setw(15) << "E6" << setw(15) << "R12" << setw(15) << "R10" << setw(15) << "-" << setw(15) << "" << setw(15) << "" << endl<<endl;
		    cout << setw(15) << "5" << setw(15) << "-" << setw(15) << "DLD-LAB" << setw(15) << "-" << setw(15) << "DLD-THEORY" << setw(15) << "OFF" << setw(15) << "OFF" << endl;
		    cout << setw(15) << "12:00-01:00" << setw(15) << "-" << setw(15) << "LAB10" << setw(15) << "-" << setw(15) << "E4" << setw(15) << "" << setw(15) << "" << endl<<endl;
		    cout << setw(15) << "6" << setw(15) << "OOP-LAB" << setw(15) << "DLD-LAB" << setw(15) << "CPS-LAB" << setw(15) << "DE" << setw(15) << "OFF" << setw(15) << "OFF" << endl;
		    cout << setw(15) << "01:00-02:00" << setw(15) << "LAB12" << setw(15) << "LAB10" << setw(15) << "C22" << setw(15) << "E4" << setw(15) << "" << setw(15) << "" << endl<<endl;
		    cout << setw(15) << "7" << setw(15) << "OOP-LAB" << setw(15) << "DLD-LAB" << setw(15) << "CPS-LAB" << setw(15) << "-" << setw(15) << "OFF" << setw(15) << "OFF" << endl;
		    cout << setw(15) << "02:00-03:00" << setw(15) << "LAB12" << setw(15) << "LAB10" << setw(15) << "C22" << setw(15) << "-" << setw(15) << "" << setw(15) << "" << endl<<endl;
		    cout << setw(15) << "8" << setw(15) << "OOP-LAB" << setw(15) << "-" << setw(15) << "CPS-LAB" << setw(15) << "-" << setw(15) << "OFF" << setw(15) << "OFF" << endl;
		    cout << setw(15) << "03:00-04:00" << setw(15) << "LAB12" << setw(15) << "-" << setw(15) << "C22" << setw(15) << "-" << setw(15) << "" << setw(15) << "" << endl<<endl;
		}
};

int Course :: i = 0;
