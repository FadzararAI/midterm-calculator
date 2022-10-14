#include"../Calculator.h"
#include"../Queue.h"
#include<iostream>
#include<stdlib.h>
#include<cmath>
using namespace std;

double Calculator::evaluate(string problem){
	int i;
	double pi = 3.141592;		
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
			ops.characterEnqueue(problem[i]);
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
					result = trig(val*pi/180, n);
				}
			}
			values.Enqueue(result);
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
					result = trig(val*pi/180, n); 
				}
			}
			values.Enqueue(result);
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
					result = trig(val*pi/180, n);
				}
			}
			values.Enqueue(result);
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
					result = trig(val*pi/180, n);
				}
			}
			values.Enqueue(result);
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
			values.Enqueue(result);
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
			
			values.Enqueue(val); 
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
			values.Enqueue(result);
		}
		
		//closed bracket, solve inside the bracket
		else if(problem[i] == ')'){
			//see if the ops queue is empty and the ops queue is not the open bracket
			while (!ops.IsEmpty() && ops.getRear() != '('){
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
				values.Enqueue(operate(val1, val2, op)); 
			}
		
			if (!ops.IsEmpty()){
				ops.Dequeue();
			}
		}
		
		//if operator
		else {
			//check if the queue is empty and the precendance
			while (!ops.IsEmpty() && precedence(ops.getRear()) >= precedence(problem[i])){
				double val1 = values.getRear();
				values.Dequeue();
				
				double val2 = values.getRear();
				values.Dequeue();
				
				char op = ops.getRear();
				ops.Dequeue();
				//push the result to queue
				values.Enqueue(operate(val1, val2, op)); 
			}
			
			//if the precendance smaller, push the operator to queue
			ops.characterEnqueue(problem[i]);
		}
	}
	
	//after arranging the problem, evaluate
	while(!ops.IsEmpty()){
		double val1 = values.getRear();
		values.Dequeue();
		
		double val2 = values.getRear();
		values.Dequeue();
		
		char op = ops.getRear();
		ops.Dequeue();
		
		values.Enqueue(operate(val1, val2, op));
	}
	
	//final result stored in queue
	return values.getRear();
}