#include<iostream>
#include<iomanip>
#include<cstring>
using namespace std;
char str[1000],s;
int t=0;
void arrange(){
    
    while(cin>>s){
        if((s=='w')||(s=='x')||(s=='a')||(s=='d')||(s=='s')||(s=='t')||(s=='`')){
            str[t++] =s; 
        }    
    }
}
///////////////////////////////////////////////////////////////////////////////////
void skill(){
    int temp = 0;
    while(temp<t){
        if(((str[temp]=='a')&&(str[temp+1]=='a')&&(str[temp+2]=='s'))||((str[temp]=='d')&&(str[temp+1]=='d')&&(str[temp+2]=='s'))){
            printf("Soul_Punch\n");
            temp+=2;
        }
        else if(str[temp]=='`'){
            temp++;
            if(str[temp]=='w'){
                temp++;
                if(str[temp]=='s'){
                    printf("Uppercut\n");
                }
                else if(str[temp]=='t'){
                    printf("Big_Bang\n");
                }
                else    
                    temp-=2;
                
            }
            else if((str[temp]=='t')){
                temp++;
                if(str[temp]=='s'){
                    temp++;
                    if(str[temp]=='t'){
                        printf("Mirror_Image\n");
                        while(str[temp+1]=='t'){
                            temp++;
                        }
                    }
                    else    
                        temp-=3;
                }
            }
            else if((str[temp]=='d')){
                temp++;
                if(str[temp]=='t'){
                    printf("Soul_Bomb\n");
                }
                else if(str[temp]=='s'){
                    printf("Skull_Blast\n");
                        while(str[temp+1]=='s'){
                            temp++;
                        }
                }
                else
                    temp-=2;
            }
            else    
                temp--;
             
        }
       
        
        temp++;
    }
}
int main(){
    arrange();
    skill();   
  //  cout<<str;
}