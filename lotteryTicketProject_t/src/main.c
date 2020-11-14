#include <stdio.h>
#include "userLink.h"

int main(int argc , char** argv)
{
	
		
	userlink_t* head = init_userLink();
	loadUserlink(head);
	showUserlink(head);
	addUserlinkNode(head);
	addUserlinkNode(head);
	showUserlink(head);
	saveUserlink(head);
	freeUserlink(head);
	return 0;
}



