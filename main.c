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

	
	return 0;
}
