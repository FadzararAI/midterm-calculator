#include"../Calculator.h"
#include"../Queue.h"
#include<iostream>
#include<stdlib.h>
#include<cmath>
using namespace std;
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