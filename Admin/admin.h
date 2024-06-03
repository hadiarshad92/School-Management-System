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

class Admin : public User , public Course
{
	protected:
		string UserName;

	public:
		Admin(string fName , string lName , string pass , string userName) : User(fName , lName , pass)
		{
			UserName = userName;
		}
		string getUserName()
		{
			int flag;
			return UserName;
		}
		string getPass()
		{
			return password;
		}
		void seeStudentDetails()
		{
			
			cout << "Student Names" << endl;
			ifstream StudentName("Student.txt" , ios :: in);
			string line;
			if (StudentName.is_open())
  			{
    			while(getline(StudentName , line))
    			{
    				cout << line << endl;
    			}
    			StudentName.close();
  			}

			else 
			cout << "Unable to open file";
		}
		void seeStudentDetails(string id)
		{
			int li = 1;
			int flag = 0;
			cout << "Student Names" << endl;
			ifstream StudentName("Student.txt" , ios :: in);
			string line;
			if (StudentName.is_open())
  			{
    			while(getline(StudentName , line))
    			{
    				if(line != id)
    				{
    					li++;
					}
    				else if (line == id)
    				{
    					for (li ; li<li + 2 ; li++)
    					{
    						cout << line << endl;
						}
    					
					}
    			}
    			if(!flag)
    			cout << "Cannot locate the student!" << endl;
    			
    			StudentName.close();
  			}

			else 
			cout << "Unable to open file" << endl;
		}
		void addStudent(string rollNo , string fName , string lName)
		{
			ofstream out("Student.txt" , ios :: app);
			out << rollNo << " " << fName << " " << lName << endl;
			out.close();
		}
		void setCourseInfo()
		{
			int n;
			cout << "Enter number of courses to be registered: ";
			cin >> n;
			system("cls");
			ofstream out("Courses.txt" , ios :: app);
//			out << "ID\tCourse Name\tCredit Hours";
			for(int i=0 ; i<n ; i++)
			{
				fflush(stdin);
				cout << "Course " << i+1 << " Name: ";
				getline(cin , CourseName[i]);
				fflush(stdin);
				cout << "Course " << i+1 << " ID: ";
				getline(cin , CourseID[i]);
				cout << "Credit Hours: ";
				cin >> CreditHour[i];
				out << endl;
				out << CourseID[i] << "\t" << CourseName[i] << "\t" << CreditHour[i];
			}
			out.close();
		}
		void setTeachers()
		{
			int n = 0;
			string str;
			string TeacherName;
			string Pass;
			string Email;
			ifstream in("Courses.txt" , ios :: in);
			if(!in)
			cout << "Teachers cannot be assigned before courses." << endl;
			else
			{
				while(getline(in , str))
				n++;
				in.close();
				ifstream cfin("Courses.txt" , ios :: in);
				for (int i=0 ; i<n ; i++)
				{
					getline(cfin , str);
					cout << "For " << str << endl << endl;
					fflush(stdin);
					cout << "\t\tTeacher Name: ";
					getline(cin , TeacherName);
					fflush(stdin);
					cout << "\t\tPassword: ";
					getline(cin , Pass);
					Email = TeacherName + "@nu.edu.pk";
					ofstream out("TeacherDetails.txt" , ios :: app | ios :: binary);
					out << TeacherName << " " << Pass  << '\n';
					out << Email << '\n';
				}
			}
		}
};

class Teacher : public User , public Course
{
	string Email;
	
