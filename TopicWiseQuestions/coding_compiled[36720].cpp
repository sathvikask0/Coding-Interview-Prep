
//BASICS
#include <bits/stdc++.h> // all libraries in c++ 
using namespace std;  // for functions like cin cout 


//insertion sort - inserting elements assuming we already have sorted array. compare with all and find the correct posn of current element.
//selection sort - find first minimum, second minumum and so on!


time complexity for recursion:

- write recurrence relations and solve them.

example for factorial:

int fact(int n)
{
 if(n==0)
   return 1;
   
 else 
   return n*fact(n-1);    
}

//time taken for input n
T(n) = a + b + T(n-1) // base case checking - a , multiplication b;


//Vector : Dynamic array.

//number is the number of elements u want in them intially.
vector<int>vec(5)

// size of vector 
v.size() 

//inserting element at the back.
v.push_back() 

//sorting the vector
sort(v.begin(),v.end());  

// initialising 2d vector with size n * m
vector<vector<int>>vis(n, vector<int> (m));



//strings

string s;
string s1(s,i,n) // selects from the string s starting from index i till n characters from there.

example : if s = "sathvik"
s1(s,2,3) = "thv" //starts from index 2 goes on for 3 characters.

s.compare() function! //returns a number which shows greater than or less than equal to for (>0,=0,<0) cases.

s.substr(index)  // starts from that index and goes till the end

example :

   s = "sathvik"
   s.substr(1) = "athvik"

sort(s.begin(),s.end()); //sort strings

//pair

pair<int,string>p; // give the required 2 data types u want.

p = make_pair(1,"b"); //making a pair.

p.first , p.second // ways to access.


//sets
cannot have repetitive elements. contains distinct elements.

set<int>s; //delcaration;

s.insert(2) //adding elements to a set.

s.find() //finds an element if it is present. else it returns s.end()

if(s.find(a)!=s.end()) //searching in a set.

//Map

map<int,int>m;

int arr[];

for(int i=0;i<n;i++)
{
 	m[arr[i]]++; //initally all values are initialized to zero.
}


map<int,int>::iterator it;

for(it = m.begin();it!=m.end();it++)
{
  cout << it->first << it ->second << endl;
}

m.erase(1) // key == 1 is removed.

Find closest key K > x :
(m.upper_bound(x))->first     // O(log n). Do need to handle the case when x is more than or equal to the max key in the map. 

Find closest key K >= x :
(m.lower_bound(x))->first     // O(log n). Do need to handle the case when x is more than the max key in the map.

The count() function basically checks if there exists an element in the unordered_map with a given key or not.

syntax:
m.count(key) // key is the key u want!


//min heap
priority_queue <int, vector<int>, greater<int>> gquiz; 

//max heap    
priority_queue <int> gquiz; 


//Functions

//sorting

int arr[n];
sort(arr,arr+n); //does it in place. array is sorted and stored in arr itself.

sort(arr,arr+n,greater<int>()) //reverse sort.

//giving custorm sort function

sort(arr,arr+n,compare);

//write your own compare function 
this compare function should be a bool function taking two arguments to compare and you should give the condition , which is smaller and which is greater. // see any online link.

//binary search

binary_search(arr,arr+n,value) // the value you want to search//returns 1 if present else 0

lower_bound(arr,arr+n,value) - arr // this gives the index , the function only gives you the pointer to that value.


//gcd function 
__gcd(a,b) //put the 2 underscores in the beginning

Basic Euclidean Algorithm for GCD
The algorithm is based on below facts.

    If we subtract smaller number from larger (we reduce larger number), GCD doesn’t change. So if we keep subtracting repeatedly the larger of two, we end up with GCD.
    Now instead of subtraction, if we divide smaller number, the algorithm stops when we find remainder 0.

int gcd(int a,int b)
{
  if(a==0)
    return b;
  return gcd(b%a,a);  
}

//power function
pow(a,b)

//swap function
swap(a,b) //swaps a,b

/***********************EOD OF************************************part onr */

// basic template for GFG

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mod 1000000007

int yo(int a[],int n)
{
  
}
int main() {
	int t;
	cin>>t;
	while(t--)
	{
	  int n;
	  cin>>n;
	  int a[n];
	  for(int i=0;i<n;i++)
	    cin>>a[i];
	    
	  cout << yo(a,n) << endl;    
	} 
	
	
	return 0;
}

/* start of Arrays file */

