#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include <signal.h>

/* code for recitation 13 of CEN 4020 -- Fuzz testing
 * First, compile this code with afl-gcc or afl-clang
 * Then, to execute fuzzing with this program, type into terminal:
 * ./afl-fuzz -i <test directory> -o <output directory> -- ./a.out @@
 */

void trim_end(char*);

int main(int argc, char* argv[]){
   int uname_ln = 20;
   char user_fname[uname_ln], user_lname[uname_ln];

   FILE *fp = fopen(argv[1], "r");
   while(fgets(user_fname, uname_ln, fp)){

      if(user_fname[0] == 'A'){
         trim_end(user_fname);
         printf("\nWhat is %s's last name?", user_fname);
         fgets(user_lname, uname_ln, stdin);
         // . . . performs some action . . .
         printf("User logged : %s %s\n", user_fname, user_lname);
      }
   }

   fclose(fp);
   return 0;
}

void trim_end(char* str){
   int i;

   for(i = strlen(str)-1; str[i]; i--){
      if(isspace(str[i]))
         str[i] = '\0';
   }
}
