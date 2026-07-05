int removeDuplicates(int* nums, int numsSize) {
    int hist[201] = {0};
    for (int i = 0; i < numsSize; i++) {
        hist[nums[i] + 100]++;
    }
    int result = 0;
    int index = 0;
    for (int i = 0; i < 201; i++) {
        if (hist[i] > 0) {
            nums[index] = i - 100;
            result++;
            index++;
        }
    }
    return result;
}
