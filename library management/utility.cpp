#include<cstdlib>
#include<conio.h>
#include<iostream>
#include<string>
#include<fstream>
#include<vector>
#include<cstring>


#include "book.h"
#include "nmj.h"
#include "user.h"
#include "utility.h"
#include<stdio.h>

#include<dos.h>
#include<Windows.h>


	VOID WINAPI Sleep(
DWORD dwMilliseconds
);

//		####################		Global Declarations
	string idOfLogedInUser;
vector <book> books;
vector <nmj> nmjs;
vector <user> users;
string logedOnId="0";
string logedOnType="0";
int databaseLoaded=0;
date today(0,0,0);

//		*******************************************************************************************


using namespace std;
//#################################################			Simple Utility Functions for Printing Spaces and Next Lines 
void enter(int a)
{

	int counter;
	for(counter=0;counter<a;counter++)
	cout<<endl;

}



void space(int a)
{
	int counter;
	for(counter=0;counter<a;counter++)
	cout<<" ";
}

//###########################################################################################################################




//---------------------------		List NMJ books		-----------------------------------
void listAllnmj()

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
	cout<<"*               List of Books                 *";
	enter(1);
	space(16);
	cout<<"*                                             *";
	enter(1);
	space(16);
	cout<<"***********************************************";
	enter(3);
	space(22);
	if(!nmjs.size())
		{
			enter(1);
			space(5);
			cout<<endl<<"No Newspapers/Magzines.Journals in database to list or database not loaded.";
			_getch();
		}
	int counter=0;
	while(nmjs.size())
		{
		
		

			enter(3);
			cout<<"News Paper/Magzine/Journal # "<<counter+1<<endl;
			nmjs[counter].printNmj();
		
		_getch();
		counter++;
			
		
		if(counter==nmjs.size())
			break;

		}
	}


//---------------------------		List all NMJ	END    ------------------------------------------------










//--------------		List all users -------------------------------------------------------


void listUsers()
	{
	int counter=0;





	system ("CLS");
	
	enter(3);
	space(16);
	cout<<"***********************************************";
	enter(1);
	space(16);
	cout<<"*                                             *";
	enter(1);
	space(16);
	cout<<"*               List of Users                 *";
	enter(1);
	space(16);
	cout<<"*                                             *";
	enter(1);
	space(16);
	cout<<"***********************************************";
	enter(3);
	space(22);
	if(!users.size())
		{
			enter(1);
			space(15);
			cout<<endl<<"No Users in database to list or database not loaded.";
			_getch();
		}
	
	while(users.size())
		{
		enter(3);
		
		cout<<"User Number : "<<counter+1<<endl;
		users[counter].printUser();
		_getch();

		counter++;
		if(counter==users.size())
			break;

		}
	}


//------------------------------		List Users End		------------------------------------------










//---------------------------		List all books		-----------------------------------
void listAllBooks()

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
	cout<<"*               List of Books                 *";
	enter(1);
	space(16);
	cout<<"*                                             *";
	enter(1);
	space(16);
	cout<<"***********************************************";
	enter(3);
	space(22);

	int counter=0;
	while(books.size())
		{
		
		

			enter(3);
			cout<<"Book # "<<counter+1<<endl;
		books[counter].printBook();
		cout<<endl<<"Book Library Code:    "<<counter;
		
		_getch();
		counter++;
			
		
		if(counter==books.size())
			break;

		}
	}


//---------------------------		List all books	END    ------------------------------------------------











//---------------------------------------		List by category		---------------------


void listByCategory()
	{
	string ctgry;
		int opt;
		char inp;
		

		int br=0;

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
	cout<<"*               List of Books                 *";
	enter(1);
	space(16);
	cout<<"*                                             *";
	enter(1);
	space(16);
	cout<<"***********************************************";
	enter(3);
	space(22);
	cout<<"1.	CS ";
	enter(1);
	space(22);
	cout<<"2.	EE";
	enter(1);
	space(22);
	cout<<"3.	English ";
	enter(1);
	space(22);
	cout<<"4.	Main Menu ";
	enter(3);
	space(5);
	

	
		cout<<"Select option [ 1 , 2 , 3 , 4 ]: ";
		cin>>opt;
		
		
		if(opt>4 || opt<1)
		{
			cout<<endl<<"Invalid Input"<<endl;
			//getch();
			continue;

			

		}

		switch (opt)
			{
			case 1:
				ctgry="CS";	
				br=1;
				break;
		
			case 2:
				ctgry="EE";	
				br=1;
				break;
		
			case 3:
				ctgry="English";
				br=1;
				break;
			case 4:
				br=1;
				menu();
		
			}

		if(br==1)
			break;

	}
		int bookFound=0;
		int counter=0;
		int c2=1;
		while(books.size())
		{
		
		if(ctgry==books[counter].getCategory())

			{enter(3);
		cout<<"Book "<<c2<<" of "<<ctgry<<endl;
		books[counter].printBook();
		cout<<endl<<"Book Library Code:    "<<counter;
		bookFound=1;
		c2++;
		_getch();
			}
		counter++;
		if(counter==books.size())
			break;

		}

		if(bookFound==0)
			cout<<"No Book found on this category";
		while(1)
					{
					enter(2);
					space(15);
					cout<<"Do you want to List books of another category ?  Y/N ";
			
					inp=_getche();
				
						if(inp=='n' || inp == 'N')
					break;
			
					if(inp=='Y' || inp == 'y')	
						{
						listByCategory();
						
						
						}
					if(inp !='y' && inp != 'Y' && inp!='n' && inp != 'N' )
						{
							enter(2);
							space(15);
							cout<<"Wrong Input";
						
						}
					}


	}

//--------------------------------------  List Books by category END		------------------------









//----------------------------------		ListBooks		---------------------
void listBooks()
{
	
	int counter=0;


	system ("CLS");
	
	enter(3);
	space(16);
	cout<<"***********************************************";
	enter(1);
	space(16);
	cout<<"*                                             *";
	enter(1);
	space(16);
	cout<<"*               List of Books                 *";
	enter(1);
	space(16);
	cout<<"*                                             *";
	enter(1);
	space(16);
	cout<<"***********************************************";
	enter(3);
	space(22);
	if(!books.size())
		{
			enter(1);
			space(15);
			cout<<endl<<"No books in database to list or database not loaded.";
			_getch();
			menu();
		}

	int opt;
		char inp;
		



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
	cout<<"*               List of Books                 *";
	enter(1);
	space(16);
	cout<<"*                                             *";
	enter(1);
	space(16);
	cout<<"***********************************************";
	enter(3);
	space(22);
	cout<<"1.	List all books. ";
	enter(1);
	space(22);
	cout<<"2.	List books by category";
	enter(1);
	space(22);
	cout<<"3.	Main Menu ";
	enter(1);
	space(22);
	cout<<"4.	Exit ";
	enter(3);
	space(5);
	

	
		cout<<"Select option [ 1 , 2 , 3 , 4 ]: ";
		cin>>opt;
		
		
		if(opt>4 || opt<1)
		{
			cout<<endl<<"Invalid Input"<<endl;
			//getch();
			continue;

			

		}

		switch (opt)
			{
			case 1:
				listAllBooks();	
				break;
		
			case 2:
				listByCategory();	
				break;
		
			case 3:
				menu();
				break;
			case 4:
				exit(0);
		
		
			}

	}//end while

}
//------------------------------------##		List books end   ##--------------------------------------------------------------










	//----------------##			Display menu		##----------------------

