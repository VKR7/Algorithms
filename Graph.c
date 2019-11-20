#include<stdio.h>
#include<conio.h>
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

 int mat[NOV][NOV];
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
int bfsVisitor[NOV];
char queue[100];
int front=-1,rear=-1;
char deQ()
{
 char toReturn;
 if(front==-1 || front > rear) return 0;
 toReturn =queue[front];
 front++;
 return toReturn;
}
void enQ( char toAdd)
{
 if(front==-1||rear==-1)
   front++;
 rear++;
 queue[rear]=toAdd;
}
BFS(char st)
{
 char deQval;
 int col;
 enQ(st);
 while(1)
 {
  deQval = deQ();
  if(deQval==0)  break;
  if(bfsVisitor[deQval-65]==0)
  {
   printf("%c ->",deQval);
   bfsVisitor[deQval-65]=1;//visited
   for(col = 0 ; col< NOV; col++)
       if(mat[deQval-65][col]!=0&&bfsVisitor[col]==0)
		enQ(col+65);
  }

  }
}

int main()
{
 int row,col,ind;
 clrscr();
 for(ind= 0 ;ind<NOE ; ind++)
 {
  mat[data[ind].ch1-65][ data[ind].ch2-65]= data[ind].wt;
  mat[data[ind].ch2-65][ data[ind].ch1-65]= data[ind].wt;
 }
 for(ind= 0 ,printf("\t\t");ind<NOV ; ind++)
   printf("%2c  ",ind+65);
 for(printf("\n\t"),row= 0 ;row< NOV;printf("\n\t"),row++)
 {
  printf("%c\t",row+65);
  for(col = 0 ;col<NOV ; col++)
    printf("%2d  ",mat[row][col]);
 }


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
 printf("\n\tBFS : ");
 BFS('G');


 getch();
 return 0 ;
}
