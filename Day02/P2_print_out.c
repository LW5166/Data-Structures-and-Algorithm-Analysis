#include<stdio.h>

void print_out(unsigned int n){     /*递归按位显示每个数字*/
    if(n<10){
        putchar(n+'0');
    }
    else{
        print_out(n/10);
        putchar(n%10+'0');
    }
}

int main(){
    unsigned int n;
    for(n=100000;n<10000000;n++){
        print_out(n);
        printf("\n");
    }
    return 0;
}