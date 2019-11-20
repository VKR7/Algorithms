#include<stdio.h>
#include<conio.h>
#define LT 218
#define RT 191
#define CROSS 197
#define HL 196
#define VL 179
#define TT 194
#define BT 193
#define LST 195
#define RST 180
#define LB 192
#define RB 217
#define BS 8
#define SPACE 32
#define WIDTH 5
#define HEIGHT 1
#define DIM 7
int main()//home
{
  int bcol , brow,ctr1,ctr2,ctr3;
  clrscr();
  bcol = (80 - ((DIM *WIDTH)+DIM+1))/2;
  brow = (25 - ((DIM *HEIGHT)+DIM+1))/2;
//  printf("Am here");
  gotoxy(bcol,brow);
   printf("%c",LT);
  for(ctr2=1 ; ctr2<= DIM ; ctr2++)
  {
   for(ctr1 =1  ; ctr1<=WIDTH; ctr1++)
    printf("%c",HL);
   printf("%c",TT);
  }
  printf("%c%c",BS,RT);
  //end of first line
  for(ctr3=1 ; ctr3<= DIM; ctr3++)
 {
  gotoxy(bcol,++brow);
  for(ctr2=1 ; ctr2<= DIM+1; ctr2++)
  {
   printf("%c",VL);
   for(ctr1 =1  ; ctr1<=WIDTH; ctr1++)
    printf("%c",SPACE);
  }
  gotoxy(bcol,++brow);
  printf("%c",LST);
  for(ctr2 =1  ; ctr2<= DIM; ctr2++)
  {
   for(ctr1 =1  ; ctr1<=WIDTH; ctr1++)
    printf("%c",HL);
  printf("%c",CROSS);
  }
  printf("%c%c",BS,RST);
 }
 //body of the box
  gotoxy(bcol,brow);
   printf("%c",LB);
  for(ctr2=1 ; ctr2<= DIM ; ctr2++)
  {
   for(ctr1 =1  ; ctr1<=WIDTH; ctr1++)
    printf("%c",HL);
   printf("%c",BT);
  }
  printf("%c%c",BS,RB);
  //end of last line
  getch();
  return 0;
}

