public static int powerOf2(int n){
int i=1;
  while(i*2<=n){
  i*=2;
  }
  return i;


}
public static int JOSEPHUS(int n){
int hp2=powerOf2(n);
  return 2*(n-hp2)+1;

}
