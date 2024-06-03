#include <iostream>
#include <iomanip>
#include <string>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <dos.h>
#include "User.h"
#include "courses.h"

using namespace std;

class Student : public User , public Course
{
	string id;
	string name;
	
	public:
		void gpacalc()
{
	const float A = 4.0;
    const float A_minus = 3.67;
	const float B_plus = 3.33;
	const float B = 3.0;
	const float B_minus = 2.67;
	const float C_plus = 2.33;
	const float C = 2.0;
	const float C_minus = 1.67;
	const float D_plus = 1.33;
	const float D = 1.00;
	const float F = 0.0;
	
	string grade,course_name;
 	float credit,caltimes=0,totalcal=0,totalcredit=0,SGPA=0;
    int option;
  
 	for(;;)
    {   
	    cout<<"\nEnter course name : ";
		cin>>course_name;
		fflush(stdin);    
        cout<<"\nEnter grade: ";
        cin>>grade;
        cout<<"Enter the course credit: ";
        cin>>credit;
    
			   
		if(grade == "a" || grade == "A")
		{
			caltimes = credit * A;
		}
		else if(grade == "a-" || grade == "A-")
		{
			caltimes = credit * A_minus;
		}
		else if(grade == "b+" || grade == "B+")
		{
			caltimes = credit * B_plus;
		}
		else if(grade == "b" || grade == "B")
		{
			caltimes = credit * B;
		}
		else if(grade == "b-" || grade == "B-")
		{
			caltimes = credit * B_minus;
		}
		else if(grade == "c+" || grade == "C+")
		{
			caltimes = credit * C_plus;
		}
		else if(grade == "c" || grade == "C")
		{
			caltimes = credit * C;
		}
		else if(grade == "c-" || grade == "C-")
		{
			caltimes = credit * C_minus;
		}
		else if(grade == "d+" || grade == "D+")
		{
			caltimes = credit * D_plus;
		}
		else if(grade == "d" || grade == "D")
		{
			caltimes = credit * D;
		}
		else if(grade == "f" || grade == "F")
		{
			caltimes = credit * F;
		}	   
		else
		{
			cout<<"Invaild Input...";
		}
	
	             
          totalcredit = totalcredit + credit;
          totalcal = totalcal + caltimes;
          
		  cout<<"Do you want to enter another grade (1 - Yes, 2 - no): ";
		  cin>>option;
		  if(option == 1)
		  {
		  	continue;
		  }
		  else
		  {
		  	break;
		  }      
 	}
                
          SGPA = totalcal/totalcredit;
          cout<<"Student's GPA: "<<SGPA<<"\n";
}
	void viewresult()
	{
		cout << "Result has not been uploaded yet!" << endl; 
	}
	void getChoice(string RollNo , int choose , int choice)
	{
		switch(choice)
		{
			case 1:
				oop(RollNo , choose);
				break;
			case 2:
				dld(RollNo , choose);
				break;
			case 3:
				de(RollNo , choose);
				break;
			case 4:
				pst(RollNo , choose);
				break;
			case 5:
				cps(RollNo , choose);
				break;
		}
	}
	void display_details()
	{
		
	}
	void oop(string ID , int Choice)
		{
			switch (Choice)
			{
				case 1:
				{
					ifstream inAttendance("OOP Attendance.txt" , ios :: in);
					if (inAttendance)
					{
						string str;
						while (inAttendance >> str)
						{
							if (str == ID)
							getline(inAttendance , str);
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
						while (inGrades >> str)
						{
							if (str == ID)
							getline(inGrades , str);
						}
					}
					else
					cout << "Could not open file!." << endl;
				}
					break;
			}
			getch();
		}
		void dld(string ID , int Choice)
		{

			switch (Choice)
			{
				case 1:
				{
					ifstream inAttendance("DLD Attendance.txt" , ios :: in);
					if (inAttendance)
					{
						string str;
						while (inAttendance >> str)
						{
							if (str == ID)
							getline(inAttendance , str);
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
						while (inGrades >> str)
						{
							if (str == ID)
							getline(inGrades , str);
						}
					}
					else
					cout << "Could not open file!." << endl;
					}
					break;
			}
			getch();
		}
		void de(string ID , int Choice)
		{
			switch (Choice)
			{
				case 1:
				{
					ifstream inAttendance("DE Attendance.txt" , ios :: in);
					if (inAttendance)
					{
						string str;
						while (inAttendance >> str)
						{
							if (str == ID)
							getline(inAttendance , str);
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
						while (inGrades >> str)
						{
							if (str == ID)
							getline(inGrades , str);
						}
					}
					else
					cout << "Could not open file!." << endl;
				}
					break;
			}
			getch();
		}
		void pst(string ID , int Choice)
		{
			switch (Choice)
			{
				case 1:
				{
					ifstream inAttendance("PST Attendance.txt" , ios :: in);
					if (inAttendance)
					{
						string str;
						while (inAttendance >> str)
						{
							if (str == ID)
							getline(inAttendance , str);
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
						while (inGrades >> str)
						{
							if (str == ID)
							getline(inGrades , str);
						}
					}
					else
					cout << "Could not open file!." << endl;
				}
					break;
			}
			getch();
		}
		void cps(string ID , int Choice)
		{
			switch (Choice)
			{
				case 1:
				{
					ifstream inAttendance("CPS Attendance.txt" , ios :: in);
					if (inAttendance)
					{
						string str;
						while (inAttendance >> str)
						{
							if (str == ID)
							getline(inAttendance , str);
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
						while (inGrades >> str)
						{
							if (str == ID)
							getline(inGrades , str);
						}
					}
					else
					cout << "Could not open file!." << endl;
				}
					break;
			}
			getch();
		}
};


