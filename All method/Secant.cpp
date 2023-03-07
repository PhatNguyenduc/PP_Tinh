#include <iostream>
#include <cmath>

using namespace std;


double f(double x) {
    return x*x*x-x-1;
}


void secant(double x0, double x1, double eps,int iter) {
    double x2 = x1 - f(x1) * (x1 - x0) / (f(x1) - f(x0));
    int i=1;
    while (abs(x2 - x1) > eps && i<=iter) {
        x0 = x1;
        x1 = x2;
        x2 = x1 - f(x1) * (x1 - x0) / (f(x1) - f(x0));
        i++;
    }
    if(i>iter )cout<<"khong tim thay nghiem sau "<<iter<<" lan lap.";
    else cout<<"Nghiem gan dung: "<<x2<<" sau "<<i<<" lan lap.";
}

int main() {
    double x0 ,x1;
    cin>>x0>>x1; 
    double eps = 0.0001; 
    int iter =1000;
    secant(x0,x1,eps,iter);
    return 0;
}

