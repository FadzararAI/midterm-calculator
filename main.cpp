#include<iostream>
#include<stdlib.h>
#include<cmath>
//#include"Calculator.h"

using namespace std;

int main() {
    Calculator calculator;	
	double history[100] = {0};	
    string problem;			
	double result;		
	int ch = 1;						    
	int key=0;						    
	
	//welcome page
	cout << "======= Scientific Calculator =======\n" << endl;
	cout << "Input requirements: " << endl;
	cout << "1. addition -> a + b\n2. subtraction -> a - b\n3. multiplication -> a * b\n4. division -> a/b\n"
	        "5. trigonometry ->  sin x, cos x, tan x, asin x, acos x, atan x\n"
	        "6. square root -> r(x)\n7. exponent -> a^b\n8. logarithm -> log(x)\n9. natural log -> ln(x)\n" << endl;
	cout << "Note: It is possible to input multiple variables and use ( ) for precedence.\n" << endl;
  //break before start the program
	do {
      cout << "\nClick Enter to Start!";
    } while (cin.get () != '\n');
	
	//program directory
	i:                                   //to return to directory
	cout << "\nDirectory:" << endl;
	cout << "1 = Calculate a Problem" << endl;
	cout << "2 = Check History" << endl;
  cout << "3 = Clear History" << endl;
  cout << "0 = Exit Calculator" << endl;

	cout << "\nEnter command: ";
	cin >> ch;
	
	while (ch != 0) {
		//calculator
		if (ch == 1) {
			cout << "\nEnter math problem: ";
			cin.ignore();
			getline(cin, problem);
			history[key++] = result = calculator.evaluate(problem);
			cout << "Answer= " << result << endl;
			do {
                cout << "\nEnter to return to directory.";
            } while (cin.get () != '\n');
		}
		//print history
		else if (ch == 2){
			//key as the index
			if(key != 0){
				cout << "\nCalculator History: " << endl;
				for (int i = 0; i < key; i++) {
					cout << "\t" <<  i+1 << ". " << history[i] << endl;
				}
			}
			else {
				cout << "\nNo Calculation History\n";
			}
		}
		//clear history
		else if (ch == 3){
		    char c;
			cout << "\nAll history will be deleted and can not be restored, continue?\nEnter 1 for continue and 0 for cancel:" << endl;
			cin >> c;
			//if user wants to continue
			if (toupper(c) == '1') {
				cout << "\n===History Cleared===" << endl;
				//deleting history contents with loop
				for (int i = 0; i < key; i++){
					history[i] = 0;			
				}
				//reseting the key to 0 so it can be reused 
				key = 0;
			}
			//if user wants to cancel
			else {
				continue;
			}
		}
		//if user input an invalid command
		else {
			cout << "Invalid Command." << endl;
		}
		goto i;               //back to directory
	}
	//exit message
	if (ch == 0) {
	        char c;
	        cout << "\n\n!!!Confirm End Program!!!\nEnter 0 to confirm exit and 1 to cancel" << endl;
			cin >> c;
			if (toupper(c) == '0'){
		        cout << "\n\n\n\n\n\nThank you for using this calculator, Goodbye!" << endl;
			} else goto i;
	}
	return 0;
}
