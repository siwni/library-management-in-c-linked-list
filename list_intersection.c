#include "header.h"
employee_type* list_intersection(employee_type* list1,employee_type* list2)
{
	employee_type *list3,*ptr1,*ptr2,*ptr3,*nptr;
	list3=NULL;
	ptr3=list3;
	ptr1=list1;
	ptr2=list2;
	while(ptr1!=NULL && ptr2!=NULL)	/* Both lists are non-empty */
	{
		if(strcmp(ptr1->employee_name,ptr2->employee_name)>0)	/* ptr2 is incremented to find match of ptr1 */
		{
			ptr2=ptr2->next;
		}	
		else if(strcmp(ptr1->employee_name,ptr2->employee_name)<0)		/* ptr1 is incremented to find match of ptr2 */
		{
			ptr1=ptr1->next;
		}
		else	/* Employee name of ptr1 and ptr2 are same */
		{
			if(strcmp(ptr1->project_name,ptr2->project_name)>0)		/* ptr2 is incremented to find match of ptr1 */
			{
				ptr2=ptr2->next;
			}	
			else if(strcmp(ptr1->project_name,ptr2->project_name)<0)	/* ptr1 is incremented to find match of ptr2 */
			{
				ptr1=ptr1->next;	
			}	
			else		/* Project name of ptr1 and ptr2 are also same */
			{
				nptr=make_node(ptr1->employee_name,ptr1->project_name,ptr1->numHrs,ptr1->employee_salary,ptr1->employee_address,ptr1->phone_number);
				if(list3==NULL)
				{
					list3=nptr;	
				}
				else
				{
					ptr3->next=nptr;
				}
				ptr1=ptr1->next;
				ptr2=ptr2->next;	
				ptr3=nptr;		
			}
		}
	}
	return list3;
}
