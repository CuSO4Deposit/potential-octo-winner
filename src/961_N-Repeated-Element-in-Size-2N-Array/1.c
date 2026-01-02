int repeatedNTimes(int* nums, int numsSize) {
    char accessed[10001] = {0};
    for (int i = 0; i < numsSize; i++) {
        if (accessed[nums[i]])
            return nums[i];
        accessed[nums[i]]++;
    }
    return -1;
}
