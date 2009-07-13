#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define	BSIZE	8192

/*!types:re2j */

typedef struct Scanner
{
	FILE			    *fp;
	unsigned char	    *cur, *tok, *lim, *eof;
	unsigned char 	    buffer[BSIZE];
	unsigned char       yych;
	enum ScanContition  cond;
	int                 state;
} Scanner;

size_t fill(Scanner *s, size_t len)
{
	size_t got = ~0, cnt;

	if (!s->eof && s->lim - s->tok < len)
	{
		if (s->tok > s->buffer)
		{
			cnt = s->tok - s->buffer;
			memcpy(s->buffer, s->tok, s->lim - s->tok);
			s->tok -= cnt;
			s->cur -= cnt;
			s->lim -= cnt;
			cnt = &s->buffer[BSIZE] - s->lim;
		}
		else
		{
			cnt = BSIZE;
		}
		if ((got = fread(s->lim, 1, cnt, s->fp)) != cnt)
		{
			s->eof = &s->lim[got];
		}
		s->lim += got;
	}
	if (s->eof && s->cur + len > s->eof)
	{
		return ~0; /* not enough input data */
	}
	return got;
}

size_t init(Scanner *s)
{
	s->cur = s->tok = s->lim = s->buffer;
	s->eof = 0;
	s->cond = EStateNormal;
	s->state = -1;

	return fill(s, 0);
}

void fputl(const char *s, size_t len, FILE *stream)
{
	while(len-- > 0)
	{
		fputc(*s++, stream);
	}
}

void scan(Scanner *s)
{
	s->tok = s->cur;
/*!re2j
re2j:define:YYGETSTATE       = "s->state";
re2j:define:YYGETSTATE:naked = 1;
re2j:define:YYCONDTYPE       = ScanContition;
re2j:indent:top              = 1;
re2j:cond:goto               = "continue;";
*/
/*!getstate:re2j */
	for(;;)
	{
		s->tok = s->cur;
/*!re2j

re2j:define:YYCTYPE          = "unsigned char";
re2j:define:YYCURSOR         = s->cur;
re2j:define:YYLIMIT          = s->lim;
re2j:define:YYMARKER         = s->tok;
re2j:define:YYFILL@len       = #;
re2j:define:YYFILL:naked     = 1;
re2j:define:YYFILL           = "if (fill(s, #) == ~0) break;";
re2j:define:YYSETSTATE@state = #;
re2j:define:YYSETSTATE       = "s->state = #;";
re2j:define:YYSETCONDITION       = "s->cond = #;";
re2j:define:YYSETCONDITION@cond  = #;
re2j:define:YYGETCONDITION       = s->cond;
re2j:define:YYGETCONDITION:naked = 1;
re2j:variable:yych           = s->yych;
re2j:yych:emit               = 0;
re2j:indent:top              = 2;
re2j:condenumprefix          = EState;

<Normal>	"??(" :=
			fputc('[', stdout);
			continue;
<Normal>	"??)" :=
			fputc(']', stdout);
			continue;
<Normal>	"??<" :=
			fputc('{', stdout);
			continue;
<Normal>	"??>" :=
			fputc('}', stdout);
			continue;
<Normal>	"??=" :=
			fputc('#', stdout);
			continue;
<Normal>	"??/" :=
			fputc('\\', stdout);
			continue;
<Normal>	"??'" :=
			fputc('^', stdout);
			continue;
<Normal>	"??!" :=
			fputc('|', stdout);
			continue;
<Normal>	"??-" :=
			fputc('~', stdout);
			continue;
<Normal>	"/*" :=> Comment
<Normal>	"//" :=> Skiptoeol
<Normal>	"'\\\"'"|"'\"'" :=
			fputl("'\"'", 3, stdout);
			continue;
<Normal>	'"' => String :=
			fputc(s->cur[-1], stdout);
			continue;
<Normal>	[^] :=
			fputc(s->cur[-1], stdout);
			continue;
<Comment>	"*" "/" :=> Normal
<Comment>	[^] :=> Comment
<Skiptoeol>	"??/" "\r"? "\n" :=> Skiptoeol
<Skiptoeol>	"\\" "\r"? "\n" :=> Skiptoeol
<Skiptoeol>	"\r" "\n" => Normal :=
			fputc('\r', stdout);
			fputc('\n', stdout);
			continue;
<Skiptoeol>	"\n" => Normal :=
			fputc('\n', stdout);
			continue;
<Skiptoeol>	[^] :=> Skiptoeol
<String>	'\\' . :=
			fputl((const char*)s->cur-2, 2, stdout);
			continue;
<String>	'"' => Normal :=
			fputc(s->cur[-1], stdout);
			continue;
<String>	[^] :=
			fputc(s->cur[-1], stdout);
			continue;
*/
	}
}

int main(int argc, char **argv)
{
	Scanner in;

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

	if (init(&in) > 0)
	{
 		scan(&in);
 	}

	if (in.fp != stdin)
	{
		fclose(in.fp);
	}
	return 0;
}
