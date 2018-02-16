///this is rough part to let the user enter the key
#include<stdio.h>
#include<string.h>
#include<windows.h>
#define HLINE for(i=0;i<50;i++)\
                printf("%c",196);
#define VLINE(X,Y) {\
                    gotoxy(X,Y);\
                    printf("%c",179);\
                   }
#define HASH '#'
void PARA();
void POINTER();
void POINTER_POS();
void POINTER_MOVER();
void LINE_CHANGER();
void BOX();
void DISPLAY();
void gotoxy(short int col, short int row);
int i,len,y;
char paragraph_for_display[]="\n       The 1910 Cuba hurricane was said to be one of\n\n\
       the worst tropical cyclones that has ever hit\n\n\
       Cuba. The storm formed in the southern caribbean\n\n\
       sea on October 9, 1910.\n\n";
char paragraph_for_pointer[]="The 1910 Cuba hurricane was said to be one of the worst tropical cyclones that has ever hit Cuba. The storm formed in the southern caribbean sea on October 9, 1910.";
char blank=' ';
char ch;
int main()
{
    DISPLAY();
    //point();
    printf("\n\n\n\nThe length of paragraph is: %d",len);
    return 0;
}
void PARA()
{
    gotoxy(6,5);
    printf("%s",paragraph_for_display);
    len=strlen(paragraph_for_pointer);

}
void gotoxy(short int col,short int row)
{
    HANDLE hStdout=GetStdHandle(STD_OUTPUT_HANDLE);
    COORD position={col,row};
    SetConsoleCursorPosition(hStdout,position);
}
void BOX()
{
    gotoxy(5,4);
    printf("%c",HASH);

    HLINE

    for(y=5;y<14;y++)
        VLINE(5,y);
    gotoxy(55,4);
    printf("%c",HASH);
    for(y=5;y<14;y++)
        VLINE(55,y);
    gotoxy(5,13);
    printf("%c",HASH);
    HLINE
    gotoxy(55,13);
    printf("%c",HASH);

}
void DISPLAY()
{
    PARA();
    BOX();
}






