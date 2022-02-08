#include <bits/stdc++.h>  

  

using namespace std;  

  

   

  

long long b1[200002];  

  

long long b2[200002];  

  

long long B1=0;  

  

long long B2=0;  

  

void fun1(long long x,long long y){  

  

    b1[B1]=x;  

  

    B1++;  

  

    b1[B1]=y;  

  

    B1++;  

  

}  

  

//My fuck goes here  

  

void fun2(long long x,long long y){  

  

    b2[B2]=x;  

  

    B2++;  

  

    b2[B2]=y;  

  

    B2++;  

  

}  

  

//It's my fuck mahn!  

  

int main()  

  

{  

  

    long long t;  

  

    cin >> t;  

  

    while(t--){  

  

        B1=0;  

  

        B2=0;  

  

          

  

        long long lapaki111 = 0;  

  

        long long lapaki222 = 0;  

  

          

  

        long long n;  

  

        cin >> n;  

  

        long long a[n];  

  

        long long A[n];  

  

          

  

        long long Y1=0,Y=2;  

  

        long long y1=0,y=0;  

  

          

  

        long long check_heer_odd =0;  

  

        for(long long i=0; i<n ;i++){  

  

            cin>>a[i];  

  

            A[i]=a[i];  

  

        }  

  

//Just get lost from here!          

  

if(a[0]%2==0)  

  

{  

  

    if(a[1]%2==0){  

  

           

  

         for(long long i=2;i<n;i++){  

  

             if(a[i]%2==1){  

  

                 Y1=a[i];  

  

                 y1=i;  

  

                 check_heer_odd = 1;  

  

                   

  

                 a[1] = a[1]^Y1;  

  

                 lapaki111++;  

  

                 fun1(1,y1);  

  

                 break;  

  

             }  

  

         }  

  

           

  

    }//Bloddy  

  

    else{  

  

        Y1=a[1];  

  

        y1=1;  

  

        check_heer_odd = 1;  

  

    }  

  

      Y=a[1];  

  

      y=1;  

  

      for(long long i =2;i<n;i++){  

  

          if(a[i]%2==1){  

  

              a[i]=a[i]^Y;  

  

              lapaki111++;  

  

              fun1(i,y);  

  

          }  

  

          i++;  

  

          if(i<n){  

  

              if(a[i]%2==0){  

  

                  a[i]=a[i]^Y;  

  

              lapaki111++;  

  

              fun1(i,y);  

  

              }  

  

          }  

  

      }//-------  

  

      A[0]=A[0]^Y1;  

  

      lapaki222++;  

  

      fun2(0,y1);  

  

        

  

      Y=A[0];  

  

      y=0;  

  

        

  

      for(long long i=1;i<n;i++){  

  

          if(A[i]%2==1){  

  

              A[i]=A[i]^Y;  

  

              lapaki222++;  

  

              fun2(i,y);  

  

          }  

  

          i++;  

  

          if(i<n){  

  

              if(A[i]%2==0){  

  

                  A[i]=A[i]^Y;  

  

                  lapaki222++;  

  

                  fun2(i,y);  

  

              }  

  

          }  

  

      }  

  

//ndh8     

  

      

  

}  

  

else{  

  

    check_heer_odd = 1;  

  

    Y=A[0];  

  

    y=0;  

  

    for(long long i=1;i<n;i++){  

  

        if(a[i]%2==1){  

  

            a[i]=a[i]^Y;  

  

            lapaki111++;  

  

            fun1(i,y);  

  

        }  

  

        i++;  

  

        if(a[i]%2==0 && i<n){  

  

            a[i]=a[i]^Y;  

  

            lapaki111++;  

  

            fun1(i,y);  

  

        }  

  

    }  

  

      

  

    Y = A[0];  

  

    y=0;  

  

      

  

    for(long long i=1;i<n;i++){  

  

        if(A[i]%2==0){  

  

            A[i]=A[i]^Y;  

  

            lapaki222++;  

  

            fun2(i,y);  

  

        }  

  

        i++;  

  

        if(A[i]%2==1 && i<n){  

  

            A[i]=A[i]^Y;  

  

            lapaki222++;  

  

            fun2(i,y);  

  

        }  

  

    }  

  

      

  

    A[0]=A[0]^A[1];  

  

    lapaki222++;  

  

    fun2(0,1);  

  

//ninjijijjijijij    

  

}  

  

if(check_heer_odd==0){  

  

     cout<<"-1\n";  

  

}  

  

else if(lapaki111>lapaki222){  

  

     long long j;  

  

     cout<<lapaki222<<"\n";  

  

     for(long long i=0;i<lapaki222;i++){  

  

         j=i*2;  

  

         cout<<b2[j]+1<<" "<<b2[j+1]+1<<"\n";  

  

     }  

  

}  

  

else{  

  

     int j;  

  

     cout<<lapaki111<<"\n";  

  

     for(long long i=0;i<lapaki111;i++){  

  

         j=i*2;  

  

         cout<<b1[j]+1<<" "<<b1[j+1]+1<<"\n";  

  

     }  

  

}  

  

//hbnci-f8  

  

      

  

}  

  

          

  

      return 0;    

  

    }
