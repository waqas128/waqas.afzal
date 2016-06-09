#include "nmj.h"

int nmj::code=0;
nmj::nmj(void)
	{
	code++;
	name=dop=status=category="NULL";
	}


nmj::~nmj(void)
	{
	//nmj::code--;
	}
nmj::nmj(string nameIn, string dopIn,string statunIn,string categoryIn)
	{
	name=nameIn;
	dop=dopIn;
	status=statunIn;
	category=categoryIn;
	code++;

	}
void nmj::setNmj(string nameIn, string dopIn,string statunIn,string categoryIn)
	{
		name=nameIn;
		dop=dopIn;
		status=status;
		category=categoryIn;
		


	}



void nmj::printNmj()
	{

	/*

	string name;
		string dop;
		string status;
		string category;


		*/
	cout<<endl<<"Name:                 "<<getName();
	cout<<endl<<"Date of Publication : "<<getDop();
	cout<<endl<<"Status:               "<<getStatus();
	cout<<endl<<"Category:             "<<getCategory();



	}







nmj & nmj:: setName(string a)
	{
		name=a;
		return *this;
	}
nmj & nmj:: setDop(string a)
	{
		dop=a;
		return *this;
	}
nmj & nmj:: setStatus(string a)
	{
		status=a;
		return *this;
	}
nmj & nmj:: setCategory(string a)
	{
		category=a;
		return *this;
	}

string nmj:: getName()
	{
		return name;
	}
string nmj:: getDop()
	{
		return dop;
	}
string nmj:: getStatus()
	{
		return status;
	}
string nmj:: getCategory()
	{
		return category;
	}