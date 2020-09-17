
dynamic programming DP
  
//best time to buy and sell stock
//one time! buy to local min and sell at local maximum
 
int main() 
{
 int n;
 cin>>n;
 int a[n];

 for(int i=0;i<n;i++)
    cin>>a[i];

 int min = INT_MAX;
 int max =0;
    
 for(int i=0;i<n;i++)
 {
  if(a[i]<min)
      min = a[i];
  else if (a[i]-min > max)
      max = a[i] - min;
 }
    
 cout << max << endl;    
}  

//Maximum Subarray Sum with One Deletion
int maximumSum(vector<int>&arr) 
{
     int n = arr.size();
     int md = arr[0];
     int m = arr[0];
     int maxi = arr[0];
        
     for(int i=1;i<n;i++)
     {
        md = max(m,md+arr[i]);    // op1 do not consider this element, op2 consider this element!
        m = max(m+arr[i],arr[i]); // normal kadanes
            
        maxi = max(maxi,max(m,md));
     }
     return maxi;
}
  
//alpha code
//very good que! see all the corner cases. The zero wala case!

// 10 23 2  J W B
// 10 2 3 2 J B C B 
// number of possible decodings!

//  1212 - 121 2  1 2 1 2  12 1 2  1 21 2 dp[n] = dp[n-1] + dp[n-2]
//    12 12 

//  1 2 12  1 2 1 2 1 2 12 1 0 10 012
                        

long long int alphacode(string s)
{

  if(s[0] == '0')
     return 0;
      
  int n = s.length();
  long long int arr[n+1];
  
  arr[0]=1;
  arr[1]=1;
  
  for(int i=2;i<=n;i++) // see the indexing
  {
     /*
      i -1 means the current charecter that is added at the moment
      if the current added charecter and previous one combined form a number that is btw 10 & 26 we have one more possibility
      other than just taking this charecter as separate  
   */
   
     if(s[i-1]!='0')
       arr[i] = arr[i-1] % k;
     else
       arr[i] = 0;
      
     int a = (s[i - 2] - '0') * 10 + (s[i - 1] - '0');
      
     if(a >= 10 && a<=26)
         arr[i] += arr[i-2] % k;
         
     arr[i] = arr[i]%k; 
  }
  
  return arr[n];
}

https://www.geeksforgeeks.org/find-maximum-possible-stolen-value-houses/

//robber looting money
//loot money
int getMaxMoney(int a[], int n)
{
    int dp[n];
    dp[0]=a[0];
    if(n==1)
        return dp[0];
    
    dp[1] = max(a[0],a[1]);
    
    for(int i=2;i<n;i++)
        dp[i] = max(dp[i-2]+a[i],dp[i-1]);
    
    return dp[n-1];
} 



https://practice.geeksforgeeks.org/problems/friends-pairing-problem/0

// just put this guy separately then it becomes the same problem with i-1 guys, or you can pair him with one person then i-2 are still
// left recur for them again; you can select any of the i-1 people from before

dp[i] = dp[i-1] + (i-1)*dp[i-2];


https://practice.geeksforgeeks.org/problems/number-of-ways/0
//tile stacking

// add a tile horizontally to all the previous configurations, the trivial case
// or go back 4 places and put all in vectical configuration to get 4*4
// till i<4 initialize to 1
// easily generalizable for any m (in place of 4)
dp[i] = dp[i-1] + dp[i-4];



jump game array
https://www.interviewbit.com/problems/jump-game-array/


// 1 2 0 1 0
// 0 1 2 3 4

// 1 0
// 0 0

int Solution::canJump(vector<int> &a) 
{
    int n = a.size();
    int dp[n];              
    memset(dp,0,sizeof(dp));
    dp[n-1]=1;
    
    /*
       dp[i] indicates if its possible to reach "n-1" index from index "i"
       dp[n-1] = 1 as we are already at index "n-1"
       for other indices we are exploring all possible paths that are possible from that particular index!
       if we can reach index "n-1" from index "j" and we can reach index "j" from "i" then, dp[i] = 1!
    */
    for(int i=n-2;i>=0;i--)
    {
        for(int j=a[i]+i;j>i;j--)
        {
            if(dp[j] && a[i]>=(j-i))
            {
                dp[i]=1;
                break;
            }
        }
    }
    return dp[0];
}

