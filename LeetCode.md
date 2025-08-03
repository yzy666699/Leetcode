# LeetCode

## 热题100

### 1 两数之和

给定一个整数数组 `nums` 和一个整数目标值 `target`，请你在该数组中找出 **和为目标值** *`target`* 的那 **两个** 整数，并返回它们的数组下标。

你可以假设每种输入只会对应一个答案，并且你不能使用两次相同的元素。

```
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target)
    {

        int temp = 0;
        vector<int> ret;
        for(int i =0;i<nums.size();++i)
        {
            temp = nums[i];
            for(int m = i + 1;m<nums.size();m++)
            {
                if(temp+nums[m] == target)
                {
                    ret.push_back(i);
                    ret.push_back(m);
                    return ret;
                }
            }
        }
        return ret;
    }
};
```



### 49 字母异位词分组

给你一个字符串数组，请你将 **字母异位词** 组合在一起。可以按任意顺序返回结果列表。

**字母异位词：** 由重新排列源单词的所有字母得到的一个新单词。

**算法核心：将所有字母排序后，其字符串应该是相同的**

```c++
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ret;
        for(auto i= 0;i < strs.size();++i)
        {
            string temp = strs[i];
            vector<string> temp6;
            temp6.push_back(temp);
            for(auto m = i+1 ;m < strs.size();++m) //拿到strs数组
            {
                string temp2 = strs[m];
                string temp5;
                for(auto l = 0;l<temp.length();++l) 
                {
                    if(temp.length() !=temp2.length())
                    {
                        break;
                    }
                    char temp3 = temp[l];
                    for(auto n = 0;n<temp.length();++n)
                    {
                        char temp4 = temp2[n];
                        if(temp3!=temp4)
                        {
                            continue;
                        }
                        temp5.push_back(temp4);
                    }          
                }
                if(temp5.length()==temp.length())
                {
                    //检查一下是不是已经插入过了
                    temp6.push_back(temp2);
                }
            } 
            ret.push_back(temp6);
        } 
        return ret;
    }
};


class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ret;
        for(auto it= strs.begin();it != strs.end();)
        {
            string temp = *it;
            vector<string> temp6;
            temp6.push_back(temp);
            for(auto m = it ;m !=strs.end(); ) //拿到strs数组
            {
                string temp2 = strs[m];
                string temp5;
                if(temp == temp2)
                {
                    continue;
                }
                for(auto l = 0;l<temp.length();++l) 
                {
                    if(temp.length() !=temp2.length())
                    {
                        break;
                    }
                    char temp3 = temp[l];
                    for(auto n = 0;n<temp.length();++n)
                    {
                        char temp4 = temp2[n];
                        if(temp3!=temp4)
                        {
                            continue;
                        }
                        temp5.push_back(temp4);
                    }    
                }
                if(temp5.length()==temp.length())
                {
                    temp6.push_back(temp2);
                    m = strs.erase(m);
                }else
                {
                    ++m;
                }
            } 
            ret.push_back(temp6);
        } 
        return ret;
    }
};


class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ret;
        vector<string> temp9;
        vector<string> temp7;
        for(auto i= 0;i < strs.size();++i)
        {
            string temp = strs[i];
            vector<string> temp6;
            vector<string> temp10;
            bool y =false;
            for(string temp8: temp9)
            {
                if(temp8 == temp)
                {
                    if(temp.empty())
                    {
                        y = true;
                        break;
                    }
                    else
                    {
                        y = true;
                        break;
                    }
                }
            }
            if(y)
            {
                continue;
            }
            //std::cout<<"test"<<std::endl;
            temp6.push_back(temp);
            for(auto m = i+1 ;m < strs.size();++m) //拿到strs数组
            {
                string temp2 = strs[m];
                string temp5;
                int num = 0;
                int num2 = temp2.length();
                vector<int> x;
                for(auto l = 0;l<temp.length();++l) 
                {
                    if(temp.length() !=temp2.length())
                    {
                        break;
                    }
                    char temp3 = temp[l];
                    for(auto n = 0;n<temp.length();++n)
                    {
                        char temp4 = temp2[n];
                        if(temp3==temp4)
                        {
                            bool u =true;
                            for(int g:x)
                            {
                                if(n == g)
                                {
                                    u =false;
                                }
                            }
                            if(u)
                            {
                                num++;
                                x.push_back(n);
                                break;
                            }
                            
                        }
                        
                        //temp5.push_back(temp4);
                        
                    }          
                }
                bool dd =true;
                for(string temp8: temp7)
                {
                    if(temp8 == temp2&&temp2.length()>=2&&temp!=temp2)
                    {
                        dd =false;
                        break;
                    }
                }
                if(dd)
                {
                    std::cout<<num<<std::endl;
                    if(num==temp.length() && temp.empty()==0)
                    {
                    //检查一下是不是已经插入过了
                    std::cout<<temp2<<std::endl;
                    temp6.push_back(temp2);
                    temp7.push_back(temp2);
                    temp9.push_back(temp2);
                    }
                    if(temp.empty()&&temp2.empty())
                    {
                        temp6.push_back(temp2);
                        temp9.push_back(temp2);
                    }
                }
            }
            for(auto rit = temp6.rbegin();rit!= temp6.rend();++rit)
            {
                temp10.push_back(*rit);
            }
            ret.push_back(temp10);
        } 
        return ret;
    }
};



class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ret;
        vector<string> temp9;
        vector<string> temp7;
        for(auto i= 0;i < strs.size();++i)
        {
            string temp = strs[i];
            vector<string> temp6;
            vector<string> temp10;
            bool y =false;
            for(string temp8: temp9)
            {
                if(temp8 == temp)
                {
                    if(temp.empty())
                    {
                        y = true;
                        break;
                    }
                    else
                    {
                        y = true;
                        break;
                    }
                }
            }
            if(y)
            {
                continue;
            }
            //std::cout<<"test"<<std::endl;
            temp6.push_back(temp);
            for(auto m = i+1 ;m < strs.size();++m) //拿到strs数组
            {
                string temp2 = strs[m];
                string temp5;
                int num = 0;
                int num2 = temp2.length();
                vector<int> x;
                for(auto l = 0;l<temp.length();++l) 
                {
                    if(temp.length() !=temp2.length())
                    {
                        break;
                    }
                    char temp3 = temp[l];
                    for(auto n = 0;n<temp.length();++n)
                    {
                        char temp4 = temp2[n];
                        if(temp3==temp4)
                        {
                            bool u =true;
                            for(int g:x)
                            {
                                if(n == g)
                                {
                                    u =false;
                                }
                            }
                            if(u)
                            {
                                num++;
                                x.push_back(n);
                                break;
                            }
                            
                        }
                        
                        //temp5.push_back(temp4);
                        
                    }          
                }
                bool dd =true;
                if(dd)
                {
                    std::cout<<num<<std::endl;
                    if(num==temp.length() && temp.empty()==0)
                    {
                    //检查一下是不是已经插入过了
                    //std::cout<<temp2<<std::endl;
                    temp6.push_back(temp2);
                    temp7.push_back(temp2);
                    temp9.push_back(temp2);
                    }
                    if(temp.empty()&&temp2.empty())
                    {
                        temp6.push_back(temp2);
                        temp9.push_back(temp2);
                    }
                }
            }
            for(auto rit = temp6.rbegin();rit!= temp6.rend();++rit)
            {
                temp10.push_back(*rit);
            }
            ret.push_back(temp10);
        } 
        return ret;
    }
};
```