	public:
		void AddMarks()
	    {
    	    int option;
        	label:
	        cout << "For what you want to add marks?" << endl;
    	    cout << "1. Assignment\n2. Quiz\n3. Midterm\n4.Finalterm\n4. Others" << endl;
        	cin >> option;
//      	switch (option)
//          {
//          	case 1:
//        case 2:
//        case 3:
//            /*for (//for total students)
//            {
//                AddDetails();
//                // save marks to file
//            }*/
//            break;
//        case 4:
//            string d;
//            cout << "details: ";
//            getline(cin,d);
//            // print d on file
//            /*for (//for total students)
//            {
//                AddDetails();
//                // save marks to file
//            }*/
//        default:
//            cout << "Enter valid option!";
//            //goto label;
//            break;
		}
		void InstructorCourse(string name , int choice)
		{
			if(name == "Nida")
			oop(choice);
			else if(name == "Amir")
			dld(choice);
			else if(name == "Nadeem")
			de(choice);
			else if(name == "Tahir")
			pst(choice);
			else if(name == "Madiha")
			cps(choice);
		}
		void InstructorUpdateCourse(string name , int choice)
		{
			if(name == "Nida")
			updateoop(choice);
			else if(name == "Amir")
			updatedld(choice);
			else if(name == "Nadeem")
			updatede(choice);
			else if(name == "Tahir")
			updatepst(choice);
			else if(name == "Madiha")
			updatecps(choice);
		}
		void updateoop(int Choice)
		{
			switch (Choice)
			{
				char Attend;
				case 1:
				{
					ifstream inAttendance("OOP Attendance.txt" , ios :: in);
					ofstream UAttend("OOP Attendance temp.txt" , ios :: app);
					
					if (inAttendance)
					{
						string str;
						while (getline(inAttendance , str))
						{
							cout << str << '\t';
							cin >> Attend;
							UAttend << str << '\t' << Attend << endl;
						}
						UAttend.close();
						inAttendance.close();
						remove("OOP Attendance.txt");
						rename("OOP Attendance temp.txt" , "OOP Attendance.txt");
					}
					else
					cout << "Could not open file!." << endl;
				}
					break;
				case 2:
				{
					float marks;
					ofstream UGrade("OOP Grades temp.txt" , ios :: app);
					ifstream inGrades("OOP Grades.txt" , ios :: in);
					if (inGrades)
					{
						string str;
						while (getline(inGrades , str))
						{
							cout << str << '\t';
							cin >> marks;
							UGrade << str << '\t' << marks;
						}
						remove("OOP Grades.txt");
						UGrade.close();
						rename("OOP Grades temp.txt" , "OOP Grades.txt");
					}
					else
					cout << "Could not open file!." << endl;
				}
					break;
			}
			getch();
		}
		void updatedld(int Choice)
		{
			switch (Choice)
			{
				char Attend;
				case 1:
				{
					ifstream inAttendance("DLD Attendance.txt" , ios :: in);
					ofstream UAttend("DLD Attendance temp.txt" , ios :: app);
					
					if (inAttendance)
					{
						string str;
						while (getline(inAttendance , str))
						{
							cout << str << '\t';
							cin >> Attend;
							UAttend << str << '\t' << Attend << endl;
						}
						remove("DLD Attendance.txt");
						UAttend.close();
						rename("DLD Attendance temp.txt" , "DLD Attendance.txt");
					}
					else
					cout << "Could not open file!." << endl;
				}
					break;
				case 2:
				{
					float marks;
					ofstream UGrade("DLD Grades temp.txt" , ios :: app);
					ifstream inGrades("DLD Grades.txt" , ios :: in);
					if (inGrades)
					{
						string str;
						while (getline(inGrades , str))
						{
							cout << str << '\t';
							cin >> marks;
							UGrade << str << '\t' << marks;
						}
						remove("DLD Grades.txt");
						UGrade.close();
						rename("DLD Grades temp.txt" , "DLD Grades.txt");
					}
					else
					cout << "Could not open file!." << endl;
				}
					break;
			}
			getch();
		}
		void updatede(int Choice)
		{
			switch (Choice)
			{
				char Attend;
				case 1:
				{
					ifstream inAttendance("DE Attendance.txt" , ios :: in);
					ofstream UAttend("DE Attendance temp.txt" , ios :: app);
					
					if (inAttendance)
					{
						string str;
						while (getline(inAttendance , str))
						{
							cout << str << '\t';
							cin >> Attend;
							UAttend << str << '\t' << Attend << endl;
						}
						remove("DE Attendance.txt");
						UAttend.close();
						rename("DE Attendance temp.txt" , "DE Attendance.txt");
					}
					else
					cout << "Could not open file!." << endl;
				}
					break;
				case 2:
				{
					float marks;
					ofstream UGrade("DE Grades temp.txt" , ios :: app);
					ifstream inGrades("DE Grades.txt" , ios :: in);
					if (inGrades)
					{
						string str;
						while (getline(inGrades , str))
						{
							cout << str << '\t';
							cin >> marks;
							UGrade << str << '\t' << marks;
						}
						remove("DE Grades.txt");
						UGrade.close();
						rename("DE Grades temp.txt" , "DE Grades");
					}
					else
					cout << "Could not open file!." << endl;
				}
					break;
			}
			getch();
		}
		void updatepst(int Choice)
		{
			switch (Choice)
			{
				char Attend;
				case 1:
				{
					ifstream inAttendance("PST Attendance.txt" , ios :: in);
					ofstream UAttend("PST Attendance temp.txt" , ios :: app);
					
					if (inAttendance)
					{
						string str;
						while (getline(inAttendance , str))
						{
							cout << str << '\t';
							cin >> Attend;
							UAttend << str << '\t' << Attend << endl;
						}
						remove("PST Attendance.txt");
						UAttend.close();
						rename("PST Attendance temp.txt" , "PST Attendance");
					}
					else
					cout << "Could not open file!." << endl;
				}
					break;
				case 2:
				{
					float marks;
					ofstream UGrade("PST Grades temp.txt" , ios :: app);
					ifstream inGrades("PST Grades.txt" , ios :: in);
					if (inGrades)
					{
						string str;
						while (getline(inGrades , str))
						{
							cout << str << '\t';
							cin >> marks;
							UGrade << str << '\t' << marks;
						}
						remove("PST Grades.txt");
						UGrade.close();
						rename("PST Grades temp.txt" , "PST Grades");
					}
					else
					cout << "Could not open file!." << endl;
				}
					break;
			}
			getch();
		}
		void updatecps(int Choice)
		{
			switch (Choice)
			{
				char Attend;
				case 1:
				{
					ifstream inAttendance("CPS Attendance.txt" , ios :: in);
					ofstream UAttend("CPS Attendance temp.txt" , ios :: app);
					
					if (inAttendance)
					{
						string str;
						while (getline(inAttendance , str))
						{
							cout << str << '\t';
							cin >> Attend;
							UAttend << str << '\t' << Attend << endl;
						}
						remove("CPS Attendance.txt");
						UAttend.close();
						rename("CPS Attendance temp.txt" , "CPS Attendance");
					}
					else
					cout << "Could not open file!." << endl;
				}
					break;
				case 2:
				{
					float marks;
					ofstream UGrade("CPS Grades temp.txt" , ios :: app);
					ifstream inGrades("CPS Grades.txt" , ios :: in);
					if (inGrades)
					{
						string str;
						while (getline(inGrades , str))
						{
							cout << str << '\t';
							cin >> marks;
							UGrade << str << '\t' << marks;
						}
						remove("CPS Grades.txt");
						UGrade.close();
						rename("CPS Grades temp.txt" , "CPS Grades");
					}
					else
					cout << "Could not open file!." << endl;
				}
					break;
			}
			getch();
		}
};

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
