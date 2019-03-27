
// C++ program for implementation of Bisection Method for 
// solving equations 
#include<bits/stdc++.h> 
using namespace std; 
#define EPSILON 0.00001 
  
// An example function whose solution is determined using 
// Bisection Method. The function is x^3 - x^2  + 2 
double func(double x) 
{ 
    return x*x*x*x*x - ((10/9)*x*x*x) + ((5/21)*x); 
} 
  
// Prints root of func(x) with error of EPSILON 
void bisection(double a, double b) 
{ 
    if (func(a) * func(b) < 0)     //possuem sinais contrarios entao sua multi sempre e negativa
    { 
        cout << "You have not assumed right a and b\n"; 
        return; 
    } 
  
    double c = a; 
    while ((b-a) >= EPSILON) 
    { 
        // Find middle point 
        c = (a+b)/2; 
  
        // Check if middle point is root 
        if (func(c) == 0.0) 
            break; 
  
        // Decide the side to repeat the steps 
        else if (func(c)*func(a) < 0) 
            b = c; 
        else
            a = c; 

        cout.precision(6);
        cout << "THE value of root is : " << c << endl; 
    } 
    //cout.precision(10);
    cout << "The FINAL value of root is : " << c << endl; 
} 
  
// Driver program to test above function 
int main() 
{ 
    // Initial values assumed 
    double a = (-0.75), b = (-0.25); 
    bisection(a, b); 
    return 0; 
} 
