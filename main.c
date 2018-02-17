#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <conio.h>
#include <stdio_ext.h>
#include <time.h>
#include "tt.h"

char *blank[4],usr_name[20];
char *main_menu_options[]={"User Login","User Statistics","About","Exit"};
char *select_user_options[]={"Existing User","New User", "Back"};
char *lessons[]={"l0.txt","l1.txt","l2.txt","l3.txt","l4.txt","l5.txt","l6.txt","l7.txt","l8.txt","l9.txt"};
int total_lessons=10;

int main()
{
	char ch;
	init_blank();
	blank[0]=ARROW;
	while(1)
	{
		menu();
		for(int i=0;i<4;i++)
			printf("\t\t\t\t\t\t    %s %d.%s\n\n",blank[i],i+1,main_menu_options[i]);
		ch=getch();
		switch (ch)
		{
			case '1':
				selectuser();
			case '2':
				stat();
			case '3':
				about();
			case '4':
				exit(0);
		}
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
				selectuser();
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

void menu()
{
	cls();
    LOGO();
    printf("\n\n\t    PLEASE SELECT AN OPTION USING 'W' OR 'S' KEYS AND PRESSING ENTER ELSE PRESS THE NUMBER BEFORE THE OPTION\n\n");
    printf("\n\n\t\t\t\t\t\t    ====>MENU<=====\n\n");
}

void existing()
{
	cls();
	FILE * fuser;
	//to read from stat.txt
	fuser=fopen("stat.txt","r");
	fnull(fuser);
	int n,num,i;
	char name[25],*nam;
	fscanf(fuser,"%d ",&n);
	char **user=calloc(n,sizeof(char*)); //bug in user doesn't sore data
	printf("The available users are:\n\n");
	for (i=0;i<n;i++)
	{
		fscanf(fuser,"%*d %s %*f %*f\n",name);
		printf("\t%d.%s\n\n",i+1,name);
		nam=calloc(strlen(name)+1,sizeof(char));
		strcpy(nam,name);
		user[i]=nam;
	}
	fclose(fuser);
	printf("\n\nEnter the number to select the user.");
	scanf("%d",&num);
	getchar();
	for (i=1;i<=n;i++){
		if (num==i)
		{
			FILE *fptr;
			//To read from previously created user file
			float wpm, accuracy;
			int lesson_num;
			strcpy(name,user[num-1]);
			strcat(name,".txt");
			fptr=fopen(name,"r");
			fnull(fptr);
			fscanf(fptr,"%*d %*s %f %f %d",&accuracy,&wpm,&lesson_num);
			fclose(fptr);
			if (lesson_num==total_lessons)
			{
				printf("\n\nCongratulations you have completed all the lessons.\n\n");
				break;
			}
			//to continue lesson
			fptr=fopen(lessons[lesson_num],"r");
			fnull(fptr);
			float *data=type(fptr);
			accuracy=(accuracy+data[0])/2;
			wpm=(wpm+data[1])/2;
			//to write on previously created user file
			fptr=fopen(name,"w");
			fnull(fptr);
			fprintf(fptr,"%d %s %f %f %d",num,user[num-1],accuracy,wpm,lesson_num+1);
			fclose(fptr);
			//to write on stat.txt
			fptr=fopen("stat.txt","r+");
			fnull(fptr);
			fscanf(fptr,"%*d ");
			for (i=0;i<n;i++)
			{
				fscanf(fptr,"%*d %s %*f %*f\n",name);
				if (!strcmp(name,user[num-2]) || num==1 )
				{
					fscanf(fptr,"%*d %*s ");
					fprintf(fptr,"%f %f",accuracy,wpm);
					break;
				}
			}
			fclose(fptr);
			break;
		}
	}
	printf("Your records have successfully saved.\n");
	continue_();
}

float *type(FILE *fr)
{
	cls();
	static float data[2];
	srand(time(NULL));
	char *para,*usr,ch;
	time_t s1,s2;
	int wcount=1,i=0,error=0,x;
	while((ch=getc(fr))!=EOF){
		i++;
	}
	para=calloc(i,sizeof(char));
	rewind(fr);
	fgets(para,i+1,fr);
	fclose(fr); //file closed
	printf("\n%s",para);
	do {
		printf("\n\nDo you want to take this exercise?\n");
		ch=getchar();
		__fpurge(stdin);//used instead of fflush(stdin)
		if(tolower(ch)=='n'){
			cls();
			main();
		}
		if (tolower(ch)=='y')
			break;
		else
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
	float accuracy,wpm;
	accuracy=(1-(float)error/i)*100;
	data[0]=accuracy;
	wpm=wcount*60.0/(s2-s1);
	data[1]=wpm;
	printf("\n\nAccuracy: %.2f%%\nWPM: %.2f\n",accuracy,wpm);
	return data;
}
int write_stat(float accuracy,float wpm)
{
	FILE *fa;
	fa=fopen("stat.txt","r+");
	fnull(fa);
	int usr_no;
	fscanf(fa,"%d",&usr_no);
	fseek(fa,0,2);
	fprintf(fa,"%d %s %f %f\n",++usr_no,usr_name,accuracy,wpm);
	rewind(fa);
	fprintf(fa,"%d",usr_no);
	fclose(fa); //file closed
	printf("Your records have successfully saved.\n");
	return usr_no;
}
void selectuser()
{
	char ch;
	init_blank();
	blank[0]=ARROW;
	while(1)
	{
		menu();
		for(int i=0;i<3;i++)
			printf("\t\t\t\t\t\t    %s %d.%s\n\n",blank[i],i+1,select_user_options[i]);
		ch=getch();
		if(ch=='1')
			existing();
		else if (ch=='2')
			new_();
		else if (ch=='3')
			main();
		if(!strcmp(blank[0],ARROW)){
			if (ch==UP){
				blank[0]=" ";
				blank[2]=ARROW;
			}
			else if(ch==DOWN){
				blank[0]=" ";
				blank[1]=ARROW;
			}
			else if (ch==ENTER)
				existing();
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
				new_();
		}
        else if(!strcmp(blank[2],ARROW)){
			if (ch==UP) {
				blank[2]=" ";
				blank[1]=ARROW;
			}
			else if(ch==DOWN){
				blank[2]=" ";
				blank[0]=ARROW;
			}
			else if (ch==ENTER)
				main();
		}
	}
}

void new_()
{
	cls();
	char name[25];
	printf("Enter your name: ");
	scanf("%s",usr_name);
	getchar();
	FILE *fptr;

	//open lesson and provide pointer to lesson to type() functon
	fptr=fopen(lessons[0],"r");
	fnull(fptr);
	float * data=type(fptr);
	//write user stats to stat.txt and extract user number
	int usr_no=write_stat(data[0],data[1]);
	//open user file and write stat of user
	strcpy(name,usr_name);
	strcat(name,".txt");
	fptr=fopen(name,"w");
	fnull(fptr);
	fprintf(fptr,"%d %s %f %f %d",usr_no,usr_name,data[0],data[1],1);//data[0]==accuracy, data[1]==wpm, 1=lesson_num
	fclose(fptr);
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
void init_blank()
{
	for (int i=0;i<4;i++)
		blank[i]=" ";
}