//some tips:
1. be carful with the variable names u give! some might be overlapping! with what are needed.
   Eg :  you could be using i,j,k as iterators in for loop, but unknowingly you might also use them for something else!

// search for Topic : Topic Name // for easy access

Topic : Arrays

//o(n) rotating array
//array rotation
void rotate(int a[],int n,int d)
{
   int j,k,temp;  
   for(int i=0;i<__gcd(n,d);i++)
   {
    temp = a[i];
    j=i;
    while(1)
    {
      k = j+d;
      if(k>=n)
       k-=n;
       
      if(k==i)
       break;
       
      a[j]=a[k];
      j=k; 
    }
    a[j]=temp;
   }
}

//maximum sum sub array
//kadane's algo
int maxSubArraySum(int a[], int size) 
{ 
    int max_so_far = INT_MIN, max_ending_here = 0; 
  
    for (int i = 0; i < size; i++) 
    { 
        max_ending_here = max_ending_here + a[i]; 
        if (max_so_far < max_ending_here) 
            max_so_far = max_ending_here; 
  
        if (max_ending_here < 0) 
            max_ending_here = 0; 
    } 
    return max_so_far; 
}


//problem for finding subarray with the given sum 
//see the double pointer idea.
//remember the left to right idea!
string target_sum(int a[],int n, int tar)  
{
  int sum = a[0];
  int i = 0;
  int j = 1;
  
  while(j<n && i<=j)
  {
    sum += a[j];    // in the case sum>tar even a[j] is removed from the sum, its added again here!
    
    if (sum > tar)
    {
      if(i==j)
       j++;
      
      sum -= a[i];
      sum -= a[j];  // because at the start of every iteration we are adding a[j] so we need to remove it here
      i++; 
    }
    
    else if (sum < tar)
      j++;
    
    else
    {
      cout << i << " " << j << endl; // prints the subarray!
      return "Found";
    } 
  }
  
  return "Not present";
                     
}

https://www.interviewbit.com/problems/max-product-subarray/
Max Product Subarray
int Solution::maxProduct(const vector<int> &nums) 
{
        int ans = INT_MIN;
        int minAns = 1, maxAns =1;
        int n = nums.size();
        
        for(int i=0;i<n;i++)
        {
           if(nums[i]<0)
               swap(minAns, maxAns);  // because multiplying by a negative number makes make negative max positive and vice versa
              
            ans = max(ans, nums[i]*maxAns);
            minAns = nums[i]*minAns;
            maxAns = max(1,nums[i]*maxAns);
            
        }
        
        return ans;
}

https://www.geeksforgeeks.org/find-smallest-value-represented-sum-subset-given-array/
find the smallest positive integer that is not the sum of a subset of the array.

int findSmallest(int arr[], int n) // arr is sorted!
{ 
   int res = 1; // Initialize result 
  
   // Traverse the array and increment 'res' if arr[i] is 
   // smaller than or equal to 'res'. 
   for (int i = 0; i < n && arr[i] <= res; i++) 
       res = res + arr[i]; 
  
   return res; 
}  


//Count subarrays with sum less than or equal to k. O(n) 
https://www.geeksforgeeks.org/number-subarrays-sum-less-k/
int countSubarrays(int arr[], int n, int k) 
{ 
    int start = 0, end = 0, 
        count = 0, sum = arr[0]; 
  
    while (start < n && end < n) 
    { 
        if (sum < k) 
        { 
            end++; 
  
            if (end >= start) 
                count += end - start; 
  
            if (end < n) 
                sum += arr[end]; 
        } 
        
        else 
        { 
            sum -= arr[start]; 
            start++; 
        } 
    } 
  
    return count; 
}

//count triplers with sum less than given value 
int countTriplets(int arr[], int n, int sum) 
{ 
    sort(arr, arr+n);
    int ans = 0; 
  
    for (int i = 0; i < n - 2; i++) 
    { 
        int j = i + 1, k = n - 1; 
  
        // Use Meet in the Middle concept 
        while (j < k) 
        { 
            // If sum of current triplet is more or equal, 
            // move right corner to look for smaller values 
            if (arr[i] + arr[j] + arr[k] >= sum) 
                k--; 
  
            // Else move left corner 
            else
            { 
                // This is important. For current i and j, there 
                // can be total k-j third elements. 
                ans += (k - j); 
                j++; 
            } 
        } 
    } 
    return ans; 
} 


