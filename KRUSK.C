#include<stdio.h>
#include<conio.h>
#define NOE 14
#define NOV 9
#define LOOP 0
#define NOLOOP 1
typedef struct input
{
char v1;
char v2;
int wt;
}EDGE;
EDGE data[NOE]={{'B','G',1},{'C','D',2},{'A','C',3},{'B','E',3},{'F','G',4},
{'A','D',5},{'E','I',5}, {'H','I',6},{'D','G',6}, {'C','F',9},
{'A','B',9},{'G','I',10},{'F','H',12},{'G','E',15}
};
typedef struct node
{
 char ch;
 struct node * next;
}NODE;
NODE * tptr, *newnode;
typedef struct head
{
 struct head * hnext;
 struct node * sllstart;
}HEAD;
HEAD * hstart,*hptr,*hprev,*hnewnode;
void initHeader()
{
 int val;
 for(val =0 ;val< NOV ; val++)
 {
 newnode = (NODE*)malloc(sizeof(NODE));
 newnode->ch = val+65;
 newnode->next=NULL;
 hnewnode= (HEAD*)malloc(sizeof(HEAD));
 hnewnode->sllstart= newnode;
 hnewnode->hnext = NULL;
 if(hstart==NULL)
   hstart= hnewnode;
 else
 {
   for(hptr = hstart ; hptr->hnext!=NULL; hptr=hptr->hnext);
   hptr->hnext = hnewnode;
 }
 }
}
kruskDisplay(int cost)
{
  clrscr();
  for(printf("\n\t"),hptr = hstart ; hptr;printf("\n\t"),hptr=hptr->hnext)
  {
    for(tptr=hptr->sllstart;tptr;tptr=tptr->next)
      printf("%c-> ",tptr->ch);
  }
  printf("\n\tMinimum cost for the path : %d ",cost);
  getch();
}
HEAD * getHeader(char search)
{
  for(hptr = hstart ; hptr;hptr=hptr->hnext)
  {
    for(tptr=hptr->sllstart;tptr;tptr=tptr->next)
      if(tptr->ch ==search)
	return hptr;
  }
  return NULL;
}
void deleteHeader(HEAD * dhptr)
{
    for(hptr = hstart,hprev=NULL ;hptr&& hptr!=dhptr;hprev= hptr , hptr=hptr->hnext);
     hprev->hnext  = hptr->hnext;
     free(hptr);
}
int main()
{
 int cost=0,ind;
 HEAD * header1,*header2;
 clrscr();
 initHeader();
 for(ind= 0 ;ind<NOE ; ind++)
 {
   header1 =getHeader(data[ind].v1);
   header2 = getHeader(data[ind].v2);
  if(header1!=header2)
  {
   cost = cost+data[ind].wt;
   for(tptr=header1->sllstart; tptr->next!=NULL; tptr=tptr->next);
   tptr->next = header2->sllstart;
   header2->sllstart=NULL;
   deleteHeader(header2);
  }
  else
    {
     printf("\n\t Cyclic path found and skipped");
     getch();
    }
  kruskDisplay(cost);
 }

 getch();
 return 0;
}