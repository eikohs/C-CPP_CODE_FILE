#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define SIZE 150
#define LEN 10
#define Line "************************************************************"
#define BR "*                                                          *"
char pr_menu_cho(void);
void put_a(char (*st)[SIZE], int len);
void put(char * st[LEN], int len, char ch);
int length(int n);
int cmp(char * st1, char * st2, char mode);
char * s_gets(char * st, int n);

int main(void)
{
    int i;
    char ch;
    char str[LEN][SIZE];
    char * strs[LEN];

    printf("Please enter %d strings: \n", LEN);
    for(i = 0;i < LEN;i++){
        s_gets(*(str+i), SIZE);
        strs[i] = *(str + i);
    }
    while((ch = pr_menu_cho()) != 'q'){
        if(ch == 'a'){
            put_a(str,LEN);
        }
        else{
            put(strs,LEN,ch);
        }
        puts(Line);
        puts("Enter any key to continue.");
        while(getchar() != '\n'){
            continue;
        }
    }
    puts("Bye! See you!");

    return 0;
}
char pr_menu_cho(void)
{
    char ch;

    puts(Line);
    puts("* Choose from {a, b, c, d, q}, I will finish that          *\n"BR);
    puts("* |a| : display all the strings in original order          *\n"BR);
    puts("* |b| : sort and display the strings in ASCII order        *\n"BR);
    puts("* |c| : display all the strings in string-length order     *\n"BR);
    puts("* |d| : display all the strings in first-word-length order *\n"BR);
    puts("* |q| : quit the programme                                 *");
    puts(Line);
    while(1){    
    ch = getchar();
    if((ch < 'a'||ch > 'd')&&ch != 'q'){
        putchar(ch);
        while((ch = getchar()) != '\n'){
            putchar(ch);
        }
        puts(" is not a command I can realize, enter again");
    }
    else{
        while(getchar() != '\n'){
            continue;
        }
        break;
    }

    }

    return ch;
}
void put_a(char (*st)[SIZE], int len)
{
    int i;

    for(i = 1;i <= len;i++){
        printf("The %d.st string: ", i);
        puts(*(st + i - 1));
    }
}
void put(char *st[LEN], int len, char ch)
{
    int leth, i, j;
    char * pt;
    
    for(leth = length(len); leth >= 1; leth = (leth+1)/2 - 1){
        for(i = leth;i < len;i++){
            for(j = i;j >= leth&&cmp(*(st + j), *(st + j - leth), ch);j -= leth){
                pt = *(st + j);
                *(st + j) = *(st + j - leth);
                *(st + j - leth) = pt;    
            }
        }
    }
    for(i = 0;i < len;i++){
        puts(*(st + i));
    }
}
int length(int n)
{
    int result = 1;

    while(result < n){
        result = (result + 1)*2 - 1;
    }

    return (result + 1)/2 - 1;
}
int cmp(char * st1, char * st2, char mode){
    int ret_val = 0;
    
    switch(mode)
    {
        case 'b' :{
            if(strcmp(st1, st2) < 0){
                ret_val = 1;
            }
            break;
        }
        case 'c' :{
            if(strlen(st1) > strlen(st2)){
                ret_val = 1;
            }
            break;
        }
        case 'd' :{
            int len1 = 0;char * pt1 = st1;
            int len2 = 0;char * pt2 = st2;
            while(isspace(*pt1)){
                pt1++;
            }
            while(!isspace(*pt1)){
                pt1++;
                len1++;
            }
            while(isspace(*pt2)){
                pt2++;
            }
            while(!isspace(*pt2)){
                pt2++;
                len2++;
            }
            if(len1 > len2){
                ret_val = 1;
            }
        }
    }

    return ret_val;
}
char * s_gets(char * st, int n)
{
    char * pt;
    char * ret_val;

    ret_val = fgets(st, n, stdin);
    pt = st;
    while(*pt != '\n'){
        pt++;
    }
    *pt = '\0';
    
    return ret_val;
}