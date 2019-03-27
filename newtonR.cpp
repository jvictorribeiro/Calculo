#include<bits/stdc++.h> 
#define EPSILON 0.00001 
using namespace std; 
  
//Escrever funcao manualmente aqui embaixo
double func(double x) 
{ 
    return x*x*x*x*x - (10/9)*x*x*x + (5/21)*x; 
} 
  
//Escrever derivada da funcao manualmente
double derivFunc(double x) 
{ 
    return 5*x*x*x*x - 30/9*x*x + 5/21; 
} 
  
//Funcao para achar raiz metodo de newton raphson 
void newtonRaphson(double x) 
{ 
    double h = func(x) / derivFunc(x); 
    while (abs(h) >= EPSILON) 
    { 
        h = func(x)/derivFunc(x); 
   
        // x(i+1) = x(i) - f(x) / f'(x)   
        x = x - h; 
    } 
    //cout.precision(10);
    cout << "The value of the root is : " << x << endl; 
} 
  

int main() 
{ 
    double x0 = -0.8; // valor inicial assumido
    newtonRaphson(x0); 
    return 0; 
} 
