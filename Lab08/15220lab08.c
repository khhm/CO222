#include<stdio.h>
#include<string.h>
#define SIZE 1000

int main(int argc , char** argv){

   FILE * pFile;
   int max_width = 0;
   int sum=0;
   int i;
   char ch;
 
   if(argc != 3){ // checking for number of arguments
     printf("Usage: ./prog <width> <input-file>\n"); 
     return -1;
   }
   
   for(i=0; argv[1][i] != '\0' ; i++){
     max_width=max_width*10+argv[1][i]-'0';
   }

   char buffer[SIZE]; 
   pFile = fopen(argv[2] , "r");
   if(max_width >= 0){           
     while (fscanf(pFile, "%s", buffer)!=EOF){
        if(strlen(buffer)>max_width){     // checking for word length
           printf("Word length must be less than screen width\n");
           return -1;
        }
     }
   }

   rewind(pFile); // reset the file pointer position
   while (fscanf(pFile, "%s", buffer)!=EOF){
      sum=sum+strlen(buffer);
      if(sum < max_width){
          fputs(buffer , stdout);
      }else{
          printf("\n");
          fputs(buffer , stdout);
          sum = strlen(buffer);
      }
          fscanf(pFile,"%c",&ch);
            if(ch==' '){
               printf(" ");  // print spaces
               sum=sum+1;       
            }else if(ch=='\n'){ // cheking for new paragraphs
               printf("\n");
               sum=0;
            }
   }
   fclose(pFile);
return 0;
}
