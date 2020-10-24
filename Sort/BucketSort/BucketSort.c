#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node{
    int nVaule;
    struct node * pNext;
}Node;
//要求 ： 只能排序[0, 1)
//思想 ： 1）把区间[0, 1)分解为n个大小相等的桶；
//      2）将n个输入数据按照其取值不同分配到n个桶里面；
//      3）对每个桶里面的数据进行排序；
//      4）然后将桶里面的数据按顺序收集。

void Sort(Node * pHead){
    if(pHead == NULL || pHead->pNext == NULL) return;

    Node * pSort = pHead;
    Node * pTemp = NULL;
    while(pSort->pNext){
        pTemp = pHead;
        while(pTemp->pNext){
            if(pTemp->nVaule > pTemp->pNext->nVaule){
                pTemp->nVaule ^= pTemp->pNext->nVaule;
                pTemp->pNext->nVaule ^= pTemp->nVaule;
                pTemp->nVaule ^= pTemp->pNext->nVaule;
            }
            pTemp = pTemp->pNext;
        }
        pSort = pSort->pNext;
    }
}

void BucketSort(int * nums, int length){
    //找到最大值最小值
    int nMin = nums[0];
    int nMax = nums[0];
    for(int i = 0; i < length; i++){
        if(nums[i] < nMin)  nMin = nums[i];
        if(nums[i] > nMax)  nMax = nums[i];
    }
    int nTemp = nMax;
    //求位数
    int nCount = 1;
    while(nTemp){
        nTemp /= 10;
        nCount *= 10;
    }
    nCount /= 10;

    //求桶的个数
    int Max = nMax / nCount;
    int Min = nMin / nCount;
    int nSize = Max - Min + 1;

     //给桶分配空间
    Node ** Bucket = (Node **)malloc(sizeof(Node *) * nSize);
    memset(Bucket, 0, sizeof(Node *) * nSize);

    //放入桶
    Node * pTemp = NULL;
    for(int i = 0; i < length; i++){
        int nIndex = nums[i] / nCount - Min;
        pTemp = (Node *)malloc(sizeof(Node));
        pTemp->nVaule = nums[i];
        pTemp->pNext = Bucket[nIndex];
        Bucket[nIndex] = pTemp;
    }
    
    //每个桶内排序
    for(int i = 0; i < nSize; i++){
        Sort(Bucket[i]);
    }

    //放回原数组
    Node * pNode = NULL;
    int count = 0;
    for(int i = 0; i < nSize; i++){
        pTemp = Bucket[i];
        while(pTemp){
            nums[count++] = pTemp->nVaule;
            pTemp = pTemp->pNext;
        }
    }
    //释放空间
    Node * pDel = NULL;
    for(int i = 0; i < nSize; i++){
        pTemp = Bucket[i];
        while(pTemp){
            pDel = pTemp;
            pTemp = pTemp->pNext;
            free(pDel);
            pDel = NULL;
        }
    }
    free(Bucket);
    Bucket = NULL;
}

void Printf(int * nums, int length){
    for(int i = 0; i < length; i++){
        printf("%d ", nums[i]);
    }
    printf("\n");
}

int main(){
    int nums[] = {5423, 6456, 6346, 1356, 9644, 6345, 2234, 9438, 6343};
    int length = sizeof(nums) / sizeof(nums[0]);
    BucketSort(nums, length);
    Printf(nums, length);
    return 0;
}