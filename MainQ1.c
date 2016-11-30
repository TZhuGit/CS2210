//
//  main.c
//  piEstimate
//
//  Created by Tony Zhu on 2016-11-12.
//  Copyright © 2016 Tony Zhu. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>



int main() {
    
    
    int nAmount = -1;
    int tenTimes = 10;
    //Create an array to store the estimated pi values
    double pi[10];
    
    //Input of the N value
    while(nAmount <= 0){
    printf("Enter N: ");
    scanf("%d", &nAmount);
    }
    
    double ratioDen = nAmount;
    
    //Nested loop to store the estimated pi values 10 times in to an array with each estimated composed of
    //N coordinates
    while(tenTimes != 0){
        nAmount = ratioDen;
        int count = 0;
        
        while (nAmount!=0) {
            
            //Random variable divided by the max value of the random function, so that the double
            //is between 0 and 1
            double x = ((double) rand() / (RAND_MAX));
            double y = ((double) rand() / (RAND_MAX));
        
    
            double coordinates = (pow(x, 2)+pow(y,2));
            //Print functions to check code
            //printf("The coordinates are %f \n", coordinates);
            if(coordinates <= 1){
                count = count + 1;
            
            }
        
            nAmount = nAmount - 1;
        }
        double ratio = count/(double)ratioDen;
        double piEstimation = ratio*4;
        
        //printf("The estimate value of %f \n", piEstimation);
        pi[tenTimes-1]=piEstimation;
        tenTimes = tenTimes -1;
        
    }
    
    
    //To calculate the average
    double total = 0;
    for(int j = 0 ; j <10; j++){
        //printf("%f \n",pi[j]);
        total = pi[j] + total;
    }
    
    double average = (double)total/10;
    double standardDeviation = 0;
    
    //To calculate the Standard deviation
    for(int k = 0 ; k <10; k++){
        standardDeviation = pow(pi[k]-average,2) + standardDeviation;
    }
    
    standardDeviation = standardDeviation/10;
    standardDeviation = sqrt(standardDeviation);
    
    printf("The average of value of pi for N = %f times is %f \n", ratioDen,average);
    printf("The standard devation of pi for N = %f is %f \n", ratioDen,standardDeviation);
    return 0;
}
