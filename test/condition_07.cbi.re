#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define	BSIZE	8192

typedef struct Scanner
{
	FILE			*fp;
	unsigned char	*cur, *tok, *lim, *eof;
	unsigned char 	buffer[BSIZE];
} Scanner;

int fill(Scanner *s, int len)
{
	if (!len)
	{
		s->cur = s->tok = s->lim = s->buffer;
		s->eof = 0;
	}
	if (!s->eof)
	{
		int got, cnt = s->tok - s->buffer;

		if (cnt > 0)
		{
			memcpy(s->buffer, s->tok, s->lim - s->tok);
			s->tok -= cnt;
			s->cur -= cnt;
			s->lim -= cnt;
		}
		cnt = BSIZE - cnt;
		if ((got = fread(s->lim, 1, cnt, s->fp)) != cnt)
		{
			s->eof = &s->lim[got];
		}
		s->lim += got;
	}
	else if (s->cur + len > s->eof)
	{
		return 0; /* not enough input data */
	}
	return -1;
}

void fputl(const char *s, size_t len, FILE *stream)
{
	while(len-- > 0)
	{
		fputc(*s++, stream);
	}
}

/*!types:re2j */

void scan(Scanner *s)
{
	int cond = EStateR1;
	
	fill(s, 0);

	for(;;)
	{
		s->tok = s->cur;
/*!re2j

re2j:define:YYCTYPE     = "unsigned char";
re2j:define:YYCURSOR    = s->cur;
re2j:define:YYLIMIT     = s->lim;
re2j:define:YYMARKER    = s->tok;
re2j:define:YYFILL@len  = #;
re2j:define:YYFILL:naked= 1;
re2j:define:YYFILL      = "{ if(fill(s, #) >= 0) break; }";
re2j:define:YYGETCONDITION       = cond;
re2j:define:YYGETCONDITION:naked = 1;
re2j:yyfill:parameter   = 0;
re2j:indent:top         = 2;
re2j:condenumprefix     = EState;

NUM		= [0-9];
ALNUM	= NUM|[a-zA-Z];
ANY		= [^];

<R1>	ALNUM+
				{
					continue;
				}
<R1>	ANY
				{
					continue;
				} 

<R2>	ALNUM+
				{
					continue;
				}
<R2>	ANY
				{
					continue;
				} 
*/
	}
}

int main(int argc, char **argv)
{
	Scanner in;
	char c;

	if (argc != 2)
	{
		fprintf(stderr, "%s <file>\n", argv[0]);
		return 1;;
	}

	memset((char*) &in, 0, sizeof(in));

	if (!strcmp(argv[1], "-"))
	{
		in.fp = stdin;
	}
	else if ((in.fp = fopen(argv[1], "r")) == NULL)
	{
		fprintf(stderr, "Cannot open file '%s'\n", argv[1]);
		return 1;
	}

	scan(&in);

	if (in.fp != stdin)
	{
		fclose(in.fp);
	}
	return 0;
}
