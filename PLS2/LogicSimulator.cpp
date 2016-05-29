

#include "stdafx.h"
#include "LogicSimulator.h"


LogicSimulator::LogicSimulator() 
{

}

void LogicSimulator::OnePointClear(PointInfo pif)
{
	pif.input = -1;
	pif.output = -1;
	pif. and = -1;
	pif. or = -1;
	pif. xor = -1;
	pif. not = -1;
	pif.line = -1;


	pif.gatein = FALSE;
	pif.gateout = FALSE;
	
	pif.lineok = FALSE;
	pif.gate = nothing;
	pif.usingpoint = FALSE;
	int i = 0;
	pif.value = &i;
}

void LogicSimulator::AllPointClear()
{
	for (int i = 0; i < INDEX; i++)
		for (int j = 0; j < INDEX; j++)
			OnePointClear(pif[i][j]);
}

void LogicSimulator::print(LogicSimulator ls)
{
}

void LogicSimulator::create_input(Input *in, CPoint clicked)
{

	in->clicked = clicked; // ���콺�� ���� ��ġ.//
	//�簢���� �׸��� ���� left�� right
	in->min = { clicked.x - 1, clicked.y - 1 };
	in->max = { clicked.x + 1, clicked.y + 1 };
	//���� ������ �� �ִ� ��.
	in->output = { clicked.x + 1, clicked.y};


	this->pif[clicked.x][clicked.y].value = &(in->value);
	this->pif[clicked.x][clicked.y].input = this->count_input;
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++) {
			this->pif[in->min.x + i][in->min.y + j].usingpoint = TRUE;
			this->pif[in->min.x + i][in->min.y + j].gate = input;
		}
	this->pif[in->output.x][in->output.y].lineok = TRUE;
	this->pif[in->output.x][in->output.y].gateout = TRUE;
	this->pif[in->output.x][in->output.y].value = &in->value;
	/*
	for (int i = 0; i < 4; i++) {
		this->pif[in->output[i].x][in->output[i].y].lineok = TRUE;
		this->pif[in->output[i].x][in->output[i].y].gateout = TRUE;
		this->pif[in->output[i].x][in->output[i].y].value = &in->value;
	}
	*/
}

void LogicSimulator::create_output(Output *out, CPoint clicked)
{
	out->clicked = clicked;
	out->min = { clicked.x - 1, clicked.y - 1 };
	out->max = { clicked.x + 1, clicked.y + 1 };
	out->input = { clicked.x - 1, clicked.y };

	this->pif[clicked.x][clicked.y].output = this->count_output;
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++) {
			this->pif[out->min.x + i][out->min.y + j].usingpoint = TRUE;
			this->pif[out->min.x + i][out->min.y + j].gate = output;
		}
	this->pif[out->input.x][out->input.y].lineok = TRUE;
	this->pif[out->input.x][out->input.y].gatein = TRUE;
	out->value = *(this->pif[out->input.x][out->input.y].value);
}

void LogicSimulator::create_and(AndGate *and, CPoint clicked) // clicked : pif �ε��� 
{
	and->clicked = clicked; //pif �ε���
	and->min = { clicked.x-2, clicked.y-2}; // ��Ʈ���� ���� ����ϴ� left��ǥ
	and->max = { clicked.x+2, clicked.y+2};

	and->output = { clicked.x+2, clicked.y};//���� ������ �� �ִ� ��.
	and->input[0] = { clicked.x-2, clicked.y - 1 }; // ���� �޴� ��.
	and->input[1] = { clicked.x-2, clicked.y + 1 };
	
		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < 5; j++) {
				this->pif[and->min.x + i][and->min.y + j].usingpoint = TRUE;
				this->pif[and->min.x + i][and->min.y + j].gate = ::and;
			}
		}
		this->pif[and->input[0].x][and->input[0].y].lineok = TRUE;
		this->pif[and->input[0].x][and->input[0].y].gatein = TRUE;
		this->pif[and->input[1].x][and->input[1].y].lineok = TRUE;
		this->pif[and->input[1].x][and->input[1].y].gatein = TRUE;
		this->pif[and->output.x][and->output.y].lineok = TRUE;
		this->pif[and->output.x][and->output.y].gatein = TRUE;

}

