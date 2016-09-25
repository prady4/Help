int romanToInt(string A) {
    int temp = 0, sum = 0, b_number = 0, count = 0, s_largest = 0, last = 0,  place_l=0, place_s=0;
    //string A = "MMMCCCXCIII";
    map<char, int> mapping;
    mapping['I'] = 1;
    mapping['V'] = 5;
    mapping['X'] = 10;
    mapping['L'] = 50;
    mapping['C'] = 100;
    mapping['D'] = 500;
    mapping['M'] = 1000;
    
    for(int i = (A.size() - 1); i >=0 ; i--)
    {
    	temp = mapping[A[i]];
    	if(temp > b_number)
    	{
    		s_largest = b_number;
    		place_s = place_l;
		place_l = i;
    		b_number = temp;
    		count = 1;
    		sum += temp;
    	}
    	else if(temp < b_number)
    	{
    		if((count > 1)||(b_number/temp > 10))
    			return 0;
    		else if(count ==  1)
    		{
    			if((s_largest == temp)&&((place_s-i)==2))
    				return 0;
    			else
    			{
    				count = 4;
    				sum -= temp;
    			}
    			
    			
    		}
    	}
    	else if(temp == b_number)
    	{
    		if(last != temp)
    		{
    			count = 1;
    		}
    		else
    			count++;
    		sum += temp;
    			
    	}
    	else  if(last == temp)
    	{
    		if((temp == 5)||(temp == 50)||(temp == 500))
    			return 0;
    		else
    		{
    			count++;
    			if(count > 3)
            return 0;
    			sum += temp;
    		}
    		
    	}	
    	last = temp;
    	
    }
    return sum;
}

