#include<iostream>
#include<bits/stdc++.h>
#include<climits>
using namespace std ;

int main()
{
	string str = "AABAACAADAABAAABAA";
	string pat = "AABA";
	str = pat+'$'+str;
	vector<int> z_array(str.size(),0);
	
	
	for(int i = 1; i < str.size(); i++){
		int j = 0, k = i;
		while(str[j] == str[k]){
			k++;
			j++;
		}
		z_array[i] = j;
		for(k = 1; k < j; k++){
			if(z_array[k]+k < j)
				z_array[i++] = z_array[k];
			else{
				int index = z_array[k];
				k = i;
				//i--;
				while(str[index] == str[k]){
					k++;
					index++;
				}
				z_array[i] = index;

			}
		}

	}

	for(int i = 0; i < str.size(); i++)
		cout<<z_array[i]<<" ";
	return 0;
}