/*
Jawad Kadir
Brian Leung
HW 11
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

char** parse_args(char* yeah)
{
	char * yeahcpy = (char *)malloc(sizeof(yeah));
	strcpy(yeahcpy,yeah);
	char **arr = (char**) malloc(sizeof *arr * 128); 
	if (arr)
	{
	  int i = 0;
	  while(yeahcpy!=NULL)
	  {
	    arr[i] = malloc(sizeof *arr[i] * 128);
	    printf("yeahcpy is %s\n",yeahcpy );
	    strcpy(arr[i], strsep(&yeahcpy," ")); 
	    printf("arr[%d] is %s\n",i,arr[i] );
	    i++;
	  }
	}
	free(yeahcpy);
	return arr;

}

int main(){
	char* strung = "ls -al .";
  char** cmd = parse_args(strung);
  printf("\nMade it, executing command now.\n");
  execvp(cmd[0],cmd);
  free(cmd);
  return 0;

}

