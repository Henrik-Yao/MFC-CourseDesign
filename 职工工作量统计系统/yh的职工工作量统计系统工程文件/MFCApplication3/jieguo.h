#pragma once


// jieguo 对话框

class jieguo : public CDialogEx
{
	DECLARE_DYNAMIC(jieguo)

public:
	jieguo(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~jieguo();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG5 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	virtual BOOL OnInitDialog();
	CListCtrl m_list;
};