### 128 最长连续序列

给定一个未排序的整数数组 `nums` ，找出数字连续的最长序列（不要求序列元素在原数组中连续）的长度。

请你设计并实现时间复杂度为 `O(n)` 的算法解决此问题。

```c++
class Solution {
public:
    vector<int> sort(vector<int>& nums)
    {
        int n = nums.size();
        int temp;
        for(auto i = 0;i< n - 1 ;++i)
        {
            for(auto m = 0; m< n - 1 -i;++m)
            {
                if(nums[m] > nums[m+1])
                {
                    temp = nums[m];
                    nums[m] = nums[m + 1];
                    nums[m + 1] = temp;
                }
            }
        }
        return nums;
    }
int longestConsecutive(vector<int>& nums) {

        vector<int> nums2 = sort(nums);
        for(int i:nums2)
        {
            std::cout<<i<<std::endl;
        }
        int nums3 = 1;
        if(nums2.empty())
        {
            return 0;
        }
        int temp = 0;
        for(auto i = 0;i + 1< nums2.size();++i)
        {
            if(nums2[i] + 1 == nums2[i+1])
            {
                nums3++;
            }else if(nums2[i] == nums2[i+1])
            {
                continue;
            }else
            {
            if(nums3>temp)
            {
                temp = nums3;
            }
                nums3 = 1;
            }
        }
        if(nums3>temp)
        {
            temp = nums3;
        }
        return temp;
    }
};
```

