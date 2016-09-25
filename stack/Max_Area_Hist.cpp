int largestRectangleArea(vector<int> &A) {
    stack<int> s;
    int i = 0, x, amax = 0, n = A.size();
    while(i < A.size()){
        if(s.empty())
            s.push(i);
        else{
            if(A[s.top()] <= A[i])
                s.push(i);
            else{
                while(!s.empty() && A[s.top()] > A[i]){
                    x = s.top();
                    s.pop();
                    if(s.empty()){
                        amax = max(amax, A[x]*i);
                    }
                    else
                        amax = max(amax, A[x]*(i-s.top()-1));
                }
                
                s.push(i);
            }
        }
        i++;
        
    }
    while(!s.empty()){
        x = s.top();
        s.pop();
        if(s.empty())
            amax = max(amax, A[x]*(n));
        else
        amax = max(amax, A[x]*(i-s.top()-1));
    }
    return amax;
}

