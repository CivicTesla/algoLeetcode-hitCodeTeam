#include <iostream>
#include <algorithm>
#include <vector>
#include "../../include/test/timeTest.h"
using namespace std;

class Solution {
public://* public关键字暴露类Solution内部的对象，才能被其他类如main(),TimeTEST()访问到
    //t O()|O()
    vector<int> func0(vector<int> vec,int target){
    }
    int func1(vector<int> vec,int target){
    }
};

// 测试
int main() {

    //*构造一维数组
    vector<int> vec{2,7,11,15};
    int target = 1 ;
    //* 构造二维数组
    int element0[2] = {1,2};
    vector<int> vec0(element0, element0+2);
    int element1[2] = {1,2};
    vector<int> vec1(element1, element1+2);
    int element2[2] = {1,2};
    vector<int> vec2(element2, element2+2);
    
    vector<int> ele[3] = {vec0,vec1,vec2};
    vector<vector<int>> interval(ele,ele+sizeof(ele)/sizeof(vector<int>));

    //* 类实例化
    Solution solve;
    
    // * ------显示整数结果
    cout << solve.func1(vec,target) << endl;

    // * ------显示整数结果结束
    // * ----------------------显示数组
    vector<int> vec =  solve.func0(vec,target);//调用func
    vector<int>::iterator ite = vec.begin();
	for (; ite != vec.end(); ite++){
		cout << *ite;
		cout << ",";
	}
    cout << endl;// * ----------------------显示数组结束
}