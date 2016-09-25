vector<int> maxone(vector<int> &A, int B) {
    int count = 0;
    int wl = 0;
    int wr = 0;
    int bestwindow = 0;
    int bestl = 0;
    vector<int> result;
    int n = A.size();
    while(wr<n)
    {
        if(count <= B)
        {
            if(A[wr] == 0)
                count++;
            wr++;
        }
        if(count > B)
        {
            if(A[wl] == 0)
                count--;
            wl++;
        }
        if(wr-wl > bestwindow)
        {
            bestwindow = wr-wl;
            bestl  = wl;
        }
    }
    for(int i = 0;  i <  bestwindow; i++)
        result.push_back(bestl+i);
    if(result.size() == 0)
        result.push_back(0);
    return result;
}

