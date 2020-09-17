

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