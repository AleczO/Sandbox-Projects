#include <iostream>
#include <functional>
#include <cmath>
#include <iomanip>
#define h 1e-7

const double eps = 1e-8;

double d(std::function<double(double)> F, double x){
    return (F(x + h) - F(x - h)) / (2 * h);
}


double BisectionMethod(std::function<double(double)> F, double a, double b){
    double x = 0;
    double dx = b - a;

    int cnt = 0;

    while(abs(dx) > eps){
        x = (a + b) / 2.0;

        if( F(a) * F(x) < 0 ){
            b = x;
            dx = b - a;
        }
        else {
            a = x;
            dx = b - a;
        }
        cnt++;
    }

    return x;
}


double NewtonMethod(std::function<double(double)> F, double a, double b){
    double dx = b - a, x = (a + b) / 2;

    int k = 0;
    while(abs(dx) > eps){
        dx = F(x) / d(F, x);
        x -= dx;
        k++;
    }

    return x;
}

double SecantMethod(std::function<double(double)> F, int n, double a, double b){
    int k = 0;
    double x = (a + b) / 2.0, dx = (b - a) / 10.0;
    double x1 = x + dx;

    while(abs(dx) > eps && (k < n)){
        double d = F(x1) - F(x);
        double x2 = x1 - F(x1) * (x1 - x) / d;

        x = x1;
        x1 = x2;
        dx = x1 - x;
        k++;
    }

    if(k == n) std::cout << "Not convergent after " << n << " iterations";

    return x1;
}



double F(double x){
    return exp(x) * log(x) - x * x;
}




int main(){
    std::cout << std::setprecision(8) << BisectionMethod(F, 0.5, 3) << '\n';
    std::cout << std::setprecision(8) << NewtonMethod(F, 0.5, 3) << '\n';
    std::cout << std::setprecision(8) << SecantMethod(F, 8, 0.5, 3) << '\n';

    return 0;
}