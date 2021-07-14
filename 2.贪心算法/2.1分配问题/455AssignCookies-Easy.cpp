#include <iostream>//cout
#include <algorithm>//sort()
#include <vector>//vector<int>数组
using namespace std;
//t O(n)|O(1),n个小孩或m个饼干，当其中一个被while完的时候，程序出结果，所以最大的时间复杂度O（n）
int findContentChildren(vector<int>& children, vector<int>& cookies) {
    sort(children.begin(), children.end());//数组由小到大排序
    sort(cookies.begin(), cookies.end());
    int child = 0, cookie = 0;
    while (child < children.size() && cookie < cookies.size()) {
        if (children[child] <= cookies[cookie]) ++child;//t 饼干如果小于孩子的胃口，就不会给他；满足，则下一个小孩，下一个饼干
        ++cookie;//t 当前饼干不满足，则验证下一个饼干
    }
    return child;
};
int main(){
    //* 0.0给数组赋值
    // vector<int> Child;
    // Child.push_back(1);
    // Child.push_back(2);
    // vector<int> Cookies;
    // Cookies.push_back(1);
    // Cookies.push_back(2);
    // Cookies.push_back(3);
    
    //* 0.1快速给数组赋值
    int ar1[2] = { 1,2 };
    vector<int> vec1(ar1, ar1+2); //,first=ar,last=ar+3,不包括ar+2
    int ar4[3] = {1,2,3};
    vector<int> vec4(ar4,ar4+3);

    //todo-------------
    cout << findContentChildren(vec1,vec4) << endl;
    system("pause"); 

}
