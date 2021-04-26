#include<stdio.h>
#include<stdlib.h>

#define INPUT "input.txt"
#define OUTPUT "output.txt"
#define LEN_NAME 10
#define NUM 5

typedef struct
{
    int no;
    char name[LEN_NAME];
    int buyprice;
    int selprice;
    int rank;
} Item;

void getBestItems(Item *A, Item **B){
    int len=0;
    /* shori */
    *B=malloc(sizeof(Item)*len);
}

void main(void){
    int ans=0;
    Item A[NUM], B[NUM];

    /* input */

    getBestItems(A, B);

    /* output */
}