#include<stdio.h>

void print_out(unsigned int n){     /*递归按位显示每个数字*/
    if(n<10 && n>=0){
        printf("%d",n);
    }
    else{
        print_out(n/10);
        printf("%d",n%10);
    }
}

int main(){
    unsigned int n;
    for(n=0;n<100;n++){
        print_out(n);
        printf("\n");
    }
    return 0;
}