#include"../Calculator.h"
#include"../Queue.h"
#include<iostream>
#include<stdlib.h>
#include<cmath>
using namespace std;
double Calculator::operate(double num1, double num2, char op){
	switch(op){
		case '+' : return num2 + num1;
		case '-' : return num2 - num1;
		case '*' : return num2 * num1;
		case '/' : return num2 / num1;
		case '^' : return pow(num2, num1);
	}
}