#pragma once
#include "LogicSimulator.h"
// CWaveDoc �����Դϴ�.

class CWaveDoc : public CDocument
{
	DECLARE_DYNCREATE(CWaveDoc)

public:
	CWaveDoc();
	virtual ~CWaveDoc();

	LogicSimulator ls;
	LogicSimulator ls2;
	LogicSimulator library;

#ifndef _WIN32_WCE
	virtual void Serialize(CArchive& ar);   // ���� ��/����� ���� �����ǵǾ����ϴ�.
#endif
#ifdef _DEBUG
	virtual void AssertValid() const;
#ifndef _WIN32_WCE
	virtual void Dump(CDumpContext& dc) const;
#endif
#endif

protected:
	virtual BOOL OnNewDocument();

	DECLARE_MESSAGE_MAP()
};
