#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    int nVaule;
    struct node * pNext;
}Node;

void BasicSort(int * nums, int length){
    //找到最大值
    int nMax = nums[0];
    int i = 0;
    for(i = 0; i < length; i++){
        if(nMax < nums[i]) nMax = nums[i];
    }
    //计算最大值的位数
    int nCount = 1;
    while(nMax != 0){
        nMax /=10;
        nCount *= 10;
    }
    nCount /= 10;
    //为指针数组申请空间
    Node ** Basic = (Node **)malloc(sizeof(Node *) * 10);
    memset(Basic, 0, sizeof(Node *) * 10);
    //将每次按照位分组的数字放入指针数组
    int nTemp = 1;
    Node * pTemp = NULL;  
    Node * pNode = NULL;
    while(nTemp <= nCount){ 
        for(i = 0; i < length; i++){
            int nIndex = nums[i] / nTemp % 10;  //得到当前元素的个位（十位， 百位）作为在指针数组中的下标
            pTemp = (Node *)malloc(sizeof(Node));
            pTemp->nVaule = nums[i];
            pTemp->pNext = NULL;
            //尾插入
            if(Basic[nIndex] == NULL){ 
                Basic[nIndex] = pTemp;
            }else{
                pNode = Basic[nIndex];
                while(pNode->pNext != NULL){
                    pNode = pNode->pNext;
                }
                pNode->pNext = pTemp;
            }
        }
        //将按位排序后的元素放回原来数组
        int count = 0;
        for(i = 0; i < 10; i++){
            pNode = Basic[i];
            while(pNode){
                nums[count++] = pNode->nVaule;
                pNode = pNode->pNext;
            }
        }
        //清空当前一趟的指针数组
        memset(Basic, 0, sizeof(Node *) * 10);
        //数位上升一位
        nTemp *= 10;
    }
    //释放空间
    free(Basic);
    Basic = NULL;

}



void Print(int * nums, int length){
    int i;
    for(i = 0; i < length; i++){
        printf("%d ", nums[i]);
    }
    printf("\n");
}

int main(){
    int nums[] = {145, 532, 642, 752, 985, 184, 432, 246, 345, 875, 4, 12, 1004};
    int length = sizeof(nums) / sizeof(nums[0]);

    BasicSort(nums, length);
    Print(nums, length);
    return 0;
}