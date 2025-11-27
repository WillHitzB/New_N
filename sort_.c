#include <stdio.h>
#include <unistd.h>
//sorting elements 
//bubble sort

void menu();
void undefined_sort(int,int*);
void bubble_sort(int,int*);

void display_pro(int,int*);

int main(){
    char choice='y';
    while(1){
        menu();
    }
}
void menu(){
    int size;               //size = no of elements
    int option;

    printf("enter the number of numbers to be added : ");
    scanf("%d",&size);

    int arr[size];                          //array initialization and entry from user
    for (int i=0;i<size;i++){
        printf("Enter element %d = ",i+1);
        scanf("%d",&arr[i]);
    }
    int carr[size];                         //making a copy which is changed, not the original array;
    for (int i=0;i<size;i++){
        carr[i]=arr[i];
    }

    int* ptr = carr;                        //pointer init
    
    printf("Select what type of sort to use . \n\n1.Bubble Sort\n2.Unavailable Sort\n");
    scanf("%d",&option);

    printf("\033[3J\033[H\033[2J");
    printf("Before sort : \n");
    display_pro(size,ptr);
    sleep(2);
    printf("\033[3J\033[H\033[2J");
    display_pro(size,ptr);


    switch(option){
        case 1:
        printf("Using Bubble sort\n");
        display_pro(size,ptr);
        sleep(2);
        printf("\033[3J\033[H\033[2J");
        bubble_sort(size,ptr);
        break;
        case 2:
        printf("Using X sort\n");
        undefined_sort(size,ptr);
        break;
        default:
        printf("Invalid");
        break;
        }
    //printf("\033[3J\033[H\033[2J");
    display_pro(size,ptr); 
    printf("After sort ^ \n");       
}
void bubble_sort(int s,int* p){             //simple bubble sort 
    // printf("%d",p);
    for(int i=0;i<s-1;i++){
        for(int j=0;j<s-1-i;j++){
            if(*(p+j)>*(p+j+1)){
                int t= *(p+j);
                *(p+j)=*(p+j+1);
                *(p+j+1)=t;
            }
        
        }
        display_pro(s,p);
        sleep(2);
        printf("\033[3J\033[H\033[2J");
    }

    
}
void undefined_sort(int s, int* p){
    int first,last;
}
// void display(int s,int *p){                 //just simple display
//     for(int i=0; i<s; i++){
//         printf("%d  ",*(p+i));
//     }
// }
void display_pro(int length,int *p){
    char ch='0';
    int max=0;
    for (int i=0;i<length-1;i++){
        if (*(p+i) >max){
            max=*(p+i);
        }
    }
    for (int j=0;j<length;j++){
        int num = *(p+j);
        printf("| ");
        while(num!=0){
            printf("%c",ch);
            num--;
        }
        printf(" %d\n",*(p+j));
    }
    //printf("\033[3J\033[H\033[2J");
}