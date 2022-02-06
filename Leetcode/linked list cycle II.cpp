/*
Part 1 : Detecting the cycle
The algorithm states that if we move a fast pointer which jumps twice at a time and a slow pointer which jumps once at a time. Then if a cycle exists, they are bound to meet.

Proof:
If no cycle exists , fast pointer will reach the end and we will detect no cycle.
If there is a cycle , then both fast and slow pointer will enter into the cycle. We know that in every step fast jumps twice and slow jumps once which means that the distance between them increases by 1 in every step. This increment will keep happening and the pointers meet when the difference becomes a multiple of cycle length.

Detecting the entry point of cycle:
Algo: If we move a pointer from head of list and another from where the two pointers met in the cycle, then their meeting point is the entry point
Proof:
let the fast and slow pointers meet at distance a from the head of list.

Which means slow pointer travelled distance a and fast therefore travelled 2*a
Difference = 2a-a = a = multiple of k (k=chain length)
let the distance of head from entry point be m then distance of meeting point from entry point = a-m
The distance of meeting point from entry point from other side of cycle is k - (a-m) i.e k-a+m
This distance is (multiple)k + m = m therefore the distance from head to entry point = entry point from meeting point
*/



class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
         if(!head) return NULL;
        
        ListNode *slow=head,*fast=head;
        
        //cycle checking
        do{
            //move slow by one
            slow = slow->next;
            if(!slow) break;
            
            //move fast by 2
            fast= fast->next;
            if(!fast) break;
            fast = fast->next;
            if(!fast) break;            
            
        }while(slow!=fast);
        //no cycle
        if(!slow or !fast)
            return NULL;
        
        //check the entry point
        fast = head;
        while(fast !=slow)
            fast=fast->next, slow=slow->next;
        return fast;
    }
};
