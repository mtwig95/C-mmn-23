/*This program prints its own source file*/
 
#include <stdio.h>

int main() {
    FILE *fp;
    int c;
   
    fp = fopen(__FILE__,"r");

    do { /*Loop to read and print each character until the end of the file*/
         c = getc(fp);
         putchar(c);
    }
    while(c != EOF);
    
    fclose(fp);
    return 0;
}
