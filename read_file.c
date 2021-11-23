#include <stdio.h>
#include <ctype.h>
int alpha_pr(char);

int main(void)
{
    char ch;
    int pt;

    while((ch = getchar()) != EOF){
        if((pt = alpha_pr(ch)) != EOF){
            printf(" %d ", pt);
        }    
    }

    return 0;
}
int alpha_pr(char ch)
{
    int pt;

    if(isupper(ch)){
        pt = ch - 'A' + 1;    
    }
    else if(islower(ch)){
        pt = ch - 'a' + 1;
    }
    else{
        pt = -1;
    }

    return pt;
}