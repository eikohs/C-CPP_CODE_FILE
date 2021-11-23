#include <stdio.h>

void print(int n, int len);

int main(void)
{
    int len;
    int n = 1;

    scanf("%d", &len);
    print(n, len);

    return 0;
}
void print(int n, int len)
{
    int i;
    for(i = n;i < len;i++){
        putchar(' ');
    }
    for(i = 1;i <= 2*n - 1;i++){
        putchar('*');
    }
    putchar('\n');
    if(n < len){
        print(n+1, len);
        for(i = n;i < len;i++){
           putchar(' ');
        }
        for(i = 1;i <= 2*n - 1;i++){
           putchar('*');
        }
        putchar('\n');
    }
}