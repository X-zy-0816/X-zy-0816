#include <stdio.h>
#include <stdlib.h>

int GetIndex(int * nums, int left, int right){
    int base = nums[left];
    while(left < right){
        while(left < right && nums[right] >= base){
            right--;
        }
        if(left < right)
        nums[left++] = nums[right];
        while(left < right && nums[left] <= base){
            left++;
        }
        if(left < right)
        nums[right--] = nums[left];
    }
    nums[left] = base;
    return left;
}

void QuickSort(int * nums, int left, int right){
    if(left < right){
        int index = GetIndex(nums, left, right);

        QuickSort(nums, left, index - 1);
        QuickSort(nums, index + 1, right);
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
    QuickSort(nums, 0, length  - 1);
    Printf(nums, length);
    return 0;
}