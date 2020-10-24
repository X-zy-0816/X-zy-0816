//
//  main.cpp
//  SelectionSort
//
//  Created by 徐致远 on 2020/9/3.
//  Copyright © 2020 徐致远. All rights reserved.
//

#include <stdio.h>
//原理 ： 找到最大或者最小的元素 然后按照顺序和数组元素交换
void SelectionSort(int nums[], int length){
    int nMinIndex = 0, i, j;
    for(i = 0; i < length - 1; i++){
        nMinIndex = i;
        for(j = i + 1; j < length; j++){    //每一轮找出最小的一个元素
            if(nums[j] < nums[nMinIndex]) nMinIndex = j;
        }
        if(nMinIndex != i){     // 使用异或需要注意是否为同一地址的元素
            nums[i] ^= nums[nMinIndex];
            nums[nMinIndex] ^= nums[i];
            nums[i] ^= nums[nMinIndex];
        }
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
    
    SelectionSort(nums, sizeof(nums) / sizeof(nums[0]));
    Printf(nums, sizeof(nums) / sizeof(nums[0]));
    
    return 0;
}
