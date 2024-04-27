//2639. 查询网格图中每一列的宽度
//给你一个下标从 0 开始的 m x n 整数矩阵 grid 。矩阵中某一列的宽度是这一列数字的最大 字符串长度 。
//比方说，如果 grid = [[-10], [3], [12]] ，那么唯一一列的宽度是 3 ，因为 -10 的字符串长度为 3 。
//请你返回一个大小为 n 的整数数组 ans ，其中 ans[i] 是第 i 列的宽度。
//一个有 len 个数位的整数 x ，如果是非负数，那么 字符串长度 为 len ，否则为 len + 1 。

//示例 1：
//输入：grid = [[1],[22],[333]]
//输出：[3]
//解释：第 0 列中，333 字符串长度为 3 。

//示例 2：
//输入：grid = [[-15,1,3],[15,7,12],[5,6,-2]]
//输出：[3,1,2]
//解释：
//第 0 列中，只有 -15 字符串长度为 3 。
//第 1 列中，所有整数的字符串长度都是 1 。
//第 2 列中，12 和 -2 的字符串长度都为 2 。

#include <vector>
#include <string>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> findColumnWidth(vector<vector<int>>& grid) {
        int m = (int)grid.size();
        int n = (int)((m > 0) ? grid[0].size() : 0);

        // 初始化每一列的宽度为0
        vector<int> widths(n, 0);

        for (int col = 0; col < n; ++col) {
            // 遍历每一列，找到该列的最大宽度
            for (int row = 0; row < m; ++row) {
                int width = (int)std::to_string(grid[row][col]).length(); // 计算每个数字的字符串长度
                widths[col] = std::max(widths[col], width); // 更新当前列的宽度
            }
        }

        return widths;
    }
};

int main() {
    // 示例用法
    vector<vector<int>> grid = { {-10, 123, 456}, {3, -100, 7}, {12, 34, 5678} };
    Solution sol;
    vector<int> widths = sol.findColumnWidth(grid);

    // 输出每一列的宽度
    cout << "每一列的宽度：" ;
    for (int width : widths) {
        cout << width << " ";
    }
    cout << endl;

    return 0;
}
