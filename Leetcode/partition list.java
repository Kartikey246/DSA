
class Solution {
    public ListNode partition(ListNode head, int x) {
        ListNode smallerHead = new ListNode(0), greaterHead = new ListNode(0);  //dummy heads of the 1st and 2nd queues
        ListNode smallerLast = smallerHead, greaterLast = greaterHead;      //current tails of the two queues;
        while (head != null){
            if (head.val < x) {
                smallerLast.next = head;
                smallerLast = smallerLast.next;
            }else {
                greaterLast.next = head;
                greaterLast = greaterLast.next;
            }
            head = head.next;
        }
        greaterLast.next = null;          
        smallerLast.next = greaterHead.next; //Skipping dummy head of greater and linking
        return smallerHead.next; //Skipping dummy head of smaller and returning next
    }
}
