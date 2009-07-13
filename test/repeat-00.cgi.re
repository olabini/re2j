// multiples scanners

void scan(unsigned char* in)
{
/*!rules:re2j

<*>		"1"	{ return "1"; }
<*>		"2"	{ return "2"; }
<r1>	"a" { return "a"; }
<r1,r2>	"b" { return "b"; }
*/

/*!use:re2j

re2j:define:YYCTYPE  = 'unsigned char';






*/
}

void scan(unsigned short* in)
{
/*!use:re2j






*/
}

void scan(unsigned int* in)
{
/*!use:re2j






*/
}