void LogicSimulator::SavePointOnTheLine(CPoint old_start, CPoint old_end, WhereFixed old_wherefixed) { // �׷��� ���� ���� ���� �����Ѵ�.

	CPoint tempP;
	if (old_start == old_end)
		return;

	if (old_wherefixed == GARO)
		if (old_start.y == old_end.y) { // 1�ٸ� �׸��°��.
			 line.Add(OneLinePoint(old_start, old_end));
			 count_line++;
			 this->create_line(line.GetAt(count_line).firstPt, line.GetAt(count_line).secondPt, count_line);
			// pif[old_start.x/10][old_start.y/10].lineok = TRUE;
			// pif[old_end.x/10][old_end.y/10].lineok = TRUE;
		}

		else {//������ �׷���� �ϴ� ���.
			tempP.x = old_end.x;
			tempP.y = old_start.y;
			 line.Add(OneLinePoint(old_start, tempP));
			 count_line++;
			 this->create_line(line.GetAt(count_line).firstPt, line.GetAt(count_line).secondPt, count_line);
			 //pif[old_start.x / 10][old_start.y / 10].lineok = TRUE;
			// pif[tempP.x / 10][tempP.y / 10].lineok = TRUE;

			tempP.x = old_end.x;
			tempP.y = old_start.y;
			 line.Add(OneLinePoint(tempP, old_end));
			 count_line++;
			 this->create_line(line.GetAt(count_line).firstPt, line.GetAt(count_line).secondPt, count_line);
			// pif[tempP.x / 10][tempP.y / 10].lineok = TRUE;
			// pif[old_end.x / 10][old_end.y / 10].lineok = TRUE;
		}
	else if (old_wherefixed == SERO) {
		if (old_start.x == old_end.x) { // 1�ٸ� �׸��°��.
			 line.Add(OneLinePoint(old_start, old_end));
			 count_line++;
			 this->create_line(line.GetAt(count_line).firstPt, line.GetAt(count_line).secondPt, count_line);
			// pif[old_start.x / 10][old_start.y / 10].lineok = TRUE;
			// pif[old_end.x / 10][old_end.y / 10].lineok = TRUE;
		}
		else {//������ �׷���� �ϴ� ���.
			tempP.x = old_start.x;
			tempP.y = old_end.y;
			 line.Add(OneLinePoint(old_start, tempP));
			 count_line++;
			 this->create_line(line.GetAt(count_line).firstPt, line.GetAt(count_line).secondPt, count_line);
			// pif[old_start.x / 10][old_start.y / 10].lineok = TRUE;
			// pif[tempP.x / 10][tempP.y / 10].lineok = TRUE;

			tempP.x = old_start.x;
			tempP.y = old_end.y;
			 line.Add(OneLinePoint(tempP, old_end));
			 count_line++;
			 this->create_line(line.GetAt(count_line).firstPt, line.GetAt(count_line).secondPt, count_line);
			// pif[tempP.x / 10][tempP.y / 10].lineok = TRUE;
			// pif[old_end.x / 10][old_end.y / 10].lineok = TRUE;
		}
	}
}

