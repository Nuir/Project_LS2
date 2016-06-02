
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
	int l = 0;
	int max = 0;
	int gate = -1;
	int direct = 0;
	CPoint pointofpif;
	if (ar.IsStoring())
	{
		// TODO: ���⿡ ���� �ڵ带 �߰��մϴ�.
		if (ls.pif[0][0].serializegate != lib) {
			ar << 0;
		}
		else {
			ar << 1;
		}
			for (int i = 0; i < INDEX; i++)
				for (int j = 0; j < INDEX; j++) {
					gate = ls.pif[i][j].serializegate;
					ar << gate;
					ar << ls.pif[i][j].direct;
				}
			ls.line.Serialize(ar);
			ar << ls.count_line;
	}
	else
	{
		// TODO: ���⿡ �ε� �ڵ带 �߰��մϴ�.
		ar >> l;
		if(l == 0){
		for (int i = 0; i < INDEX; i++)
			for (int j = 0; j < INDEX; j++) {
				ar >> gate;
				ar >> direct;
				ls.pif[i][j].serializegate = (WhatGate)gate;
				pointofpif = { i,j };
				switch (ls.pif[i][j].serializegate) {
				case input:
					ls.count_input++;
					ls.create_input(&(ls.in[ls.count_input]), pointofpif);
					ls.rotate_input(&(ls.in[ls.count_input]), (Direct)direct);
					break;
				case output:
					ls.count_output++;
					ls.pif[i][j].value;
					ls.create_output(&ls.out[ls.count_output], pointofpif);
					ls.rotate_output(&ls.out[ls.count_output], (Direct)direct);
					break;
				case and:
					ls.count_and++;
					ls.pif[i][j].and = ls.count_and;
					ls.create_and(&ls.and[ls.count_and], pointofpif); // ����� �Լ� ȣ��.
					ls.rotate_and(&ls.and[ls.count_and], (Direct)direct);
					break;
				case xor:
					ls.count_xor++;
					ls.pif[i][j].xor = ls.count_xor;
					ls.create_xor(&ls.xor[ls.count_xor], pointofpif); // ����� �Լ� ȣ��.
					ls.rotate_xor(&ls.xor[ls.count_xor], (Direct)direct);
					break;
				case nor:
					ls.count_nor++;
					ls.pif[i][j].nor = ls.count_nor;
					ls.create_nor(&ls.nor[ls.count_nor], pointofpif); // ����� �Լ� ȣ��.
					ls.rotate_nor(&ls.nor[ls.count_nor], (Direct)direct);
					break;
				case nand:
					ls.count_nand++;
					ls.pif[i][j].nand = ls.count_nand;
					ls.create_nand(&ls.nand[ls.count_nand], pointofpif); // ����� �Լ� ȣ��.
					ls.rotate_nand(&ls.nand[ls.count_nand], (Direct)direct);
					break;
				case or :
					ls.count_or++;
					ls.pif[i][j]. or = ls.count_or;
					ls.create_or(&ls. or [ls.count_or], pointofpif);
					ls.rotate_or(&ls. or [ls.count_or], (Direct)direct);
					break;
				case not:
					ls.count_not++;
					ls.pif[i][j].not = ls.count_not;
					ls.create_not(&ls. not [ls.count_not], pointofpif);
					ls.rotate_not(&ls. not [ls.count_not], (Direct)direct);
					break;
				case tff:
					ls.count_tff++;
					ls.create_tff(&ls.tff[ls.count_tff], pointofpif);
					ls.rotate_tff(&ls.tff[ls.count_tff], (Direct)direct);
					break;
				case lsclock:
					ls.count_clock++;
					ls.create_clock(&ls.clock[ls.count_clock], pointofpif);
					ls.rotate_clock(&ls.clock[ls.count_clock], (Direct)direct);
					break;
				case dff:
					ls.count_dff++;
					ls.create_dff(&ls.dff[ls.count_dff], pointofpif);
					ls.rotate_dff(&ls.dff[ls.count_dff], (Direct)direct);
					break;
				case jkff:
					ls.count_jkff++;
					ls.create_jkff(&ls.jkff[ls.count_jkff], pointofpif);
					ls.rotate_jkff(&ls.jkff[ls.count_jkff], (Direct)direct);
					break;
				case seg7:
					ls.count_seg7++;
					ls.create_seg7(&ls.seg7[ls.count_seg7], pointofpif);
					ls.rotate_seg7(&ls.seg7[ls.count_seg7], (Direct)direct);
				}
			}
		ls.line.Serialize(ar);
		ar >> max;
		for (int i = 0; i <= max; i++) {
			ls.count_line++;
			ls.create_line(ls.line[i].firstPt, ls.line[i].secondPt, i);
		}
		}
		else {
			for (int i = 0; i < INDEX; i++)
				for (int j = 0; j < INDEX; j++) {
					ar >> gate;
					ar >> direct;
					library.pif[i][j].serializegate = (WhatGate)gate;
					pointofpif = { i,j };
					switch (library.pif[i][j].serializegate) {
					case input:
						library.count_input++;
						library.create_input(&(library.in[library.count_input]), pointofpif);
						library.rotate_input(&(library.in[library.count_input]), (Direct)direct);
						break;
					case output:
						library.count_output++;
						library.pif[i][j].value;
						library.create_output(&library.out[library.count_output], pointofpif);
						library.rotate_output(&library.out[library.count_output], (Direct)direct);
						break;
					case and:
						library.count_and++;
						library.pif[i][j].and = library.count_and;
						library.create_and(&library.and[library.count_and], pointofpif); // ����� �Լ� ȣ��.
						library.rotate_and(&library.and[library.count_and], (Direct)direct);
						break;
					case xor:
						library.count_xor++;
						library.pif[i][j].xor = library.count_xor;
						library.create_xor(&library.xor[library.count_xor], pointofpif); // ����� �Լ� ȣ��.
						library.rotate_xor(&library.xor[library.count_xor], (Direct)direct);
						break;
					case nor:
						library.count_nor++;
						library.pif[i][j].nor = library.count_nor;
						library.create_nor(&library.nor[library.count_nor], pointofpif); // ����� �Լ� ȣ��.
						library.rotate_nor(&library.nor[library.count_nor], (Direct)direct);
						break;
					case nand:
						library.count_nand++;
						library.pif[i][j].nand = library.count_nand;
						library.create_nand(&library.nand[library.count_nand], pointofpif); // ����� �Լ� ȣ��.
						library.rotate_nand(&library.nand[library.count_nand], (Direct)direct);
						break;
					case or :
						library.count_or++;
						library.pif[i][j]. or = library.count_or;
						library.create_or(&library. or [library.count_or], pointofpif);
						library.rotate_or(&library. or [library.count_or], (Direct)direct);
						break;
					case not:
						library.count_not++;
						library.pif[i][j].not = library.count_not;
						library.create_not(&library. not [library.count_not], pointofpif);
						library.rotate_not(&library. not [library.count_not], (Direct)direct);
						break;
					case tff:
						library.count_tff++;
						library.create_tff(&library.tff[library.count_tff], pointofpif);
						library.rotate_tff(&library.tff[library.count_tff], (Direct)direct);
						break;
					case lsclock:
						library.count_clock++;
						library.create_clock(&library.clock[library.count_clock], pointofpif);
						library.rotate_clock(&library.clock[library.count_clock], (Direct)direct);
						break;
					case dff:
						library.count_dff++;
						library.create_dff(&library.dff[library.count_dff], pointofpif);
						library.rotate_dff(&library.dff[library.count_dff], (Direct)direct);
						break;
					case jkff:
						library.count_jkff++;
						library.create_jkff(&library.jkff[library.count_jkff], pointofpif);
						library.rotate_jkff(&library.jkff[library.count_jkff], (Direct)direct);
						break;
					case seg7:
						library.count_seg7++;
						library.create_seg7(&library.seg7[library.count_seg7], pointofpif);
						library.rotate_seg7(&library.seg7[library.count_seg7], (Direct)direct);
					}
				}
			library.line.Serialize(ar);
			ar >> max;
			for (int i = 0; i <= max; i++) {
				library.count_line++;
				library.create_line(library.line[i].firstPt, library.line[i].secondPt, i);
			}
		}
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
