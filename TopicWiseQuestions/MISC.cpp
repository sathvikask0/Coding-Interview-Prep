
MISC


//sieve proper implementation
void SieveOfEratosthenes(int n) 
{ 
    // Create a boolean array "prime[0..n]" and initialize 
    // all entries it as true. A value in prime[i] will 
    // finally be false if i is Not a prime, else true. 
    bool prime[n+1]; 
    memset(prime, true, sizeof(prime)); 
  
    for (int p=2; p*p<=n; p++) // going only till p*p <=n  because we start i at p*p so no point going more than p*p
    { 
        // If prime[p] is not changed, then it is a prime 
        if (prime[p] == true) 
        { 
            // Update all multiples of p greater than or  
            // equal to the square of it 
            // numbers which are multiple of p and are 
            // less than p^2 are already been marked.  
            for (int i=p*p; i<=n; i += p) 
                prime[i] = false; 
        } 
    } 
  
    // Print all prime numbers 
    for (int p=2; p<=n; p++) 
       if (prime[p]) 
          cout << p << " "; 
} 	  

good que
https://practice.geeksforgeeks.org/problems/sum-of-prime/0

after sieve just do: simple trick!
 for(int i=2;i<n;i++)
    {
      if(p[i] && p[n-i])
       {
           cout <<  i <<" " << n-i;
           return;
       }
    }


//multiplication on string a numbers
// multiplication of a number given as string f and a number given as int 'n' useful for large numbers!
string mul(int n,string f)
{
  string s="";
  int carry=0;
  int prod;
  for(int i=0;i<f.length();i++)
  {
      prod = (f[i]-'0')*n+carry;
      carry =  prod/10;
      s+=to_string(prod%10);
  }
  if(carry)
  {
    string s1 = to_string(carry);
    reverse(s1.begin(),s1.end());
    s+=s1;
  } 
  return s;
}

//LRU Cache implementation
int yo(int a[],int n,int s)
{
  int ans=0;
  set <int> st;
  list <int> lis; //using list
  dq.clear();
  ma.clear();
  for(int i=0;i<n;i++)
  {
    if(st.find(a[i])==st.end())
    {
      if(lis.size()==s)
      {
       int k = lis.back();
       st.erase(k);      
       lis.pop_back();
      }
      st.insert(a[i]);
      ans++;
    }
    else
      lis.remove(a[i]); // this is one of the main operations in list
       
    lis.push_front(a[i]);
  }
  return ans;  
}

//Longest Common Prefix in an Array
// finding the common prefix in the most dissimilar strings!
string yo(string a[],int n)
{
   sort(a,a+n);
   
   int m = min(a[0].length(),a[n-1].length());
   
   string ans="";
   int flag =0;
   for(int i=0;i<m;i++)
   {
       if(a[0][i]==a[n-1][i])
       {
         flag=1;  
         ans+=a[0][i];
       }
       else
         break;
   }
   if(flag)
     return ans;
   
   return "-1";
}

// function to detect bipartite graph
// using the coloring idea - if we can color the graph with 2 coolors then it is bi-partite
https://www.geeksforgeeks.org/bipartite-graph/
bool isBipartite(int dp[][MAX],int n)
{
    queue<int>q;
    q.push(0);
    int vis[n];
    memset(vis,0,sizeof(vis)); //vis==0 indicates not visited
     
    int par,i;
    vis[0]=1;         ///vis =1 is one color , vis=2 the other
    int count=0;
    while(!q.empty() || count<=n)
    {
      if(!q.empty())
      {
        par = q.front();
        q.pop();
        count++;
        
        if(dp[par][par])  //self loop exists then odd cycle exists so not true // same node cannot have 2 colors
          return false;
          
        for(i=0;i<n;i++)
        {
            if(dp[par][i])
            {
               if(!vis[i])
               {
                  vis[i]=vis[par]%2+1;  // giving it 1 or 2 based on the parent 
                  q.push(i);
               }
               else if(vis[i]==vis[par])
                return false;
            }
         }
      }
      else
      {
         for(i=0;i<n;i++)
           if(!vis[i])
             break;
         q.push(i);         
      }
    }
    return true;
            
}

