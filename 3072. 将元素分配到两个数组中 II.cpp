/*3072. 将元素分配到两个数组中 II
给你一个下标从 1 开始、长度为 n 的整数数组 nums 。
现定义函数 greaterCount ，使得 greaterCount(arr, val) 返回数组 arr 中 严格大于 val 的元素数量。
你需要使用 n 次操作，将 nums 的所有元素分配到两个数组 arr1 和 arr2 中。在第一次操作中，将 nums[1] 追加到 arr1 。在第二次操作中，将 nums[2] 追加到 arr2 。之后，在第 i 次操作中：
如果 greaterCount(arr1, nums[i]) > greaterCount(arr2, nums[i]) ，将 nums[i] 追加到 arr1 。
如果 greaterCount(arr1, nums[i]) < greaterCount(arr2, nums[i]) ，将 nums[i] 追加到 arr2 。
如果 greaterCount(arr1, nums[i]) == greaterCount(arr2, nums[i]) ，将 nums[i] 追加到元素数量较少的数组中。
如果仍然相等，那么将 nums[i] 追加到 arr1 。
连接数组 arr1 和 arr2 形成数组 result 。例如，如果 arr1 == [1,2,3] 且 arr2 == [4,5,6] ，那么 result = [1,2,3,4,5,6] 。
返回整数数组 result 。

示例 1：
输入：nums = [2,1,3,3]
输出：[2,3,1,3]
解释：在前两次操作后，arr1 = [2] ，arr2 = [1] 。
在第 3 次操作中，两个数组中大于 3 的元素数量都是零，并且长度相等，因此，将 nums[3] 追加到 arr1 。
在第 4 次操作中，两个数组中大于 3 的元素数量都是零，但 arr2 的长度较小，因此，将 nums[4] 追加到 arr2 。
在 4 次操作后，arr1 = [2,3] ，arr2 = [1,3] 。
因此，连接形成的数组 result 是 [2,3,1,3] 。

示例 2：
输入：nums = [5,14,3,1,2]
输出：[5,3,1,2,14]
解释：在前两次操作后，arr1 = [5] ，arr2 = [14] 。
在第 3 次操作中，两个数组中大于 3 的元素数量都是一，并且长度相等，因此，将 nums[3] 追加到 arr1 。
在第 4 次操作中，arr1 中大于 1 的元素数量大于 arr2 中的数量（2 > 1），因此，将 nums[4] 追加到 arr1 。
在第 5 次操作中，arr1 中大于 2 的元素数量大于 arr2 中的数量（2 > 1），因此，将 nums[5] 追加到 arr1 。
在 5 次操作后，arr1 = [5,3,1,2] ，arr2 = [14] 。
因此，连接形成的数组 result 是 [5,3,1,2,14] 。*/

#include <vector>
#include <unordered_map>
#include <algorithm>
#include <iostream>

class BinaryIndexedTree {
private:
    std::vector<int> tree; // 树状数组

public:
    // 构造函数，初始化树状数组
    BinaryIndexedTree(int n) : tree(n + 1) {}

    // 在索引 i 处添加一个元素
    void add(int i) {
        while (i < tree.size()) {
            tree[i] += 1;
            i += i & -i; // 更新索引，跳到父节点
        }
    }

    // 获取从 1 到 i 的元素和
    int get(int i) {
        int res = 0;
        while (i > 0) {
            res += tree[i];
            i &= i - 1; // 更新索引，跳到前一个节点
        }
        return res;
    }
};

class Solution {
public:
    std::vector<int> resultArray(std::vector<int>& nums) {
        int n = (int)nums.size();

        // 创建排序后的 nums 副本
        std::vector<int> sortedNums = nums;
        std::sort(sortedNums.begin(), sortedNums.end());

        // 创建值到索引的映射
        std::unordered_map<int, int> index;
        for (int i = 0; i < n; ++i) {
            index[sortedNums[i]] = i + 1;
        }

        // 初始化 arr1 和 arr2
        std::vector<int> arr1 = { nums[0] };
        std::vector<int> arr2 = { nums[1] };

        // 初始化树状数组
        BinaryIndexedTree tree1(n), tree2(n);
        tree1.add(index[nums[0]]);
        tree2.add(index[nums[1]]);

        // 遍历 nums 的剩余元素
        for (int i = 2; i < n; ++i) {
            int idx = index[nums[i]];
            int count1 = (int)(arr1.size() - tree1.get(idx)); // arr1 中严格大于 nums[i] 的数量
            int count2 = (int)(arr2.size() - tree2.get(idx)); // arr2 中严格大于 nums[i] 的数量

            // 根据规则将 nums[i] 添加到 arr1 或 arr2
            if (count1 > count2 || (count1 == count2 && arr1.size() <= arr2.size())) {
                arr1.push_back(nums[i]);
                tree1.add(idx);
            }
            else {
                arr2.push_back(nums[i]);
                tree2.add(idx);
            }
        }

        // 连接 arr1 和 arr2 形成最终结果
        arr1.insert(arr1.end(), arr2.begin(), arr2.end());
        return arr1;
    }
};

int main() {
    // 测试用例
    std::vector<int> nums1 = { 2, 1, 3, 3 };
    std::vector<int> nums2 = { 5, 14, 3, 1, 2 };

    Solution solution;

    // 计算并输出结果
    std::vector<int> result1 = solution.resultArray(nums1);
    std::vector<int> result2 = solution.resultArray(nums2);

    std::cout << "Result for nums1: ";
    for (int num : result1) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    std::cout << "Result for nums2: ";
    for (int num : result2) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
