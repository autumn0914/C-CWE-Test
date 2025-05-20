#include <stdio.h>
#include "an.h"
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>


int square(int x);

float Division(float num, float den)
{
    // return the result of division
    return (num / den);

} 

int main()
{
	//char *p = (char *)malloc(10);

	int stackarray[3];
    int *pt = stackarray;  // array_assign
    //free(pt);              // incorrect_free

    char c;
    c = getchar();

    float numerator = 12.5;
    float denominator = 0;
    float result;

    // calls Division function
    result = Division(numerator, denominator);


	return 1;
}


int square(int x) {
    return x*x;
}

void loop(int x);  
int example(int a, int b, int x, int y) {
    int result = 0;
    if (a > 0) {
        result = square(a) + square(x);
    }
    if (a > 0) {
        // "square(a)" should read "square(b)"
        result = square(b) + square(y);
    }

   // int val = 5;
   // int iZero = 0;
   //int zeTest = 5/0;

   // divided by zero
   float nn = 0.0;
   float mm = 4.0;
   float fb = 1.0/nn;
   fb = 1.0/mm;	

    loop(result);

    return result;
}


int foo(int y) {
    if (y < 0) {
        return 0;
    }
    return y;
}
            
void bar(int y) {
    int z = 1 / foo(y);
    float f_b = 0.0;
    float f_r = foo(y)/f_b;
    
}

void test(int i) {
    int n ;
    int x = 3.0;
    //char *p = malloc(n);       
    int y = n;    //  Valid indices are buffer[0] to buffer[y - 1]
    //p[y] = 'a';   //  Defect: writing to buffer[y] overruns local buffer

    //coverity[leaked_storage : SUPPRESS]
    
}

struct s {
    int a;
    int b;
} s1;
          
void overrun_test2() {
    int n, i;  
    struct s  *p = malloc(n * sizeof(struct s));
    if (i <= n)     //  "i" can be equal to n 
        p[i] = s1;  // Defect: overrun of buffer p
    //int *pt = myIntArraryMalloc(10);
    //pt[1] = 1;
    //free(pt);

}


void access_dbuffer(int *x, int n) {
    x[n-1] = 1;
}
void overrun_caller(int n) {
    int array[10];
    if (n < 100) {
        access_dbuffer(array, n); // defect
    }
}

void callee1(int *x) {
    x[10] = 1;
}

void callee2(int *x) {
    callee1(x); //Calling "callee1(int *)" indexes array "x" at byte position 40.
}

void overrun_caller3() {
    int x[5];
    callee2(x);
}

void testATOMICITY()
{

}

typedef void *HANDLE;
void testHardcode() {
    char password[] = "ABCD1234!";
    HANDLE pHandle;
    //LogonUserA("User", "Domain", password, 3, 0, &pHandle);
        // HARDCODED_CREDENTIALS defect at preceding statement
}


void loop(int x)
{
    int i=0;
    while (1) {
      if (i >= 10) {
        if (x == 55) { // x is never updated
          break;
        }
      }
      i++;
    }
}

void testAccFile()
{
   
}



struct S { int a[4]; };
void bad_free_fn(struct S *s) {
    int stackarray[3];
    int *p = stackarray;  // array_assign
    free(p);              // incorrect_free

    free(s->a);           // array_free
}



int (*fnptr)(int);
void bad_free_fn2() {
    free(fnptr);         // fnptr_free
}

void command_inj_bug(int socket) {
    char message[1024];
    if (recv(socket, message, sizeof(message), 0) > 0) {
        system(message);       // OS_CMD_INJECTION defect 
    }
}

