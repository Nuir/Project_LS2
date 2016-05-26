#pragma once
#include "stdafx.h"

#define INDEX 200

//enum�����Դϴ�.
enum WhatGate { nothing, input, output, line, and, or, xor, nand, nor, nxor, not ,lsclock, dff, jkff, tff};
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
		int nand = -1;
		int nor = -1;
		int dff = -1;
		int jkff = -1;
		int tff = -1;
		int clock = -1;


		BOOL gatein = FALSE; //����Ʈ�� �Է°����� ���Ǵ°�
		BOOL gateout = FALSE; //����Ʈ�� ��°����� ���Ǵ°�

		BOOL lineok = FALSE;
		WhatGate gate = nothing;
		BOOL usingpoint = FALSE;

		int* value = NULL;
	}pinfo;

	struct Input {
		int value = 1; // ������ ��.
		CString name;
		CPoint clicked{ -1, -1 }; // �簢���� ����.
		CPoint min; // �簢���� ���� ����
		CPoint max; // �簢���� ������ ����
		CPoint output[4];  // ���� ������ �� �ִ� ��.
	};

	struct Output {
		int value = 1;
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

	struct AndGate { // �Է°��� pif[input[0].x][input[0].y].value * �� �̷������� ���� �� ����.
		int out = NULL;  // ���� �������� ����
		CString name;
		CPoint clicked{ -1, -1 };
		CPoint min;
		CPoint max;
		CPoint output;
		CPoint input[2];
	};

	struct XorGate {
		int * value = NULL;
		CString name; // caption
		CPoint clicked{ -1, -1 }; // �簢���� ����.
		CPoint min; // �簢���� ���� ����
		CPoint max; // �簢���� ������ ����
		CPoint output;  // ���� ������ �� �ִ� ��.
		CPoint input[2];
	};

	struct NorGate {
		int * value = NULL;
		CString name; // caption
		CPoint clicked{ -1, -1 }; // �簢���� ����.
		CPoint min; // �簢���� ���� ����
		CPoint max; // �簢���� ������ ����
		CPoint output;  // ���� ������ �� �ִ� ��.
		CPoint input[2];
	};

	struct NAndGate {
		int * value = NULL;
		CString name;
		CPoint clicked{ -1, -1 }; // �簢���� ����.
		CPoint min; // �簢���� ���� ����
		CPoint max; // �簢���� ������ ����
		CPoint output;  // ���� ������ �� �ִ� ��.
		CPoint input[2];
	};

	struct OrGate {
		int* value = NULL;
		CString name;
		CPoint clicked{ -1, -1 };
		CPoint min;
		CPoint max;
		CPoint output;
		CPoint input[2];
	};

	struct NotGate {
		int* value = NULL;
		CString name;
		CPoint clicked{ -1. - 1 };
		CPoint min;
		CPoint max;
		CPoint output;
		CPoint input;
	};

	struct TFF{
		int* value = NULL;
		CString name;
		CPoint clicked{ -1. - 1 };
		CPoint min;
		CPoint max;
		CPoint output[2];
		CPoint input;
		CPoint clock;
	};

	struct Clock {
		int value = 0;
		CString name;
		CPoint clicked{ -1. - 1 };
		CPoint min;
		CPoint max;
		CPoint output;
	};

	struct DFF {
		int* value = NULL;
		CString name;
		CPoint clicked{ -1. - 1 };
		CPoint min;
		CPoint max;
		CPoint output[2];
		CPoint input;
		CPoint clock;
	};

	struct JKFF {
		int* value = NULL;
		CString name;
		CPoint clicked{ -1. - 1 };
		CPoint min;
		CPoint max;
		CPoint output[2];
		CPoint input[2];
		CPoint clock;
	};

	//�����Դϴ�.
public:
	PointInfo pif[INDEX][INDEX];
	CArray<OneLinePoint, OneLinePoint&> line; // �� ���Ұ� �� ����
	Input in[INDEX];
	Output out[INDEX];
	AndGate and[INDEX];
	XorGate xor[INDEX];
	NorGate nor[INDEX];
	NAndGate nand[INDEX];
	OrGate or [INDEX];
	NotGate not[INDEX];
	TFF tff[INDEX];
	Clock clock[INDEX];
	DFF dff[INDEX];
	JKFF jkff[INDEX];

	CPoint downPoint;
	CPoint upPoint;



	WhereFixed wherefixed = DEFAULT;
	WhatGate whatgate = nothing;

	bool canDrawState = false;
	int count_input = -1;
	int count_output = -1;
	int count_and = -1;
	int count_xor = -1;
	int count_nor = -1;
	int count_nand = -1;
	int count_or = -1;
	int count_not = -1;
	int count_clock = -1;
	int count_tff = -1;
	int count_dff = -1;
	int count_jkff = -1;
	int count_line = -1;

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
	void create_xor(XorGate *xor, CPoint clicked);
	void create_nor(NorGate *nor, CPoint clicked);
	void create_nand(NAndGate *nand, CPoint clicked);
	void create_or(OrGate * or , CPoint clicked);
	void create_not(NotGate * not, CPoint clicked);
	void create_tff(TFF * not, CPoint clicked);
	void create_clock(Clock * not, CPoint clicked);
	void create_dff(DFF * dff, CPoint clicked);
	void create_jkff(JKFF * jkff, CPoint clicked);
	void create_line(CPoint firstPt, CPoint secondPt, int index);
	//void calculate_and(AndGate *and);
};