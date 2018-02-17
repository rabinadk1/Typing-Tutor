#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <conio.h>
#include <stdio_ext.h>
#include <time.h>
#include "tt.h"
char *blank[4];
char *main_menu_options[]={"User Login","User Statistics","About","Exit"};
int main()
{
	char ch;
	blank[0]=ARROW;
	for (int i=1;i<4;i++)
		blank[i]="   ";
	while(1)
	{
		mainmenu();
		ch=getch();
		if(ch=='1')
			type();
		else if (ch=='2')
			stat();
		else if (ch=='3')
			about();
		else if (ch=='4')
			exit(0);
		if(!strcmp(blank[0],ARROW)){
			if (ch==UP){
				blank[0]=" ";
				blank[3]=ARROW;
			}
			else if(ch==DOWN){
				blank[0]=" ";
				blank[1]=ARROW;
			}
			else if (ch==ENTER)
				type();
		}
		else if(!strcmp(blank[1],ARROW)){
			if(ch==UP){
				blank[1]=" ";
				blank[0]=ARROW;
			}
			else if(ch==DOWN){
				blank[1]=" ";
				blank[2]=ARROW;
			}
			else if (ch==ENTER)
				stat();
		}
        else if(!strcmp(blank[2],ARROW)){
			if (ch==UP) {
				blank[2]=" ";
				blank[1]=ARROW;
			}
			else if(ch==DOWN){
				blank[2]=" ";
				blank[3]=ARROW;
			}
			else if (ch==ENTER)
				about();
		}
        else if(!strcmp(blank[3],ARROW)){
			if (ch==UP) {
				blank[3]=" ";
				blank[2]=ARROW;
			}
			else if(ch==DOWN){
				blank[3]=" ";
				blank[0]=ARROW;
			}
			else if(ch==ENTER)
				exit(0);
		}
	}
}

void mainmenu()
{
	int i;
    system("clear");
    LOGO();
    printf("\n\n\t    PLEASE SELECT AN OPTION USING 'W' OR 'S' KEYS AND PRESSING ENTER ELSE PRESS THE NUMBER BEFORE THE OPTION\n\n");
    printf("\n\n\t\t\t\t\t\t    ====>MENU<=====\n\n");
    for(i=0;i<4;i++)
        printf("\t\t\t\t\t\t    %s %d.%s\n\n",blank[i],i+1,main_menu_options[i]);
}

/*void selectuser()
{
	cls();
	FILE * fuser;
	fuser=fopen("stat.txt","r");
	fnull(fuser);
	int n;
	char name[20],*nam;
	fscanf(fuser,"%d ",&n);
	char *user[n];
	printf("The available users are:\n\n");
	for (int i=0;i<n;i++)
	{
		fscanf(fuser,"%*d %s %*f %*f\n",name);
		printf("%d %s\n",i+1,name);
		nam=calloc(strlen(name)+1,sizeof(char));
		strcpy(nam,name);
		user[i]=nam;
	}
	printf("If user is already pre");
	fclose(fuser);
	continue_();
}*/

void type()
{
	cls();
	char *lesson[]={"l1.txt","l2.txt","l3.txt","l4.txt","l5.txt","l6.txt","l7.txt","l8.txt","l9.txt"};
	srand(time(NULL));
	char name[20],*para,*usr,ch;
	printf("Enter your name: ");
	scanf("%s",name);
	getchar();
	time_t s1,s2;
	int wcount=1,i=0,error=0,x,usr_no;
	FILE * fr,* fa; //fr to read and fa to write without erasing
	fr=fopen(lesson[rand()%9],"r");
	fnull(fr);
	while((ch=getc(fr))!=EOF){
		i++;
	}
	para=calloc(i,sizeof(char));
	rewind(fr);
	fgets(para,i+1,fr);
	printf("\n\n%s",para);
	do {
	printf("\n Do you want to take this exrcise?\n");
	ch=getchar();
	__fpurge(stdin);//used instead of fflush(stdin)
	if(tolower(ch)=='n'){
		cls();
		main();
	}
	if (tolower(ch)=='y')
		break;
	else if (tolower(ch)!='y')
		printf("I'm sorry. I didn't get that.\n");
	} while (1);
	usr=calloc(i,sizeof(char));
	printf("\n\nEnter the paragraph given above:\n\n");
	s1=time(NULL);
	scanf("%[^\n]",usr);
	getchar();
	s2=time(NULL);
	for (x=0;x<i;x++)
	{
		if(usr[x]==' ')
			wcount++;
		if (usr[x]!=para[x])
			error++;
	}
	float wpm, accuracy;
	wpm=wcount*60.0/(s2-s1);
	accuracy=(1-(float)error/i)*100;
	printf("\n\nAccuracy: %.2f%%\nWPM: %.2f\n",accuracy,wpm);
	fa=fopen("stat.txt","r+");
	fnull(fr);
	fscanf(fa,"%d",&usr_no);
	fseek(fa,0,2);
	fprintf(fa,"%d %s %f %f\n",++usr_no,name,accuracy,wpm);
	rewind(fa);
	fprintf(fa,"%d",usr_no);
	fclose(fa);
	fclose(fr);
	printf("Your records have successfully saved.\n");
	continue_();
}

void stat()
{
	cls();
	FILE * fstat;
	fstat=fopen("stat.txt","r");
	fnull(fstat);
	int no,user_no;
	float accuracy,wpm;
	char name[20];
	fscanf(fstat,"%d",&no);
	printf("%-6s %-20s %-15s %-6s\n\n","SN","Name","Accuracy","WPM");
	for (int i=0;i<no;i++)
	{
		fscanf(fstat,"%d %s %f %f\n",&user_no,name,&accuracy,&wpm);
		printf("%-6d %-20s %-15.2f %-6.2f\n",user_no,name,accuracy,wpm);
	}
	fclose(fstat);
	continue_();
}

void about()
{
	cls();
	printf("A b o u t  T y p i n g  T u t o r\n\n");
	printf("\tTyping Tutor 1.0\n\n");
	printf("\tDevelopers: Rabin Adhikari\n");
	printf("\t%11c Pujan Dahal\n",' ');
	printf("\t%11c Saurab Bhusal\n",' ');
	continue_();
}

void continue_()
{
	sleep(1);
	printf("\n\nPress Esc to go to Main Menu\n");
	char ch=getche();
	__fpurge(stdin);//used instead of fflush(stdin)
	if(ch==27){
		cls();
		main();
	}

	else
	{
		printf("I'm sorry. I didn't get that.\n");
		continue_();
	}
}
