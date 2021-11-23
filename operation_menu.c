#include <stdio.h>
#include <ctype.h>

char get_choice(void);
char get_first(void);
void add(void);
void subtract(void);
void multiply(void);
void divide(void);
double get_num1(void);
double get_num2(void);

int main(void)
{
    char choice;

    choice = get_choice();
    while(choice != 'q'){
        switch (choice)
        {
        case 'a': add();
            break;
        case 's': subtract();
            break;
        case 'm': multiply();
            break;
        case 'd': divide();
            break;
        default: printf("Program Error!\n");
            break;
        }
        choice = get_choice();
    }
    printf("Bye.\n");

    return 0;
}

char get_choice(void)
{
    char ch;

    printf("Enter the operation of your choice:\n");
    printf("a. add         s. subtract\n");
    printf("m. multiply    d. divide\n");
    printf("q. quit\n");
    ch = get_first();
    while(ch != 'a'&&ch != 's'&&ch != 'm'&&ch != 'd'&&ch != 'q'){
        printf("Please respond with a, s, m, d or q.\n");
        ch = get_first();
    }

    return ch;
}
char get_first(void)
{
    char ch;

    ch = getchar();
    while(!isalnum(ch)){
        ch = getchar();
    }
    while(getchar() != '\n'){
        continue;
    }

    return ch;
}
double get_num1(void)
{
    double n;
    char ch;

    printf("Enter first number: ");
    while(!scanf("%lf", &n)){
        while((ch = getchar()) != '\n'){
            putchar(ch);
        }
        printf(" is not a valid number.\nPlease ");
        printf("enter a number, such ad 2.5, -1.78E8, or 3: ");
    }

    return n;
}
double get_num2(void)
{
    double n;
    char ch;

    printf("Enter second number: ");
    while(!scanf("%lf", &n)){
        while((ch = getchar()) != '\n'){
            putchar(ch);
        }
        printf(" is not a valid number.\nPlease ");
        printf("enter a number, such ad 2.5, -1.78E8, or 3: ");
    }

    return n;
}
void add(void)
{
    double num1, num2;

    num1 = get_num1();
    num2 = get_num2();
    printf("%g + %g = %g\n", num1, num2, num1 + num2);
}
void subtract(void)
{
    double num1, num2;

    num1 = get_num1();
    num2 = get_num2();
    printf("%g - %g = %g\n", num1, num2, num1 - num2);
}
void multiply(void)
{
    double num1, num2;

    num1 = get_num1();
    num2 = get_num2();
    printf("%g * %g = %g\n", num1, num2, num1 * num2);
}
void divide(void)
{
    double num1, num2;

    num1 = get_num1();
    num2 = get_num2();
    while(num2 == 0){
        printf("Enter a number other than 0: ");
        while(!scanf("%lf", &num2)){
        printf("Please enter a number, such as 2.5, -1.78E8, or 3: ");
        }
    }
    printf("%g / %g = %g\n", num1, num2, num1 / num2);
}