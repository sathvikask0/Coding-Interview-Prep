
  GRAPHS;

//adjacency list

      int n,m;
      cin>>n>>m;
      vector<int>vec[n];
      int f,s2;

      for(int i=0;i<m;i++)  
      {
          cin>>f>>s2;
          vec[f].push_back(s2);
          vec[s2].push_back(f);
      }
      

//BFS
int main() {

    // vertices , edges
    int n, e;
    cin >> n >> e;
    
    //adjacency matrix
    int dp[n][n];
    
    memset(dp,0,sizeof(dp));
    
    //taking edges as input
    int f,s;
    for(int i=0;i<e;i++)
    {
        cin>>f>>s;
        dp[f][s] = 1;
        dp[s][f] = 1;   
    }
    
    //visited array
    int v[n];
    memset(v,0,sizeof(v));
    
    queue <int> q;
    q.push(0);
    
    while(!q.empty())
    {
        int i= q.front();
        cout << i << " ";
        q.pop();	
        v[i]=1;
        for(int j=0;j<n;j++)
        {
         if(dp[i][j] && !v[j])
         {
            v[j]=1;
            q.push(j);   // mark it visited and push it into the queue!  
         }
        }
    }
    
    return 0;
}

//recursive DFS
void DFS(int dp[][100],int n,int v[],int f)
{
  v[f]=1;
  cout << f << " ";
  for(int i=0;i<n;i++)
    if(dp[i][f] && !v[i]) 
        DFS(dp,n,v,i); 
  return;               
}

// word search on board 
https://www.interviewbit.com/problems/word-search-board/
bool  isvalid(vector<string> &a, int i,int j,string s,int ind,int l,int n,int m)
{
  return (i>=0 && i<n && j>=0 && j<m && a[i][j]==s[ind]);   
}
int dfs(vector<string> &a, int i,int j,string s,int ind,int l,int n,int m)
{
    if(ind == l)
       return 1;
    
    int x[] = {1,0,-1,0};
    int y[] = {0,-1,0,1};
    int x1,y1;
    
    for(int k=0;k<4;k++)
    {
        x1 = i + x[k];
        y1 = j + y[k];
        
        if(isvalid(a,x1,y1,s,ind,l,n,m))
          if(dfs(a,x1,y1,s,ind+1,l,n,m))
                return 1;       
    }
    return 0;
}
int Solution::exist(vector<string> &a, string s) 
{
    int n = a.size();
    int m = a[0].size();
    int l = s.length();
    
    /*
       as same letter can be used more than once, there is no need for vis. array.
       start dfs from the starting letter and explore from there
       if found return true;
    */
    for(int i=0;i<n;i++)
    {
       for(int j=0;j<m;j++)
       {
           if(a[i][j]==s[0])
           {
               if(dfs(a,i,j,s,1,l,n,m)) 
                   return 1;
           }
       }
    }
    return 0;
}


//get path DFS
// HERE THE IMPORTANT PART IS SENDING REFERENCE TO QUE!
void DFS(int dp[][1000],int n,int v[],int f,int s,queue<int>&q) //SEE & usage. you have to send it as & when sending to a function
{ 
  if(f==s)
  {
   q.push(s); 
   return;
  }
  
  v[f]=1;
  for(int i=0;i<n;i++)
  {
    if(dp[i][f] && !v[i])
    {    
      DFS(dp,n,v,i,s,q);
      if(!q.empty())
      {
       if(i==q.back())
       { 
        q.push(f);
        return;
       } 
      }
    }    
  }
}

