#ifndef __OUTPUTMEMBERSHIP_H
#define __OUTPUTMEMBERSHIP_H
#include "Membership.h"
struct OutputMembership
{
	MembershipPoint *Membership;
	int id;
	struct OutputMembership *next;
};
void setOutputMembership(OutputMembership*,MembershipPoint*);
OutputMembership* OutputMembershipInit(OutputMembership*,int);



#endif
