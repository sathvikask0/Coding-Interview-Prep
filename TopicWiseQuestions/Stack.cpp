
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