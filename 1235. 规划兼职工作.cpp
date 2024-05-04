//1235. 规划兼职工作
//你打算利用空闲时间来做兼职工作赚些零花钱。
//这里有 n 份兼职工作，每份工作预计从 startTime[i] 开始到 endTime[i] 结束，报酬为 profit[i]。
//给你一份兼职工作表，包含开始时间 startTime，结束时间 endTime 和预计报酬 profit 三个数组，请你计算并返回可以获得的最大报酬。
//注意，时间上出现重叠的 2 份工作不能同时进行。
//如果你选择的工作在时间 X 结束，那么你可以立刻进行在时间 X 开始的下一份工作。

//示例 1：
//输入：startTime = [1,2,3,3], endTime = [3,4,5,6], profit = [50,10,40,70]
//输出：120
//解释：
//我们选出第 1 份和第 4 份工作， 
//时间范围是 [1-3]+[3-6]，共获得报酬 120 = 50 + 70。

//示例 2：
//输入：startTime = [1,2,3,4,6], endTime = [3,5,10,6,9], profit = [20,20,100,70,60]
//输出：150
//解释：
//我们选择第 1，4，5 份工作。 
//共获得报酬 150 = 20 + 70 + 60。

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
		int n = (int)startTime.size();
		vector<vector<int>> jobs(n);
		for (int i = 0; i < n; i++) {
			jobs[i] = { startTime[i], endTime[i], profit[i] };
		}
		// 按照结束时间排序
		sort(jobs.begin(), jobs.end(), [](const vector<int>& job1, const vector<int>& job2) -> bool {
			return job1[1] < job2[1];
			});
		vector<int> dp(n + 1);
		for (int i = 1; i <= n; i++) {
			// 在时间点 jobs[i-1][0] 之前结束的工作的下标
			// 显式转换为 int 类型
			int k = static_cast<int>(upper_bound(jobs.begin(), jobs.begin() + i - 1, jobs[i - 1][0], [&](int st, const vector<int>& job) -> bool {
				return st < job[1];
				}) - jobs.begin());

			// 当前工作选择和不选择的最大报酬
			dp[i] = max(dp[i - 1], dp[k] + jobs[i - 1][2]);
		}
		return dp[n];
	}
};

int main() {
	vector<int> startTime = { 1, 2, 3, 4, 6 };
	vector<int> endTime = { 3, 5, 10, 6, 9 };
	vector<int> profit = { 20, 20, 100, 70, 60 };

	Solution solution;
	int maxProfit = solution.jobScheduling(startTime, endTime, profit);
	cout << "最大报酬：" << maxProfit << endl;

	return 0;
}
