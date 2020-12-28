#include "OutputMembership.h"

OutputMembership* OutputMembershipInit(OutputMembership *Output, int id)
{
	Output=(struct OutputMembership *) malloc (sizeof (struct OutputMembership));
	Output->next=NULL;
	Output->Membership=NULL;
	Output->id=id;
	return Output;
}

void setOutputMembership(OutputMembership *Output,MembershipPoint *Membership)
{
	OutputMembership *current = Output;
	if(current->Membership==NULL)
	{
		current->Membership = Membership;
	}
	else
	{
		while (current->next != NULL) 
		{
	        current = current->next;
	    }
		current->next = (struct OutputMembership *) malloc (sizeof (struct OutputMembership));
	    current->next->Membership = Membership;
	    current->next->next = NULL;		
	}
}
