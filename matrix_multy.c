#include <stdio.h>
void gets_matrix(int m, int n, double arr[m][n]);
double caculate(int j, int n, int l, double arr1[], double arr2[j][n]);

int main(void)
{
    int m, j, n;
    int k, l;

    printf("Enter the size of matrix in the form of m*j j*n\n");
    printf("For example, if you wanna caculate the multiply of ");
    printf("matrix1(2*3) and matrix2(3*4), please input: 2|3|4\n");

    scanf("%d|%d|%d", &m, &j, &n);
    double ar1[m][j];
    double ar2[j][n];
    gets_matrix(m, j, ar1);
    gets_matrix(j, n, ar2);
    for(k = 0;k < m;k++){
        printf("|%6.2lf|", caculate(j, n, 0, ar1[k], ar2));
        for(l = 1;l < n;l++){
            printf("%6.2lf|", caculate(j, n, l, ar1[k], ar2));
        }
        putchar('\n');
    }
    
    return 0;
}
void gets_matrix(int m, int n, double arr[m][n])
{
    int i;

    printf("Enter a matrix of %d*%d, please from left to right and from up to down\n", m, n);
    printf("For example, if you wanna enter a matrix of 2*3, and it is\n");
    printf("|1|3|5|\n");
    printf("|2|4|6|\n");
    printf("so you shoule enter \" 1 3 5 2 4 6\"\n");
    printf("Let's begin: \n");

    for(i = 0;i < m*n; i++){
        scanf("%lf", *arr + i);
    }
}
double caculate(int j, int n, int l, double arr1[], double arr2[j][n])
{
    double result;
    int i;

    for(result = i = 0;i < j;i++){
        result += arr1[i]*arr2[i][l];
    }

    return result;
}