// Array and deque
//maximum of all subarrays of size k
https://www.geeksforgeeks.org/sliding-window-maximum-maximum-of-all-subarrays-of-size-k/
void yo(int a[],int n,int k)
{
   deque<int>dq;  // using deque!
   
   /*
     Useful elements from the previous window are the elements in the current window and are maximum also!
   */
   
   dq.push_back(0);
   for(int i=1;i<k;i++)
   {
       while(!dq.empty() && a[dq.back()]<=a[i])  // storing elements in decreasing order and storing only those matter
          dq.pop_back();
       
       dq.push_back(i);       // storing indices very good idea we can remove outside range values easily
   }
   
   cout << a[dq.front()] << " ";
   
   for(int i=k;i<n;i++)
   {   
       while(!dq.empty() && dq.front()<=i-k)  // removing outside range values
         dq.pop_front();
        
       while(!dq.empty() && a[dq.back()]<=a[i])
          dq.pop_back();
        
        dq.push_back(i);
       
       cout << a[dq.front()] << " ";       
   }
} 
/* end of arrays */

/* start of queues , stacks , linked list */

Topic : linked list

// removing loop in the linked list
void removeTheLoop(Node *head)
{
    Node* s = head;
    Node * f = head;
    
    int j=0;
    
    // slow fast pointer concept!
    while(f->next && f->next->next)
    {
        if(f==s && j==1)
          break;
        j=1;  
        f = f->next->next;
        s = s->next;
    }

    // if they dont meet, there is no cycle return
    if(!f || f!=s)
      return;
      
    /* 
       after they meet, again start one pointer from the start and the other will be at the prev point 
       continue till they meet, just before they meet, the position where f is, is the starting point
       of the cycle!
    */  
    s = head;
    
    while(f->next!=s->next)
    {
       f = f->next;
       s = s->next;
    }

    f->next = NULL; // removing cycle's starting point
    return;
}

Topic : stacks

//Next larger element
// Next greater element
https://www.geeksforgeeks.org/next-greater-element/

void yo(ll a[],int n)
{
  ll ans[n]; // answer array with the values for each of the index
  
  stack<int>s; // this stack will store the indices only! 
  int i=1;
  s.push(0); //pushing the first index
  while(i<n)
  {
    while(!s.empty() && a[s.top()]<a[i]) // if a[i] > a[s.top()] its the next greater element for all! till till point! Think!
    {
        ans[s.top()]=a[i];
        s.pop();
    }
    s.push(i);
    i++;  
  }
  
  while(!s.empty())
  {
    ans[s.top()] = -1;
    s.pop();
  }
  
  for(int i=0;i<n;i++)
    cout << ans[i] << " ";
     
}

Topic : Queues

//hussain's set que see it. // see codechef
// we are using queue to keep track of the maximum element after the operations are done
    
    
    sort(a,a+n);  
    int qe;
    ll ans;
    int count=0;
    queue<ll>q;
    int end=n-1;  
    while(m--)
    {
      cin>>qe;
      for(;count<qe;count++)
      {
        if(end>=0 && (q.empty() || a[end]>q.front()))  //queue usage! very good que!
        {
          ans = a[end];
          end--;
        }
        else
        {
          ans = q.front();
          q.pop();
        }
        q.push(ans/2);
      }
      cout << ans << endl;
    }

  /* EOD of Ques_stacks_ll file */

/* strat of maps file */
Topic : Maps


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
/*   END of Maps file  */

/*           Start of 2nf file   */  

Topic : Sorting


//Merge sort with inversion count
ll merge(int a[],int left,int mid2,int right)
{
    int i=left,j=mid2,k=0;
    int temp[right-left+1];
    ll count=0;
    while(i<mid2 && j<=right)
    {
        if(a[i]<=a[j])
           temp[k++]=a[i++];
        else
        {
            count += mid2-i;  //here is the idea! if a[i]>a[j] then from i to <mid2 all of them will be >a[j]
            temp[k++]=a[j++];
        }
    }
    while(i<mid2)
     temp[k++]=a[i++];
     
    while(j<=right)
     temp[k++]=a[j++];
    
    for(int i=left;i<=right;i++)
        a[i]=temp[i-left];
    
    return count;
}
ll merge_s(int a[],int left,int right)
{
    ll count=0;
    if(right>left) // if right == left it implies one element! no sorting needed.
    {
        int mid = (left+right)/2;
        
        //left and right calls
        ll lc = merge_s(a,left,mid);   
        ll rc = merge_s(a,mid+1,right);
        
        //merging  
        ll m = merge(a,left,mid+1,right);   
        return (lc+rc+m);  //adding up inversion counts!
    }
    return count;
}
ll solve(int a[], int n)
{
  ll ans = merge_s(a,0,n-1);//initilization
  return ans;  
}


