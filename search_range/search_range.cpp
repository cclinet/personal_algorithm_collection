#include <iostream>
#include <array>
#include <vector>

using std::vector;

int binary_search_left(const vector<int> &nums, int target) {
    int left = -1;
    int right = static_cast<int> (nums.size());
    while (left + 1 < right) {
        int mid = (left + right) / 2;
        if (nums[mid] < target) {
            left = mid;
        } else {
            right = mid;
        }
    }
    return right;
}

int binary_search_right(const vector<int> &nums, int target) {
    int left = -1;
    int right = static_cast<int> (nums.size());
    while (left + 1 < right) {
        int mid = (left + right) / 2;
        if (nums[mid] <= target) {
            left = mid;
        } else {
            right = mid;
        }
    }
    return left;
}

vector<int> searchRange(const vector<int> &nums, int target) {
    if (nums.empty()) {
        return {-1, -1};
    }
    int left = binary_search_left(nums, target);
    int right = binary_search_right(nums, target);
    if (left <= right && right < nums.size() && nums[left] == target) {
        return {left, right};
    }
    return {-1, -1};
}

int main() {
    auto r = searchRange(std::vector<int>{2,2}, 3);
    std::cout << r[0] << ' ' << r[1] << std::endl;
    return 0;
}
