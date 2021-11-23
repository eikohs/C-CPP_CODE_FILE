#include <stdio.h>
#include <string.h>
int flag[20], sor[20], cir[20];
int book,N;
int is_Prime(int a, int b);
void dfs(int times);

int main(void)
{
    int i;

    memset(flag, 1, sizeof(flag));
    memset(sor, 0, sizeof(sor));
    memset(cir, 0, sizeof(cir));
    cir[0] = 1;
    while (scanf("%d", &N))
    {
        
        for (i = 1; i <= N; i++)
        {
            sor[i - 1] = i;
        }
        book = 0;
        dfs(1);
        if(!book){
            puts("No case! Next number");
        }
        else{
            puts("End case. Next number");
        }
    }

    return 0;
}
int is_Prime(int a, int b)
{
    int n, i;

    n = a + b;
    for (i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            return 0;
        }
    }

    return 1;
}
void dfs(int times)
{
    if (times == N)
    {
        int i;
        printf("Case %d: ", ++book);
        for (i = 0; i < N; i++)
        {
            printf("%d ", cir[i]);
        }
        puts("1");
        return;
    }
    if (times == N - 1)
    {
        int j;
        for (j = 1; j < N; j++)
        {
            if (flag[j] && is_Prime(sor[j], cir[times - 1]) && is_Prime(sor[j], 1))
            {
                flag[j] = 0;
                cir[times] = sor[j];
                dfs(times + 1);
                flag[j] = 1;
            }
        }
        return;
    }
    if (times < N - 1)
    {
        int j;
        for (j = 1; j < N; j++)
        {
            if (flag[j] && is_Prime(sor[j], cir[times - 1]))
            {
                flag[j] = 0;
                cir[times] = sor[j];
                dfs(times + 1);
                flag[j] = 1;
            }
        }
        return;
    }
}