void LogicSimulator::create_line(CPoint firstPt, CPoint secondPt, int index) {
	// �� �Լ��� �ֿ� ������ pif�� ������ �����ϴ� ��.(�����ߴٰ� �ε� ���� �� �� ������ �־�� ���� �ǹǷ�.)
	if (firstPt.y == secondPt.y) { //�����ΰ��
		if ((firstPt.x - secondPt.x) < 0) {
			for (int i = 1; i <= abs(firstPt.x - secondPt.x) / 20; i++) {
				this->pif[(firstPt.x / 20) + i][firstPt.y / 20].value = pif[firstPt.x / 20][firstPt.y / 20].value;
				pif[(firstPt.x / 20) + i][firstPt.y / 20].line = index;
				pif[(firstPt.x / 20) + i][firstPt.y / 20].lineok = TRUE;
				pif[(firstPt.x / 20) + i][firstPt.y / 20].usingpoint = TRUE;
				pif[(firstPt.x / 20) + i][firstPt.y / 20].gateout = TRUE;
			}
		}
		else {
			for (int i = 1; i <= abs(firstPt.x - secondPt.x) / 20; i++) {
				pif[(firstPt.x / 20) - i][firstPt.y / 20].value = pif[firstPt.x / 20][firstPt.y / 20].value;
				pif[(firstPt.x / 20) - i][firstPt.y / 20].line = index;
				pif[(firstPt.x / 20) - i][firstPt.y / 20].lineok = TRUE;
				pif[(firstPt.x / 20) - i][firstPt.y / 20].usingpoint = TRUE;
				pif[(firstPt.x / 20) - i][firstPt.y / 20].gateout = TRUE;
			}
		}
	}
		

	else {//�����ΰ��
		if ((firstPt.y - secondPt.y) < 0) {
			for (int i = 1; i <= abs(firstPt.y - secondPt.y) / 20; i++) {
				pif[(firstPt.x / 20)][firstPt.y / 20 + i].value = pif[firstPt.x / 20][firstPt.y / 20].value;
				pif[(firstPt.x / 20)][firstPt.y / 20 + i].line = index;
				pif[(firstPt.x / 20)][firstPt.y / 20 + i].lineok = TRUE;
				pif[(firstPt.x / 20)][firstPt.y / 20 + i].usingpoint = TRUE;
				pif[(firstPt.x / 20)][firstPt.y / 20 + i].gateout = TRUE;
			}
		}

		else {
			for (int i = 1; i <= abs(firstPt.y - secondPt.y) / 20; i++) {
				pif[(firstPt.x / 20)][firstPt.y / 20 -i].value = pif[firstPt.x / 20][firstPt.y / 20].value;
				pif[(firstPt.x / 20)][firstPt.y / 20 - i].line = index;
				pif[(firstPt.x / 20)][firstPt.y / 20 - i].lineok = TRUE;
				pif[(firstPt.x / 20)][firstPt.y / 20 - i].usingpoint = TRUE;
				pif[(firstPt.x / 20)][firstPt.y / 20 - i].gateout = TRUE;
			}
		}
	}
}

void LogicSimulator::calculate_xor(XorGate * xor)
{
	if (*(this->pif[xor->input[0].x][xor->input[0].y].value) == *(this->pif[xor->input[1].x][xor->input[1].y].value))
		xor->value = 0;
	else
		xor->value = 1;
}

void LogicSimulator::create_xor(XorGate * xor, CPoint clicked)
{
	xor->clicked = clicked; // ���콺�� ���� ��ġ.
	xor->min = { clicked.x - 2, clicked.y - 2 }; // ��Ʈ���� ���� ����ϴ� left��ǥ
	xor->max = { clicked.x + 2, clicked.y + 2 }; //�����ϴ��� ��
	xor->output = { clicked.x + 2, clicked.y };//���� ������ �� �ִ� ��.
	xor->input[0] = { clicked.x - 2, clicked.y - 1 }; // ���� �޴� ��.
	xor->input[1] = { clicked.x - 2, clicked.y + 1 };

	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 5; j++) {
			this->pif[xor->min.x + i][xor->min.y + j].usingpoint = TRUE;
			this->pif[xor->min.x + i][xor->min.y + j].gate = ::xor;
		}
	this->pif[xor->input[0].x][xor->input[0].y].lineok = TRUE;
	this->pif[xor->input[0].x][xor->input[0].y].gatein = TRUE;
	this->pif[xor->input[1].x][xor->input[1].y].lineok = TRUE;
	this->pif[xor->input[1].x][xor->input[1].y].gatein = TRUE;
	this->pif[xor->output.x][xor->output.y].lineok = TRUE;
	this->pif[xor->output.x][xor->output.y].gateout = TRUE;
	this->pif[xor->output.x][xor->output.y].value = &(xor->value);
}

