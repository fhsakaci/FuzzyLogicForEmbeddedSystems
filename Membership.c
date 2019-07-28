#include "Membership.h"

MembershipPoint* setMembershipPoint(float d1,float d2,float d3,float d4)
{
	MembershipPoint *setPoints;
	setPoints=(struct MembershipPoint *) malloc (sizeof (struct MembershipPoint));
	setPoints->d1=d1;
	setPoints->d2=d2;
	setPoints->d3=d3;
	setPoints->d4=d4;
	return setPoints;
}
