float *type(int);
void selectuser();
void stat();
void about();
void menu();
void continue_();
void new_();
int write_stat(float, float);
void existing();
void init_blank();

void cls()
{
	system("cls");
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
#define ENTER '\n'
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
