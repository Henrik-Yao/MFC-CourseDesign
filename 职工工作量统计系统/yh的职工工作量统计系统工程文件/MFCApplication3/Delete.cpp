// Delete.cpp: 实现文件
//

#include "pch.h"
#include "MFCApplication3.h"
#include "Delete.h"
#include "afxdialogex.h"
#include"Date.h"
#include<string>
using namespace std;

// Delete 对话框

IMPLEMENT_DYNAMIC(Delete, CDialogEx)

Delete::Delete(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG3, pParent)
{

}

Delete::~Delete()
{
}

void Delete::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(Delete, CDialogEx)
	ON_BN_CLICKED(IDOK, &Delete::OnBnClickedOk)
	ON_EN_CHANGE(IDC_EDIT_DEID, &Delete::OnEnChangeEditDeid)
END_MESSAGE_MAP()


// Delete 消息处理程序


void Delete::OnBnClickedOk()
{
	Date* p1, * p2;
	p1 = head;
	p2 = p1->next;
	CString x;
	GetDlgItemText(IDC_EDIT_DEID, x);
	string wantid(CW2A(x.GetString()));
	int flag = 0;
	while (true)
	{
		if (p1->ID==wantid)break;
		p1 = p1->next;
		if (p1 == NULL)break;
	}
	if (p1 == head && p1->ID == wantid)
	{
		head = head->next;
		delete p1;
		flag++;
	}
	else if (p1 == NULL)
	{
		flag = 0;
	}
	else if (p1->next == NULL)
	{
		while (p2->next != p1)
		{
			p2 = p2->next;
		}
		p2->next = NULL;
		delete p1;
		flag++;
	}
	else
	{
		while (p2->next != p1)
		{
			p2 = p2->next;
		}
		p2->next = p1->next;
		delete p1;
		flag++;
	}
	if (flag == 0)
	{
		MessageBox(_T("删除失败，查无此人!"), _T("提示"));
	}
	else
	{
		MessageBox(_T("删除成功!"), _T("提示"));
	}
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnOK();
}


void Delete::OnEnChangeEditDeid()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}
