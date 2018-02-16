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
#define LOGO printf("\
            ************         #### #    # #### #### #   # ####    #### #  # #### #### ####        **************\n\
            ************          ##   #  #  #  #  ##  ##  # #        ##  #  #  ##  #  # #  #        **************\n\
            ************          ##    ##   ####  ##  # # # # ##     ##  #  #  ##  #  # ####        **************\n\
            ************          ##    ##   #     ##  #  ## #  #     ##  #  #  ##  #  # ##          **************\n\
            ************          ##    ##   #    #### #   # ####     ##  ####  ##  #### # #         **************\n\n");\
    printf("\n\n\t\t\t\t\t+++++++++++>>>>  WELCOME  <<<<++++++++++++\n\n")




///these are the parts of main program
char arrow='>';
char blank[]={' ',' ',' ',' ',' '};
char ch;



///this is for opening sorted menu(first page)==SORTED MENU
char arr_opening_sorted_menu[][20]={"1.User Login","2.User Statistics","3.About","4.Exit","5.Fifth Option"};
void opening_sorted_menu();
void display_opening_sorted_menu();
//void opening_sorted_menu_option_select();



///this is for user login menu(second page)==USER LOGIN MENU
char arr_user_login_menu[][20]={"1.Existing User","2.New User","3.Back"};
void user_login_menu();
void display_user_login_menu();
//void user_login_menu_option_select();





///this is for lesson select menu(fourth page)==LESSON SELECT MENU
char arr_lesson_select_menu[][20]={"1.Easy","2.Medium","3.Hard","4.Back"};
void lesson_select_menu();
void display_lesson_select_menu();
//void lesson_select_menu_option_select();





int main()
{
    opening_sorted_menu();
}




///this is the menu part of the program(first page)==SORTED MENU
void opening_sorted_menu()
{

    system("cls");
    blank[0]='>';
    blank[1]=' ';
    blank[2]=' ';
    blank[3]=' ';
    blank[4]=' ';
    while(1)
    {
        display_opening_sorted_menu();
        ch=getch();
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
        if(FIRST AND ENTER)
        user_login_menu();
    /*else if(SECOND AND ENTER)
        user_statistics_page();
    else if(THIRD AND ENTER)
        about_developers_page();
    else if(FOURTH AND ENTER)
        exit_page();*/

        //opening_sorted_menu_option_select();
    }
}

void display_opening_sorted_menu()
{
    int i;
    system("cls");
    LOGO;
    printf("\n\n\t\t\t\t\tPLEASE SELECT AN OPTION USING 'W' OR 'S' KEYS\n\n");
    printf("\n\n\t\t\t\t\t\t ====>MENU<=====\n\n");
    for(i=0;i<=4;i++)
    {
        printf("\t\t\t\t\t\t");
        printf("%c %s\n",blank[i],arr_opening_sorted_menu[i]);
        printf("\n");
    }
}






///this part is for the user login menu(second page)==USER LOGIN MENU
void user_login_menu()
{
    char ch;

    system("cls");
    blank[0]='>';
    blank[1]=' ';
    blank[2]=' ';
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
        /*if(FIRST AND ENTER)
            user_login_existing_user_page();
    /*else if(SECOND AND ENTER)
        user_login_new_user_page();*/
        if(THIRD AND ENTER){
            opening_sorted_menu();
        }
        //user_login_menu_option_select();
        }
    }
void display_user_login_menu()
{
    int i;
    system("cls");
    LOGO;
    printf("\n\t\t\t\t\tPLEASE SELECT AN OPTION USING 'W' OR 'S' KEYS\n");
    printf("\n\n\t\t\t\t\t   ====>USER LOGIN MENU<=====\n\n");
    for(i=0;i<=2;i++)
    {
        printf("\t\t\t\t\t\t");
        printf("%c %s\n",blank[i],arr_user_login_menu[i]);
        printf("\n");
    }
}






///this part is of lesson select menu(fourth page)==LESSON SELECT MENU
void lesson_select_menu()
{
    char ch;
    system("cls");
    blank[0]='>';
    blank[1]=' ';
    blank[2]=' ';
    blank[3]=' ';
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
        /*if(FIRST AND ENTER)
        easy_lessons;
    else if(SECOND AND ENTER)
        medium_lessons;
    else if(THIRD AND ENTER)
        hard_lessons;
    else if(FOURTH AND ENTER)
        go back;*/
        //lesson_select_menu_option_select();
    }
}
void display_lesson_select_menu()
{
    int i;
    system("cls");
    LOGO;
    printf("\n\n\t\t\t\t\tPLEASE SELECT A LESSON USING 'W' OR 'S' KEYS\n\n");
    printf("\n\n\t\t\t\t\t\t ====>LESSON SELECT MENU<=====\n\n");
    for(i=0;i<=3;i++)
    {
        printf("\t\t\t\t\t\t");
        printf("%c %s\n",blank[i],arr_lesson_select_menu[i]);
        printf("\n");
    }
}





