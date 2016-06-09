#pragma once
#include<cstdlib>
#include<conio.h>
#include<iostream>
#include<string>
#include<fstream>
#include<vector>
#include<cstring>


using namespace std;

class book
	{
	
	private:
		string name;			//Name of Book
		string author;			//Author name
		string yop;				//Year Of Publication
		string isbn;			//International Standard Book Number
		string category;		//CS, EE, English, Bio etc
		string status;			// Available, Issued, Lost, On Order
		string iTo;				//Issued To
		string numOfCopies;		//Number of Coppies available
		string copyNum;			//Copy Number of current book
		
		
	public:
		static int code;	//Declared static so can be easyly accessed and will increase when 
							//number of books increase automatically through constructors
		book(void);
		~book(void);
		


		book(string name, string author,string yop,	string isbn,string category,string status,string iTo,string numOfCopies,string copyNum);
		//Over loaded Constructor above
		
		
		
		
		void setBook( string name, string author,string yop,	string isbn,string category,string status,string iTo,string numOfCopies,string copyNum	);
		//above one function to set all details of the book .
		

		void printBook();


		// Below		Getters
		string getName();
		string getAuthor();
		string getYop();		
		string getIsbn();
		string getCategory();
		string getStatus();
		string getIto();
		string getnumOfCopies();
		string getCopyNum();
		
		//-----------------------------------------------------------


		//Below		Cascading enabled setters
		book & setName(string);
		book & setAuthor(string);
		book & setYop(string);
		book & setIsbn(string);
		book & setCategory(string);
		book & setStatus(string);
		book & setIto(string);
		book & setnumOfCopies(string);
		book & setCopyNum(string);
		//------------------------------------------------------------------------------------


		};

