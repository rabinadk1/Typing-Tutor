void type();
void stat();
void about();
void mainmenu();
void continue_();

void cls()
{
	system("clear");
}

void fnull(FILE *fptr)
{
	if (fptr==NULL){
		printf("\n Error Occurred!!!");
		continue_();
	}
}
