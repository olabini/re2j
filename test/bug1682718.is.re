char *scan(char *p)
{
/*!re2j
        re2j:define:YYCTYPE  = "unsigned char";
        re2j:define:YYCURSOR = p;
        re2j:yyfill:enable   = 0;
        re2j:yych:conversion = 1;
        re2j:indent:top      = 1;
        [0-9]+          {return p;}
        [\000-\377]     {return (char*)0;}
*/
}

