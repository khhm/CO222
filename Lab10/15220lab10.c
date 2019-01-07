#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define SIZE 100

typedef struct node{ // Creating a node
   char str[100]; // Here store the length
   int len; // Here store the length of the string
   struct node * next;
}node_t;

int print_list(node_t * head ,int max) {  // print_list function print strings according to decending order
    while(max > 0){
       node_t * current = head;
       while (current != NULL) {
          if(current->len == max){
               printf("%s\n", current->str);
          }
          current = current->next;
       }
       max--;
    }
    return 0;
}
int maximum_length(node_t * head){ // maximum_length function find maximum length string in file and return max length
    node_t * current = head;
    static int max_length=-1;
    while (current != NULL) {
        if(current->len > max_length){
           max_length = current->len;
        }
        current = current->next;
    }
   return max_length;
}

int main(int argc , char **argv){
   FILE * pFile;
   char buffer[SIZE]={};
   node_t head;
   node_t * iterator = &head;

   if(argc != 2){ // if number of arguments are wrong here print error massage
     printf("Usage: ./prog <input-file>\n");
     return -1;
   }

   pFile = fopen(argv[1],"r");

   while( !feof(pFile)) {
      fscanf(pFile,"%s",buffer);
      char buff[SIZE]={};
      int value=1;
      int c=0;
      for(int i=0; buffer[i] != '\0' ; i++){
          if((buffer[i] > 96 && buffer[i] < 128) || (buffer[i] > 64 && buffer[i] < 91)){
              buff[c] = buffer[i];
              c++;
          }
      }
      node_t * newNode = NULL;
      newNode = malloc(sizeof(node_t));
      iterator->next = newNode;
      node_t * temp = &head; 
      while(temp->next != NULL){  // If same string is occures more than one time here check it
        temp = temp->next;
        if(strlen(buff)==temp->len){
          value = strcmp(temp->str,buff);
        }
        if(value == 0){
          break;
        }
      }
      if(value != 0){
          strcpy(newNode-> str ,buff);  // assign string to newNode
          newNode->len = strlen(buff);  // assign string length to newNode
      }
      iterator = newNode;
   }
   fclose(pFile);
   print_list(&head ,maximum_length(&head)); // Calling print_list function
   return 0;
}