int searchMatrix(vector<vector<int> > &A, int B) {
    int low = 0;
    int high = A.size()-1;
    int low1 = 0;
    int high1 = A[0].size()-1;
    int mid;
    int mid1;
    int row = -1;
    
    while(low<=high)    //check
    {
        mid = (low+high)/2;
        if(A[mid][0]==B)
            return 1;
        else if(A[mid][0] > B)
            high = mid - 1;
        else
        {
            if(A[mid][high1] == B)
                return 1;
            else if(A[mid][high1] > B)
            {
                row = mid;
                break;
            }
            else
                low = mid+1;
        }
        
        
    }
    if(row==-1)
        return 0;
    else
    {
        while(low1<=high1)
        {
            mid1 = (low1+high1)/2;
            if(A[row][mid1] == B)
                return 1;
            else if(A[row][mid1] > B)
                high1 = mid1 - 1;
            else
                low1 = mid1 + 1;
            
        }
    }
    return 0;
    
}

