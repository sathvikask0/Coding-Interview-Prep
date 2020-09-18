// heap implementation

// Rearranges input array so that it becomes a max heap
int MinHeap ::  extractMin()
{
    if(heap_size==0)
      return -1;
      
    int ans = harr[0];
    harr[0] = harr[heap_size-1];
    heap_size--;
    MinHeapify(0);
    return ans;
}
/* Removes element from position x in the min heap  */
void MinHeap :: deleteKey(int i)   // see these ideas!
{
    if(i<0 || i>=heap_size)
      return ;
    
    decreaseKey(i,INT_MIN); //decreasing the value of the node to be deleted to INT_MIN, as it will be min, doing extact min removes it!
    extractMin();
}
/* Inserts an element at position x into the min heap*/
void MinHeap ::insertKey(int k)  
{
   if(heap_size==capacity)
     return;
   
   harr[heap_size] = INT_MAX;
   heap_size++;
   decreaseKey(heap_size-1,k);
}
// Decrease Key operation, helps in deleting key from heap
void MinHeap::decreaseKey(int i, int new_val)
{
    harr[i] = new_val;
    while (i != 0 && harr[parent(i)] > harr[i])
    {
       swap(harr[i], harr[parent(i)]);
       i = parent(i);
    }
}
/* You may call below MinHeapify function in 
   above codes. Please do not delete this code
   if you are not writing your own MinHeapify */
void MinHeap::MinHeapify(int i)
{
    int l = left(i);
    int r = right(i);
    int smallest = i;
    if (l < heap_size && harr[l] < harr[i])
        smallest = l;
    if (r < heap_size && harr[r] < harr[smallest])
        smallest = r;
    if (smallest != i)
    {
        swap(harr[i], harr[smallest]);
        MinHeapify(smallest);
    }
}


void buildHeap(int arr[], int n)  
{ 
    for(int i=n/2 -1 ; i>=0 ;i--)
      heapify(arr,n,i);
}

void heapSort(int arr[], int n)  
{
    buildHeap(arr, n);
    for (int i=n-1; i>=0; i--)  
    {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
} 

//k smallest elements

void yo(int a[],int n, int k)
{
  priority_queue <int, vector<int>, greater<int>> min_heap;
  
  
  for(int i=0;i<n;i++)
    min_heap.push(a[i]);
  
  for(int i=0;i<k;i++)
  {
    cout << min_heap.top() << " ";
    min_heap.pop();
  }    

}
