#include <vector>
#include <iostream>

using std::vector;


int singleNumber(const vector<int> &nums) {
    int target = 0;
    for (const auto &num: nums) {
        target = target xor num;
    }
    return target;
}

vector<int> singleNumber3(const vector<int> &nums) {
    int target = 0;
    for (const auto &num: nums) {
        target = target xor num;
    }
    int k = 0;
    while ((target & 1) == 0) {
        target >>= 1;
        k += 1;
    }
    int flag = (1 << k);
    int r1 = 0, r2 = 0;
    for (const auto &num: nums) {
        if (num & flag) {
            r1 = r1 xor num;
        } else {
            r2 = r2 xor num;
        }
    }
    return {r1, r2};
}

int main() {
    std::cout << singleNumber({2, 2, 1}) << std::endl;
    auto sn3 = singleNumber3({1, 2, 2, 3});
    std::cout << sn3[0] << ' ' << sn3[1] << std::endl;
}