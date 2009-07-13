unsigned char scan(const unsigned char *s)
{
	unsigned char* cr;
	unsigned char  ch;
/*!re2j

re2j:define:YYCTYPE     = "unsigned char";
re2j:define:YYCURSOR    = cr;
re2j:define:YYFILL      = fill;
re2j:variable:yych      = ch;
re2j:yyfill:enable      = 0;

"a" := return 'a';
"b" := return 'b';

*/
}
