
// PLS2Doc.cpp : CPLS2Doc Ŭ������ ����
//

#include "stdafx.h"
// SHARED_HANDLERS�� �̸� ����, ����� �׸� �� �˻� ���� ó���⸦ �����ϴ� ATL ������Ʈ���� ������ �� ������
// �ش� ������Ʈ�� ���� �ڵ带 �����ϵ��� �� �ݴϴ�.
#ifndef SHARED_HANDLERS
#include "PLS2.h"
#endif

#include "PLS2Doc.h"

#include <propkey.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CPLS2Doc

IMPLEMENT_DYNCREATE(CPLS2Doc, CDocument)

BEGIN_MESSAGE_MAP(CPLS2Doc, CDocument)
END_MESSAGE_MAP()


// CPLS2Doc ����/�Ҹ�

CPLS2Doc::CPLS2Doc()
{
	// TODO: ���⿡ ��ȸ�� ���� �ڵ带 �߰��մϴ�.

}

CPLS2Doc::~CPLS2Doc()
{
}

BOOL CPLS2Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: ���⿡ ���ʱ�ȭ �ڵ带 �߰��մϴ�.
	ls.AllPointClear();
	// SDI ������ �� ������ �ٽ� ����մϴ�.

	return TRUE;
}




// CPLS2Doc serialization

void CPLS2Doc::Serialize(CArchive& ar)
{
	int gate = -1;
	CPoint pointofpif;
	if (ar.IsStoring())
	{
		// TODO: ���⿡ ���� �ڵ带 �߰��մϴ�.
		for (int i = 0; i < INDEX; i++)
			for (int j = 0; j < INDEX; j++) {
				gate = ls.pif[i][j].serializegate;
				ar << gate;
			}
		ls.line.Serialize(ar);
	}
	else
	{
		// TODO: ���⿡ �ε� �ڵ带 �߰��մϴ�.
		for (int i = 0; i < INDEX; i++)
			for (int j = 0; j < INDEX; j++) {
				ar >> gate;
				ls.pif[i][j].serializegate = (WhatGate)gate;
				pointofpif = { i,j };
				switch (ls.pif[i][j].serializegate) {
				case input:
					ls.count_input++;
					ls.create_input(&(ls.in[ls.count_input]), pointofpif);
					break;
				case output:
					ls.count_output++;
					ls.pif[i][j].value;
					ls.create_output(&ls.out[ls.count_output], pointofpif);
					break;
				case and:
					ls.count_and++;
					ls.create_and(&ls.and[ls.count_and], pointofpif); // ����� �Լ� ȣ��.
					break;
				case xor:
					ls.count_xor++;
					ls.pif[i][j].xor = ls.count_xor;
					ls.create_xor(&ls.xor[ls.count_xor], pointofpif); // ����� �Լ� ȣ��.
					break;
				case nor:
					ls.count_nor++;
					ls.create_nor(&ls.nor[ls.count_nor], pointofpif); // ����� �Լ� ȣ��.
					break;
				case nand:
					ls.count_nand++;
					ls.create_nand(&ls.nand[ls.count_nand], pointofpif); // ����� �Լ� ȣ��.
					break;
				case or :
					ls.count_or++;
					ls.pif[i][j]. or = ls.count_or;
					ls.create_or(&ls. or [ls.count_or], pointofpif);
					break;
				case not:
					ls.count_not++;
					ls.pif[i][j].not = ls.count_not;
					ls.create_not(&ls. not [ls.count_not], pointofpif);
					break;
				case tff:
					ls.count_tff++;
					ls.create_tff(&ls.tff[ls.count_tff], pointofpif);
					break;
				case lsclock:
					ls.count_clock++;
					ls.create_clock(&ls.clock[ls.count_clock], pointofpif);
					//SetTimer(ls.count_clock, 500, NULL);
					break;
				case dff:
					ls.count_dff++;
					ls.create_dff(&ls.dff[ls.count_dff], pointofpif);
					break;
				case jkff:
					ls.count_jkff++;
					ls.create_jkff(&ls.jkff[ls.count_jkff], pointofpif);
					break;
				}
			}
		ls.line.Serialize(ar);
	}
}

#ifdef SHARED_HANDLERS

// ����� �׸��� �����մϴ�.
void CPLS2Doc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
{
	// ������ �����͸� �׸����� �� �ڵ带 �����Ͻʽÿ�.
	dc.FillSolidRect(lprcBounds, RGB(255, 255, 255));

	CString strText = _T("TODO: implement thumbnail drawing here");
	LOGFONT lf;

	CFont* pDefaultGUIFont = CFont::FromHandle((HFONT) GetStockObject(DEFAULT_GUI_FONT));
	pDefaultGUIFont->GetLogFont(&lf);
	lf.lfHeight = 36;

	CFont fontDraw;
	fontDraw.CreateFontIndirect(&lf);

	CFont* pOldFont = dc.SelectObject(&fontDraw);
	dc.DrawText(strText, lprcBounds, DT_CENTER | DT_WORDBREAK);
	dc.SelectObject(pOldFont);
}

// �˻� ó���⸦ �����մϴ�.
void CPLS2Doc::InitializeSearchContent()
{
	CString strSearchContent;
	// ������ �����Ϳ��� �˻� �������� �����մϴ�.
	// ������ �κ��� ";"�� ���еǾ�� �մϴ�.

	// ��: strSearchContent = _T("point;rectangle;circle;ole object;");
	SetSearchContent(strSearchContent);
}

void CPLS2Doc::SetSearchContent(const CString& value)
{
	if (value.IsEmpty())
	{
		RemoveChunk(PKEY_Search_Contents.fmtid, PKEY_Search_Contents.pid);
	}
	else
	{
		CMFCFilterChunkValueImpl *pChunk = NULL;
		ATLTRY(pChunk = new CMFCFilterChunkValueImpl);
		if (pChunk != NULL)
		{
			pChunk->SetTextValue(PKEY_Search_Contents, value, CHUNK_TEXT);
			SetChunkValue(pChunk);
		}
	}
}

#endif // SHARED_HANDLERS

// CPLS2Doc ����

#ifdef _DEBUG
void CPLS2Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CPLS2Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CPLS2Doc ���
