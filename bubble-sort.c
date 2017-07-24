#include<stdio.h>

int main(int argc,char *args[]){

    //数の配列のリスト
    int num_list[] = {8,4,10,5,9,3,7,6,1,2};
    
    // num_listの配列の数
    int num_list_length = (sizeof(num_list)/sizeof(int));
    
    // カウンター
    int i,j,tmp;
    
    // ソート処理を行う
    for(i=0;i < (num_list_length-1);i++){
        for(j=(num_list_length-1); j>i ;j--){
            
            if(num_list[j-1] > num_list[j]){
                tmp = num_list[j];
                num_list[j] = num_list[j-1];
                num_list[j-1] = tmp;
            }
        }
    }
    
    for(i=0;i<num_list_length;i++){
        printf("%d,",num_list[i]);
    }
    printf("\n");
    
    return 0;
}

