#include <stdio.h>
void convert(unsigned long n, int nary);

int main(void)
{
    unsigned long num;
    int nary;

    printf("Enter an integer and a number to convert (q to quit): \n");
    while(scanf("%lu %d", &num, &nary) == 2){
    convert(num, nary);
    printf("\nEnter an integer and a number to convert (q to quit): \n");
    }
    return 0;
} 
void convert(unsigned long n, int nary)
{
    if(n >= 1){
        convert(n / nary, nary);
        printf("%lu", n % nary);
    }
} 