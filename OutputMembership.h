#ifndef __OUTPUTMEMBERSHIP_H
#define __OUTPUTMEMBERSHIP_H
#include "Membership.h"
struct OutputMembership
{
	MembershipPoint *Membership;
	struct OutputMembership *next;
};
void setOutputMembership(OutputMembership*,MembershipPoint*);
OutputMembership* OutputMembershipInit(OutputMembership*,int);



#endif
