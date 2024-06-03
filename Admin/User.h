#include <iostream>
#include <iomanip>
#include <string>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <dos.h>
#include <fstream>

using namespace std;

class User
{
	protected:
		string f_name;
		string l_name;
		static int ID;
		string password;
		
	public:
		User(string first_name = "" , string last_name = "" , string pass = "") : f_name(first_name) , l_name(last_name)  , password(pass){}
		
		void setName(string FirstName , string LastName)
		{
			f_name = FirstName;
			l_name = LastName;
		}
		void setPassword(string pass)
		{
			password = pass;
		}
		void displayInfo()
		{
			cout << "First name: " << f_name << endl;
			cout << "Last name: " << l_name << endl;
			cout << "Enrollment ID: " << ID << endl;
			cout << "Password: " << password << endl;
		}
		
};

int User :: ID = 10;


