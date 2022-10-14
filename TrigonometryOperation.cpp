#include<iostream> 
#include<cmath> 
#include<stdlib.h>
using namespace std; 

const double pi = 3.1415936; 
#define degree(x) (x*pi)/180

float input(int n,char trig[20]) { 
    int i=3,j=0; char temp[10]; 
    while(trig[i] !='\0') { 
        if(trig[i]==' ') {
            i++; break;
        } 
        i++;
    } 
    while(trig[i]!='\0') { 
        temp[j]=trig[i]; 
        j++;
        i++; 
    } 
    return degree(atoi(temp)); 

} 
    
int main() { 
    int n; char trig[20]; 

    cout<<"\nEnter the input (sin x, cos x, tan x) and 'exit' to exit:\n"; 
        while(1){ 
            cout<<"\nTrigonometry input: "; 
            gets(trig); 
             
            switch(trig[0]) {
                case 's': cout<<"Output: "<<sin(input(n,trig)); 
                break; 
            
                case 'c': cout<<"Output: "<<cos(input(n,trig)); 
                break; 
            
                case 't': cout<<"Output: "<<tan(input(n,trig)); 
                break; 
            
                case 'a': switch(trig[1]) { 
                    case 's': cout<<"Output: "<<sin(input(n,trig)); 
                    break; 
                
                    case 'c': cout<<"Output: "<<cos(input(n,trig)); 
                    break; 
                
                    case 't': cout<<"Output: "<<tan(input(n,trig)); 
                    break; 
                }
                break; 
                
                case 'e': exit(0);
                
                default: cout<<"Invalid Input."; 
            }; 
        } 
        return 0; 
}
