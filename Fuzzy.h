#ifndef __FUZZY_H
#define __FUZZY_H

#include "InputMembership.h"
#include "OutputMembership.h"
#include "Membership.h"
#include "Rule.h"



struct FuzzyInput
{
	InputMembership *Inputx;
	struct FuzzyInput *next;
};
void setFuzzyInput(FuzzyInput*,InputMembership*);
FuzzyInput* FuzzyInputInit(FuzzyInput *Inputs);


struct FuzzyOutput
{
	OutputMembership *Outputx;
	float result;
	struct FuzzyOutput *next;
};
void setFuzzyOutput(FuzzyOutput*,OutputMembership*);
FuzzyOutput* FuzzyOutputInit(FuzzyOutput *Outputs);




struct FuzzyRule
{
	FuzzyInputRule *Rule;
	OutputMembership *Output;
	MembershipPoint	 *outputMembership;
	struct FuzzyRule *next;
	uint8_t counter=0;
	float result;
};
FuzzyRule* FuzzyRuleInit(FuzzyRule*);
void setFuzzyRule(FuzzyRule*,FuzzyInputRule*,OutputMembership*,MembershipPoint*);


struct Fuzzy
{
    FuzzyInput *Input;
	FuzzyOutput *Output;
	FuzzyRule *Rules;
};
void setFuzzy(Fuzzy*,FuzzyInput*,FuzzyOutput*,FuzzyRule*);
Fuzzy* FuzzyInit(Fuzzy *fuzzy);

void addFuzzyRule(Fuzzy*, FuzzyRule*);


float calculateFuzzyMode(FuzzyRule*);
void fuzzify(Fuzzy*,float array[]);
float defuzzify(Fuzzy*);
#endif