//DFS application
https://www.interviewbit.com/problems/black-shapes/
bool isvalid(vector<string> &s,int i,int j,vector<vector<int>>&vis,int n,int m)
{
    return (i>=0 && i<n && j>=0 && j<m && !vis[i][j] && s[i][j]=='X');
}
void dfs(vector<string> &s,int i,int j,vector<vector<int>>&vis,int n,int m)
{
    vis[i][j]=1;
    
    int x[] = {1,0,-1,0};
    int y[] = {0,-1,0,1};
    int x1,y1;
    for(int k=0;k<4;k++)
    {
        x1 = i + x[k];
        y1 = j + y[k];
        
        if(isvalid(s,x1,y1,vis,n,m))
          dfs(s,x1,y1,vis,n,m);
    }
    return;
}
int Solution::black(vector<string> &s) 
{
    int n = s.size();
    int m = s[0].size();
    
    int count=0;
    vector<vector<int>>vis(n, vector<int> (m));
    
    /* 
       start at every 'X' which is not visited and start dfs from there!
       in the end you will get all the connected components corresponding to 'X', that is the required ans.
    */
    for(int i=0;i<n;i++)
    {
       for(int j=0;j<m;j++)
       {
           if(s[i][j]=='X' && !vis[i][j]) 
           {
               dfs(s,i,j,vis,n,m);
               count++;
           }
       }
    }
    return count;
}

//DFS application
https://www.interviewbit.com/problems/capture-regions-on-board/

bool valid(int i, int j, int r, int c)
{
    return (i>=0 && i<r && j>=0 && j<c);
}

void dfs(int i, int j, int r, int c, vector<vector<char> > &A)
{
    A[i][j] = '-'; // visited ones are marked like this!
    
    int x[] = {1,0,-1,0};
    int y[] = {0,-1,0,1};
    int x1,y1;
    
    for(int k=0;k<4;k++)
    {
        x1 = i + x[k];
        y1 = j + y[k];
        
        if(valid(x1,y1,r,c) && A[x1][y1] =='O')
          dfs(x1,y1,r,c,A);
    }
 
    return;
}

void Solution::solve(vector<vector<char> > &A) {
  
    int r = A.size();
    int c = A[0].size();
    /*
      apply dfs/bfs from the boundary "O" 
      whatever "O"s are not reached by this are internal "O"s
      they should be replaced by "X"s
    */
    
    // first and last rows
    for(int i=0; i<c; i++)
    {
        if(A[0][i] == 'O')
            dfs(0,i,r,c,A);
        if(A[r-1][i] == 'O')
            dfs(r-1,i,r,c,A);
    }
    
    // first and last columns
    for(int i=1; i<r-1; i++)
    {
        if(A[i][0] == 'O')
            dfs(i,0,r,c,A);
        if(A[i][c-1] == 'O')
            dfs(i,c-1,r,c,A);
    }
    
    int count=0;
    for(int i=0; i<r; i++)
    {
        for(int j=0; j<c; j++)
        {
            if(A[i][j] == '-')
                A[i][j] = 'O';
                
            else
            {   
                if(A[i][j]=='O')
                  count++;       // number of internal "O"s
                  
                A[i][j] = 'X';   // they become "X"s
            }
        }
    }
    
    //cout << count << endl; // to print internal "O"s
    
    return;
}


//Detect cycle in a directed graph
bool dfs(int n,int i,vector<int>dp[],int vis[],int st[])
{
    vis[i]=1;
    st[i]=1;
    
    for(auto j:dp[i])
    {
        if(st[j])
          return true;
        
        if(!vis[j] && dfs(n,j,dp,vis,st))
          return true;
    }
    st[i]=0;
    return false;
}
bool isCyclic(int n, vector<int> dp[])
{
    int vis[n] = {0};   // visited array
    int st[n]  = {0};  // recursion stack

    for(int i=0;i<n;i++)
    {
      if(!vis[i])    
         if(dfs(n,i,dp,vis,st))
            return true;
    }
    return false;
}


https://practice.geeksforgeeks.org/problems/circle-of-strings/0
// very good example of when to use bfs and when dfs!
// look at it and think why did u do dfs and not bfs
bool dfs(vector<int>vec[],int s,int n,int c,int v[])
{
  v[s]=1;
  c++;
  
  
  for(auto j : vec[s])
  {
     if(!v[j] && j!=s)
     {
       if(dfs(vec,j,n,c,v))
          return true;
     }
     if(v[j] && j!=s && c==n)
       return true;
  }        
   
   return false;       
}

