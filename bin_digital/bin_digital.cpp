#include <array>
#include <iostream>


unsigned long long bin_digital(int n) {
    if (n == 1)
        return 0;
    if (n == 2)
        return 0;
    std::array<std::array<std::array<unsigned long long, 2>, 2>, 10001> dp{};
    dp[2][0][0] = 0;
    dp[2][0][1] = 0;
    dp[2][1][0] = 1;
    dp[2][1][1] = 1;
    for (int i = 3; i <= n; i++) {
        dp[i][0][0] = dp[i - 1][1][0];
        dp[i][0][1] = dp[i - 1][0][0] + dp[i - 1][1][0];
        dp[i][1][0] = dp[i - 1][0][1] + dp[i - 1][1][1];
        dp[i][1][1] = dp[i - 1][0][1];
    }
    return (1 << (n - 1)) - (dp[n][0][0] + dp[n][0][1] + dp[n][1][0] + dp[n][1][1]);
}

int main() {
    std::cout << bin_digital(4) << std::endl;
    return 0;
}
