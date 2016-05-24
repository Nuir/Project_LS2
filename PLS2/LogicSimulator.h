#pragma once
#include "stdafx.h"

#define INDEX 300

//enum변수입니다.
enum WhatGate { nothing, input, output, line, and, or, xor, nand, nor, nxor, not };
enum WhereFixed { DEFAULT, SERO, GARO }; // 그림그릴 때 가로가 고정되었나 세로가 고정되었나?

class LogicSimulator
{

public:
//구조체입니다.
public: 

	struct PointInfo {

		//각각 몇번인가
		int input = -1; //입력
		int output = -1; //출력
		int and = -1;
		int or = -1;
		int xor = -1;
		int not = -1;
		int line = -1;


		BOOL gatein = FALSE; //게이트의 입력값으로 사용되는가
		BOOL gateout = FALSE; //게이트의 출력값으로 사용되는가
	
		BOOL lineok = FALSE;
		WhatGate gate = nothing;
		BOOL usingpoint = FALSE;

		int* value = NULL;
	}pinfo;

	struct Input {
		int value = 0; // 가지는 값.
		CString name;
		CPoint clicked{ -1, -1 }; // 사각형의 중점.
		CPoint min; // 사각형의 왼쪽 끝점
		CPoint max; // 사각형의 오른쪽 끝점
		CPoint output[4];  // 값을 내보낼 수 있는 점.
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
		int* get1 = NULL; // 값을 받는 변수
		int* get2 = NULL; // 값을 받는 변수
		int out = NULL;  // 값을 내보내는 변수
		CString name;
		CPoint clicked{ -1, -1 };
		CPoint min;
		CPoint max;
		CPoint output[1];
		CPoint input[2];
	};

	struct XorGate {
		int * value = NULL;
		CString name; // caption
		CPoint clicked{ -1, -1 }; // 사각형의 중점.
		CPoint min; // 사각형의 왼쪽 끝점
		CPoint max; // 사각형의 오른쪽 끝점
		CPoint output;  // 값을 내보낼 수 있는 점.
		CPoint input[2];
	};

	struct NorGate {
		int * value = NULL;
		CString name; // caption
		CPoint clicked{ -1, -1 }; // 사각형의 중점.
		CPoint min; // 사각형의 왼쪽 끝점
		CPoint max; // 사각형의 오른쪽 끝점
		CPoint output;  // 값을 내보낼 수 있는 점.
		CPoint input[2];
	};

//변수입니다.
public:
	PointInfo pif[INDEX][INDEX];
	CArray<OneLinePoint, OneLinePoint&> line; // 각 원소가 한 라인
	Input in[INDEX];
	Output out[INDEX];
	AndGate and[INDEX];
	XorGate xor[INDEX];
	NorGate nor[INDEX];

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

	int create = -1; // 이 숫자에 따라 무엇을 생성할 지가 정해짐.

//함수입니다.
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
};