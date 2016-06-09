#pragma once
#include<cstdlib>
#include<conio.h>
#include<iostream>
#include<string>
#include<fstream>
#include<vector>
#include<cstring>

using namespace std;

class date
	{
	private:
		int day,month,year;
	public:
		date(void);
		~date(void);
		date(int,int,int);
		void setDate(int,int,int);
		date getDate();
		void printDate();
		date backDate(date,int);
		date &setDay(int);
		date &setMonth(int);
		date &setYear(int);
		int getDay();
		int getMonth();
		int getYear();

	};

