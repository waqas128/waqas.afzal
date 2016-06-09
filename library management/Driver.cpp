#include "book.h"
#include "nmj.h"
#include "user.h"
#include<stdio.h>
#include "utility.h"


#include<dos.h>
#include<Windows.h>




int main ()
	{

	system("cls");
	


	menu();


	



	_getch();
	
	return 1;
	}



















//-----------------------------------------------------------------------------------------------------------


























/*	

//----------------------------------------------		Main Menu		-------------------------------------------

void menu (void)
{
	
	int opt;

	while(1)
	{

	system ("CLS");
	
	enter(3);
	space(16);
	cout<<"***********************************************";
	enter(1);
	space(16);
	cout<<"*                                             *";
	enter(1);
	space(16);
	cout<<"*                  Main Menu                  *";
	enter(1);
	space(16);
	cout<<"*                                             *";
	enter(1);
	space(16);
	cout<<"***********************************************";
	enter(3);
	space(22);
	cout<<"1.	Log In.";
	enter(1);
	space(22);
	cout<<"2.	Update an existing Student.";
	enter(1);
	space(22);
	cout<<"3.	Delete a record.";
	enter(1);
	space(22);
	cout<<"4.	Search for a student (Using ID or Name) ";
	enter(1);
	space(22);
	cout<<"5.	List Directory ";
	enter(1);
	space(22);
	cout<<"6.	Exit ";
	enter(3);
	space(5);
	

	
		cout<<"Select option [1 , 2 , 3 , 4 , 5 , 6]: ";
		cin>>opt;
		if(opt>6 || opt<1)
		{
			cout<<endl<<"Invalid Input"<<endl;
			//getch();
			continue;

			

		}

		if(opt==1)
		{
			insert();	
			break;
		}
		if(opt==2)
		{
			update();	
			break;
		}
		if(opt==3)
		{
			dlt();	
			break;
		}
		if(opt==4)
		{
			search_student();	
			break;
		}
		if(opt==5)
		{
			list_dir();	
			break;
		}
		if(opt==6)
		{
			exit(0);	
			//break;
		}


	}//end while
	


}

//-----------------------------------------------------------------------------------------------------------









*/