// non repeating charecter in a stream
https://www.geeksforgeeks.org/find-first-non-repeating-character-stream-characters/
void yo(char a[],int n)
{
   queue<char>q;
   int count[26];
   memset(count,0,sizeof(count));
   
   for(int i=0;i<n;i++)
   {
       q.push(a[i]);
       count[a[i]-'a']++;
       
       while(!q.empty())
       {
         if(count[q.front()-'a']==1)
         {
           cout << q.front() << " ";
           break;
         }
         else
           q.pop();
       }
       
       if(q.empty())
         cout << "-1" << " ";
   }
}


//longest arithmetic progressioon
int yo(int a[],int n)
{
    if(n<=2)
      return n;
  unordered_map<int,map<int,int>>dp;
  int d;
  int maxi=2;
 
  for(int i=1;i<n;i++)
  {
      for(int j=0;j<i;j++)
      {
          d= a[i]-a[j];
          if(dp.find(d)==dp.end())
            dp[d][i]=2;
          else
            dp[d][i]=dp[d][j]+1;  // if found at j add one to it
          
          cout << d<<" "<<i <<" "<<dp[d][i]  <<endl; // for understanding it
          
          maxi = max(maxi,dp[d][i]);    
      }
  }
  return maxi;
}

//Maximum Sum Rectangle
#include<bits/stdc++.h>
using namespace std;

int kadane(int a[] , int n)
{
  int max_ending_here =0;
  int max_so_far = INT_MIN;
  
  for(int i=0;i<n;i++)
  {
    max_ending_here += a[i];
    
    if(max_ending_here > max_so_far)
      max_so_far = max_ending_here;
    
    if(max_ending_here <=0)
      max_ending_here =0;  
  }
  
  return max_so_far;
}

int max_rect(int d[][100], int l, int m , int n)
{
  int maxi = INT_MIN;
  int sum[m];
  memset(sum,0,sizeof(sum));
  for(int r=l;r<n;r++)
  {
    for(int i=0;i<m;i++)
     sum[i]+=d[i][r];
     
    int a = kadane(sum,m);
    if(a>maxi)
     maxi = a;  
  }
  
  return maxi;
}

int main() 
{
 int m,n;
 cin >>m>>n;
 
 int d[m][100];
 
 for(int i=0;i<m;i++)
  for(int j=0;j<n;j++)
     cin>>d[i][j];
  
 int maxi = INT_MIN;
 
 for(int i=0;i<n;i++)
 {
   int k = max_rect(d,i,m,n);
   if(k>maxi)
    maxi =k;
 }
        
 cout << maxi << endl;      
}

https://www.geeksforgeeks.org/count-number-of-sub-sequences-with-gcd-1/
    
    ll dp[n][101];
    memset(dp,0,sizeof(dp));
    dp[0][a[0]]=1;
                                                                               
    for(int i=1;i<n;i++)
    {
        dp[i][a[i]]=1;
        for(int j=0;j<i;j++)                       
        {
            if(a[j]<a[i])
            {
                for(int k=1;k<=100;k++)
                {
                    int g = gcd(k,a[i]);  
                    dp[i][g]= (dp[i][g]%N + (dp[j][k]%N))%N;  
                }
            }
        }
    }
    ll ans=0;
    for(int i=0;i<n;i++)
        ans=(ans%N+dp[i][1]%N)%N;


//adjacent bit counts        
ll c(ll n, ll j) 
{ 
    ll dp[n+1][j+1][2];
    memset(dp,0,sizeof(dp));
    
    dp[1][0][0]=1;
    dp[1][0][1]=1;
  
    for(int i=2;i<=n;i++)
    {
        for(int k=0;k<=j;k++)
        {
            
            dp[i][k][0]= (dp[i-1][k][1]%N+dp[i-1][k][0]%N)%N;
            
            if(k>=1)
                dp[i][k][1]= (dp[i-1][k-1][1]%N +dp[i-1][k][0]%N)%N;
                      
            else
                dp[i][k][1]= (dp[i-1][k][0]%N);

        }
    }
    
    return (dp[n][j][0]%N+dp[n][j][1]%N)%N;
}


