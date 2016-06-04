// DlgSelLib.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "PLS2.h"
#include "DlgSelLib.h"
#include "afxdialogex.h"


// DlgSelLib ��ȭ �����Դϴ�.

IMPLEMENT_DYNAMIC(DlgSelLib, CDialogEx)

DlgSelLib::DlgSelLib(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG2, pParent)
{

}

DlgSelLib::~DlgSelLib()
{
}

void DlgSelLib::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_list);
}


BEGIN_MESSAGE_MAP(DlgSelLib, CDialogEx)
END_MESSAGE_MAP()


// DlgSelLib �޽��� ó�����Դϴ�.


BOOL DlgSelLib::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  ���⿡ �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
	CFileFind finder;
	CString s;
	BOOL bWorking = finder.FindFile(_T("res\\lib_*.mdi"));

	while (bWorking) {
		bWorking = finder.FindNextFile();
		//TRACE(_T("[%s]\n"), (LPCTSTR)finder.GetFileName()); //���丮�ΰ�� [] �� ������.
		m_list.AddString(finder.GetFileTitle());
	}

	m_list.SetCurSel(0); // ù��° �׸��� ����Ʈ�� ���õǾ��ְ� ��.
	SetWindowText(_T("���̺귯�� ����(lib_*.mdi)")); // ���̾�α� â �̸�.

	return TRUE;  // return TRUE unless you set the focus to a control
				  // ����: OCX �Ӽ� �������� FALSE�� ��ȯ�ؾ� �մϴ�.
}
