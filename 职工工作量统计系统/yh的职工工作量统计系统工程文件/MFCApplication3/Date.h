#pragma once
#include<iostream>
#include<string>
using namespace std;
class Date
{
public:
	string name;           //ְ������
	string ID;			   //ְ��??
	int age; 			   //����
	string Department;	      //���ڲ�??
	string Contact; 	      //��ϵ��ʽ
	int WorkHour;          //����?? 	
	Date* next; 	   //����ָ��
};
Date* head;