https://www.hackerearth.com/practice/algorithms/dynamic-programming/introduction-to-dynamic-programming-1/practice-problems/algorithm/roy-and-coin-boxes-1/description/

int main()
{
    ll n,m;
    cin>>n>>m;
    ll st[n+1],ed[n+1];  // this is one of the main ideas
    memset(st,0,sizeof(st));
    memset(ed,0,sizeof(ed));
    
    ll s,e;
    while(m--)
    {
        cin >>s>>e;
        st[s]++;
        ed[e]++;
    }
    ll count[n+1];
    count[1]=st[1];
    for(int i=2;i<=n;i++)
       count[i]=count[i-1]+st[i]-ed[i-1];  //the whole idea which let us solve this ques in linear time // simple observation
    
    ll count1[n+1];
    memset(count1,0,sizeof(count1));
    
    for(int i=1;i<=n;i++)
        count1[count[i]]++;

    for(int i=n-1;i>=1;i--)
        count1[i]+=count1[i+1];

    ll q,q1;
    cin>>q;
    while(q--)
    {
        cin>>q1;
        cout<<count1[q1]<<endl;
    }
        
    return 0;
}


// Alyona and Spreadsheet solution
// with visualization
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,m;
    cin>>n>>m;
    long long int a[n][m];
    
    for(int i=0;i<n;i++)
      for(int j=0;j<m;j++) 
        cin>>a[i][j];
        
    int dp[n][m];  // dp[i][j] means last row in jth column till where the column was sorted! // see the visualization for better use!
    cout << endl;
    for(int i=0;i<m;i++)
      dp[0][i]=1;
     
    for(int i=0;i<m;i++)
      cout << dp[0][i] <<" ";
    cout << endl;  
    
    for(int i=1;i<n;i++)
    {
      for(int j=0;j<m;j++)
      {
        if(a[i][j]>=a[i-1][j])
          dp[i][j]=dp[i-1][j];
        
        else
          dp[i][j]=i+1;
          
        cout << dp[i][j] <<" ";    
      }
      cout << endl;
    }
    cout << endl;
    
    int dp1[n];
    for(int i=0;i<n;i++)
    {
      dp1[i]=INT_MAX;
      for(int j=0;j<m;j++)
      {
        dp1[i]=min(dp1[i],dp[i][j]);
      }
      cout << dp1[i] << " "; 
    }
    cout << endl;
    
   
    int q;
    cin >>q;
    
    while(q--)
    {
      int l,r;
      cin >> l >>r;
      l,r--;
      
      if(dp1[r]<=l)
        cout << "YES" << endl;
      else
        cout << "NO" << endl;
    }   
}
 
 
HackerRank

//hackerank photo album question

vector<int> photo(vector<int>index,vector<int>identity)
{
   list<int>lis;
   list<int>::iterator it;
   vector<int>ans;
   
   int n = index.size();
   
   for(int i=0;i<n;i++)
   {
      it = lis.begin();
      advance(it,index[i]);
      
      lis.insert(identity[i]);
   }
   
   for(it=lis.begin();it!=lis.end();it++)
     ans.push_back(*it);
     
   return ans;  
}


// hackerank marks rank que;

vector<int> awards(int k,vector<int>marks)
{
   sort(marks.begin(),marks.end(),greater<int>());
   
   int i=0;
   int count=0;
   int c=0;
   int curr = -1;
   
   while(i<n)
   {
      if(curr == -1)
      {
        curr = marks[i];
        
        if(curr==0)
           return count;  
      }
      
      while(marks[i] == curr)
      {
        i++;
        c++;
      }
      
      count+=c;
      k-=c;
      
      if(k<=0)
        return count;
      
      c=0;
      curr = -1;
   }
   
   return count;
}

