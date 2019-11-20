#include<stdio.h>
#include<conio.h>
#include<limits.h>
#define NOV 9
#define NOE 14
struct edge
{
 char ch1;
 char ch2;
 int wt;
};
typedef struct edge EDGE;

 EDGE data[NOE]={{'A','C',3},{'A','D',5},{'A','B',9},{'B','G',1},{'B','E',3},
 {'C','D',2},{'H','I',6},{'F','H',12},{'F','G',4},{'G','I',10},{'G','E',15},
 {'E','I',5},{'C','F',9},{'D','G',6} };

typedef struct node
 {
   char ch;
   int wght;
   struct node *next;
 }NODE;

NODE *header[NOV];
NODE* tptr,*newnode;

void connector(char ind_ch,char con_ch,int weit)
{
 newnode = (NODE*)malloc(sizeof(NODE));
 newnode->ch = con_ch;
 newnode->wght = weit;
 newnode->next=NULL;
 if(header[ind_ch-65] ==NULL)
   header[ind_ch-65] = newnode;
 else
 {
  for(tptr = header[ind_ch-65]  ; tptr->next!=NULL;  tptr= tptr->next);
  tptr->next= newnode;
 }
}
#define VISITED 1
#define NOTVISITED 0
typedef struct dj
{
 char vertex;
 int visit;
 int cost;
 char parent;
}DJNODE;
DJNODE dj[NOV];
void initDJ()
{
 int ind;
 for(ind=0 ; ind < NOV ;ind++)
 {
  dj[ind].vertex= ind+65;
  dj[ind].visit=NOTVISITED;
  dj[ind].cost=INT_MAX;
  dj[ind].parent=NULL;
 }
}
char findMin()
{
 int ind,min=INT_MAX;
 char min_ch;
 for(ind=0 ; ind<NOV ; ind++ )
  { if(dj[ind].cost < min && dj[ind].visit == NOTVISITED)
    {
      min = dj[ind].cost;
      min_ch =dj[ind].vertex;
    }
    }
  return min_ch;
}

void DJalgo(char start)
{
  int count =0;
  char min_ch;
  dj[start-65].cost=0;
  while(count<NOV)
 {
  min_ch=findMin();
  dj[min_ch-65].visit=VISITED;
   count++;
  for(tptr = header[min_ch-65] ; tptr; tptr=tptr->next)
  {
    if(dj[min_ch-65].cost + tptr->wght  < dj[(tptr->ch)-65].cost
       && dj[(tptr->ch)-65].visit==NOTVISITED)
     {
	dj[(tptr->ch)-65].cost = dj[min_ch-65].cost + tptr->wght;
	dj[(tptr->ch)-65].parent = min_ch;
     }
  }
  }
}

void display()
{
 int ind;
 for(ind=0 ; ind < NOV ;ind++)
 {
 printf("\n\t %c %d %d %c ", dj[ind].vertex,dj[ind].visit,dj[ind].cost,  dj[ind].parent);
 }

}
int main()
{
 int row,col,ind;
 clrscr();
  //array of list
  for(ind= 0 ;ind<NOE ; ind++)
 {
  connector(data[ind].ch1,data[ind].ch2,data[ind].wt);
  connector(data[ind].ch2,data[ind].ch1,data[ind].wt);
 }
  for(printf("\n\t"),row= 0 ;row< NOV;printf("\n\t"),row++)
 {
  printf("%c\t",row+65);
//  for(col = 0 ;col<NOV ; col++)
  for(tptr=header[row];tptr;tptr=tptr->next)
    printf("%c(%2d)-> ",tptr->ch,tptr->wght);
 }

  initDJ();
  DJalgo('A');
  display();
 getch();
 return 0 ;
}
