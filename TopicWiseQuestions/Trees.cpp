
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
