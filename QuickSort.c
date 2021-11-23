#include <stdio.h>
#include <stdlib.h>
//以下为快速排序基于double型数组的模板，实现方式参考了qsort函数，建议使用qsort函数而非以下代码

/*partrition函数，对分好的每一个块进行处理，使用时注意修改变量类型， 实际上把5个double改为对应类型即可*/
double * partrition(double * low, double * high, int (* compare)(const void *, const void *))//这一行有3个
{
    double mid;
    double * tmp = &mid;//这里一个，上面一个
    *tmp = *low;

    while(low < high){
        while(low < high && compare((void *)high, (void *)tmp) > 0){
            high--;
        }
        *low = *high;
        while(low < high && compare((void *)tmp, (void *)low) > 0){
            low++;
        }
        *high = *low;
    }
    *low = *tmp;

    return low;
}


/*Qsort函数，快排主题递归函数，使用时修改三个double*/
void QSort(double * low, double * high, int(* compare)(const void *, const void *))//这里面有两个
{
    double * mid;//此处还有一个

    if(low < high){
        mid = partrition(low, high, compare);
        QSort(low, mid-1, compare);
        QSort(mid+1, high, compare);
    }

    return ;
}


/*QuickSort函数，用户接口函数，使用时把double改为对应变量类型*/
void QuickSort(double * arr, size_t SizeofArr, int (* compare)(const void *, const void *))//这里面的double
{
    QSort(arr, arr+SizeofArr-1, compare);
}


/*cmp函数，使用qsort函数时同样会用到*/
int cmp(const void * a, const void * b)
{
    return *(double *)a - *(double *)b;
}


/*main函数，用来提供对QuickSort的测试，测试参考用例附在末尾*/
int main(void)
{
    double num[100];
    int size = 0, i;

    puts("Please enter some numbers(less than 100), q to end enter:");
    while(scanf("%lf", num+size)){
        size++;
    }
    QuickSort(num, size, cmp);
    printf("%g", *num);
    for(i = 1;i < size;i++){
        printf("<%g", num[i]);
    }

    return 0;
}
//测试样例：129 0.2341 843.23 3445.99 233 454 512 123.44 565.23 5555 887233 q