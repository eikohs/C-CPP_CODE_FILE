#include <stdio.h>
#include <string.h>
#include <ctype.h>
double det[15][15];
int flag[15];
int mun[15];
double answer;
int N;
void i_put(void);
int re_put(void);
void arr_get(void);
int nixushu(int *num);
void dfs(int arr);

int main(void)
{
    memset(flag, 1, sizeof(flag));

    i_put();
    do
    {
        answer = 0.0;
        dfs(0);
        puts("*****************************************************");
        printf("The answer is %.4lf\n", answer);
    } while (re_put());
    puts("See you!");

    return 0;
}
void i_put(void)
{
    char ch;

    puts("Enter the power of the determinant");
    while (!scanf("%d", &N))
    {
        while((ch = getchar()) != '\n')
        {
            putchar(ch);
        }
        puts(" is not a valid input, try again");
    }
    printf("Enter %d numbers\n", N * N);
    puts("For example, if you wanna caculate a determinant like");
    puts("|2 3 4|");
    puts("|5 6 7|");
    puts("|8 9 0|");
    puts("Please input like: ");
    puts("2 3 4");
    puts("5 6 7");
    puts("8 9 0");
    puts("*****************************************************");
    arr_get();
}
int nixushu(int *num)
{
    int ret_val, i, j;

    for (ret_val = i = 0; i < N - 1; i++)
    {
        for (j = i + 1; j < N; j++)
        {
            if (num[j] < num[i])
            {
                ret_val++;
            }
        }
    }

    return ret_val % 2;
}
void dfs(int arr)
{
    if (arr == N)
    {
        int i;
        double num;
        for (i = 0, num = 1.0; i < N; i++)
        {
            num *= det[i][mun[i] - 1];
        }
        if (nixushu(mun))
        {
            answer -= num;
        }
        else
        {
            answer += num;
        }
    }
    else
    {
        int j;
        for (j = 0; j < N; j++)
        {
            if (flag[j])
            {
                mun[arr] = j + 1;
                flag[j] = 0;
                dfs(arr + 1);
                flag[j] = 1;
            }
        }
    }
}
void arr_get(void)
{
    int i, j;
    char ch;

    while(getchar() != '\n'){
        continue;
    }
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
        {
            if (!scanf("%lf", det[i] + j))
            {
                while ((ch = getchar()) != '\n' && ch != ' ')
                {
                    putchar(ch);
                }
                if (ch != '\n')
                {
                    while (getchar() != '\n')
                    {
                        continue;
                    }
                }
                puts(" is not a valid number, please enter the line again");
                i--;
                break;
            }
        }
    }
}
int re_put(void)
{
    char ch;
    int ret_val;

    while (getchar() != '\n')
    {
        continue;
    }
    puts("Continue? (N/n to exit the programme, enter other key to continue.");
    if ((ch = getchar()) == 'N' || ch == 'n')
    {
        ret_val = 0;
    }
    else
    {
        puts("Enter the power of the determinant");
        while(!scanf("%d", &N))
        {
            while ((ch = getchar()) != '\n')
            {
                putchar(ch);
            }
            puts(" is not a valid input, try again");
        }
        printf("Enter %d numbers\n", N * N);
        arr_get();
        ret_val = 1;
    }

    return ret_val;
}