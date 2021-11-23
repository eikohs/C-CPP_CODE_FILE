#include <stdio.h>
void sort_pr(int (*num)[3], int size);
int len(int n);
int cmp(int * num1, int * num2);

int main(void)
{
    int SIZE, line, high;
    scanf("%d %d %d", &SIZE, &line, &high);
    int lev_a[SIZE][3], lev_b[SIZE][3], lev_c[SIZE][3], lev_d[SIZE][3];
    int na, nb, nc, nd, i, j, tm[3];

    for(na = nb = nc = nd = i = 0;i < SIZE;i++){
        scanf("%d %d %d", &tm[0], &tm[1], &tm[2]);
        if(tm[1] < line||tm[2] < line){
            continue;
        }
        if(tm[1] >= high&&tm[2] >= high){
            for(j = 0;j < 3;j++){
                *(*(lev_a + na)+j) = tm[j];
            }
            na++;
        }
        else if(tm[1] >= high){
            for(j = 0;j < 3;j++){
                lev_b[nb][j] = tm[j];
            }
            nb++;
        }
        else if(tm[1] >= tm[2]){
            for(j = 0;j < 3;j++){
                lev_c[nc][j] = tm[j];
            }
            nc++;
        }
        else{
            for(j = 0;j < 3;j++){
                lev_d[nd][j] = tm[j];
            }
            nd++;
        }
    }
    printf("%d\n", na+nb+nc+nd);
    sort_pr(lev_a, na);
    sort_pr(lev_b, nb);
    sort_pr(lev_c, nc);
    sort_pr(lev_d, nd);
    
    return 0;
}
void sort_pr(int num[][3], int size)
{
    int leth, i, j, k, tmp;
    
    for(leth = len(size); leth >= 1; leth = (leth+1)/2 - 1){
        for(i = leth;i < size;i++){
            for(j = i;j >= leth&&cmp(*(num + j), *(num + j - leth));j -= leth){
                for(k = 0;k < 3;k++){
                    tmp = num[j][k];
                    num[j][k] = num[j - leth][k];
                    num[j - leth][k] = tmp;
                }
            }
        }
    }
    for(i = 0;i < size;i++){
        printf("%d %d %d\n", num[i][0], num[i][1], num[i][2]);
    }
}
int len(int n)
{
    int result = 1;

    while(result < n){
        result = (result + 1)*2 - 1;
    }

    return (result + 1)/2 - 1;
}
int cmp(int * num1, int * num2)
{
    if(num1[1] + num1[2] > num2[1] + num2[2]){
        return 1;
    }
    else if(num1[1] + num1[2] == num2[1] + num2[2]){
        if(num1[1] > num2[1]){
            return 1;
        }
        else if(num1[1] == num2[1]){
             if(num1[0] < num2[0]){
                 return 1;
             }
        }
    }

    return 0;
}