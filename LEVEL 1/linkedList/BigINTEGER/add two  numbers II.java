class Solution {
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        if(l1 == null && l2 ==null) 
            return null;
        
        int length1 = getLength(l1);
        int length2 = getLength(l2);
        
         if(length1 > length2) {
             l2= addZeros(l2,length1-length2);
         }else{
             l1 = addZeros(l1,length2-length1);
         }
        
        ListNode res = helper(l1,l2);
        if(res.val >9){
            ListNode node = new ListNode(1);
            res.val = res.val % 10;
            node.next = res;
            res = node;
        }
        return res;
    }
    
    public ListNode helper(ListNode l1, ListNode l2){
        if(l1 == null && l2 == null) return null;
        ListNode result = new ListNode(0);
        
        result.val = l1.val + l2.val;
        ListNode post = helper(l1.next,l2.next);
        
        if(post!= null && post.val > 9){
            result.val = result.val + 1;
            post.val = post.val % 10;
        }
        
        result.next = post;
        return result;
        
    }
    
    public int getLength(ListNode node){
        int count = 0;
        while(node != null){
            count++;
            node = node.next;
        }
        return count;
    }
    
    public ListNode addZeros(ListNode node, int n){
        while(n>0){
            ListNode head = new ListNode(0);
            head.next = node;
            node = head;
            n--;
        }
        return node;
    }
}
