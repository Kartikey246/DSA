public void reverseDI() {
      int li = 0;
      int ri = size - 1;
      while(li < ri){
        Node left = getNodeAt(li);
        Node right = getNodeAt(ri);

        int temp = left.data;
        left.data = right.data;
        right.data = temp;

        li++;
        ri--;
      }
    }