int yo(string a[],int n)
{ 
  if(n==1)
  {
    if(a[0][0]==a[0][a[0].length()-1])
    return 1;
    return 0;
  } 
  vector<int>vec[n];
  
  unordered_map<char,vector<int>>s;
  unordered_map<char,vector<int>>e;
  
  for(int i=0;i<n;i++)
  {
    int k = a[i].length();
    
    if(e.find(a[i][0])!=e.end())
      for(auto j : e[a[i][0]])
        vec[j].push_back(i);
        
      s[a[i][0]].push_back(i);
      
    if(s.find(a[i][k-1])!=s.end())
      for(auto j : s[a[i][k-1]])
        vec[i].push_back(j);
        
      e[a[i][k-1]].push_back(i);       
  }
  int v[n];
  memset(v,0,sizeof(v));
  if(dfs(vec,0,n,0,v))
    return 1;
  return 0;     
}



// topological sort : DFS application
// alien dictionary
void addegde(string s1,string s2,vector<int>dp[])
{
    int n = s1.length();
    int m = s2.length();
    
    for(int i=0;i<min(n,m);i++)
     if(s1[i]!=s2[i])
     {
         dp[s1[i]-'a'].push_back(s2[i]-'a'); // adding a directed edge between the letters indicating an order
         return;
     }
}

void dfs(int s,vector<int> dp[],stack<int>&st,int vis[])
{
    vis[s]=1;
    for(auto j : dp[s])
      if(!vis[j])
        dfs(j,dp,st,vis); //explore all children
    
    st.push(s);   // if none of them are left, push it into the stack
    return;
}

string printOrder(string dict[], int n, int k)
{
   vector<int>dp[k];
   string s="";

   for(int i=0;i<n-1;i++)
     addegde(dict[i],dict[i+1],dp);
   
   int vis[k];
   memset(vis,0,sizeof(vis));
   stack<int>st;
   for(int i=0;i<k;i++)
       if(!vis[i])
          dfs(i,dp,st,vis);  // explore unvisited vertices
    
    while(!st.empty())
    {
        s+=(st.top()+'a');
        st.pop();
    }
    return s;
}

//krushkal's algo
//union find algo
#include <bits/stdc++.h>
using namespace std;

struct edges
{
  int v1,v2,w;    
};

bool customsort(edges a, edges b)
{
    return (a.w<b.w);
}

int rep(int v , int p[])// return top most parent of the node
{
  while(p[v]!=v)
  {
    v = p[v];  
  }
  return v;  
}

int main()
{
  int n,e;
  cin>>n>>e;
    
  edges a[e];
  for(int i=0;i<e;i++)
      cin >> a[i].v1 >> a[i].v2 >> a[i].w;
   
  sort(a,a+e,customsort);
  
  int p[n];
  for(int i=0;i<n;i++) //intially are nodes are parents of themselves! all of them are in different components!
      p[i]=i;
  
  int count=0;
  int i=0;
  cout << endl;
  while(count < (n-1))
  {
    int p1 = rep(a[i].v1,p); // returns top most parent of the node
    int p2 = rep(a[i].v2,p);
    if(p1!=p2)               // if not same means that they are form different components!
    {
       if(a[i].v1 < a[i].v2)
          cout << a[i].v1 << " " << a[i].v2 << " " << a[i].w << endl;
       else
          cout << a[i].v2 << " " << a[i].v1 << " " << a[i].w << endl;   
       
       //making parent same for both the vertices
       p[p1] = p2;
       count++;
    }
    i++;
  }
  return 0;
}


