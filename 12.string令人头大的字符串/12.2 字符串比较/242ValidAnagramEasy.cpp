#include <iostream>
#include <algorithm>
#include <vector>
#include "../../include/breaknine/print.h"
using namespace std;
// ! 题目：判断两个字符串包含的字符是否完全相同（组成的字母相同，每个字母的个数相同）。
class Solution {
public:
    //t O()|O()
    bool isAnagram(string s, string t)
    {
        if (s.length() != t.length())
        {
            return false;
        }
        vector<int> counts(26, 0);//26个0
        print(counts);
        for (int i = 0; i < s.length(); ++i)
        {
            print("------");
            ++counts[s[i] -'a'];//字母相减，等于两者之间的字母个数
            print(s[i] -'a');
            print(counts[s[i] -'a']);
            print("------");
            --counts[t[i] -'a'];
            print(t[i] -'a');
            print(counts[t[i] -'a']);
            print("------");
        }
        for (int i = 0; i < 26; ++i)
        {
            if (counts[i])//非0则true，负数也true
            {
                return false;
            }
        }
        return true;
    }
};

// 测试
int main() {
    string s =  "anagram";string  t = "nagaram";

    // 类实例化
    Solution solve;
    
    // 显示结果
    if (solve.isAnagram(s,t))
        print("true");
    else
        print("false");
}