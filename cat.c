#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>

 

/* newcat: Concatenate files */

int main(int argc, char *argv[])

{

   void filecopy(int ifd, int ofd); /* prototype for function */

   int fd1,fd2,fd;

   char *prog = argv[0]; /* program name for errors */

  if (argc == 1) /* no args; copy standard input */

      filecopy(0, 1);

  else
  {
      //while (--argc > 0)

        /* if ((fd2 = open(*++argv, O_RDONLY, 0)) == -1) {

            fprintf(stderr, "%s: can't open %s\n", prog, *argv);

            exit(-1);

         } 
         if ((fd1 = open(*++argv, O_APPEND, 0)) == -1) {

            fprintf(stderr, "%s: can't open %s\n", prog, *argv);

            exit(-1);

         } 
         else {

            filecopy(fd1, fd2);

            close(fd1);
            close(fd2);

         }*/
             while (--argc > 0){

         	if((fd = open(*++argv, O_RDONLY, 0)) == -1) {

            fprintf(stderr, "%s: can't open %s\n", prog, *argv);

            exit(-1);

         } else {

            filecopy(fd, 1);

            close(fd);

         }
     }


        }
  

   exit(0);

}

/* filecopy: copy file ifp to ofp */

void filecopy(int ifd, int ofd)

{

   char buffer[512];

   int c;

   while ((c = read(ifd, buffer, 512)) != 0)

      write(ofd, buffer, c);

 

}








