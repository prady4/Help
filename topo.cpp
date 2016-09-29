#include<iostream>
#include<bits/stdc++.h>
#include<climits>
using namespace std ;
vector<bool> visited;
stack<int> s;

void dfs(list<int> *adj, int u){
	list<int>::iterator i;
	for(i = adj[u].begin(); i != adj[u].end(); i++){
		if(!visited[*i]){
			visited[*i] = 1;
			dfs(adj, *i);
			
		}
	}
	s.push(u);
	return;
}


int main()
{
int n,e,u,v;
cin>>n>>e;
list<int> *adj = new list<int>[n+1];
while(e--){
cin>>u>>v;
adj[u].push_back(v);
//adj[v].push_back(u);
}
for(int i = 0; i < n; i++)
	visited.push_back(false);
for(int i = 0; i < n; i++)
if(!visited[i]){
	visited[i] = 1;
	dfs(adj, i);
	}

while(!s.empty()){
	cout<<s.top()<<" ";
	s.pop();
}
cout<<"\n";
/*
s.push(1);
list<int>::iterator i;
while(!s.empty()){
	u = s.top();
	s.pop();
	visited[u] = 1;
	cout<<u<<endl;
	for(i = adj[u].begin(); i != adj[u].end(); i++){
		if(!visited[*i]){
			s.push(*i);
			visited[*i] = 1;
		}
	}
}
*/
return 0;
}
