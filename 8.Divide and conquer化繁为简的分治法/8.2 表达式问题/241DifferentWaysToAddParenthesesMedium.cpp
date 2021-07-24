#include <iostream>
#include <algorithm>
#include <vector>
#include <sstream>//* istringstream
#include "../../include/test/timeTest.h"
#include "../../include/breaknine/print.h"
using namespace std;

// ? 没看明白

class Solution {
public:
    //t O()|O()
    //todo1 ------------------------------------------
    vector<int> diffWaysToCompute0(string input)
    {
        vector<int> ways;
        for (int i = 0; i < input.length(); i++)
        {
            char c = input[i];
            if (c == '+' || c == '-' || c == '*')
            {
                vector<int> left = diffWaysToCompute0(input.substr(0, i));
                vector<int> right = diffWaysToCompute0(input.substr(i + 1));
                for (const int &l : left)
                {
                    for (const int &r : right)
                    {
                        switch (c)
                        {
                        case '+':
                            ways.push_back(l + r);
                            break;
                        case '-':
                            ways.push_back(l - r);
                            break;
                        case '*':
                            ways.push_back(l * r);
                            break;
                        }
                    }
                }
            }
        }
        if (ways.empty())
            ways.push_back(stoi(input));//stoi,C++的字符处理函数，把数字字符串转换成int输出
        return ways;
    }
    //todo2 ----------------------------------------------
    vector<int> diffWaysToCompute1(string input)
    {
        vector<int> data;
        vector<char> ops;
        int num = 0;
        char op = ' ';
        istringstream ss(input + '+');//* istringstream 是將字串變成字串迭代器一樣，將字串流在依次拿出，比較好的是，它不會將空格作為流。這樣就實現了字串的空格切割。
        while (ss >> num && ss >> op)
        {
            data.push_back(num);
            ops.push_back(op);
        }
        int n = data.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>()));
        for (int i = 0; i < n; ++i)
        {
            for (int j = i; j >= 0; --j)
            {
                if (i == j)
                {
                    dp[j][i].push_back(data[i]);
                }
                else
                {
                    for (int k = j; k < i; k += 1)
                    {
                        for (auto left : dp[j][k])
                        {
                            for (auto right : dp[k + 1][i])
                            {
                                int val = 0;
                                switch (ops[k])
                                {
                                case '+':
                                    val = left + right;
                                    break;
                                case '-':
                                    val = left - right;
                                    break;
                                case '*':
                                    val = left * right;
                                    break;
                                }
                                dp[j][i].push_back(val);
                            }
                        }
                    }
                }
            }
        }
        return dp[0][n - 1];
    }
};

// 测试
TimeTEST(test_1)
{
    std::cout << "this is test_1" << std::endl;
    string input =  "2-1-1";
    // *类实例化
    Solution solve;
    print(solve.diffWaysToCompute1(input));
}