Min sum path in matrix
https://www.interviewbit.com/problems/min-sum-path-in-matrix/
int Solution::minPathSum(vector<vector<int> > &arr) 
{
    int n = arr.size();
    int m = arr[0].size();
    
    int dp[n][m];
    
    for(int i=0;i<n;i++)
     for(int j=0;j<m;j++)
        dp[i][j] = INT_MAX;
        
    dp[0][0] = arr[0][0];
    
    for(int i=0;i<n;i++)
    {
     for(int j=0;j<m;j++)
     {
        if (i+1 < n)
          dp[i+1][j] = min(dp[i+1][j],dp[i][j] + arr[i+1][j]);
          
        if (j+1 < m)
          dp[i][j+1] = min(dp[i][j+1],dp[i][j] + arr[i][j+1]);  
     }
    }
    
    return dp[n-1][m-1];
}

//knapsack
// space optimized knapsack!
int knapsack(int* weights, int* values, int n, int maxWeight)
{
  int dp[2][maxWeight+1];
  // as base case has zero as the answer we initiliase with zero
  memset(dp,0,sizeof(dp));
 
    
  for(int i=1;i<=n;i++)
  {
      for(int j=1;j<=maxWeight;j++)
      {
          if(weights[i-1]<=j)
              dp[i%2][j]= max(dp[(i-1)%2][j-weights[i-1]]+values[i-1],dp[(i-1)%2][j]);
          else
              dp[i%2][j]=dp[(i-1)%2][j];
      }
  }
    return dp[n%2][maxWeight];
}


//similar to subset sum and knapsack : given sum is the knapsack's weight values of array are the given sarray!
// find if there exists a subset of the array with the given sum
int subsetsum(int a[],int n,int k)
{
    int dp[2][k+1];
    memset(dp,0,sizeof(dp));
    
    for(int i=0;i<=1;i++)
      dp[i][0]=1;
    
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=k;j++)
        {
            if(a[i-1]<=j)
                dp[i%2][j] = max(dp[(i-1)%2][j],dp[(i-1)%2][j-a[i-1]]);
            else
                dp[i%2][j]=dp[(i-1)%2][j];
        }
    }
    return dp[n%2][k];
}

// equal sum partition
//Given a set of numbers, check whether it can be partitioned into two subsets such that the sum of elements in both subsets is same or not.
// basically a simple modification of a given sum is possible to construct from the array or not!
void ans(int a[],int n,int sum)
{
    if(sum%2==1)
    {
        cout << "NO" << endl;  // if sum is odd you can never partition the set into 2 parts! with same sum
        return;
    }
    
    int s = sum/2;
    int dp[2][s+1];
    memset(dp,0,sizeof(dp));   // just find the sum/2 value if it exists! then you are done // sum here is the sum of the array
    
    for(int j=0;j<=1;j++)
      dp[j][0]=1;
    
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=s;j++)
        {
            if(a[i-1]<=j)
              dp[i%2][j] = max(dp[(i-1)%2][j-a[i-1]],dp[(i-1)%2][j]);
            else
              dp[i%2][j] = dp[(i-1)%2][j];
        }
    }
    if(dp[n%2][s])
      cout << "YES" << endl;
      
    else
      cout << "NO" << endl;
}

//Minimum Subset Sum Difference
https://practice.geeksforgeeks.org/problems/minimum-sum-partition/0
//Given an array, the task is to divide it into two sets S1 and S2 such that the absolute difference between their sums is minimum.

int yo(int a[],int n,int sum)
{
  int k = sum/2; // idea is to get as close as posssible to sum/2 where sum is the sum of all elements in the array
  
  int dp[2][k+1];
  memset(dp,0,sizeof(dp));
  
  for(int i=0;i<2;i++) 
   dp[i][0]=1;
   
  int maxi=0; 
  for(int i=1;i<=n;i++)
  {
      for(int j=1;j<=k;j++)
      {
          if(j>=a[i-1])
           dp[i%2][j] = max(dp[(i-1)%2][j-a[i-1]],dp[(i-1)%2][j]);
          else 
          dp[i%2][j] = dp[(i-1)%2][j];
          
          if(i==n && dp[i%2][j])
            maxi = max(maxi,j);   //maxi stores the closest possible sum to sum/2
      }
  }
  return abs(sum-2*maxi);  // this would then be the answer! // intuition!
}


