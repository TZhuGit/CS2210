//
//  main.c
//  TimeCalc
//
//  Created by Tony Zhu on 2016-10-25.
//  Copyright © 2016 Tony Zhu. All rights reserved.
//

#include <stdio.h>

int main(){
    int time = 0, duration = 0;
    int cHour = -1;
    int cMinutes = -1;
    
    //Validation conditions for the correct minute and hour input
    while( cHour > 23 || cHour < 0 || cMinutes < 0 || cMinutes > 59 ){
        printf("Enter a valid current time: ");
        scanf("%d", &time);
        cHour = time/100;
        cMinutes = time-(cHour*100);
        
        if (time == 2400){
            break;
        }
        else{
            ;
        }
    }

    
    
    int dHour = 0;
    int dMinutes = 60;
    
    //Only need to validate the minutes and not the hour
    while( dMinutes < -59 || dMinutes > 59 ){
        printf("Enter a valid time duration: ");
        scanf("%d", &duration);
        dHour = duration/100;
        dMinutes = duration-(dHour*100);
        
        
    }

    //simple calculation of the new time with % to keep the time within 24 hours and 59 minutes
    
    //Adding or minus an extra hour if the minutes is greater than +-60
    int extraHour = (cMinutes + dMinutes)/60;
    if (extraHour>0){
        dHour = dHour + extraHour;
    }
    int newMinutes = (cMinutes + dMinutes)%60;
    
    //Change negative minutes to positive
    if (newMinutes<0){
        cHour = cHour - 1;
        newMinutes = 60 + newMinutes;
    }
    
    int newHour = (cHour + dHour)%24;
    
    //Change negative hours to positive
    if (newHour<0){
        newHour = 24 + newHour;
    }
    
    
    printf("%02d%02d \n",newHour,newMinutes);
    return 0;
    
}
