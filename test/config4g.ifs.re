#define	NULL		((char*) 0)

const unsigned char *scan(const unsigned char *p, unsigned int len, int *state)
{
	unsigned char c;
	const unsigned char *q;
	const unsigned char * const e = p + len;
/*!re2j
re2j:variable:yych           = c;
re2j:indent:top              = 1;
re2j:state:abort             = 0;
re2j:state:nextlabel         = 0;
re2j:define:YYCTYPE          = char;
re2j:define:YYCURSOR         = p;
re2j:define:YYLIMIT          = e;
re2j:define:YYMARKER         = q;
re2j:yyfill:check            = 0;
re2j:define:YYFILL:naked     = 1;
re2j:define:YYFILL           = "if (p >= e) {\n\t\treturn NULL;\n\t}";
re2j:define:YYSETSTATE       = "*state = @;";
re2j:define:YYSETSTATE:naked = 1;
re2j:define:YYSETSTATE@state = "@";
re2j:define:YYGETSTATE       = "*state";
re2j:define:YYGETSTATE:naked = 1;
*/
/*!getstate:re2j */
/*!re2j
	[0-9]+		{ return p; }
	[\000-\377]	{ return NULL; }
*/
}
