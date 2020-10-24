#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void GetNext(char * child, int * next){
    int i = 0;
    int j = -1;
    next[0] = -1;
    int child_length = strlen(child);
    while(i < child_length){
        if(j == -1 || child[i] == child[j]){
            i++;
            j++;
            next[i] = j;
        }else{
            j = next[j];
        } 
    }
}

int KMP(char * child, char * father){
    int next[255] = {0};
    GetNext(child, next);
    int i = 0;
    int j = 0;
    int child_length = strlen(child);
    int father_length = strlen(father);
    while(i < father_length && j < child_length){
        if(j == -1 || child[j] == father[i]){
            i++;
            j++;
        }else{
            j = next[j];
        }
    }
    if(j == strlen(child)){
        return i - j + 1;
    }
    return -1;
}

int main(){
    char father[] = {"wocaozheshishadongxihahahahahaokuo"};
    char child[] = {"xiha"};
    int num = KMP(child, father);
    if(num == -1) printf("没有找到下标\n");
    else printf("找到了，下标为%d\n", num);

    return 0;
}