//
//  main.cpp
//  InsertSort
//
//  Created by 徐致远 on 2020/9/3.
//  Copyright © 2020 徐致远. All rights reserved.
//

#include <stdio.h>
//思想 ： 将数组第一个元素视为有序数列 然后将以后的每一个元素插入有序数列
void InsertSort(int * nums, int length){
    int i, j;
    for(i = 1; i < length; i++){
        int nTemp = nums[i];
        for(j = i - 1; j >= 0 && nums[j] > nTemp; j--){
            nums[j + 1] = nums[j];
        }
        nums[j + 1] = nTemp;
    }
}

void Printf(int * nums, int length){
    for(int i = 0; i < length; i++){
        printf("%d ",nums[i]);
    }
    printf("\n");
}

int main(){
    int nums[] = {5, 1, 9, 4, 10, 11, 14, 15, 16, 10};
    
    InsertSort(nums, sizeof(nums) / sizeof(nums[0]));
    Printf(nums, sizeof(nums) / sizeof(nums[0]));
    
    return 0;
}