//quicksort
// see this once!
int partition(int a[],int s,int e)  
{
  // generating random numbers between s and e! both included!
  int piv = (rand() % (e- s + 1)) + s;
    
  int p = a[piv]; //taking last element as pivot!!
  int l = s;       //left and right!
  int r = e;
  int temp;
  
  while(l<=r)
  {
    while(a[l]<p)
      l++;
    
    while(a[r]>p)
      r--;
      
    if(l<=r)
    {
       temp = a[l];
       a[l] = a[r];
       a[r] = temp;
       
       l++;
       r--;
    }    
  }
  
  return l;                    
}

void quicksort(int a[],int s,int e)
{
    if(e>s)
    {
        int c = partition(a,s,e);
        quicksort(a,s,c-1);
        quicksort(a,c,e);
    }   
}
/****************EOD OF 2nf file */

/* start of strings */
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

/******************** strngs end *********************/

/* **************8strts of sets*/
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
/* end of sets*********************/
/********************start of Back tracing ***************/

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

/************** start of binary search *************/

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
/**************** ENd of binary search *********/

/***********************start of trees *************/

Trees

//mindepth of a tree
int Solution::minDepth(TreeNode* root) 
{
    if(root==NULL)
      return 0;
      
    if(root->left==NULL && root->right==NULL)
      return 1;
    
    if(root->left==NULL)  // if there is no left node, we cannot use it for mindepth!
       return 1+minDepth(root->right);
       
    if(root->right==NULL)  // similarly for right node
       return 1+minDepth(root->left);
       
    return (1+min(minDepth(root->left),minDepth(root->right)));  
}

//level order traversal tree
void level_order(Node *root)
{
  queue<Node*>q;
  q.push(root);
  int n;
  Node* temp;
  while(!q.empty())
  {
      n = q.size();
      for(int i=0;i<n;i++)
      {
          temp = q.front();
          cout << temp << endl;
          
          q.pop();
   
          if(temp->left)
             q.push(temp->left);
          
          if(temp->right)
             q.push(temp->right);
      }
  }
}

// Nodes at even distance
https://practice.geeksforgeeks.org/problems/nodes-at-even-distance/0
Think of this as a tree for a second and consider level order traversal :
a odd level node will have a EVEN difference with a odd level node similarly a even level node will have a EVEN difference with other even level node

 (even*(even-1))/2 + (odd*(odd-1))/2

so just do level order traversal and find number of nodes at odd and even levels! only among themselves are nodes with even distance

//Populate Next Right Pointers Tree
https://www.interviewbit.com/problems/populate-next-right-pointers-tree/
void Solution::connect(TreeLinkNode* root) 
{
  queue<TreeLinkNode*>q;
  q.push(root);
  int n;
  TreeLinkNode* temp;
  while(!q.empty())
  {
      n = q.size();
      TreeLinkNode* prev = NULL;
      for(int i=0;i<n;i++)
      {
          temp = q.front();
          if(i==0)           // i == 0 first node in the level!
             prev = temp;
          else
             prev ->next = temp;  // as we remembered the prev node, we simply connect it to the current one
          
          prev = temp;  // update the prev node to the current node
          
          q.pop();
   
          if(temp->left)
             q.push(temp->left);
          
          if(temp->right)
             q.push(temp->right);
           
          if(i == n-1)            // i ==n-1 last node in the level it should point to NULL
             temp ->next = NULL;
      }
      
  }
}

https://practice.geeksforgeeks.org/problems/sum-tree/1
bool isleaf(Node *root)  // function to test if the given node is a leaf!
{
  if(!root->left && !root->right)
     return true;
  return false;     
}
bool isSumTree(Node* root)
{
  if(!root)
    return true;
  
  if(!root->left && !root->right)
     return true;
  
  if(isSumTree(root->left) && isSumTree(root->right)) // the main idea here is that, if subtree rooted at this node is a sum tree
  {                                                   // then the sum coming from that subtree is 2 times the value at the node
      int l=0,r=0;                                    // if the node is a leaf sum, contribution is it's value itself
      if(root->left)
      {
        l = 2*root->left->data;
        if(isleaf(root->left))
          l-=root->left->data;
      }    
      if(root->right)
      {
         r = 2*root->right->data;
         if(isleaf(root->right))
          r-=root->right->data;
      }  
      return (l+r == root->data);     
  }       
}

