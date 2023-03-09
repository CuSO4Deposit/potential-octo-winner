// My First Solution
//
// Key: 
// 1. The leftmost and rightmost entry of our target subarray must be positive.
// 2. Contiguous positive entries are either "all not included", or "all included" in the
//      target array.

int MergeContiguousEntries(int* source, int n, int* target){
    /* 
     * ===  FUNCTION  ======================================================================
     *         Name:  MergeContiguousEntries
     *  Description:  n is the size of source array. Scan <source> and merge the elements of
     *                  same sign into one element, and save into <target>. Return the size
     *                  of <target>. 
     *      Example:  [1, 2, 3, -2, -1, 5] -> [6, -3, 5].
     * =====================================================================================
     */
    int size = 0;
    int sum = source[0];
    int negativeFlag = 1;   // 0 indicates for all i in [0, n - 1], source[i] <= 0
    for(int i = 1; i < n; i++){
        if(negativeFlag && source[i] > 0)   negativeFlag = 0;
        if((sum ^ source[i]) >= 0){  // Note that ^ has lower precedence than >=  
            sum += source[i];
        }
        else{
            target[size++] = sum;
            sum = source[i];
        }
    }
    target[size++] = sum;
    if(negativeFlag)    return -1; // if return -1, means all entries is non-positive.
    return size;
}

int max(int a, int b){
    return a > b ? a : b;
}

int MaxSubarraySum(int* array, int l, int r){
    /* 
     * ===  FUNCTION  ======================================================================
     *         Name:  MaxSubarraySum
     *        Input:  Input array must satisfy: each element have a different sign with its
     *                  neighbor. That is: array[i] ^ array[i + 1] < 0.
     *  Description:  Recursively solve the ans of max sum of subarray of <array[l..r]>.
     *    Algorithm:  As this alg returns the maxSubarray value, if the leftmost/rightmost
     *                  element is negative, it won't be take into account. So we have them
     *                  ignored in 2nd and 3rd "if".
     *
     *                  After this optimization, the array input must be like: [+-+-+..+]
     *                  Then we consider array[l] + array[l + 1], if it's negative, then the
     *                  answer we want is either array[l] or MaxArraySum(array, l + 2, r).
     *                  This is what we handle in 5th and 6th "if".
     *
     *                  Then if an array has left&rightmost element positive, and left&right
     *                  two-element-sum both positive, we have: if array[l + 2] is a part of
     *                  max subarray, then array[l] and array[l + 1] must also be. This part
     *                  of code is at the last of this func.
     *
     *                  The 1st, 4th and 7th "if" handles the exit of recursion. 
     * =====================================================================================
     */
    if(l == r)
        return array[l];
    if(array[l] < 0)
        return MaxSubarraySum(array, l + 1, r);
    if(array[r] < 0)
        return MaxSubarraySum(array, l, r - 1);
    if(r - l == 2)
        return max(max(array[l], array[r]), array[l] + array[l + 1] + array[r]);
    if(array[l] + array[l + 1] < 0)
        return max(MaxSubarraySum(array, l + 2, r), array[l]);
    if(array[r] + array[r - 1] < 0)
        return max(MaxSubarraySum(array, l, r - 2), array[r]);
    if(r - l == 4){
        array[l + 2] += array[r - 1] + array[r];
        return max(array[r], MaxSubarraySum(array, l, l + 2));
    }
    array[l + 2] += array[l] + array[l + 1];
    array[r - 2] += array[r] + array[r - 1];
    return max(max(array[l], array[r]), MaxSubarraySum(array, l + 2, r - 2));
}

int maxSubArray(int* nums, int numsSize){
    int* MergedArray = (int*)malloc(numsSize * sizeof(int));
    for(int i = 0; i < numsSize; i++)
        MergedArray[i] = 0;
    int size = MergeContiguousEntries(nums, numsSize, MergedArray);
    if(size == -1){ // if all elements are negative, <MaxSubarraySum> alg will not work.
        int min = nums[0];
        for(int i = 1; i < numsSize; i++)
            if(nums[i] > min)
                min = nums[i];
        return min;
    }
    return MaxSubarraySum(MergedArray, 0, size - 1);
}
