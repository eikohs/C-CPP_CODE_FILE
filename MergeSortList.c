#include <stdio.h>
#include <stdlib.h>
/*struct 结构原型的定义，可根据需要修改*/
typedef struct LINE{
    int count;
    int tal_price;
    double price;
    struct LINE * next;
}List;
/*
merge 函数， 用于将链表链接起来
其中需要根据比较内容的不同以及单增单减的区别进行修改
*/
List * Merge(List * l1, List * l2)
{
    List * dummyhead = (List *)malloc(sizeof(List)), * ret_val = dummyhead;
    while(l1&&l2){
        if(l1->price > l2->price){  //在此行进行单增单减的修改及比较内容的修改
            ret_val->next = l1;
            ret_val = l1;
            l1 = l1->next;
        }
        else{
            ret_val->next = l2;
            ret_val = l2;
            l2 = l2->next;
        }
    }
    ret_val->next = l1?l1:l2;
    ret_val = dummyhead->next;
    free(dummyhead);
    return ret_val;
}
/*归并排序主体：可以不做修改直接引用 */
List * MergeSortList(List * head)
{
    if(!head || !head->next) return head;
    List * fast = head;
    List * slow = head;
    List * brek = head;
    while(fast && fast->next){
        fast = fast->next->next;
        brek = slow;
        slow = slow->next;
    }
    brek->next = NULL;
    fast = MergeSortList(head);
    slow = MergeSortList(slow);

    return Merge(fast, slow);
}

/*main函数，其中包含链表的初始化，随使用场景的不同需要进行各自的初始化*/
int main(void)
{
    int kind, need, i;
    double salemoney = 0.0;

    scanf("%d %d", &kind, &need);
    List *head, *node, *end;
    head = (List *)malloc(sizeof(List));//head文件初始化
    end = head;
    for(i = 0;i < kind;i++){
        node = (List *)malloc(sizeof(List));//在这个for循环中进行链表内容大小初始化
        scanf("%d", &node->count);
        end->next = node;
        end = node;
    }
    end->next = NULL;//在此步过后初始化结束
    node = head;
    for(i = 0;i < kind;i++){
        node = node->next;
        scanf("%d", &node->tal_price);
        node->price = (double)(node->tal_price)/(double)(node->count);
    }
    node = MergeSortList(head->next);
    while(need > 0&& node){
        need -= node->count;
        salemoney += (double)node->tal_price;
        if(need < 0){
            salemoney -= node->price * (-need);
        }
        else{
            node = node->next;
        }
    }
    printf("%.2lf\n", salemoney);

    return 0;
}