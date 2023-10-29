#include<stdio.h>
#include<ctype.h>

#define NUM_OF_CHARS 128
#define MAX_LENGTH 100

char *toonestring(int argc, char *argv[])
{
 char input[MAX_LENGTH]={'\0'};
 for(int i=1;i<argc;i++,n++)
 {
  for(int j=0;argv[i][j]!='\0';j++,n++)input[n]=argv[i][j];
  if(i!=(argc-1))input[n]=' ';
  if(n>MAX_LENGTH)
  {
   printf("Input is too long!\n");
   exit(0);
  }
 }
 return input;	
}

int tonewline(int i)
{
 int c;	
 while(c!='\n')
 {
  c=fgetc(stdin);//na konec radku
  if(i++>=MAX_LENGTH)
  {
   printf("Your file contains too long words!\n");
   exit(0);	   	  
  }
 }
 while(c=='\n')c=fgetc(stdin);
 return	c;
}

int main(int argc, char* argv[])
{
char c=fgetc(stdin);
int wordfound[MAX_LENGTH+1]={0};
int alphb[NUM_OF_CHARS]={0};
int n=0,k=0,enable=0,p=0;//counters
char *input=toonestring(argc,argv[]);

while(c!=EOF)
{	
 int i=0;
 while(c==' ' || c=='\n')c=fgetc(stdin);
 if(argc==1)alphb[(int)toupper(c)]=1;
 if(tolower(c)!=tolower(input[0]) || argc==1)
 {
  c=tonewline(i);//na novy radek
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
  k++;//pokud k je 1, vytisknout wordfound na konci
  p=1;//pokud p je 1, vytisknout wordfound na konci
 }else if(input[i]=='\0')//konec hledaneho radku
 {
  int kostyl1=(alphb[' ']==0)?0:2,kostyl2=(enable==0)?1:0;//kostyl1 a 2 jsou nutne aby netisknout zbytecne bile znaky v "Enable". kostyl2 urcuje jestli (zbytecny bily znak byl jedinym najdenym znakem)
  enable=1;  
  alphb[(int)toupper(c)]=1;//add new char found
  while(c!='\n')//zapis noveho wordfound
  {	   	  
   if(k==0)break;//vordfound uz je vytvoreno
   if(kostyl1<2 && c==' ')kostyl1=1;else kostyl1=2;//pokud radek v souboru obsahuje zbytecne bile znaky, kostyl1 je 1 
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
 c=tonewline(i);
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
