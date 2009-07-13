#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int scan(char *s)
{
	char *p = s;

	#define YYCTYPE         char
	#define YYCURSOR        p
	
	for(;;)
	{
/*!re2j
	re2j:indent:top    = 2;
	re2j:yyfill:enable = 0;

	"0"[0-9]+	{ printf("Oct\n");	continue; }
	[1-9][0-9]*	{ printf("Num\n");	continue; }
	"0"			{ printf("Num\n");	continue; }
	"+"			{ printf("+\n");	continue; }
	"-"			{ printf("-\n");	continue; }
	"\000"		{ printf("EOF\n");	return 0; }
	[^]			{ printf("ERR\n");	return 1; }
*/
	}
}

int main(int argc, char **argv)
{
	if (argc > 1)
	{
		return scan(argv[1]);
	}
	else
	{
		fprintf(stderr, "%s <expr>\n", argv[0]);
		return 1;
	}
}
