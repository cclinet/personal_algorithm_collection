#include <vector>
#include <iostream>
#include <string>
#include <optional>

using namespace std;


int maxPower(string s) {
    if (s.empty()) {
        return 0;
    }
    int consecutive_max_length = 1;
    int max_length = 1;
    for (auto i = s.begin() + 1; i != s.end(); i++) {
        if (*i == *(i - 1)) {
            consecutive_max_length++;
        } else {
            max_length = max(max_length, consecutive_max_length);
            consecutive_max_length = 1;
        }
    }
    max_length = max(max_length, consecutive_max_length);
    return max_length;
}

int main() {
    std::cout << maxPower("cc") << std::endl;
}