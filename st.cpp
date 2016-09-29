#include<iostream>
#include<bits/stdc++.h>
#include<climits>
using namespace std ;

vector<int> vec;
vector<int> seg;

int create_seg(int low, int high, int pos){
	if(low==high){
		seg[pos] = vec[low];
	}
	else{
		int mid = (low+high)/2;
		seg[pos] = min(create_seg(low, mid, 2*pos+1),create_seg(mid+1, high, 2*pos+2));
	}
	return seg[pos];
}

int range_query(int q_low, int q_high, int low, int high, int pos){
	//total overlap
	if(q_low <= low && q_high >= high){
		return seg[pos];
	}
	//no overlap
	else if(q_high < low || q_low > high){
		return INT_MAX;
	}
	//partial overlap
	else{
		int mid = (low+high)/2;
		return min(range_query(q_low, q_high, low, mid, 2*pos+1),range_query(q_low, q_high, mid+1, high, 2*pos+2));
	}


}


int main()
{
	int n, ele, tmp, size;
	//vector<int> vec;
	cin>>n;
	size = 2*pow(2, ceil(log(n)/log(2)))-1;
	//vector<int> seg(size,0);
	tmp = n;
	while(tmp--){
		cin>>ele;
		vec.push_back(ele);
	}
	while(size--)
		seg.push_back(0);

	create_seg(0,n-1,0);
	for(int i = 0; i < seg.size();i++)
		cout<<seg[i]<<" ";
	cout<<"\n";

	cout<<range_query(4,4,0,4,0)<<endl;
	return 0;
}