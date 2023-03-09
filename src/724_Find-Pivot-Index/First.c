// 23 ms (< 70.76%), 6.6 MB (< 70.60%)

int pivotIndex(int* nums, int numsSize){
    int sum = 0;
    for (int i = 0; i < numsSize; i++){
        sum += nums[i];
    }

    int RunningSum = 0;
    for (int pivot = 0; pivot < numsSize; pivot++){
        if (2 * RunningSum == sum - nums[pivot]){
            // So that RunningSum == sum - RunningSum - pivot
            return pivot;
        }
        RunningSum += nums[pivot];
    }
    return -1;
}
