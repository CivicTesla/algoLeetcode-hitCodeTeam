//! 性能测试优化的目的
//* 但是，时代是会变化的，如今，单个核心的性能增长非常慢，而且，如今的程序还必须运行在移动平台上(已经成为大多数)，
//* 电池的电量和散热都制约了指令的执行效率，而优化，可以让程序永远保持活力
//* 而且说性能无所谓的，只限于某些程序，对于工作负载很大以至于需要分布式处理的程序，性能影响就会非常大，
//* 以至于小小的优化都能节约莫大的成本，例如从1000台云主机将到只需600台
//！优化方法 
//* 如何优化
//* 1.使用更好的编译器，然后打开它们的优化选项
//* 
//* 2.使用更好的算法，而不是英勇地去改进算法
//* 
//* 3.使用更好的库
//* 
//* 4.减少内存分配和复制，这是一个很有用的优化手段
//* 
//* 5.使用更好的数据结构
//* 
//* 6.提高并发行
//！ 仿gtest时间测试
//* 如何测试性能
//* 之前使用了gtest测试框架，觉得gtest的测试用例所使用的形式深的我心，于是仿照其形式写了一个测试运行时间的，如下
#include <iostream>
#include <queue>
#include <chrono>
using namespace std::chrono;

namespace _TimeTest
{
//A Base Timer
class TimerBase
{
public:
    TimerBase() : m_start(system_clock::time_point::min()) {}

    void Clear()
    {
        m_start = system_clock::time_point::min();
    }

    void Start()
    {
        m_start = system_clock::now();
    }

    bool IsStarted() const
    {
        return (m_start.time_since_epoch() != system_clock::duration(0));
    }

    unsigned long GetMs()
    {
        if (IsStarted())
        {
            system_clock::duration diff;
            diff = system_clock::now() - m_start;
            return (unsigned)(duration_cast<milliseconds>(diff).count());
        }
        return 0;
    }
private:
    system_clock::time_point m_start;
};

class TimeBaseTest
{
public:
    virtual void run()=0;
    virtual ~TimeBaseTest(){}
    static TimerBase timer;
};

TimerBase TimeBaseTest::timer;
std::queue<TimeBaseTest *> tests;
}

#define TEST_CLASS(test_case_name) \
class TEST_CLASS_##test_case_name : public _TimeTest::TimeBaseTest {\
public:\
    TEST_CLASS_##test_case_name()\
    {\
        _TimeTest::tests.push(this);\
    }\
    void run();\
};\

/* TEST_CLASS_INSTANCE
 * 1.delcare the test class TEST_CLASS_test_case_name
 * 2.get a instance of the class
 * 3.define the run() for the class
 * */

#define TEST_CLASS_INSTANCE(test_case_name) \
    TEST_CLASS(test_case_name);\
    auto test_case_name##_instance = new TEST_CLASS_##test_case_name;\
    void TEST_CLASS_##test_case_name::run()

#define TimeTEST(test_case_name) TEST_CLASS_INSTANCE(test_case_name)

#define RunAllTimeTest(); \
    while(!_TimeTest::tests.empty())\
    {\
        auto i = _TimeTest::tests.front();\
        _TimeTest::tests.pop();\
        std::cout << "\033[1;32:42m[    RUN    ]\033[0m" << std::endl;\
        i->timer.Start();\
        i->run();\
        std::cout << "\033[1;31:42m[    FINISH,USE TIME : "<< i->timer.GetMs() <<"ms]\033[0m\n" << std::endl;\
        i->timer.Clear();\
        delete i;\
    }\

int main()
{
    RunAllTimeTest();
    return 0;
}
