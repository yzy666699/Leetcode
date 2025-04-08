#pragma once
#include "solution.h"



vector<int> Solution::twoSum(vector<int>& nums, int target)
{
    int temp = 0;
    vector<int> ret;
    for (int i = 0;i < nums.size();++i)
    {
        temp = nums[i];
        for (int m = i + 1;m < nums.size();m++)
        {
            if (temp + nums[m] == target)
            {
                ret.push_back(i);
                ret.push_back(m);
                return ret;
            }
        }
    }
    return ret;
}

vector<vector<string>> Solution::groupAnagrams(vector<string>& strs)
{
    unordered_map<string, vector<string>> groups;

    for (const string& s : strs) {
        string key = s;
        sort(key.begin(), key.end());
        groups[key].push_back(s);
    }

    vector<vector<string>> result;
    for (auto& pair : groups) {
        result.push_back(move(pair.second));
    }

    return result;
}

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

int Solution::maxArea(vector<int>& height)
{
    int temp = 0;
    for (int i = 0;i < height.size();++i)
    {
        for (int m = i + 1;m < height.size();++m)
        {
            int num = 0;
            if (height[i] < height[m])
            {
                num = height[i] * (m - i);
            }
            else
            {
                num = height[m] * (m - i);
            }

            if (num > temp)
            {
                temp = num;
            }
        }
    }
    return temp;
}
