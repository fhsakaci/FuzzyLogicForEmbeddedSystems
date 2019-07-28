#include "InputMembership.h"
InputMembership* InputMembershipInit(InputMembership *Input, int id)
{
	Input=(struct InputMembership *) malloc (sizeof (struct InputMembership));
	Input->next=NULL;
	Input->Membership=NULL;
	return Input;
}

void setInputMembership(InputMembership *Input,MembershipPoint *Membership)
{
	InputMembership *current = Input;
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
		current->next = (struct InputMembership *) malloc (sizeof (struct InputMembership));
	    current->next->Membership = Membership;
	    current->next->next = NULL;		
	}
}

