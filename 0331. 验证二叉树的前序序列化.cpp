//331. 验证二叉树的前序序列化
//序列化二叉树的一种方法是使用 前序遍历 。当我们遇到一个非空节点时，我们可以记录下这个节点的值。如果它是一个空节点，我们可以使用一个标记值记录，例如 #。
//例如，上面的二叉树可以被序列化为字符串 "9,3,4,#,#,1,#,#,2,#,6,#,#"，其中 # 代表一个空节点。
//给定一串以逗号分隔的序列，验证它是否是正确的二叉树的前序序列化。编写一个在不重构树的条件下的可行算法。
//保证 每个以逗号分隔的字符或为一个整数或为一个表示 null 指针的 '#' 。
//你可以认为输入格式总是有效的
//例如它永远不会包含两个连续的逗号，比如 "1,,3" 。
//注意：不允许重建树。
//
//示例 1:
//: preorder = "9,3,4,#,#,1,#,#,2,#,6,#,#"
//输出: true
//
//示例 2:
//输入: preorder = "1,#"
//输出: false
//
//示例 3:
//输入: preorder = "9,#,#,1"
//输出: false

#include <iostream>
#include <string>
#include <stack>

using namespace std;

class Solution {
public:
    bool isValidSerialization(string preorder) {
        stack<char> stk;
        int i = 0, n = (int)preorder.size();

        while (i < n) {
            if (preorder[i] == ',') {
                i++;
                continue;
            }
            else if (preorder[i] == '#') {
                if (!stk.empty() && stk.top() == '#') {
                    while (!stk.empty() && stk.top() == '#') {
                        stk.pop(); // 弹出栈顶的 '#'
                        if (stk.empty()) return false; // 无效
                        stk.pop(); // 弹出节点值
                    }
                    stk.push('#'); // 入栈表示一个子树结束
                }
                else {
                    stk.push('#'); // 入栈表示一个叶子节点
                }
            }
            else { // 数值节点
                while (i < n && preorder[i] != ',') {
                    i++;
                }
                stk.push('x'); // 入栈表示一个数值节点
            }
            i++;
        }

        return stk.size() == 1 && stk.top() == '#'; // 如果栈中只剩下一个 '#'，则序列有效
    }
};

int main() {
    Solution sol;
    string preorder1 = "9,3,4,#,#,1,#,#,2,#,6,#,#";
    string preorder2 = "1,#";
    string preorder3 = "9,#,#,1";

    cout << "示例1结果：" << (sol.isValidSerialization(preorder1) ? "true" : "false") << endl;
    cout << "示例2结果：" << (sol.isValidSerialization(preorder2) ? "true" : "false") << endl;
    cout << "示例3结果：" << (sol.isValidSerialization(preorder3) ? "true" : "false") << endl;

    return 0;
}