题解：

```
class Solution {
public:
int longestConsecutive(vector<int>& nums) {
    std::unordered_set<int> num_set(nums.begin(), nums.end());
        int longest_streak = 0;
        
        for (int num : num_set) {
            // 检查是否是序列的起点
            if (num_set.find(num - 1) == num_set.end()) {
                int current_num = num;
                int current_streak = 1;
                
                // 向后扩展序列
                while (num_set.find(current_num + 1) != num_set.end()) {
                    current_num += 1;
                    current_streak += 1;
                }
                
                longest_streak = std::max(longest_streak, current_streak);
            }
        }
        
        return longest_streak;
        
    }
};
```



### 283 移动零

给定一个数组 `nums`，编写一个函数将所有 `0` 移动到数组的末尾，同时保持非零元素的相对顺序。

**请注意** ，必须在不复制数组的情况下原地对数组进行操作。

第一个版本 比较简单：

```c++
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int nums2 = 0;
        for(auto it = nums.begin();it!= nums.end();)
        {
            if(*it == 0)
            {
                nums.erase(it);
                ++nums2;
            }
            else
            {
                ++it;
            }
        }
        std::cout<<nums2<<std::endl;
        for(auto i = 0;i<nums2;++i)
        {
            nums.push_back(0);
        }
    }
};
```



```c++
void Solution::moveZeroes(vector<int>& nums)
{
    auto it = std::remove(nums.begin(), nums.end(), 0); //返回的是之前未定义的值
    for (auto it2 = it; it2 != nums.end();++it2)
    {
        *it2 = 0;
    }
    for (int num : nums) {
        std::cout << num << " ";
    }
}
```



### 11 盛最多水的容器

给定一个长度为 `n` 的整数数组 `height` 。有 `n` 条垂线，第 `i` 条线的两个端点是 `(i, 0)` 和 `(i, height[i])` 。

找出其中的两条线，使得它们与 `x` 轴共同构成的容器可以容纳最多的水。

返回容器可以储存的最大水量。

**说明：**你不能倾斜容器。

**×超出时间限制了**

```C++
class Solution {
public:
    int maxArea(vector<int>& height) {
        int temp = 0;
        for(int i = 0;i<height.size();++i)
        {
            for(int m = i + 1;m<height.size();++m)
            {
                int num = 0;
                if(height[i] < height[m])
                {
                    num = height[i] *(m - i);
                }else
                {
                    num = height[m] *(m - i);
                }
                    
                if(num > temp)
                {
                    temp = num;
                }    
            }
        }
        return temp;
    }
};
```



题解：

**双指针法的正确性**

- 初始化两个指针 `left` 和 `right`，分别指向数组的开头和结尾。
- 计算当前容器的容量：`(right - left) * min(height[left], height[right])`。
- 移动较短的那条线段的指针（因为移动较长的线段不会增加容量，而移动较短的线段可能会遇到更高的线段，从而可能增加容量）。
- 重复上述步骤，直到 `left` 和 `right` 相遇。
- 在整个过程中记录最大的容量。

