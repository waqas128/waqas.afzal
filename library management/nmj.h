#pragma once
#include<cstdlib>
#include<conio.h>
#include<iostream>
#include<string>
#include<fstream>
#include<vector>
#include<cstring>


using namespace std;


class nmj
	{
	private:
		string name;
		string dop;
		string status;
		string category;
	public:
		static int code;
		nmj(void);
		~nmj(void);
		nmj(string nameIn, string dopIn,string statunIn,string categoryIn);
		void setNmj(string nameIn, string dopIn,string statunIn,string categoryIn);
		void printNmj();


		nmj & setName(string);
		nmj & setDop(string);
		nmj & setStatus(string);
		nmj & setCategory(string);

		string getName();
		string getDop();
		string getStatus();
		string getCategory();

	};

