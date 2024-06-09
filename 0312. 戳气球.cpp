//0312. 戳气球
//有 n 个气球，编号为0 到 n - 1，每个气球上都标有一个数字，这些数字存在数组 nums 中。
//现在要求你戳破所有的气球。戳破第 i 个气球，你可以获得 nums[i - 1] * nums[i] * nums[i + 1] 枚硬币。 
//这里的 i - 1 和 i + 1 代表和 i 相邻的两个气球的序号。如果 i - 1或 i + 1 超出了数组的边界，那么就当它是一个数字为 1 的气球。
//求所能获得硬币的最大数量。

//示例 1：
//输入：nums = [3,1,5,8]
//输出：167
//解释：
//nums = [3,1,5,8] --> [3,5,8] --> [3,8] --> [8] --> []
//coins =  3*1*5    +   3*5*8   +  1*3*8  + 1*8*1 = 167

//示例 2：
//输入：nums = [1,5]
//输出：10

#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        // 加上两端的虚拟气球
        vector<int> balloons(n + 2, 1);
        for (int i = 0; i < n; ++i) {
            balloons[i + 1] = nums[i];
        }

        // dp数组，dp[i][j]表示戳破区间[i, j]的最大硬币数
        vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));

        // 区间长度从1到n
        for (int len = 1; len <= n; ++len) {
            for (int left = 1; left <= n - len + 1; ++left) {
                int right = left + len - 1;
                for (int k = left; k <= right; ++k) {
                    dp[left][right] = max(dp[left][right],
                        dp[left][k - 1] +
                        balloons[left - 1] * balloons[k] * balloons[right + 1] +
                        dp[k + 1][right]);
                }
            }
        }

        // 返回戳破所有气球的最大硬币数
        return dp[1][n];
    }
};

int main() {
    // 示例输入
    vector<int> nums = { 3, 1, 5, 8 };

    // 创建Solution对象并调用maxCoins函数
    Solution sol;
    int result = sol.maxCoins(nums);

    // 输出结果
    cout << "戳破所有气球能获得的最大硬币数是: " << result << endl;

    return 0;
}