//2d array! 2d dp!

// coin change problem
// number of ways of getting change for 'n rupees' using a array of coins 's' of size 'm'
int count( int s[], int m, int n ) 
{ 
    int dp[n + 1][m]; 
      
    // initialization number of ways of getting change for '0(zero)' rupees is 1 (one).  
    for (i = 0; i < m; i++) 
        dp[0][i] = 1; 
 
    int x,y;
    
    for (int i = 1; i <= n; i++) 
    { 
        for (int j = 0; j < m; j++) 
        { 
             x=0,y=0;
             
            // Count of solutions including s[j] 
	        if(s[j]<=i)
	         x = dp[i-s[j]][j]; // observe that we still use "j", because we would want to use this coin again.
  
            // Count of solutions excluding s[j] 
            // "j - 1" we are excluding it completely.
             if(j>=1)
	         y = dp[i][j-1];
  
            // total count 
            dp[i][j] = x + y; 
        } 
    } 
    return dp[n][m - 1]; 
}

//minimum coins needed problem
/// similar to coin change problem, but here intialisations are different
int yo(int s,int a[],int n)
{
  sort(a,a+n);   
  int dp[2][s+1];
  memset(dp,0,sizeof(dp));
  for(int i=1;i<=s;i++)
  {
   dp[0][i]=INT_MAX-1;      
   if(i%a[0]==0)
     dp[0][i] = i/a[0]; // this is main initialization! if its divisible, its a number else no number!
  }  

  for(int i=1;i<n;i++)
  {
      for(int j=1;j<=s;j++)
      {
          if(j>=a[i])   // u are adding a one to j-a[i] case, see that! number of coins would be one plus the one we are adding!
          dp[i%2][j] = min(dp[i%2][j-a[i]]+1,dp[(i-1)%2][j]); // u dont add like in coin change u take the min
          else
          dp[i%2][j] = dp[(i-1)%2][j];
      }
  }
  if(dp[(n-1)%2][s]!=INT_MAX-1)
    return dp[(n-1)%2][s];
  return -1;
}


//hackerank almost sorted que
// longest increasing subsequence! in O(nlogn) link is below :
https://www.youtube.com/watch?v=1RpMc3fv0y4

// In this particular question, you have to return how many elements have to be removed so that the array is almost sorted
// what is almost sorted ? all the elements are in a sorted way or one element is out of its position!

// idea : we find the longest increasing subseq. that is the longest sequence of elements already in sorted order
// we return ans as : n - length - 1

// where is the length of the array
// length is the length of LIS 
// we subtract 'one' so as to account for the almost sorted case!
 
int LIS(vector<int>arr)
{
    
    int n = arr.size();
	int parent[n];
	int increasingSub[n+1]; 
	int length = 0; 
			
	for(int i=0; i<n; i++)
	{
		//Binary search
		int low = 1;
		int high = length;
		
		while(low <= high)
		{
			int mid = (low + high)/2;
				
			if(arr[increasingSub[mid]] < arr[i])
				low = mid + 1;
			else
				high = mid - 1;
		}
			
		int pos = low;

		parent[i] = increasingSub[pos-1];
		increasingSub[pos] =  i;
			
		if(pos > length)
			length = pos;
	}

    return max(0,(n-length-1));						
}

//box stacking problem
// prints all the stack of boxes also!
https://www.youtube.com/watch?v=9mod_xRB-O0


struct box
{
  int l,w,h;
};

bool compare(box a, box b)
{
   int a1 = (a.l)*(a.w);
   int a2 = (b.l)*(b.w); // returns the greater of 2 areas
   if(a1==a2)
     return a.l > b.l;  // if areas are same returns the one with the greater length;
   return a1 > a2;
} 

