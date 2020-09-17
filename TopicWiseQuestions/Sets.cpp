
Topic : Sets!

//longest consecutive subsequence.
//very important question
vector<int> longestSubsequence(int *a, int n)
{	
 set<int>s;
 for(int i=0;i<n;i++)
  s.insert(a[i]);
  
 int i,j;
 int ans=INT_MIN;
 int index;
    
 for(i=0;i<n;i++)
 {
   if(s.find(a[i]-1)==s.end()) //crucial idea!! if a[i]-1 is not found in our set, that means that this element can be a starting element!
   {
     j = a[i];
     
     while(s.find(j)!=s.end())
         j++;
       
     if(j-a[i]>ans)
     { 
       ans = j - a[i];
       index = i;  
     }
   }
 }
 
 j = a[index];   
 while(ans--)
 {
    cout << j << endl;
     j++;
 } 
 
}	
