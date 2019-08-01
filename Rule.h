#ifndef __RULE_H
#define __RULE_H
#include "InputMembership.h"
#include "Stdint.h"


typedef enum
{
	Single =	1,
	And	   =	2,
	Or	   =	3
}FuzzyRuleMode;

typedef enum
{
	MOM	=	1,
	COM =	2,
	COA =	3
}DefuzzicationMode;


struct FuzzyInputRule
{
	FuzzyRuleMode Mode;
	InputMembership *FuzzyInput1;
	MembershipPoint *Membership1;
	InputMembership *FuzzyInput2;
	MembershipPoint *Membership2;
	uint8_t counter=0;
	struct FuzzyInputRule *next;
};


FuzzyInputRule* AddRuleAND(InputMembership *Input1,MembershipPoint *Membership1, InputMembership *Input2,MembershipPoint *Membership2);
FuzzyInputRule* AddRuleOR(InputMembership *Input1,MembershipPoint *Membership1, InputMembership *Input2,MembershipPoint *Membership2);
FuzzyInputRule* AddRuleSingle(InputMembership *Input1,MembershipPoint *Membership1);


#endif
