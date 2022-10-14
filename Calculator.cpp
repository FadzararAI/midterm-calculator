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
//Evaluate the problem
double Calculator::evaluate(string problem){
	int i;				
	Queue values(100);	
	Queue ops(100);	
	
	//Loop to check entire problem
	for (i=0; i < problem.length(); i++){
		
		//ignore the blanks
		if (problem[i] == ' '){
			continue;
		}
		
		//push open bracket to the ops queue
		else if (problem[i] == '('){
			ops.charEnqueue(problem[i]);
		}
		
		//sin
		else if (problem[i] == 's') {
			int n=1;
			double result = 0;
			//track the number until bracket closed
			while (i<problem.length() && problem[i] != ')'){
				i++;
				double val = 0;
				if(isdigit(problem[i])){
					while (i<problem.length() && isdigit(problem[i])){
						val = (val*10) + (problem[i]-'0');
						i++;
						if (problem[i] == '.' || problem[i] == ','){
							i=i+1;
							int j=-1;
							while (i<problem.length() && isdigit(problem[i])){
								float point = ((problem[i]-'0') * pow(10,j--));
								val = (double) (val) + point;
								i++;
							}
						}
					}					
					i--;
					result = trig(val, n);
				}
			}
			values.numEnqueue(result);
		}
		//cos
		else if (problem[i] == 'c') {
			int n=2;						
			double result = 0;			
			
			while (i<problem.length() && problem[i] != ')'){
				i++;
				double val = 0;
				if(isdigit(problem[i])){
					while (i<problem.length() && isdigit(problem[i])){
						val = (val*10) + (problem[i]-'0');
						i++;
						if (problem[i] == '.' || problem[i] == ','){
							i=i+1;
							int j=-1; 
							while (i<problem.length() && isdigit(problem[i])){
								float point = ((problem[i]-'0') * pow(10,j--)); 
								val = (double) (val) + point;
								i++;
							}
						}
					}
					i--;
					result = trig(val, n); 
				}
			}
			values.numEnqueue(result);
		}

		//tan
		else if (problem[i] == 't') {
			int n=3;
			double result = 0;
			while (i<problem.length() && problem[i] != ')'){
				i++;
				double val = 0;
				if(isdigit(problem[i])){
					while (i<problem.length() && isdigit(problem[i])){
						val = (val*10) + (problem[i]-'0');
						i++;
						if (problem[i] == '.' || problem[i] == ','){
							i=i+1;
							int j=-1;
							while (i<problem.length() && isdigit(problem[i])){
								float point = ((problem[i]-'0') * pow(10,j--));
								val = (double) (val) + point;
								i++;
							}
						}
					}					
					i--;
					result = trig(val, n);
				}
			}
			values.numEnqueue(result);
		}
		
		//if arc
		else if (problem[i] == 'a') {
			int n;
			double result = 0;
			i++;
			//checking the acos, asin, or atan
			switch(problem[i]){
			    case 's': n=4; break;
				case 'c': n=5; break;
				case 't': n=6; break;
			}
			while (i<problem.length() && problem[i] != ')'){
				i++;
				double val = 0;
				if(isdigit(problem[i])){
					while (i<problem.length() && isdigit(problem[i])){
						val = (val*10) + (problem[i]-'0');
						i++;
						if (problem[i] == '.' || problem[i] == ','){
							i=i+1;
							int j=-1;
							while (i<problem.length() && isdigit(problem[i])){
								float point = ((problem[i]-'0') * pow(10,j--));
								val = (double) (val) + point;
								i++;
							}
						}
					}					
					i--;
					result = trig(val, n);
				}
			}
			values.numEnqueue(result);
		}
		//log or ln
		else if (problem[i] == 'l') {
			int n;
			double result = 0;
			i++;
			switch(problem[i]){
				case 'o': n=7; break;
				case 'n': n=8; break;
			}
			while (i<problem.length() && problem[i] != ')'){
				i++;
				double val = 0;
				if(isdigit(problem[i])){
					while (i<problem.length() && isdigit(problem[i])){
						val = (val*10) + (problem[i]-'0');
						i++;
						if (problem[i] == '.' || problem[i] == ','){
							i=i+1;
							int j=-1;
							while (i<problem.length() && isdigit(problem[i])){
								float point = ((problem[i]-'0') * pow(10,j--));
								val = (double) (val) + point;
								i++;
							}
						}
					}					
					i--;
					result = trig(val, n);
				}
			}
			values.numEnqueue(result);
		}

		//if input is number
		else if (isdigit(problem[i])){
			double val = 0;
			
			while (i<problem.length() && isdigit(problem[i])){
				val = (val*10) + (problem[i]-'0');
				i++;
				if (problem[i] == '.' || problem[i] == ','){
					i=i+1;
					int j=-1; 
					while (i<problem.length() && isdigit(problem[i])){
						float point = ((problem[i]-'0') * pow(10,j--));
						val = (double) (val) + point; 						
						i++;
					}
				}
			}
			
			values.numEnqueue(val); 
			i--; 					//adjust order
		}

		//if square root
		else if (problem[i] == 'r') {
			double result = 0;
			while (i<problem.length() && problem[i] != ')'){
				i++;
				double val = 0;
				if(isdigit(problem[i])){
					while (i<problem.length() && isdigit(problem[i])){
						val = (val*10) + (problem[i]-'0');
						i++;
						if (problem[i] == '.' || problem[i] == ','){
							i=i+1;
							int j=-1;
							while (i<problem.length() && isdigit(problem[i])){
								float point = ((problem[i]-'0') * pow(10,j--));
								val = (double) (val) + point;
								i++;
							}
						}
					}					
					i--;
					result = sqrt(val); //the difference is in the result
				}
			}
			values.numEnqueue(result);
		}
		
		//closed bracket, solve inside the bracket
		else if(problem[i] == ')'){
			//see if the ops queue is empty and the ops queue is not the open bracket
			while (!ops.isEmpty() && ops.getRear() != '('){
				//take first number 
				double val1 = values.getRear();
				values.Dequeue(); 
				
				//take take second number
				double val2 = values.getRear();
				values.Dequeue(); 
				
				//take operator
				char op = ops.getRear();
				ops.Dequeue(); 
				//push result to queue
				values.numEnqueue(operate(val1, val2, op)); 
			}
		
			if (!ops.isEmpty()){
				ops.Dequeue();
			}
		}
		
		//if operator
		else {
			//check if the queue is empty and the precendance
			while (!ops.isEmpty() && precedence(ops.getRear()) >= precedence(problem[i])){
				double val1 = values.getRear();
				values.Dequeue();
				
				double val2 = values.getRear();
				values.Dequeue();
				
				char op = ops.getRear();
				ops.Dequeue();
				//push the result to queue
				values.numEnqueue(operate(val1, val2, op)); 
			}
			
			//if the precendance smaller, push the operator to queue
			ops.charEnqueue(problem[i]);
		}
	}
	
	//after arranging the problem, evaluate
	while(!ops.isEmpty()){
		double val1 = values.getRear();
		values.Dequeue();
		
		double val2 = values.getRear();
		values.Dequeue();
		
		char op = ops.getRear();
		ops.Dequeue();
		
		values.numEnqueue(operate(val1, val2, op));
	}
	
	//final result stored in queue
	return values.getRear();
}
