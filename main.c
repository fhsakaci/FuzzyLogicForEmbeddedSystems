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
	
	MembershipPoint *L1=setMembershipPoint(40,50,50,60);
	MembershipPoint *L2=setMembershipPoint(50,60,60,70);
	MembershipPoint *L3=setMembershipPoint(70,90,90,110);
	
	
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

	OutputMembership *Output1;
	Output1=OutputMembershipInit(Output1,1);
	setOutputMembership(Output1,L1);
	setOutputMembership(Output1,L2);
	setOutputMembership(Output1,L3);
	
	FuzzyInput *Inputs;
	Inputs=FuzzyInputInit(Inputs);
	setFuzzyInput(Inputs,Input1);
	setFuzzyInput(Inputs,Input2);
	
	FuzzyOutput *Outputs;
	Outputs=FuzzyOutputInit(Outputs);
	setFuzzyOutput(Outputs,Output1);
	
	Fuzzy *fuzzy;
	fuzzy=FuzzyInit(fuzzy);
	
	FuzzyRule* Rules;
	Rules=FuzzyRuleInit(Rules);
	FuzzyInputRule *LowAndSLow=AddRuleAND(Input1,Low,Input2,SLow);
	FuzzyInputRule *MediumAndMiddle=AddRuleAND(Input1,Medium,Input2,Middle);
	FuzzyInputRule *highandfast=AddRuleAND(Input1,high,Input2,Fast);
	setFuzzyRule(Rules,LowAndSLow,Output1,L3);
	setFuzzyRule(Rules,highandfast,Output1,L2);
	setFuzzyRule(Rules,MediumAndMiddle,Output1,L1);
	
	
	
	setFuzzy(fuzzy,Inputs,Outputs,Rules);


	float x[2];
	x[1]=10.5;
	float sonuc;
	for(float i=2.8;i<5;i=i+0.5)
	{
	x[0]=i;
	fuzzify(fuzzy,x);
	sonuc=defuzzify(fuzzy);
	printf("Input 1 degree: %f\n",Rules->outputMembership->degree);
	printf("Input 2 degree: %f\n",Rules->next->outputMembership->degree);
	printf("Input 3 degree: %f\n",Rules->next->next->outputMembership->degree);
	printf("%f %f : %f\n",x[0],x[1],sonuc);
	}
	
	return 0;
}




	
