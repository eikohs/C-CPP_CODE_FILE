#include <stdio.h>
int row, column;
int dr, dc, step = 0;
int min;
int pace[4][2] = {
    {0, 1}, {0, -1}, {-1, 0}, {1, 0}
};
void dsf(int xr, int xc, int (*pam)[column]);

int main(void)
{
    scanf("%d %d", &row, &column);
    int map[row][column];
    int i;
    int sr, sc;

    for(i = 0;i < row*column;i++){
        scanf("%d", *map + i);
    }
    scanf("%d %d %d %d", &sr, &sc, &dr, &dc);
    dr--;dc--;
    min = row*column;
    map[sr-1][sc-1] = 1;
    dsf(sr-1, sc-1, map);
    printf("%d", min);

    return 0;
}
void dsf(int xr, int xc, int (*pam)[column])
{
    if(xr == dr&&xc == dc){
        if(step < min){
            min = step;
        }
        return ;
    }
    else{
        int k;
        int tr = xr, tc = xc;
        for(k = 0;k < 4;k++){
            tr = xr + pace[k][0];
            tc = xc + pace[k][1];
            if(tr < 0||tr >= row||tc < 0||tc >= column||pam[tr][tc]){
                continue;
            }
            pam[tr][tc] = 1;
            step++;
            printf("I'm in (%d %d)\n", tr+1, tc+1);
            dsf(tr, tc, pam);
            step--;
            pam[tr][tc] = 0;
        }
        return ;
    }
}