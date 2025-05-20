#include <stdio.h>

int main()
{
	
	char*s = "aaa";
	if( s = "aaa")
	{
		printf("equal");
	}
	
	int i, total;

	int *p;  /* wild pointer */
   	/* Some unknown memory location is being corrupted. 
  	 This should never be done. */ 
  	*p = 12;

	total = 0;
	for(i=0;i<10;i++)
		total += i;

	if(total != 45)
		printf("Failure\n");
	else
		printf("Success\n");

	return 0;
}
