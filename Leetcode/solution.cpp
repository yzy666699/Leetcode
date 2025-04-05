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