void LogicSimulator::create_nor(NorGate * nor, CPoint clicked)
{
	nor->clicked = clicked; // ���콺�� ���� ��ġ.
	nor->min = { clicked.x - 2, clicked.y - 2 }; // ��Ʈ���� ���� ����ϴ� left��ǥ
	nor->max = { clicked.x + 2, clicked.y + 2 }; //�����ϴ��� ��
	nor->output = { clicked.x + 2, clicked.y };//���� ������ �� �ִ� ��.
	nor->input[0] = { clicked.x - 2, clicked.y - 1 }; // ���� �޴� ��.
	nor->input[1] = { clicked.x - 2, clicked.y + 1 };

	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 5; j++) {
			this->pif[nor->min.x + i][nor->min.y + j].usingpoint = TRUE;
			this->pif[nor->min.x + i][nor->min.y + j].gate = ::nor;
		}
	this->pif[nor->input[0].x][nor->input[0].y].lineok = TRUE;
	this->pif[nor->input[0].x][nor->input[0].y].gatein = TRUE;
	this->pif[nor->input[1].x][nor->input[1].y].lineok = TRUE;
	this->pif[nor->input[1].x][nor->input[1].y].gatein = TRUE;
	this->pif[nor->output.x][nor->output.y].lineok = TRUE;
	this->pif[nor->output.x][nor->output.y].gateout = TRUE;
}

void LogicSimulator::create_nand(NAndGate *nand, CPoint clicked) {
	nand->clicked = clicked; //pif �ε���
	nand->min = { clicked.x - 2, clicked.y - 2 }; // ��Ʈ���� ���� ����ϴ� left��ǥ
	nand->max = { clicked.x + 2, clicked.y + 2 };
	nand->output = { clicked.x + 2, clicked.y };//���� ������ �� �ִ� ��.
	nand->input[0] = { clicked.x - 2, clicked.y - 1 }; // ���� �޴� ��.
	nand->input[1] = { clicked.x - 2, clicked.y + 1 };

	for (int i = 0; i < 5; i++){
		for (int j = 0; j < 5; j++) {
			this->pif[nand->min.x + i][nand->min.y + j].usingpoint = TRUE;
			this->pif[nand->min.x + i][nand->min.y + j].gate = ::nand;
		}
	}
	this->pif[nand->input[0].x][nand->input[0].y].lineok = TRUE;
	this->pif[nand->input[0].x][nand->input[0].y].gatein = TRUE;
	this->pif[nand->input[1].x][nand->input[1].y].lineok = TRUE;
	this->pif[nand->input[1].x][nand->input[1].y].gatein = TRUE;
	this->pif[nand->output.x][nand->output.y].lineok = TRUE;
	this->pif[nand->output.x][nand->output.y].gatein = TRUE;
	this->pif[xor->output.x][xor->output.y].gateout = TRUE;
}

