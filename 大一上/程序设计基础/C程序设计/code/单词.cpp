#include<stdio.h>
#include<stdio.h> 
int main(void)
{
	char string[81],c;  
	int i,num=0,word=0;
    gets(string);                           
    for (i=0;(c=string[i])!='\0';i++) 
        if(c==' ') 
			word=0; 
        else if(word==0) 
		{ 	word=1; 
	        num++; 
		}
     printf("%d words\n",num); 	
     return 0; 
} 
