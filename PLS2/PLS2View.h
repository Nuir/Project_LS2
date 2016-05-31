
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
	
	CPoint oldpoint = { 0,0 };
	int garo = 0, sero = 0;
	int line = 0, inout = 0, gate = 0, ff = 0;
	int zero = 0;
	int se[10];
	int repeat = 0;

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
};

#ifndef _DEBUG  // PLS2View.cpp�� ����� ����
inline CPLS2Doc* CPLS2View::GetDocument() const
   { return reinterpret_cast<CPLS2Doc*>(m_pDocument); }
#endif