//kruskal algo's application
// finish courses given prerequisites
https://www.interviewbit.com/problems/possibility-of-finishing-all-courses-given-prerequisites/
int top(int v,int p[])
{
    while(v!=p[v])
     v = p[v];
    return v; 
}
int Solution::solve(int n, vector<int> &b, vector<int> &c) 
{
    int m = b.size();
    
    if(m>=n)
      return 0;
    
    int p[n];
    for(int i=0;i<n;i++)
      p[i]=i;
      
    /*
       basically, the main idea here is to think when is it not possible to complete the courses!
       if you think about it, it is not possible to complete the prereq only when all the courses are in a cycle
       
       if there was a cycle in graph with all the courses, you can never complete all the courses!
       so we use the kruskal idea, to find if the added edge formed a cycle or not. 
    */  
    
    int p1,p2;  
    for(int i=0;i<m;i++)
    {
       p1 = top(b[i]-1,p);
       p2 = top(c[i]-1,p);
       
       if(p1==p2)
          return 0;
        
       p[p1]=p2;      
    }
    return 1;
}


//prims's algo
// see this once. Not so obvious.
#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n,e;
  cin>>n>>e;
    
  int dp[n][n];
  memset(dp,0,sizeof(dp));
  int v1,v2,w;  
  for(int i=0;i<e;i++)
  {
    cin>>v1>>v2>>w;
    dp[v1][v2]=w;
    dp[v2][v1]=w; 
  }    
   
  int p[n];
  p[0]= -1;
    
  int we[n];
  we[0]=0;  
  for(int i=1;i<n;i++)
      we[i] = INT_MAX;
  
  int v[n];
  memset(v,0,sizeof(v));
    
  int min1,min1_index;  
    
  for(int i=0;i<n-1;i++)
  {
    min1=INT_MAX;
    min1_index = -1;  
      
    for(int i=0;i<n;i++) 
    {    
        if(we[i]<min1 && !v[i])
        {   
            min1 = we[i];
            min1_index = i;
        }
    }
      
    v[min1_index]=1; 
      
    for(int j=0;j<n;j++)
    {
        if(dp[min1_index][j]!=0 && !v[j])
        {
            if(dp[min1_index][j]<we[j])
            {   
                we[j] = dp[min1_index][j];
                p[j]= min1_index;
            } 
        }            
    } 
  } 
   
  for(int i=1;i<n;i++)
  {
      if(p[i]>i)
          cout << i << " " << p[i] << " " << we[i]<< endl;
      else
          cout << p[i] << " " << i << " " << we[i]<< endl;
  }
    
    
}    


//Dijkstra's Algorithm
//very similar to prim's algo!
#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n,e;
  cin>>n>>e;
    
  int dp[n][n];
  memset(dp,0,sizeof(dp));
  int v1,v2,w;  
  
  for(int i=0;i<e;i++)
  {
    cin>>v1>>v2>>w;
    dp[v1][v2]=w;
    dp[v2][v1]=w; 
  }    
   
  //distance array!
   
  int dis[n];
  dis[0]=0;   // source point 
  
  for(int i=1;i<n;i++)
      dis[i] = INT_MAX;
    
  int v[n];
  memset(v,0,sizeof(v));
    
  int min1,min1_index;  
    
  for(int i=0;i<n;i++)
  {
    min1=INT_MAX;
    min1_index = -1;  
      
    for(int k=0;k<n;k++)
    {    
        if(dis[k]<min1 && !v[k])
        {   
            min1 = dis[k];	
            min1_index = k;
        }
    }
      
    v[min1_index]=1; 
      
    for(int j=0;j<n;j++)
        if(dp[min1_index][j]!=0 && !v[j])
            if(dp[min1_index][j] + dis[min1_index] <dis[j])
                dis[j] = dp[min1_index][j] + dis[min1_index]; 
  } 
   
  for(int i=0;i<n;i++)
     cout << i << " " << dis[i] << endl;
    
}


https://practice.geeksforgeeks.org/problems/minimum-cost-path/0