// minimum in bst useful func
// useful to keep popping out the BST values in order
void pushstack(stack<Node*>&s2)
{
    Node * r = s2.top();
    cout << r->data << " ";
    s2.pop();
    r = r->right;
    while(r)
    {
        s2.push(r);
        r = r->left;
    }
}

https://www.interviewbit.com/problems/root-to-leaf-paths-with-sum/
//back tracking solution
//explore all the paths to get the answer!
// root to leaf paths with sum
void sum(TreeNode* root, int s,vector<vector<int>>&ans,vector<int>&vec)
{
    if(root==NULL)
      return;
      
    s-=root->val;  // decrementing the required sum "s"
    vec.push_back(root->val); //push everything into the current vector
    
    if(root->left==NULL && root->right==NULL)
    {
        if(s==0)
          ans.push_back(vec); //push it into the final answer only when we have the current answer
        vec.pop_back();  //pop back anyway to explore new paths if possible
        return;                 //nothing left to do here leave!
    }  
    
    sum(root->left,s,ans,vec);  
    sum(root->right,s,ans,vec);
    
    vec.pop_back(); //remove the current node !
    return;
}


//Maximum difference between node and its ancestor 
int maxdiff(Node* root, int *res)
{
    if(!root)
      return INT_MAX;
     
     if(root->right==NULL && root->left==NULL)
       return root->data;
       
     int l = maxdiff(root->left,res); // return left subtree min
     int r = maxdiff(root->right,res); // returns right subtree min
     
     int ans = min(l,r);  // min of both
     *res = max(*res,root->data-ans); // see if its more than current max
     
     return min(ans,root->data);  //return min of left subtree , right subtree, and root
}
int maxDiff(Node* root)
{
    int res = INT_MIN;
    maxdiff(root,&res);
    return res;
}

// LCA Least common ancestor
https://www.interviewbit.com/problems/least-common-ancestor/

// first find if those nodes actually exist!
int find(TreeNode * root,int a)
{
    if(root==NULL)
      return 0;
      
    int k = root->val;  
    if(k==a)
      return 1;
    return (find(root->right,a)||find(root->left,a));    
}

//the main algorithm
https://www.youtube.com/watch?v=13m9ZCB8gjw
TreeNode * lcahelp(TreeNode* root, int a, int b)
{
    if(!root)return root;
    
    int k = root->val;
    if(k==a || k==b)
      return root;
      
    TreeNode* l = lcahelp(root->left,a,b);
    TreeNode* r = lcahelp(root->right,a,b);  
     
    if(l!=NULL && r!=NULL)  // if u are getting not null from both sides that means this is the required node
      return root;
      
    return (l?l:r); // return l if it is not null else return r 
}

int Solution::lca(TreeNode* root, int a, int b) 
{
    if(root==NULL)
      return -1;
    
    if(find(root,a)==0 || find(root,b)==0)
      return -1;
    
    TreeNode * ans =lcahelp(root,a,b);
    if(!ans) 
      return -1;
    return ans->val;  
}

//Construct Binary Tree From Inorder And Preorder
https://www.interviewbit.com/problems/construct-binary-tree-from-inorder-and-preorder/
TreeNode * build(vector<int> &pre, int ps,int pe , vector<int> &in,int s,int e,unordered_map<int,int>&m)
{
    if(s>e)
      return NULL;
    TreeNode * root = new TreeNode(pre[ps]);
    if(s==e)
      return root;
      
    int index = m[pre[ps]]; // finding where is that node in the inorder list
    
    /*
       1. the inorder list is partitioned into two : (start)s --> index -1  and  index + 1 --> e(end)
            a. index is the current node so we exclude it
            
       2. preoder will be partitioned differently 
          - from the current node to the inorder index node would be the part which is to the left of it. recall inorder/preorder
            a. ps + 1 to ps + (index -s)  : ps is the current node.
    */
    
    root->left = build(pre,ps+1,ps+(index-s),in,s,index-1,m);
    root->right = build(pre,ps+(index-s)+1,pe,in,index+1,e,m);
    
    return root;
}
TreeNode* Solution::buildTree(vector<int> &pre, vector<int> &in) 
{
    int n = in.size();
    unordered_map<int,int>m;
    for(int i=0;i<n;i++)
        m[in[i]]=i;         // knowing the index of each element in the tree
    return build(pre,0,n-1,in,0,n-1,m);
}

ZigZag traversal!
https://www.geeksforgeeks.org/zigzag-tree-traversal/

