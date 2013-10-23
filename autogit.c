#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SHELLSCRIPT "\
#/bin/bash \n\
echo \"hello\" \n\
echo \"how are you\" \n\
echo \"today\" \n\
"

int main(int argc,char *argv[])
{
  if (argc != 2)
  {
    fprintf(stderr,"%s <Commit Message>\n",argv[0]);
    exit(1);
  }
  
  char str[1000];
  strcpy(str, "\
  #/bin/bash \n\
  git add *\n\
  git commit -m \"");
  strcat(str, argv[1]);
  strcat(str, "\"\n\
  git push origin master\n\
  ");

  system(str);
  return 0;
}