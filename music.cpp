#include <bits/stdc++.h>

using namespace std;
int main(){
	int n, h, initial;
	cin>>n;
	vector<int> vec(n,0);
	for(int i = 0; i < n; i++)
		cin>>vec[i];
	cin>>initial;
	cin>>h;
	vector<int> A(h+1, 0);
	vector<int> B(h+1, 0);
	if(initial+vec[0] <= h)
		A[initial+vec[0]] = 1;
	if(initial-vec[0] >= 0)
		A[initial-vec[0]] = 1;
	for(int i = 1; i < n; i++){
		for(int j = 0; j <= h; j++){
			if(i%2){
				if(A[j] == 1){
					if(j+vec[i] <= h)	// && B[j+vec[i]] == 0
						B[j+vec[i]] = 1;
					if(j-vec[i] >= 0)	//  && B[j-vec[i]] == 0
						B[j-vec[i]] = 1;
					A[j] = 0;
				}
			}
			else{
				if(B[j] == 1){
					if(j+vec[i] <= h)	// && A[j+vec[i]] == 0
						A[j+vec[i]] = 1;
					if(j-vec[i] >= 0)	//  && A[j-vec[i]] == 0
						A[j-vec[i]] = 1;
					B[j] = 0;
				}
			}
		}
	}
	if(n%2){
		int i = h;
		while(i >= 0 && A[i] != 1)
			i--;
		cout<<i<<endl;
	}
	else{
		int i = h;
		while(i >= 0 && B[i] != 1)
			i--;
		cout<<i<<endl;
	}
	return 0;
}