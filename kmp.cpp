#include<iostream>
#include<bits/stdc++.h>
#include<climits>
using namespace std ;

int main()
{
	string str = "AABAACAADAABAAABAA";
	string pat = "AABA";
	vector<int> vec(pat.size(),0);
	int j = 0;

	//cout<<"yesss";

	for(int i = 1; i < vec.size(); i++){
		if(pat[j] == pat[i]){
			vec[i] = ++j;
		}
		else{
			j = vec[j-1];
			while(j>0){
				if(pat[j] == pat[i]){
					vec[i] = ++j;
					break;
				}
				else{
					j = vec[j-1];
				}
			}
			if(j == 0){
				if(pat[j] == pat[i]){
					vec[i] = ++j;
				}				
			}
		}
	}

	j = 0;
	for(int i = 0; i < str.size(); i++){
		if(str[i] == pat[j]){
			j++;
		}
		else{
			if(j!=0){
				j = vec[j-1];
				i--;
			}
		}
		if(j == (vec.size())){
			cout<<i-j + 1<<endl;
			j = 0;
		}
	}
	return 0;
}