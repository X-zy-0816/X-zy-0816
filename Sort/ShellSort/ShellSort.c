#include <stdio.h>
#include <stdlib.h>

void ShellSort(int * nums, int length){
    int i, j, k;
    int nGep;
    int nTemp;
    //定间隔
    for(nGep = length / 2; nGep > 0; nGep /= 2){
        //分组
        for(i = 0; i < nGep; i++){
            //各组之内直接插入排序
            for(j = i + nGep; j < length; j += nGep){
                k = j - nGep;
                nTemp = nums[j];
                while(nums[k] > nTemp && k >= i){
                    nums[k + nGep] = nums[k];
                    k -= nGep;
                }
                nums[k + nGep] = nTemp;
            }
        }
    }
}

void Printf(int * nums, int length){
    for(int i = 0; i < length; i++){
        printf("%d ", nums[i]);
    }
    printf("\n");
}

int main(){
    int nums[] = {10, 5, 6, 2, 1, 4, 3, 7, 8, 9, 10};
    int length = sizeof(nums) / sizeof(nums[0]);
    ShellSort(nums, length);
    Printf(nums, length);
    return 0;
}