#include <stdio.h>
int main(){
        FILE* fa;
        fa=fopen("stat.txt","w");
        fprintf(fa,"%d %d %s %f %f\n",1,1,"Rabin",100,32.5);
        fclose(fa);
}