void displayMenu()
	{
		int opt;
		char inp;
		int counter;



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
	cout<<"*               Display Menu                  *";
	enter(1);
	space(16);
	cout<<"*                                             *";
	enter(1);
	space(16);
	cout<<"***********************************************";
	enter(3);
	space(22);
	cout<<"1.	List Books. ";
	enter(1);
	space(22);
	cout<<"2.	List Newspaper/Magzines/Journals";
	enter(1);
	space(22);
	cout<<"3.	List all users ";
	enter(1);
	space(22);
	cout<<"4.	Main Menu ";
	enter(1);
	space(22);
	cout<<"5.	Exit ";
	enter(3);
	space(5);
	

	
		cout<<"Select option [ 1 , 2 , 3 , 4 , 5 ]: ";
		cin>>opt;
		
		
		if(opt>5 || opt<1)
		{
			cout<<endl<<"Invalid Input"<<endl;
			//getch();
			continue;

			

		}

		switch (opt)
			{
			case 1:
				listBooks();	
				break;
		
			case 2:
				listAllnmj();	
				break;
		
			case 3:
				listUsers();	
				break;
			case 4:
				menu();
				break;
			case 5:
				exit(0);
		
		
			}

	}//end while
	

	}


//------------------------  $$			Display MEnu End	$$-----------------------------------












//----------------------------------------------		Log in Menu		-------------------------------------------

void logOn (void)
{
	
	int opt;
	string inId;
	int counter;
	int found=-1;
	char inp;


	if(users.size()==0)
		{
			system("cls");
			enter(3);
	space(16);
	cout<<"***********************************************";
	enter(1);
	space(16);
	cout<<"*                                             *";
	enter(1);
	space(16);
	cout<<"*                  Log In Menu                *";
	enter(1);
	space(16);
	cout<<"*                                             *";
	enter(1);
	space(16);
	cout<<"***********************************************";
	enter(3);
	space(15);
			enter(1);
			space(15);
			cout<<"No users in database or database not Loaded";
			enter(2);
			space(15);
			cout<<"To log in, you need to Load database first";
			enter(3);
			space(15);
			cout<<"Press any key to go back to main menu. ";
			_getch();

		}


	while(users.size())
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
	cout<<"*                  Log In Menu                *";
	enter(1);
	space(16);
	cout<<"*                                             *";
	enter(1);
	space(16);
	cout<<"***********************************************";
	enter(3);
	space(15);

	//------------------------   if already loged in		-------------------------------------------------

	if(logedOnId!="0" && logedOnType!="0" )
		{
			enter(3);
			space(15);
			cout<<"You are Already loged in";
			enter(2);
			space(15);
			cout<<"Your ID is : "<<logedOnId;
			enter(1);
			space(15);
			cout<<"Your account type is : "<<logedOnType;

			while(1)
					{
					enter(2);
					space(15);
					cout<<"Do you want to Log on as a diffrent user ?  Y/N ";
			
					inp=_getche();
				
						if(inp=='n' || inp == 'N')
					menu();
			
					if(inp=='Y' || inp == 'y')	
						{
						break;
						
						}
					if(inp !='y' && inp != 'Y' && inp!='n' && inp != 'N' )
						{
							enter(2);
							space(15);
							cout<<"Wrong Input";
						
						}
					}

		}
	//-----------------------------------------------------------------------------------------------

	enter(3);
	space(15);
	cout<<"1.	Enter your Log in Details.";
	enter(1);
	space(15);
	cout<<" 	For students Roll number for teachers";
	enter(1);
	space(15);
	cout<<"         for library staff employee code";
	enter(1);
	space(15);
	
	

	
		cout<<"ID: ";
		cin>>inId;

		counter=0;
		while(1)
			{
			if(users[counter].getAccountNumber()==inId)
				{
					enter(2);
					space(15);
					cout<<"User found you have Sucessfully loged in . ";
					logedOnId=users[counter].getAccountNumber();
					logedOnType=users[counter].getType();enter(2);
					enter(2);
					space(15);
					cout<<"Your ID is : "<<logedOnId;
					enter(1);
					space(15);
					cout<<"Your account type is : "<<logedOnType;
					

					found=1;
					_getch();
					break;

				}
			else
				found=0;

				counter++;
				if(counter==users.size())
					break;
			

			}
		if(found == 0)
				{	
					enter(2);
					space(15);
					cout<<"Could not find ID";

					while(1)
					{
					enter(2);
					space(15);
					cout<<"Do you want to Enter another ID ?  Y/N ";
			
					inp=_getche();
				
						if(inp=='n' || inp == 'N')
					menu();
			
					if(inp=='Y' || inp == 'y')	
						logOn();
					if(inp !='y' && inp != 'Y' && inp!='n' && inp != 'N' )
						{
							enter(2);
							space(15);
							cout<<"Wrong Input";
						
						}
			
					}
				
		

			}
		if(found==1)
			menu();


	}//end while
	


}
	
//--------------------------------------------		Log In menu END		---------------------------------------------------------------














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
	cout<<"*                   WELLCOME                  *";
	enter(1);
	space(16);
	cout<<"*        To Library Management System.        *";
	enter(1);
	space(16);
	cout<<"*                                             *";
	enter(1);
	space(16);
	cout<<"***********************************************";
	enter(3);
	space(22);
	cout<<"1.	Login...";
	enter(1);
	space(22);
	cout<<"2.	Load Library Database";
	enter(1);
	space(22);
	cout<<"3.	Display Library Items ";
	enter(1);
	space(22);
	cout<<"4.	Perform Library actions ";
	enter(1);
	space(22);
	cout<<"5.	Set Today's Date ";
	enter(1);
	space(22);
	cout<<"6.	Exit ";
	enter(3);
	space(5);
	

	
		cout<<"Select option [ 1 , 2 , 3 , 4 , 5 , 6 ]: ";
		cin>>opt;
		
		
		if(opt>6 || opt<1)
		{
			cout<<endl<<"Invalid Input"<<endl;
			_getch();
			continue;

			

		}

		switch (opt)
			{
			case 1:
				logOn();	
				break;
		
			case 2:
				loadDB();	
				break;
		
			case 3:
				displayMenu();	
				break;
			case 4:
				if(databaseLoaded==0 || logedOnId=="0" || logedOnType=="0")
					{
						enter(3);
						space(22);
						cout<<"Not loged in or Database not Loaded. ";
						enter(2);
						space(22);
						cout<<"	Press any key to continue";
						enter(3);
						_getch();
						continue;

					}
				if(databaseLoaded==1)
					{
				actions();
				break;
					}
			case 5:
				updateDate();	
				break;
			case 6:
				exit(0);
		
		
			}

	}//end while
	


}

//----------------------------------------------		Main Menu END		-------------------------------------------









