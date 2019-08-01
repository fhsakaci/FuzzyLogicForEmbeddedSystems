#ifndef __Membership_H
#define __Membership_H
#include <stdlib.h>
struct MembershipPoint
{
	float d1;
	float d2;
	float d3;
	float d4;
	struct MembershipPoint *next;
	float degree=0;
};
MembershipPoint* setMembershipPoint(float,float,float,float);

#endif
