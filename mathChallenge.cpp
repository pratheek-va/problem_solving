#include<bits/stdc++.h>

using namespace std;

string mathChallenge(string num, int val, int pos, string res = ""){
    string ans = "";
    if(val == 0 && pos >= num.size()) return res;
    if(pos >= num.size()) return "-1";

    ans = mathChallenge(num, val + (num[pos] - '0'), pos + 1, res + "+");
    if(ans != "-1") return ans;

    ans = mathChallenge(num, val - (num[pos] - '0'), pos + 1, res + "-");
    if(ans != "-1") return ans;

    return "-1";
}

int main()
{
   cout<<mathChallenge("22990", 2, 1)<<endl;
}