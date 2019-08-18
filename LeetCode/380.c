#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int arr[50000];
    int num;//记录数组中已有多少个元素
} RandomizedSet;

/** Initialize your data structure here. */

RandomizedSet* randomizedSetCreate() {
    RandomizedSet *obj=(RandomizedSet *)malloc(sizeof(RandomizedSet));
    obj->num=0;
    memset(obj->arr,0,sizeof(obj->arr));//数组的初始化
    return obj;
}

/** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
bool randomizedSetInsert(RandomizedSet* obj, int val) {
    int i,j;
    if(obj->num==0){//数组为空时，直接插入就可以
        obj->arr[0]=val;
        obj->num=1;
        return true;
    }
    else{//我的数组中元素的存储是按从小到大顺序存储的
        for(i=0;i<obj->num;i++){
            if(obj->arr[i]==val)
                break;
            if(obj->arr[obj->num-1]<val){
                obj->arr[obj->num]=val;
                obj->num++;
                return true;
            }
            if(obj->arr[i]>val){
                for(j=obj->num;j>i;j--)
                    obj->arr[j]=obj->arr[j-1];//元素后移
                 obj->arr[i]=val;//插入新元素
                 obj->num++;
                 return true;
            }
        }
    }
    return false;
}

/** Removes a value from the set. Returns true if the set contained the specified element. */
bool randomizedSetRemove(RandomizedSet* obj, int val) {
    int i,j;
    if(obj->num==0)
        return false;
    for(i=0;i<obj->num;i++){
        if(obj->arr[i]>val)
            break;
        if(obj->arr[i]==val){
            for(j=i;j<obj->num-1;j++)
                obj->arr[j]=obj->arr[j+1];//元素前移
            obj->num--;
            return true;
        }
    }
    return false;
}

/** Get a random element from the set. */
int randomizedSetGetRandom(RandomizedSet* obj) {
    int res=0,i;
    for(i=0;i<obj->num;i++){//这两行是随机取的核心代码
        res=(rand()%(i+1)==0)?obj->arr[i]:res;
    }
    return res;
}

void randomizedSetFree(RandomizedSet* obj) {
    free(obj);//释放
}

/**
 * Your RandomizedSet struct will be instantiated and called as such:
 * RandomizedSet* obj = randomizedSetCreate();
 * bool param_1 = randomizedSetInsert(obj, val);

 * bool param_2 = randomizedSetRemove(obj, val);

 * int param_3 = randomizedSetGetRandom(obj);

 * randomizedSetFree(obj);
*/
