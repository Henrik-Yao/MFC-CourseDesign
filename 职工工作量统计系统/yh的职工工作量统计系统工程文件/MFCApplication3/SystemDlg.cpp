// SystemDlg.cpp: 实现文件
//

#include "pch.h"
#include "MFCApplication3.h"
#include "SystemDlg.h"
#include "afxdialogex.h"
#include"Add.h"
#include"Delete.h"
#include"Find.h"
#include"xianshi.h"
#include"Date.h"
#include<math.h>
#include<fstream>
#include"Edit.h"
#include"AddWH.h"
#include"Addall.h"
using namespace std;

// SystemDlg 对话框

IMPLEMENT_DYNAMIC(SystemDlg, CDialogEx)

SystemDlg::SystemDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG1, pParent)
{

}

SystemDlg::~SystemDlg()
{
}

void SystemDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(SystemDlg, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &SystemDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON4, &SystemDlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON6, &SystemDlg::OnBnClickedButton6)
	ON_BN_CLICKED(IDC_BUTTON2, &SystemDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &SystemDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON8, &SystemDlg::OnBnClickedButton8)
	ON_BN_CLICKED(IDC_BUTTON9, &SystemDlg::OnBnClickedButton9)
	ON_BN_CLICKED(IDC_BUTTON5, &SystemDlg::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON7, &SystemDlg::OnBnClickedButton7)
	ON_BN_CLICKED(IDC_BUTTON10, &SystemDlg::OnBnClickedButton10)
END_MESSAGE_MAP()


// SystemDlg 消息处理程序


void SystemDlg::OnClose()
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CDialog* pdlg=(CDialog*) AfxGetMainWnd();
	pdlg->DestroyWindow();
	CDialogEx::OnClose();
}


BOOL SystemDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}






void SystemDlg::OnBnClickedButton1()
{
	Add x;
	x.DoModal();
	// TODO: 在此添加控件通知处理程序代码
}


void SystemDlg::OnBnClickedButton4()
{
	// TODO: 在此添加控件通知处理程序代码
	Delete dlg;
	dlg.DoModal();
}


void SystemDlg::OnBnClickedButton6()
{
	Find dlg2;
	dlg2.DoModal();
	// TODO: 在此添加控件通知处理程序代码
}


void SystemDlg::OnBnClickedButton2()
{
	xianshi dlg4;
	dlg4.DoModal();
	// TODO: 在此添加控件通知处理程序代码
}


void SystemDlg::OnBnClickedButton3()
{
	Date* p = head;
	int flag = 0;
	for (; p->next != NULL; p = p->next)
	{
		Date* max = p;
		for (Date* j = p->next; j != NULL; j = j->next)
		{
			if (j->WorkHour < max->WorkHour)max = j;
		}
		swap(p->name, max->name);
		swap(p->ID, max->ID);
		swap(p->age, max->age);
		swap(p->Department, max->Department);
		swap(p->Contact, max->Contact);
		swap(p->WorkHour, max->WorkHour);
	}
	xianshi dlg5;
	dlg5.DoModal();
	// TODO: 在此添加控件通知处理程序代码
}


void SystemDlg::OnBnClickedButton8()
{
	ofstream save;
	save.open("date.txt", ios::out);
	for (Date* p = head; p != NULL; p = p->next)
	{
		save << p->name << " "
			<< p->ID << " "
			<< p->age << " "
			<< p->Department << " "
			<< p->Contact << " "
			<< p->WorkHour << endl;
	}
	save.close();
	MessageBox(_T("保存成功!"), _T("提示"));
	// TODO: 在此添加控件通知处理程序代码
}


void SystemDlg::OnBnClickedButton9()
{
	ifstream read;
	read.open("date.txt", ios::in);
	if (!read.is_open())
	{
		MessageBox(_T("文件为空!"), _T("提示"));
	}
	else
	{
		while (!read.eof())
		{
			Date* node;
			node = new Date;
			read >> node->name >> node->ID >> node->age >> node->Department
				 >> node->Contact >> node->WorkHour;
			if (node->age <= 0)break;
			if (head == NULL)
			{
				head = node;
				head->next = NULL;
			}
			else
			{
				Date* tail;
				tail = head;
				while (tail->next != NULL)
				{
					tail = tail->next;
				}
				node->next = NULL;
				tail->next = node;
			}
		}
		MessageBox(_T("读入成功!"), _T("提示"));
	}
	read.close();
	// TODO: 在此添加控件通知处理程序代码
}


void SystemDlg::OnBnClickedButton5()
{
	Edit dlg6;
	dlg6.DoModal();
	// TODO: 在此添加控件通知处理程序代码
}


void SystemDlg::OnBnClickedButton7()
{
	AddWH dlg7;
	dlg7.DoModal();
	// TODO: 在此添加控件通知处理程序代码
}


void SystemDlg::OnBnClickedButton10()
{
	Addall dlg8;
	dlg8.DoModal();
	// TODO: 在此添加控件通知处理程序代码
}
