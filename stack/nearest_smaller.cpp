vector<int> prevSmaller(vector<int> &A) {
    stack<int> s;
    int i = 1;
    s.push(A[0]);
    vector<int> vec;
    vec.push_back(-1);
    while(i < A.size()){
        if(A[i] > s.top()){
            vec.push_back(s.top());
            s.push(A[i]);
        }
        else{
            while(!s.empty() && s.top() >= A[i])
                s.pop();
            if(s.empty())
                vec.push_back(-1);
            else
                vec.push_back(s.top());
            s.push(A[i]);
        }
        i++;
    }
    return vec;
}

