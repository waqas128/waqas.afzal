#include "book.h"



 int book::code=0;

book::book(void)
	{
	code++;
			name = "NULL";
			author="NULL";
			yop = "NULL";
			isbn= "NULL";
			category= "NULL";
			status= "NULL";
			iTo= "NULL";
			numOfCopies = "NULL";
			copyNum="NULL";

	}


book::~book(void)
	{
	
	//book::code--;
	}


book::book( string nameIn, string authorIn,string yopIn,	string isbnIn,string categoryIn,string statusIn,string iToIn,string numOfCopiesIn,string copyNumIn	)
	{
		
			name = nameIn;
			author=authorIn;
			yop = yopIn;
			isbn= isbnIn;
			category= categoryIn;
			status= statusIn;
			iTo= iToIn;
			numOfCopies = numOfCopiesIn;
			copyNum=copyNumIn;

		code++;


	}
		void book::setBook( string nameIn, string authorIn,string yopIn,string isbnIn,string categoryIn,string statusIn,string iToIn,string numOfCopiesIn,string copyNumIn	)
			{
			name = nameIn;
			author=authorIn;
			yop = yopIn;
			isbn= isbnIn;
			category= categoryIn;
			status= statusIn;
			iTo= iToIn;
			numOfCopies = numOfCopiesIn;
			copyNum=copyNumIn;

			



			}


	void book::printBook()
		{

		cout<<endl<<"Name :                "<<getName();
		cout<<endl<<"Author :              "<<getAuthor();
		cout<<endl<<"Year of Publication : "<<getYop();
		cout<<endl<<"ISB Number :          "<<getIsbn();
		cout<<endl<<"Category :            "<<getCategory();
		cout<<endl<<"Status :              "<<getStatus();
		cout<<endl<<"Issued to :           "<<getIto();
		cout<<endl<<"Number of Coppies :   "<<getnumOfCopies();
		cout<<endl<<"Copy Number :         "<<getCopyNum();
		




		}

		 
		string book::getName()
			{
			return name;

			}
		string book::getAuthor()
			{
			return author;
			}
		string book::getYop()
			{
			return yop;
			}
		
		string book::getIsbn()
			{
			return isbn;
			}
		string book::getCategory()
			{
			return category;
			}
		string book::getStatus()
			{
			return status;
			}
		string book::getIto()
			{
			return iTo;
			}
		string book::getnumOfCopies()
			{
			return numOfCopies;
			}
		string book::getCopyNum()
			{
			return copyNum;
			}

		book &book::setName(string a)
			{
			name = a; return * this;
			}
		book &book::setAuthor(string a)
			{
			author =a; return * this;
			}
		book &book::setYop(string a)
			{
			yop = a; return * this;
			}
		
		book &book::setIsbn(string a)
			{
			isbn = a; return * this;
			}
		book &book::setCategory(string a)
			{
			category = a; return * this;
			}
		book &book::setStatus(string a)
			{
			status = a; return * this;
			}
		book &book::setIto(string a)
			{
			iTo=a; return * this;
			}
		book &book::setnumOfCopies(string a)
			{
			numOfCopies =a; return * this;
			}
		book &book::setCopyNum(string a)
			{
			copyNum = a; return * this;
			} 
