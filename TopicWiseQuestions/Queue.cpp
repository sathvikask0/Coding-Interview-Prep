
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