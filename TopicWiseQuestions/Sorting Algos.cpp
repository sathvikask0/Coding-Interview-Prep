
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