#include<stdio.h>///this is a program to create a menu
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
char arr_user_login_menu[][20]={"1.Existing User","2.New User","3.Back"};
char arrow='>';
char blank[]={' ',' ',' ',' ',' '};
void display();
void user_login_menu_option_select();
void user_login_menu();
void display_user_login_menu();
char ch;
int main()
{
    user_login_menu();
}
void user_login_menu()
{
    char ch;

    system("cls");
    blank[0]='>';
    while(1)
    {
        display_user_login_menu();
        ch=getch();
        if(FIRST AND UP){
            blank[0]=' ';
            blank[2]='>';
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
            blank[0]='>';
        }
        }
    }
void display_user_login_menu()
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
    printf("\n\t\t\t\t\tPLEASE SELECT AN OPTION USING 'W' OR 'S' KEYS\n");
    printf("\n\n\t\t\t\t\t   ====>USER LOGIN MENU<=====\n\n");
    for(i=0;i<=2;i++)
    {
        printf("\t\t\t\t\t\t");
        printf("%c %s\n",blank[i],arr_user_login_menu[i]);
        printf("\n");
    }
}
void check_user_login_menu_option_select()
{
   /* if(FIRST AND ENTER)
        user_login_existing_user_page();
    else if(SECOND AND ENTER)
        user_login_new_user_page();*/
   // else if(THIRD AND ENTER)
       // opening_sorted_menu();
}