//----------------------------------------------		Database load menu		-------------------------------------------
int loadDB(void)
	{

	if(databaseLoaded==1)
		{
		system("cls");
		enter(3);
		space(16);
		cout<<"***********************************************";
		enter(1);
		space(16);
		cout<<"*                                             *";
		enter(1);
		space(16);
		cout<<"*             Data Base Load Menu             *";
		enter(1);
		space(16);
		cout<<"*                                             *";
		enter(1);
		space(16);
		cout<<"***********************************************";

		enter(3);
		space(13);
	
	
		cout<<"Database Already loaded press any key to go to main menu. ";


		_getch();







		return 1;
		}
	book *newBook=NULL;
	nmj *newNmj=NULL;
	user *newUser=NULL;
	string pathName;
	char inp;
	system("cls");
	int flip_flop=0;
	enter(3);
	space(16);
	cout<<"***********************************************";
	enter(1);
	space(16);
	cout<<"*                                             *";
	enter(1);
	space(16);
	cout<<"*             Data Base Load Menu             *";
	enter(1);
	space(16);
	cout<<"*                                             *";
	enter(1);
	space(16);
	cout<<"***********************************************";

	enter(3);
	space(13);
	
	
	cout<<"Enter database File name with Extension: ";
	cin>>pathName;
	enter(3);
	space(13);
	cout<<"Loading Database";

	

	//pathName="database.db";
	//_getch();


	//ifstream in("database.db");
	ifstream in(pathName);

	
	if(!in)
		{
			cout<<endl<<"ERROR !!!	Error Opening File...";
			

		

			
		
		while(1)
					{
					enter(2);
					space(15);
					cout<<"Do you want to Enter another File name ?  Y/N ";
			
					inp=_getche();
				
						if(inp=='n' || inp == 'N')
					menu();
			
					if(inp=='Y' || inp == 'y')	
						{
						loadDB();
						
						}
					if(inp !='y' && inp != 'Y' && inp!='n' && inp != 'N' )
						{
							enter(2);
							space(15);
							cout<<"Wrong Input";
						
						}
					}

			

			return 1;

		}//End File checking if
	
	
	//---------			If file is Sucessfully found we can start reading it and load it into the containers

	
	//---------------------  Variables for Books

		string sname;			//Name of Book
		string sauthor;			//Author name
		string syop;				//Year Of Publication
		string sisbn;			//International Standard Book Number
		string scategory;		//CS, EE, English, Bio etc
		string sstatus;			// Available, Issued, Lost, On Order
		string siTo;				//Issued To
		string snumOfCopies;		//Number of Coppies available
		string scopyNum;
		int nbook=-1;
		int bbool=0;

	//------------------------	Variables for nmj (Newspapers/Magezines/Journals)
		string nname;
		string ndop;
		string nstatus;
		string ncategory;
		int nnmj=-1;
		int nmjbool=0;

	//-------------------------  Variables for users
		int ubool=0;
		int nuser=-1;
		string ut;
		string uid;


//		sname,sauthor,syop,sisbn,scategory,sstatus,siTo,snumOfCopies,scopyNum

int bookCountTemp=0,nmjCountTemp=0,userCountTemp=0;
	

	string line;
	while(getline(in,line))
		{





			//------------------------------------------		Book loading start



		if(line=="------------------------------		booksDbStart")
			bbool=1;
		if(line =="------------------------------		booksDbEnd")
			bbool=0;
		if(bbool==1)
			{

					if(line=="...book")
						{
						bookCountTemp++;
					
						nbook=0;
					
						}
					if (nbook>=1 && nbook<=9)
						{
							switch (nbook)
								{
									case 1:
										sname=line;
										break;
									case 2:
										sauthor=line;
										break;
									case 3:
										syop=line;
										break;
									case 4:
										sisbn=line;
										break;
									case 5:
										scategory=line;
										break;
									case 6:
										sstatus=line;
										break;
									case 7:
										siTo=line;
										break;
									case 8:
										snumOfCopies=line;
										break;
									case 9:
										scopyNum = line;
										break;


								}

					
						}

					nbook++;


					if(nbook==10 && bbool==1)
						{
						nbook=-9999999;


					
							newBook = new book (sname,sauthor,syop,sisbn,scategory,sstatus,siTo,snumOfCopies,scopyNum);
						//newBook->setName(sname).setAuthor(sauthor).setYop(syop).setCategory(scategory).setStatus(sstatus).setIto(siTo).setnumOfCopies(snumOfCopies).setCopyNum(scopyNum);

							//newBook->setCopyNum("1");
							books.push_back(*newBook);
						//	books[books.size()].setName(sname).setAuthor(sauthor).setYop(syop).setCategory(scategory).setStatus(sstatus).setIto(siTo).setnumOfCopies(snumOfCopies).setCopyNum(scopyNum);
							delete newBook;


						} // endif of book creation



			}// Endif of	bbool==1


//----------------------------------------		Book loading end




// ---------------------------------		nmj Loading Start



		if(line=="-------------------------------------		News Papers Magezines journals start")
			nmjbool=1;
		if(line =="-------------------------------------		News Papers Magezines journals End")
			nmjbool=0;
		if(nmjbool==1)
			{
				if(line=="...nmj")
						{
						nmjCountTemp++;
						//cout<<endl<<"New NMJ Number = "<<nmjCountTemp;
						nnmj=0;
						//break;
						}//endif for new nmj entry
				if (nnmj>=1 && nnmj<=4)
						{
							switch (nnmj)
								{
									case 1:
										nname=line;
										break;
									case 2:
										ndop=line;
										break;
									case 3:
										nstatus=line;
										break;
									case 4:
										ncategory=line;
										break;
									
								}

					
						}

					nnmj++;


					if(nnmj==5 && nmjbool==1)
						{
						nnmj=-9999999;


					
						newNmj = new nmj (nname,ndop,nstatus,ncategory);
						
						nmjs.push_back(*newNmj);
						
							delete newNmj;


						} // endif of nmj creation





				




			}//endif for nmjbool == 1

//------------------------------------------	nmj Loading end



		



			



//----------------------------------		User loading start

		
		if(line=="-------------------------------------		User loading start")
			ubool=1;
		if(line =="-------------------------------------		User loading end")
			{
			ubool=0;
			
			}
		if(ubool==1)
			{
				if(line=="...user")
						{
						userCountTemp++;
						
						nuser=0;
						//break;
						}//endif for new user entry
				if (nuser>=1 && nuser<=2)
						{
						switch (nuser)
								{
									case 1:
										ut=line;
										break;
									case 2:
										uid=line;
										break;
									
									
								}

					
						}

					nuser++;


					if(nuser==3 && ubool==1)
						{
						nuser=-9999999;


					
						newUser = new user (ut,uid);
						

						
						users.push_back(*newUser);
						
						delete newUser;


						} // endif of user creation








			}//endif for ubool == 1






//----------------------------------		User loading end


		

		//_getch();


		



		//	system("cls");
/*
	enter(3);
	space(16);
	cout<<"***********************************************";
	enter(1);
	space(16);
	cout<<"*                                             *";
	enter(1);
	space(16);
	cout<<"*             Data Base Load Menu             *";
	enter(1);
	space(16);
	cout<<"*                                             *";
	enter(1);
	space(16);
	cout<<"***********************************************";

	enter(3);
	space(13);*/
	//		cout<<book::code<<"Books"<<endl;
			flip_flop++;
	if(flip_flop%50==0)
		
			cout<<" *";
			
	
Sleep(5);


















	//	cout<<endl<<book::code<<"   books";
	//				_getch();



//------------		Handle all your File reading before this Line		------------------------
		}	//end Line reading loop





















	
	enter(2);
	cout<<book::code<<" Books Loaded.";
	enter(2);
	cout<<nmj::code<<" Magzines / Journals / News Papers Loaded.";
	enter(2);
	cout<<user::count<<" Users Loaded.";
	enter(3);
	space(13);
	cout<<"Database Sucessfully Loaded!!!\n\n\t\t\t Press any key to continue";
	databaseLoaded=1;

	_getch();


	



	return 1;
	}

//----------------------------------------------		Database load menu END		-------------------------------------------












//---------------------------------------  Staff Actions Menu ------------------------------------------------

