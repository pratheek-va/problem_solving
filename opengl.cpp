#include<iostream>
#include<vector>

using namespace std;

void getBrackets(vector<string> &brackets, int open, int close, string s = ""){
	int new_open, new_close;

	if(open == 0 && close == 0) {
		brackets.push_back(s);
		return;
	}

	if(open > 0){
		new_open = open - 1;
		getBrackets(brackets, new_open, close, s + "(");
	}
	
	if(close > open){
		new_close = close - 1;
		getBrackets(brackets, open, new_close, s + ")");
	}
}

int noOfPalindromes(string s){
	int res = 0, left, right;

	for(int i = 0; i < s.size(); i++){
		left = i, right = i;
		while(left >= 0 && right < s.size()){
			if(s[left] == s[right]) res++;
			else break;
			left--, right++;
		}
	}

	for(int i = 0; i < s.size(); i++){
		left = i, right = i + 1;
		while(left >= 0 && right < s.size()){
			if(s[left] == s[right]) res++;
			else break;
			left--, right++;
		}
	}

	return res;
}

vector<string> noOfBrackets(int n){
	vector<string> brackets = {};
	getBrackets(brackets, n, n);
	return brackets;
}

int main()
{
	// vector<string> b = noOfBrackets(3);
	// for(string s: b)
	// 	cout<<s<<endl;
	cout<<noOfPalindromes("abc")<<endl;
}