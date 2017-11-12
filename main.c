#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#define N      20  // For this example, we will allocate 20 strings
#define LENGTH 10

char** parse_args(char* yeah)
{
	char * yeahcpy = (char *)malloc(sizeof(yeah));
	strcpy(yeahcpy,yeah);
	char **arr = (char**) malloc(sizeof *arr * N); 
	if (arr)
	{
	  int i = 0;
	  while(yeahcpy!=NULL)
	  {
	    arr[i] = malloc(sizeof *arr[i] * (LENGTH + 1));
	    printf("yeahcpy is %s\n",yeahcpy );
	    strcpy(arr[i], strsep(&yeahcpy," ")); 
	    printf("arr[%d] is %s\n",i,arr[i] );
	    i++;
	  }
	}
	return arr;

}

/*
char ** parse_args(char* sting)
{
	char* temp = sting;
	char * ans[512];
	int i = 0;
	for (int j = 0; j<511; j++)
	{
		ans[j] = malloc(32);
	}	
	printf("made\n");
	while((temp = strsep(&temp," ")) != NULL)
	{
		printf("made!\n");
		printf("%s\n",temp);
	}
	return ans;
}
	ans[i] = NULL;
	return ans;
char ** parse_args( char * line ){
  char ** ans = (char **)malloc((sizeof(line)+1));
  int i = 0;
  while(line){
    ans[i] = strsep(&line, " ");
    i++;
  }
  ans[i] = NULL;
  return ans;
}
*/
int main(){
  //char line[100] = "wow-this-is-cool";
  //char *s1 = line;
  //printf("[%s]\n", strsep( &s1, "-" ));
  //printf("[%s]\n", s1);
	char* strung = "ls -al .";
  char** cmd = parse_args(strung);
  printf("\nMade it, executing command now.\n");
  execvp(cmd[0],cmd);
  /*while(args[i])
    printf("%s\n", args[i]);
  free(args);*/
  //return 0;
  return 0;

}

