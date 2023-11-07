#include <iostream>
#include <ctime>

using namespace std;

template<typename T>
T sum(T n1, T n2)
{
    return n1 + n2;
}
template<typename T>
T sub(T n1, T n2)
{
    return n1 - n2;
}
template<typename T>
T mul(T n1, T n2)
{
    return n1 * n2;
}
template<typename T>
T div(T n1, T n2)
{
    return (n1 == 0 || n2 == 0) ? 0 : n1 / n2;
}


int main()
{
    double n1, n2;
    cout << "Enter first  number: ";
    cin >> n1 ;
    cout << "Enter second  number: ";
    cin >> n2;
    double (*action[4])(double, double) = { sum, sub, mul, div };
    cout << "Enter op (0(+),1(-),2(*),3(/)): ";
    
    int op;
    cin >> op;
    cout << action[op](n1, n2) << endl;


    return 0;
}