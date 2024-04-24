//2385. 感染二叉树需要的总时间
//给你一棵二叉树的根节点 root ，二叉树中节点的值 互不相同 。另给你一个整数 start 。在第 0 分钟，感染 将会从值为 start 的节点开始爆发。
//每分钟，如果节点满足以下全部条件，就会被感染：
//- 节点此前还没有感染。
//- 节点与一个已感染节点相邻。
//返回感染整棵树需要的分钟数。

//示例 1：
//输入：root = [1,5,3,null,4,10,6,9,2], start = 3
//输出：4
//解释：节点按以下过程被感染：
//- 第 0 分钟：节点 3
//- 第 1 分钟：节点 1、10、6
//- 第 2 分钟：节点5
//- 第 3 分钟：节点 4
//- 第 4 分钟：节点 9 和 2
//感染整棵树需要 4 分钟，所以返回 4 。

//示例 2：
//输入：root = [1], start = 1
//输出：0
//解释：第 0 分钟，树中唯一一个节点处于感染状态，返回 0 。

#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <unordered_set>
#include <functional> // 添加此行

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int amountOfTime(TreeNode* root, int start) {
        // 构建无向图
        unordered_map<int, vector<int>> graph;
        function<void(TreeNode*)> dfs = [&](TreeNode* node) {
            for (TreeNode* child : vector<TreeNode*>{ node->left, node->right }) {
                if (child != nullptr) {
                    // 添加节点和其子节点到图中
                    graph[node->val].push_back(child->val);
                    graph[child->val].push_back(node->val);
                    dfs(child);
                }
            }
            };
        dfs(root);

        // BFS 遍历图
        queue<vector<int>> q;
        q.push({ start, 0 }); // 起始节点和其感染时间放入队列中
        unordered_set<int> visited;
        visited.insert(start);
        int time = 0;
        while (!q.empty()) {
            auto arr = q.front();
            q.pop();
            int nodeVal = arr[0];
            time = arr[1];
            for (int childVal : graph[nodeVal]) {
                if (!visited.count(childVal)) {
                    q.push({ childVal, time + 1 }); // 更新感染时间并放入队列
                    visited.insert(childVal);
                }
            }
        }
        return time;
    }
};

int main() {
    // 创建二叉树
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(5);
    root->right = new TreeNode(3);
    root->right->left = nullptr;
    root->right->right = new TreeNode(4);
    root->left->left = new TreeNode(10);
    root->left->right = new TreeNode(6);
    root->left->right->left = new TreeNode(9);
    root->left->right->right = new TreeNode(2);

    int start = 3; // 感染开始的节点值

    Solution solution;
    int minutes = solution.amountOfTime(root, start);

    cout << "感染整棵树需要 " << minutes << " 分钟" << endl;

    // 释放内存
    delete root->left->right->right;
    delete root->left->right->left;
    delete root->left->right;
    delete root->left->left;
    delete root->right->right;
    delete root->right;
    delete root->left;
    delete root;

    return 0;
}
