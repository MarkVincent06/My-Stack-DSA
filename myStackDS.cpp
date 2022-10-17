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
	string expression;
	cout<<"Enter an expression:  "; // input expression from STDIN/Console
	cin>>expression;
	if(areCurlyBraceBalanced(expression))
		cout<<"Balanced\n";
	else
		cout<<"Not Balanced\n";
}