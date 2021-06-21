#include<stdio.h>
void change(int a[]){
  a[0] = 10;
  a[0] =40;
}
int main(){
  int arr[5] ,i=0;
  while(i<5){
    arr[i] = ++i;

  }
  for(i=0;i<5;i++){
    printf("%d ",i);
  }
  // int a[6]={5,1,15,20,25};
  // int i,j,m;
  // i=++a[1];
  // j=a[1]++;
  // i=++a[1];
  // m = a[i++];
  // printf("%d %d %d %d ",i,j,m,a[1]);
  // int i;
  // int arr[5]={0};
  // for(i=0; i<=5;i++){
  //   printf("%d ", arr[i]);
  // }
  // int a[3] ={20,30,40};
  // int sum1=0,sum2=0;
  // for(int i=0;i<3;i++){
  //   sum1+=a[i];

  // }
  // change(a);
  // for (int i = 0; i < 3; i++)
  // {
  //   sum2 += a[i];
  // }
  // printf("%d %d", sum1, sum2);
  return 0;
}