void djk(vector<vector<int>>&dp,int i,int j,int n,int m,vector<vector<int>>&vis,vector<vector<int>>&dis)
{   
    vis[i][j]=1;
    
    int x[]={1,0,-1,0};
    int y[]={0,-1,0,1};
    int x1,y1;
    
    for(int k=0;k<4;k++)
    {
        x1 = i+x[k];
        y1 = j+y[k];

        if(x1>=0 && x1<n && y1>=0 && y1<m && !vis[x1][y1])  // visiting the adjacent nodes and marking them as visited 
           dis[x1][y1] = min(dis[x1][y1],dis[i][j]+dp[x1][y1]);  // updating their distance if condition is satified
    }     
}
{	  
	  dis[0][0]=dp[0][0]; //initialization of the distance metric
	   
	   pair<int,int>p;
	   for(int i=0;i<n;i++)
       {
	     for(int j=0;j<n;j++)
	     { 
	        p=getmin(dis,vis,n); // getting the min distance of the vertex which is not yet visited
	        djk(dp,p.first,p.second,n,n,vis,dis);  // updates the distances from the min_dis 
	     }
	   }
	   
	   cout << dis[n-1][n-1] << endl;   
} 

//Knight in a chess board problem
// BFS ! Shortest path
int Solution::knight(int n, int m, int s1, int s2, int e1, int e2) 
{
    
     vector<vector<int>>vis(n+1, vector<int> (m+1));    
  
      // possible steps knight can take!
      int x[] = {2,2,1,-1,-2,-2,-1,1};
      int y[] = {1,-1,-2,-2,-1,1,2,2};
      queue<pair<int,int>>q;
      q.push(make_pair(s1,s2));
      
      int ans =0;
      vector<pair<int,int>>v;
      int n1,x1,y1,x2,y2;
      
      while(!q.empty())
      {
         n1 = q.size();
         for(int i=0;i<n1;i++)
         {
             x1 = q.front().first;
             y1 = q.front().second;
             
             v.push_back(x1,y1);
             
             if(x1 == e1 && y1 == e2)
                return ans;
                
             q.pop();
             vis[x1][y1]=1;
             
             // going through all the children nodes!
             // you do not need to create the graph because you know it already
             // you know what vertex is connected to what!
             
             for(int k=0;k<8;k++)
             {
                 x2 = x1 + x[k];
                 y2 = y1 + y[k];
                 
                 if(x2>=1 && x2<=n && y2>=1 && y2<=m && !vis[x2][y2])
                 {
                     vis[x2][y2]=1;
                     q.push(make_pair(x2,y2));
                 }
             }
         }
         ans++;
      }
      return -1;
}

Smallest sequence with given Primes
https://www.interviewbit.com/problems/smallest-sequence-with-given-primes/
vector<int> Solution::solve(int A, int B, int C, int D) 
{
    vector<int> numbers;
    
    if(D==0)
        return numbers;
        
    /*
       if you observe closely, this is like BFS which is implemented by a queue!
       the main difference here comes because of the "sorted" sequence issue.
       set is very useful in this context, so that we can remove elements and add new elements while keeping everything sorted.
       that is why we changed from queue to set. But observe that, else it's the same thing.
    */    
    
    set<int> st;
    st.insert(A);
    st.insert(B);
    st.insert(C);
    
    while(!st.empty()) 
    {
        int curr = *st.begin();
        st.erase(st.begin());
        numbers.push_back(curr);
        if(numbers.size()==D)
            break;
        int p1 = curr*A;
        int p2 = curr*B;
        int p3 = curr*C;
        st.insert(p1);
        st.insert(p2);
        st.insert(p3);
    }
    return numbers;
}