//zigzag and spiral form
zizag = push to s2 first
spiral = push to s1 first

void zigZagTraversal(Node* root)
{
    stack<Node*>s1,s2;
    s2.push(root);
    
    int level=0;
    int n;
    Node* t;
    while(!s1.empty() || !s2.empty())
    {
       if(!s1.empty())
       {
           n = s1.size();
           for(int i=0;i<n;i++)
           {
               t = s1.top();
               s1.pop();
               cout << t->data << " ";
               if(t->right)
                 s2.push(t->right);  // one time we push right first
               if(t->left)
                 s2.push(t->left);
           }
       }
       else
       {
           n = s2.size();
           for(int i=0;i<n;i++)
           {
               t = s2.top();
               s2.pop();
               cout << t->data << " ";
               if(t->left)
                 s1.push(t->left);    // this is the other kind
               if(t->right)
                 s1.push(t->right);     
           } 
       }
    }
    cout << endl;   
}


//delete node in a bst // if node is not present do nothing
Node *deleteNode(Node *root,  int x)
{
   int k = root->data;
   
   if(k<x)
   {
     if(root->right!=NULL)
     root->right = deleteNode(root->right,x);
     return root;
   } 
    if(k>x)
    {
     if(root->left!=NULL)
     root->left = deleteNode(root->left,x);
     return root;
    }
    Node * temp=NULL,*temp2 = NULL;
    if(root->right)
    {
        temp=root->left;
        temp2 = root->right;
        root = root->right;
        while(root->left!=NULL)
         root=root->left;
         
        root->left = temp; 
        return temp2;
    }
    if(root->left)
    {
        temp=root->right;
        temp2 = root->left;
        root = root->left;
        while(root->right!=NULL)
         root=root->right;
         
        root->right = temp; 
        return temp2; 
    }
    return NULL;    
}



// flatten binary tree
https://www.interviewbit.com/problems/flatten-binary-tree-to-linked-list/
TreeNode* Solution::flatten(TreeNode* root) 
{
   if(!root)
     return root;
   
   if(!root->left && !root->right)
     return root;
     
   TreeNode* l =  flatten(root->left);
   TreeNode* r =  flatten(root->right);
   
   if (l)   // if l in NULL no need to do anything
   {
    TreeNode* temp = root->right;
    root->right = root->left;
    TreeNode* it = root->right;
    
    while(it->right) // go to the last of the tree
      it = it ->right;
      
    it->right = temp;  // attach the right sub tree here
    root->left = NULL;
   }
   return root;    
}

// diameter of a tree

int height(Node * node)
{
    if(!node)
     return 0;
    return (1 + max(height(node->left),height(node->right)));
}
int diameter(Node* node)
{
   if(!node)
     return 0;
   
   int l = height(node->left);
   int r = height(node->right);
   
   int ld = diameter(node->left);
   int rd = diameter(node ->right);
   
   return max(l+r+1,max(ld,rd));
}

https://practice.geeksforgeeks.org/problems/longest-consecutive-sequence-in-binary-tree/1
//tricky que
we have to go from top to bottom!
void yo(Node* root,int len,int ex,int *res) // expected value to be seen
{
    if(!root)
       return;
    if(root->data == ex)  //if it is seen, len increaases
      len++;
    else
      len=1;   // new sequence starts from here
      
    *res = max(*res,len);   //update max
    yo(root->left,len,root->data+1,res);
    yo(root->right,len,root->data+1,res);        
}
int longestConsecutive(Node* root)
{
    int res=0;
    yo(root,0,root->data,&res);
    if(res==1)
      return -1;
    return res;  
}


// TREE DP
// Diamter of a n-ary tree
https://www.interviewbit.com/problems/largest-distance-between-nodes-of-a-tree/
int height(int curr,vector<int>arr[],int n , int h[])
{
    if(n==1)
      return 0;
      
    if(arr[curr].empty())
       return h[curr] = 1;
    
    if(h[curr]!=0)
      return h[curr];
    
    int maxd = 0;
    for(auto i : arr[curr])
    {
        maxd = max(maxd,height(i,arr,n,h));  
    }
    
    return h[curr]= 1 + maxd;
}

