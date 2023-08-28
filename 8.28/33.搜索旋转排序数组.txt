int search(int* nums, int numsSize, int target){
    int left = 0, right = numsSize - 1, mid;
    while (left <= right) {
        mid = left + (right - left) / 2;  // 防止溢出
        if (nums[mid] == target) return mid;
        if (nums[left] <= nums[mid]) {  // 等于处理单个不存在情况
            if (target < nums[mid] && target >= nums[left]) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        } else {
            if (target > nums[mid] && nums[right] >= target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
    }
    return -1;
}
