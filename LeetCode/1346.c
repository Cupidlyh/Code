#include <stdio.h>
#include <stdlib.h>

bool checkIfExist(int* arr, int arrSize){
    int i,j;
    for(i = 0; i < arrSize; i++) {//±éÀúÊý×é
        for(j = 0; j < arrSize; j++) {
            if(i == j)
                continue;
            if(arr[i] == 2 * arr[j])
                return true;
        }
    }
    return false;
}
