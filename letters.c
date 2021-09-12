/******************************************************************************
The program output the file in the following form:
1) each sentence will start after a point in capital letter, the rest in small letters.
2) Each quote will be written in capital letters only.
3) The program will not issue digits.
*******************************************************************************/

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>

#include "info.h"

enum status
{
  NEW, IN, STR
};


int
main ()
{
int c;
int state = NEW;


if (!isatty(0)){
	char buffer[BUFFERSIZE];
	fgets(buffer, BUFFERSIZE, stdin);
	printf("The reformatted file output:\n%s", buffer);
}
else {
 printf("please enter sentence:\n");
}


  while ((c = getchar ()) != EOF)
    {
      switch (state)
	{

	case NEW:

	  if (isdigit (c))
	    {
	      break;
	    }
	  if (c == '\"')
	    {
	      putchar(c);
	      state = STR;
	      break;
	    }
	  if (isalpha (c))
	    {
	      putchar (toupper (c));
	      state = IN;
	      break;
	    }
	  putchar (c);
	  break;


	case IN:
	  //printf ("IM IN");
	  if (isdigit (c))
	    {
	      break;
	    }
	  if (c == '\"')
	    {
	      putchar(c);
	      state = STR;
	      break;
	    }
	  if (isalpha (c))
	    {
	      putchar (tolower (c));
	      break;
	    }
	  if (c == '.')
	    {
	      putchar (c);
	      state = NEW;
	      break;
	    }
	  putchar (c);
	  break;

	case STR:
	  //printf ("IM STR");
	  if (isdigit (c))
	    {
	      break;
	    }
	  if (c == '\"')
	    {
		putchar(c);
	      state = IN;
	      break;
	    }
	  if (isalpha (c))
	    {
	      putchar (toupper (c));
	      break;
	    }
	putchar(c);

	  break;

	}
    }
  return 0;

}

