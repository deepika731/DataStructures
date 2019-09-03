#include<stdio.h>
#include<stdlib.h>
#include<time.h>
typedef struct node np;
struct node{
    int data;
    np *up;    
    np *down;
    np *left;
    np *right;
};
np *list=NULL;
int height=1,width=1;
int toss_coin();
np *createNode();
void print_sl();
void toss_it(np *x);
int search_sl(int item);
int delete_sl(int item);
int insert_sl(int item);
int main(){
    srand(time(NULL));
   
    //option for choice
    int choice=1;
    while(choice!=0){
        printf("\nOption for operation:\n 0)Exit 1)insert 2)search 3)print List 4)delete\nOption: ");
        scanf("%d",&choice);
        while(choice<0 || choice>4){
            printf("Select correct option: ");
            scanf("%d",&choice);
        }
        int data;
        switch(choice){
            case 1:
                printf("\nEnter a nonnegative value: ");
                scanf("%d",&data);
                if(insert_sl(data)==1){
                    printf("\n%d was inserted successfully\n",data);                   
                }
                else{
                    printf("\n%d was not inserted!!\n",data);
                }
                break;
            case 2:
                printf("\nEnter a value to search: ");
                scanf("%d",&data);
                if(search_sl(data))
                    printf("\n%d has been found.\n",data);
                else
                    printf("\n%d is not available.\n",data);
                break;   
            case 3:
                print_sl();
                break;
            case 4:
                printf("\nEnter a value to delete: ");
                scanf("%d",&data);
                if(delete_sl(data))
                    printf("\n%d has been deleted.\n",data);
                else
                    printf("\n%d is not available.\n",data);
                break;            
        }
    }   
}

int delete_sl(int item){
    np *curr=list,*temp;
    int down_count=0;
    while(curr!=NULL){
        temp=curr;
        if(curr->right && curr->right->data<item){
            curr=curr->right;
            printf("Right-");
        }
        else if(curr->right && curr->right->data==item){
            np *node=curr->right;
            while(node){//go down one by one
                if(node->left->data==-1 && node->right==NULL){
                    down_count++;//count the level from uppermost level       
                }
                if(node->right){
                    node->right->left=node->left;
                    node->left->right=node->right;               
                }
                else{
                    node->left->right=NULL;
                }
                np *nd=node->down;
                free(node);
                node=nd;           
            }
            //update the width and height
            width--;
            height=height-down_count;
            return 1;
        }
        else {
            curr=curr->down;
            printf("Down-");
        }
    }
    return 0;
    printf("\n");   
}

int search_sl(int item){
    np *curr=list,*temp;
    while(curr!=NULL){
        temp=curr;
        if(curr->right && curr->right->data<item){
            curr=curr->right;
            printf("Right-");
        }
        else if(curr->right && curr->right->data==item)return 1;
        else {
            curr=curr->down;
            printf("Down-");
        }
    }
    return 0;
    printf("\n");   
}

int insert_sl(int item){
    if(item<0)return 0;
    if(!list){//for the first item
        list=createNode();
        np *newnode=createNode();
        list->right=newnode;
        newnode->left=list;
        newnode->data=item;
        //toss to go upper level
        toss_it(list->right);
        width++;
        return 1;
    }
    //if list is not empty, find the right position
    np *curr=list,*temp;
    while(curr!=NULL){
        temp=curr;
        if(curr->right && curr->right->data<item){
            curr=curr->right;
            printf("Right-");
        }
        else if(curr->right && curr->right->data==item)return 0;
        else {
            curr=curr->down;
            printf("Down-");
        }
    }
    printf("\n");   
    np *newnode=createNode();
    newnode->data=item;
    if(temp->right==NULL){//when added at the right most
        temp->right=newnode;
        newnode->left=temp;
    }
    else{//when added between two nodes
        newnode->left=temp;
        newnode->right=temp->right;
        temp->right->left=newnode;
        temp->right=newnode;       
    }       
    toss_it(newnode);
    width++;
    return 1;   
}

void toss_it(np *x){
    int h=1;
    while(toss_coin()){
        printf("\nToss Win");
        h++;
        if(h>height){//create a new level
            height=h;
            np *ln=createNode();
            ln->down=list;
            list->up=ln;
            list=ln;
            //add the node to the new level
            np *newnode=createNode();
            ln->right=newnode;
            newnode->data=x->data;
            newnode->down=x;
            newnode->left=ln;
            x->up=newnode;
            x=newnode;
        }
        else{//add the node to an existing level       
            np *temp=x->left;
            while(temp->up==NULL){
                temp=temp->left;
            }
            temp=temp->up;
            np *newnode=createNode();
            newnode->data=x->data;
            newnode->left=temp;
            newnode->down=x;
            temp->right=newnode;
            x->up=newnode;
            x=newnode;
        }   
    }   
}

np *createNode(){
    np *newnode=(np *)malloc(sizeof(np));
    newnode->data=-1;
    newnode->left=NULL;
    newnode->down=NULL;
    newnode->up=NULL;
    newnode->right=NULL;
    return newnode;
}

void print_sl(){
    if(!list)return;
    int v[height][width],i,j;
    for(i=0;i<height;i++){
        for(j=0;j<width;j++){
            v[i][j]=-1;
        }
    }
   
    np *base=list;
    for(base=list;base->down;base=base->down);
    j=0;
    for(;base;base=base->right){
        i=height-1;
        np *goup=base;
        for(;goup;goup=goup->up){
            v[i][j]=goup->data;
            i--;           
        }
        j++;       
    }
    printf("\n");
    for(i=0;i<height;i++){
        for(j=1;j<width;j++){
            if(v[i][j]==-1){
                printf(" - ");
            }
            else{
                printf("%3d",v[i][j]);
            }
        }
        printf("\n");
    }
    printf("\n");
}

int toss_coin(){
    float t=(float)(rand()%100)/100;
    return t>0.5?1:0;
}
