#include<bits/stdc++.h>
int detectloop(Node *head) {
    
    // your code here
    unordered_set<Node*> s;
    while(head !=NULL)
    {
        if(s.find(head) !=s.end())
        return true;
        
        s.insert(head);
        head=head->next;
    }
    return false;
}
