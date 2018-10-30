
#include <boost/thread/thread.hpp>
#include <iostream>

using namespace std;

void hello_world()
{
    cout << "Hello world, I'm a thread!" << endl;
}

int main(int argc, char* argv[])
{
// 启动一个线程
boost::thread my_thread(&hello_world);
// 等待
my_thread.join();

return 0;
}
