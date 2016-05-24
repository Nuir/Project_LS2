#pragma once
#include "stdafx.h"

#define INDEX 300

//enum�����Դϴ�.
enum WhatGate { nothing, input, output, line, and, or, xor, nand, nor, nxor, not };
enum WhereFixed { DEFAULT, SERO, GARO }; // �׸��׸� �� ���ΰ� �����Ǿ��� ���ΰ� �����Ǿ���?

class LogicSimulator
{

public:
//����ü�Դϴ�.
public: 

	struct PointInfo {

		//���� ����ΰ�
		int input = -1; //�Է�
		int output = -1; //���
		int and = -1;
		int or = -1;
		int xor = -1;
		int not = -1;
		int line = -1;


		BOOL gatein = FALSE; //����Ʈ�� �Է°����� ���Ǵ°�
		BOOL gateout = FALSE; //����Ʈ�� ��°����� ���Ǵ°�
	
		BOOL lineok = FALSE;
		WhatGate gate = nothing;
		BOOL usingpoint = FALSE;

		int* value = NULL;
	}pinfo;

	struct Input {
		int value = 0; // ������ ��.
		CString name;
		CPoint clicked{ -1, -1 }; // �簢���� ����.
		CPoint min; // �簢���� ���� ����
		CPoint max; // �簢���� ������ ����
		CPoint output[4];  // ���� ������ �� �ִ� ��.
	};

	struct Output {
		int* value = 0; 
		CString name;
		CPoint clicked{ -1, -1 }; 
		CPoint min; 
		CPoint max;
		CPoint input;
	};

	struct OneLinePoint {

		CPoint firstPt;
		CPoint secondPt;
		OneLinePoint() {}
		OneLinePoint(CPoint a, CPoint b) {
			firstPt = a;
			secondPt = b;
		}
	};

	struct AndGate {
		int* value = NULL; // ������ ��.
		CString name;
		CPoint clicked{ -1, -1 }; // �簢���� ����.
		CPoint min; // �簢���� ���� ����
		CPoint max; // �簢���� ������ ����
		CPoint output[1];  // ���� ������ �� �ִ� ��.
		CPoint input[2];
	};

//�����Դϴ�.
public:
	PointInfo pif[INDEX][INDEX];
	CArray<OneLinePoint, OneLinePoint&> line; // �� ���Ұ� �� ����
	Input in[INDEX];
	Output out[INDEX];
	AndGate and[INDEX];


	CPoint downPoint;
	CPoint upPoint;



	WhereFixed wherefixed = DEFAULT;
	WhatGate whatgate = nothing;

	bool canDrawState = false;
	int count_input = -1;
	int count_output = -1;
	int count_and = -1;

	int create = -1; // �� ���ڿ� ���� ������ ������ ���� ������.

//�Լ��Դϴ�.
public:
	LogicSimulator::LogicSimulator();
	void OnePointClear(PointInfo pif);
	void AllPointClear();
	void print(LogicSimulator ls);
	void create_input(Input* in, CPoint clicked);
	void create_output(Output* out, CPoint clicked);
	void create_and(AndGate *and, CPoint clicked);
	void SavePointOnTheLine(CPoint old_start, CPoint old_end, WhereFixed old_wherefixed);
};