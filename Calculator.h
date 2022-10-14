#ifndef CALCULATORH
#define CALCULATORH

#include<iostream>
#include<stdlib.h>
#include<cmath>
using namespace std;

class Calculator{
public :
	double evaluate (string problem);					
	double operate (double num1, double num2, char op);	
	double trig (double num1, int n);	
	int precedence (char op);			
};

#endif
