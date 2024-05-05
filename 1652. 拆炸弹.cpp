//1652. 拆炸弹
//你有一个炸弹需要拆除，时间紧迫！你的情报员会给你一个长度为 n 的 循环 数组 code 以及一个密钥 k 。
//为了获得正确的密码，你需要替换掉每一个数字。所有数字会 同时 被替换。
//如果 k > 0 ，将第 i 个数字用 接下来 k 个数字之和替换。
//如果 k < 0 ，将第 i 个数字用 之前 k 个数字之和替换。
//如果 k == 0 ，将第 i 个数字用 0 替换。
//由于 code 是循环的， code[n-1] 下一个元素是 code[0] ，且 code[0] 前一个元素是 code[n-1] 。
//给你 循环 数组 code 和整数密钥 k ，请你返回解密后的结果来拆除炸弹！

//示例 1：
//输入：code = [5,7,1,4], k = 3
//输出：[12,10,16,13]
//解释：每个数字都被接下来 3 个数字之和替换。解密后的密码为 [7+1+4, 1+4+5, 4+5+7, 5+7+1]。注意到数组是循环连接的。
//示例 2：
//输入：code = [1,2,3,4], k = 0
//输出：[0,0,0,0]
//解释：当 k 为 0 时，所有数字都被 0 替换。
//示例 3：
//输入：code = [2,4,9,3], k = -2
//输出：[12,5,6,13]
//解释：解密后的密码为 [3+9, 2+3, 4+2, 9+4] 。注意到数组是循环连接的。如果 k 是负数，那么和为 之前 的数字。

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int n = code.size();
        vector<int> result(n, 0); // 创建一个与输入数组相同大小的结果数组，并初始化为零

        if (k == 0) { // 如果 k 等于 0，则直接返回结果数组
            return result;
        }

        for (int i = 0; i < n; ++i) { // 遍历循环数组
            int sum = 0; // 初始化当前索引位置的替换值为零
            if (k > 0) { // 如果 k 大于 0，则向后取和
                for (int j = 1; j <= k; ++j) { // 遍历取和的数字个数
                    sum += code[(i + j) % n]; // 计算当前索引位置的替换值
                }
            }
            else { // 如果 k 小于 0，则向前取和
                for (int j = -1; j >= k; --j) { // 遍历取和的数字个数
                    sum += code[(i + j + n) % n]; // 计算当前索引位置的替换值
                }
            }
            result[i] = sum; // 将计算得到的替换值存储在结果数组中
        }

        return result; // 返回结果数组
    }
};

int main() {
    Solution solution;
    vector<int> code = { 5, 7, 1, 4 };
    int k = 3;
    vector<int> decrypted_code = solution.decrypt(code, k);
    cout << "Decrypted code:";
    for (int num : decrypted_code) {
        cout << " " << num;
    }
    cout << endl;
    return 0;
}
