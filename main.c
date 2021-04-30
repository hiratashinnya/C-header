/*----------------------------------------------------*/
/* @file    main.c                                    */
/* @brief   extract best profit rate items            */
/* @date    2021.04.30                                */
/* @version 1.0.0                                     */
/* @auther  shinnya.hirata                            */
/*----------------------------------------------------*/
/*----include header----------------------------------*/
#include<stdio.h>
#include<stdlib.h>
#include "type_MAXMIN.h" /* define type & type MAXMIN */

/*----define macro------------------------------------*/
#define INPUT "input.txt"
#define OUTPUT "output.txt"
#define LEN_NAME 10 /* u2_length of item name */
#define ITEM_NUM 5  /* number of items     */

typedef ST
{
    U2 u2_No;
    U2 u2_BuyPrice;
    U2 u2_SellPrice;
    U2 u2_Rank;
    U1 u1_Name[LEN_NAME];
} Item;

/*----prototype declaration---------------------------*/
/* Extract the items with the highest profit ray.     */
U2 u2_GetBestItems(Item *, Item *);

/* Read file & set Items.                             */
/* Accepted formats are as follows.                   */
/* U2,U2,U2,U2,strings\n                              */
VD vd_InputItems(Item *);

/* Write extracted Items to a file.                   */
/* Writing formats are as follows (like csv).         */
/* u2_No,u2_BuyPrice,sellprice,u2_Rank,name\n            */
VD vd_OutputItems(Item *, U2);

/**/
void main(void){
    U2 u2_Num_B=0;
    Item st_A[NUM], st_B[NUM];

    /* input */
    vd_InputItems(&st_A[0]);

    /* extract items */
    u2_Num_B=u2_GetBestItems(&st_A[0], &st_B[0]);

    /* output */
    vd_OutputItems(&st_B[0], u2_Num_B);
}

/**/
U2 u2_GetBestItems(Item *st_A, Item *st_B){
    U2 u2_len=0;
    U2 i;
    float temp_max=0.0;
    float temp_rate;

    /* liner serach */
    for(i=0; i<NUM; i++){
        if(st_A[i].u2_BuyPrice == 0){ //Avoid division by zero Errors.
            printf("ERR!! A[%d]'s u2_BuyPrice is 0!\n");
            continue;
        }else{
            temp_rate=(st_A[i].u2_SellPrice - st_A[i].u2_BuyPrice) / st_A[i].u2_BuyPrice;
            if(temp_rate > temp_max){ //Update array st_B with Item with the maximum profit rate.
                st_B[0]=st_A[i];
                u2_len=1;
            }else if (temp_rate == temp_max){ //Add the product with the same rate of 1st place to array st_B.
                st_B[u2_len]=st_A[i];
                u2_len++;
            }
        }
    }
    return u2_len;
}

/**/
VD vd_InputItems(Item *items){
    FILE *fp;

    if((fp=fopen(INPUT, "r")) != NULL){
        while((fscanf(fp, "%d,%d,%d,%d,%s\n", &items->u2_No, &items->u2_BuyPrice, &items->u2_SellPrice, &items->u2_Rank, &items->name)) != EOF){
            items++;
        }
    }else{
        printf("%s is not opened!\n", INPUT);
        exit(1);
    }
}

/**/
VD vd_OutputItems(Item *items, U2 num){
    FILE *fp;
    U2 i;

    if((fp=fopen(OUTPUT, "w")) != NULL){
        for(i=0; i<num; i++){
            fprintf(fp, "%d,%d,%d,%d,%s\n", items[i].u2_No, items[i].u2_BuyPrice, items[i].u2_SellPrice, items[i].u2_Rank, items[i].name);
        }
    }else{
        printf("%s is not opened!\n", OUTPUT);
        exit(1);
    }
}