int staffActions()
	{


	
//_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-	Log in check			_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-


	if(logedOnId=="0" && logedOnType=="0")
		{
		system("cls");
		enter(3);
		space(16);
		cout<<"***********************************************";
		enter(1);
		space(16);
		cout<<"*                                             *";
		enter(1);
		space(16);
		cout<<"*             Staff Action Menu               *";
		enter(1);
		space(16);
		cout<<"*                                             *";
		enter(1);
		space(16);
		cout<<"***********************************************";

		enter(3);
		space(1);
		
			
				cout<<"You need to load database and log in First to perform any actions";
				enter(2);
				space(16);
				cout<<"Press any key to go back to main menu";
				_getch();
				menu();
			

		}


//_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-	Checking done			_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-

	int opt;
	

	while(1)
	{

	system ("CLS");
	
	enter(2);
	space(16);
	cout<<"***********************************************";
	enter(1);
	space(16);
	cout<<"*                                             *";
	enter(1);
	space(16);
	cout<<"*             Staff Action Menu               *";
	enter(1);
	space(16);
	cout<<"*                                             *";
	enter(1);
	space(16);
	cout<<"***********************************************";
	enter(2);
	space(22);
	cout<<"1.	Add New Book";
	enter(1);
	space(22);
	cout<<"2.	Check status of a book";
	enter(1);
	space(22);
	cout<<"3.	Check account information of a User ";
	enter(1);
	space(22);
	cout<<"4.	Issue Book ";
	enter(1);
	space(22);
	cout<<"5.	Re-Issue Book ";
	enter(1);
	space(22);
	cout<<"6.	Return Book ";
	enter(1);
	space(22);
	cout<<"7.	Remove fine of a user ";
	enter(1);
	space(22);
	cout<<"8.	Calculate Fines ";
	enter(1);
	space(22);
	cout<<"9.	Main Menu ";
	enter(1);
	space(22);
	cout<<"10.	Exit ";
	enter(3);
	space(5);
	

	
		cout<<"Select option [ 1 , 2 , 3 , 4 , 5 , 6 , 7 , 8 , 9 , 10 ]: ";
		cin>>opt;
		
		
		if(opt>10 || opt<1)
		{
			cout<<endl<<"Invalid Input"<<endl;
			_getch();
			continue;

			

		}

		switch (opt)
			{
			case 1:
				addNewBook();	
				break;
		
			case 2:
				statusByCode();	
				break;
		
			case 3:
				if(today.getDay()==0 || today.getMonth()==0 || today.getYear()==0 )
					{
						enter(2);
						cout<<"Date not Set or Invalid date ";
						_getch();
						continue;

					}
				userAccountInfo()	;
				break;
			case 4:
				if(today.getDay()==0 || today.getMonth()==0 || today.getYear()==0 )
					{
						enter(2);
						cout<<"Date not Set or Invalid date ";
						_getch();
						continue;

					}
				issue();
				break;
			case 5:
						if(today.getDay()==0 || today.getMonth()==0 || today.getYear()==0 )
							{
								enter(2);
								cout<<"Date not Set or Invalid date ";
								_getch();
								continue;

							}
			reIssue();
				break;
			case 6:
			returnBook();
				break;
			case 7:
				if(today.getDay()==0 || today.getMonth()==0 || today.getYear()==0 )
					{
						enter(2);
						cout<<"Date not Set or Invalid date ";
						_getch();
						continue;

					}
				removeFine();
				break;
			case 8:
				
				if(today.getDay()==0 || today.getMonth()==0 || today.getYear()==0 )
					{
						enter(2);
						cout<<"Date not Set or Invalid date ";
						_getch();
						continue;

					}
				calculateFine();
				break;
			case 9:
				menu();
			case 10:
				exit(0);
		
		
			}












		return 1;
	}
}


//-----------------------------------##		staff Actions Menu End		##---------------------------












//-----------------------------------	Actions Menu
void actions()
	{
	if(logedOnType=="student")
		studentActions();
	if(logedOnType=="staff")
		staffActions();
	if(logedOnType=="teacher")
		teacherActions();
	



	}


//----------------------------------##	Actions Menu End	##----------------------------------












//-------------------------------   add new book		--------------------------------------

void addNewBook()
	{
	system("cls");
	char inp;
	
	//_getch();
		book * newBook;
		int opt,selected=0,infoCorrect=0;
		string sname;			//Name of Book
		string sauthor;			//Author name
		string syop;				//Year Of Publication
		string sisbn;			//International Standard Book Number
		string scategory;		//CS, EE, English, Bio etc
		string sstatus;			// Available, Issued, Lost, On Order
		string siTo;				//Issued To
		string snumOfCopies;		//Number of Coppies available
		string scopyNum;		//Number of this copy




	while(1)
		{
		enter(2);
		cout<<"###################		Add new Book		#########################";
		enter(2);
		cout<<endl<<"Enter Name of The Book	:";
		cin>>sname;
		cout<<endl<<"Enter Author's Name	:";
		cin>>sauthor;
		cout<<endl<<"Enter Year of Publication	:";
		cin>>syop;
		cout<<endl<<"Enter International Standard Book Number	:";
		cin>>sisbn;
			while(selected==0)
				{
					cout<<endl<<endl<<"Select type of book";
					enter(2);
					cout<<"1.	CS";
					enter(2);
					cout<<"2.	EE";
					enter(2);
					cout<<"3.	English";
					enter(2);
					cout<<"Select option [ 1 , 2 , 3 ]: ";
					cin>>opt;
		
		
					if(opt>3 || opt<1)
					{
						cout<<endl<<"Invalid Input"<<endl;
						_getch();
						continue;

			

					}

					switch (opt)
						{
						case 1:
							scategory="CS";	
							selected=1;
							break;
		
						case 2:
							scategory="EE";
							selected=1;
							break;
		
						case 3:
							scategory="English";
							selected=1;
							break;
			
		
						}

				
			}	//Category Selection While

			selected=0;
			while(selected==0)
				{
					enter(3);
					cout<<"Enter Current status of the book	:";
					enter(2);
					cout<<"1.	Available";
					enter(2);
					cout<<"2.	Issued";
					enter(2);
					cout<<"3.	Lost";
					enter(2);
					cout<<"4.	On Order";
					enter(2);
					cout<<"Select option [ 1 , 2 , 3 ]: ";
					cin>>opt;
		
		
					if(opt>4 || opt<1)
					{
						cout<<endl<<"Invalid Input"<<endl;
						_getch();
						continue;

			

					}

					switch (opt)
						{
						case 1:
							sstatus="Available";	
							selected=1;
							break;
		
						case 2:
							sstatus="Issued";
							selected=1;
							break;
		
						case 3:
							sstatus="Lost";
							selected=1;
							break;
						case 4:
							sstatus="On Order";
							selected=1;
							break;
			
		
						}

				
			}	//Status Selection While end

			
			
			
			siTo="NULL";

			cout<<endl<<"Enter Number of copies available	:";
			cin>>snumOfCopies;

			cout<<endl<<"Enter Copy Number of this copy	:";
			cin>>scopyNum;

			cout<<endl<<endl<<"			You Have Enterd Below Details"<<endl<<endl;
			cout<<endl<<"Name                   :"<<sname;
			cout<<endl<<"Author's Name          :"<<sauthor;
			cout<<endl<<"Year of Publication    :"<<syop;
			cout<<endl<<"International Standard Book Number	:"<<sisbn;
			cout<<endl<<"Category               :"<<scategory;
			cout<<endl<<"Current Status         :"<<sstatus;
			cout<<endl<<"Number of copies       :"<<snumOfCopies;
			cout<<endl<<"Current copy Number    :"<<scopyNum;

			//cout<<endl<<endl<<"Are these details correct ? Add book ?";




			while(1)
					{
					enter(2);
					space(15);

					cout<<"Is the above Information Correct ? ADD book  Y/N ";
			
					inp=_getche();
				
						if(inp=='n' || inp == 'N')
							addNewBook();
			
					if(inp=='Y' || inp == 'y')	
						{

						newBook = new book (sname,sauthor,syop,sisbn,scategory,sstatus,siTo,snumOfCopies,scopyNum);
						books.push_back(*newBook);
						delete newBook;
						enter(3);
						cout<<"Book Sucessfully Added...";
						cout<<endl<<endl<<"\t\t Presany key to continue.";
						_getch();
						staffActions();
						
						}
					if(inp !='y' && inp != 'Y' && inp!='n' && inp != 'N' )
						{
							enter(2);
							space(15);
							cout<<"Wrong Input";
						
						}
					}





			/*
		
						newBook = new book (sname,sauthor,syop,sisbn,scategory,sstatus,siTo,snumOfCopies,scopyNum);
						//newBook->setName(sname).setAuthor(sauthor).setYop(syop).setCategory(scategory).setStatus(sstatus).setIto(siTo).setnumOfCopies(snumOfCopies).setCopyNum(scopyNum);

							//newBook->setCopyNum("1");
							books.push_back(*newBook);
						//	books[books.size()].setName(sname).setAuthor(sauthor).setYop(syop).setCategory(scategory).setStatus(sstatus).setIto(siTo).setnumOfCopies(snumOfCopies).setCopyNum(scopyNum);
							delete newBook;


			*/

		}

	}

