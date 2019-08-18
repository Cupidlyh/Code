#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int arr[50000];
    int num;//��¼���������ж��ٸ�Ԫ��
} RandomizedSet;

/** Initialize your data structure here. */

RandomizedSet* randomizedSetCreate() {
    RandomizedSet *obj=(RandomizedSet *)malloc(sizeof(RandomizedSet));
    obj->num=0;
    memset(obj->arr,0,sizeof(obj->arr));//����ĳ�ʼ��
    return obj;
}

/** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
bool randomizedSetInsert(RandomizedSet* obj, int val) {
    int i,j;
    if(obj->num==0){//����Ϊ��ʱ��ֱ�Ӳ���Ϳ���
        obj->arr[0]=val;
        obj->num=1;
        return true;
    }
    else{//�ҵ�������Ԫ�صĴ洢�ǰ���С����˳��洢��
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
                    obj->arr[j]=obj->arr[j-1];//Ԫ�غ���
                 obj->arr[i]=val;//������Ԫ��
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
                obj->arr[j]=obj->arr[j+1];//Ԫ��ǰ��
            obj->num--;
            return true;
        }
    }
    return false;
}

/** Get a random element from the set. */
int randomizedSetGetRandom(RandomizedSet* obj) {
    int res=0,i;
    for(i=0;i<obj->num;i++){//�����������ȡ�ĺ��Ĵ���
        res=(rand()%(i+1)==0)?obj->arr[i]:res;
    }
    return res;
}

void randomizedSetFree(RandomizedSet* obj) {
    free(obj);//�ͷ�
}

/**
 * Your RandomizedSet struct will be instantiated and called as such:
 * RandomizedSet* obj = randomizedSetCreate();
 * bool param_1 = randomizedSetInsert(obj, val);

 * bool param_2 = randomizedSetRemove(obj, val);

 * int param_3 = randomizedSetGetRandom(obj);

 * randomizedSetFree(obj);
*/
