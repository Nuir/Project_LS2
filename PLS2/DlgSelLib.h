#pragma once
#include "afxwin.h"


// DlgSelLib ��ȭ �����Դϴ�.

class DlgSelLib : public CDialogEx
{
	DECLARE_DYNAMIC(DlgSelLib)

public:
	DlgSelLib(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~DlgSelLib();

// ��ȭ ���� �������Դϴ�.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG2 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	CListBox m_list;
	CString m_selectedFile;
};
