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

/*
Extract the items with the highest profit ray.
*/
int getBestItems(Item *A, Item *B){
    int len=0;
    int i;
    float temp_max=0.0;
    float temp_rate;

    /* liner serach */
    for(i=0; i<NUM; i++){
        if(A[i].buyprice == 0){ //Avoid division by zero Errors.
            printf("ERR!! A[%d]'s buyprice is 0!\n");
            continue;
        }else{
            temp_rate=(A[i].selprice - A[i].buyprice) / A[i].buyprice;
            if(temp_rate > temp_max){ //Update array B with Item with the maximum profit rate.
                B[0]=A[i];
                len=1;
            }else if (temp_rate == temp_max){ //Add the product with the same rate of 1st place to array B.
                B[len]=A[i];
                len++;
            }
        }
    }
    return len;
}
/*
Read file & set Items.
Accepted formats are as follows.
int,int,int,int,strings\n
*/
void inputItems(Item *items){
    FILE *fp;

    if((fp=fopen(INPUT, "r")) != NULL){
        while((fscanf(fp, "%d,%d,%d,%d,%s\n", &items->no, &items->buyprice, &items->selprice, &items->rank, &items->name)) != EOF){
            items++;
        }
    }else{
        printf("%s is not opened!\n", INPUT);
        exit(1);
    }
}

/*
Write extracted Items to a file.
Writing formats are as follows (like csv).
no,buyprice,sellprice,rank,name\n
*/
void outputItems(Item *items, int num){
    FILE *fp;
    int i;

    if((fp=fopen(OUTPUT, "w")) != NULL){
        for(i=0; i<num; i++){
            fprintf(fp, "%d,%d,%d,%d,%s\n", items[i].no, items[i].buyprice, items[i].selprice, items[i].rank, items[i].name);
        }
    }else{
        printf("%s is not opened!\n", OUTPUT);
        exit(1);
    }
}

void main(void){
    int num_B=0;
    Item A[NUM], B[NUM];

    /* input */
    inputItems(A);

    /* extract items */
    num_B=getBestItems(A, B);

    /* output */
    outputItems(B, num_B);
}