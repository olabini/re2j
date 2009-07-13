// multiple scanners

/*!types:re2j */

void scan(unsigned char* in)
{
/*!rules:re2j

<*>		"1"	{ return "1"; }
<*>		"2"	{ return "2"; }
<r1>	"a" { return "a"; }
<r1,r2>	"b" { return "b"; }
*//*!use:re2j

re2j:define:YYCTYPE  = 'unsigned char';
re2j:define:YYFILL   = 'fill1';
re2j:define:YYCURSOR = 'cursor1';
re2j:define:YYLIMIT  = 'limit1';

*/
}

void scan(unsigned short* in)
{
/*!use:re2j

re2j:define:YYCTYPE  = 'unsigned short';
re2j:define:YYFILL   = 'fill2';
re2j:define:YYCURSOR = 'cursor2';
re2j:define:YYLIMIT  = 'limit2';

*/
}

void scan(unsigned int* in)
{
/*!use:re2j

re2j:define:YYCTYPE  = 'unsigned int';
re2j:define:YYFILL   = 'fill3';
re2j:define:YYCURSOR = 'cursor3';
re2j:define:YYLIMIT  = 'limit3';

*/
}

