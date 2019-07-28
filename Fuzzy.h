#ifndef __FUZZY_H
#define __FUZZY_H

#include "InputMembership.h"
#include "OutputMembership.h"
#include "Membership.h"



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
	struct FuzzyOutput *next;
};
void setFuzzyOutput(FuzzyOutput*,OutputMembership*);
FuzzyOutput* FuzzyOutputInit(FuzzyOutput *Outputs);

struct Fuzzy
{
    FuzzyInput *Input;
	FuzzyOutput *Output;
};
void setFuzzy(Fuzzy*,FuzzyInput*,FuzzyOutput*);
Fuzzy* FuzzyInit(Fuzzy *fuzzy);
#endif
