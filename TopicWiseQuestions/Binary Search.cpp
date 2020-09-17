

Binary search 


//Count number of occurrences (or frequency) in a sorted array
// also gives first and last occurances of an element in the array
// see the use of lower and upper bounds

int count(int arr[], int x, int n) 
{     
  /* get the index of first occurrence of x */
  int *low = lower_bound(arr, arr+n, x); 
  
  // If element is not present, return 0 
  if (low == (arr + n) || *low != x) 
     return 0; 
     
  /* Else get the index of last occurrence of x. 
     Note that we  are only looking in the  
     subarray after first occurrence */   
  int *high = upper_bound(low, arr+n, x);      
     
  /* return count */
  return high - low; 
} 

https://practice.geeksforgeeks.org/problems/find-the-highest-number/0
//binary search modified
	    
void yo(int a[],int l,int r)
{
  int n = r;    
  while(l<=r)
  {
   int mid = (l+r)/2;
   if(a[mid]>a[mid-1] && a[mid]>a[mid+1]) // this is the required case a local maxima that is the answer itself
   {
      cout << a[mid] << endl;
      return;
   }
   if(a[mid]>a[mid-1] && a[mid]<a[mid+1]) // we are still in the increasing zone
     l = mid+1;
   else
     r = mid-1;  // reached into decreasing zone so go back
  }
  cout << a[n] << endl;
}


https://practice.geeksforgeeks.org/problems/count-the-elements/0

this is the idea
      sort(b,b+n);
	  for(int i=0;i<n;i++)
	  {
	    ans[i]=upper_bound(b,b+n,a[i])-b;
	  }
	  
	  

  greedy

//interval problem 
//Activity Selection

struct interval
{
    int s;
    int e;
};

bool compare(interval i1 , interval i2)
{
  return (i1.e<i2.e); //sorting based on the ending times of the interval
}

int main()
{
    int n;
    cin>>n;
    interval a[n];
    
    for(int i=0;i<n;i++)
        cin>>a[i].s>>a[i].e;
    
    sort(a,a+n,compare); 
    
    int b=1,j=0;
    for(int i=0;i<n-1;i++)
    {
        /*
          if ending time of current selected interval <= starting time of next interval? 
          yes : include it , make it the current selected interval
          no : discard it! 
        */
        if(a[j].e <= a[i+1].s) 
        {
            b++;
            j=i+1;           //very important!
        }
    }
    cout << b << endl;
    return 0;
} 

https://practice.geeksforgeeks.org/problems/shortest-path-from-1-to-n/0
// intersting question! u did it using greedy
int yo(int n)
{
  int ans=0;
  
  while(n>=3)
  {
      ans+=n%3;
      n-=n%3;
      n = n/3;
      ans++;
  }
  if(n==2)
    ans++;
    
  return ans;
}

//hotel arrival and departure problem

int max_rooms(int a[],int d,int n)
{   
    sort(a,a+n);
    sort(d,d+n);
    
    int count=0;
    int max_c=-1;
    
    int i=0,j=0;
    
    while(i<n && j<n)
    {
        if(a[i]<d[j])  //assume u are at the reception u just see and keep track of a or d! if a<d c++ else c--
        {
            count++;
            i++;
        }
        else
        {
            count--;
            j++;
        }
        
        if(max_c<count)
             max_c = count;
    }
    cout << max_c << endl;
}

Given a list of numbers, create an algorithm that arranges them in order to form the largest possible integer.
https://www.geeksforgeeks.org/given-an-array-of-numbers-arrange-the-numbers-to-form-the-biggest-number/
int myCompare(string X, string Y) 
{ 
    // first append Y at the end of X 
    string XY = X.append(Y); 
  
    // then append X at the end of Y 
    string YX = Y.append(X); 
  
    // Now see which of the two formed numbers is greater 
    return XY.compare(YX) > 0 ? 1: 0; 
} 
  
// The main function that prints the arrangement with the largest value. 
// The function accepts a vector of strings 
void printLargest(vector<string> arr) 
{ 
    sort(arr.begin(), arr.end(), myCompare); 
  
    for (int i=0; i < arr.size() ; i++ ) 
        cout << arr[i]; 
} 

//majority element
https://www.interviewbit.com/problems/majority-element/
int Solution::majorityElement(const vector<int> &arr) 
{
    int candidate=0;
    int count=0;
    for(auto i:arr)
    {
      if(count==0)
         candidate = i; // this would never happen with a majority element, its count is greater all others combined.
      
      if(i==candidate)
           count++;
      else
          count--;
    }
    return candidate; 
}