// hackerank identical pairs question

int identicalPairs(vector<int> marks) 
{
    stack <int> s;
    s.push(marks[0]);
    int i = 1;
    int n = marks.size();
    
    for(int i=1;i<n;i++)
    {
        if(!s.empty())
        {
            if(s.top()==marks[i])
                s.pop();
             else
                s.push(marks[i]);   
        }
        else
            s.push(marks[i]);
    }
    
    return s.size();

}

// hacker rank
// longestPalindromicSubsequenceProduct
// max non overlapping palidromes product

int longestPalindromicSubsequenceProduct(string x)
{

 int n = x.size();
 int dp[n][n];
 memset(dp,0,sizeof(dp)); // dp[i][j] - len of the longest palidrome starting from idx i and ending at idx j
 
 for(int i=0;i<n;i++)
     dp[i][i] = 1;
     
 for(int k=1;k<n;k++)  //  (k+1) is the len of palidrome that we are looking at!
 {
    for(int i=0;i<n-k;i++) // i is the starting point of that palidrome
    {
        int j = i + k;      // is the ending point!
        
        if(x[i]==x[j])
           dp[i][j] = 2 + dp[i+1][j-1];
             
        else
           dp[i][j] = max(dp[i][j-1],dp[i+1][j]);
      
    } 
 }
 
 int maxProd = 0;
 
 for(int i=0;i<n;i++)
    for(int j=0;j<n-1;j++)
        maxProd = max(maxProd,dp[i][j]*dp[j+1][n-1]);
        
        
 return maxProd;
}


// biggest square sub matrix  // hackerank
int printMaxSubSquare(vector<vector<int>> M)

{
    int R = M.size();
    int C = M[0].size();
    
	int i,j; 
	int S[R][C]; 
	int val = 1;
	
	for(i = 0; i < R; i++) 
		S[i][0] = M[i][0]; 
	

	for(j = 0; j < C; j++) 
		S[0][j] = M[0][j]; 
		

	for(i = 1; i < R; i++) 
	{ 
		for(j = 1; j < C; j++) 
		{ 
			if(M[i][j] == 1) 
				S[i][j] = 1 + min(S[i][j-1],min(S[i-1][j],S[i-1][j-1]));
			else
				S[i][j] = 0; 
		}
		val = max(val, S[i][j]); 
	}
	
	return val;
} 


//mud walls hackerank
https://fizzbuzzer.com/mud-walls/
		
int maxh(vector<int>pos,vector<int>h)
{
   int n = pos.size();
   int maxi = 0;
   int heightdiff, gaplen,localmax;
   int low,remgap;
   
   for(int i=0;i<n-1;i++)
   {
      if(pos[i+1]-pos[i]>1)
      {
         heightdiff = abs(h[i+1]-h[i]);
         gaplen = pos[i+1]-pos[i]-1;
         
         if(gaplen>heightdiff)
         {
            low = max(h[i+1],h[i])+1;
            remgap = gaplen-heightdiff-1;
            
            localmax = low + remgap/2;
         }
         else
           localmax = min(h[i+1],h[i]) + gaplen;
           
         maxi = max(maxi,localmax);  
      } 
   }
   
   return maxi;
}


//max game score hackerank
// take prime ending with 3 or 1 steps
void sieve(int n,vector<int>&primes3) 
{ 
    bool prime[n+1]; 
    memset(prime, true, sizeof(prime)); 
  
    for (int p=2; p*p<=n; p++) 
    { 
        if (prime[p] == true) 
        { 
            for (int i=p*p; i<=n; i += p) 
                prime[i] = false; 
        } 
    } 
  
    for (int p=2; p<=n; p++) 
       if (prime[p] && p%10 == 3) 
            primes3.push_back(p);
} 

