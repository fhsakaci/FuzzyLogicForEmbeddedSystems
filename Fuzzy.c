#include "Fuzzy.h"
#include <stdio.h>
#include <stdlib.h>


Fuzzy* FuzzyInit(Fuzzy *fuzzy)
{
	fuzzy=(struct Fuzzy *) malloc (sizeof (struct Fuzzy));
	fuzzy->Input=NULL;
	fuzzy->Output=NULL;
	fuzzy->Rules=NULL;
	return fuzzy;
}


void setFuzzy(Fuzzy* fuzzy,FuzzyInput* fuzzyinput,FuzzyOutput* fuzzyoutput,FuzzyRule* fuzzyrule)
{
	fuzzy->Input=fuzzyinput;
	fuzzy->Output=fuzzyoutput;
	fuzzy->Rules=fuzzyrule;
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




void fuzzify(Fuzzy *fuzzy, float inputArray[])
{
	float x1,x2,x3,sh,down,up,h,area,newArea;
	FuzzyInput *Inputs=fuzzy->Input;
	int i=0;
	while(Inputs!=NULL)
	{
		InputMembership *Membs=Inputs->Inputx;
		while(Membs!=NULL)
		{		
				// check the crispValue is small then A
	    if (inputArray[i] < Membs->Membership->d1)
	    {
	        // check if this FuzzySet represents "everithing small is true"
	        if (Membs->Membership->d1 == Membs->Membership->d2 && Membs->Membership->d2 != Membs->Membership->d3 && Membs->Membership->d3 != Membs->Membership->d4)
	        {
	            // if so, the pertinence is 1
	            Membs->Membership->degree = 1.0;
	        }
	        else
	        {
	            // else, pertinence is 0
	            Membs->Membership->degree = 0.0;
	        }
	    }
	    // check if the inputArray[i] is between A and B
	    else if (inputArray[i] >= Membs->Membership->d1 && inputArray[i] < Membs->Membership->d2)
	    {
	        // calculate a slope
	        float slope = 1.0 / (Membs->Membership->d2 - Membs->Membership->d1);
	        // calculate the value of pertinence
	        Membs->Membership->degree = slope * (inputArray[i] - Membs->Membership->d2) + 1.0;
	    }
	    // check if the pertinence is between B and C
	    else if (inputArray[i] >= Membs->Membership->d2 && inputArray[i] <= Membs->Membership->d3)
	    {
	        Membs->Membership->degree = 1.0;
	    }
	    // check if the pertinence is between C and D
	    else if (inputArray[i] > Membs->Membership->d3 && inputArray[i] <= Membs->Membership->d4)
	    {
	        // calculate a slope
	        float slope = 1.0 / (Membs->Membership->d3 - Membs->Membership->d4);
	        // calculate the value of pertinence
	        Membs->Membership->degree = slope * (inputArray[i] - Membs->Membership->d3) + 1.0;
	    }
	    // check the inputArray[i] is bigger then D
	    else if (inputArray[i] > Membs->Membership->d4)
	    {
	        // check if this FuzzySet represents "everithing bigger is true"
	        if (Membs->Membership->d3 == Membs->Membership->d4 && Membs->Membership->d3 != Membs->Membership->d2 && Membs->Membership->d2 != Membs->Membership->d1)
	        {
	            // if so, the pertinence is 1
	            Membs->Membership->degree = 1.0;
	        }
	        else
	        {
	            // else, pertinence is 0
	            Membs->Membership->degree = 0.0;
	        }
	    }
	
	//			if(Membs->Membership->d1>inputArray[i] || Membs->Membership->d4<inputArray[i])
	//			{
	//				Membs->Membership->degree=0;
	//			}
	//			else if(inputArray[i]>=Membs->Membership->d2 && inputArray[i]<=Membs->Membership->d3)
	//			{
	//				Membs->Membership->degree=1;
	//			}
	//			else
	//			{
	//				down=Membs->Membership->d4-Membs->Membership->d1;
	//				up=Membs->Membership->d3-Membs->Membership->d2;
	//				h=1;
	//				area=(up+down)*h/2;
	//				if(inputArray[i]>Membs->Membership->d3)
	//				{
	//					x1=inputArray[i]-Membs->Membership->d3;
	//					x2=Membs->Membership->d4-inputArray[i];
	//					sh=x2/(x1+x2);
	//					x3=1-sh*(Membs->Membership->d2-Membs->Membership->d1);
	//				}
	//				else
	//				{
	//					x1=Membs->Membership->d2-inputArray[i];
	//					x2=inputArray[i]-Membs->Membership->d1;
	//					sh=x2/(x1+x2);
	//					x3=1-sh*(Membs->Membership->d4-Membs->Membership->d3);
	//				}
	//				newArea=(down+x1+x3+Membs->Membership->d3-Membs->Membership->d2)*sh/2;
	//				float degree=newArea/area;
	//				Membs->Membership->degree=degree;
	//			}
	
	
				printf("%f\n",inputArray[i]);
				Membs=Membs->next;
			}
			Inputs=Inputs->next;
			i++;
	}
}




FuzzyRule* FuzzyRuleInit(FuzzyRule *fuzzyrule)
{
	fuzzyrule=(struct FuzzyRule *) malloc (sizeof (struct FuzzyRule));
	fuzzyrule->Output=NULL;
	fuzzyrule->Rule=NULL;
	fuzzyrule->outputMembership=NULL;
	fuzzyrule->next=NULL;
	return fuzzyrule;
}




void setFuzzyRule(FuzzyRule *FRule,FuzzyInputRule *InputRule,OutputMembership *Output,MembershipPoint *outputMembership)
{
	FuzzyRule *current=FRule;
	if(current->Rule==NULL&&current->Output==NULL&&current->outputMembership==NULL)
	{
		current->Rule=InputRule;
		current->Output=Output;
		current->outputMembership=outputMembership;
		current->counter=1;
	}
	else
	{
		
		while (current->next != NULL) 
		{
	        current = current->next;
	    }
	    current->next = (struct FuzzyRule*) malloc (sizeof (struct FuzzyRule));
	    current->next->Rule = InputRule;
	    current->next->Output=Output;
	    current->next->outputMembership=outputMembership;
	    current->counter++;
	    current->next->next = NULL;
	}
}


float calculateFuzzyMode(FuzzyRule *Rules)
{
	float result;
	switch(Rules->Rule->Mode)
	{
	case And:
		if(Rules->Rule->Membership1->degree > Rules->Rule->Membership2->degree)
		{
			result=Rules->Rule->Membership2->degree;
		}
		else
		{
			result=Rules->Rule->Membership1->degree;
		}
		
		if(Rules->outputMembership->degree <= 1 && Rules->outputMembership->degree < result)
			result=Rules->outputMembership->degree;
		
	break;
	case Or:
			
		if(Rules->Rule->Membership1->degree > Rules->Rule->Membership2->degree)
		{
			result=Rules->Rule->Membership1->degree;
		}
		else
		{
			result=Rules->Rule->Membership2->degree;
		}	
		
		if(Rules->outputMembership->degree <= 1 && Rules->outputMembership->degree > result)
				result=Rules->outputMembership->degree;
				
		break;
	case Single:
			result=Rules->Rule->Membership1->degree;
	break;
	}
	return result;
}



float calculateOutput(FuzzyRule *Rules)
{
	FuzzyRule *current=Rules;
	float* myPoints;
	float* myPointsDegree;
	float sum,div;
	int counter=0;
	myPoints =(float*) malloc(sizeof(float) *128);
	myPointsDegree=(float*) malloc(sizeof(float) * 128);
	while(current!=NULL)
	{
		
		MembershipPoint *currentMembership = current->outputMembership;
		if(currentMembership->degree==0)
		{
			myPoints[6*counter+0] = currentMembership->d1;
			myPoints[6*counter+1] = (currentMembership->d1+(currentMembership->d2-(currentMembership->d2-currentMembership->d1)*(1-currentMembership->degree)))/2;
			myPoints[6*counter+2] = currentMembership->d2-(currentMembership->d2-currentMembership->d1)*(1-currentMembership->degree);
			myPoints[6*counter+3] = currentMembership->d3+(currentMembership->d4-currentMembership->d3)*(1-currentMembership->degree);
			myPoints[6*counter+4] = (currentMembership->d3+(currentMembership->d4-currentMembership->d3)*(1-currentMembership->degree)+currentMembership->d4)/2;
			myPoints[6*counter+5] = currentMembership->d4;
				
			myPointsDegree[6*counter+0] = 0;
			myPointsDegree[6*counter+1] = 0;
			myPointsDegree[6*counter+2] = 0;
			myPointsDegree[6*counter+3] = 0;
			myPointsDegree[6*counter+4] = 0;
			myPointsDegree[6*counter+5] = 0;
		}
		else
		{
			
			myPoints[6*counter+0] = currentMembership->d1;
			myPoints[6*counter+1] = (currentMembership->d1+(currentMembership->d2-(currentMembership->d2-currentMembership->d1)*(1-currentMembership->degree)))/2;
			myPoints[6*counter+2] = currentMembership->d2-(currentMembership->d2-currentMembership->d1)*(1-currentMembership->degree);
			myPoints[6*counter+3] = currentMembership->d3+(currentMembership->d4-currentMembership->d3)*(1-currentMembership->degree);
			myPoints[6*counter+4] = (currentMembership->d3+(currentMembership->d4-currentMembership->d3)*(1-currentMembership->degree)+currentMembership->d4)/2;
			myPoints[6*counter+5] = currentMembership->d4;
				
			myPointsDegree[6*counter+0] = 0;
			myPointsDegree[6*counter+1] = currentMembership->degree/2;
			myPointsDegree[6*counter+2] = currentMembership->degree;
			myPointsDegree[6*counter+3] = currentMembership->degree;
			myPointsDegree[6*counter+4] = currentMembership->degree/2;
			myPointsDegree[6*counter+5] = 0;
		}
		current=current->next;
		counter++;
	}
//		for(int i=0;i<4*counter;i++)
//		{
//			for(int j=0;j<4*counter;j++)
//			{
//				if(myPoints[i]>=myPoints[j] && myPoints[i+1]<=myPoints[j])
//				{
////					if(myPointsDegree[i]>myPointsDegree[j])
////					{
////						myPointsDegree[j]=myPointsDegree[i];
////					}
////					else
////					{
////						myPointsDegree[i]=myPointsDegree[j];
////					}
//				}
//			}
//		}
		sum=0;
		div=0;
		for(int i=0;i<6*counter;i++)
		{
			sum+=myPoints[i]*myPointsDegree[i];
			div+=myPointsDegree[i];		
//			printf("%f %f\n",myPoints[i],myPointsDegree[i],sum/div);	
		}
		if(div==0)
			return sum;
		else
			return sum/div;
}




float defuzzify(Fuzzy* fuzzy)
{
	float result;
	FuzzyRule *Rules=fuzzy->Rules;
	FuzzyRule *RulesForOutput=fuzzy->Rules;
	OutputMembership *RulesOutput=fuzzy->Rules->Output;
	FuzzyOutput *Outputs=fuzzy->Output;
	
	while(Rules!=NULL)
	{
		result=calculateFuzzyMode(Rules);
		Rules->outputMembership->degree=result;		
		Rules=Rules->next;
	}
	
	result = calculateOutput(RulesForOutput);
	return result;
}

void FuzzyClean(Fuzzy *fuzzy)
{
	
}

