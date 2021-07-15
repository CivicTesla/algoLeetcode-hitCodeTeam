#include <iostream>//cout
#include <algorithm>//sort()
#include <vector>//vector<int>数组
#include <numeric>//accumulate()求和
using namespace std;

//! 糖果分配问题：规则，每个小孩只与旁边相邻两个小孩比，谁分高则谁糖果多；求最少的糖果分配总数
//t O(2n)|O(1)，从左往右再从右往左遍历，一共两次
class solution {
public:
   
    vector<int> candy(vector<int>& ratings) {
        int size = ratings.size();
        if (size < 2) {
            vector<int> one;
            one.push_back(1);
            return one;
        }
        vector<int> num(size, 1);//构造一个数组，有size个1；即先给每个小孩一个糖果
        for (int i = 1; i < size; ++i) {//todo1 左遍历
            if (ratings[i] > ratings[i-1]) {//右边比左边大，则右边+1
                num[i] = num[i-1] + 1;
            }
        }
        for (int i = size - 1; i > 0; --i) {//todo2 右遍历
            if (ratings[i] < ratings[i-1]) {//右边比左边小，则左边取max(原本的值，右边的值+1)
                num[i-1] = max(num[i-1], num[i] + 1);
            } 
        }
        return num;//*返回vector<int> num变量
        // return accumulate(num.begin(), num.end(), 0); // std::accumulate 可以很方便 地求和 //? 0
        }
};
int main() {
    int grade[9] = { 1,0,2,5,1,6,4,8,9 };
    vector<int> child(grade, grade+9); //,first=ar,last=ar+3,不包括ar+2
    solution solve;

// * ----------------------显示分配数组
    vector<int> vec =  solve.candy(child);
    vector<int>::iterator ite = vec.begin();
	for (; ite != vec.end(); ite++){
		cout << *ite;
		cout << ",";
	}
    cout << endl;// * ----------------------显示分配数组结束

    cout << accumulate(vec.begin(), vec.end(), 0) << endl;//*统计总数
    // cout << solve.candy(child) << endl;
    // system("pause"); exe文件单独双击运行时可设置此代码令其暂停显示；终端运行无需设置
}