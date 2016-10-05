#define pr pair<int,int>
int Solution::maxcoin(vector<int> &A) {
    int n = A.size();
    vector<vector<pr> > dp;
		dp.resize(n, vector<pr>(n));
    for(int i = 0; i < n; i++){
        dp[i][i].first = A[i];
        dp[i][i].second = 0;
    }
    
    for(int i = n-2; i >= 0; i--){
        for(int j = i+1; j < n; j++){
            if((A[i]+dp[i+1][j].second) > (A[j] + dp[i][j-1].second)){
                dp[i][j].first = (A[i] + dp[i+1][j].second);
                dp[i][j].second = dp[i+1][j].first;
            }
            else{
                dp[i][j].first = (A[j] + dp[i][j-1].second);
                dp[i][j].second = dp[i][j-1].first;
            }
        }
    }
    /*
    for(int k = 1; k < n; k++){
        for(int i = 0; i < n; i++){
            if(i+k < n){
                if((A[i] + dp[i+1][i+k].second) > (A[i+k] + dp[i][i+k-1].second)){
                    dp[i][i+k].first = (A[i] + dp[i+1][i+k].second);
                    dp[i][i+k].second = dp[i+1][i+k].first;
                }
                else{
                    dp[i][i+k].first = (A[i+k] + dp[i][i+k-1].second);
                    dp[i][i+k].second = dp[i][i+k-1].first;
                }
                
            }
                
        }
    }
    */
    return dp[0][A.size()-1].first;
}

