//Second program 
//learn how to use if else satement in java 

import java.util.*;
  
  public class GradingSystem{
  
  public static void main(String[] args) {
      // input - don''t change this code
      Scanner scn = new Scanner(System.in);
      int marks = scn.nextInt();
      // input - don''t change this code
      // bina and wali condition ke bhi kaaam chal jayega bcoz pehli condition ne bound kar diya hai 90 se
    // agar mein sirf if use karta kar conditioin ko check karne ke liye toh mujhe and ki jarurat hoti 
      // code here 
      if (marks > 90){
          System.out.println("excellent");
      }
      else if (marks > 80 && marks <= 90){
          System.out.println("good");
      }
      else if (marks > 70 && marks <= 80){
          System.out.println("fair");
      }
      else if  (marks > 60 && marks <= 70){
          System.out.println("meets expectations");
      }
      else {
          System.out.println("below par");
      }
   }
  }
