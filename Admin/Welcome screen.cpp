#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include "admin.h"
//#include "teacher.h"
using namespace std;

void showStudentDetails(Admin obj);
void AdminLoginScreen();
void TeacherLoginScreen();
void StudentLoginScreen();
void AdminMainMenu(Admin obj);
void addingStudent(Admin obj);
void CourseDetails(Admin obj);
void SeeCourse(Admin obj , int choose);
void TeacherEntry(Admin obj);
void TeacherMainMenu(Teacher obj , string);
void StudentMainMenu(Student obj , string);
void StudentSelect(Student obj , string RollNo , int choose);

void WelcomeScreen()
{
	cout << "\n\n\n\n\n\n\n\t\t\t\t#########################################";
	cout << "\n\t\t\t\t#\t\t WELCOME TO\t\t#";
	cout << "\n\t\t\t\t#   RMH UNIVERSITY MANAGEMENT SYSTEM    #";
	cout << "\n\t\t\t\t#########################################";
	cout << "\n\n\n\n\n Press any key to continue......" << endl;
	getch();
	system("cls");
}

void Title()//function for title screen
{
	cout << "\n\n\t\t----------------------------------------------------------------------------------";
	cout << "\n\t\t\t\t       RMH UNIVERSITY         ";
	cout << "\n\t\t----------------------------------------------------------------------------------" << endl;
}

void start()
{
	system("cls");
	Title();
	int x;
	do
	{   
	    cout << "\n\n1. Admin \n\n2. Teacher \n\n3. Student: "<< endl;
		cin >> x;
		
		if(x == 1 || x == 2 || x == 3)
		{
			if(x == 1)
			{
			system("cls");
			AdminLoginScreen();
			}
	
			else if(x == 2)
			{
				system("cls");
				TeacherLoginScreen();
			}
			else if(x == 3)
			{
				system("cls");
				StudentLoginScreen();
			}
			
		}
		
		else
		{
		cout << "\nENTER A CORRECT NUMBER";
		system("cls");
		}
	}
	while(1);
	
}

void AdminLoginScreen()
{
	Title();
	int e = 0;
	string Username;
	string Password;
	Admin Obj("Muhammad" , "Razi" , "razi123" , "RMH");
	do
	{
		cout << "\n\n\n\n\t\t\t\tEnter your Username and Password";
		cout << "\n\n\n\t\t\t\t\tUSERNAME:";
		cin >> Username;
		cout << "\n\n\t\t\t\t\tPASSWORD:";
		cin >> Password;
	
		if (Username == Obj.getUserName() && Password == Obj.getPass())
		{
			cout << "\n\n\n\t\t\t\t\t...Login Successfull...";
			getch();
			AdminMainMenu(Obj);
			break;
		}
		
		else
		{
			cout << "\n\t\t\tUserName or Password is incorrect:( Try Again :)";
			e++;
			getch();
		}
	}
	while(e <= 2);
	
	if(e > 2)
	{
		cout << "You have cross the limit. You cannot login. :( :(";
		getch();
    	exit(1);
	}
	
	system("cls");
}

void TeacherLoginScreen()
{
	Title();
	int e = 0;
	string Username;
	string Password;
	string line;
	Teacher obj;
	ifstream tdin("TeacherDetails.txt" , ios :: in);
	do
	{
		cout << "\n\n\n\n\t\t\t\tEnter your Username and Password";
		cout << "\n\n\n\t\t\t\t\tUSERNAME:";
		cin >> Username;
		Username[0] = toupper(Username[0]);
		cout << "\n\n\t\t\t\t\tPASSWORD:";
		cin >> Password;
	
		while(getline(tdin , line))
		{
			if (line == Username + " " + Password)
			TeacherMainMenu(obj , Username);
		}
		e++;
	}
	while(e <= 2);
	
	if(e > 2)
	{
		cout << "You have cross the limit. You cannot login. :( :(";
		getch();
    	exit(1);
	}
	
	system("cls");
}

void StudentLoginScreen()
{
	Title();
	int e = 0;
	string Username;
	string Password;
	string line;
	Student obj;
	ifstream tdin("Student Details.txt" , ios :: in);
	do
	{
		cout << "\n\n\n\n\t\t\t\tEnter your Username and Password";
		cout << "\n\n\n\t\t\t\t\tRoll Number:";
		cin >> Username;
		Username[0] = toupper(Username[0]);
		cout << "\n\n\t\t\t\t\tPASSWORD:";
		cin >> Password;
	
		while(getline(tdin , line))
		{
			if (line == Username + " " + Password)
			StudentMainMenu(obj , Username);
		}
		e++;
	}
	while(e <= 2);
	
	if(e > 2)
	{
		cout << "You have cross the limit. You cannot login. :( :(";
		getch();
    	exit(1);
	}
	
	system("cls");
}

void AdminMainMenu(Admin obj)
{

	system("cls");
	int choose;
	Title();
	cout << "\n\n\n\n\n\t\t\t\t1. Student Details" << endl;
	cout << "\n\t\t\t\t2. Add A Student" << endl;
	cout << "\n\t\t\t\t3. Course Details" << endl;
	cout << "\n\t\t\t\t4. Assign Teachers" << endl;
	cout << "\n\t\t\t\t5. Exit" << endl;
    cout << "\n\n\n \n\t\t\t\tChoose from 1 to 5:";
	cin >> choose;
	switch (choose)
	{
		case 1:
			showStudentDetails(obj);
			break;
		case 2:
			addingStudent(obj);
			break;
		case 3:
			CourseDetails(obj);
			break;
		case 4:
			TeacherEntry(obj);
			break;
		case 5:
			start();
		default:
			break;
	}
	AdminMainMenu(obj);
}