void LogicSimulator::create_or(OrGate * or , CPoint clicked)
{
	or ->clicked = clicked; // ���콺�� ���� ��ġ.
	or ->min = { clicked.x - 2, clicked.y - 2 };
	or ->max = { clicked.x + 2, clicked.y + 2 };
	or ->output = { clicked.x + 2, clicked.y };
	or ->input[0] = { clicked.x - 2,clicked.y - 1 };
	or ->input[1] = { clicked.x - 2, clicked.y + 1 };

	for(int i=0; i<5; i++)
		for (int j = 0; j < 5; j++) {
			this->pif[or ->min.x + i][or ->min.y + j].usingpoint = TRUE;
			this->pif[or ->min.x + i][or ->min.y + j].gate = :: or ;
		}
	this->pif[or ->input[0].x][or ->input[0].y].lineok = TRUE;
	this->pif[or ->input[0].x][or ->input[0].y].gatein = TRUE;
	this->pif[or ->input[1].x][or ->input[1].y].lineok = TRUE;
	this->pif[or ->input[1].x][or ->input[1].y].gatein = TRUE;
	this->pif[or ->output.x][or ->output.y].lineok = TRUE;
	this->pif[or ->output.x][or ->output.y].gateout = TRUE;
}

void LogicSimulator::create_not(NotGate * not, CPoint clicked)
{
	not->clicked = clicked;
	not->min = { clicked.x - 2, clicked.y - 2 };
	not->max = { clicked.x + 2, clicked.y + 2 };
	not->output = { clicked.x + 2,clicked.y };
	not->input = { clicked.x - 2,clicked.y };

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			this->pif[not->min.x + i][not->min.y + j].usingpoint = TRUE;
			this->pif[not->min.x + i][not->min.y + j].gate = ::not;
		}
	}

	this->pif[not->input.x][not->input.y].lineok = TRUE;
	this->pif[not->input.x][not->input.y].gatein = TRUE;
	this->pif[not->output.x][not->output.y].lineok = TRUE;
	this->pif[not->output.x][not->output.y].gateout = TRUE;
}

void LogicSimulator::create_tff(TFF * tff, CPoint clicked)
{
	tff->clicked = clicked; // ���콺�� ���� ��ġ.
	tff->min = { clicked.x - 3, clicked.y - 3 };
	tff->max = { clicked.x + 3, clicked.y + 3 };
	tff->input = { clicked.x - 3, clicked.y - 2 };
	tff->clock = { clicked.x - 3, clicked.y };
	tff->output[0] = { clicked.x + 3,clicked.y - 1 };
	tff->output[1] = { clicked.x + 3, clicked.y + 1 };

	for (int i = 0; i<7; i++)
		for (int j = 0; j < 7; j++) {
			this->pif[tff->min.x + i][tff->min.y + j].usingpoint = TRUE;
			this->pif[tff->min.x + i][tff->min.y + j].gate = :: tff ;
		}

	this->pif[tff->input.x][tff->input.y].lineok = TRUE;
	this->pif[tff->input.x][tff->input.y].gatein = TRUE;
	this->pif[tff->clock.x][tff->clock.y].lineok = TRUE;
	this->pif[tff->clock.x][tff->clock.y].gatein = TRUE;
	this->pif[tff->output[0].x][tff->output[0].y].lineok = TRUE;
	this->pif[tff->output[0].x][tff->output[0].y].gateout = TRUE;
	this->pif[tff->output[1].x][tff->output[1].y].lineok = TRUE;
	this->pif[tff->output[1].x][tff->output[1].y].gateout = TRUE;
}

void LogicSimulator::create_clock(Clock * clock, CPoint clicked)
{
	clock->clicked = clicked; // ���콺�� ���� ��ġ.//
						   //�簢���� �׸��� ���� left�� right
	clock->min = { clicked.x - 1, clicked.y - 1 };
	clock->max = { clicked.x + 1, clicked.y + 1 };
	//���� ������ �� �ִ� ��.
	clock->output = { clicked.x + 1, clicked.y };

	this->pif[clicked.x][clicked.y].value = &(clock->value);
	this->pif[clicked.x][clicked.y].clock = this->count_clock;
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++) {
			this->pif[clock->min.x + i][clock->min.y + j].usingpoint = TRUE;
			this->pif[clock->min.x + i][clock->min.y + j].gate = lsclock;
		}
	for (int i = 0; i < 4; i++) {
		this->pif[clock->output.x][clock->output.y].lineok = TRUE;
		this->pif[clock->output.x][clock->output.y].gateout = TRUE;
		this->pif[clock->output.x][clock->output.y].value = this->pif[clicked.x][clicked.y].value;
	}
}

