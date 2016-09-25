string addBinary(string A, string B) {
    
    string result = "";

    if(A.size() == 0)
        return B;
    if(B.size() == 0)
        return A;
    while(A.size()>B.size())
    {
        B="0"+B;
    }
    while(A.size()<B.size())
    {
        A="0"+A;
    }
    int length = A.size();
    int carry = 0;
 
    for (int i = length-1 ; i >= 0 ; i--)
    {
        int firstBit = A.at(i) - '0';
        int secondBit = B.at(i) - '0';
 
        int sum = (firstBit ^ secondBit ^ carry)+'0';
 
        result = (char)sum + result;
 
        // boolean expression for 3-bit addition
        carry = (firstBit & secondBit) | (secondBit & carry) | (firstBit & carry);
    }
 
    if (carry)
        result = '1' + result;
 
    return result;

}