long maxGameScore(vector<int> cell)
{
    int n = cell.size();
    vector<int> primes3;
    primes3.push_back(1);

    sieve(10000,primes3);

    int ans[n];
    memset(ans,0,sizeof(ans));
    ans[0] = cell[0];
    
    for(int i=1;i<n;i++)
    {
        ans[i] = INT_MIN ;
        for(int j =0;j<primes3.size();j++)
        {
            if(i-primes3[j]>=0)
                ans[i] = max(ans[i],cell[i]+ans[i-primes3[j]]);
            else
                break;    
        }
    }

    return ans[n-1];
}

// 'calculateTotalRegion' // hackerank

void fillr(int rmin[],int n,vector<int>h)
{
    stack<pair<int,int>> st;
    rmin[n-1] = n-1;
    st.push(make_pair(h[n-1],n-1));

    for(int i=n-2; i>=0; i--)
    {
        while(!st.empty() && h[i] >= st.top().first) 
            st.pop();

        if(st.empty())
        {
         rmin[i] = n-1;
         st.push(make_pair(h[i],i));
        }

        else 
          rmin[i] = st.top().second-1;

        if(h[i] != st.top().first) 
           st.push(make_pair(h[i],i)); 
    }
}

void filll(int lmin[],int n,vector<int>h)
{
   stack<pair<int,int>> st;
   lmin[0] = 0;
   
   st.push(make_pair(h[0],0));

   for(int i=1; i<n; i++)
   {
        while(!st.empty() && h[i] >= st.top().first) 
            st.pop();
            
        if(st.empty()) 
        {
          lmin[i] = 0;
          st.push(make_pair(h[i],i));
        }

        else
          lmin[i] = st.top().second+1;

        if(h[i] != st.top().first) 
           st.push(make_pair(h[i],i)); 
    }
}

long count(int rmin[],int lmin[],int n)
{
    long count = 0;
    
    for(int i=0; i<n; i++)
        count += rmin[i]-lmin[i]+1;
    
    return count;
}
long calculateTotalRegion(vector<int> h) 
{
    int n = h.size();
    int rmin[n];
    int lmin[n];
    fillr(rmin,n,h);
    filll(lmin,n,h);
    return count(rmin,lmin,n); 
}
 
 
//friends liking que // hackerank
// Interest sharing problem. Find maximal product of nodes in the group sharing maximum number of interests.


   int adj[101][101] = {0}; // initialization
  
   int n =  friends_from.size();
   for(int i =0;i<n;i++)
   {
       adj[friends_from[i]][friends_to[i]] ++;
       adj[friends_to[i]][friends_from[i]] ++;
    }

    int max_ans = -1;;
    int max_likings = -1;

    for(int i =1;i<=friends_nodes;i++)
    {
        for(int j =i+1;j<=friends_nodes;j++)
        {
            if(adj[i][j]>max_likings)
            {
                max_ans = i*j;
                max_likings = adj[i][j];
           }
           else if(adj[i][j]==max_likings)
           {
               if(i*j > max_ans)
                max_ans = i*j;
           }

        }
    }

   return max_ans


//hackerank flasks que

3. A shopkeeper has to given serve certain number of requirements of the customer. A customer will be satisfied if he gets at least the amount he ordered. Given m flasks from which only one can be used to measure the quantity and serve the customers. Given order quantity array and different markings of different flask. Find the index flask with which loss of shopkeeper is minimum.

eg : Order - [4 6] , flask 1 = [5 10] , flask2 = [5 7]...Loss1 = 5 - 4 + 10 - 6 = 5 , loss2 = 5 - 4 + 7 - 6 = 2.So flask 2 is best option.

