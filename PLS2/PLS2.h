
// PLS2.h : PLS2 ���� ���α׷��� ���� �� ��� ����
//
#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"       // �� ��ȣ�Դϴ�.


// CPLS2App:
// �� Ŭ������ ������ ���ؼ��� PLS2.cpp�� �����Ͻʽÿ�.
//

class CPLS2App : public CWinApp
{
public:
	CPLS2App();


// �������Դϴ�.
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// �����Դϴ�.
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CPLS2App theApp;
