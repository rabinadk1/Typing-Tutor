#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <conio.h>
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
	char **user=calloc(n,sizeof(char*));
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
	while(1){
		printf("\n\nEnter the number to select the user: ");
		scanf("%d",&num);
		getchar();
		if (num>n) {
			printf("Please enter the number inside the range.");
			continue;
		}
		break;
	}
	FILE *fptr;
	//To read from previously created user file
	float *wpm, *accuracy,wpmavg=0,accuracyavg=0;
	int lesson_num;
	strcpy(name,user[num-1]);
	strcat(name,".txt");
	fptr=fopen(name,"r");
	fnull(fptr);
	fscanf(fptr,"%d %*d %*s",&lesson_num);
	wpm=calloc(lesson_num,sizeof(float));
	accuracy=calloc(lesson_num,sizeof(float));
	for (i=0;i<lesson_num;i++)
		fscanf(fptr," %f %f",accuracy+i,wpm+i);
	fclose(fptr);
	if (lesson_num==total_lessons){
		printf("\n\nCongratulations you have completed all the lessons.\n\n");
		continue_();
	}
	//to continue lesson
	float *data=type(lesson_num+1);
	for (i=0;i<lesson_num;i++)
	{
		wpmavg+=wpm[i];
		accuracyavg+=accuracy[i];
	}
	lesson_num++;
	wpmavg+=data[1];
	accuracyavg+=data[0];
	wpmavg/=lesson_num;
	accuracyavg/=lesson_num;
	//to write on previously created user file
	fptr=fopen(name,"r+");
	fnull(fptr);
	fprintf(fptr,"%d",lesson_num);
	fseek(fptr,0,2);
	fprintf(fptr," %f %f",data[0],data[1]);
	fclose(fptr);
	//to write on stat.txt
	fptr=fopen("stat.txt","r+");
	fnull(fptr);
	fscanf(fptr,"%*d ");
	for (i=0;i<num-1;i++)
		fscanf(fptr,"%*d %s %*f %*f\n",name);
	fscanf(fptr,"%*d %*s ");
	fprintf(fptr,"%f %f",accuracyavg,wpmavg);
	fclose(fptr);
	printf("Your records have successfully saved.\n");
	continue_();
}

float *type(int less)
{
	cls();
	FILE* fr;
	fr=fopen(lessons[less],"r");
	fnull(fr);
	static float data[2];
	char *para,*usr,ch;
	time_t s1,s2;
	int wcount=1,i=0,ok=0,x;
	while((ch=getc(fr))!=EOF)
		i++;
	para=calloc(i+1,sizeof(char));
	rewind(fr);
	fgets(para,i+1,fr);
	fclose(fr); //file closed
	printf("\n%s",para);
	do {
		printf("\n\nDo you want to take this exercise?\n");
		ch=getchar();
		fflush(stdin);
		if(tolower(ch)=='n'){
			cls();
			main();
		}
		if (tolower(ch)=='y')
			break;
		else
			printf("I'm sorry. I didn't get that.\n");
	} while (1);
	usr=calloc(i+1,sizeof(char));
	printf("\n\nEnter the paragraph given above:\n\n");
	s1=time(NULL);
	scanf("%[^\n]",usr);
	getchar();
	s2=time(NULL);
	for (x=0;x<i;x++)
	{
		if (usr[x]=='\0')
			break;
		if(usr[x]==' ')
			wcount++;
		if (usr[x]==para[x])
			ok++;
	}
	free(usr);
	free(para);
	data[0]=ok*100.0/i;
	data[1]=wcount*60.0/(s2-s1);
	printf("\n\nAccuracy: %.2f%%\nWPM: %.2f\n",data[0],data[1]);
	return data;
}
int write_stat(float accuracy,float wpm)
{
	FILE *fa;
	fa=fopen("stat.txt","r+");
	//ok
	if (fa==NULL) {
		fa=fopen("stat.txt","w");
		fnull(fa);
		fprintf(fa,"%d %d %s %f %f\n",1,1,usr_name,accuracy,wpm);
		fclose(fa);
		return 1;
	}
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
	char *name;
	printf("Enter your name: ");
	scanf("%s",usr_name);
	getchar();
	//open lesson
	float *datum=type(0); //error when float *data used
	//write user stats to stat.txt and extract user number
	int usr_no=write_stat(datum[0],datum[1]);
	//open user file and write stat of user
	name=calloc(strlen(usr_name)+1,sizeof(char));
	strcpy(name,usr_name);
	strcat(name,".txt");
	FILE* fptr;
	fptr=fopen(name,"w");
	fnull(fptr);
	fprintf(fptr,"%d %d %s %f %f",1,usr_no,usr_name,datum[0],datum[1]);//data[0]==accuracy, data[1]==wpm, 1=lesson_num
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
	fflush(stdin);
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
