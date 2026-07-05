void binarySearch(int * nums, int left, int right, int target, int * answer) {
    if (left == right) {
        if (nums[left] < target) {
            *answer = left + 1;
            return;
        } else {
            *answer = left;
            return;
        }
    }
    int mid = (right + left) / 2;
    if (nums[mid] > target) {
        binarySearch(nums, left, mid, target, answer);
    } else if (nums[mid] == target) {
        *answer = mid;
        return;
    } else {
        binarySearch(nums, mid + 1, right, target, answer);
    }
}

int searchInsert(int* nums, int numsSize, int target) {
    int answer = 0;
    binarySearch(nums, 0, numsSize - 1, target, &answer);
    return answer;
}