//-------------------------------##   add new book		##--------------------------------------














//-------------------------------------		student Actions		-----------------------------------------
void studentActions()
	{
	
	
//_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-	Log in check			_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-


	if(logedOnId=="0" && logedOnType=="0")
		{
		system("cls");
		enter(3);
		space(16);
		cout<<"***********************************************";
		enter(1);
		space(16);
		cout<<"*                                             *";
		enter(1);
		space(16);
		cout<<"*            Student Action Menu              *";
		enter(1);
		space(16);
		cout<<"*                                             *";
		enter(1);
		space(16);
		cout<<"***********************************************";

		enter(3);
		space(1);
		
			
				cout<<"You need to load database and log in First to perform any actions";
				enter(2);
				space(16);
				cout<<"Press any key to go back to main menu";
				_getch();
				menu();
			

		}


//_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-	Checking done			_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-

	int opt;
	

	while(1)
	{

	system ("CLS");
	
	enter(2);
	space(16);
	cout<<"***********************************************";
	enter(1);
	space(16);
	cout<<"*                                             *";
	enter(1);
	space(16);
	cout<<"*            Student Action Menu              *";
	enter(1);
	space(16);
	cout<<"*                                             *";
	enter(1);
	space(16);
	cout<<"***********************************************";
	enter(2);
	space(22);
	cout<<"1.	List Booksby category ";
	enter(1);
	space(22);
	cout<<"2.	Check status of a book";
	enter(1);
	space(22);
	cout<<"3.	Check your account information  ";
	enter(1);
	space(22);
	cout<<"4.	Calculate Fines ";
	enter(1);
	space(22);
	cout<<"5.	Main Menu ";
	enter(1);
	space(22);
	cout<<"6.	Exit ";
	enter(3);
	space(5);
	

	
		cout<<"Select option [ 1 , 2 , 3 , 4 , 5 , 6 ]: ";
		cin>>opt;
		
		
		if(opt>6 || opt<1)
		{
			cout<<endl<<"Invalid Input"<<endl;
			_getch();
			continue;

			

		}

		switch (opt)
			{
			case 1:
				listByCategory();
				break;
		
			case 2:
				statusByCode();	
				break;
		
			case 3:
				if(today.getDay()==0 || today.getMonth()==0 || today.getYear()==0 )
					{
						enter(2);
						cout<<"Date not Set or Invalid date ";
						_getch();
						continue;

					}
				userAccountInfo2()	;
				break;
		
			case 4:
				
				if(today.getDay()==0 || today.getMonth()==0 || today.getYear()==0 )
					{
						enter(2);
						cout<<"Date not Set or Invalid date ";
						_getch();
						continue;

					}
				calculateFine();
				break;
			case 5:
				menu();
			case 6:
				exit(0);
		
		
			}



	}

	}

//------------------------------------ ##  student actions end  ##---------------------------------------












//--------------------------------------  Teacher actions		-------------------------------------------


void teacherActions()
	{


	
//_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-	Log in check			_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-


	if(logedOnId=="0" && logedOnType=="0")
		{
		system("cls");
		enter(3);
		space(16);
		cout<<"***********************************************";
		enter(1);
		space(16);
		cout<<"*                                             *";
		enter(1);
		space(16);
		cout<<"*            Teacher Action Menu              *";
		enter(1);
		space(16);
		cout<<"*                                             *";
		enter(1);
		space(16);
		cout<<"***********************************************";

		enter(3);
		space(1);
		
			
				cout<<"You need to load database and log in First to perform any actions";
				enter(2);
				space(16);
				cout<<"Press any key to go back to main menu";
				_getch();
				menu();
			

		}


//_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-	Checking done			_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-

	int opt;
	

	while(1)
	{

	system ("CLS");
	
	enter(2);
	space(16);
	cout<<"***********************************************";
	enter(1);
	space(16);
	cout<<"*                                             *";
	enter(1);
	space(16);
	cout<<"*            Teacher Action Menu              *";
	enter(1);
	space(16);
	cout<<"*                                             *";
	enter(1);
	space(16);
	cout<<"***********************************************";
	enter(2);
	space(22);
	cout<<"1.	List Booksby category ";
	enter(1);
	space(22);
	cout<<"2.	Check status of a book";
	enter(1);
	space(22);
	cout<<"3.	Check your account information  ";
	enter(1);
	space(22);
	cout<<"4.	Calculate Fines ";
	enter(1);
	space(22);
	cout<<"5.	Main Menu ";
	enter(1);
	space(22);
	cout<<"6.	Exit ";
	enter(3);
	space(5);
	

	
		cout<<"Select option [ 1 , 2 , 3 , 4 , 5 , 6 ]: ";
		cin>>opt;
		
		
		if(opt>6 || opt<1)
		{
			cout<<endl<<"Invalid Input"<<endl;
			_getch();
			continue;

			

		}

		switch (opt)
			{
			case 1:
				listByCategory();
				break;
		
			case 2:
				statusByCode();	
				break;
		
			case 3:
				if(today.getDay()==0 || today.getMonth()==0 || today.getYear()==0 )
					{
						enter(2);
						cout<<"Date not Set or Invalid date ";
						_getch();
						continue;

					}
				userAccountInfo2()	;
				break;
		
			case 4:
				
				if(today.getDay()==0 || today.getMonth()==0 || today.getYear()==0 )
					{
						enter(2);
						cout<<"Date not Set or Invalid date ";
						_getch();
						continue;

					}
				calculateFine();
				break;
			case 5:
				menu();
			case 6:
				exit(0);
		
		
			}



	}







	}

//---------------------------------------------------##		Teacher actions End  ##---------------------------













//---------------------------------------		Status by code		--------------------------------------
void statusByCode()
	{

	string ctgry;
		int opt;
		char inp;
		int bookFound=0;
		int counter=0;
		int c2=1;
		int inCode=-1;
		int br=0;
		

		while(inCode==-1)
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
	cout<<"*           Status Checking Menu              *";
	enter(1);
	space(16);
	cout<<"*                                             *";
	enter(1);
	space(16);
	cout<<"***********************************************";
	enter(3);
	space(22);
	cout<<"Enter Code of book to check status : ";
	cin>>inCode;
	}
		
		counter=inCode;
		
		if(inCode>books.size())
			cout<<"\n\n\n\n\n\n Invalid Code... \n\n";
		else
			{
		
				enter(3);
				cout<<"Book of Code :  "<<inCode<<endl;
				books[inCode].printBook();
				cout<<endl<<"Book Library Code:    "<<counter;
				enter(5);
				bookFound=1;	
				_getch();
			
			}
		

		if(bookFound==0)
			cout<<"No Book found with this code . ";
		while(1)
					{
					enter(2);
					space(15);
					cout<<"Do you want to check stats of another Book ?  Y/N ";
			
					inp=_getche();
				
						if(inp=='n' || inp == 'N')
							actions();
			
					if(inp=='Y' || inp == 'y')	
						{
						statusByCode();
						
						
						}
					if(inp !='y' && inp != 'Y' && inp!='n' && inp != 'N' )
						{
							enter(2);
							space(15);
							cout<<"Wrong Input";
						
						}
					}
		



	}


//-------------------------------------##		Status by code END	##-------------------------------------









//---------------------------------------		Issue		----------------------------------------------

