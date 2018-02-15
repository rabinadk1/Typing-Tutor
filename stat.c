#include <stdio.h>
int main()
{
	FILE * fptr;
	fptr=fopen("stat.txt","r");
	int no,user_no;
	float accuracy,wpm;
	char name[20];
	fscanf(fptr,"%d ",&no);
	printf("%-6s %-20s %-15s %-6s\n\n","SN","Name","Accuracy","WPM");
	for (int i=0;i<no;i++)
	{
		fscanf(fptr,"%d %s %f %f\n",&user_no,name,&accuracy,&wpm);
		printf("%-6d %-20s %-15.2f %-6.2f\n",user_no,name,accuracy,wpm);
	}
	fclose(fptr);
}
