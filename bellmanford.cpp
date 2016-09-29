#include<iostream>
#include<bits/stdc++.h>
#include<climits>
using namespace std ;

int main()
{
int n,e,u,v,w;
cin>>n>>e;

vector<pair<int, pair<int,int> > > vec; 
while(e--){
cin>>u>>v>>w;
vec.push_back(make_pair(w, make_pair(u,v)));
}

vector<int> dist(n, INT_MAX);

dist[0] = 0;
for(int i = 0; i < n; i++){
	for(int j = 0; j < vec.size(); j++){
		u = vec[j].second.first;
		v = vec[j].second.second;
		w = vec[j].first;
		if(dist[v] > dist[u]+w)
			dist[v] = dist[u]+w;
	}
}

for(int i = 0; i < n; i++){
	cout<<dist[i]<<" ";
}
cout<<"\n";

return 0;
}
