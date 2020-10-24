#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int BinarySearch(int nums[], int length, int Search){
    int low =0;
    int high = length - 1;
    int mid;
    while(low <= high){
        mid = (high - low) / 2 + low;
        if(nums[mid] < Search){
            low = mid + 1;
        }else if(nums[mid] > Search){
            high = mid - 1;
        }else{
            return mid + 1;
        }
    }
    return -1;
}

int main(){
    int nums[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int length = sizeof(nums) / sizeof(nums[0]);
    printf("%d \n", BinarySearch(nums, length, 6));
    return 0;
}