Constraints(n <= 10^5 , m < 10^3 , number of all markings for all flask < 10^4).
        
        
long long loss(vector<int> req,vector<int> curr)
{
    long long int l = 0;
    int n = req.size();
    int m = curr.size();
    for(int i=0;i<n;i++)
    {
        int ind = lower_bound(curr.begin(),curr.end(),req[i])-curr.begin();
        if(ind<m)
          l += curr[ind] - req[i];
        else
          return LONG_MAX; 
    }
    return l;
}
int chooseFlask(vector<int> req, int m, vector<vector<int>> markings) 
{
    sort(req.begin(),req.end(),greater<int>());
    long long int mini=LONG_MAX;
    int min_index = -1;
    int n = markings.size();     
    vector<int>curr;
    int j=0;
    long long int curr_loss;

    for(int i=0;i<n;i++)
    {
       if(markings[i][0]==j)
         curr.push_back(markings[i][1]);
       
       else
       {
         curr_loss = loss(req,curr); 
         if(curr_loss<mini)
        {
           mini = curr_loss;
           min_index = j;
        }

        cout << curr_loss << endl;
        j++;
        curr.clear();
        curr.push_back(markings[i][1]);
       }
     }
        curr_loss = loss(req,curr); 
                cout << curr_loss << endl;

         if(curr_loss<mini)
        {
           mini = curr_loss;
           min_index = j;
        }
     
     if(mini!=LONG_MAX)
       return min_index;
       
     return -1;
}


//hackerank ques // delete triplets to make max distinct elements

//if odd count then lit - they cancel among themselves
//if even count, and even number of even counts then no need
//if odd number of even count - you will get to distinct - 1;

