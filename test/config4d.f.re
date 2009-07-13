#define	NULL		((char*) 0)
#define	YYCTYPE		char
#define	YYCURSOR	p
#define	YYLIMIT		p
#define	YYMARKER	q
#define	YYFILL(n)

char *scan(char *p)
{
	char *q;
/*!re2j
	re2j:startlabel = "start";
	re2j:state:abort = 0;
	re2j:state:nextlabel = 1;
	[0-9]+		{ return YYCURSOR; }
	[\000-\377]	{ return NULL; }
*/
}
