#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <conio.h>
#include <stdio_ext.h>
#include <time.h>
#include "tt.h"
int main()
{
	mainmenu();
	char ch=getchar();
	__fpurge(stdin);//used instead of fflush(stdin)
	switch (ch)
	{
		case '1':
			type();
			break;
		case '2':
			stat();
			break;
		case '3':
			about();
			break;
		case '4':
			exit(0);
		default:
			printf("I'm sorry. I didn't get that.");
			cls();
			main();
	}
}
void mainmenu()
{
	printf("Main Menu:\n\n\n");
	printf("1. Type\n\n");
	printf("2. Statistics\n\n");
	printf("3. About\n\n");
	printf("4. Exit\n\n");
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
	else if (tolower(ch)!='y')
		printf("I'm sorry. I didn't get that.\n");
	} while (1);
	usr=calloc(i,sizeof(char));
	printf("\n\nEnter the paragraph given above:\n\n");
	s1=time(NULL);
	for (x=0; x<i;x++)
	{
		usr[i]=getche();
	}
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
	printf("Typing Tutor 1.0\n\n");
	printf("Developers: Rabin Adhikari\n");
	printf("%11c Pujan Dahal\n",' ');
	printf("%11c Saurab Bhusal\n",' ');
	continue_();
}

void continue_()
{
	printf("\n\nDo you want to goto Main Menu?\n");
	char ch=getchar();
	__fpurge(stdin);//used instead of fflush(stdin)
	if(tolower(ch)=='y'){
		cls();
		main();
	}
	else if (tolower(ch)=='n')
		exit(0);
	else
	{
		printf("I'm sorry. I didn't get that.\n");
		continue_();
	}
}
