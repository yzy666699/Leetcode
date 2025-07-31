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

```
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

 ```
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











