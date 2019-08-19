#include "main.h"
#include <stdio.h>
int main(void)
{
	
	MembershipPoint *Low=setMembershipPoint(1,2,2,3);
	MembershipPoint *Medium=setMembershipPoint(2,3,3,4);
	MembershipPoint *high=setMembershipPoint(3,4,4,5);

	MembershipPoint *SLow=setMembershipPoint(9,10,10,11);
	MembershipPoint *Middle=setMembershipPoint(10,11,11,12);
	MembershipPoint *Fast=setMembershipPoint(11,12,12,13);
	
	MembershipPoint *Cold=setMembershipPoint(9,10,10,11);
	MembershipPoint *Average=setMembershipPoint(10,11,11,12);
	MembershipPoint *Hot=setMembershipPoint(11,12,12,13);
	
	MembershipPoint *L1=setMembershipPoint(40,50,50,60);
	MembershipPoint *L2=setMembershipPoint(50,60,60,70);
	MembershipPoint *L3=setMembershipPoint(70,90,90,110);
	
	MembershipPoint *Ls1=setMembershipPoint(120,130,130,140);
	MembershipPoint *Ls2=setMembershipPoint(130,140,140,150);
	MembershipPoint *Ls3=setMembershipPoint(140,150,150,160);
	
	
	InputMembership *Input1;	
	Input1=InputMembershipInit(Input1,1);	
	setInputMembership(Input1,Low);
	setInputMembership(Input1,Medium);
	setInputMembership(Input1,high);
	
	InputMembership *Input2;	
	Input2=InputMembershipInit(Input2,2);	
	setInputMembership(Input2,SLow);
	setInputMembership(Input2,Middle);
	setInputMembership(Input2,Fast);
	
	InputMembership *Input3;	
	Input3=InputMembershipInit(Input3,3);	
	setInputMembership(Input3,Cold);
	setInputMembership(Input3,Average);
	setInputMembership(Input3,Hot);

	OutputMembership *Output1;
	Output1=OutputMembershipInit(Output1,1);
	setOutputMembership(Output1,L1);
	setOutputMembership(Output1,L2);
	setOutputMembership(Output1,L3);
	
	OutputMembership *Output2;
	Output2=OutputMembershipInit(Output2,2);
	setOutputMembership(Output2,Ls1);
	setOutputMembership(Output2,Ls2);
	setOutputMembership(Output2,Ls3);
	
	FuzzyInput *Inputs;
	Inputs=FuzzyInputInit(Inputs);
	setFuzzyInput(Inputs,Input1);
	setFuzzyInput(Inputs,Input2);
	setFuzzyInput(Inputs,Input3);
	
	FuzzyOutput *Outputs;
	Outputs=FuzzyOutputInit(Outputs);
	setFuzzyOutput(Outputs,Output1);
	setFuzzyOutput(Outputs,Output2);
	
	
	Fuzzy *fuzzy;
	fuzzy=FuzzyInit(fuzzy);
	
	FuzzyRule* Rules;
	Rules=FuzzyRuleInit(Rules);
	FuzzyInputRule *LowAndSLow=AddRuleAND(Input1,Low,Input2,SLow);
	FuzzyInputRule *MediumAndMiddle=AddRuleAND(Input1,Medium,Input2,Middle);
	FuzzyInputRule *highandfast=AddRuleAND(Input1,high,Input2,Fast);
	FuzzyInputRule *HotAndMiddle=AddRuleAND(Input2,SLow,Input3,Cold);
//	
	setFuzzyRule(Rules,LowAndSLow,Output1,L3);
	setFuzzyRule(Rules,highandfast,Output1,L2);
	setFuzzyRule(Rules,MediumAndMiddle,Output1,L1);
	setFuzzyRule(Rules,HotAndMiddle,Output2,Ls3);
	setFuzzy(fuzzy,Inputs,Outputs,Rules);

	float x[3];
	x[0]=1.8;
	x[1]=9.6;
	x[2]=9.6;
	float sonuc;
//	for(float i=2.8;i<5;i=i+0.5)
//	{
		
		fuzzify(fuzzy,x);
		sonuc=defuzzify(fuzzy);
//		printf("%f %f %f : %f\n",x[0],x[1],x[3],sonuc);
//		printf("\n\n%d",fuzzy->Output->Outputx->id);
//	}

printf("\nInput1: %f",fuzzy->Rules->outputMembership->degree);
	return 0;
}




	
