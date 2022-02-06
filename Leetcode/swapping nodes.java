class Solution {
    public ListNode reverseBetween(ListNode head, int left, int right) {
       if(right-left==0) return head;
        ListNode dummy = new ListNode(-1);
        ListNode curr=dummy;
        ListNode maincurr=head;
        
        ListNode nextGroupNode;
        for(int i=1;i<=right;i++){
            maincurr=maincurr.next;
        }
        nextGroupNode=maincurr;
        
        maincurr=head;
        for(int i=1;i<left;i++){
            curr.next=maincurr;
            maincurr=maincurr.next;
            curr=curr.next;
        }
        
        curr.next=reverse(maincurr,right-left+1);
        maincurr.next=nextGroupNode;
        return dummy.next;
        
        
        
        
    }
    
        public ListNode reverse(ListNode node,int k){
            ListNode prev,curr;
            prev = null;
            curr=node;
            while(curr!=null&&k-->0){
                ListNode next = curr.next;
                curr.next =prev;
                prev =curr;
                curr=next;
            }
            return prev;
            
        }
}
