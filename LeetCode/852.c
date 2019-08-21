#include <stdio.h>
#include <stdlib.h>

int peakIndexInMountainArray(int* A, int ASize){//¶ş·Ö²éÕÒ
    int left=0,right=ASize-1;
    while(left<right){
        int mid=left+(right-left)/2;
        if(A[mid]<A[mid+1])
            left=mid+1;
        else
            right=mid;
    }
    return left;
}
