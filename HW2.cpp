#include <iostream>
#include <cmath>

using namespace std;

double sqrt1(double a, double b, double c)
{
    return (-b + sqrt(b * b - 4 * a * c)) / (2 * a);
} 
double sqrt2(double a, double b, double c)
{
    return (-b - sqrt(b * b - 4 * a * c)) / (2 * a);
}

void sq()
{
    int a, b, c;
    
    cout << "a = ";
    cin >> a;
    cout << "b = ";
    cin >> b;
    cout << " c = ";
    cin >> c;
    cout << "????????? + = " << sqrt1(a, b, c) << "????????? - = " << sqrt2( a, b, c ) << endl;
}

int main() 
{ 
    sq();
    return 0;
}