void TeacherMainMenu(Teacher obj , string name)
{
	repeat:
	system("cls");
	
	int choose;
	Title();
	cout << "\n\n\n\n\n\t\t\t\t1. See Attendance" << endl;
	cout << "\n\t\t\t\t2. See Grades" << endl;
	cout << "\n\t\t\t\t3. Update Attendance" << endl;
	cout << "\n\t\t\t\t4. Update Grades" << endl;
	cout << "\n\t\t\t\t5. TimeTable" << endl;
	cout << "\n\t\t\t\t6. Exit" << endl;
	cout << "\n\n\n \n\t\t\t\tChoose from 1 to 6:";
	cin >> choose;
	system("cls");
//	obj.InstructorCourse(name , choose);
	switch(choose)
	{
		case 1:
			obj.InstructorCourse(name , choose);
			goto repeat;
			break;
		case 2:
			obj.InstructorCourse(name , choose);
			goto repeat;
			break;
		case 3:
			obj.InstructorUpdateCourse(name , choose-2);
			goto repeat;
			break;
		case 4:
			obj.InstructorUpdateCourse(name , choose-2);
			goto repeat;
			break;
		case 5:
			obj.showTimetable();
			getch();
			goto repeat;
		case 6:
			start();
	}
}

void StudentMainMenu(Student obj , string RollNo)
{
	system("cls");
	
	int choose;
	Title();
	cout << "\n\n\n\n\n\t\t\t\t1. See Attendance" << endl;
	cout << "\n\t\t\t\t2. See Grades" << endl;
	cout << "\n\t\t\t\t3. View Result" << endl;
	cout << "\n\t\t\t\t4. GPA Calculator" << endl;
	cout << "\n\t\t\t\t5. TimeTable" << endl;
	cout << "\n\t\t\t\t5. See Instructor Information" << endl;
	cout << "\n\t\t\t\t6. Exit" << endl;
	cout << "\n\n\n \n\t\t\t\tChoose from 1 to 6:";
	cin >> choose;
	switch(choose)
	{
		case 1:
			StudentSelect(obj , RollNo , choose);
			break;
		case 2:
			StudentSelect(obj , RollNo , choose);
			break;
		case 3:
			obj.viewresult();
		case 4:
			obj.gpacalc();
			break;
		case 5:
			obj.showTimetable();
			break;
//		case 6:
//			obj
	}
}

void StudentSelect(Student obj , string RollNo , int choose)
{
	int i = 1 , choice;
	string str;
	ifstream in("Courses.txt" , ios :: in);
	while(getline(in , str))
	{
		cout << i << ". " << str << endl;
	}
	cout << "Enter your choice: ";
	cin >> choice;
	obj.getChoice(RollNo , choose , choice);
}
void showStudentDetails(Admin obj)
{
	system("cls");
	string name , id;
	int choose;
	Title();
	cout << "\n\n\n\n\n\t\t\t\t1. All Student Details" << endl;
	cout << "\n\t\t\t\t2. Specific Student Student" << endl;
	cout << "\n\t\t\t\t3. Back to Main Menu" << endl;
	cin >> choose;
	cout << endl <<endl << endl;
	switch(choose)
	{
		case 1:
			system("cls");
			obj.seeStudentDetails();
			getch();
			break;
		case 2:
			cout << "Enter Student ID: ";
			getline(cin , id);
			cout << "Enter Student Name(as per registration): ";
			getline(cin , name);
			obj.seeStudentDetails(id);
			getch();
			break;
		case 3:
			AdminMainMenu(obj);
	}
}

void addingStudent(Admin obj)
{
	Title();
	string RollNo , f_name , l_name , contact;
	cout << endl << endl << endl;
	cout << "Roll Number: ";
	cin >> RollNo;
	cout << "Full Name: ";
	cin >> f_name;
	cout << "Last Name: ";
	cin >> l_name;
//	cout << "Contact: ";
//	cin >> contact;
	
	obj.addStudent(RollNo , f_name , l_name);
	getch();
	AdminMainMenu(obj);
}

void CourseDetails(Admin obj)
{
	int course;
	system("cls");
	string name , id;
	int choose;
	Title();
	cout << "\n\n\n\n\n\t\t\t\t1. Register Courses" << endl;
	cout << "\n\t\t\t\t2. View Course Information" << endl;
	cout << "\n\t\t\t\t3. Back to Main Menu" << endl;
	
	cin >> choose;
	cout << endl <<endl << endl;
	switch(choose)
	{
		case 1:
			obj.setCourseInfo();
			break;
		case 2:
			course = obj.viewCourseInfo();
			SeeCourse(obj , course);
			break;
		case 3:
			AdminMainMenu(obj);
			break;
	}
	getch();
	AdminMainMenu(obj);
}

void SeeCourse(Admin obj , int choice)
{
	int choose;
	cout << "\n\n\n\n\n\t\t\t\t1. Attendance" << endl;
	cout << "\n\t\t\t\t2. Grades" << endl;
	cout << "\n\t\t\t\t3. Back to Main Menu" << endl;
	cout << "Choice: ";
	cin >> choose;
	system("cls");
	switch (choice)
	{
		case 1:
			obj.oop(choice);
			break;
		case 2:
			obj.dld(choice);
			break;
		case 3:
			obj.de(choice);
			break;
		case 4:
			obj.cps(choice);
			break;
		case 5:
			obj.pst(choice);
			break;
	}
	getch();
	CourseDetails(obj);
}

void TeacherEntry(Admin obj)
{
	Title();
	obj.setTeachers();
	system("cls");
	cout << "\t\t***The teachers have been successfully assigned to the courses***" << endl;
}
int main()
{
	WelcomeScreen();
	start();
}

