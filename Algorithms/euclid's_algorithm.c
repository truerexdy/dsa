#include <stdio.h>

int gcd(int a, int b){
    while(b!=0){
        int r = a%b;
        a = b;
        b = r;
    }
    return a;
}

int main(){
    printf("Enter the first number:\n");
    int a,b;
    scanf("%d", &a);
    printf("Enter the second number:\n");
    scanf("%d", &b);
    printf("GCD = %d", gcd(a,b));
    return 0;
}