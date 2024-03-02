//2368. 受限条件下可到达节点的数目
//现有一棵由 n 个节点组成的无向树，节点编号从 0 到 n - 1 ，共有 n - 1 条边。
//给你一个二维整数数组 edges ，长度为 n - 1 ，其中 edges[i] = [ai, bi] 表示树中节点 ai 和 bi 之间存在一条边。另给你一个整数数组 restricted 表示 受限 节点。
//在不访问受限节点的前提下，返回你可以从节点 0 到达的 最多 节点数目。
//注意，节点 0 不 会标记为受限节点。

//示例1：
//输入：n = 7, edges = [[0,1],[1,2],[3,1],[4,0],[0,5],[5,6]], restricted = [4,5]
//输出：4
//解释：上图所示正是这棵树。
//在不访问受限节点的前提下，只有节点 [0,1,2,3] 可以从节点 0 到达。

//示例2：
//输入：n = 7, edges = [[0,1],[0,2],[0,5],[0,4],[3,2],[6,5]], restricted = [4,2,1]
//输出：3
//解释：上图所示正是这棵树。
//在不访问受限节点的前提下，只有节点 [0,5,6] 可以从节点 0 到达。

#include <iostream>
#include <vector>
#include <functional> // for std::function

using namespace std;

class Solution {
public:
    // 可达节点数计算函数
    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& restricted) {
        // 标记受限节点
        vector<int> isrestricted(n);
        for (auto x : restricted) {
            isrestricted[x] = 1;
        }

        // 构建图的邻接表
        vector<vector<int>> g(n);
        for (auto& v : edges) {
            g[v[0]].push_back(v[1]);
            g[v[1]].push_back(v[0]);
        }
        int cnt = 0; // 可达节点数
        // 深度优先搜索函数
        function<void(int, int)> dfs = [&](int x, int f) {
            cnt++; // 当前节点可达，计数加一
            for (auto& y : g[x]) {
                // 遍历相邻节点
                if (y != f && !isrestricted[y]) {
                    dfs(y, x); // 递归调用深度优先搜索
                }
            }
            };
        dfs(0, -1); // 从节点 0 开始深度优先搜索
        return cnt; // 返回可达节点数
    }
};

int main() {
    // 使用示例
    Solution solution;
    int n = 7;
    vector<vector<int>> edges = { {0,1},{1,2},{3,1},{4,0},{0,5},{5,6} };
    vector<int> restricted = { 4,5 };
    // 计算最大可达节点数
    int result = solution.reachableNodes(n, edges, restricted);
    cout << "从节点 0 可达的最大节点数: " << result << endl;

    return 0;
}
