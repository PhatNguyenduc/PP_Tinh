#include <bits/stdc++.h>
using namespace std;

#define lb double

lb f(lb x, lb y)
{
    return 1 + x * x + y;
}

lb ff(lb x, lb y)
{
    return 2 * x + f(x, y);
}

lb Euler(lb x0, lb y0, lb h, lb x)
{
    int n = ((x - x0) / h);
    for (int i = 0; i < n; i++)
    {
        y0 = y0 + h * f(x0, y0) + h * h / 2 * ff(x0, y0);
        x0 += h;
    }
    return y0;
}

int main()
{
    lb x0, y0, h, x;

    // Enter initial values and step size
    cout << "Enter x0: ";
    cin >> x0;
    cout << "Enter y0: ";
    cin >> y0;
    cout << "Enter step size h: ";
    cin >> h;
    cout << "Enter the value of x to calculate: ";
    cin >> x;

    lb result = Euler(x0, y0, h, x);
    cout << "The value of y at x = " << x << " is: " << result << endl;
    system("pause");
}