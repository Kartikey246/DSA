 public void reversePI(){
      if (head == null || head.next == null ){
        return ;
      }
    //if ( size == 0 || size == 1 ){
   //   return ;
   // }
       Node prev = null ;
       Node curr = head ;
      
      while ( curr != null){
       Node ahead = curr.next;
       curr.next = prev;

       prev = curr;
       curr = ahead;
      }

      Node temp = head ; 

      head = tail;

      tail = temp ;

    }
