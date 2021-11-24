## 题目
求所有n位二进制数中 存在至少三位连续相同数字的个数，n小于10000
## 思考
至少三位连续相同 = n位二进制数量 - 任意连续三位不同

求任意连续三位不同，可以用动态规划来求解
状态转移方程为：

```c++
        dp[i][0][0] = dp[i - 1][1][0];
        dp[i][0][1] = dp[i - 1][0][0] + dp[i - 1][1][0];
        dp[i][1][0] = dp[i - 1][0][1] + dp[i - 1][1][1];
        dp[i][1][1] = dp[i - 1][0][1];
```

其中`dp[i][0][1]` 表示 i 位二进制数，低两位为 0，1 满足条件的数量

注意 n 位二进制最高位必须是 1，所以初始状态为：

```c++
dp[2][0][0] = 0;
dp[2][0][1] = 0;
dp[2][1][0] = 1;
dp[2][1][1] = 1;
```
