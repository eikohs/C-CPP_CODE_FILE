#include <stdio.h>
#include <string.h>
#define SIZE 81
char * s_gets(char * st, int n);
char * string_in(char * st1, char * st2);

int main(void)
{
    char str1[SIZE], str2[SIZE];
    char * pt;
    int len1, len2, i;
    int flag, galf;

    s_gets(str1, SIZE);s_gets(str2, SIZE);
    len1 = strlen(str1);len2 = strlen(str2);
    while(1){
        galf = 0;
        pt = str1;
        while(pt <= str1 - len2 + len1){
            if(*pt == *str2){
                for(flag = i = 1;i < len2;i++){
                    if(*(pt+i) != *(str2+i)){
                        flag = 0;
                        break;
                    }
                }
                if(flag){
                    i = 0;
                    galf = 1;
                    while(pt + len2 < str1 + len1){
                        *pt = *(pt + len2);
                        pt++;
                    }
                    *pt = '\0';
                len1 -= len2;
                break;
                }
            }
            pt++;
        }
        if(!galf){
            break;
        }
    }
    puts(str1);

    return 0;
}
char * s_gets(char * st, int n)
{
    char * ret_val;
    char * find;

    ret_val = fgets(st, n, stdin);
    find = strchr(st, '\n');
    if(find){
        *find = '\0';
    }
    else{
        while(getchar() != '\n'){
            continue;
        }
    }

    return ret_val;
}
char * string_in(char * st1, char * st2)
{
    char * pt;
    int i, flag;

    pt = st1;
    flag = 0;
    while(*pt != '\0'&&!flag){
        if(*pt == *st2){
            for(i = 0;*(st2 + i) != '\0';i++){
                if(*(pt+i) != *(st2+i)){
                    break;
                }
            }
            if(*(st2+i) == '\0'){
                flag = 1;
            }
        }
        pt++;
    }
    if(!flag){
        pt = NULL;
    }

    return pt;
}