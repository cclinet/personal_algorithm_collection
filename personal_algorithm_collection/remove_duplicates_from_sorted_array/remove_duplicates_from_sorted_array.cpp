#include <iostream>
#include <vector>

using std::vector;

int removeDuplicates(vector<int> &nums) {
    if (nums.empty()) {
        return 0;
    }
    int left = 1;
    int right = 1;
    while (right < nums.size()) {
        if (nums[right] != nums[right - 1]) {
            nums[left++] = nums[right];
        }
        right++;
    }
    return left;
}

int main() {
    vector<int> nums{1, 1, 2};
    std::cout << removeDuplicates(nums) << std::endl;
    for (auto i: nums) {
        std::cout << i << ' ';
    }
    std::cout << std::endl;
}