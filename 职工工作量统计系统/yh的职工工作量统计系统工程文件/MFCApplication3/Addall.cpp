// Addall.cpp: 实现文件
//

#include "pch.h"
#include "MFCApplication3.h"
#include "Addall.h"
#include "afxdialogex.h"
#include"Date.h"
#include<string>
using namespace std;


// Addall 对话框

IMPLEMENT_DYNAMIC(Addall, CDialogEx)

Addall::Addall(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG9, pParent)
{

}

Addall::~Addall()
{
}

void Addall::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(Addall, CDialogEx)
	ON_BN_CLICKED(IDOK, &Addall::OnBnClickedOk)
END_MESSAGE_MAP()


// Addall 消息处理程序


void Addall::OnBnClickedOk()
{
	int newwh = GetDlgItemInt(IDC_EDIT_WorkHour);
	int flag = 0;
	for (Date* p = head; p != NULL; p = p->next)
	{
		p->WorkHour += newwh;
		flag++;	
	}
	if (flag == 0)MessageBox(_T("查无此人!"), _T("提示"));
	else MessageBox(_T("添加成功!"), _T("提示"));
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnOK();
}
