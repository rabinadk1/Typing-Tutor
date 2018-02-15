///this is a program to create a menu
#include<stdio.h>
#include<windows.h>
#define UP (ch==119)
#define DOWN (ch==115)
#define ENTER (ch==13)
#define AND &&
#define OR ||
#define FIRST (blank[0]=='>')

#define SECOND (blank[1]=='>')

#define THIRD (blank[2]=='>')

#define FOURTH (blank[3]=='>')

#define FIFTH (blank[4]=='>')


char arr[5][20]={"1.First Option","2.Second Option","3.Third Option","4.Fourth Option","5.Fifth Option"};
char arrow='>';
char blank[]={' ',' ',' ',' ',' '};
void display();
int main()
{
    char ch;

    system("cls");
    blank[0]='>';
    while(1)
    {
        display();
        ch=getch();
        if(ENTER)
            break;
        if(FIRST AND UP){
            blank[0]=' ';
            blank[4]='>';
            }
        else if(FIRST AND DOWN){
            blank[0]=' ';
            blank[1]='>';
        }
        else if(SECOND AND UP){
            blank[1]=' ';
            blank[0]='>';
        }
        else if(SECOND AND DOWN){
            blank[1]=' ';
            blank[2]='>';
        }
        else if(THIRD AND UP){
            blank[2]=' ';
            blank[1]='>';
        }
        else if(THIRD AND DOWN){
            blank[2]=' ';
            blank[3]='>';
        }
        else if(FOURTH AND UP){
            blank[3]=' ';
            blank[2]='>';
        }
        else if(FOURTH AND DOWN){
            blank[3]=' ';
            blank[4]='>';
        }
        else if(FIFTH AND UP){
            blank[4]=' ';
            blank[3]='>';
        }
        else if(FIFTH AND DOWN){
            blank[4]=' ';
            blank[0]='>';
        }
    }
    return 0;
}
void display()
{
    int i;
    system("cls");
    printf("\
            ************         #### #    # #### #### #   # ####    #### #  # #### #### ####        **************\n\
            ************          ##   #  #  #  #  ##  ##  # #        ##  #  #  ##  #  # #  #        **************\n\
            ************          ##    ##   ####  ##  # # # # ##     ##  #  #  ##  #  # ####        **************\n\
            ************          ##    ##   #     ##  #  ## #  #     ##  #  #  ##  #  # ##          **************\n\
            ************          ##    ##   #    #### #   # ####     ##  ####  ##  #### # #         **************\n\n");
    printf("\n\n\t\t\t\t\t+++++++++++>>>>  WELCOME  <<<<++++++++++++\n\n");
    printf("\n\n\t\t\t\t\t\t ====>MENU<=====\n\n");
    for(i=0;i<=4;i++)
    {
        printf("\t\t\t\t\t\t");
        printf("%c %s\n",blank[i],arr[i]);
        printf("\n");
    }
}
