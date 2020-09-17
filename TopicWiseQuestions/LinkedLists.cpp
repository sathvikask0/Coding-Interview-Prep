
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
