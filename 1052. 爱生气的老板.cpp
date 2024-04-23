//1052. 爱生气的老板
//有一个书店老板，他的书店开了 n 分钟。每分钟都有一些顾客进入这家商店。
//给定一个长度为 n 的整数数组 customers ，其中 customers[i] 是在第 i 分钟开始时进入商店的顾客数量，所有这些顾客在第 i 分钟结束后离开。
//在某些时候，书店老板会生气。 如果书店老板在第 i 分钟生气，那么 grumpy[i] = 1，否则 grumpy[i] = 0。
//当书店老板生气时，那一分钟的顾客就会不满意，若老板不生气则顾客是满意的。
//书店老板知道一个秘密技巧，能抑制自己的情绪，可以让自己连续 minutes 分钟不生气，但却只能使用一次。
//请你返回 这一天营业下来，最多有多少客户能够感到满意 。

//示例 1：
//输入：customers = [1,0,1,2,1,1,7,5], grumpy = [0,1,0,1,0,1,0,1], minutes = 3
//输出：16
//解释：书店老板在最后 3 分钟保持冷静。
//感到满意的最大客户数量 = 1 + 1 + 1 + 1 + 7 + 5 = 16.

//示例 2：
//输入：customers = [1], grumpy = [0], minutes = 1
//输出：1

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int satisfied = 0; // 记录老板不使用技巧时满意顾客的数量
        int extraSatisfied = 0; // 记录老板使用技巧后额外的满意顾客数量
        int maxExtraSatisfied = 0; // 记录滑动窗口内的最大额外满意顾客数量
        int n = (int)customers.size();

        // 计算老板不使用技巧时满意顾客的数量
        for (int i = 0; i < n; ++i) {
            if (grumpy[i] == 0) {
                satisfied += customers[i];
            }
        }

        // 滑动窗口计算额外满意顾客数量
        int left = 0, right = 0;
        while (right < n) {
            // 如果窗口大小大于 minutes，则左边界右移
            if (right - left >= minutes) {
                if (grumpy[left] == 1) {
                    extraSatisfied -= customers[left];
                }
                ++left;
            }

            // 如果当前分钟老板生气，则累加额外满意顾客数量
            if (grumpy[right] == 1) {
                extraSatisfied += customers[right];
            }

            // 更新滑动窗口内的最大额外满意顾客数量
            maxExtraSatisfied = max(maxExtraSatisfied, extraSatisfied);

            ++right;
        }

        // 返回老板不使用技巧时满意顾客数量与使用技巧后最大额外满意顾客数量的总和
        return satisfied + maxExtraSatisfied;
    }
};

int main() {
    Solution solution;
    vector<int> customers = { 1, 0, 1, 2, 1, 1, 7, 5 };
    vector<int> grumpy = { 0, 1, 0, 1, 0, 1, 0, 1 };
    int minutes = 3;
    int maxSatisfied = solution.maxSatisfied(customers, grumpy, minutes);
    cout << "最多有 " << maxSatisfied << " 客户感到满意。" << endl;
    return 0;
}
