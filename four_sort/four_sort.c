#include <stdio.h>
#include <limits.h>
#include <string.h>
void bubble_sort(int nums[],int len);
void select_sort(int nums[],int len);
void insert_sort(int nums[],int len);
void insert_sort(int nums[],int len);
void count_sort(int nums[],int len);
void print_num(int nums[],int len);
void main(){
    int nums[10]={3,1,4,7,8,10,2,5,6,9};
    //数组参数传递，形参穿的类似指针变量，如果直接在函数中计算则为8/4=2
    int len = sizeof(nums)/sizeof(nums[0]);
    bubble_sort(nums,len);
    select_sort(nums,len);
    insert_sort(nums,len);
    count_sort(nums,len);
}

void bubble_sort(int nums[],int len){
    for(int i=0;i<len;i++){
        int flag = 1;
        for(int j=len-1;j>i;j--){
            //遇到小的，前移
            if(nums[j] < nums[j-1]){
                int temp = nums[j];
                nums[j] = nums[j-1];
                nums[j-1] = temp;
                flag =  0;
            }
        }
        if(flag)break;
    }
    print_num(nums,len);
}

void select_sort(int nums[],int len){
    int min = INT_MAX;
    int min_p = 0;
    for(int i=0;i<len;i++){
        for(int j=i;j<len;j++){
            if(min > nums[j]){
                min = nums[j];
                min_p = j;
            }
        }
        //说明是不稳定的
        nums[min_p] = nums[i];
        nums[i] = min;
        min = INT_MAX;
    }
    print_num(nums,len);
}

void insert_sort(int nums[],int len){
    int j,temp;
    for(int i=1;i<len;i++){
        temp = nums[i];
        for(j=i-1;j>=0 && nums[j]>temp;j--){
            nums[j+1] = nums[j];
        }
        nums[j+1] = temp;
    }
    print_num(nums,len);
}

void count_sort(int nums[],int len){
    int min = nums[0];
    int max = nums[0];
    for(int i=0;i<len;i++){
        min = min < nums[i]?min:nums[i];
        max = max > nums[i]?max:nums[i];
    }
    int new_numsl = max - min + 1;
    int new_nums[new_numsl];
    int out_nums[len];
    memset(new_nums,0,sizeof(new_nums)/sizeof(int));
    for(int i=0;i<len;i++){
        new_nums[nums[i]-min]++;
    }
    for(int i=0,j=0;i<new_numsl;i++){
        if(new_nums[i]!=0){
            out_nums[j++]= i+min;
            new_nums[i]--;
        }
    }
    print_num(out_nums,len);
}

void print_num(int nums[],int len){
    for(int i=0;i<len;i++){
        printf("%d,",nums[i]);
    }
    printf("\n");
}