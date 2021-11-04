#pragma once


// Find 对话框

class Find : public CDialogEx
{
	DECLARE_DYNAMIC(Find)

public:
	Find(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~Find();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG4 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
};
