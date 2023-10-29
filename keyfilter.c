#include<stdio.h>
#include<ctype.h>

#define NUM_OF_CHARS 128
#define MAX_LENGTH 100

int main(int argc, char* argv[])
{
	char c=fgetc(stdin);
	int wordfound[MAX_LENGTH+1]={0};
	int alphb[NUM_OF_CHARS]={0};
	int n=0,k=0,enable=0,p=0;//counters
	char input[MAX_LENGTH]={'\0'};

	for(int i=1;i<argc;i++,n++)
	{
	 for(int j=0;argv[i][j]!='\0';j++,n++)input[n]=argv[i][j];
	 if(i!=(argc-1))input[n]=' ';
	 if(n>MAX_LENGTH)
	 {
	  printf("Input is too long!\n");
	  return 1;
	 }
	}

	while(c!=EOF)
	{	
	 int i=0;
	 while(c==' ' || c=='\n')c=fgetc(stdin);
	 if(argc==1)alphb[(int)toupper(c)]=1;
	 if(tolower(c)!=tolower(input[0]) || argc==1)
	 {
          while(c!='\n')c=fgetc(stdin);
	  while(c=='\n')c=fgetc(stdin);
	  continue;
	 }
	 for(i=0;tolower(input[i])==tolower(c);i++)
	 {
	  if(k==0)wordfound[i]=(int)c;//sestavit wordfound
	  c=fgetc(stdin);
	 }
	 if(input[i]=='\0' && c=='\n')//presny match
	 {
	  for(int j=i;j<MAX_LENGTH+1;j++)wordfound[j]=0;
	  k++;//pokud je 1, vytisknout wordfound na konci
	  p=1;
	 }else if(input[i]=='\0')//konec hledaneho radku
	 {
	  int kostyl1=(alphb[' ']==0)?0:2,kostyl2=(enable==0)?1:0;
	  enable=1;  
	  alphb[(int)toupper(c)]=1;//add new char found
	  while(c!='\n' && k==0)
	  {	   	  
	   if(kostyl1<2 && c==' ')kostyl1=1;else kostyl1=2; 
	   wordfound[i]=(int)c;
	   c=fgetc(stdin);
	   if(i++>=MAX_LENGTH)
	   {
	    printf("Your file contains too long words!\n");
	    return 1;
	   }
	   if(kostyl1==1)
	   {
            alphb[' ']=0;
	    if(kostyl2==1)enable=0;
	   }
	  }
	  k++;
	 }else if(k==0)
	  {
	   for(int j=0;j<MAX_LENGTH+1;j++)wordfound[j]=0;//nove wordfound
	  }
	 
	 while(c!='\n')
	 {
	  c=fgetc(stdin);//na konec radku
	  if(i++>=MAX_LENGTH)
	  {
	   printf("Your file contains too long words!\n");
	   return 1;	   	  
	  }
	 }
	 while(c=='\n')c=fgetc(stdin);
	}

	if(p==1 || k==1)
	{
	 printf("Found: ");
	 for(int i=0;wordfound[i]!=0;i++)printf("%c",wordfound[i]);
	 printf("\n");
	}else if(k==0 && argc!=1)printf("Not found\n");

	if(enable || argc==1)
	{
	 printf("Enable: ");
	 for(int i=0;i<NUM_OF_CHARS;i++)
	 {
	  if(alphb[i])printf((i==' ')?"' ' ":"%c ",toupper(i));//zkouska %d '.'
	 }
 	 printf("\n");
	}
}
