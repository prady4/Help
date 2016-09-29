#include<bits/stdc++.h>

using namespace std;

int main(){
int s, n, sum = 0;
cin>>s>>n;
vector<bool> prime(n+1, true);

for(int i = 2; i <= sqrt(n); i++)
	if(prime[i])
		for(int j = i*2; j <= n; j+=i)
			prime[j] = false;
for(int i = s; i <= n; i++)
if(prime[i])
	sum+=i;
cout<<sum<<endl;
return 0;
}
