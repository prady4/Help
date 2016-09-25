int isPalindrome(string A) {
    int  x = A.size();
    string str = ""; 
    for(int i = 0; i < x; i++)
    {
        if((A[i] >=65 && A[i] <= 90)||(A[i] >=97 && A[i] <= 122)||(A[i] >=48 && A[i] <= 57))
        {
            str+=toupper(A[i]);
        }
    }
    x = str.size()-1;
    for(int i = 0; i <= x; i++)
    {
        if(str[i]!=str[x-i])
            return  0;
    }
    return 1;
}

