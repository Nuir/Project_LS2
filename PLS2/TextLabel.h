#pragma once
#include "afxwin.h"


// TextLabel ��ȭ �����Դϴ�.

class TextLabel : public CDialog
{
	DECLARE_DYNAMIC(TextLabel)

public:
	TextLabel(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~TextLabel();

// ��ȭ ���� �������Դϴ�.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
public:
	CString m_str;
	virtual BOOL OnInitDialog();
	virtual void OnOK();
	afx_msg void OnBnClickedOk();
	char m_label2;
};
