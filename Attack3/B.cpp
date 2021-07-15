#include<iostream>
#include<iomanip>
#include<string.h>
using namespace std;
string str;
int s,i=0;
int stack[1000],top=0;;
//////////////////////////
int atoi(char c){
    return (c-'0');
}

void push(int item){
    top++;
    stack[top]=item;
}
int pop(){
    int item;
    if(top==0){
        return -1;
    }
    else{
        item=stack[top];
        top--;
        return item;
    }
    
}
//////////////////////////////////
int main(){
    int x,y;
    while(getline(cin,str)){
            if((str[0]=='l')&&(str[1]=='o')&&(str[2]=='a')&&(str[3]=='d')){
                push(atoi(str[5]));
            }
            else if((str[0]=='a')&&(str[1]=='d')&&(str[2]=='d')){
                x=pop();
                if(top==0){
                    break;
                }
                y=pop();
                push(x+y);     
            }
            else if((str[0]=='s')&&(str[1]=='u')&&(str[2]=='b')){
                x=pop();
                if(top==0){
                    break;
                }
                y=pop();
                push(x-y);     
            }
            else if((str[0]=='m')&&(str[1]=='o')&&(str[2]=='d')){
                x=pop();
                if(top==0){
                    break;
                }
                y=pop();
                push(x%y); 
            }
            else if((str[0]=='i')&&(str[1]=='n')&&(str[2]=='c')){
                x=pop();
                x++;
                push(x);
            }
            else if((str[0]=='c')&&(str[1]=='o')&&(str[2]=='p')&&(str[3]=='y')){
                push(stack[top]);
            }
            else if((str[0]=='d')&&(str[1]=='e')&&(str[2]=='l')&&(str[3]=='e')&&(str[4]=='t')&&(str[5]=='e')){
                pop();
            }
            else if((str[0]=='s')&&(str[1]=='w')&&(str[2]=='i')&&(str[3]=='t')&&(str[4]=='c')&&(str[5]=='h')){
                x=pop();
                if(top==0){
                    break;
                }
                y=pop();
                push(x); 
                push(y);
            }
    }
        if(top==1)
            printf("%d\n",stack[top]);
        else
            printf("Invalid format\n");
        
    
}