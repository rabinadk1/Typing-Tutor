#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main()
{
	char name[20],*para,*usr,ch;
	printf("Enter your name: ");
	scanf("%s",name);
	getchar();
	time_t s1,s2;
	int wcount=1,i=0,error=0,x,usr_no;
	FILE * fr,* fa; //fr to read and fa to write without erasing
	fr=fopen("lesson.txt","r");
	while((ch=getc(fr))!=EOF){
		i++;
	}
	para=calloc(i,sizeof(char));
	rewind(fr);
	fgets(para,i+1,fr);
	puts(para);
	usr=calloc(i,sizeof(char));
	printf("\nEnter the paragraph given above:\n");
	s1=time(NULL);
	scanf("%[^\n]",usr);
	s2=time(NULL);
	for (x=0;x<i;x++)
	{
		if(para[x]==' ')
			wcount++;
		if (usr[x]!=para[x])
			error++;
	}
	float wpm, accuracy;
	wpm=wcount*60.0/(s2-s1);
	accuracy=(1-(float)error/i)*100;
	printf("Accuracy: %.2f%%\nWPM: %.2f",accuracy,wpm);
	fa=fopen("stat.txt","r+");
	fscanf(fa,"%d",&usr_no);
	fseek(fa,0,2);
	fprintf(fa,"%d %s %f %f\n",++usr_no,name,accuracy,wpm);
	rewind(fa);
	fprintf(fa,"%d",usr_no);
	fclose(fa);
	fclose(fr);
	return 0;
}
