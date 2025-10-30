/* bill amount:
       0-2000    =2%
       2000-4000 =4%
       4000-6000 =6%
       6000-8000 =8%
       8000-10000=10%
           >10000=20%  the shopping🛒 calculator */

#include<stdio.h>
int main(){
 printf("welcome shopping bill calculator\n");
 printf("enter bill payment:\n");
 int bill;
 scanf("%d",&bill);
 float tax;
 int percentage;
  if((bill>0)&&(bill<=2000)){
   percentage=2;
   tax=1;
  }
  else if((bill>2000)&&(bill<=4000)){
   percentage=4;
   tax=2;
  }
  else if((bill>4000)&&(bill<=6000)){
   percentage=6;
   tax=4;
  }
  else if((bill>6000)&&(bill<=8000)){
   percentage=8;
   tax=6;
  }
  else if((bill>8000)&&(bill<=10000)){
   percentage=10;
   tax=8;
  } 
  else if(bill>10000){
   percentage=20;
   tax=10;
  }
  else {
    printf("invalid \n");
  } 
      bill= bill;
  int discount=(bill*percentage)/100;
     tax=(bill*tax)/100;
  int payment=bill-discount+tax;
      
      
    printf("bill=%d\n",bill);
    printf("discount percentage=%d\n",discount); 
    printf("tax=%.0f\n",tax);
    printf("total amount=%d\n",payment); 
     
     
     printf("thank you! for shopping visit again have a nice day");
      
  
  
  return 0;
  }
