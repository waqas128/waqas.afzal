#pragma once
#include"book.h"
#include"date.h"
#include"nmj.h"
#include<cstdlib>
#include<conio.h>
#include<iostream>
#include<string>
#include<fstream>
#include<vector>
#include<cstring>



using namespace std;

class user
	{
	private:
		string type;
		string accountNumber;
		vector <book> issuedBooks;
		vector <date> issued;
		vector <date> back;
		int max;
		int fine;
		int hasBooks;
		int maxDays;

	public:
		static int count;
		user(void);
		user(string utype, string uaccountNumber);
		~user(void);
		void setUser(string utype, string uaccountNumber);
		void issueBook(book *, date *);
		string getAccountNumber();
		string getType();
		void printUser();
		void calcFine(date);
		void backDate();
		int getFine();
		void setFine(int);
		int getHasBooks();
		int getMax();
		void printStatusOfBook(int);
		int reIssueBook(int, date );
		int returnBook(int);
		book *f;
		void delBookPtr();
		
	};

