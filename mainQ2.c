//
//  InterestCalc.c
//  TimeCalc
//
//  Created by Tony Zhu on 2016-10-25.
//  Copyright © 2016 Tony Zhu. All rights reserved.
//

#include <stdio.h>
int main(){
    int numOfPayments = 0;
    float loanAmount = 0, rate = 0, paymentAmount = 0, balance;
    
    //make sure positive values for each of the four inputs
    while(loanAmount <= 0){
        printf("Enter the loan amount: ");
        scanf("%f", &loanAmount);
        
    }
    //Initiating inital balance
    
    balance = loanAmount;
    while(rate<=0){
        printf("Enter the annual interest rate: ");
        scanf("%f", &rate);
        
    }
    
    //Calculated monthly rate conversion from % to decimal
    float monthlyRate = (rate/12)/100;
    
    while(paymentAmount<=0){
        printf("Enter the monthly payment amount: ");
        scanf("%f", &paymentAmount);
        
    }
    
    while(numOfPayments<=0){
        printf("Enter the number of payments you wish to make: ");
        scanf("%d", &numOfPayments);
        
    }
    
    while(numOfPayments !=0){
        //If statement for if the client pays off all of his balance before the indicated number of payments
        if (balance < paymentAmount){
            printf("Your last payment amount was only $%.2f \n", balance);
            printf("Your balance is at $0.00 \n");
            break;
        }
        balance = balance*(1+monthlyRate) - paymentAmount;
        printf("Your current balance is: $%.2f \n", balance);
        numOfPayments = numOfPayments - 1;
    }
    
    return 0;
}
