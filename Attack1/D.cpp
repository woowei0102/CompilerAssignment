#include<iostream>
#include<iomanip>
#include<string.h>
using namespace std;
char str[1000];
int top=0;// stack
char s;
int temp=0;
int tempG=0;
int tempF=0;
int i; 
int pn=-1;
int d,d1=0;
/*/////////////////////////////////////////////
typedef enum {num=0, plus=1, minus=2, mul=3, div=4, lpr=5, pdr=6 
}type;*/
struct token{
	int type;
    int Val=0;
    int priority=-1;//0:(內 1:+- 2:*/ 3:正負 4:(外
    
}setG[1000],post[1000],stack[1000];
//////////////////////////////////////////
/////////////Grammer原型宣告//////////////////////////////////////////
int factor(int x);
int term_tail(int x);
int expr_tail(int x);
int term(int x);
int expr(int x);
//////////////////////////////////////////////////////////////
void arrange(){
    int i = 0;
    while(cin>>s){
        if((s!=' ')||(s!='\n')){
            str[i++] =s; 
        }    
    }
}
int atoi(char c){
    return (c-'0');
}
int ScanDigit(int t, int g){ //temp,tempG//
    if((*(str+t)>='0')&&(*(str+t)<='9')){
        if(setG[g-1].priority==3){

            if(setG[g-1].type==1){
               pn=0;
            }
            else if(setG[g-1].type==2){
                pn=1;
            }
            g--;
            tempG--;
        }
        setG[g].Val=setG[g].Val*10+atoi(*(str+t));
        setG[g].type = 0;
        setG[g].priority=-1;
        t++;
        ScanDigit(t,g);
    }
    else{
        if(pn==1)
            setG[g].Val=0-setG[g].Val;
        pn=-1;
         return t;
    }
        
}
void push(struct token s[] ,struct token item){
    if(item.priority==4)
        item.priority=0;
    top=top+1;
    stack[top]=item;
}
struct token pop(struct token s[]){
    struct token item;
    if (top==0)
        printf("Stack is Full!\n");
    else{
        item=stack[top];
        top=top-1;
        return item;
    }
    
    

}
int postfix(int t){
    int i = 0;
    int k = 0;
    int a=0,b=0;
    struct token x,y;
    while(i<t){
        if(setG[i].type==0){
            post[k++]=setG[i];
            a++;
        }
        else{
            if(setG[i].type==6){
                do{
                    y=pop(stack);  
                     
                    if(y.type!=5)
                        post[k++]=y;
                }while(y.type!=5);
               
                tempF+=2;
                
            }
            else{
                if(top==0){
                    push(stack,setG[i]);
                }
                else if(setG[i].priority>stack[top].priority){
                    push(stack,setG[i]);
                    
                }
                else{
                    do{
                    y=pop(stack); 
                    
                    post[k++]=y;
                    }while(setG[i].priority>y.priority); 
                    push(stack,setG[i]);
                  
                }
               
            }
            b++;
        }
        i++;
    }
    b-=tempF;
    //printf("%d %d %d\n",tempF,a,b);
    if((a-1)!=b)
        return 0;
     while(top!=0){
        y=pop(stack);
        post[k++]=y;
    }
    return 1;
}
void Scan(){
    while(*(str+temp)!='\0'){
        if((*(str+temp)>='0')&&(*(str+temp)<='9')){
           temp =  ScanDigit(temp,tempG)-1;
           setG[tempG++].type = 0;
        }
        else if(*(str+temp)=='+'){
            if((setG[tempG-1].type>0)&&(setG[tempG-1].type<=5)){
                setG[tempG].priority = 3;
                setG[tempG++].type = 1;
            }
            else{
                setG[tempG].priority = 1;
                setG[tempG++].type = 1;
            }
            if((*(str+temp-1)=='*')||(*(str+temp-1)=='/')){
                pn=0;
            }
            
        }
        else if(*(str+temp)=='-'){
            if((setG[tempG-1].type>0)&&(setG[tempG-1].type<=5)){
                setG[tempG].priority = 3;
                setG[tempG++].type = 2;
            }
            else{
                setG[tempG].priority = 1;
                setG[tempG++].type = 2;
            }
            if((*(str+temp-1)=='*')||(*(str+temp-1)=='/')){
                pn=0;
            }
        }
        else if(*(str+temp)=='*'){
            setG[tempG].priority = 2;
            setG[tempG++].type = 3;
        }
        else if(*(str+temp)=='/'){
            setG[tempG].priority = 2;
            setG[tempG++].type = 4;
        }
        else if(*(str+temp)=='('){
            setG[tempG].priority = 4;
            setG[tempG++].type = 5;
        }
        else if(*(str+temp)==')'){
            setG[tempG++].type = 6;
        }
        temp++;
    }
}
int ErrorHandling(){
    int pr=0,PNsign=0,t=0,p=1;
    while(*(str+t)!='\0'){
        if((*(str+t)>='0')&&(*(str+t)<='9')){
            if((*(str+t)=='0')&&(*(str+t-1)=='/')){
                printf("Error: Divided by Zero.\n");
                return 4;
            }
            PNsign=0;
            p=0;
            t++;
        }
            
        else if((*(str+t)=='+')||(*(str+t)=='-')){
                PNsign++;         
            if((PNsign==3)||((PNsign==2)&&(p==1))){
                printf("Error: Unexpected token '%c'.\n",*(str+t));
                return 2;
            }
            t++;
        }
        else if((*(str+t)=='*')||(*(str+t)=='/')){
            if((*(str+t-1)=='+')||(*(str+t-1)=='-')){
                 printf("Error: Unexpected token '%c'.\n",*(str+t));
                 return 2;
            }
            PNsign=0;
            p=0;
            t++;
        }
        else if((*(str+t)=='(')){
            p=1;
            pr++;
            PNsign=0;
            t++;
        }
        else if(*(str+t)==')'){
            pr--;
            if(pr<0){
               printf("Error: Unexpected token '%c'.\n",*(str+t));
            return 2;
            }
            PNsign=0;
            p=0;
            t++;
        }
        else{
            printf("Error: Unrecognized token '%c'.\n",*(str+t));
            return 2;
        }
    }
      if(pr>0){
        printf("Error: Unexpected token 'EOF'.\n");
        return 3;
    }
    else    
        return 1;
}
////////////////////////////////////////////////////
int main(){
    arrange();
    Scan();
    d = ErrorHandling();
    if(d==1){
        
        if(expr(0)!=-1){
            d=postfix(tempG);
            
        }
            
    }
    if(d==1)
        printf("Correct.\n");
     
       /* for(int i=0;i<(tempG);i++){
        printf("%d %d %d\n",setG[i].type,setG[i].Val,setG[i].priority);
        //printf("%d %d %d\n",post[i].type,post[i].Val,post[i].priority);
       } */
    //cout << str;
}
//////////////////Grammer///////////////////////////
int factor(int i){
    if(i!=-1){
       if(setG[i].type==5){
        i++;
        i=expr(i);
        if(setG[i].type==6){
            i++;
            return i;
        }    
        else{
            d=0;
            if(i!=-1){
                if(setG[i-1].type==1){
                    printf("Error: Unexpected token '+'.\n");  
                }
                else if(setG[i-1].type==2){
                    printf("Error: Unexpected token '-'.\n");
                }
                else if(setG[i-1].type==3){
                    printf("Error: Unexpected token '*'.\n");  
                }
                else if(setG[i-1].type==4){
                    printf("Error: Unexpected token '/'.\n");
                }
                else if(setG[i+-1].type==5){
                    printf("Error: Unexpected token '('.\n");
                }
            }
            return -1;
        }
           
        }
        else if((setG[i].type==1)||(setG[i].type==2)){
            i++;
            if(setG[i].type==0){
                 i++;
                return i;
            }
            else{
                if(setG[i].type==1){
                    printf("Error: Unexpected token '+'.\n");  
                }
                else if(setG[i].type==2){
                    printf("Error: Unexpected token '-'.\n");
                }
                else if(setG[i].type==3){
                    printf("Error: Unexpected token '*'.\n");  
                }
                else if(setG[i].type==4){
                    printf("Error: Unexpected token '/'.\n");
                }
                else if(setG[i].type==5){
                    printf("Error: Unexpected token '('.\n");
                }
                d=0;
                return -1;
            }
           
        }
        else if(setG[i].type==0){
           
            i++;
            return i;
        }
        else{
             d=0;
            if(setG[i].type==3){
                printf("Error: Unexpected token '*'.\n");  
            }
            else if(setG[i].type==4){
                printf("Error: Unexpected token '/'.\n");
            }
            else if(setG[i].type==6){
                printf("Error: Unexpected token ')'.\n");
            }
            return -1;
        }
 
    }
    else    
        return -1;
    

}
int term_tail(int i){
    if(i!=-1){
       if((setG[i].type==3)||(setG[i].type==4)){
         i++;
         return term_tail(factor(i));
        }
         else 
            return i; 
    }
    else    
        return -1;
     
}
int expr_tail(int i){
    if(i!=-1){
        if((setG[i].type==1)||(setG[i].type==2)){     
        i++;
        return expr_tail(term(i));
     }
        else  
            return i;
    }
    else    
        return -1;
}
int term(int i){
    if(i!=-1)
        return term_tail(factor(i));
    else    
        return -1;
}
int expr(int i){
    if(i!=-1)
        return expr_tail(term(i));
    else    
        return -1;
}
///////////////////////////////////////////////////////