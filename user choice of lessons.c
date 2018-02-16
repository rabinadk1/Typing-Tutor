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
char arr_lesson_select_menu[][20]={"1.Easy","2.Medium","3.Hard","4.Back"};
char arrow='>';
char blank[]={' ',' ',' ',' '};
void display_lesson_select_menu();
void lesson_select_menu();
void lesson_select_menu_option_select();
char ch;
int main()
{
    void lesson_select_menu();
    return 0;
}
void lesson_select_menu()
{
    char ch;
    system("cls");
    blank[0]='>';
    while(1)
    {
        display_lesson_select_menu();
        ch=getch();
        if(FIRST AND UP){
            blank[0]=' ';
            blank[3]='>';
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
            blank[0]='>';
        }
        lesson_select_menu_option_select();
    }
}
void display_lesson_select_menu()
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
    printf("\n\n\t\t\t\t\tPLEASE SELECT A LESSON USING 'W' OR 'S' KEYS\n\n");
    printf("\n\n\t\t\t\t\t\t ====>LESSON SELECT MENU<=====\n\n");
    for(i=0;i<=3;i++)
    {
        printf("\t\t\t\t\t\t");
        printf("%c %s\n",blank[i],arr_lesson_select_menu[i]);
        printf("\n");
    }
}
void lesson_select_menu_option_select()
{
    /*if(FIRST AND ENTER)
        easy_lessons;
    else if(SECOND AND ENTER)
        medium_lessons;
    else if(THIRD AND ENTER)
        hard_lessons;
    else if(FOURTH AND ENTER)
        go_back;*/
}
