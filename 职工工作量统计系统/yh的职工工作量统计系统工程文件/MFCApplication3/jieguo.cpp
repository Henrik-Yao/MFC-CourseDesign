// jieguo.cpp: 实现文件
//

#include "pch.h"
#include "MFCApplication3.h"
#include "jieguo.h"
#include "afxdialogex.h"
#include<string>
#include"Date.h"


// jieguo 对话框

IMPLEMENT_DYNAMIC(jieguo, CDialogEx)

jieguo::jieguo(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG5, pParent)
{

}

jieguo::~jieguo()
{
}

void jieguo::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_list);
}


BEGIN_MESSAGE_MAP(jieguo, CDialogEx)
	ON_BN_CLICKED(IDOK, &jieguo::OnBnClickedOk)
END_MESSAGE_MAP()


// jieguo 消息处理程序

BOOL jieguo::OnInitDialog()
{
	CString cs;
	CDialog* pdlg = (CDialog*)GetParent();
	pdlg->GetDlgItemText(IDC_EDIT_LOOK, cs);
	std::string strl(CW2A(cs.GetString()));
	Date* node = head;
	for (; node != NULL; node = node->next)
	{
		if (node->name ==strl || node->ID == strl)break;
	}
	CDialogEx::OnInitDialog();
	m_list.InsertColumn(0, _T("姓名"),0,100);
	m_list.InsertColumn(1, _T("职工号"),0,100);
	m_list.InsertColumn(2, _T("年龄"), 0, 100);
	m_list.InsertColumn(3, _T("部门"), 0, 100);
	m_list.InsertColumn(4, _T("联系方式"), 0, 100);
	m_list.InsertColumn(5, _T("工作量"), 0, 100);
	CString xm, zgh, bm, lxfs;
	CString gzl, nl;
	xm = node->name.c_str();
	zgh = node->ID.c_str();
	bm = node->Department.c_str();
	lxfs = node->Contact.c_str();
	gzl.Format(_T("%d"), node->WorkHour);
	nl.Format(_T("%d"), node->age);
	m_list.InsertItem(0, xm);
	m_list.SetItemText(0,1, zgh);
	m_list.SetItemText(0, 2, nl);
	m_list.SetItemText(0, 3, bm);
	m_list.SetItemText(0, 4, lxfs);
	m_list.SetItemText(0, 5, gzl);
	return true;
}

void jieguo::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnOK();
}
