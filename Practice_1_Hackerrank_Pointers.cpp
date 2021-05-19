// Hackerrank
//https://www.hackerrank.com/challenges/c-tutorial-pointer/problem
#include <iostream>
#include <stdio.h>
using namespace std ;

void update(int *a,int *b) {
    // Complete this function    
    int temp = (*a);
    *a = (temp) + (*b);
    *b = (temp) - (*b);
    
    if((*b) < 0 )
    {
        *b = -1 * (*b);
    }
}

int main() {
    int a, b;
    a = 5 ;
    b = 7 ;
    int *pa = &a, *pb = &b;
    
    //scanf("%d %d", &a, &b);
    update(pa, pb);
    printf("%d\n%d", a, b);

    return 0;
}