int yo(box a[],int n)
{
  box all[3*n];
  int j=0;
	  // generating all sequences of boxes
	  // we are just putting l>=w doesnt matter if it is the other way!
  for(int i=0;i<n;i++)
  {
	j=0;
	all[i*3+j].h = a[i].h;
	all[i*3+j].l = max(a[i].l,a[i].w);
	all[i*3+j].w = min(a[i].l,a[i].w);
	    
	j++;
	all[i*3+j].h = a[i].l;
	all[i*3+j].l = max(a[i].h,a[i].w);
	all[i*3+j].w = min(a[i].h,a[i].w);
	    
    j++;
	all[i*3+j].h = a[i].w;
	all[i*3+j].l = max(a[i].h,a[i].l);
	all[i*3+j].w = min(a[i].h,a[i].l);  
  }
  
  n=3*n;
  sort(all,all+n,compare); // reverse sorting
  int dp[n];
  int res[n];
  for(int i=0;i<n;i++)
  {
    dp[i] = a[i].h;
    res[i]=i;
  }
  
  int maxi = 0;
  int max_index=-1;
  for(int i=0;i<n;i++)
  {
    for(int j=0;j<i;j++)
    {
      if(a[i].l < a[j].l && a[i].w < a[j].w)
      {
        if(dp[i]<dp[j]+a[i].h)
        {
          dp[i] = dp[j] + a[i].h;  // if condition is satisfied we can put i on top of j
          res[i] = j;              // storing that i is on top of j
        }
      }
    }
    if(maxi<dp[i])
    {
      maxi = dp[i];
      max_index = i;
    }
  }
  
  int i = max_index;
  
  // prints the result! 
  // prints all the boxes right from the top to the bottom
  while(i!=res[i])
  {
    cout << a[i].l << " " << a[i].w <<" " << a[i].h << endl;
    i = res[i];
  }
  cout << a[i].l << " " << a[i].w <<" " << a[i].h << endl;
  
  
  return maxi;
}


//longest common subsequence LCS

//see the video if any doubt
int lcs(string s1, string s2)
{

  int m = s1.length();
  int n = s2.length();
    
  
  int dp[m+1][n+1];
    
  for(int i=0;i<=m;i++)
  {
      for(int j=0;j<=n;j++)
      {
        if(i==0 || j==0)
            dp[i][j]=0;   //initialization 
            
        else if(s1[i-1]==s2[j-1])
            dp[i][j] = 1 + dp[i-1][j-1];   // if the 2 charecters are same, just add one to lcs of string before them
          
        else
            dp[i][j] = max(dp[i-1][j],dp[i][j-1]);  // take max of other two  
      }
  }
  return dp[m][n];   

}


//Form a palindrome from a given string with min insertion of charecters
// charecters can be inserted anywhere
// idea is to find lcs between string and its reverse and subtract the len of the string from it
// as charecters can be inserted anywhere, idea is that insert only those which are not contributing to the palindrome as such

int yo(string s)
{
  int n = s.length();
  string s1 = s;
  reverse(s.begin(),s.end());

  int dp[2][n+1];
  memset(dp,0,sizeof(dp));
  
  for(int i=1;i<=n;i++)
  {
      for(int j=1;j<=n;j++)
      {
          if(s[i-1]==s1[j-1])
           dp[i%2][j] = 1 + dp[(i-1)%2][j-1];
           
          else
           dp[i%2][j] = max(dp[(i-1)%2][j],dp[i%2][j-1]);
      }
  }
  return (n - dp[n%2][n]);
}

https://www.geeksforgeeks.org/longest-repeated-subsequence/
Longest Repeating Subsequence
Given a string, print the longest repeating subsequence such that the two subsequence don’t have same string character at same position

// lcs with the same string with a simple extra condition!
int lcs(string s1)
{

  int m = s1.length();
  int n = m;
    
  
  int dp[m+1][n+1];
    
  for(int i=0;i<=m;i++)
  {
      for(int j=0;j<=n;j++)
      {
        if(i==0 || j==0)
            dp[i][j]=0;   //initialization 
            
        else if(s1[i-1]==s2[j-1] && i!=j)  // i!=j is the simple condition, i==j means it is the same charecter we dont want that!
            dp[i][j] = 1 + dp[i-1][j-1];   // if the 2 charecters are same, just add one to lcs of string before them
          
        else
            dp[i][j] = max(dp[i-1][j],dp[i][j-1]);  // take max of other two  
      }
  }
  return dp[m][n];   

}

