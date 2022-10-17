#include<iostream>
#include<stack> // This library will let us use the functions like push and pop
#include<string>

using namespace std;

// This function will check if curly braces are pairs or not
bool areCurlyBracesPair(char opening,char closing) {
	return (opening == '{' && closing == '}') ? true : false;
}

// This will check the if the curly braces are balanced
bool areCurlyBraceBalanced(string exp) {
	stack<char>  S;
	for(int i =0;i<exp.length();i++)
	{
		if(exp[i] == '{')
			S.push(exp[i]);
		else if(exp[i] == '}')
		{
			if(S.empty() || !areCurlyBracesPair(S.top(),exp[i]))
				return false;
			else
				S.pop();
		}
	}
	return S.empty() ? true:false;
}

int main() {
    int noOfExpressions;
	string expression;

    cout << "Input number of expressions: ";
    cin >> noOfExpressions;

    int results[noOfExpressions]; // This array will store ones and zeroes to correctly display balanced or not balanced of curly braces.
    cout << endl;

    for(int i=0; i<noOfExpressions; i++) {
        cout << "Enter expression " << (i+1) << ": ";
        cin >> expression;
	    areCurlyBraceBalanced(expression) ? results[i] = 1 : results[i] = 0;
    }

    cout << "\nOutput: " << endl;

    for(int i=0; i<noOfExpressions; i++) {
        if(results[i]) {
            cout << "Expression " << (i+1) << " is... BALANCED!" << endl;
        } else {
            cout << "Expression " << (i+1) << " is... NOT BALANCED!" << endl;    
        }
    }

}