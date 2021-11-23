#include <stdio.h>

int main(void)
{
    int m, n;
    int temp, bst;
    long int big;

    scanf("%d %d", &m, &n);
    if(m < n){
        m += n;
        n = m - n;
        m -= n;
    }
    bst = m%n;
    big = m*n;
    while(bst != 0){
        temp = bst;
        bst = n%bst;
        n = temp;
    }
    printf("%d %ld", n, big/n);

    return 0;    
}