// N people have ratings, adjacent ones should not have same number of candy
https://www.interviewbit.com/problems/distribute-candy/
int Solution::candy(vector<int> &a) 
{
    int n = a.size();
    vector<int>dp(n,1); // initialise with "1"
    
    for(int i=0;i<n-1;i++)
      if(a[i+1]>a[i])
         dp[i+1]=dp[i]+1;  // left to right increase number of candy according to the rule
         
    for(int i=n-1;i>=0;i--)
      if(a[i-1]>a[i] && dp[i-1]<=dp[i])  // same idea, but give one more only if its against the rule
         dp[i-1]=dp[i]+1;         	
      
    int ans=0;     
    for(auto i:dp)
       ans+=i;
       
    return ans;   
}


// bulbs right flip 
//very good que and very good solution!
https://www.interviewbit.com/problems/bulbs/
int Solution::bulbs(vector<int> &A) 
{
    int state = 0, ans = 0;
    for (int i = 0;i < A.size();i++) 
    {
        //firstly find the first zero! hence the initilization with state = 0
        // then ans++ as we have to on this bulb! now this changes the state of all bulbs after it
        // now we are in an alternate universe, when we should start looking for one.
        if (A[i] == state) 
        {
            ans++;
            state = 1 - state;
        }
    }
    return ans;
}

// gas station question
https://www.interviewbit.com/problems/gas-station/
int Solution::canCompleteCircuit(const vector<int> &gas, const vector<int> &cost) 
{
        int sumo=0;
        int fuel=0;
        int start=0;
        int n = gas.size();
        for(int i=0;i<n;i++)
        {
            sumo = sumo + (gas[i] - cost[i]);
            fuel = fuel + (gas[i] - cost[i]);
            if (fuel<0)
            {
                fuel=0;
                start=i+1;
            }        
        }
        if (sumo>=0)
            return (start%n);
        else
            return -1 ;
}

Binary search and greedy!
//see this que
https://www.quora.com/What-is-the-correct-approach-to-solve-the-SPOJ-problem-Aggressive-cow/answer/Raziman-T-V?ch=10&share=c73687f8&srid=po1HB 

//agrressive cows question!
int F(ll a[],ll n, ll c, ll gap)
{
  int cows = 1;
  int curr = 0;
    
  for(int i=1;i<n;i++)
  {
      if(a[i]-a[curr] >= gap)  //greedily filling positions!
      {
          curr = i;
          if(++cows == c)
              return 1;
      }
  }
  return 0;  
}

void min_distance(ll a[],ll n,ll c)
{
  ll mi = 0;
  ll max = a[n-1]-a[0];
  ll ans=-1;  
  while(mi <= max)  //binary search!
  {
      ll mid = mi + (max-mi)/2;
      
      if(F(a,n,c,mid))
      {
          mi = mid + 1;
          ans = mid;
      }
      else
          max = mid-1;
  }
  cout <<ans <<endl;
}


https://www.interviewbit.com/problems/min-jumps-array/
min jump array
int Solution::jump(vector<int> &A) 
{
    int n = A.size();
    if(n <= 1)
        return 0;
        
    int maxReachPos = A[0];
    int curMaxReachPos = A[0];
    int curStep = 1;
    
    /*
       With the current number of steps, try to maintain the maximum index which is reachable. 
       When you exceed the index, you have to increase the number of steps, and at that instance you can increase the maximum index     reachable  accordingly.
       
    */
    for(int i = 1; i <= maxReachPos; i++)
    {
        if(i == n - 1)
            return curStep;

        curMaxReachPos = max(curMaxReachPos, i + A[i]);
        if(i == maxReachPos)
        {
            if (curMaxReachPos <= i) 
                return -1;
            maxReachPos = curMaxReachPos;
            curStep++;
        }
    }
    return -1;
}



//Stock buy and sell any number of times
 
int yo(int a[],int n)
{
  if(n<=1)
    return -1;

  int i=0;
  vector<int>ans;
  ans.clear();
  while(i<n-1)
  {
      while(i<n-1 && a[i+1]<=a[i]) //find local minima
        i++;
      
      if(i==n-1)
        break;
        
      ans.push_back(i);
      while(i<n-1 && a[i+1]>=a[i]) // find local maxima
        i++;
    
      ans.push_back(i);
      if(i==n-1)
        break;
  }
  if(ans.empty())
    return -1;
}