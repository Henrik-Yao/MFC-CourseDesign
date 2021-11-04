#pragma once
#include<iostream>
#include "SystemDlg.h"

// Add 对话框

class Add : public CDialogEx
{
	DECLARE_DYNAMIC(Add)

public:
	Add(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~Add();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG2 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:

	afx_msg void OnEnChangeEdit2();
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedCancel();
};
