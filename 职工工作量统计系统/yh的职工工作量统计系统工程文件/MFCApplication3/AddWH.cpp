// AddWH.cpp: 实现文件
//

#include "pch.h"
#include "MFCApplication3.h"
#include "AddWH.h"
#include "afxdialogex.h"
#include"Date.h"


// AddWH 对话框

IMPLEMENT_DYNAMIC(AddWH, CDialogEx)

AddWH::AddWH(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG8, pParent)
{

}

AddWH::~AddWH()
{
}

void AddWH::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(AddWH, CDialogEx)
	ON_BN_CLICKED(IDOK, &AddWH::OnBnClickedOk)
END_MESSAGE_MAP()


// AddWH 消息处理程序


void AddWH::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	CString x;
	GetDlgItemText(IDC_EDIT_ID, x);
	string strl(CW2A(x.GetString()));
	int newwh=GetDlgItemInt(IDC_EDIT_WorkHour);
	int flag = 0;
	for (Date* p = head; p != NULL; p = p->next)
	{
		if (p->ID == strl)
		{
			p->WorkHour += newwh;
			MessageBox(_T("添加成功!"), _T("提示"));
			flag++;
		}
	}
	if (flag == 0)MessageBox(_T("查无此人!"), _T("提示"));
	CDialogEx::OnOK();
}
