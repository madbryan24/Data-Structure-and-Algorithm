#include <stdio.h>

int count;

void move(int n, char A, char B, char C){
    if(n == 1){
        count++;
        printf("Step %d: move 1 disk from %c -> %c\n",count,A,B);
    }else{
        move(n-1,A,C,B);
        move(1,A,B,C);
        move(n-1,C,B,A);
    }
}

int main(){
    int n = 10;
    count = 0;
    move(n,'A','B','C');
}