int dis(vector<int>arr)
{
  int n = arr.size();
  int count[100001];
  memset(count,0,sizeof(count));
  
  int evecount=0;
  
  int dis;
  
  for(int i=0;i<n;i++)
  {
   if(count[arr[i]==0)
     dis++;
     
    count[arr[i]]++;
  }
    
  for(int i=1;i<100001;i++)
    if(count[i]>0 && count[i]%2==0)
       evecount++;
       
  if(evecount % 2 ==0)
    return dis;
    
  return dis -1;        
}


https://www.geeksforgeeks.org/print-maximum-sum-square-sub-matrix-of-given-size/

//hackerank max submatrix binary search

int yo(vector<vector<int>> grid,int mid)
{
    int n = grid.size();

    vector<vector<int>>ss(n,vector<int>(n));
  
    for (int j=0; j<n; j++) 
    {
        int s= 0; 
        for (int i=0; i<mid; i++)
            s+= grid[i][j];

        ss[0][j] = s; 
  
        for (int i=1; i<n-mid+1; i++) 
        { 
            s += (grid[i+mid-1][j] - grid[i-1][j]); 
            ss[i][j] = s; 
        } 
    } 
 
    int max_sum = INT_MIN;
  
    for (int i=0; i<n-mid+1; i++) 
    {
        int s = 0; 
        for (int j = 0; j<mid; j++) 
            s += ss[i][j]; 
  
        max_sum = max(max_sum,s);


        for (int j=1; j<n-mid+1; j++) 
        { 
            s += (ss[i][j+mid-1] - ss[i][j-1]); 
            
            max_sum = max(max_sum,s);
        } 
    }

    return max_sum;
 
}

int largestSubgrid(vector<vector<int>> grid, int max_s) 
{
    int n = grid.size();

    int l = 1;
    int h = n;
    int mid;

    int ans1;
    while(l<=h)
    {
        mid = (l+h)/2;

        int ans = yo(grid,mid);
        if(ans<=max_s)
        {
          l = mid+1;
          ans1 = mid;
        } 
        else
          h = mid-1;  
    } 
    return ans1;
}

//hackerank
//predators problem - (JUNGLE BOOK - NFRENCE LABS IIT M) 
int pred(vector<int>arr)
{
  vector<int>roots;
  
  int m = arr.size();
  vector<int>dp[m];
  
  for(int i=0;i<m;i++)
  {
     if(arr[i]==-1)
       roots.push_back(i);
     
     else
       dp[arr[i]].push_back(i);  
  }
  
  queue<int>q;
  int n;
  int f;
  int max_level = 0,level;
  int vis[m];
  
  for(auto root : roots)
  {
     q.push(root);
     level = 0;
     while(!q.empty())
     {
       n = q.size();
       
       for(int i=0;i<n;i++)
       {
          f = q.front();
          q.pop();
          vis[f]=1;
          
          for(auto j : dp[f])
            q.push(j);   
       }
       
       level++;
     }
          
     max_level = max(level,max_level);
  }
  
  return max_level; 
}


https://www.geeksforgeeks.org/count-substrings-that-contain-all-vowels-set-2/

int countSubstringsUtil(string s) 
{ 
    int count = 0; 
  
    // Map is used to store count of each vowel 
    unordered_map<char, int> mp; 
  
    int n = s.length(); 
  
    // Start index is set to 0 initially 
    int start = 0; 
  
    for (int i = 0; i < n; i++) 
    { 
        mp[s[i]]++; 
  
        // If substring till now have all vowels 
        // atleast once increment start index until 
        // there are all vowels present between 
        // (start, i) and add n - i each time 
        while (mp['a'] > 0 && mp['e'] > 0 && mp['i'] > 0 && mp['o'] > 0 && mp['u'] > 0) 
        { 
            count += n - i; 
            mp[s[start]]--; 
            start++; 
        } 
    } 
  
    return count; 
} 
   
// hackerank   
// Function to extract all maximum length 
// sub-strings in s that contain only vowels 
// and then calls the countSubstringsUtil() to find 
// the count of valid sub-strings in that string 
int countSubstrings(string s) 
{ 
    int count = 0; 
    string temp = ""; 
  
    for (int i = 0; i < s.length(); i++) { 
  
        // If current character is a vowel then 
        // append it to the temp string 
        if (isVowel(s[i])) { 
            temp += s[i]; 
        } 
  
        // The sub-string containing all vowels ends here 
        else { 
  
            // If there was a valid sub-string 
            if (temp.length() > 0) 
                count += countSubstringsUtil(temp); 
  
            // Reset temp string 
            temp = ""; 
        } 
    } 
  
    // For the last valid sub-string 
    if (temp.length() > 0) 
        count += countSubstringsUtil(temp); 
  
    return count; 
    
    
//choclate que

int find(dp[100][100][100],int c,int n)
{
   for(int i=0;i<n;i++)
     for(int j =0;j<n;j++)
        if(dp[i][j])
           return i;
}

pair<int,int> yo(dp[100][100][100],int c,int n)
{
      queue<int>q;
      
      int s = find(dp,c,n);
      
      q.push(s);
      
      int v[n];
      memset(v,0,sizeof(v));
      
      int count=0;  
      long long max1 = -1,max2=-1;

      while(!q.empty())
      { 
          int e = q.front();
          q.pop();
          v[e]=1;
          count++; 
              
          if(max1<e)
          {
            max2 = max1;
            max1 = e;
          }
              
          else if(max2<e)
            max2 = e;
                
                 
          for(int i=0;i<n;i++)
          {    
             if(dp[e][i][c] && !v[i])
             {   
                v[i]=1;
                q.push(i);
             }
          }     
      }
      
      int ans = (max2+1)*(max1+1);
      return make_pair(ans,count);
}

int choc(int f,vector<int>from,vector<int>to,vector<int>c)
{
  int dp[100][100][100];
  memset(dp,0,sizeof(dp);
  
  int n = from.size();
  
  unordered_set<int>s;
  for(int i=0;i<n;i++)
  {
    dp[from[i]-1][to[i]-1][c[i]-1]=1;
    dp[to[i]-1][from[i]-1][c[i]-1]=1;
    s.insert(c[i]-1);
  }
  
  int max_c = -1;
  int max_ans = 0;
  for(auto i : s)
  {
    pair<int,int> ans = yo(dp,i,f);
    
    if(max_c < ans.second)
    {
      max_c = ans.second;
      max_ans = ans.first;
    }
    else if(max_c == ans.second)
      max_ans = max(max_ans,ans.first);
  }
  
  return max_ans;
}