//Edit distance
int editDistDP(string str1, string str2, int m, int n) 
{ 
    // Create a table to store results of subproblems 
    int dp[m+1][n+1]; 
  
    // Fill d[][] in bottom up manner 
    for (int i=0; i<=m; i++) 
    { 
        for (int j=0; j<=n; j++) 
        { 
            // If first string is empty, only option is to 
            // insert all characters of second string 
            if (i==0) 
                dp[i][j] = j;  // Min. operations = j 
  
            // If second string is empty, only option is to 
            // remove all characters of second string 
            else if (j==0) 
                dp[i][j] = i; // Min. operations = i 
  
            // If last characters are same, ignore last char 
            // and recur for remaining string 
            else if (str1[i-1] == str2[j-1]) 
                dp[i][j] = dp[i-1][j-1]; 
  
            // If the last character is different, consider all 
            // possibilities and find the minimum 
            else
                dp[i][j] = 1 + min(dp[i][j-1], //Insert (in insert we insert in 1st string as the last chars. matched we go to j-1
                                               //        i doesnt change because we didnt remove anything from 1st string   
                                               //       )
                
                                   
                                   dp[i-1][j], //Remove (in remove we remove in 1st string as the last chars. matched we go to i-1
                                               //        j doesnt change because we didnt remove anything from 2nd string   
                                               //       )
                                   
                                   dp[i-1][j-1]);//Replace we just make 1st string last char to 2nd string last char!
        } 
    } 
  
    return dp[m][n]; 
} 


//this is just sum of len of 2 string - longest commmon subsquence
//m,n their lengths
//space optimized
int smallestSuperSequence(char s1[], int m, char s2[], int n) 
{ 
  int dp[2][n+1];
  
  for(int i=0;i<=m;i++)
  {
      for(int j=0;j<=n;j++)
      {
          if(i==0||j==0)
              dp[i%2][j]=0;
              
          else if(s1[i-1]==s2[j-1])
              dp[i%2][j] = 1 + dp[(i-1)%2][j-1];
          
          else
              dp[i%2][j] = max(dp[(i-1)%2][j],dp[i%2][j-1]);
      }
  }
  return (m+n-dp[m%2][n]);  
  
}


// weighted job scheduling
// hackerank
https://www.geeksforgeeks.org/weighted-job-scheduling/

struct Job 
{ 
    ll start, finish, profit; 
}; 

bool myfunction(Job s1, Job s2) 
{ 
    return (s1.finish < s2.finish); // sorting based on finish times!
} 
  
ll binarySearch(Job jobs[], ll index) 
{ 
    ll lo = 0, hi = index - 1; 
  
    while (lo <= hi) 
    { 
        ll mid = (lo + hi) / 2; 
        if (jobs[mid].finish < jobs[index].start) // check this as per condition given in the question
        { 
            if (jobs[mid + 1].finish < jobs[index].start) 
                lo = mid + 1; 
            else
                return mid; 
        } 
        else
            hi = mid - 1; 
    } 
  
    return -1; 
} 
  
ll findMaxProfit(Job arr[], ll n) 
{ 
    sort(arr, arr+n, myfunction);  // sorts the given array based on ending finish times : check myfunction

    ll table[n]; // dp array
    table[0] = arr[0].profit;// initialization 
  
    for (ll i=1; i<n; i++) 
    { 
        ll inclProf = arr[i].profit; 
        ll l = binarySearch(arr, i);  // search for where exactly we can put this job!
        
        if (l != -1) 
            inclProf += table[l];     // if there is a place to put add the value of that!
            
        table[i] = max(inclProf, table[i-1]); // should we include it or not?
    } 
  
    ll result = table[n-1]; 
  
    return result; 
} 


// matrix chain multiplication
// the dp matrix should be initialised with "-1"

