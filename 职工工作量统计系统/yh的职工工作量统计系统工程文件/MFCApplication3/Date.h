#pragma once
#include<iostream>
#include<string>
using namespace std;
class Date
{
public:
	string name;           //职工姓名
	string ID;			   //职工??
	int age; 			   //年龄
	string Department;	      //所在部??
	string Contact; 	      //联系方式
	int WorkHour;          //工作?? 	
	Date* next; 	   //链表指针
};
Date* head;