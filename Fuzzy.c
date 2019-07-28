#include "Fuzzy.h"
#include <stdio.h>
#include <stdlib.h>


Fuzzy* FuzzyInit(Fuzzy *fuzzy)
{
	fuzzy=(struct Fuzzy *) malloc (sizeof (struct Fuzzy));
	fuzzy->Input=NULL;
	fuzzy->Output=NULL;
	return fuzzy;
}


void setFuzzy(Fuzzy* fuzzy,FuzzyInput* fuzzyinput,FuzzyOutput* fuzzyoutput)
{
	fuzzy->Input=fuzzyinput;
	fuzzy->Output=fuzzyoutput;
}

FuzzyInput* FuzzyInputInit(FuzzyInput *Inputs)
{
	Inputs=(struct FuzzyInput *) malloc (sizeof (struct FuzzyInput));
	Inputs->next=NULL;
	Inputs->Inputx=NULL;
	return Inputs;
}

void setFuzzyInput(FuzzyInput* InputArray,InputMembership *newInput)
{
	FuzzyInput *current = InputArray;
	if(current->Inputx==NULL)
	{
		current->Inputx = newInput;
	}
	else
	{
		while (current->next != NULL) 
		{
	        current = current->next;
	    }
		current->next = (struct FuzzyInput *) malloc (sizeof (struct FuzzyInput));
	    current->next->Inputx = newInput;
	    current->next->next = NULL;		
	}
}









FuzzyOutput* FuzzyOutputInit(FuzzyOutput *Outputs)
{
	Outputs=(struct FuzzyOutput *) malloc (sizeof (struct FuzzyOutput));
	Outputs->next=NULL;
	Outputs->Outputx=NULL;
	return Outputs;
}

void setFuzzyOutput(FuzzyOutput* OutputArray,OutputMembership *newOutput)
{
	FuzzyOutput *current = OutputArray;
	if(current->Outputx==NULL)
	{
		current->Outputx = newOutput;
	}
	else
	{
		while (current->next != NULL) 
		{
	        current = current->next;
	    }
		current->next = (struct FuzzyOutput *) malloc (sizeof (struct FuzzyOutput));
	    current->next->Outputx = newOutput;
	    current->next->next = NULL;		
	}
}









