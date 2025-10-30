#include<stdio.h>
int main(){
  int num1,x=1;
  int num2,result;
   char op,c;
   while(x){
   printf("enter a number:\n");
   scanf("%d",&num1);
   printf("enter the operator[+,-,*,/]:\\n");
        scanf(" %c", &op);
   
   printf("enter a number:\n");
   scanf("%d",&num2);
   
      if (op == '+') {
            result = num1 + num2;
            
        }
        else if (op == '-') {
            result = num1 - num2;
        } 
        else if (op == '*') {
            result = num1 * num2;
        } 
        else if (op == '/') {
            if (num2 != 0) {
                result = num1 / num2;
            } else {
                printf("Error: Division by zero\\n");
                continue;
            }
      }  
         else {
            printf("Error: Invalid operator\\n");
            continue;
         }   
   
   printf("result:%d\n",result);
   printf("-------------------------\n");
   
   printf("do you want to continue the calculator?[y/n]\n");
   scanf("%c",&c);
   
   if (c=='y'){
      num1=result;
   }
   else{
      printf("thank you!\n");
      x=0;
   }   
 } 
 return 0;
} 
