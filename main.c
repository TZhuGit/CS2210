//
//  main.c
//  TestCQ
//
//  Created by Tony Zhu on 2016-11-05.
//  Copyright © 2016 Tony Zhu. All rights reserved.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    // insert code here...
    int i, j, k;
    i = j = k = 1;
    i += j += k;
    printf("%d %d %d \n", i ,j ,k );
    return 0;
}
