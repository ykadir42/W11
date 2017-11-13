/*
Jawad Kadir
Brian Leung
HW 11
*/

//INCLUSIONS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

char** parse_args(char* yeah)
{
	//Init copy of argstring and array to store it.
	char * yeahcpy = (char *)malloc(sizeof(yeah));
	strcpy(yeahcpy,yeah);
	char **arr = (char**) malloc(sizeof *arr * 8); 

	if (arr)
	{
	  //The i is just to help me keep track of the strings.
	  int i = 0;
	  while(yeahcpy!=NULL)
	  {
	  	//Copy the strsepped string into the array.
	    arr[i] = malloc(sizeof *arr[i] * 8);
	    printf("yeahcpy is %s\n",yeahcpy);
	    strcpy(arr[i], strsep(&yeahcpy," ")); 
	    printf("arr[%d] is %s\n",i,arr[i]);
	    i++;
	  }
	}
	//Free the copied string.
	free(yeahcpy);
	return arr;

}

int main(){
  //<strung> is the test string.
  char* strung = "ls -al .";
  char** cmd = parse_args(strung);
  printf("\nMade it, executing command now.\n");
  execvp(cmd[0],cmd);
  
  free(cmd);
  return 0;
}

