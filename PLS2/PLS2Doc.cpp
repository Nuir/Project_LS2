
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
	CString str;
	int l = 0;
	int max = 0;
	int gate = -1;
	int direct = 0;
	CPoint pointofpif;
	CString name;
	if (ar.IsStoring())//�ϼ�
	{
		// TODO: ���⿡ ���� �ڵ带 �߰��մϴ�.
			
		if(ls.readylibaray == 0){
			ar << 1;
			for (int i = 0; i < INDEX; i++)
				for (int j = 0; j < INDEX; j++) {
					gate = ls.pif[i][j].serializegate;
					ar << gate;
					ar << ls.pif[i][j].direct;
					ar << ls.pif[i][j].name;
				}
			ls.line.Serialize(ar);
			ar << ls.count_line;
			if (ls.existlibrary == 0) {
				ar << 0;
			}
			else {
				ar << 1;
				for (int i = 0; i < INDEX; i++)
					for (int j = 0; j < INDEX; j++) {
						gate = library.pif[i][j].serializegate;
						ar << gate;
						ar << library.pif[i][j].direct;
						ar << ls.pif[i][j].name;
					}
				library.line.Serialize(ar);
				ar << library.count_line;
			}
		}
		else {
			ar << 0;
			ar << 1;
			for (int i = 0; i < INDEX; i++)
				for (int j = 0; j < INDEX; j++) {
					gate = ls.pif[i][j].serializegate;
					ar << gate;
					ar << ls.pif[i][j].direct;
					ar << ls.pif[i][j].name;
				}
			ls.line.Serialize(ar);
			ar << ls.count_line;
		}
			
	}
	else//�ϼ�
	{
		// TODO: ���⿡ �ε� �ڵ带 �߰��մϴ�.
		ar >> l;
		if(l == 1){
		for (int i = 0; i < INDEX; i++)
			for (int j = 0; j < INDEX; j++) {
				ar >> gate;
				ar >> direct;
				ar >> name;
				ls.pif[i][j].direct = (Direct)direct;
				ls.pif[i][j].serializegate = (WhatGate)gate;
				pointofpif = { i,j };
				switch (ls.pif[i][j].serializegate) {
				case input:
					ls.count_input++;
					ls.pif[i][j].input = ls.count_input;
					ls.create_input(&(ls.in[ls.count_input]), pointofpif);
					ls.rotate_input(&(ls.in[ls.count_input]), (Direct)direct);
					ls.in[ls.count_input].name = name;
					break;
				case output:
					ls.count_output++;
					ls.pif[i][j].output = ls.count_output;
					ls.create_output(&ls.out[ls.count_output], pointofpif);
					ls.rotate_output(&ls.out[ls.count_output], (Direct)direct);
					ls.out[ls.count_output].name = name;
					break;
				case and:
					ls.count_and++;
					ls.pif[i][j].and = ls.count_and;
					ls.create_and(&ls.and[ls.count_and], pointofpif); // ����� �Լ� ȣ��.
					ls.rotate_and(&ls.and[ls.count_and], (Direct)direct);
					ls.and[ls.count_and].name = name;
					break;
				case xor:
					ls.count_xor++;
					ls.pif[i][j].xor = ls.count_xor;
					ls.create_xor(&ls.xor[ls.count_xor], pointofpif); // ����� �Լ� ȣ��.
					ls.rotate_xor(&ls.xor[ls.count_xor], (Direct)direct);
					ls.xor[ls.count_xor].name = name;
					break;
				case nor:
					ls.count_nor++;
					ls.pif[i][j].nor = ls.count_nor;
					ls.create_nor(&ls.nor[ls.count_nor], pointofpif); // ����� �Լ� ȣ��.
					ls.rotate_nor(&ls.nor[ls.count_nor], (Direct)direct);
					ls.nor[ls.count_nor].name = name;
					break;
				case nand:
					ls.count_nand++;
					ls.pif[i][j].nand = ls.count_nand;
					ls.create_nand(&ls.nand[ls.count_nand], pointofpif); // ����� �Լ� ȣ��.
					ls.rotate_nand(&ls.nand[ls.count_nand], (Direct)direct);
					ls.nand[ls.count_nand].name = name;
					break;
				case or :
					ls.count_or++;
					ls.pif[i][j]. or = ls.count_or;
					ls.create_or(&ls. or [ls.count_or], pointofpif);
					ls.rotate_or(&ls. or [ls.count_or], (Direct)direct);
					ls. or [ls.count_or].name = name;
					break;
				case not:
					ls.count_not++;
					ls.pif[i][j].not = ls.count_not;
					ls.create_not(&ls. not [ls.count_not], pointofpif);
					ls.rotate_not(&ls. not [ls.count_not], (Direct)direct);
					ls. not [ls.count_not].name = name;
					break;
				case tff:
					ls.count_tff++;
					ls.create_tff(&ls.tff[ls.count_tff], pointofpif);
					ls.rotate_tff(&ls.tff[ls.count_tff], (Direct)direct);
					ls.tff[ls.count_tff].name = name;
					break;
				case lsclock:
					ls.count_clock++;
					ls.create_clock(&ls.clock[ls.count_clock], pointofpif);
					ls.rotate_clock(&ls.clock[ls.count_clock], (Direct)direct);
					ls.clock[ls.count_clock].name = name;
					break;
				case dff:
					ls.count_dff++;
					ls.create_dff(&ls.dff[ls.count_dff], pointofpif);
					ls.rotate_dff(&ls.dff[ls.count_dff], (Direct)direct);
					ls.dff[ls.count_dff].name = name;
					break;
				case jkff:
					ls.count_jkff++;
					ls.create_jkff(&ls.jkff[ls.count_jkff], pointofpif);
					ls.rotate_jkff(&ls.jkff[ls.count_jkff], (Direct)direct);
					ls.jkff[ls.count_jkff].name = name;
					break;
				case seg7:
					ls.count_seg7++;
					ls.create_seg7(&ls.seg7[ls.count_seg7], pointofpif);
					ls.rotate_seg7(&ls.seg7[ls.count_seg7], (Direct)direct);
					ls.seg7[ls.count_seg7].name = name;
					break;
				case dcd:
					ls.count_dcd++;
					ls.create_dcd(&ls.dcd[ls.count_dcd], pointofpif);
					//ls.rotate_dcd(&ls.dcd[ls.count_dcd], (Direct)direct);
					ls.dcd[ls.count_dcd].name = name;
					break;
				case lib:
					ls.count_lib++;
					ls.create_lib(&ls.lib[ls.count_lib], pointofpif);
					ls.rotate_lib(&ls.lib[ls.count_lib], (Direct)direct);
					ls.lib[ls.count_lib].name = name;
					break;
				}
			}
			ls.line.Serialize(ar);
			ar >> max;
			for (int i = 0; i <= max; i++) {
				ls.count_line++;
				ls.create_line(ls.line[i].firstPt, ls.line[i].secondPt, i);
			}
		}
		ar >> l;
		if(l == 1) {
			ls.existlibrary = 1;
			for (int i = 0; i < INDEX; i++)
				for (int j = 0; j < INDEX; j++) {
					ar >> gate;
					ar >> direct;
					ar >> name;
					library.pif[i][j].serializegate = (WhatGate)gate;
					pointofpif = { i,j };
					switch (library.pif[i][j].serializegate) {
					case input:
						ls.count_input++;
						ls.pif[i][j].input = ls.count_input;
						ls.create_input(&(ls.in[ls.count_input]), pointofpif);
						ls.rotate_input(&(ls.in[ls.count_input]), (Direct)direct);
						ls.in[ls.count_input].name = name;
						break;
					case output:
						ls.count_output++;
						ls.pif[i][j].output = ls.count_output;
						ls.create_output(&ls.out[ls.count_output], pointofpif);
						ls.rotate_output(&ls.out[ls.count_output], (Direct)direct);
						ls.out[ls.count_output].name = name;
						break;
					case and:
						ls.count_and++;
						ls.pif[i][j].and = ls.count_and;
						ls.create_and(&ls.and[ls.count_and], pointofpif); // ����� �Լ� ȣ��.
						ls.rotate_and(&ls.and[ls.count_and], (Direct)direct);
						ls.and[ls.count_and].name = name;
						break;
					case xor:
						ls.count_xor++;
						ls.pif[i][j].xor = ls.count_xor;
						ls.create_xor(&ls.xor[ls.count_xor], pointofpif); // ����� �Լ� ȣ��.
						ls.rotate_xor(&ls.xor[ls.count_xor], (Direct)direct);
						ls.xor[ls.count_xor].name = name;
						break;
					case nor:
						ls.count_nor++;
						ls.pif[i][j].nor = ls.count_nor;
						ls.create_nor(&ls.nor[ls.count_nor], pointofpif); // ����� �Լ� ȣ��.
						ls.rotate_nor(&ls.nor[ls.count_nor], (Direct)direct);
						ls.nor[ls.count_nor].name = name;
						break;
					case nand:
						ls.count_nand++;
						ls.pif[i][j].nand = ls.count_nand;
						ls.create_nand(&ls.nand[ls.count_nand], pointofpif); // ����� �Լ� ȣ��.
						ls.rotate_nand(&ls.nand[ls.count_nand], (Direct)direct);
						ls.nand[ls.count_nand].name = name;
						break;
					case or :
						ls.count_or++;
						ls.pif[i][j]. or = ls.count_or;
						ls.create_or(&ls. or [ls.count_or], pointofpif);
						ls.rotate_or(&ls. or [ls.count_or], (Direct)direct);
						ls. or [ls.count_or].name = name;
						break;
					case not:
						ls.count_not++;
						ls.pif[i][j].not = ls.count_not;
						ls.create_not(&ls. not [ls.count_not], pointofpif);
						ls.rotate_not(&ls. not [ls.count_not], (Direct)direct);
						ls. not [ls.count_not].name = name;
						break;
					case tff:
						ls.count_tff++;
						ls.create_tff(&ls.tff[ls.count_tff], pointofpif);
						ls.rotate_tff(&ls.tff[ls.count_tff], (Direct)direct);
						ls.tff[ls.count_tff].name = name;
						break;
					case lsclock:
						ls.count_input++;
						ls.pif[i][j].input = ls.count_input;
						ls.create_input(&(ls.in[ls.count_input]), pointofpif);
						ls.rotate_input(&(ls.in[ls.count_input]), (Direct)direct);
						ls.in[ls.count_input].name = name;
						break;
					case dff:
						ls.count_dff++;
						ls.create_dff(&ls.dff[ls.count_dff], pointofpif);
						ls.rotate_dff(&ls.dff[ls.count_dff], (Direct)direct);
						ls.dff[ls.count_dff].name = name;
						break;
					case jkff:
						ls.count_jkff++;
						ls.create_jkff(&ls.jkff[ls.count_jkff], pointofpif);
						ls.rotate_jkff(&ls.jkff[ls.count_jkff], (Direct)direct);
						ls.jkff[ls.count_jkff].name = name;
						break;
					case seg7:
						ls.count_seg7++;
						ls.create_seg7(&ls.seg7[ls.count_seg7], pointofpif);
						ls.rotate_seg7(&ls.seg7[ls.count_seg7], (Direct)direct);
						ls.seg7[ls.count_seg7].name = name;
						break;
					case dcd:
						ls.count_dcd++;
						ls.create_dcd(&ls.dcd[ls.count_dcd], pointofpif);
						//ls.rotate_dcd(&ls.dcd[ls.count_dcd], (Direct)direct);
						ls.dcd[ls.count_dcd].name = name;
						break;
					case lib:
						ls.count_lib++;
						ls.create_lib(&ls.lib[ls.count_lib], pointofpif);
						ls.rotate_lib(&ls.lib[ls.count_lib], (Direct)direct);
						ls.lib[ls.count_lib].name = name;
						break;
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