void issue()
	{
	int opt;
		char inp;
		int bookFound=0;
		int counter=0;
		int c2=1;
		int inCode=-1;
		int br=0;
		int selectedCode=-1;
		string selectedUserId;
		book a;
		
	//**********************	Book Selection Start	***********************
		while(inCode==-1)
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
	cout<<"*                 Issue Book                  *";
	enter(1);
	space(16);
	cout<<"*                                             *";
	enter(1);
	space(16);
	cout<<"***********************************************";
	enter(3);
	space(22);
	cout<<"Enter Code of book to Select : ";
	cin>>inCode;
	if(inCode>books.size())
		{
			enter(3);
			cout<<"\n\n\n\n\n\n Invalid Code... \n\n";
			_getch();
			continue;
		}
	}
		
		counter=inCode;
		
		if(inCode>books.size())
			cout<<"\n\n\n\n\n\n Invalid Code... \n\n";
		else
			{
		
				enter(3);
				cout<<"Book of Code :  "<<inCode<<endl;
				books[inCode].printBook();
				cout<<endl<<"Book Library Code:    "<<counter;
				enter(5);
				bookFound=1;	
				//_getch();
			
			}
		

		if(bookFound==0)
			cout<<"No Book found with this code . ";
		while(1)
					{
					enter(2);
					space(15);
					cout<<"Do you want to select This Book ?  Y/N ";
			
					inp=_getche();
				
						if(inp=='n' || inp == 'N')
							{
							issue();
							
							}
			
					if(inp=='Y' || inp == 'y')	
						{
						selectedCode=inCode;
							break;
						}
					if(inp !='y' && inp != 'Y' && inp!='n' && inp != 'N' )
						{
							enter(2);
							space(15);
							cout<<"Wrong Input";
						
						}
					}

		a=books[selectedCode];

		//	************		Book Selection End		************


		// *************		User Selection Start	*************

		string inId="0";
		int userSelected=0;
		string backId;
		int idFound=0,idCode=-1;;
while(userSelected==0)
	{
	system("cls");



	while(idFound==0)
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
	cout<<"*                 Issue Book                  *";
	enter(1);
	space(16);
	cout<<"*                                             *";
	enter(1);
	space(16);
	cout<<"***********************************************";
	enter(3);
	space(22);
	cout<<"Enter ID of user to Select : ";
	cin>>inId;
	counter=0;
	while(counter<users.size())
		{	
		backId= users[counter].getAccountNumber();
		if(backId==inId)
			{
			idCode=counter;
			idFound=1;
			break;
			}
		counter++;



		}

	if(idFound==0)
		{
			enter(3);
			cout<<"\n\n\n\n\n\n Invalid ID... \n\n";
			_getch();
			continue;
		}
	}
		
		
		
	if(idCode==-1)
			cout<<"\n\n\n\n\n\n Can not Find User... \n\n";
		else
			{
		
				enter(3);
				cout<<"User with ID :  "<<inId<<endl;
				users[idCode].printUser();
				
				enter(5);
				
				//_getch();
			
			}
		

	if(idFound==0)
			cout<<"No User found with this ID . ";
		while(1)
					{
					enter(2);
					space(15);
					cout<<"Do you want to select This User ?  Y/N ";
			
					inp=_getche();
				
						if(inp=='n' || inp == 'N')
							{
							idFound=0;
							break;
							
							
							}
			
					if(inp=='Y' || inp == 'y')	
						{
						selectedUserId=users[idCode].getAccountNumber();
						userSelected=1;
							break;
						}
					if(inp !='y' && inp != 'Y' && inp!='n' && inp != 'N' )
						{
							enter(2);
							space(15);
							cout<<"Wrong Input";
						
						}
					}
		if(userSelected==1)
			break;
	}// user selection while end

	//-----################  User Selection End   ################----------------
	
	
	

	//############---------------------		Issuing Date  ---------------------
	
	date submit;






	system ("CLS");
	
	enter(3);
	space(16);
	cout<<"***********************************************";
	enter(1);
	space(16);
	cout<<"*                                             *";
	enter(1);
	space(16);
	cout<<"*                 Issue Book                  *";
	enter(1);
	space(16);
	cout<<"*                                             *";
	enter(1);
	space(16);
	cout<<"***********************************************";
	enter(3);
	space(22);
	cout<<"Enter Issuing Date : ";
	int d,m,y;
	
	//#####	Day
	while(1)
		{
		enter(2);
		cout<<"Enter Day: ";
			cin>>d;
		if(d<=31 && d>=1)
			break;
		else
			{
			enter(2);
			cout<<" Invalid Day.....   Enter Again.";
			continue;
			}

		}
	
	//#####	Month
	while(1)
		{
		enter(2);
		cout<<"Enter Month: ";
		cin>>m;
		if(m<=12 && m>=1)
			break;
		else
			{
			enter(2);
			cout<<" Invalid Month.....   Enter Again.";
			continue;
			}

		}
	while(1)
		{
		enter(2);
		cout<<"Enter Year: ";
		cin>>y;
		if(y>2011 && y<2015)
			break;
		else
			{
			enter(2);
			cout<<" Invalid year..... has to be between 2012 and 2015 Inclusively. Lolz  \nEnter Again.";
			continue;
			}

		}
	
	
	submit.setDate(d,m,y);
	
	
	//#########-----------###########		Issuing Date End		####-------------------------


	if(users[idCode].getHasBooks()< users[idCode].getMax() && books[selectedCode].getStatus()=="Available")
		{

	
	enter(2);
	cout<<"Book Sucessfully Issued to User";
	books[selectedCode].setStatus("Issued");
	books[selectedCode].setIto(users[idCode].getAccountNumber());
	a.setStatus("Issued");
	a.setIto(users[idCode].getAccountNumber());
	users[idCode].issueBook(&a,&submit);

	_getch();

		}
	else
		{
		enter(2);
		cout<<"This user Has Already Issued Maximum Books";
		cout<<endl<<" Or the Book is Not Available ";
	//	books[selectedCode].setStatus("Available");
	//	books[selectedCode].setIto("NULL");
		_getch();

		}
		
}

//------------------------------------##		Issue End		------------------------------------------












//-----------------------------------------		User Account Info		---------------------------------

void userAccountInfo()
	{

			// *************		User Selection Start	*************

		string inId="0";
		int userSelected=0;
		string backId;
		int idFound=0,idCode=-1;;
		char inp;
		int counter;
		string selectedUserId;
while(userSelected==0)
	{
	system("cls");



	while(idFound==0)
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
	cout<<"*             User Account Info               *";
	enter(1);
	space(16);
	cout<<"*                                             *";
	enter(1);
	space(16);
	cout<<"***********************************************";
	enter(3);
	space(22);
	cout<<"Enter ID of user to Select : ";
	cin>>inId;
	counter=0;
	while(counter<users.size())
		{	
		backId= users[counter].getAccountNumber();
		if(backId==inId)
			{
			idCode=counter;
			idFound=1;
			break;
			}
		counter++;



		}

	if(idFound==0)
		{
			enter(3);
			cout<<"\n\n\n\n\n\n Invalid ID... \n\n";
			_getch();
			continue;
		}
	}
		
		
		
	if(idCode==-1)
			cout<<"\n\n\n\n\n\n Can not Find User... \n\n";
		else
			{
		
				enter(3);
				cout<<"User with ID :  "<<inId<<endl;
				users[idCode].printUser();
				
				enter(5);
				
				//_getch();
			
			}
		

	if(idFound==0)
			cout<<"No User found with this ID . ";
		while(1)
					{
					enter(2);
					space(15);
					cout<<"Do you want to select This User ?  Y/N ";
			
					inp=_getche();
				
						if(inp=='n' || inp == 'N')
							{
							break;
							
							}
			
					if(inp=='Y' || inp == 'y')	
						{
						selectedUserId=users[idCode].getAccountNumber();
						userSelected=1;
							break;
						}
					if(inp !='y' && inp != 'Y' && inp!='n' && inp != 'N' )
						{
							enter(2);
							space(15);
							cout<<"Wrong Input";
						
						}
					}
		if(userSelected==1)
			break;
	}// user selection while end

	//############------------ User Selection End		###------------------------------

	system("cls");
	

	cout<<"###-----------------------------------------------###";
	enter(2);
	users[idCode].printUser();
	cout<<" Fine of This User is	:	"<<users[idCode].getFine();
	enter(2);
	if(users[idCode].getHasBooks()==0)
		{cout<<" Has Issued no Books";
	enter(2);
	_getch();
		}
	else
		{
			int cx=0;
			while(cx<users[idCode].getHasBooks())
				{
					enter(3);
					cout<<"Book #	:	"<<cx+1<<endl;
					users[idCode].printStatusOfBook(cx);




					cx++;
					_getch();
				}
		}


	
	}