ll mcm(int a[],int i,int j,ll dp[101][101])
{
    // one or no matrix : so no cost!
    if(i==j or i==j-1)
     return dp[i][j] = 0;
    
    if(dp[i][j]!=-1)
     return dp[i][j];  // initialisation
     
    ll ans = INT_MAX;
    ll cost;
    
    for(int k=i+1;k<j;k++)
    {
        cost = mcm(a,i,k,dp) + a[i]*a[k]*a[j] + mcm(a,k,j,dp); // left side + "last" multiplication + right side
        ans = min(ans,cost);
    }
    
    return dp[i][j] = ans;
}



ll mcm_init(int a[],int n)
{
  return mcm(a,0,n-1,dp);
}


// palindrome partitioning
ll dp[1001][1001];

bool isPalin(string s,int i,int j)
{
  while(s[i]==s[j] && i<j)
  {
    i++;
    j--;
  }
    
  if(i>j)
    return true;
  if(i == j && (j-i+1) % 2 == 1)
    return true;
  
  return false;  
}

ll mcm(string a,int i,int j,ll dp[1001][1001])
{
    if(dp[i][j]!=-1)
     return dp[i][j];

    if(i==j || isPalin(a,i,j))
     return dp[i][j] = 0;
    
    if(i+1 == j)
     return 1;
    
    ll ans = INT_MAX;
    ll cost;
    
    for(int k=i;k<j;k++)
    {
        cost = mcm(a,i,k,dp) + 1 + mcm(a,k+1,j,dp);
        ans = min(ans,cost);
    }
    
    return dp[i][j] = ans;
}


ll mcm_init(string s,int n)
{
  return mcm(s,0,n-1,dp);
}

https://practice.geeksforgeeks.org/problems/maximize-dot-product/0
//maximise dot product

ll yo(ll a[],int n,ll b[],int m)
{
    ll dp[m+1][n+1];
    memset(dp,0,sizeof(dp));
    
    for(int i=1;i<=m;i++)  // for every element in b! you can only select that index or any index from A, to maintain the order!
      for(int j=i;j<=n;j++)
        dp[i][j] = max(dp[i][j-1],(ll)(b[i-1]*a[j-1])+dp[i-1][j-1]); // including excluding principle
        
    return dp[m][n];    
}


// egg drop puzzle

ll mcm(int f , int e ,ll dp[1001][1001])
{
    if(dp[f][e]!=-1)
     return dp[f][e];

    if(e == 1)
     return dp[f][e] = f;
    
    if(f <= 1)
     return dp[f][e] = f;
    
    ll ans = INT_MAX;
    ll cost;
    
    for(int k=1;k<f;k++)
    {
        cost =1 + max( mcm(k-1,e,dp) , mcm(f-k,e-1,dp) ); // worst case
        ans = min(ans,cost);                              // select best in that
    }
    
    return dp[f][e] = ans;
}

https://www.geeksforgeeks.org/program-nth-catalan-number/
https://www.geeksforgeeks.org/applications-of-catalan-numbers/

int countBST( int n)
{
    int dp[n + 1]; 
    memset(dp,0,sizeof(dp));
    
    dp[0] = 1; 
    dp[1] = 1; 
   
    for (int i = 2; i <= n; i++) 
        for (int j = 0; j <i; j++)  
            dp[i] = ( (dp[i] % N) + ( (dp[i-j-1] % N) * (dp[j] % N) ) % N ) % N; 
        
    return dp[n]; 
}


https://www.sanfoundry.com/dynamic-programming-solutions-boredom-problem/

int solve(int n,vector<int>a)
{
    map<int,int>m;
    
    for(int i=0;i<n;i++)
        m[a[i]]++;
    
    int dp[1001];
    dp[0]=0;
    dp[1]= m[1];
    
    for(int i=2;i<=1000;i++)
       dp[i]  = max(dp[i-2] + m[i]*i , dp[i-1]);
    
    return dp[1000];
}


https://www.geeksforgeeks.org/minimum-number-of-squares-whose-sum-equals-to-given-number-n/
int minCount(int n)
{
  int dp[n+1];
  for(int i=0;i<=n;i++)
      dp[i]=i;
  
  for(int i=4;i<=n;i++)
    for(int j=1;j*j<=i;j++)
        dp[i] = min(dp[i],1+dp[i-j*j]);
    
  return dp[n];  
}


