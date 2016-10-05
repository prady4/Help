int numDecodings(string A) {
    vector<int> vec(A.size(), 1);
    
    if(A[0] - '0' == 0)
        return 0;
    if(A[1] - '0' == 0){
        if(((A[0]-'0')*10 + A[1]-'0') >  26)
            return 0;
        else
            vec[1] = 1;
    }
    else
        vec[1] = (((A[0]-'0')*10 + A[1]-'0') <=  26)?2:1;

    for(int i = 2; i < A.size(); i++){
        if((A[i] - '0' == 0) && A[i-1] - '0' == 0)
            return 0;
        else if(A[i] - '0' == 0){
            if(((A[i-1]-'0')*10 + A[i]-'0') >  26)
                return 0;
            else
                vec[i] = vec[i-2];
        }
        
        else if(A[i-1] - '0' == 0){
            vec[i] = vec[i-1];
        }
        else
        vec[i] = (((A[i-1]-'0')*10 + A[i]-'0') <= 26)?vec[i-1]+vec[i-2]:vec[i-1];
    }
    return vec[A.size()-1];
}

