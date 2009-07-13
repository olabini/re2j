#define	NULL		((char*) 0)
char *scan(char *p){
char *q;
#define	YYCTYPE		char
#define	YYCURSOR	p
#define	YYLIMIT		p
#define	YYMARKER	q
#define	YYFILL(n)
/*!re2j
	[0-9]+		{return YYCURSOR;}
	[\000-\377]	{return NULL;}
*/
}
