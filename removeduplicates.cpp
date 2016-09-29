#include<bits/stdc++.h>

using namespace std;

int main(){
string s = "bullluuubshit";
string res="";
stack<char> st;
int i = 1;
char same;
st.push(s[0]);
while(i < s.size()){
	if(s[i] == same)
		i++;
	else{
		if(!st.empty()){
			if(s[i] == st.top()){
				st.pop();
				same = s[i];
			}
			else
			st.push(s[i]);
		}
		else
		st.push(s[i]);
		i++;
	}
}
while(!st.empty()){
	res = st.top()+res;
	st.pop();
}
cout<<res<<endl;
return 0;
}