为什么双指针法是正确的？关键在于我们每次移动较短的那条线段的指针。因为容器的容量由较短的线段和宽度决定，移动较长的线段的指针不会增加容量（因为高度不会超过当前的较短线段，而宽度在减少）。而移动较短的线段的指针，可能会遇到更高的线段，从而可能增加容量。

```C++
class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0;
        int right =height.size() - 1;
        int temp = 0;
        int num = 0;
        while(left < right)
        {
            int x = height[left];
            int y = height[right];
            if(x < y)
            {
                num = x * (right - left);
                left++;
            }else
            {
                num = y * (right - left);
                right--;
            }
            if(num>temp)
            {
                temp = num;
            }
        }
        return temp;
    }
};
```





### 15 三数之和

给你一个整数数组 `nums` ，判断是否存在三元组 `[nums[i], nums[j], nums[k]]` 满足 `i != j`、`i != k` 且 `j != k` ，同时还满足 `nums[i] + nums[j] + nums[k] == 0` 。请你返回所有和为 `0` 且不重复的三元组。



备注：

`for(int x :M(vector))` x是备份 并不是直接操作M

erase（nums.begin()+i)会删除元素之后自动调整数组大小

我的代码超出时间限制了 呜呜呜

```C++
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ret;
        vector<int> san;
        for(auto i = 0;i<nums.size();++i)
        {
            for(auto j = i+1;j<nums.size();++j)
            {
                for(auto k = j+1;k<nums.size();++k)
                {
                    if(nums[i]+nums[j]+nums[k] == 0)
                    {
                        if(san.size()>=3)
                        {
                            san.clear();
                        }
                        san.push_back(nums[i]);
                        san.push_back(nums[j]);
                        san.push_back(nums[k]);
                        ret.push_back(san);
                    }
                }
            }
        }
        for(auto i =0;i<ret.size();++i)
        {
            sort(ret[i].begin(), ret[i].end());
        }
        for(auto i = 0;i + 1<ret.size();)
        {
            bool duplicate = false;
            for(int j = i+1; j < ret.size(); ++j) {
                if(ret[i] == ret[j]) {
                    duplicate = true;
                    break;
                }
            }
            
            if(duplicate) {
                ret.erase(ret.begin() + i);
            } else {
                ++i;
            }
        }
        return ret;
    }
};
```



官方求解 **最佳实践是使用排序+双指针法，从一开始就避免生成重复的三元组：**

```c++
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        
        for (int i = 0; i < nums.size() && nums[i] <= 0; ++i) {
            if (i > 0 && nums[i] == nums[i-1]) continue;
            
            int left = i+1, right = nu.size()-1;
            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];
                if (sum < 0) {
                    ++left;
                } else if (sum > 0) {
                    --right;
                } else {
                    res.push_back({nums[i], nums[left], nums[right]});
                    while (left < right && nums[left] == nums[left+1]) ++left;
                    while (left < right && nums[right] == nums[right-1]) --right;
                    ++left;
                    --right;
                }
            }
        }
        return res;
    }
};
```



### 42 接雨水 （困难）

 双指针法

```c++
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int left = 0, right = height.size() - 1;
        int left_max = 0, right_max = 0;
        int total_water = 0;

        while (left < right) {
            if (height[left] < height[right]) {
                if (height[left] >= left_max) {
                    left_max = height[left];
                } else {
                    total_water += left_max - height[left];
                }
                ++left;
            } else {
                if (height[right] >= right_max) {
                    right_max = height[right];
                } else {
                    total_water += right_max - height[right];
                }
                --right;
            }
        }

        return total_water;
    }
};


int main() {
    Solution sol;
    vector<int> height = {0,1,0,2,1,0,1,3,2,1,2,1};
    int result = sol.trap(height);
    cout << "可以接的雨水总量为: " << result << endl;
    return 0;
}

```



前缀最大值 & 后缀最大值

