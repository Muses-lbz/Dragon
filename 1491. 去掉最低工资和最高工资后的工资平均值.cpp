//1491. 去掉最低工资和最高工资后的工资平均值
//给你一个整数数组 salary ，数组里每个数都是 唯一 的，其中 salary[i] 是第 i 个员工的工资。
//请你返回去掉最低工资和最高工资以后，剩下员工工资的平均值。

//示例 1：
//输入：salary = [4000,3000,1000,2000]
//输出：2500.00000
//解释：最低工资和最高工资分别是 1000 和 4000 。
//去掉最低工资和最高工资以后的平均工资是 (2000+3000)/2= 2500

//示例 2：
//输入：salary = [1000,2000,3000]
//输出：2000.00000
//解释：最低工资和最高工资分别是 1000 和 3000 。
//去掉最低工资和最高工资以后的平均工资是 (2000)/1= 2000

#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
    double average(std::vector<int>& salary) {
        // 对工资数组进行排序
        std::sort(salary.begin(), salary.end());

        // 去掉最低工资和最高工资
        salary.erase(salary.begin());
        salary.pop_back();

        // 计算剩余工资的总和
        double sum = 0;
        for (int s : salary) {
            sum += s;
        }

        // 计算平均工资
        return sum / salary.size();
    }
};

int main() {
    std::vector<int> salary = { 4000, 3000, 1000, 2000 };
    Solution sol;
    double avg = sol.average(salary);
    std::cout << "Average salary: " << avg << std::endl;
    return 0;
}
