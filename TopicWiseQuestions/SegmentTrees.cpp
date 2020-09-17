

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