Word Ladder I
BFS Application + crazy optimization
https://www.interviewbit.com/problems/word-ladder-i/
int Solution::solve(string beginWord, string endWord, vector<string> &C) 
{
    
    unordered_set<string> wordList;
    for(auto s : C)
      wordList.insert(s);
    
    wordList.insert(beginWord);
    unordered_map<string,vector<string>>gr;
  
    // crazy optimisation
    for(auto s1 : wordList)
    {
     int m = s1.length();
     string s2 = s1;
     for(int i=0;i<m;i++)
     {
       s1 = s2;
       for(int j=0;j<26;j++) // replace each of the letters with a random letter from 'a' - 'z'
       {
         s1[i] = 'a' + j;
         if(s1!=s2 && wordList.find(s1)!=wordList.end()) // search if its there
           gr[s2].push_back(s1);  // add it to the adjacency list
       }
     }
    } 
  
   queue<string>q;
   unordered_set<string>vis;
  
   q.push(beginWord);
   int count = 1;
  
   while(!q.empty())
   {
     int q_size = q.size();
     
     for(int j=0;j<q_size;j++)
     {
       
       string t = q.front();
       if(t == endWord)
         return count;

       q.pop();
       vis.insert(t);

       for(auto i : gr[t])
       {
         if(vis.find(i)==vis.end())
         {
           vis.insert(i);
           q.push(i);
         }
       }
     }
     count++;
     
   }
  
  return count;
}

https://practice.geeksforgeeks.org/problems/rotten-oranges/0
// very good que!!
// bfs!
// see this once again -- very good que
int main() {
	int t;
	cin>>t;
	while(t--)
	{
	  int n,m;
	  cin>>n>>m;
	  
	  vector<vector<int>>dp(n, vector<int> (m));
      vector<vector<int>>vis(n, vector<int> (m));
      
      queue<pair<int,int>>q;
      int count=0;
      for(int i=0;i<n;i++)
      {
	    for(int j=0;j<m;j++)
	    {
	      cin>>dp[i][j];
	      if(dp[i][j]==2)
	        q.push(make_pair(i,j));  // for bfs! bfs is the only way as time constraint is given! if we have to go day by day bfs only!
	        
	       if(dp[i][j]==1)
	         count++; 
	    }
	  }  

	   int ans = 0;
	    
	   int x[]={1,0,-1,0};
       int y[]={0,-1,0,1};
       int x1,y1;  
	   int n1;
	      
	   int i,j;   
	   while(!q.empty() && count>0)
	   {
	    
	     int n1 = q.size();  // presently in the queue all of them will rot their adjacent ones today!
	     for(int l=0;l<n1;l++)
	     { 
	        i = q.front().first;
	        j = q.front().second;
	        vis[i][j]=1;
	        q.pop();
	        for(int k=0;k<4;k++)
            {
              x1 = i+x[k];
              y1 = j+y[k];
            
              if(x1>=0 && x1<n && y1>=0 && y1<m && dp[x1][y1]==1 && !vis[x1][y1])
              {
               dp[x1][y1]=2;
               count--;
               q.push(make_pair(x1,y1));
               vis[x1][y1]=1;
              }
	        }   
	     }
	     ans++;
	  }
	  if(count<=0)
	    cout << ans << endl;
	  else
	    cout << "-1" << endl;
	  
	}   
	return 0;
}


https://practice.geeksforgeeks.org/problems/negative-weight-cycle/0
//bellman ford algorithm
// single source shortest path!

struct edge
{
  int v1,v2,w;
};

int main() 
{
    int t;
    cin>>t;
    while(t--)
    {
     int n,e;
     cin>>n>>e;
    
     int v1,v2,w;
     edge a[e];
     
     for(int i=0;i<e;i++)
         cin>>a[i].v1>>a[i].v2>>a[i].w;
         
     
     int dis[n]; // this will finally contain all distances from source '0'
     for(int i=0;i<n;i++)
       dis[i]=INT_MAX;
     
     dis[0]=0;  
     
     int flag = 0;
     for(int i=0;i<n;i++)
     {
        for(int j=0;j<e;j++)
        {
            v1 = a[j].v1;
            v2 = a[j].v2;
            
            if(dis[v2]>dis[v1]+a[j].w)
            {
                dis[v2]=dis[v1]+a[j].w;
                if(i==n-1)
                {
                   flag = 1;
                   cout << 1 << endl;  // detecting negative cycle
                   break;
                }
            }
        }
        if(flag)
         break;
     }
     if(!flag)
      cout << 0 << endl;
     
    }
	return 0;
}



//floyd warshall
https://www.geeksforgeeks.org/floyd-warshall-algorithm-dp-16/
input dis matrix! 

