

https://practice.geeksforgeeks.org/problems/zero-sum-subarrays/0
https://www.geeksforgeeks.org/print-all-subarrays-with-0-sum/

int yo(int a[],int n)
{
  unordered_map<int,vector<int>>m;  // stores all indices with a particular sum!
  int sum=0;
  int ans=0;
  int siz;
  m[0].push_back(-1); //basic initilization
  for(int i=0;i<n;i++)
  {
      sum+=a[i];
      
      if(m.find(sum)!=m.end())
      {
           siz = m[sum].size();  //for all of the elements in that vector we have one sub array starting from that index to present index
           ans+=siz;             // that is why we are adding the size of that vector to our ans! very important!
      }
      m[sum].push_back(i);
  }
  return ans;
}

//first non repeating charecter in a string.
int main() {

 string s;
 cin >>s;
 
 map<char,int>m;
 
 for(int i=0;i<s.length();i++)
   m[s[i]]++;
  
 int j;  
 int min =INT_MAX;  
 
 for(int i=0;i<s.length();i++)
 {
  if(m[s[i]]==1)
  { 
   cout << s[i] << endl;
   return 0;
  }
 }
 
 
https://practice.geeksforgeeks.org/problems/check-frequencies/0
//see it once

int yo(string s)
{
    int n = s.length();
  unordered_map<char,int>m;
  for(int i=0;i<n;i++)
    m[s[i]]++;
    
  int count=0;
  int c[n+1];
  memset(c,0,sizeof(c));
  int count1=0;
  for(auto i:m)
  {
     if(c[i.second]==0)
        count++;
     if(count>2)
       return 0;
     c[i.second]++;
  }
  int a=-1,b=-1;
  for(int i=1;i<=n;i++)
  {
      if(c[i]!=0)
      {
          if(a==-1)
            a = i;
          if(i!=a)
          {
            b = i;
            if(c[a]!=1 && c[b]!=1)
               return 0;
               
            if(abs(b-a)>1)
              return 0;
          }
      }
  }
  return 1;
}


//Smallest distinct window 
https://www.geeksforgeeks.org/smallest-window-contains-characters-string/
int yo(string s)
{
  
  int m1[256]; // 256 are the total number of characters possible! we can use this as a map counter!
  memset(m1,0,sizeof(m1));
  
  int m2[256];  // will be used later
  memset(m2,0,sizeof(m2));
  int n = s.length();
  
  int m=0; // number of distinct charecters in the given string
  for(int i=0;i<n;i++) 
      if(!m1[s[i]]) // if its zero
      {
         m1[s[i]]=1;  // update it to one
         m++;         // increase the number of distinct charecters
      }         
  
  int i=0,j=0;
  int count=0;
  
  int mini = n; // minimum length that has all the charecters initialized as n
  while(i<n)
  {
     m2[s[i]]++;
     
     if(m2[s[i]]==1)
       count++;
       
     if(count==m && j<n) // if you found all the 'm' distinct charecters use the double pointer approach!
     {
       while(m2[s[j]]>1) //remove charecters occuring more than once
       {
         m2[s[j]]--;
         j++;  
       }
       
       mini = min(mini,i-j+1);
     }
     i++;
  }

  return mini;
}

//Count distinct elements in every window
//tricky to do in order of n 
void countDistinct(int a[], int k, int n)
{
   unordered_map<int,int>m;
   
   int count=0;
   for(int i=0;i<k;i++)
   {
      if(m[a[i]]==0)  // if a new element is found count increases;
        count++;
      m[a[i]]++;     //increase count of that element
   }
   cout << count << " ";
   
   for(int i=k;i<n;i++)
   {
       m[a[i-k]]--;     // decrease count of the removed element
       if(m[a[i-k]]==0)  // if count after decreasing became zero meaning that element is done with count decreases.
         count--;
       
       if(m[a[i]]==0) // if a new element is found count increases;
         count++;
       m[a[i]]++;     
       cout << count << " ";
   }
}



https://practice.geeksforgeeks.org/problems/smallest-window-in-a-string-containing-all-the-characters-of-another-string/0
//smallest substring inside a sub string
string yo(string s1,string s2)
{
  unordered_map<char,int>m1,m2; //for both the strings
  int n = s1.length();
  int m = s2.length();
  
  if(m>n)
    return "-1"; //impossible to get answer
    
  for(int i=0;i<m;i++)
    m2[s2[i]]++;
    
  int count=0;
  int i=0,j=0;
  int mini = n+1;
  int min_index=-1;
  while(i<n)
  {
      m1[s1[i]]++;
      if(m2.find(s1[i])!=m2.end() && m1[s1[i]]<=m2[s1[i]])
        count++;
       
      if(count==m) // first reach the point where u have all the required charecters then remove the unneccsary ones.
      {
          while(m2.find(s1[j])==m2.end() || m1[s1[j]]>m2[s1[j]] && j<n) //first condition not needed charecter remove
          {                                                             //second more charecters are present than needed so remove
            if(m1[s1[j]]>m2[s1[j]])
              m1[s1[j]]--;
              
            j++;  
          }
          if(mini>i-j+1)
          {
             mini = i-j+1;
             min_index = j;
          }
      }
      i++;  
  }
  if(mini==n+1)
    return "-1";
  return s1.substr(min_index,mini);
}