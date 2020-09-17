
Topic : Strings


//Longest substring with Distinct characters in string
int yo(string s,int n)
{
  int count[256];
  memset(count,0,sizeof(count));
  int i=0,j=0;
  int maxi = 0;
  
  while(i<n)
  {
      if(count[s[i]]==0)
      {
          count[s[i]]++;
          i++;
          maxi = max(maxi,i-j);
      }
      else
      {
          count[s[j]]--;
          j++;
      }
  }
  return maxi;
}

//longest palindromic substring

int main()
{
    string s;
    cin >>s;
    
    int n = s.length();
    int low,high,start,maxlen=-1,max_s=-1;
    
    for(int i=0;i<n;i++)
    {
     //odd len palindromes
     
     low = i-1;
     high = i+1;
     
     while(low>=0 && high <n && s[low]==s[high]) // palindrome conditions
     {
       start = low;
       if(high-low+1 > maxlen)
       {  
         maxlen = high-low+1;
         max_s = start;
       }
       low--;
       high++; 
     }
     
     //even
     
     low = i;
     high = i+1;
    
     while(low>=0 && high <n && s[low]==s[high])
     {
       start = low;
       if(high-low+1 > maxlen)
       {  
         maxlen = high-low+1;
         max_s = start;
       }
       low--;
       high++; 
     }
      
    }
    cout << s1(s,max_s,maxlen) <<endl;
}
