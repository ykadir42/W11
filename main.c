#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char ** parse_args( char * line ){
  char ** ans = (char **)malloc(sizeof(line)+1);
  int i = 0;
  while(line){
    ans[i] = strsep(&line, " ");
    i++;
  }
  ans[i] = NULL;
  return ans;
}

int main(){
  //char line[100] = "wow-this-is-cool";
  //char *s1 = line;
  //printf("[%s]\n", strsep( &s1, "-" ));
  //printf("[%s]\n", s1);

  char** args = parse_args("ls -al .");
  int i = 0;
  while(args[i])
    printf("%s\n", args[i]);
  return 0;
}
