int counter =0;
while(n!=0){
int rsmb=n&(-n);
  counter++;
  n=n-rsmb;


}
