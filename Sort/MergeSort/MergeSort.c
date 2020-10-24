#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void Sort_1(int * nums, int start, int end, int mid){
    int * arr = (int *)malloc(sizeof(int) * (end - start + 1));
    memset(arr, 0, sizeof(int) * (end - start + 1));

    int start1 = start, start2 = mid + 1, end1 = mid, end2 =end;
    int count = 0;
    while(start1 <= end1 && start2 <= end2)
        arr[count++] = nums[start1] > nums[start2] ? nums[start2++] : nums[start1++];

    while(start1 <= end1)
        arr[count++] = nums[start1++];
    while(start2 <= end2)
        arr[count++] = nums[start2++];

    for(int i = 0, k = start; i < count; i++, k++){
        nums[k] = arr[i];
    }
    free(arr);
    arr = NULL;
}

void MergeSort(int * nums, int start, int end){
    if(start >= end) return;
    int mid = (start + end) / 2;

    MergeSort(nums, start, mid);
    MergeSort(nums, mid + 1, end);
    Sort_1(nums, start, end, mid);
}

void Printf(int nums[], int length){
    for(int i = 0; i < length; i++){
        printf("%d ",nums[i]);
    }
    printf("\n");
}

int main(){
    int nums[] = {1, 4, 6, 3, 2, 9, 5, 21, 412, 523, 6, 432, 234,34};
    int length = sizeof(nums) / sizeof(nums[0]);
    MergeSort(nums, 0, length - 1);
    Printf(nums, length);

    return 0;
}
