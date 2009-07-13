// multiple scanners, additional rules, char width change

void scan(unsigned char* in)
{
/*!rules:re2j

"a" := return "a";
"b" := return "b";
"c" := return "c";
"d" := return "d";

re2j:indent:top = 1;

*//*!use:re2j

re2j:flags:u = 0;
re2j:flags:w = 0;

re2j:define:YYCTYPE  = 'unsigned char';
re2j:define:YYFILL   = 'fill1';
re2j:define:YYCURSOR = 'cursor1';
re2j:define:YYLIMIT  = 'limit1';

"1"	:= return "1";
.   := return ".";

*/
}

void scan(unsigned short* in)
{
/*!use:re2j

re2j:flags:u = 0;
re2j:flags:w = 1;

re2j:define:YYCTYPE  = 'unsigned short';
re2j:define:YYFILL   = 'fill2';
re2j:define:YYCURSOR = 'cursor2';
re2j:define:YYLIMIT  = 'limit2';

"2"	:= return "2";
.   := return ".";

*/
}

void scan(unsigned int* in)
{
/*!use:re2j

re2j:flags:u = 1;
re2j:flags:w = 1;

re2j:define:YYCTYPE  = 'unsigned int';
re2j:define:YYFILL   = 'fill3';
re2j:define:YYCURSOR = 'cursor3';
re2j:define:YYLIMIT  = 'limit3';

"3"	:= return "3";
.   := return ".";

*/
}
