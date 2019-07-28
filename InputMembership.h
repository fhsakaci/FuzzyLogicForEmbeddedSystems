#ifndef __INPUTMEMBERSHIP_H
#define __INPUTMEMBERSHIP_H
#include "Membership.h"
struct InputMembership
{
	MembershipPoint *Membership;
	struct InputMembership *next;
};
void setInputMembership(InputMembership*,MembershipPoint*);


InputMembership* InputMembershipInit(InputMembership*,int);


#endif
