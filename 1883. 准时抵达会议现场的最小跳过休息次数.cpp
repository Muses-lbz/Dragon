//1883. 准时抵达会议现场的最小跳过休息次数
//给你一个整数 hoursBefore ，表示你要前往会议所剩下的可用小时数。要想成功抵达会议现场，你必须途经 n 条道路。
//道路的长度用一个长度为 n 的整数数组 dist 表示，其中 dist[i] 表示第 i 条道路的长度（单位：千米）。另给你一个整数 speed ，表示你在道路上前进的速度（单位：千米每小时）。
//当你通过第 i 条路之后，就必须休息并等待，直到 下一个整数小时 才能开始继续通过下一条道路。注意：你不需要在通过最后一条道路后休息，因为那时你已经抵达会议现场。
//例如，如果你通过一条道路用去 1.4 小时，那你必须停下来等待，到 2 小时才可以继续通过下一条道路。如果通过一条道路恰好用去 2 小时，就无需等待，可以直接继续。
//然而，为了能准时到达，你可以选择 跳过 一些路的休息时间，这意味着你不必等待下一个整数小时。注意，这意味着与不跳过任何休息时间相比，你可能在不同时刻到达接下来的道路。
//例如，假设通过第 1 条道路用去 1.4 小时，且通过第 2 条道路用去 0.6 小时。跳过第 1 条道路的休息时间意味着你将会在恰好 2 小时完成通过第 2 条道路，且你能够立即开始通过第 3 条道路。
//返回准时抵达会议现场所需要的 最小跳过次数 ，如果 无法准时参会 ，返回 -1 。

//示例 1：
//输入：dist = [1,3,2], speed = 4, hoursBefore = 2
//输出：1
//解释：
//不跳过任何休息时间，你将用 (1/4 + 3/4) + (3/4 + 1/4) + (2/4) = 2.5 小时才能抵达会议现场。
//可以跳过第 1 次休息时间，共用 ((1/4 + 0) + (3/4 + 0)) + (2/4) = 1.5 小时抵达会议现场。
//注意，第 2 次休息时间缩短为 0 ，由于跳过第 1 次休息时间，你是在整数小时处完成通过第 2 条道路。

//示例 2：
//输入：dist = [7,3,5,5], speed = 2, hoursBefore = 10
//输出：2
//解释：
//不跳过任何休息时间，你将用 (7/2 + 1/2) + (3/2 + 1/2) + (5/2 + 1/2) + (5/2) = 11.5 小时才能抵达会议现场。
//可以跳过第 1 次和第 3 次休息时间，共用 ((7/2 + 0) + (3/2 + 0)) + ((5/2 + 0) + (5/2)) = 10 小时抵达会议现场。

//示例 3：
//输入：dist = [7,3,5,5], speed = 1, hoursBefore = 10
//输出：-1
//解释：即使跳过所有的休息时间，也无法准时参加会议。

#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
using namespace std;

class Solution {
public:
    int minSkips(vector<int>& dist, int speed, int hoursBefore) {
        int n = dist.size();
        // 创建动态规划表，dp[i][j] 表示通过前 i 条道路时，跳过 j 次休息时间所需的最小时间
        vector<vector<long long>> dp(n + 1, vector<long long>(n + 1, numeric_limits<long long>::max()));

        // 初始条件：在没有经过任何道路时，不需要跳过任何休息时间，所需时间为0
        dp[0][0] = 0;

        // 动态规划填表
        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j <= i; ++j) {
                // 选择跳过休息时间的情况
                if (j > 0 && dp[i - 1][j - 1] != numeric_limits<long long>::max()) {
                    // 跳过休息时间后，所需时间
                    long long skip_time = dp[i - 1][j - 1] + dist[i - 1];
                    // 检查是否会发生整数溢出
                    if (skip_time <= numeric_limits<long long>::max() - speed) {
                        dp[i][j] = min(dp[i][j], skip_time);
                    }
                }
                // 不跳过休息时间的情况
                if (dp[i - 1][j] != numeric_limits<long long>::max()) {
                    // 不跳过休息时间后，所需时间
                    long long no_skip_time = (dp[i - 1][j] + dist[i - 1] + speed - 1) / speed * speed;
                    // 检查是否会发生整数溢出
                    if (no_skip_time <= numeric_limits<long long>::max() - dist[i - 1]) {
                        dp[i][j] = min(dp[i][j], no_skip_time);
                    }
                }
            }
        }

        // 找到最小跳过次数
        for (int j = 0; j <= n; ++j) {
            if (dp[n][j] <= (long long)hoursBefore * speed) {
                return j;
            }
        }

        // 无法准时参会
        return -1;
    }
};

int main() {
    // 示例输入
    vector<int> dist = { 1, 3, 2 };
    int speed = 4;
    int hoursBefore = 2;

    Solution sol;
    // 调用函数计算最小跳过次数
    int min_skips = sol.minSkips(dist, speed, hoursBefore);
    // 输出结果
    cout << "最小跳过次数：" << min_skips << endl;

    return 0;
}