void LogicSimulator::create_dff(DFF * dff, CPoint clicked)
{
	dff->clicked = clicked; // ���콺�� ���� ��ġ.
	dff->min = { clicked.x - 3, clicked.y - 3 };
	dff->max = { clicked.x + 3, clicked.y + 3 };
	dff->input = { clicked.x - 3, clicked.y - 2 };
	dff->clock = { clicked.x - 3, clicked.y };
	dff->output[0] = { clicked.x + 3,clicked.y - 1 };
	dff->output[1] = { clicked.x + 3, clicked.y + 1 };

	for (int i = 0; i<7; i++)
		for (int j = 0; j < 7; j++) {
			this->pif[dff->min.x + i][dff->min.y + j].usingpoint = TRUE;
			this->pif[dff->min.x + i][dff->min.y + j].gate = ::dff;
		}

	this->pif[dff->input.x][dff->input.y].lineok = TRUE;
	this->pif[dff->input.x][dff->input.y].gatein = TRUE;
	this->pif[dff->clock.x][dff->clock.y].lineok = TRUE;
	this->pif[dff->clock.x][dff->clock.y].gatein = TRUE;
	this->pif[dff->output[0].x][dff->output[0].y].lineok = TRUE;
	this->pif[dff->output[0].x][dff->output[0].y].gateout = TRUE;
	this->pif[dff->output[1].x][dff->output[1].y].lineok = TRUE;
	this->pif[dff->output[1].x][dff->output[1].y].gateout = TRUE;
}

void LogicSimulator::create_jkff(JKFF * jkff, CPoint clicked) {
	jkff->clicked = clicked; // ���콺�� ���� ��ġ.
	jkff->min = { clicked.x - 3, clicked.y - 3 };
	jkff->max = { clicked.x + 3, clicked.y + 3 };
	jkff->input[0] = { clicked.x - 3, clicked.y - 2 };
	jkff->input[1] = { clicked.x - 3, clicked.y + 2 };
	jkff->clock = { clicked.x - 3, clicked.y };
	jkff->output[0] = { clicked.x + 3,clicked.y - 1 };
	jkff->output[1] = { clicked.x + 3, clicked.y + 1 };

	for (int i = 0; i<7; i++)
		for (int j = 0; j < 7; j++) {
			this->pif[jkff->min.x + i][jkff->min.y + j].usingpoint = TRUE;
			this->pif[jkff->min.x + i][jkff->min.y + j].gate = ::jkff;
		}

	this->pif[jkff->input[0].x][jkff->input[0].y].lineok = TRUE;
	this->pif[jkff->input[0].x][jkff->input[0].y].gatein = TRUE;
	this->pif[jkff->input[1].x][jkff->input[1].y].lineok = TRUE;
	this->pif[jkff->input[1].x][jkff->input[1].y].gatein = TRUE;
	this->pif[jkff->clock.x][jkff->clock.y].lineok = TRUE;
	this->pif[jkff->clock.x][jkff->clock.y].gatein = TRUE;
	this->pif[jkff->output[0].x][jkff->output[0].y].lineok = TRUE;
	this->pif[jkff->output[0].x][jkff->output[0].y].gateout = TRUE;
	this->pif[jkff->output[1].x][jkff->output[1].y].lineok = TRUE;
	this->pif[jkff->output[1].x][jkff->output[1].y].gateout = TRUE;
}

/*
void LogicSimulator::calculate_and(AndGate *and){
	//������ ����
	if(this->pif[and->input[0].x][and->input[0].y].value && this->pif[and->input[1].x][and->input[1].y].value)
		and->value = 1;
	else
		and->value = 0;
}
*/