which initially is the adjacency matrix itself, we modify it accordingly as shown below:

dis[i][j]  - will have shortest path from i-j

      for(int k=0;k<n;k++)
        for(int i=0;i<n;i++)
          for(int j=0;j<n;j++)
             if(dis[i][j] > dis[i][k] + dis[k][j]) // is direct distance greater than going from a intermediate path?
               dis[i][j] = dis[i][k] + dis[k][j];
  


https://www.youtube.com/watch?v=RpgcYiky7uw
//Strongly Connected Components (Kosaraju's Algo) 

void dfs(int i,vector<int> dp[],int vis[],stack<int>&s)
{
    vis[i]=1;
    for(auto j : dp[i])
      if(!vis[j])
        dfs(j,dp,vis,s);
    
    s.push(i); // if explored completely push into stack   
}

void dfs2(int i,vector<int> dp[],int vis[])
{
    vis[i]=1;
    for(auto j : dp[i])
      if(!vis[j])
        dfs2(j,dp,vis);  //normal dfs
}

int kosaraju(int n, vector<int> dp[])
{
    stack<int>s;
    int vis[n];
    memset(vis,0,sizeof(vis));
    
    for(int i=0;i<n;i++)
    {
        if(!vis[i])
          dfs(i,dp,vis,s);
    }
    
    vector<int>rev_dp[n];
    for(int i=0;i<n;i++)
    {
       for(auto j:dp[i])
         rev_dp[j].push_back(i);  //reversing the given the adjacency list
    }
    
    memset(vis,0,sizeof(vis));
    int curr,count=0;
    
    while(!s.empty())
    {
        curr = s.top();
        s.pop();
        if(!vis[curr])
        {
          dfs2(curr,rev_dp,vis);  // visiting the graph in the normal dfs way // see the graph
          count++;
        }
    }
    return count;
}



//screenshot ref 2019-09-36 20-57-45 
//hackerearth post man test

Range queries! 

Answers between range! max, min, sum etc;

If there are no updates that will occur in the array, if the given array is fixed then suffix and or prefix array will suffice.
No need for segment tree. Segment tree is only needed when there are updates in the current array.

This ref question doesnt need updates. So suffix and prefix array suffices! For max,min both needed.

example: MAX!

given arr[5] = {300,400,200,500,600}

build max_prefix array = max from the start to this point

 int max_pre[n];
 max_pre[0]=arr[0];
 
 for(int i=1;i<n;i++)
   max_pre[i]=max(max_pre[i-1],arr[i]);
  
//in this case   
max_pre = {300,400,400,500,600}
   
build max_suffix array = max from here to the end.   

  int max_suf[n];
  max_suf[n-1]=arr[n-1];
  
  for(int i=n-2;i>=0;i--)
    max_suf[i]=max(max_suf[i-1],arr[i]);
    
//in this case
max_suf = {600,600,600,600,600}

after building these arrays, range queries! for a given l , r

//basically we are compary the values at max_prefix l r and same for sufix and taking the min of them!
  ans = min(max(max_prefix[l],max_prefix[r]) ,max(max_sufix[l],max_sufix[r]));
    
//similarly for min!

Question specifics, first sort by the prices. For each query do binary search on prices to get the indices, send the indices to the range
query to get answer;

//question specific // special binary seach for this que
int find(int a[],int n,int q,int l)
{
  int s=0;
  int e=n-1;
  int mid;
  while(e>s)
  {
    mid = (s+e)/2;
    if(a[mid]<q)
     s = mid+1;
    else if(a[mid]>q)
     e = mid -1;
     else
      return mid;   
  }
  if(a[s]<q && l==0) // l==0 indicates that it is the left end of the range! if left end is not there if give higher value present! 
    return s+1;
    
  if(a[s]>q && l==1) // l==1 indicates that it is right end of the range! if right end is not there give closest value less than present!ss
    return s-1;
      
  return s;
}

//see this also!
https://www.geeksforgeeks.org/difference-array-range-update-query-o1/
