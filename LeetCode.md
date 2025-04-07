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

### 最长连续序列

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









































