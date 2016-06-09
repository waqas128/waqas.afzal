#include "user.h"

int user::count=0;

user::user(void)
	{
	user::count++;
	hasBooks=0;
	fine=0;
	}


user::~user(void)
	{
	//user::count--;
	}

user::user(string utype, string uaccountNumber)
	{
		setUser( utype, uaccountNumber);
		
		
		hasBooks=0;
		fine=0;
		user::count++;
	}
void user::setUser(string utype, string uaccountNumber)
	{
	type=utype;
	accountNumber=uaccountNumber;
	if(utype=="student")		//	student, teacher or library staff
		{
		max=3;
		maxDays=7;
		}
	if(utype=="teacher")		//	student, teacher or library staff
		{
		max=10;
		maxDays=90;
		}
	if(utype=="staff")		//	student, teacher or library staff
		{
		max=5;
		maxDays=21;
		}


		
	

	}

void user::issueBook(book *b, date *dt)
	{
	
	issuedBooks.push_back(*b);
	issued.push_back(*dt);
	backDate();
	
	hasBooks++;
	}

string user::getAccountNumber()
	{
	return accountNumber;
	}

string user::getType()
	{
	return type;
	}
void user::printUser()
	{
	cout<<endl<<"User type = "<<type;
	cout<<endl<<"User ID/Account Number = "<<accountNumber;

	}

void user::calcFine(date a)
	{
	int counter=0,days,months,years;

	while(counter<issuedBooks.size() )
		{
		

			days=(a.getDay()	- issued[counter].getDay())
										+
				(	(a.getMonth()	- issued[counter].getMonth())*31	)
										+
				(	(a.getYear()	- issued[counter].getYear())*365	);

			
			if(days>maxDays)
				fine+=  10*(days-maxDays);







			



		counter++;
		}



	}



void user::backDate()
	{
	int subd,subm,suby;

	int counter;
	counter=0;
	date a;


	
	subd=issued[hasBooks].getDay();
	subm=issued[hasBooks].getMonth();
	suby=issued[hasBooks].getYear();

		subd+=maxDays;

		while(subd>31)
	{
					if(subd>31  )
						{

						subd-=31;
						subm++;
						}
		
					if(subm>12)
						{

						subm-=12;
						suby++;
						}

	}

		a.setDate(subd,subm,suby);

		back.push_back(a);


		

		

	}

int user::getFine()
	{
	return fine;

	}
void user::setFine(int a)
	{
	fine=a;

	}


int user::getHasBooks()
	{
	return hasBooks;
	}
int user::getMax()
	{
	return max;
	}


void user::printStatusOfBook(int a)
	{
	cout<<endl<<endl;
	issuedBooks[a].printBook();
	cout<<"\n\n Was Issued on :	";issued[a].printDate();
	cout<<"\n Return Date is  :	";back[a].printDate();
	cout<<endl;




	}

int user::reIssueBook(int num, date a)

	{

	int days,subd,subm,suby;

	days=(a.getDay()	- issued[num].getDay())
										+
				(	(a.getMonth()	- issued[num].getMonth())*31	)
										+
				(	(a.getYear()	- issued[num].getYear())*365	);

			
			if(days>maxDays)
				return 0;
			else{
				subd=a.getDay();
				subm=a.getMonth();
				suby=a.getYear();

							subd+=maxDays;
while(subd>31)
	{
					if(subd>31  )
						{

						subd-=31;
						subm++;
						}
		
					if(subm>12)
						{

						subm-=12;
						suby++;
						}

	}
					back[num].setDate(subd,subm,suby);


				}
		
return 1;
	}



int user::returnBook(int a)
	{
	f= new (book);
	*f=issuedBooks[ a];
	issuedBooks.erase(issuedBooks.begin()+ a);
	issued.erase(issued.begin()+a);
	back.erase(back.begin()+a);
	hasBooks--;
	return 1;




	}

void user::delBookPtr()
	{

	delete (f);
	}