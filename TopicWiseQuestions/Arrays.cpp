

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
