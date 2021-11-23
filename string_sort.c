#include <stdio.h>
#include <string.h>
#define SIZE 11
char * s_gets(char * st, int n);

int main(void)
{
    int time, step, i;
    int j;
    scanf("%d %d", &time, &step);
    char st[time][SIZE];
    char temp[SIZE];

    getchar();
    for(i = 0;i < time;i++){
        s_gets(*(st+i), SIZE);
    }
    for(i = 0;i < step;i++){
        for(j = 0;j < time - 1 - i;j++){
            if(strcmp(*(st + j), *(st + j + 1)) > 0){
                strcpy(temp, *(st + j));
                strcpy(*(st + j), *(st + j + 1));
                strcpy(*(st + j + 1), temp);
            }
        }
    }
    for(i = 0;i < time;i++){
        puts(*(st + i));
    }
    
    return 0;
}
char * s_gets(char * st, int n)
{
    char * rev_val;
    char * pt = st;

    rev_val = fgets(st, n, stdin);
    while(*pt != '\n'&&*pt != '\0'){
        pt++;
    }
    if(*pt == '\n'){
        *pt = '\0';
    }
    else{
        while(getchar() != '\n'){
            continue;
        }
    }

    return rev_val;
}