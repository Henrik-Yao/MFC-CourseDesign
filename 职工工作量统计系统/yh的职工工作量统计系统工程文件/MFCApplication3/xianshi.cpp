// xianshi.cpp: 实现文件
//

#include "pch.h"
#include "MFCApplication3.h"
#include "xianshi.h"
#include "afxdialogex.h"
#include"Date.h"


// xianshi 对话框

IMPLEMENT_DYNAMIC(xianshi, CDialogEx)

xianshi::xianshi(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG6, pParent)
{

}

xianshi::~xianshi()
{
}

void xianshi::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_list2);
}


BEGIN_MESSAGE_MAP(xianshi, CDialogEx)
END_MESSAGE_MAP()


BOOL xianshi::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	m_list2.InsertColumn(0, _T("姓名"), 0, 100);
	m_list2.InsertColumn(1, _T("职工号"), 0, 100);
	m_list2.InsertColumn(2, _T("年龄"), 0, 100);
	m_list2.InsertColumn(3, _T("部门"), 0, 100);
	m_list2.InsertColumn(4, _T("联系方式"), 0, 100);
	m_list2.InsertColumn(5, _T("工作量"), 0, 100);
	CString xm, zgh, bm, lxfs;
	CString gzl, nl;
	for (Date* node = head; node != NULL; node = node->next)
	{
		int i = 0;
		xm = node->name.c_str();
		zgh = node->ID.c_str();
		bm = node->Department.c_str();
		lxfs = node->Contact.c_str();
		gzl.Format(_T("%d"), node->WorkHour);
		nl.Format(_T("%d"), node->age);
		m_list2.InsertItem(i, xm);
		m_list2.SetItemText(i, 1, zgh);
		m_list2.SetItemText(i, 2, nl);
		m_list2.SetItemText(i, 3, bm);
		m_list2.SetItemText(i, 4, lxfs);
		m_list2.SetItemText(i, 5, gzl);
		i++;
	}
	return true;
}
// xianshi 消息处理程序
