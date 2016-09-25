int maxArea(vector<int> &A) {
    int i = 0, j = A.size()-1, area = 0;
    //return min(5,2);
    if(A.size() == 0 || A.size() == 1)
        return area;
    while(i<j)
    {
        area = max(area,(j-i)*min(A[i],A[j]));
        if(A[i]>A[j])
            j--;
        else if(A[i] < A[j])
            i++;
        else
        {
            i++;
            j--;
        }
    }
    return area;
    
}
