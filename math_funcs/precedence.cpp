#include"../Calculator.h"
#include"../Queue.h"
#include<iostream>
#include<stdlib.h>
#include<cmath>
using namespace std;
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