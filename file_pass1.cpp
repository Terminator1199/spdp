
#include<stdio.h>
#include<string.h>
#include<conio.h>
#include<stdlib.h>

struct MOT
{
 char mname[10];
 int nmopc,nmsize;
};

struct RT
{
 char rname[10];
 int rtopc;
};

struct POT
{
 char pname[10];
 int popc;
};

struct ST
{
 char sname[10];
 int len,val,addr;
};

struct LT
{
 char lname[10];
 int addr;
};

struct MOT m[5]=
{
 {"mov",41,4},
 {"add",42,4},
 {"sub",43,4},
 {"div",44,4}
};

struct POT p[5]=
{
 {"start",0},
 {"end",1},
 {"origin",2},
 {"ltorg",3}
};

struct RT r[5]=
{
 {"areg",1},
 {"breg",2},
 {"creg",3},
 {"dreg",4}
};

struct ST s[10];

struct LT l[5];

void main()
{
 FILE *fptr;

 int flag=0,flag1=0,i,j,f,num,x,z,lc=0,cnt=0,cnt1=0,cnt2=0,k,q,val1,y,flag2=0;
 float scnt;
 char ch,a[10],b[10],c[10],d[10],e[10],filename[10],ch1;
 clrscr();
 printf("\n Enter Filename:  ");
 scanf("%s",&filename);
 fptr=fopen(filename,"r");
  if(fptr==NULL)
  {
   printf("\n no file found");
   exit(0);
  }
  ch=fgetc(fptr);
  i=0;
   while(ch!=EOF)
   {
    if(flag==0)
    {
     if(ch==' ' || ch==',' || ch=='\n')
     {
      a[i]='\0';
      flag=1;
     }
     else
     {
      a[i]=ch;
       i++;
     //ch=fgetc(fptr);
     }
  }
  if(flag==1)
  {
   for(j=0;j<4;j++)
   {
    x=strcmp(p[j].pname,a);
    if(x==0)
    {
       if(j==0 || j==2)
      {
       ch=fgetc(fptr);
       z=0;
        while(ch!='\n')
        {
          b[z]=ch;
          z++;
          ch=fgetc(fptr);
        }
        b[z]='\0';
        lc=atoi(b);
      }
       if(j==1 || j==3)
      {
       while(cnt<cnt1)
       {
         l[cnt].addr=lc;
         printf("%d)",lc);
         printf("%s\n",l[cnt].lname);
         lc=lc+4;
         cnt++;
       }
     }
     flag1=1;
    }
   }
   for(j=0;j<3;j++)
   {
    x=strcmp(a,r[j].rname);
    if(x==0)
    {
     printf("%d",r[j].rtopc);
     flag1=1;
    }
   }
   for(j=0;j<3;j++)
   {
    x=strcmp(a,m[j].mname);
    if(x==0)
    {
     printf("%d) ",lc);
     printf(" %d ",m[j].nmopc);
     lc=lc+m[j].nmsize;
     flag1=1;
    }
   }
   if(a[0] =='=')
   {       //ch=fgetc(fptr);
    //if(ch=='=')
    //{
    printf("%s",a);
    strcpy(l[cnt1].lname,a);
    l[cnt1].addr=0;
    cnt1++;
    flag1=1;
          // }
   }
   if(flag1!=1)
   {
    k=0;
    if(ch=='\n')
    { printf("%s",a);
     flag2=1;
    }
    if(flag2==0)
    {
      num=0;

     for(f=0;a[f]!='\0';f++)
     {
      num=num+(f*a[f]);
     }
     scnt=num%10;
     strcpy(s[int(scnt)].sname,a);
     ch=fgetc(fptr);
     while(ch!=' ')
     {
      b[k]=ch;
      k++;
      ch=fgetc(fptr);
     }
     b[k]='\0';
     x=strcmp(b,"dc");
     if(x==0)
     {
      y=0;
      ch=fgetc(fptr);
      while(ch!='\n')
      {
       c[y]=ch;
       y++;
       ch=fgetc(fptr);
      }
      c[y]='\0';
      for(f=0;c[f]!='\0';f++)
      {
       if(c[f]=='\'')
        c[f]=' ';
      }
      val1=atoi(c);
      s[int(scnt)].val=val1;
      s[int(scnt)].len=4;
      s[int(scnt)].addr=lc;
      lc=lc+4;
      //cnt2++;
      printf("%d)",lc);
      printf("%s",a);
     }
     else
     {
      q=0;
      ch=fgetc(fptr);
      while(ch!='\n')
      {
       c[q]=ch;
       q++;
       ch=fgetc(fptr);
      }
      c[q]='\0';
      val1=atoi(c);
      val1=val1*4;
      lc=lc+val1;
      s[int(scnt)].val=0;
      s[int(scnt)].addr=lc;
      s[int(scnt)].len=val1;
      //cnt2++;
      printf("%d)",lc);
      printf("%s",a);
     }
    }
   }
   if(ch==',')
    printf("  ");
   if(ch=='\n')
    printf("\n");
   if(ch==' ')
    printf("  ");
   flag=0;
   flag1=0;
   i=0;
   flag2=0;
  }
  ch=fgetc(fptr);
 }
 printf("%d)",lc);
 for(i=0;i<cnt1;i++)
 {
  printf("%s\t%d",l[i].lname,l[i].addr);
  printf("\n");
 }
 for(i=0;i<10;i++)
 {
  printf("%s\t%d\t%d\t%d",s[i].sname,s[i].addr,s[i].len,s[i].val);
  printf("\n");
 }
 fclose(fptr);
 getch();
}
