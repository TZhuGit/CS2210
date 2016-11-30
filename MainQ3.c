//
//  main.c
//  moneyChange
//
//  Created by Tony Zhu on 2016-11-14.
//  Copyright © 2016 Tony Zhu. All rights reserved.
//

#include <stdio.h>

//Prototype
void pay_amount(int dollars, int *twenties, int *tens, int *fives, int *toonies, int *lonnie);


int main() {
    
    //New variables and verify input
    int n=0, twenties, tens, fives, toonies, loonies;
    while(n<=0){
        printf("Enter the amount: ");
        scanf("%d", &n);
        if(n<=0){
            printf("Invalid amount, please try again \n");
        }
    }
    
    //Call function with amount and address of the money variables
    pay_amount(n, &twenties, &tens, &fives, &toonies, &loonies);
    return 0;
}

void pay_amount(int dollars, int *twenties, int *tens, int *fives, int *toonies, int *lonnie){
    
    //Change the value of the location of each pointer to match how much of each bill should be
    *twenties = dollars/20;
    //Then subtract the actual amount from the total for the next bill
    dollars = dollars - (*twenties * 20);
    
    *tens = dollars/10;
    dollars = dollars-(*tens * 10);
    
    *fives = dollars/5;
    dollars = dollars - (*fives * 5);
    
    *toonies = dollars/2;
    dollars = dollars-(*toonies*2);
    
    *lonnie = dollars/1;
    //Dollars will be at zero and no need for further subtraction
    
    printf("Your payment amount will be %d $20 bill(s), %d $10 bill(s), %d $5 bill(s), %d toonie(s), and %d loonie(s) \n", *twenties,*tens,*fives,*toonies,*lonnie);
    
}