```c++
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if (n == 0) return 0;

        vector<int> max_left(n), max_right(n);
        int total_water = 0;

        // 计算前缀最大值
        max_left[0] = height[0];
        for (int i = 1; i < n; ++i) {
            max_left[i] = max(max_left[i - 1], height[i]);
        }

        // 计算后缀最大值
        max_right[n - 1] = height[n - 1];
        for (int i = n - 2; i >= 0; --i) {
            max_right[i] = max(max_right[i + 1], height[i]);
        }

        // 计算总的接水量
        for (int i = 0; i < n; ++i) {
            int water_height = min(max_left[i], max_right[i]);
            if (water_height > height[i]) {
                total_water += water_height - height[i];
            }
        }

        return total_water;
    }
};

```





### 3 无重复字符的最长子串

给定一个字符串 `s` ，请你找出其中不含有重复字符的 **最长 子串** 的长度。

 

**示例 1:**

```
输入: s = "abcabcbb"
输出: 3 
解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。
```

**示例 2:**

```
输入: s = "bbbbb"
输出: 1
解释: 因为无重复字符的最长子串是 "b"，所以其长度为 1。
```

**示例 3:**

```
输入: s = "pwwkew"
输出: 3
解释: 因为无重复字符的最长子串是 "wke"，所以其长度为 3。
     请注意，你的答案必须是 子串 的长度，"pwke" 是一个子序列，不是子串。
```



```c++
class Solution {
    //滑动窗口
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> hash;
        auto i = 0;
        auto start = 0,maxLen = 0;
        for(i=0;i<s.size();++i)
        {
            char str = s[i];
            if(hash.count(str)&&hash[str]>=start)//这个字符上一次出现的位置是不是还在当前窗口范围内
            {
                start = hash[str]+1;
            }
            hash[str] = i;
            maxLen = max(maxLen,i-start+1);
        }
        
        return maxLen;
    }
};
```



### 146. LRU 缓存

