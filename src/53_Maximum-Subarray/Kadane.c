// Kadane's algorithm
//
// 205 ms (< 27.14%), 12.4 MB (< 32.74%)

int max(int a, int b){
    return a > b ? a : b;
}

int maxSubArray(int* nums, int numsSize){
    int cur = 0;
    int Max = nums[0];
    for(int i = 0; i < numsSize; i++){
        cur = nums[i] + max(cur, 0);
        Max = max(cur, Max);
    }
    return Max;
}