//----------------------------------------##		User Account Info End	-------------------------------












//-----------------------------------------		Remove Fine		---------------------------------

void removeFine()
	{

			// *************		User Selection Start	*************

		string inId="0";
		int userSelected=0;
		string backId;
		int idFound=0,idCode=-1;;
		char inp;
		int counter;
		string selectedUserId;
while(userSelected==0)
	{
	system("cls");



	while(idFound==0)
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
	cout<<"*                 Remove Fine                 *";
	enter(1);
	space(16);
	cout<<"*                                             *";
	enter(1);
	space(16);
	cout<<"***********************************************";
	enter(3);
	space(22);
	cout<<"Enter ID of user to Select : ";
	cin>>inId;
	counter=0;
	while(counter<users.size())
		{	
		backId= users[counter].getAccountNumber();
		if(backId==inId)
			{
			idCode=counter;
			idFound=1;
			break;
			}
		counter++;



		}

	if(idFound==0)
		{
			enter(3);
			cout<<"\n\n\n\n\n\n Invalid ID... \n\n";
			_getch();
			continue;
		}
	}
		
		
		
	if(idCode==-1)
			cout<<"\n\n\n\n\n\n Can not Find User... \n\n";
		else
			{
		
				enter(3);
				cout<<"User with ID :  "<<inId<<endl;
				users[idCode].printUser();
				
				enter(5);
				
				//_getch();
			
			}
		

	if(idFound==0)
			cout<<"No User found with this ID . ";
		while(1)
					{
					enter(2);
					space(15);
					cout<<"Do you want to select This User ?  Y/N ";
			
					inp=_getche();
				
						if(inp=='n' || inp == 'N')
							{
							break;
							
							}
			
					if(inp=='Y' || inp == 'y')	
						{
						selectedUserId=users[idCode].getAccountNumber();
						userSelected=1;
							break;
						}
					if(inp !='y' && inp != 'Y' && inp!='n' && inp != 'N' )
						{
							enter(2);
							space(15);
							cout<<"Wrong Input";
						
						}
					}
		if(userSelected==1)
			break;
	}// user selection while end

	//############------------ User Selection End		###------------------------------



	enter(5);
	cout<<"Fine of This User is	:	"<<users[idCode].getFine();
	int inFine;
	cout<<endl<<"Enter New Fine of User (enter 0 if you want to remove Fine ) ";
	cout<<endl<<"Enter New Fine		:	";
	cin>>inFine;
	users[idCode].setFine(inFine);

	enter(5);
	cout<<"\t\t\t\t New Fine Sucessfully Set ... ";
	_getch();


	
	}

//----------------------------------------##		Remove Fine End	   ##-------------------------------















	//-----------------------------------		Update Date Start		--------------------
void updateDate()
	{
	int dateSelected=0;
	int d,m,y;



	while(dateSelected==0)
		
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
	cout<<"*                  Set Date                   *";
	enter(1);
	space(16);
	cout<<"*                                             *";
	enter(1);
	space(16);
	cout<<"***********************************************";
	enter(3);
	space(22);
	cout<<"Enter Issuing Date : ";
	
	
	//#####	Day
	while(1)
		{
		enter(2);
		cout<<"Enter Day: ";
			cin>>d;
		if(d<=31 && d>=1)
			break;
		else
			{
			enter(2);
			cout<<" Invalid Day.....   Enter Again.";
			continue;
			}

		}
	
	//#####	Month
	while(1)
		{
		enter(2);
		cout<<"Enter Month: ";
		cin>>m;
		if(m<=12 && m>=1)
			break;
		else
			{
			enter(2);
			cout<<" Invalid Month.....   Enter Again.";
			continue;
			}

		}
	while(1)
		{
		enter(2);
		cout<<"Enter Year: ";
		cin>>y;
		if(y>2011 && y<2015)
			break;
		else
			{
			enter(2);
			cout<<" Invalid year..... has to be between 2012 and 2015 Inclusively. Lolz  \nEnter Again.";
			continue;
			}

		}

	enter(5);
	cout<<"Date you have entered is		:	";
	cout<<endl<<"Day	:"<<d;
	cout<<endl<<"Month	:"<<m;
	cout<<endl<<"Year	:"<<y;
	enter(2);
	cout<<"Is this Date Correct	?";
		

	char inp;
		
		
		while(1)
					{
					enter(2);
					space(15);
					cout<<"Is this Date Correct	?";
			
					inp=_getche();
				
						if(inp=='n' || inp == 'N')
							{
							break;
							
							}
			
					if(inp=='Y' || inp == 'y')	
						{
						dateSelected=1;
							break;
						}
					if(inp !='y' && inp != 'Y' && inp!='n' && inp != 'N' )
						{
							enter(2);
							space(15);
							cout<<"Wrong Input";
						
						}
					}
		
		
		
		
		
		
		
		}


		today.setDate(d,m,y);

		enter(3);
		space(15);
		cout<<"Date Sucessfully Set...";
		cout<<endl<<"\t\t\t\t\tPress Any key to Continue...";
	}

//-------------------------------------##		Update Date END		##		--------------------------











//-------------------------------------		Calculate Fines		--------------------------
void calculateFine()
	{
	int counter =0;

	while(counter<users.size())
		{
		users[counter].calcFine(today);



			
			

		counter++;
		}


	enter(1);
		cout<<"Fines of  "<<counter<<"  Users are Calculated and updated ";
		_getch();



	}

//-------------------------------------##		Calculate Fines END		##--------------------------










//------------------------------------		Re Issue		----------------------------
void reIssue()
	{

	
			// *************		User Selection Start	*************
		int inBnum;
		string inId="0";
		int userSelected=0;
		string backId;
		int idFound=0,idCode=-1;;
		char inp;
		int counter;
		string selectedUserId;
while(userSelected==0)
	{
	system("cls");
	


	while(idFound==0)
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
	cout<<"*                 Re-Issue Book               *";
	enter(1);
	space(16);
	cout<<"*                                             *";
	enter(1);
	space(16);
	cout<<"***********************************************";
	enter(3);
	space(22);
	cout<<"Enter ID of user to Select : ";
	cin>>inId;
	counter=0;
	while(counter<users.size())
		{	
		backId= users[counter].getAccountNumber();
		if(backId==inId)
			{
			idCode=counter;
			idFound=1;
			break;
			}
		counter++;



		}

	if(idFound==0)
		{
			enter(3);
			cout<<"\n\n\n\n\n\n Invalid ID... \n\n";
			_getch();
			continue;
		}
	}
		
		
		
	if(idCode==-1)
			cout<<"\n\n\n\n\n\n Can not Find User... \n\n";
		else
			{
		
				enter(3);
				cout<<"User with ID :  "<<inId<<endl;
				users[idCode].printUser();
				
				enter(5);
				
				//_getch();
			
			}
		

	if(idFound==0)
			cout<<"No User found with this ID . ";
		while(1)
					{
					enter(2);
					space(15);
					cout<<"Do you want to select This User ?  Y/N ";
			
					inp=_getche();
				
						if(inp=='n' || inp == 'N')
							{
							break;
							
							}
			
					if(inp=='Y' || inp == 'y')	
						{
						selectedUserId=users[idCode].getAccountNumber();
						userSelected=1;
							break;
						}
					if(inp !='y' && inp != 'Y' && inp!='n' && inp != 'N' )
						{
							enter(2);
							space(15);
							cout<<"Wrong Input";
						
						}
					}
		if(userSelected==1)
			break;
	}// user selection while end

	//############------------ User Selection End		###------------------------------

	system("cls");
	

	cout<<"###-----------------------------------------------###";
	enter(2);
	users[idCode].printUser();
