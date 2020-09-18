Topic : Recusion:

https://cs.stackexchange.com/questions/7048/a-recursive-formula-for-generalized-josephus-problem
int yo(int n,int k)
{
    if(n==0)
     return k;
    
    return (yo(n-1,k)+k)%n;
}


Topic : Backtracking

//N queens problem
//this print all the solutions for n queens problem! not just one!
void printsol(int q[10][10],int n)
{
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            cout << q[i][j] << " ";
    cout << endl;
}

bool safe(int q[10][10],int n, int row,int col)  //filiing columns col by col..
{
    int i,j;
    
    for(i=0;i<col;i++)
        if(q[row][i])
            return false;
    
    for(i=row,j=col;i>=0 && j>=0;i--,j--)
        if(q[i][j])
            return false;
    
    for(i=row,j=col;i<n && j>=0;i++,j--)
        if(q[i][j])
            return false;
    
    return true;    
}

bool solve(int q[10][10],int n, int col)    
{
    if(col==n)
    {    
        printsol(q,n); //if reached here print ans
        return true;
    }
    
    bool res = false;//initilization
    for(int i=0;i<n;i++)  //all the columns
    {
        if(safe(q,n,i,col)) //checking if we can place the queen here!
        {
            q[i][col]=1;  //if yes! mark it as a solution.
            res = solve(q,n,col+1) || res;
            q[i][col]=0;    //marking it as zero irrespective of sol / found or not! 
        }
    }
    return res;
}

void placeNQueens(int n){
  
  int q[10][10];
  memset(q,0,sizeof(q));
    
  solve(q,n,0);  
}


//rat in maze problem
// prints all possible solutions

void printsol(int q[20][20],int n)
{
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            cout << q[i][j] << " ";
    cout << endl;
}

bool safe(int s[20][20],int maze[20][20],int n, int row , int col)
{
    if(row>=0 && row<n && col>=0 && col<n && !s[row][col] && maze[row][col])
        return true;
    
    return false;
}

bool solve(int s[20][20],int maze[20][20],int n, int row , int col)
{
    if(row==n-1 && col==n-1)
    {
        printsol(s,n);
        return true;
    }
    
    // directions in which a rat can go! Writing it elegantly!
    int x[] = {1,0,-1,0}; 
    int y[] = {0,-1,0,1};
    
    bool res = false;
    for(int i=0;i<4;i++)
    {
        int x1 = row+x[i];
        int y1 = col+y[i];
        if(safe(s,maze,n,x1,y1))
        {
            s[x1][y1]=1;
            res = solve(s,maze,n,x1,y1) || res;
            
            //masking solution for it 0 independent of res!
            s[x1][y1]=0;
        }
    }
    
    // if res was true at least once true would be returned! meaning that end can be reached from here!
    return res;
}
void ratInAMaze(int maze[][20], int n){
  
  int s[20][20];
  memset(s,0,sizeof(s));
  
  s[0][0]=1;  
  solve(s,maze,n,0,0);
}

// done till here

//graph m-coloring back tracking problem!

bool valid(vector<int>dp[],int v,int c[],int k)
{
   for(auto j:dp[v])
     if(k==c[j])
      return false;
   return true;   
}

int col(vector<int>dp[],int v,int n,int c[],int m)
{
  if(v==n)
    return 1;
  
  for(int k=1;k<=m;k++)
  {
    if(valid(dp,v,c,k))
    {
      c[v]=k;
      
      if(col(dp,v+1,n,c,m))
       return 1;
      c[v]=0; 
    }
  }
  return 0;  
}

int yo(vector<int>dp[],int m,int n)
{
  int c[n];
  memset(c,0,sizeof(c));
  
  if (col(dp,0,n,c,m))
    return 1;
  return 0;  
}

int main() {
	int t;
	cin>>t;
	while(t--)
	{
	    int n,m,e;
	    cin>>n>>m>>e;
	    
	    vector<int>vec[n];
	    
	    int f,s;
	    for(int i=0;i<e;i++)
	    {
	        cin>>f>>s;
	        vec[f-1].push_back(s-1);
	        vec[s-1].push_back(f-1);
	    }
	    
	    cout << yo(vec,m,n) << endl;
	      
	}
	return 0;
}



//bit manupulation

leftshift operator : <<

8 << 1 = 16
11 << 2 = 44

n << x = n*(2^x)

rightshift operator : >>

8 >> 1 = 4
11 >> 2 = 2

n >> x = n/(2^x)


& | ^ ~  //other bit operators

//xor properties!  
1. x^1 = ~x  

2. x^x = 0

3. x^0 = x

4. Based on 2,3 number xor_ed with itself even number of times results in 0! 