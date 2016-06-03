// TextLabel.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "PLS2.h"
#include "TextLabel.h"
#include "afxdialogex.h"


// TextLabel ��ȭ �����Դϴ�.

IMPLEMENT_DYNAMIC(TextLabel, CDialog)

TextLabel::TextLabel(CWnd* pParent /*=NULL*/)
	: CDialog(IDD_DIALOG1, pParent)
	, m_label2(0)
{

}

TextLabel::~TextLabel()
{
}

void TextLabel::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_str);
}


BEGIN_MESSAGE_MAP(TextLabel, CDialog)
	ON_BN_CLICKED(IDOK, &TextLabel::OnBnClickedOk)
END_MESSAGE_MAP()


// TextLabel �޽��� ó�����Դϴ�.


BOOL TextLabel::OnInitDialog()
{
	CDialog::OnInitDialog();
	SetDlgItemText(IDC_EDIT1, m_str);

	return TRUE;  // return TRUE unless you set the focus to a control
				  // ����: OCX �Ӽ� �������� FALSE�� ��ȯ�ؾ� �մϴ�.
}


void TextLabel::OnOK()
{
	GetDlgItemText(IDC_EDIT1, m_str);
	CDialog::OnOK();
}


void TextLabel::OnBnClickedOk()
{
	EndDialog(IDC_EDIT1);
	CDialog::OnOK();
}