请你设计并实现一个满足 [LRU (最近最少使用) 缓存](https://baike.baidu.com/item/LRU) 约束的数据结构。

实现 `LRUCache` 类：

- `LRUCache(int capacity)` 以 **正整数** 作为容量 `capacity` 初始化 LRU 缓存
- `int get(int key)` 如果关键字 `key` 存在于缓存中，则返回关键字的值，否则返回 `-1` 。
- `void put(int key, int value)` 如果关键字 `key` 已经存在，则变更其数据值 `value` ；如果不存在，则向缓存中插入该组 `key-value` 。如果插入操作导致关键字数量超过 `capacity` ，则应该 **逐出** 最久未使用的关键字。

函数 `get` 和 `put` 必须以 `O(1)` 的平均时间复杂度运行。

 

**示例：**

```c++
输入
["LRUCache", "put", "put", "get", "put", "get", "put", "get", "get", "get"]
[[2], [1, 1], [2, 2], [1], [3, 3], [2], [4, 4], [1], [3], [4]]
输出
[null, null, null, 1, null, -1, null, -1, 3, 4]

解释
LRUCache lRUCache = new LRUCache(2);
lRUCache.put(1, 1); // 缓存是 {1=1}
lRUCache.put(2, 2); // 缓存是 {1=1, 2=2}
lRUCache.get(1);    // 返回 1
lRUCache.put(3, 3); // 该操作会使得关键字 2 作废，缓存是 {1=1, 3=3}
lRUCache.get(2);    // 返回 -1 (未找到)
lRUCache.put(4, 4); // 该操作会使得关键字 1 作废，缓存是 {4=4, 3=3}
lRUCache.get(1);    // 返回 -1 (未找到)
lRUCache.get(3);    // 返回 3
lRUCache.get(4);    // 返回 4
```



```c++
class LRUCache {
private:
    int capacity;
    list<pair<int, int>> cache; // 双向链表：{key, value}
    unordered_map<int, list<pair<int, int>>::iterator> map; // key -> 节点迭代器

public:
    LRUCache(int capacity) : capacity(capacity) {}

    int get(int key) {
        if (map.find(key) == map.end())
            return -1;
        //if(!map.count(key)) return -1;
        // 将该 key 移动到链表头部（最近使用）
        auto it = map[key];
        cache.splice(cache.begin(), cache, it); // O(1)
        return it->second;
    }

    void put(int key, int value) {
        if (map.find(key) != map.end()) {
            // key 已存在，更新值并移到头部
            auto it = map[key];
            it->second = value;
            cache.splice(cache.begin(), cache, it);
        } else {
            // key 不存在，检查是否超出容量
            if (cache.size() == capacity) {
                // 删除链表尾部元素（最久未使用）
                int oldKey = cache.back().first;
                map.erase(oldKey);
                cache.pop_back();
            }
            // 插入新元素到头部
            cache.emplace_front(key, value);
            map[key] = cache.begin();
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
```



### 206 反转链表

给你单链表的头节点 `head` ，请你反转链表，并返回反转后的链表。

 ```c++
 /**
  * Definition for singly-linked list.
  * struct ListNode {
  *     int val;
  *     ListNode *next;
  *     ListNode() : val(0), next(nullptr) {}
  *     ListNode(int x) : val(x), next(nullptr) {}
  *     ListNode(int x, ListNode *next) : val(x), next(next) {}
  * };
  */
 class Solution {
 public:
     ListNode* reverseList(ListNode* head) {
         ListNode* prev = nullptr;
         ListNode* curr = head;
         while(curr!=nullptr)
         {
             ListNode* Next = curr->next;
             curr->next = prev;
             prev = curr;
             curr = Next;
         }
         return prev;
     }
 };
 ```



### 25 K 个一组翻转链表

```c++
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    // 反转从start到end（不含end）的链表
    ListNode* reverse(ListNode* start, ListNode* end) {
        ListNode* prev = nullptr;
        ListNode* curr = start;
        while (curr != end) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        if (head == nullptr || k <= 1) return head;
        
        ListNode dummy(0);
        dummy.next = head;
        ListNode* groupPrev = &dummy;

        while (true) {
            ListNode* kth = groupPrev;
            // 查找第k个节点
            for (int i = 0; i < k && kth != nullptr; ++i) {
                kth = kth->next;
            }
            if (kth == nullptr) break;

            ListNode* groupNext = kth->next;
            ListNode* prev = groupPrev->next;
            ListNode* curr = prev->next;

            // 反转这一组
            while (curr != groupNext) {
                prev->next = curr->next;
                curr->next = groupPrev->next;
                groupPrev->next = curr;
                curr = prev->next;
            }

            groupPrev = prev;
        }

        return dummy.next;
    }
};

```



### 121 买卖股票的最佳时机

给定一个数组 `prices` ，它的第 `i` 个元素 `prices[i]` 表示一支给定股票第 `i` 天的价格。

你只能选择 **某一天** 买入这只股票，并选择在 **未来的某一个不同的日子** 卖出该股票。设计一个算法来计算你所能获取的最大利润。

返回你可以从这笔交易中获取的最大利润。如果你不能获取任何利润，返回 `0` 。

 

**示例 1：**

```
输入：[7,1,5,3,6,4]
输出：5
解释：在第 2 天（股票价格 = 1）的时候买入，在第 5 天（股票价格 = 6）的时候卖出，最大利润 = 6-1 = 5 。
     注意利润不能是 7-1 = 6, 因为卖出价格需要大于买入价格；同时，你不能在买入前卖出股票。
```

**示例 2：**

```
输入：prices = [7,6,4,3,1]
输出：0
解释：在这种情况下, 没有交易完成, 所以最大利润为 0。
```

暴力法

```c++
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() == 0) return 0;
        int max = 0;
        for(auto i = 0;i<prices.size();++i)
        {
            int curr = prices[i];
            int temp = 0;
            for(auto m = i;m<prices.size();++m)
            {
                
                if(curr < prices[m])
                {
                    int max_temp = prices[m]-curr;
                    if(max_temp>temp)
                    {
                        temp  = max_temp;
                    }
                }
            }
            if(temp>max)
            {
                max = temp;
            }
        }
        return max;
    }
};
```



线性时间

```c++
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.empty()) return 0;
        int minPrice = prices[0];
        int maxProfit = 0;
        for (int i = 1; i < prices.size(); ++i) 
        {
            if (prices[i] < minPrice)
                minPrice = prices[i];
            else
                maxProfit = max(maxProfit, prices[i] - minPrice);
        }
        return maxProfit;
    }
};
```



### 200 岛屿数量

给你一个由 `'1'`（陆地）和 `'0'`（水）组成的的二维网格，请你计算网格中岛屿的数量。

岛屿总是被水包围，并且每座岛屿只能由水平方向和/或竖直方向上相邻的陆地连接形成。

此外，你可以假设该网格的四条边均被水包围。

 

**示例 1：**

```
输入：grid = [
  ["1","1","1","1","0"],
  ["1","1","0","1","0"],
  ["1","1","0","0","0"],
  ["0","0","0","0","0"]
]
输出：1
```

**示例 2：**

```
输入：grid = [
  ["1","1","0","0","0"],
  ["1","1","0","0","0"],
  ["0","0","1","0","0"],
  ["0","0","0","1","1"]
]
输出：3
```



一个经典的图遍历问题，题目叫做「岛屿数量」（LeetCode 第 200 题：Number of Islands），我们可以使用 **DFS**（深度优先搜索）或 **BFS**（广度优先搜索）来解决。

```c++
class Solution {
public:
    void dfs(vector<vector<char>>& grid, int i, int j) {
        int m = grid.size(), n = grid[0].size();
        // 越界或遇到水就返回
        if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] == '0') return;

        // 标记当前陆地为访问过
        grid[i][j] = '0';

        // 递归访问四个方向
        dfs(grid, i + 1, j);
        dfs(grid, i - 1, j);
        dfs(grid, i, j + 1);
        dfs(grid, i, j - 1);
    }

    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty()) return 0;
        int count = 0;
        int m = grid.size(), n = grid[0].size();

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == '1') {
                    dfs(grid, i, j); // 从当前陆地出发沉岛
                    ++count;         // 岛屿数 +1
                }
            }
        }
        return count;
    }
};

```



### 215. 数组中的第K个最大元素

给定整数数组 `nums` 和整数 `k`，请返回数组中第 `**k**` 个最大的元素。

请注意，你需要找的是数组排序后的第 `k` 个最大的元素，而不是第 `k` 个不同的元素。

你必须设计并实现时间复杂度为 `O(n)` 的算法解决此问题。



```c++
class Solution {
public:
    int quickSelect(vector<int>& nums, int left, int right, int k_smallest) {
        if (left == right) return nums[left];

        int pivot_index = left + rand() % (right - left + 1);
        pivot_index = partition(nums, left, right, pivot_index);

        if (k_smallest == pivot_index)
            return nums[k_smallest];
        else if (k_smallest < pivot_index)
            return quickSelect(nums, left, pivot_index - 1, k_smallest);
        else
            return quickSelect(nums, pivot_index + 1, right, k_smallest);
    }

    int partition(vector<int>& nums, int left, int right, int pivot_index) {
        int pivot = nums[pivot_index];
        swap(nums[pivot_index], nums[right]); // 将 pivot 放到最后
        int store_index = left;

        for (int i = left; i < right; i++) {
            if (nums[i] < pivot) {
                swap(nums[store_index], nums[i]);
                store_index++;
            }
        }
        swap(nums[right], nums[store_index]); // 把 pivot 放到正确位置
        return store_index;
    }

    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        // 第 k 大 = 第 (n - k) 小
        return quickSelect(nums, 0, n - 1, n - k);
    }
};
```



### 300. 最长递增子序列



给你一个整数数组 `nums` ，找到其中最长严格递增子序列的长度。

**子序列** 是由数组派生而来的序列，删除（或不删除）数组中的元素而不改变其余元素的顺序。例如，`[3,6,2,7]` 是数组 `[0,3,1,6,2,2,7]` 的子序列。

 

```c++
//动态规划
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        vector<int> dp(n, 1); // 每个位置都初始化为1
        int maxLen = 1;

        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[i] > nums[j]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            maxLen = max(maxLen, dp[i]);
        }

        return maxLen;
    }
};


//贪心算法 二分查找
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> tails;
        for (int num : nums) {
            auto it = lower_bound(tails.begin(), tails.end(), num);
            if (it == tails.end()) {
                tails.push_back(num);
            } else {
                *it = num;
            }
        }
        return tails.size();
    }
};

```



### 46. 全排列

给定一个不含重复数字的数组 `nums` ，返回其 *所有可能的全排列* 。你可以 **按任意顺序** 返回答案。

```c++
// 回溯
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> path;
        vector<bool> used(nums.size(), false);
        backtrack(nums, used, path, res);
        return res;
    }

    void backtrack(const vector<int>& nums, vector<bool>& used, 
                   vector<int>& path, vector<vector<int>>& res) {
        if (path.size() == nums.size()) {
            res.push_back(path);
            return;
        }

        for (int i = 0; i < nums.size(); ++i) {
            if (used[i]) continue;
            used[i] = true;
            path.push_back(nums[i]);
            backtrack(nums, used, path, res);
            path.pop_back();      // 回溯
            used[i] = false;
        }
    }
};

```



### 165. 比较版本号

给你两个 **版本号字符串** `version1` 和 `version2` ，请你比较它们。版本号由被点 `'.'` 分开的修订号组成。**修订号的值** 是它 **转换为整数** 并忽略前导零。

比较版本号时，请按 **从左到右的顺序** 依次比较它们的修订号。如果其中一个版本字符串的修订号较少，则将缺失的修订号视为 `0`。

返回规则如下：

- 如果 `*version1* < *version2*` 返回 `-1`，
- 如果 `*version1* > *version2*` 返回 `1`，
- 除此之外返回 `0`。

 

**示例 1：**

**输入：**version1 = "1.2", version2 = "1.10"

**输出：**-1

**解释：**

version1 的第二个修订号为 "2"，version2 的第二个修订号为 "10"：2 < 10，所以 version1 < version2。

**示例 2：**

**输入：**version1 = "1.01", version2 = "1.001"

**输出：**0

**解释：**

忽略前导零，"01" 和 "001" 都代表相同的整数 "1"。

**示例 3：**

**输入：**version1 = "1.0", version2 = "1.0.0.0"

**输出：**0

**解释：**

version1 有更少的修订号，每个缺失的修订号按 "0" 处理。

```c++
class Solution {
public:
    int compareVersion(string version1, string version2) {
        vector<int> v1 = split(version1);
        vector<int> v2 = split(version2);
        int n = max(v1.size(), v2.size());
        for (int i = 0; i < n; ++i) {
            int num1 = i < v1.size() ? v1[i] : 0;
            int num2 = i < v2.size() ? v2[i] : 0;
            if (num1 < num2) return -1;
            if (num1 > num2) return 1;
        }
        return 0;
    }

private:
    vector<int> split(string& version) {
        vector<int> res;
        int i = 0, n = version.size();
        while (i < n) {
            int num = 0;
            while (i < n && version[i] != '.') {
                num = num * 10 + (version[i] - '0');
                i++;
            }
            res.push_back(num);
            i++; // skip '.'
        }
        return res;
    }
};

```





### 160. 相交链表

给你两个单链表的头节点 `headA` 和 `headB` ，请你找出并返回两个单链表相交的起始节点。如果两个链表不存在相交节点，返回 `null` 。

图示两个链表在节点 `c1` 开始相交**：**

```C++
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        //双指针法（推荐做法）
          if (!headA || !headB) return nullptr;

        ListNode* pA = headA;
        ListNode* pB = headB;

        while (pA != pB) {
            pA = pA ? pA->next : headB;
            pB = pB ? pB->next : headA;
        }

        return pA;  // 如果相交，返回相交节点；否则为 nullptr
    }
};
```



## temp



