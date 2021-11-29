#include <array>
#include <vector>
#include <unordered_map>
#include <random>

using std::vector;
using std::unordered_map;

class Solution {
public:
    Solution(int m, int n) : map_{}, total_(m * n), m(m), n(n), gen(rd()) {
        map_.reserve(1000);
    }

    vector<int> flip() {
        vector<int> ans;
        total_--;
        std::uniform_int_distribution<> dis(0, total_);
        auto r = dis(gen);
        auto search = map_.find(r);
        if (search == map_.end()) {
            ans = {r / n, r % n};
        } else {
            ans = {map_[r] / n, map_[r] % n};
        }
        search = map_.find(total_);
        if (search == map_.end()) {
            map_[r] = total_;
        } else {
            map_[r] = map_[total_];
        }
        return ans;
    }

    void reset() {
        total_ = m * n;
        map_ = {};
    }

private:
    int total_, m, n;
    unordered_map<int, int> map_;
    std::random_device rd;
    std::mt19937 gen;
};

int main() {
    auto *obj = new Solution(3, 2);
    vector<int> param_1 = obj->flip();
    obj->reset();
    return 0;
}
