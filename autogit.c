#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc,char *argv[])
{
  if (argc < 2 || argc > 3)
  {
    fprintf(stderr,"%s [Directory] <Commit Message>\n",argv[0]);
    exit(1);
  }
  
  char str[1000];
  
  if (argc == 2)
  {
      
      strcpy(str, "\
      #/bin/bash \n\
      git add -A\n\
      git commit -m \"");
      
      strcat(str, argv[1]);
      
      strcat(str, "\"\n\
      git push origin master\n\
      ");
  }
  else
  {
    strcpy(str, "\
    #/bin/bash \n\
    git add ");

    strcat(str, argv[1]);

    strcat(str, "*\n\
    git commit -m \"");

    strcat(str, argv[2]);

    strcat(str, "\"\n\
    git push origin master\n\
    ");
  }

  system(str);
  return 0;
}
