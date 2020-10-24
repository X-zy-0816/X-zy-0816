//
//  main.cpp
//  BubbleSort
//
//  Created by 徐致远 on 2020/9/3.
//  Copyright © 2020 徐致远. All rights reserved.
//

#include <stdio.h>

void BubbleSort(int * nums, int length){
    int count = 0;  //交换次数
    bool bFlag;     //标示 用于记录一趟中是否发生交换： 若没有交换则排序完成
    int nTemp = length - 1; //减少交换次数
    for(int i = 0; i < length - 1; i++){
        bFlag = true;
        int NewTemp = 0;//  标记交换的最后位置 
        for(int j = 0; j < nTemp; j++){
            count++;
            if(nums[j] > nums[j + 1]){
                bFlag = false;
                NewTemp = j + 1;
                nums[j] ^= nums[j + 1];
                nums[j + 1] ^= nums[j];
                nums[j] ^= nums[j + 1];
            }
        }
        nTemp = NewTemp;
        if(nTemp == 0) break;
        
        if(bFlag) break;
        
    }
    printf("比较了 %d 次\n", count);
}

void Printf(int * nums, int length){
    for(int i = 0; i < length; i++){
        printf("%d ",nums[i]);
    }
    printf("\n");
}

int main(){
    int nums[] = {5, 1, 9, 4, 10, 11, 14, 15, 16, 10};
    
    BubbleSort(nums, sizeof(nums) / sizeof(nums[0]));
    Printf(nums, sizeof(nums) / sizeof(nums[0]));
    
    return 0;
}
