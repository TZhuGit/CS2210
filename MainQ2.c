//
//  main.c
//  MagicSquare
//
//  Created by Tony Zhu on 2016-11-13.
//  Copyright © 2016 Tony Zhu. All rights reserved.
//

#include<stdio.h>

int main() {
    
    //Input and validation of the correct N value
    int n=0;
    while(n<=0 || n>14 || (n%2==0)){
        printf("Enter size of magic square: ");
        scanf("%d", &n);
        if(n<=0 || n>14 || (n%2==0)){
            printf("Invalid size, please try again \n");
        }
    }
    
    //A 2d array of size n filled with zeros
    int magic_square[13][13] = {0};
    int rowCount = 0;
    int columnCount = n/2;
    int totalValues = n*n;
    
    for(int i = 1; i<=totalValues;i++){
        
        //Pointer to set 1 into the middle of the first row
        if ( i == 1 ){
            *(*(magic_square + rowCount)+columnCount) = i;

        }
        
        //For all other values move the pointer up and to the right one space and check if it's empty
        //if it's empty place the new value in
        //else place the new value below the current spot
        else if ((*(*(magic_square + ((rowCount-1+n)%n))+((columnCount+1)%n))) == 0){
            rowCount = (rowCount-1+n)%n;
            columnCount = (columnCount+1)%n;
            *(*(magic_square + rowCount)+columnCount) = i;
            
        }
        
        else {
            rowCount = (rowCount+1)%n;
            *(*(magic_square + rowCount)+columnCount) = i;
            
        }
        
    }
    
    //Print out the magic square with spaces adjusted for
    for (int row = 0; row < n; row ++){
        
        for(int col=0; col <n; col ++){
            printf(" %4.d", *(*(magic_square + row)+col));
        }
        printf("\n");
    }
    
    
    return 0;
}
