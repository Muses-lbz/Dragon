//705. 设计哈希集合
//不使用任何内建的哈希表库设计一个哈希集合（HashSet）。
//实现 MyHashSet 类：
//void add(key) 向哈希集合中插入值 key 。
//bool contains(key) 返回哈希集合中是否存在这个值 key 。
//void remove(key) 将给定值 key 从哈希集合中删除。如果哈希集合中没有这个值，什么也不做。
 
//示例：
//输入：
//["MyHashSet", "add", "add", "contains", "contains", "add", "contains", "remove", "contains"]
//[[], [1], [2], [1], [3], [2], [2], [2], [2]]
//输出：
//[null, null, null, true, false, null, true, null, false]
//解释：
//MyHashSet myHashSet = new MyHashSet();
//myHashSet.add(1);      // set = [1]
//myHashSet.add(2);      // set = [1, 2]
//myHashSet.contains(1); // 返回 True
//myHashSet.contains(3); // 返回 False ，（未找到）
//myHashSet.add(2);      // set = [1, 2]
//myHashSet.contains(2); // 返回 True
//myHashSet.remove(2);   // set = [1]
//myHashSet.contains(2); // 返回 False ，（已移除）

#include <iostream>
#include <vector>

using namespace std;

class MyHashSet {
private:
    std::vector<std::vector<int>> data; // 使用二维向量存储哈希集合数据
    static const int base = 769; // 可以选择一个较大的素数作为基数

    // 哈希函数，计算键的哈希值
    static int hash(int key) {
        return key % base; // 取余数作为哈希值
    }

public:
    MyHashSet() : data(base) {} // 构造函数，初始化二维向量

    // 添加元素到哈希集合
    void add(int key) {
        int h = hash(key); // 计算键的哈希值
        for (auto it = data[h].begin(); it != data[h].end(); ++it) { // 遍历哈希值对应的向量
            if (*it == key) return; // 如果找到相同的值，直接返回，不添加
        }
        data[h].push_back(key); // 向向量中添加元素
    }

    // 从哈希集合中移除元素
    void remove(int key) {
        int h = hash(key); // 计算键的哈希值
        for (auto it = data[h].begin(); it != data[h].end(); ++it) { // 遍历哈希值对应的向量
            if (*it == key) { // 如果找到相同的值
                data[h].erase(it); // 从向量中删除该值
                return;
            }
        }
    }

    // 检查哈希集合中是否包含指定的元素
    bool contains(int key) {
        int h = hash(key); // 计算键的哈希值
        for (auto it = data[h].begin(); it != data[h].end(); ++it) { // 遍历哈希值对应的向量
            if (*it == key) return true; // 如果找到相同的值，返回true
        }
        return false; // 否则返回false
    }
};

int main() {
    // 创建一个哈希集合对象
    MyHashSet* obj = new MyHashSet();

    // 向哈希集合中添加值 1
    obj->add(1);
    // 向哈希集合中添加值 2
    obj->add(2);

    // 检查哈希集合中是否包含值 1
    std::cout << "是否包含值 1: " << (obj->contains(1) ? "True" : "False") << std::endl;
    // 检查哈希集合中是否包含值 3
    std::cout << "是否包含值 3: " << (obj->contains(3) ? "True" : "False") << std::endl;

    // 再次向哈希集合中添加值 2
    obj->add(2);

    // 检查哈希集合中是否包含值 2
    std::cout << "是否包含值 2: " << (obj->contains(2) ? "True" : "False") << std::endl;

    // 从哈希集合中移除值 2
    obj->remove(2);

    // 再次检查哈希集合中是否包含值 2
    std::cout << "是否包含值 2: " << (obj->contains(2) ? "True" : "False") << std::endl;

    return 0;
}
