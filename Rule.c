#include "Rule.h"

FuzzyInputRule* AddRuleAND(InputMembership *Input1,MembershipPoint *Membership1, InputMembership *Input2,MembershipPoint *Membership2)
{
	FuzzyInputRule *Rule;
	Rule=(struct FuzzyInputRule *) malloc (sizeof (struct FuzzyInputRule));
	Rule->Mode=And;
	Rule->FuzzyInput1=Input1;
	Rule->Membership1=Membership1;
	Rule->FuzzyInput2=Input2;
	Rule->Membership2=Membership2;
	return Rule;
}

FuzzyInputRule* AddRuleOR(InputMembership *Input1,MembershipPoint *Membership1, InputMembership *Input2,MembershipPoint *Membership2)
{
	FuzzyInputRule *Rule;
	Rule=(struct FuzzyInputRule *) malloc (sizeof (struct FuzzyInputRule));
	Rule->Mode=Or;
	Rule->FuzzyInput1=Input1;
	Rule->Membership1=Membership1;
	Rule->FuzzyInput2=Input2;
	Rule->Membership2=Membership2;
	return Rule;
}

FuzzyInputRule* AddRuleSingle(InputMembership *Input1,MembershipPoint *Membership1)
{
	FuzzyInputRule *Rule;
	Rule=(struct FuzzyInputRule *) malloc (sizeof (struct FuzzyInputRule));
	Rule->Mode=Single;
	Rule->FuzzyInput1=Input1;
	Rule->Membership1=Membership1;
	Rule->FuzzyInput2=NULL;
	Rule->Membership2=NULL;
	return Rule;
}
