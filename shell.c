#include <stdio.h>

void shell(int num[], int n);
int lenth(int n);

int main(void)
{
    int num[100];
    int i = 0, n;

    while(scanf("%d", &num[i]) == 1){
        i++;
    }
    shell(num, i);
    printf("%d", num[0]);
    for(n = 1;n < i;n++){
        printf(" %d", num[n]);
    }

    return 0;
}
void shell(int num[], int n)
{
    int len, i, j, k;

    for(len = lenth(n);len >= 1;len = (len + 1)/2 - 1){
        for(i = len;i < n;i++){
            for(j = i;j >= len&&num[j] < num[j-len];j -= len){
                k = num[j];
                num[j] = num[j-len];
                num[j-len] = k;
            }
        }
    }
}
int lenth(int n)
{
    int i = 1;

    while(i <= n){
        i = (i+1)*2 - 1;
    }
    i = (i + 1)/2 - 1;

    return i;
}