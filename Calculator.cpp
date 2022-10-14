#include"Calculator.h"
#include"Queue.h"
#include<iostream>
#include<stdlib.h>
#include<cmath>
using namespace std;

//Creating arithmetic precedence
int Calculator::precedence(char op){
	if (op == '+' || op == '-'){
		return 1;
	}
	if (op == '*' || op == '/'){
		return 2;
	}
	if (op == '^'){
		return 3;
	}
	else {
		return 0;
	}
}

//Calculate two number according to operator
double Calculator::operate(double num1, double num2, char op){
	switch(op){
		case '+' : return num2 + num1;
		case '-' : return num2 - num1;
		case '*' : return num2 * num1;
		case '/' : return num2 / num1;
		case '^' : return pow(num2, num1);
	}
}

//Calculate the trigonometry
double Calculator::trig(double num1, int n){
	switch(n){
		case 1: return sin(num1);
		case 2: return cos(num1);
		case 3: return tan(num1);
		case 4: return asin(num1);
		case 5: return acos(num1);
		case 6: return atan(num1);
		case 7: return log10(num1);
		case 8: return log(num1);
	}
}
