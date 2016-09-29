#include<bits/stdc++.h>

using namespace std;

int main(){
int n, v;
cin>>n>>v;
map<int, int> hash;
vector<int> vec;
while(n--){
	cin>>e;
	if(e){
		vec.push_back(e);
		hash[e] = 1;
	}
}
for(int i = 0; i < vec.size(); i++){
	for(int j = i+1; i <vec.size(); j++)
		if(hash[v/(vec[i]*vec[j])])
			cout<<vec[i]<<vec[j]<<v/(vec[i]*vec[j]);
}
return 0;
}
