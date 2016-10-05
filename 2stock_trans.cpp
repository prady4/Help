#include<climits>
int Solution::maxProfit(const vector<int> &A) {
    
    if(A.size() == 0 || A.size() == 1)
        return 0;
    int profit_sf = 0, min_sf = A[0], max_sf = A[A.size()-1];
    vector<int> frwd(A.size(), 0);
    vector<int> bkwd(A.size(), 0);
    for(int i = 1; i < A.size(); i++)
    {
        min_sf = A[i]<min_sf?A[i]:min_sf;
        profit_sf = max(profit_sf, A[i] - min_sf);
        frwd[i] = profit_sf;
        //cout<<frwd[i]<<endl;
    }
    
    profit_sf = 0;
    for(int i = A.size()-2; i >= 0; i--)
    {
        max_sf = A[i]>max_sf?A[i]:max_sf;
        profit_sf = max(profit_sf, max_sf - A[i]);
        bkwd[i] = profit_sf;
    }
    max_sf = INT_MIN;
    for(int i = 0; i < A.size(); i++){
        frwd[i] += bkwd[i];
        max_sf = max(frwd[i], max_sf);
    }
    return max_sf;
}

