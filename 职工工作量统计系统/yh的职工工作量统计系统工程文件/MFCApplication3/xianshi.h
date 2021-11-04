#pragma once


// xianshi 对话框

class xianshi : public CDialogEx
{
	DECLARE_DYNAMIC(xianshi)

public:
	xianshi(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~xianshi();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG6 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	
	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	CListCtrl m_list2;
};
