//
//  main.cpp
//  CountSort
//
//  Created by 徐致远 on 2020/9/3.
//  Copyright © 2020 徐致远. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

//原理：根据元素本身的值，将每个元素出现的次数记录到辅助空间后，通过对辅助空间内数据的计算，即可确定每一个元素最终的位置。
void CountSort(int * nums, int length){
    int nMin = nums[0], nMax = nums[0];
    for(int i = 0; i < length; i++){
        if(nums[i] > nMax) nMax = nums[i];
        if(nums[i] < nMin) nMin = nums[i];
    }
    
    int nSize = nMax - nMin + 1;
    int * nNums = (int*)malloc(sizeof(int) * nSize);
    
    memset(nNums, 0, sizeof(int) * nSize);
    
    for(int i = 0; i < length; i++){
        nNums[nums[i] - nMin]++;
    }
    
    int count = 0;
    for(int i = 0; i < nSize; i++){
        if(nNums[i] != 0){
            for(int j = 0; j < nNums[i]; j++){
                nums[count++] = i + nMin;       //将元素取出装回原数组
            }
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
    
    CountSort(nums, sizeof(nums) / sizeof(nums[0]));
    Printf(nums, sizeof(nums) / sizeof(nums[0]));
    
    return 0;
}
