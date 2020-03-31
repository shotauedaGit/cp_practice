#include <stdio.h>

int main(){
    int i,n=100;

    for(i=1;i<n;i++){

        if(i%3!=0 && i%5!=0)printf("%d",i);
        if(i%3==0)printf("Fizz");
        if(i%5==0)printf("Buzz");

        printf("\n");

    }
    return 0;
}
