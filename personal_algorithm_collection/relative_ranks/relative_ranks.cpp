#include <iostream>
#include <string>
#include <utility>
#include <vector>
using namespace std;

vector<string> findRelativeRanks(const vector<int> &score) {
    auto size = score.size();
    vector<pair<int, int>> vp;
    vp.reserve(size);
    for (auto i = 0; i != size; i++) {
        vp.emplace_back(std::make_pair(i, score[i]));
    }
    std::sort(vp.begin(), vp.end(), [](pair<int, int> a, pair<int, int> b) { return a.second > b.second; });
    vector<string> result(size);
    string s{};
    for (auto i = 0; i != size; i++) {
        switch (i) {
            case 0:
                s = "Gold Medal";
                break;
            case 1:
                s = "Silver Medal";
                break;
            case 2:
                s = "Bronze Medal";
                break;
            default:
                s = std::to_string(i + 1);
        }
        result[vp[i].first] = s;
    }
    return result;
}

int main() {
    auto result = findRelativeRanks({10, 3, 8, 9, 4});
    for (const auto &s: result) {
        cout << s << ' ';
    }
    return 0;
}