/*Question:
Camel Case is a naming style common in many programming languages. In Java, method and variable names typically start with a lowercase letter, with all subsequent words starting with a capital letter (example: startThread). Names of classes follow the same pattern, except that they start with a capital letter (example: BlueCar).

Your task is to write a program that creates or splits Camel Case variable, method, and class names.

*/

//Solution
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cctype>
using namespace std;


int main() {
   
    string input;
    bool isClass;
    bool isMethod;
    
    while(getline(cin, input)){
        isMethod = input[2] == 'M';
        isClass = input[2] == 'C';
        string str = input;
        str.erase(0, 4);
        
        if(input[0] == 'S'){
               if(isMethod) {str.erase(str.size()-2,2); }//remove ()
               if(isClass) {str[0] = tolower(str[0]);}
               
               for(int i = 0; i < str.size(); i++){
                   if(isupper(str[i])) {
                        str[i] = tolower(str[i]);
                       str.insert(i, " ");
                       i++;
                   }
               }
        }
        
        else if (input[0] == 'C'){
            for(int i = 0; i < str.size(); i++){
                if(str[i] == ' ') {
                    str.erase(i,1);
                    str[i]=toupper(str[i]);
                }
            }
            if(isClass) {str[0] = toupper(str[0]);}
            if(isMethod) {str += '('; str += ')';}
        }
        
        cout << str << endl;
    }
    return 0;
}