//	cout<<"Fine of This User is	:	"<<users[idCode].getFine();
	enter(2);
	if(users[idCode].getHasBooks()==0)
		{cout<<"Has Issued no Books";
	enter(2);
	_getch();
		}
	else
		{
		enter(3);
		cout<<"Select book by book Number";
			int cx=0;
			while(cx<users[idCode].getHasBooks())
				{
					enter(3);
					cout<<"Book #	:	"<<cx+1<<endl;
					users[idCode].printStatusOfBook(cx);




					cx++;
					_getch();
				}
		}

	enter(5);
	cout<<"Enter Number of Book to Re-Issue";
	cin>>inBnum;

	users[idCode].printStatusOfBook(inBnum-1);

	while(1)
					{
					enter(2);
					space(15);
					cout<<"Do you want to select This Book ?  Y/N ";
			
					inp=_getche();
				
						if(inp=='n' || inp == 'N')
							{
							reIssue();
							
							}
			
					if(inp=='Y' || inp == 'y')	
						{
						
							break;
						}
					if(inp !='y' && inp != 'Y' && inp!='n' && inp != 'N' )
						{
							enter(2);
							space(15);
							cout<<"Wrong Input";
						
						}
					}
	if(users[idCode].reIssueBook(inBnum-1,today) )
		{
		enter(3);
		space(15);
		cout<<"Book Sucessfully Re-Issued \n\n\t\t ";
		cout<<"\t\t\t\t\t Press any key to print the details";
		users[idCode].printStatusOfBook(inBnum-1);
		_getch();
		
		}
	else
		{
		enter(4);
		cout<<"Could not issue book. can Only Re-Issue in return time";
		_getch();
		}

	staffActions();

	}


//------------------------------------###		Re Issue End		###----------------------------













//------------------------------------		Return Book		-------------------------------
void 	returnBook()
	{

		
			// *************		User Selection Start	*************
		int inBnum;
		string inId="0";
		int userSelected=0;
		string backId;
		int idFound=0,idCode=-1;;
		char inp;
		int counter;
		string selectedUserId;
while(userSelected==0)
	{
	system("cls");
	


	while(idFound==0)
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
	cout<<"*                  Return Book                *";
	enter(1);
	space(16);
	cout<<"*                                             *";
	enter(1);
	space(16);
	cout<<"***********************************************";
	enter(3);
	space(22);
	cout<<"Enter ID of user to Select : ";
	cin>>inId;
	counter=0;
	while(counter<users.size())
		{	
		backId= users[counter].getAccountNumber();
		if(backId==inId)
			{
			idCode=counter;
			idFound=1;
			break;
			}
		counter++;



		}

	if(idFound==0)
		{
			enter(3);
			cout<<"\n\n\n\n\n\n Invalid ID... \n\n";
			_getch();
			continue;
		}
	}
		
		
		
	if(idCode==-1)
			cout<<"\n\n\n\n\n\n Can not Find User... \n\n";
		else
			{
		
				enter(3);
				cout<<"User with ID :  "<<inId<<endl;
				users[idCode].printUser();
				
				enter(5);
				
				//_getch();
			
			}
		

	if(idFound==0)
			cout<<"No User found with this ID . ";
		while(1)
					{
					enter(2);
					space(15);
					cout<<"Do you want to select This User ?  Y/N ";
			
					inp=_getche();
				
						if(inp=='n' || inp == 'N')
							{
							break;
							
							}
			
					if(inp=='Y' || inp == 'y')	
						{
						selectedUserId=users[idCode].getAccountNumber();
						userSelected=1;
							break;
						}
					if(inp !='y' && inp != 'Y' && inp!='n' && inp != 'N' )
						{
							enter(2);
							space(15);
							cout<<"Wrong Input";
						
						}
					}
		if(userSelected==1)
			break;
	}// user selection while end

	//############------------ User Selection End		###------------------------------

	system("cls");
	

	cout<<"###-----------------------------------------------###";
	enter(2);
	users[idCode].printUser();
//	cout<<"Fine of This User is	:	"<<users[idCode].getFine();
	enter(2);
	if(users[idCode].getHasBooks()==0)
		{cout<<"Has Issued no Books";
	enter(2);
	_getch();
		}
	else
		{
		enter(3);
		cout<<"Select book by book Number";
			int cx=0;
			while(cx<users[idCode].getHasBooks())
				{
					enter(3);
					cout<<"Book #	:	"<<cx+1<<endl;
					users[idCode].printStatusOfBook(cx);




					cx++;
					_getch();
				}
		}

	enter(5);
	cout<<"Enter Number of Book to Return it";
	cin>>inBnum;

	users[idCode].printStatusOfBook(inBnum-1);

	while(1)
					{
					enter(2);
					space(15);
					cout<<"Do you want to select This Book ?  Y/N ";
			
					inp=_getche();
				
						if(inp=='n' || inp == 'N')
							{
							reIssue();
							
							}
			
					if(inp=='Y' || inp == 'y')	
						{
						
							break;
						}
					if(inp !='y' && inp != 'Y' && inp!='n' && inp != 'N' )
						{
							enter(2);
							space(15);
							cout<<"Wrong Input";
						
						}
					}
	


	if(users[idCode].returnBook(inBnum-1) )
		{
		enter(3);
		space(15);
		cout<<"Book Sucessfully ReTurned \n\n\t\t ";
	//	cout<<"\t\t\t\t\t Press any key to print the details";
		int k=0;
		while(1)
			{

			books[k].setIto("NULL");
			books[k].setStatus("Available");
			k++;

			if(books[k].getName()!=users[idCode].f->getName() && books[k].getAuthor()!=users[idCode].f->getAuthor() && books[k].getCopyNum()!=users[idCode].f->getCopyNum()	)
				{
				users[idCode].delBookPtr();
				break;

				}
			}



		_getch();
		
		}
	else
		{
		enter(4);
		cout<<"Could not return book. ";
		_getch();
		}

	staffActions();



	}


//-------------------------------###		Return Book End		--------------------------













	//-----------------------------------------		User Account Info2		---------------------------------

void userAccountInfo2()
	{

			// *************		User Selection Start	*************
	system("cls");
		string inId="0";
		int userSelected=0;
		string backId;
		int idFound=0,idCode=-1;;
		char inp;
		int counter;
		string selectedUserId;
		int k=0;
while(1)
	{
	


	if(logedOnId==users[k].getAccountNumber())
		break;
	k++;
	
	}// user selection while end
idCode=k;
	//############------------ User Selection End		###------------------------------

	system("cls");
	

	cout<<"###-----------------------------------------------###";
	enter(2);
	users[idCode].printUser();
	cout<<" Fine of This User is	:	"<<users[idCode].getFine();
	enter(2);
	if(users[idCode].getHasBooks()==0)
		{cout<<" Has Issued no Books";
	enter(2);
	_getch();
		}
	else
		{
			int cx=0;
			while(cx<users[idCode].getHasBooks())
				{
					enter(3);
					cout<<"Book #	:	"<<cx+1<<endl;
					users[idCode].printStatusOfBook(cx);




					cx++;
					_getch();
				}
		}


	
	}

//----------------------------------------##		User Account Info2 End	-------------------------------