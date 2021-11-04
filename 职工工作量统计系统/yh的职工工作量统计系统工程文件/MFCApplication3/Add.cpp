// Add.cpp: 实现文件
//

#include "pch.h"
#include "MFCApplication3.h"
#include "Add.h"
#include "afxdialogex.h"
#include<iostream>
#include<string>
#include "SystemDlg.h"
#include"Date.h"
using namespace std;
// Add 对话框

IMPLEMENT_DYNAMIC(Add, CDialogEx)

Add::Add(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG2, pParent)
{
	//cout << "lalaal";
}

Add::~Add()
{
}

void Add::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(Add, CDialogEx)

	ON_BN_CLICKED(IDOK, &Add::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, &Add::OnBnClickedCancel)
END_MESSAGE_MAP()


// Add 消息处理程序




void Add::OnEnChangeEdit2()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。
	// TODO:  在此添加控件通知处理程序代码
}


void Add::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	CString NAME;              //职工姓名
	CString MID;			       //职工号
	CString AGE; 			   //年龄
	CString DEPARTMENT;	       //所在部门
	CString CONTACT; 	       //联系方式
	CString WORKHOUR;
	Date* node;
	node = new Date;
	GetDlgItemText(IDC_EDIT_name,NAME );
	GetDlgItemText(IDC_EDIT_ID, MID);
	GetDlgItemText(IDC_EDIT_Department,DEPARTMENT);
	GetDlgItemText(IDC_EDIT_Contact, CONTACT);
	string str1(CW2A(NAME.GetString()));
	string str2(CW2A(MID.GetString()));
	string str3(CW2A(AGE.GetString()));
	string str4(CW2A(DEPARTMENT.GetString()));
	string str5(CW2A(CONTACT.GetString()));
	node->name = str1;
	node->ID =str2;
	node->age = GetDlgItemInt(IDC_EDIT_Age);
	node->Department = str4;
	node->Contact = str5;
	node->WorkHour = GetDlgItemInt(IDC_EDIT_WorkHour);
	int flag = 0;
	for (Date* p = head; p != NULL; p = p->next)
	{
		if (node->ID == p->ID)
		{
			MessageBox(_T("请勿重复添加"), _T("添加失败"));
			flag = 1;
			break;
		}
	}
	if (flag == 0)
	{
		if (head == NULL)
		{
			head = node;
			head->next = NULL;
		}
		else
		{
			Date* tail;
			tail = head;
			while (tail->next != NULL)           //寻找尾节点
			{
				tail = tail->next;
			}
			node->next = NULL;				  //设置尾节点
			tail->next = node;				  //插入节点
		}
		MessageBox(_T("输入成功"), _T("提示"));
	}
	CDialogEx::OnOK();
}


void Add::OnBnClickedCancel()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnCancel();
}
