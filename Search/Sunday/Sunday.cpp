#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>

using namespace std;
//获取匹配串中每个元素最后一次出现的下标
int * getNext(char * match){
    int * next = (int *)malloc(sizeof(int) * 256);
    memset(next, -1, sizeof(int) * 256);
    
    for(int i = 0; i < strlen(match); i++){
        next[match[i]] = i; //若元素重复出现则直接覆盖下标
    }
    return next;
}

//Sunday算法 
int Sunday(char * src, char * match){
    if(src == NULL || match == NULL) return -1;

    int * next = getNext(match);

    int i = 0; 
    int j = 0;
    int k = i;

    while(i < strlen(src) && j < strlen(match)){
        if(src[i] == match[j]){ //若子串和被匹配串相同则同时向后移
            i++;
            j++;
        }else{  //若不相同则将子串后移
            if(k + strlen(match) < strlen(src)){
                k = k + strlen(match) - next[src[k + strlen(match)]];
                //  k + strlen(match)为当前在被匹配串中匹配的位置
                //  src[k + strlen(match)]为匹配失败后被匹配串的元素
                //  next[src[k + strlen(match)]]为这个元素在子串中最后一次出现的下标
                //                              若为-1 则表示这个元素没有在子串中出现 则被匹配串向后移动一位
                //                              若 > 0 则表示这个元素在字串中出现 则找到这个元素在字串中出现的最后一次的下标 然后将被匹配串移动到与字串同一个元素的位置
                i = k;
                j = 0;
            }else{  //被匹配串长度不足则直接匹配失败
                return -1;
            }
        }
    }
    if(j == strlen(match)){
        return k;
    }else{
        return -1;
    }

}
int main(){
    printf("%d\n", Sunday("qwedfsafasfsvzcxvasfsdafvzfadfas", "fas"));

    return 0;
}

