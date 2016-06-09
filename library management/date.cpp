#include "date.h"


date::date(void)
	{
	day=NULL;
	month=NULL;
	year=NULL;

	}


date::~date(void)
	{
	}
date::date(int a,int b,int c)
	{
		day=a;
		month=b;
		year=c;
	}
void date::setDate(int a,int b,int c)
	{
		day=a;
		month=b;
		year=c;
	}
date date::getDate()
	{
		return *this;

	}
void date::printDate()
	{
		cout<<day<<"-"<<month<<"-"<<year;
	}
date date::backDate(date a,int in)
	{
		int adays,amonth,ayear;
		adays=a.getDay();
		amonth=a.getMonth();
		ayear=a.getYear();
		adays=adays+in;
		if(adays>30)
			{amonth++; adays+=-30;}
		if(amonth>12)
			{
			ayear++;
			amonth-=30;
			}

		date b(adays,amonth,ayear);
		return b;
		
	}
		

	
date &date::setDay(int a)
	{
		day=a;
		return * this;
	
	}
date &date::setMonth(int a)
	{
		month=a;
		return * this;
	}
date &date::setYear(int a)
	{
		year=a;
		return * this;
	}
int date::getDay(){return day;}
int date::getMonth(){return month;}
int date::getYear(){return year;}