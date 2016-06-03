
// PLS2View.h : CPLS2View Ŭ������ �������̽�
//

#pragma once

class CPLS2View : public CView
{
protected: // serialization������ ��������ϴ�.
	CPLS2View();
	DECLARE_DYNCREATE(CPLS2View)

// Ư���Դϴ�.
public:
	CPLS2Doc* GetDocument() const;

//���� �ùķ����� �����Դϴ�.
public:
	BOOL drawline = FALSE;
	CPoint startline;
	CPoint rbuttonClickedPoint;

	CPoint oldpoint = { 0,0 };
	int garo = 0, sero = 0;
	int line = 0, inout = 0, gate = 0, ff = 0;
	int zero = 0;
	int se[10];
	int repeat = 0;
	int hz = 1000;
	CString m_str;
//���� �ùķ����� �Լ��Դϴ�.
	CPoint DividedByTwenty(CPoint point);

// �۾��Դϴ�.
public:

// �������Դϴ�.
public:
	virtual void OnDraw(CDC* pDC);  // �� �並 �׸��� ���� �����ǵǾ����ϴ�.
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

	void drawingline(CPoint start, CPoint end, WhereFixed wherefixed);
	CPoint old_start; //drawingline���� ������ �׷����� �����ֱ� ���Ѱ�.
	CPoint old_end; //drawingline���� ������ �׷����� �����ֱ� ���Ѱ�.
	WhereFixed old_wherefixed; //drawingline���� ������ �׷����� �����ֱ� ���Ѱ�.
// �����Դϴ�.
public:
	virtual ~CPLS2View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ������ �޽��� �� �Լ�
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void Create_Input_BCLK();
	afx_msg void Create_Output_BCLK();
	afx_msg void Create_AndGate_BCLK();
	afx_msg void Create_XorGate_BCLK();
	afx_msg void Create_NorGate_BCLK();
	afx_msg void Create_NAndGate_BCLK();
	afx_msg void Create_OrGate_BCLK();
	afx_msg void Create_NotGate_BCLK();
	afx_msg void Create_TFF_BCLK();
	afx_msg void Create_Clock_BCLK();
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnDestroy();
	afx_msg void Create_DFF_BCLK();
	afx_msg void Create_JKFF_BCLK();
	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
	afx_msg void OnSerialize();
	afx_msg void Onrun();
	afx_msg void Create_7Segment_BCLK();
	afx_msg void On1second();
	afx_msg void Onpoint5second();
	afx_msg void Onpoint25second();
	afx_msg void Onpoint1second();
	afx_msg void Onclockstop();
	afx_msg void OnContextMenu(CWnd* /*pWnd*/, CPoint /*point*/);
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
	afx_msg void On_TurnToRight();
	afx_msg void On_TurnToLeft();
	afx_msg void On_TurnToTop();
	afx_msg void On_TurnToBottom();
	afx_msg void Onlibready();
	afx_msg void Oncreatelib();
	afx_msg void Ondecoder();
	afx_msg void Onautorun();
	afx_msg void Onrunstop();
	afx_msg void On32825();
	afx_msg void On32826();
//	afx_msg void OnRButtonDblClk(UINT nFlags, CPoint point);
	afx_msg void OnMButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnTextlabel();
};

#ifndef _DEBUG  // PLS2View.cpp�� ����� ����
inline CPLS2Doc* CPLS2View::GetDocument() const
   { return reinterpret_cast<CPLS2Doc*>(m_pDocument); }
#endif

