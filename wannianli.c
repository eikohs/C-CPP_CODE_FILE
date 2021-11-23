#include <stdio.h>
#include <stdlib.h>
const int num[2] = {365, 366};
const int m_num[4] = {31, 30, 28, 29};
int is_run(int yea);
int m_day(int yea, int mon);

int main(void)
{
    int year,month;
    int init, i;

    puts("Please input the year and the mouth:");
    puts("And I will print a calendar for you.");
    while(scanf("%d %d", &year, &month) == 2){
        if(year >= 2001){
            for(i = 0, init = 1;i < year - 2001;i++){
                init += is_run(i+2001)%7;
            }
        }
        else{
            if(year != 1582){
                for(i = 1, init = 1;i <= 2001 - year;i++){
                    init -= is_run(2001 - i)%7;
                }
                init = 7 + init%7;
            }
        }
        for(i = 1;i < month;i++){
            switch (i)
            {
            case 1 : case 3: case 5: case 7: case 8: case 10: case 12 : init += m_num[0]%7;break;
            case 4 : case 6: case 9: case 11: init += m_num[1]%7;break;
            case 2 : init += (is_run(year) > 365? 29 : 28)%7;break;
            }
        }
        init %= 7;
        puts("Sun. Mon. Tue. Wed. Thu. Fri. Sat.\n");
        for(i = 0;i < init&&init != 7;i++){
            printf("     ");
        }
        for(i = 1;i <= m_day(year, month);i++, init++){
            printf("%3d  ", i);
            if((init+1)%7 == 0){
                putchar('\n');
                putchar('\n');
            }
        }
        init = 0;
        putchar('\n');
    }

    return 0;
}
int is_run(int yea)
{
    if((yea%4 == 0&&yea%100 != 0)||yea % 400==0){
        return num[1];
    }
    else if(yea != 1582){
        return num[0];
    }
    else{
        return 374;
    }
}
int m_day(int yea, int mon)
{
    int ret_val;

    switch (mon)
    {
        case 1 : case 3: case 5: case 7: case 8: case 10: case 12 : ret_val = m_num[0];break;
        case 4 : case 6: case 9: case 11: ret_val = m_num[1];break;
        case 2 : ret_val = (is_run(yea) > 365? m_num[3] : m_num[2]);break;
    }

    return ret_val;
}