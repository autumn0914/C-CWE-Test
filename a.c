#include <stdio.h>

extern void test(int i);

typedef unsigned short int uint16_t;
typedef unsigned char uint8_t;

int main()
{
	int i, total;

	char*s = "aaa";
	if( s == "aaa")
	{
		printf("equal");
	}

	//if( strcmp(s, "aaa") == 1)
	//{
	//	printf("equal");
	//}

	int a [10] = {1,2,3,4,5,6,7,8,9,0};
	int b;

	uint16_t u = 0xEEFF;
	uint8_t u8 = u;

	total = 0;
	for(i=0;i<10;i++)
		total += i;

	if(total != 45)
		printf("Failure\n");
	else
		printf("Success\n");

	if(total < -1 && total > 18)
		printf("No good");

	int y, z;
	if (total==0) {
  	 	y=32;
   		z=y*2;
	} else {
  		y=32;
  		z=y*2;
	}

	switch(total)
	{
		case 0:
			printf("0\n");
			//break;
		case 10:
			printf("10\n");
			break;
		case 45:
			printf("45\n");
			break;
		case 90:
			printf("90\n");
			break;
		default:
			break;
	}


	test(total);


	signed char vp = -4;
	char strDest[40] = {0};
	char strDest2[40] = {0};

	snprintf(strDest, 40, "neighbor %hhd!", (unsigned char)vp);

	snprintf(strDest2, 40, "neighbor %c!", vp);

	printf("%c test", (unsigned char)vp);
	
	printf("%d test", (unsigned char)vp);

	return 0;
}



struct bigStc {
    int a[20];
    int b[20];
    int c[20];
};

void bug1(const char *s) {
    //if (strcmp(s, "blah") == 1) { /* ... */ }
}

void bug2(const char *s) {
    if (s == "blah") { /* ... */ }
}

char* getvalue()
{
	char* s= "value";
	return s;
}

void bug3() {
	if (getvalue() == "blah") { /* ... */ }
}
// coverity[pass_by_value:FALSE]
void funStruct(struct bigStc b) {   // Warning: passing by value, 240 bytes
	//return sizeof(b);
}

void handle_error(){
	printf("error pointer here!!!");
}


//#define LOOP_VALUE 5
const int LOOP_VALUE = 5;
int deadcode_example1(int *p) {
    
	//for(count = 0U;count < LOOP_VALUE; count++)
	//{
	//	handle_error();
	//}  
	
	if( p == NULL ) {
        return -1;
    }

    //use_p( *p );
    if ( p == NULL ) {      // p cannot be null.
		
        handle_error();     // Defect: dead code
        return -1;         
    }

	int count; 
	

    return 0;
}
