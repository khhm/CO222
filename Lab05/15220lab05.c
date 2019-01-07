#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define RESET		0
#define BRIGHT 		1

#define BLACK 		0
#define RED		1
#define GREEN		2
#define YELLOW		3
#define BLUE		4
#define MAGENTA		5
#define CYAN		6
#define	WHITE		7

int  argCount();
int  is_Figure_Available();
int  is_BG_Color_Available();
int  is_FG_Color_Available();
void print_Checker();
void print_Donut();

char **g_argv;
int  g_argc;
int  checker=0,donut=0,backcolor=-1,forecolor=-1,diameter=0,distance;
int  color[]={BLACK,RED,GREEN,YELLOW,BLUE,MAGENTA,CYAN,WHITE};
char input[][10]={"black","red","green","yellow","blue","magenta","cyan","white"}; // String array to compare input colours

void textcolor(int attr, int fg, int bg);

void textcolor(int attr, int fg, int bg)
{	char command[13];

	/* Command is the control command to the terminal */

	/* textcolor(BRIGHT,BLACK,WHITE) will have characters printed in
	black in white background */
	sprintf(command, "%c[%d;%d;%dm", 0x1B, attr, fg + 30, bg + 40);
	printf("%s", command);
}





int main(int argc, char **argv){

   g_argv=argv;
   g_argc=argc;

   if(argCount()==-1){
      return -1;
   }
   if(is_Figure_Available()==-1){
      return -1;
   }
   if(is_BG_Color_Available()==-1){
      return -1;
   }
   if(is_FG_Color_Available()==-1){
      return -1;
   }

   if(checker==1){
      print_Checker();
   }

   if(donut==1){
      scanf("%d",&diameter);         // If figure is donut here ask to enter diameter
      if(diameter>0){                       //Here check radius is valid or not
         print_Donut();
      }else{
         return -1;
      }
   }
   return 0;
}



int argCount(){
     
   if(g_argc < 4){
      printf("Not enough arguments\n");  // Here check whether number of arguments are correct
      return -1;
   }else if(g_argc > 4){
      printf("Too many arguments\n");
      return -1;
   }
   return 0;
}


int is_Figure_Available(){

   if(!strcmp(g_argv[1],"checker")){
      checker=1;
   }else if(!strcmp(g_argv[1],"donut")){     // Here check what figure is has to print and it is valid figure
      donut=1;
   }else{
      printf("Requested figure is not available\n");
   return -1;
   }
   return 0;
}
 

int is_BG_Color_Available(){

   for(int a=0;a<8;a++){
      if(!strcmp(g_argv[2],input[a])){    // Here get integer assign to Background color
         backcolor=color[a];
      }
   }

   if(backcolor==-1){
      printf("Background color is not available\n");  // Here check Background color is available or not
      return -1;
   }
   return 0;
}


int is_FG_Color_Available(){

   for(int b=0;b<8;b++){
      if(!strcmp(g_argv[3],input[b])){     // Here get integer assign to Foreground color
         forecolor=color[b];
      }
   }

   if(forecolor==-1){
      printf("Foreground color is not available\n");  // Here check Background color is available or not
      return -1;
   }
   return 0;
}


void print_Checker(){

   for(int i=0;i<8;i++){
     for(int j=0;j<8;j++){
       for(int k=0;k<4;k++){
          if(i%2==1){ 
             textcolor(RESET, forecolor , backcolor); 
             printf("        "); 
             textcolor(RESET, backcolor , forecolor);
             printf("        ");
          
          }else{                                        // If figure is checker borad here print 8*8 checker board
             textcolor(RESET, backcolor , forecolor);
             printf("        ");
             textcolor(RESET, forecolor , backcolor);
             printf("        ");
          }
          textcolor(RESET, forecolor , backcolor);
       }
       printf("\n"); 
     }
   }
   textcolor(RESET, WHITE, BLACK);
}


void print_Donut(){

   for(int i=0;i<diameter;i++){
       for(int j=0;j<diameter;j++){    
              
           distance=(i-(diameter/2))*(i-(diameter/2))+(j-(diameter/2))*(j-(diameter/2));
           if(distance+0.5<(double)diameter/2*(double)diameter/2  &&  distance>(double)diameter/4*(double)diameter/4){    // Here print donut 
               textcolor(RESET, backcolor , forecolor);
               printf(" ");
           }else{
               textcolor(RESET, forecolor , backcolor);
               printf(" ");
           }
               textcolor(RESET, forecolor , backcolor);
           }
       printf("\n");
   }    
   textcolor(RESET, WHITE, BLACK);	
}