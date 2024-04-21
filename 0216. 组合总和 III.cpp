//216. 组合总和 III
//找出所有相加之和为 n 的 k 个数的组合，且满足下列条件：
//只使用数字1到9
//每个数字 最多使用一次 
//返回 所有可能的有效组合的列表 。该列表不能包含相同的组合两次，组合可以以任何顺序返回。

//示例 1:
//输入: k = 3, n = 7
//输出: [[1,2,4]]
//解释:
//1 + 2 + 4 = 7
//没有其他符合的组合了。

//示例 2:
//输入: k = 3, n = 9
//输出: [[1,2,6], [1,3,5], [2,3,4]]
//解释:
//1 + 2 + 6 = 9
//1 + 3 + 5 = 9
//2 + 3 + 4 = 9
//没有其他符合的组合了。

//示例 3:
//输入: k = 4, n = 1
//输出: []
//解释: 不存在有效的组合。
//在[1,9]范围内使用4个不同的数字，我们可以得到的最小和是1+2+3+4 = 10，因为10 > 1，没有有效的组合。

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    /**
     * @brief 在数字1到9中找出所有相加之和为n的k个数的组合
     *
     * @param k 数字个数
     * @param n 目标和
     * @return vector<vector<int>> 返回所有可能的有效组合的列表
     */
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> result;
        vector<int> current;
        backtrack(result, current, k, n, 1);
        return result;
    }

private:
    /**
     * @brief 回溯函数，用于生成所有可能的组合
     *
     * @param result 存储结果的二维数组
     * @param current 当前组合
     * @param k 目标数字个数
     * @param remain 剩余目标和
     * @param start 起始数字
     */
    void backtrack(vector<vector<int>>& result, vector<int>& current, int k, int remain, int start) {
        // 如果目标和为0且当前组合长度为k，则将当前组合加入结果集
        if (remain == 0 && current.size() == k) {
            result.push_back(current);
            return;
        }

        // 如果剩余目标和小于0或者当前组合长度已经达到k，则返回
        if (remain < 0 || current.size() >= k) {
            return;
        }

        // 从start开始遍历数字
        for (int i = start; i <= 9; ++i) {
            current.push_back(i); // 将当前数字加入组合
            // 递归调用backtrack函数，继续寻找下一个数字
            backtrack(result, current, k, remain - i, i + 1);
            current.pop_back(); // 回溯，移除当前数字，继续尝试其他数字
        }
    }
};

int main() {
    Solution sol;

    // 示例测试
    int k1 = 3, n1 = 7;
    vector<vector<int>> res1 = sol.combinationSum3(k1, n1);
    cout << "k = " << k1 << ", n = " << n1 << endl;
    for (const auto& comb : res1) {
        cout << "[ ";
        for (int num : comb) {
            cout << num << " ";
        }
        cout << "]" << endl;
    }

    int k2 = 3, n2 = 9;
    vector<vector<int>> res2 = sol.combinationSum3(k2, n2);
    cout << "k = " << k2 << ", n = " << n2 << endl;
    for (const auto& comb : res2) {
        cout << "[ ";
        for (int num : comb) {
            cout << num << " ";
        }
        cout << "]" << endl;
    }

    int k3 = 4, n3 = 1;
    vector<vector<int>> res3 = sol.combinationSum3(k3, n3);
    cout << "k = " << k3 << ", n = " << n3 << endl;
    for (const auto& comb : res3) {
        cout << "[ ";
        for (int num : comb) {
            cout << num << " ";
        }
        cout << "]" << endl;
    }

    return 0;
}
