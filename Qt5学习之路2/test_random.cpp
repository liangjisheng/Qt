#include <iostream>
#include <random>
#include <ctime>
#include <functional>

using namespace std;

int main()
{
    // 设置种子,每次生成的随机数都不一样 generator对象
    default_random_engine engine(time(nullptr));
    // 均匀分布[1, 255] distributions 对象
    uniform_int_distribution<> dis(1, 255);
    for (int i = 0; i < 10; i++)
        cout << dis(engine) << " ";
    cout << endl;

    // 使用bind绑定, 包含functionsal头文件
    auto dice = bind(dis, engine);
    for (int i = 0; i < 10; i++)
        cout << dice() << " ";
    cout << endl;

    random_device rd;   // 作为种子
    for (int i = 0; i < 10; i++)
        cout << rd() << " ";
    cout << endl;

    default_random_engine engine1(rd());
    uniform_int_distribution<> dis1(1, 255);
    for (int i = 0; i < 10; i++)
        cout << dis1(engine1) << " ";
    cout << endl;

    // mt为随机数引擎,用来生成随机数，rd()作为每次生成随机数的种子
    std::mt19937 mt(rd());
    for (int i = 0; i < 10; i++)
        cout << mt() << " ";
    cout << endl;

    return 0;
}
