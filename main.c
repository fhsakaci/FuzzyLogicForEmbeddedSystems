#include "main.h"
#include <stdio.h>
int main(void)
{
	
	MembershipPoint *Low=setMembershipPoint(1,2,3,4);
	MembershipPoint *Medium=setMembershipPoint(5,6,7,8);
	MembershipPoint *high=setMembershipPoint(9,10,11,12);

	InputMembership *Input1;	
	Input1=InputMembershipInit(Input1,1);	
	setInputMembership(Input1,Low);
	setInputMembership(Input1,Medium);
	setInputMembership(Input1,high);
	
	InputMembership *Input2;	
	Input2=InputMembershipInit(Input2,1);	
	setInputMembership(Input2,Low);
	setInputMembership(Input1,Medium);
	setInputMembership(Input2,high);

	OutputMembership *Output1;
	Output1=OutputMembershipInit(Output1,1);
	setOutputMembership(Output1,high);
	setOutputMembership(Output1,Medium);
	setOutputMembership(Output1,Low);
	
	FuzzyInput *Inputs;
	Inputs=FuzzyInputInit(Inputs);
	setFuzzyInput(Inputs,Input1);
	setFuzzyInput(Inputs,Input2);
	
	FuzzyOutput *Outputs;
	Outputs=FuzzyOutputInit(Outputs);
	setFuzzyOutput(Outputs,Output1);
	
	Fuzzy *fuzzy;
	fuzzy=FuzzyInit(fuzzy);
	setFuzzy(fuzzy,Inputs,Outputs);
	printf("%f",fuzzy->Output->Outputx->Membership->d1);

	float x=2;
	if(fuzzy->Input->Inputx->Membership->d1<x && fuzzy->Input->Inputx->Membership->d4>x)
	{
		fuzzy->Input->Inputx->Membership->degree=0;
	}
	else if(fuzzy->Input->Inputx->Membership->d2>=x && fuzzy->Input->Inputx->Membership->d3<=x)
	{
		fuzzy->Input->Inputx->Membership->degree=1;
	}
	else
	{
		float down=fuzzy->Input->Inputx->Membership->d4-fuzzy->Input->Inputx->Membership->d1;
		float up=fuzzy->Input->Inputx->Membership->d3-fuzzy->Input->Inputx->Membership->d2;
		float h=1;
		float area=(up+down)*h/2;
		
		if(x>fuzzy->Input->Inputx->Membership->d3)
		{
			float x1=x-fuzzy->Input->Inputx->Membership->d2;
			float x2=fuzzy->Input->Inputx->Membership->d3-x;
			float sh=1-(x1/(x1+x2));
		}
		else
		{
			float x1=x-fuzzy->Input->Inputx->Membership->d1;
			float x2=fuzzy->Input->Inputx->Membership->d2-x;
			float sh=1-(x1/(x1+x2));
		}
		
	}
	
	return 0;
}
