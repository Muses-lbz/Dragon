//377. 组合总和 Ⅳ
//给你一个由 不同 整数组成的数组 nums ，和一个目标整数 target 。请你从 nums 中找出并返回总和为 target 的元素组合的个数。
//题目数据保证答案符合 32 位整数范围。 

//示例 1：
//输入：nums = [1,2,3], target = 4
//输出：7
//解释：
//所有可能的组合为：
//(1, 1, 1, 1)
//(1, 1, 2)
//(1, 2, 1)
//(1, 3)
//(2, 1, 1)
//2, 2)
//(3, 1)
//请注意，顺序不同的序列被视作不同的组合。

//示例 2：
//输入：nums = [9], target = 3
//输出：0

#include <iostream>
#include <vector>

class Solution {
public:
    // 计算总和为 target 的组合数
    int combinationSum4(std::vector<int>& nums, int target) {
        // 创建一个数组 dp，大小为 target+1，初始化为0
        std::vector<unsigned int> dp(target + 1, 0);
        dp[0] = 1; // 空集合是一种解法

        // 动态规划：计算每个目标值对应的组合数
        for (int i = 1; i <= target; ++i) {
            // 遍历数组 nums
            for (int j = 0; j < nums.size(); ++j) {
                // 如果当前数 nums[j] 小于等于目标值 i
                if (i >= nums[j]) {
                    // 更新 dp[i]，加上以 nums[j] 结尾的组合数
                    dp[i] += dp[i - nums[j]];
                }
            }
        }
        // 返回目标值 target 对应的组合数
        return dp[target];
    }
};

int main() {
    // 创建 Solution 类的实例
    Solution sol;

    // 示例 1 输入
    std::vector<int> nums1 = { 1, 2, 3 };
    int target1 = 4;

    // 示例 1 输出
    int result1 = sol.combinationSum4(nums1, target1);
    std::cout << "示例 1 输出: " << result1 << std::endl;

    // 示例 2 输入
    std::vector<int> nums2 = { 9 };
    int target2 = 3;

    // 示例 2 输出
    int result2 = sol.combinationSum4(nums2, target2);
    std::cout << "示例 2 输出: " << result2 << std::endl;

    return 0;
}
