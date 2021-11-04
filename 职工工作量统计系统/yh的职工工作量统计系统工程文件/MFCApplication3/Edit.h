#pragma once


// Edit 对话框

class Edit : public CDialogEx
{
	DECLARE_DYNAMIC(Edit)

public:
	Edit(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~Edit();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG7 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
};
