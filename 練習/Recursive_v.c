#include<stdio.h>
#include<stdlib.h>
#include<string.h>
/////////////////////////
char str[10000]; 
int detII=3;//0:id 1:assign 2:inum 
int temp=0;//str�r���첾 
int tempG=0;
int i; 
int quit=0;
/////////////////////////
typedef enum {f=-1, id=0, assign=1, inum=2 
}type;
type setG[10000];
struct token{
	type token;
}ans;
int detTaken(int type, int detII){
	if(detII==3){
		if(type==0)
     	  detII = 0;
		else if(type==1)
		  detII = 1;
	    else if(type==2)
		  detII = 2;
	}
	else
	  if((type!=detII)||((detII==1)&&(detII==type)))
		detII=-1;
		
	return detII;
}
/////////////Grammer///////////////////////////
int Val(type g[], int i){
	if(g[i]==id){
		i++;
		if(g[i]==assign){
			i++;
		 Val(g,i); 
	    }
	    else 
	      return 0;
    }
    else if((g[i]==inum)&&(i==(tempG-1))){
    	return 1;
	}
	else {
		 return 0;	
	}
	     
}
int Procs(type g[], int c){
	return Val(g, c);
}

//////////////////////////////////////////////
void Scan(){
	char s;
	while(~scanf("%s", str)) {
		s=getchar();
			while(*(str+temp)!='\0'){
    		if(((*(str+temp)>='A')&&(*(str+temp)<='Z'))||((*(str+temp)>='a')&&(*(str+temp)<='z'))){
    			detII=detTaken(0,detII); 
                if(detII==0)
    		      ans.token = id;
                else 
                  ans.token = f;
			}
			else if(*(str+temp)=='='){
				detII=detTaken(1,detII);
				if(detII==1)
    		      ans.token = assign;
                else 
                  ans.token = f;
			}
    		else if(((*(str+temp)>='0')&&(*(str+temp)<='9'))||(*str=='-')){
    			if((*(str+temp)=='-')&&(temp!=0)){
    				ans.token = f;
				}
				else{
				detII=detTaken(2,detII);
    		    if(detII==2)
    		      ans.token = inum;
                else 
                  ans.token = f;	
				}		
			}
			else
				ans.token=f;
			
			temp++;//�r�겾��
			if(ans.token==f)//�L��token���� 
			  break;
		}
	/////////////token���X///////////// 
	    setG[tempG++] = ans.token;
	///////////��l///////////////////
    detII=3;
    temp=0;
    /////////����+��X////////////////////
        if(ans.token==f){
        	printf("Token mismatch.");
        	break;
		}
    		  
    	if(s=='\n'){
    		int a = Procs(setG,0);
    		if(a==0)
    		  printf("Grammar mismatch.");
    		else 
			   printf("TA is handsome.");
    		break;
		}
 	//////////////////////////////////
		   
	}		
}
int main(){
	
	Scan();
	
/*	
		switch(ans.token){  
	    case id:
	      printf("ID ");
	      break;
	    case assign:
	    	
		  printf("assign ");
		  break;
		case  inum:  
		  printf("inum ");
		  
		  break;
		default:
		  printf("token���~");
	}*/
 }

