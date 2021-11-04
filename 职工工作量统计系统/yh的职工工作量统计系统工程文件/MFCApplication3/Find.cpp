// Find.cpp: 实现文件
//

#include "pch.h"
#include "MFCApplication3.h"
#include "Find.h"
#include "afxdialogex.h"
#include"Date.h"
#include<string>
#include"jieguo.h"
using namespace std;


// Find 对话框

IMPLEMENT_DYNAMIC(Find, CDialogEx)

Find::Find(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG4, pParent)
{

}

Find::~Find()
{
}

void Find::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(Find, CDialogEx)
	ON_BN_CLICKED(IDOK, &Find::OnBnClickedOk)
END_MESSAGE_MAP()


// Find 消息处理程序


void Find::OnBnClickedOk()
{
	CString x;
	GetDlgItemText(IDC_EDIT_LOOK, x);
	string want(CW2A(x.GetString()));
	Date* node = head;
	int flag = 0;
	for (; node != NULL; node = node->next)
	{
		if (node->name == want||node->ID==want)
		{
			jieguo dlg3;
			dlg3.DoModal();
			flag ++;
		}
	}
	if (flag == 0)
	{
		MessageBox(_T("查无此人!"), _T("提示"));
	}
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnOK();
}
