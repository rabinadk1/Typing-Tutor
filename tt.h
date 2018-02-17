void type();
//void selectuser();
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
#define UP 'w'
#define DOWN 's'
#define ENTER 'e'
#define ARROW "-->"

void LOGO()
{
	printf("\
            ************         #### #    # #### #### #   # ####    #### #  # #### #### ####        **************\n\
            ************          ##   #  #  #  #  ##  ##  # #        ##  #  #  ##  #  # #  #        **************\n\
            ************          ##    ##   ####  ##  # # # # ##     ##  #  #  ##  #  # ####        **************\n\
            ************          ##    ##   #     ##  #  ## #  #     ##  #  #  ##  #  # ##          **************\n\
            ************          ##    ##   #    #### #   # ####     ##  ####  ##  #### # #         **************\n\n");
	printf("\n\n\t\t\t\t\t+++++++++++>>>>  WELCOME  <<<<++++++++++++\n\n");
}
