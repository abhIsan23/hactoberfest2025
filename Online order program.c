#include<stdio.h>
#include<string.h>

int main() {

    int cases,t1,t2,t3,milli,time;
    char customer[100];
    char choose[10];
    char minutemaid[] = "minutemaid";
    char thumsup[] = "thumsup";
    char yes[] = "y";
    char day[30];
    
    do {
        printf("welcome to gupta beverages mart.\n");
        printf("select your soft drink\n");
        printf("thumsup, sprite, minutemaid:\n");
        scanf("%s", customer);

        if (strcmp(customer, minutemaid) == 0) {
            printf("select flavour of minutemaid\n");
            printf("two flavours goa, orange\n");
            scanf("%s", customer);
            printf("minutemaid added to cart\n");
        }
        else if (strcmp(customer, thumsup) == 0) {
            printf("thumsup added to cart\n");
        }
        else {
            printf("sprite added to cart\n");
        }

        printf("enter the milli liters of the drink\n");
        printf("250ml, 500ml, 2l\n");
        scanf("%d", &milli);

        if (milli == 250) {
            printf("this item case cost :500/-\n");
        }
        else if (milli == 500) {
            printf("this item case cost :1000/-\n");
        }
        else {
            printf("this item case cost :1500/-\n");
        }

        printf("how many cases are you want: ");
        scanf("%d", &cases);

        if(milli==250) {
            t1= 500*cases;
            printf("total amount=%d\n",t1);
        }
        else if(milli==500) {
            t2=1000*cases;
            printf("total amount=%d\n",t2);
        }
        else {
            t3=1500*cases;
            printf("total amount=%d\n",t3);
        }
         printf("GST = NO GST\n");
        
         printf("enter your address sir : \n ");
         scanf("%s",&customer);
        
        

         printf("can you want to continue this order\n, [y/n]: ");
         scanf("%s", &choose);
        
            if(choose=='y'){
               printf("continuing the order. \n");
            } 
            else{
               printf("ok checkout the order.\n");
               
              printf("please select your shipping day(tomorrow),(friday),(monday): \n"); 
              scanf("%s",&day);
             if(day=='tomorrow'){
              printf("thank you for giving the scheduled day we will shipped your order in in time .\n");
             }
             else if(day=='friday'){
              printf("thank you for giving the scheduled day we will shipped your order in time.\n");
             }
             else if(day=='monday'){
              printf("thank you for giving the scheduled day we will shipped your order in time.\n");
             }
             else{
              printf("thank you for giving the scheduled day we will try to shipped your order in selected schduled .\n");
             }
             
             printf("select your order timings in above timings(9am),(11am),(3pm):\n");
             printf("placed order time:%d\n");
             scanf("%d",&time);
             if(time==9){
             printf("ok your order shipped on selected slot.\n");
             printf("ORDER ID:2420014\n");
             }
             else if(time==11){
             printf("ok your order shipped on selected slot.\n ");
             printf("ORDER ID:2420013\n");
             }
             else if(time==3){
             printf("ok your order shipped on selected slot.\n");
             printf("ORDER ID:2420012\n");
             }
             else{
             printf("your delivery on our selected time.\n");
             printf("ORDER ID:2420011\n");
             }
             
             
             printf("thank you ! for placing the order \n");
            
            }    
        
        
        

    }
             while (strcmp(choose, yes) ==0);
    return 0;
}
