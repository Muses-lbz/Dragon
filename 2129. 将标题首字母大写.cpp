//2129. 将标题首字母大写
//给你一个字符串 title ，它由单个空格连接一个或多个单词组成，每个单词都只包含英文字母。
//请你按以下规则将每个单词的首字母 大写 ：
//如果单词的长度为 1 或者 2 ，所有字母变成小写。
//否则，将单词首字母大写，剩余字母变成小写。
//请你返回 大写后 的 title 。

//示例 1：
//输入：title = "capiTalIze tHe titLe"
//输出："Capitalize The Title"
//解释：
//由于所有单词的长度都至少为 3 ，将每个单词首字母大写，剩余字母变为小写。

//示例 2：
//输入：title = "First leTTeR of EACH Word"
//输出："First Letter of Each Word"
//解释：
//单词 "of" 长度为 2 ，所以它保持完全小写。
//其他单词长度都至少为 3 ，所以其他单词首字母大写，剩余字母小写。

//示例 3：
//输入：title = "i lOve leetcode"
//输出："i Love Leetcode"
//解释：
//单词 "i" 长度为 1 ，所以它保留小写。
//其他单词长度都至少为 3 ，所以其他单词首字母大写，剩余字母小写。

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string capitalizeTitle(string title) {
        int n = (int)title.size();
        int l = 0, r = 0;   // 单词左右边界（左闭右开）
        while (r < n) {
            while (r < n && title[r] != ' ') {
                ++r;
            }
            // 对于每个单词按要求处理
            if (r - l > 2) {
                title[l] = toupper(title[l]); // 将首字母大写
            }
            ++l; // 移动到单词中的下一个字母
            while (l < r) {
                title[l] = tolower(title[l]); // 将其他字母变为小写
                ++l; // 移动到单词中的下一个字母
            }
            l = ++r; // 移动到下一个单词的左边界
        }
        return title;
    }
};

int main() {
    Solution sol;
    string title = "First leTTeR of EACH Word";
    cout << "Original title: " << title << endl;
    string capitalizedTitle = sol.capitalizeTitle(title);
    cout << "Capitalized title: " << capitalizedTitle << endl;

    return 0;
}