int diameter(int curr,vector<int>arr[],int n,int h[]) 
{
    if(n==1)
      return 1;
      
    if(arr[curr].empty())
       return 1;
    
    int max1 = 0;
    int max2 = -1;
    int maxd = 0;
    
    int h1;
    for(auto i : arr[curr])
    {
        h1 = height(i,arr,n,h);
        if(h1>max1)
        {
            max2 = max1;
            max1 = h1;
        }
        else if(h1>max2)
          max2 = h1;
          
        maxd = max(maxd,diameter(i,arr,n,h));  
    }
    
    return max(maxd , max1+max2+1);
}
int Solution::solve(vector<int> &parent) 
{
   int n = parent.size();
   vector<int>dp[n];
   int root = -1;
   
   for(int i=0;i<n;i++)
   {
     if(parent[i]==-1)
       root = i;
     
     else
       dp[parent[i]].push_back(i);
   }
   
   int h[n];
   memset(h,0,sizeof(h));
   return diameter(root,dp,n,h) - 1;
}


//maxpath from any node to any other node
int maxpath(TreeNode * root, int &res)
    {
        if(!root)
           return INT_MIN;
        
        if(!root ->left && !root->right)
            return root->val;
        
        int l = maxpath(root->left,res);
        int r = maxpath(root->right,res);
        
        int sum = 0;
        if(l!=INT_MIN)
            sum+=l;
        if(r!=INT_MIN)
            sum+=r;
        
        int max_lr = max(l,r);
        res = max(res,max(sum+root->val,max_lr));
        cout << res << " " << root->val << " " << l << " " << r << endl;
    
        return max(root->val, max_lr+root->val);
    }
    int maxPathSum(TreeNode* root) 
    {
        int res = root->val;
        res = max(res,maxpath(root,res));
        if(res == INT_MIN)
             return 0;
        return res;
    }




// max path sum in a n- ary tree 
// hackerank

int maxpath(int root,vector<int>dp[], int &res,vector<int>values) 
{
   if(dp[root].empty())
     return values[root];
     
   int max1 = INT_MIN;
   int max2 = INT_MIN;
   int curr;
        
   for(auto j : dp[root])
   {
     curr = maxpath(j,dp,res,values);
        
     if(curr>max1)
     {
       max2 = max1;
       max1 = curr;
     }
           
     else if(curr>max2)
       max2 = curr;    
   }
        
   res = max(res, max1+max2+values[root]);
        
   return values[root] + max1;
}

int yo(vector<int>parent,vector<int>values)
{
   int n = parent.size();
   
   vector<int>dp[n];
   int root = -1;
   
   for(int i=0;i<n;i++)
   {
     if(parent[i]==-1)
       root = i;
     
     else
       dp[parent[i]].push_back(i);
   }
   
   int res = INT_MIN;
   maxpath(root, dp, res,values);
   
   return res;
}


//top view of a binary tree
void topView(struct Node *root)
{
   queue<pair<Node *,int>>q; // que with Node * root and the horizontal distance as elements!
   q.push(make_pair(root,0));
   map<int,int>m;
   int n;
   int dis;
   Node * temp = NULL;
   while(!q.empty())
   {
       n = q.size();
       for(int i=0;i<n;i++)
       {
            temp = q.front().first;
            dis = q.front().second;
            q.pop();
            if(temp->left)
                 q.push(make_pair(temp->left,dis-1));
                 
            if(temp->right)
                q.push(make_pair(temp->right,dis+1));
            
            /*
               1. we only add the node which first occurs at this horizontal distance!
               2. if we want bottom view binary tree 
                  just : remove the "if" condition! 
                  then it will store the last node at that distance!
            */
            if(m.find(dis)==m.end()) // comment this to get bottom view
              m[dis] = temp->data; 
       }
   }
   for(auto i:m)
     cout << i.second <<" ";
}

//right View of a binary tree
void rightView(Node *root)
{
   queue<Node *>q;
   q.push(root);
   
   int n;
   Node * temp = NULL;
   while(!q.empty())
   {
       n = q.size();
       for(int i=0;i<n;i++)
       {
           temp = q.front();
           q.pop();
           /*
              for right view we simply need the right most element at each level in the tree
              we know that the q has all the node at a particular level :
                  
                   a. i == 0 gives you the first element   (left view binary tree)
                   b. i == n-1 gives you the last element.
           */
           if(i==n-1)
             cout << temp->data << " ";
             
           if(temp->left)q.push(temp->left);
           if(temp->right)q.push(temp->right);
       }
   }
}


