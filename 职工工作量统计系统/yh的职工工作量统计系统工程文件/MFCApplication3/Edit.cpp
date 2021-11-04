// Edit.cpp: 实现文件
//

#include "pch.h"
#include "MFCApplication3.h"
#include "Edit.h"
#include "afxdialogex.h"
#include"Date.h"
#include<string>
using namespace std;

// Edit 对话框

IMPLEMENT_DYNAMIC(Edit, CDialogEx)

Edit::Edit(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG7, pParent)
{

}

Edit::~Edit()
{
}

void Edit::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(Edit, CDialogEx)
	ON_BN_CLICKED(IDOK, &Edit::OnBnClickedOk)
END_MESSAGE_MAP()


// Edit 消息处理程序


void Edit::OnBnClickedOk()
{
	CString NAME;           //职工姓名
	CString MID;			   //职工??
	CString AGE; 			   //年龄
	CString DEPARTMENT;	      //所在部??
	CString CONTACT; 	      //联系方式
	CString WORKHOUR;
	Date* node;
	node = new Date;
	GetDlgItemText(IDC_EDIT_name, NAME);
	GetDlgItemText(IDC_EDIT_ID, MID);
	GetDlgItemText(IDC_EDIT_Department, DEPARTMENT);
	GetDlgItemText(IDC_EDIT_Contact, CONTACT);
	string str1(CW2A(NAME.GetString()));
	string str2(CW2A(MID.GetString()));
	string str3(CW2A(AGE.GetString()));
	string str4(CW2A(DEPARTMENT.GetString()));
	string str5(CW2A(CONTACT.GetString()));
	node->name = str1;
	node->ID = str2;
	node->age = GetDlgItemInt(IDC_EDIT_Age);
	node->Department = str4;
	node->Contact = str5;
	node->WorkHour = GetDlgItemInt(IDC_EDIT_WorkHour);
	int flag = 0;
	for (Date* p = head; p != NULL; p = p->next)
	{
		if (node->ID == p->ID)
		{
			p->name = str1;
			p->ID = str2;
			p->age = GetDlgItemInt(IDC_EDIT_Age);
			p->Department = str4;
			p->Contact = str5;
			p->WorkHour = GetDlgItemInt(IDC_EDIT_WorkHour);
			MessageBox(_T("编辑成功"), _T("提示"));
			flag = 1;
			break;
		}
	}
	if (flag == 0)
	{
		MessageBox(_T("编辑失败，查无此人"), _T("提示"));
	}
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnOK();
}
