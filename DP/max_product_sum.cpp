int maxProduct(const vector<int> &A) {
    
    int lmax = 0, lprev = 1, rmax = 0, rprev = 1;
    for(int i = 0; i < A.size(); i++){
        if(lprev == 0)
            lprev = 1;
        lprev *= A[i];
        lmax= max(lmax, lprev);
    }
    //rmax = lprev;
    for(int i = A.size()-1; i >= 0; i--){
        if(rprev == 0)
            rprev = 1;
        rprev *= A[i];
        rmax= max(rmax, rprev);
    }
    return max(lmax, rmax);
}