morris traversal!
//preorder
vector<int> Solution::preorderTraversal(TreeNode* root) 
{
    vector<int>ans;
    if(root==NULL)
      return ans;
    
    TreeNode * curr = root;
    while(curr!=NULL)
    {
      if(curr->left==NULL)
      {
          ans.push_back(curr->val);
          curr = curr->right;
      }
      else
      {          
          TreeNode * pred = curr->left;
          while(pred->right!=NULL && pred->right!=curr)
            pred = pred->right;
            
          if(pred->right==NULL)
          {
              pred->right=curr;
              ans.push_back(curr->val)
              curr=curr->left;
          }
          else
          {
              pred->right=NULL;
              curr=curr->right;
          }
      }
    }
    
    return ans;
}


//binary tree to doubly linked list inplace
// binary tree to DLL
void bToDLL(Node *root, Node **head_ref)
{
    Node * prev=NULL;
    Node * curr;
    while(root)
    {
        if(!root->left)
        {
            if(!prev)
            {
              prev = root;
              curr = prev;
            }
            
            else
            {
                curr->right = root;
                root->left = curr;
                curr = curr->right;
            }
            root = root->right;
        }
        else
        {
            Node* temp = root->left;
            while(temp->right && temp->right!=root)
              temp = temp->right;
            
            if(!temp->right)
            {
                temp->right = root;
                root = root->left;
            }
            else
            {
                if(!prev)
                {
                  prev = root;
                  curr = prev;
                }
            
                else
                {
                  curr->right = root;
                  root->left = curr;
                  curr = curr->right;
                }
                root = root->right;
            }
        }
    }
    *head_ref=prev;
}
/****************************End of trees***************/
Recusion:

https://cs.stackexchange.com/questions/7048/a-recursive-formula-for-generalized-josephus-problem
int yo(int n,int k)
{
    if(n==0)
     return k;
    
    return (yo(n-1,k)+k)%n;
}

  
  
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


/************* EN dof DP *******************/
/*      Start of Graphs *****************/
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


/******************* ENd of graphs *******************/
/*********** Sart of segment trees *********/
Segment trees
//segment tree for minimum

int query(int tree[],int s,int e,int l,int r,int idx)
{ 
  if(s>r || e<l)
    return INT_MAX;
    
  if(s>=l && e<=r)
    return tree[idx];

  int mid = (s+e)/2;
  
  return min(query(tree,s,mid,l,r,2*idx),query(tree,mid+1,e,l,r,2*idx+1));   
}

void update(int tree[],int s,int e,int i,int val,int idx)
{
  if(s==e)
  {
    tree[idx]= val;
    return;
  }
  
  int mid = (s+e)/2;

  if(mid>i)
  {
     update(tree,s,mid,i,val,2*idx);
     tree[idx]= min(tree[idx],tree[2*idx]);
  }
  else
  {
     update(tree,mid+1,e,i,val,2*idx+1);
     tree[idx]= min(tree[idx],tree[2*idx+1]);
  }
  return;   
}

void buildtree(int a[],int tree[],int s,int e,int idx)
{
    if(s==e)
    {
       tree[idx]=a[s];
       return;
    }

    int mid = (s+e)/2;

    buildtree(a,tree,s,mid,2*idx);
    buildtree(a,tree,mid+1,e,2*idx+1);
    
    tree[idx] = min(tree[2*idx],tree[2*idx+1]);
    return;
}

int main() 
{
    int n;
    cin>>n;
    
    int a[n];
    for(int i=0;i<n;i++)
       cin>>a[i];

    int tree[4*n];
    memset(tree,0,sizeof(tree));

    buildtree(a,tree,0,n-1,1);
    update(tree,0,n-1,4,10,1);
    
    int q;
    cin>>q;
    int l,r;
    while(q--)
    {
     cin>>l>>r;
     cout << query(tree,0,n-1,l,r,1) << endl;
    }
}


void Solve(int k, int arr[], int n) 
{
    int s =0,e=0,count=0,sum=arr[0];
    int ans[n];
    memset(ans,0,sizeof(ans));
    while(s<n && e<n)
    {
        if(sum<=k)
        {
            e++;		
            if(e>=s)
            {
             ans[e-s-1]+=1;
             cout << ans[e-s-1] << endl;
            }
             
            if(e<n)
            sum+=arr[e];
        }
        else
        {
            sum-=arr[s];
            if(s==e)
            e++;
            
            s++;
        }
    }
    
     
    for(int i=n-2;i>=0;i--)
      ans[i] += ans[i+1];
      
      for(int i=0;i<n;i++)
     cout << ans[i] << " ";   
}

/******** END OF SEGMENT TREES **********/
/************ Start of MISC *****************/
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
