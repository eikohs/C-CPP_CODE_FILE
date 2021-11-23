#include <stdio.h>
#include <math.h>

int main(void)
{
    double x;
    double s1, s2;
    for(x = -100.0;x <= 10000;x++){
        s1 = sqrt(x + 100);s2 = sqrt(x + 268);
        if(s1 == (int)s1&&s2 == (int)s2){
            printf("%.0lf\n", x);
        }
    }

    return 0;
}