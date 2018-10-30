#include <boost/numeric/ublas/vector.hpp>
#include <boost/numeric/ublas/matrix.hpp>
#include <boost/numeric/ublas/io.hpp>

#include <iostream>

using namespace boost::numeric::ublas;

// 举例：y = Ax 矩阵与向量相乘

int main()
{
    using std::cout;
    using std::endl;

    // 列向量，2行1列
    vector<double> x(2);
    x(0) = 1;
    x(1) = 2;
    cout << x << endl;

    matrix<double> A(2, 2);
    A(0, 0) = 0; A(0, 1) = 1;
    A(1, 0) = 2; A(1, 1) = 3;
    cout << A << endl;

    vector<double> y = prod(A, x);
    std::cout << y << std::endl;

    getchar();
    return 0;
}
