#pragma once


// Addall 对话框

class Addall : public CDialogEx
{
	DECLARE_DYNAMIC(Addall)

public:
	Addall(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~Addall();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG9 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
};
