/* Generated by re2j */
#line 1 "condition_01.c.re"

#line 5 "<stdout>"
{
	YYCTYPE yych;
	switch (YYGETCONDITION()) {
	case yyca: goto yyc_a;
	case yycb: goto yyc_b;
	}
/* *********************************** */
yyc_a:
	if ((YYLIMIT - YYCURSOR) < 2) YYFILL(2);
	yych = *YYCURSOR;
	switch (yych) {
	case 'a':	goto yy4;
	default:	goto yy3;
	}
yy3:
yy4:
	yych = *++YYCURSOR;
	switch (yych) {
	case 'b':	goto yy5;
	default:	goto yy3;
	}
yy5:
	++YYCURSOR;
#line 3 "condition_01.c.re"
	{ }
#line 31 "<stdout>"
/* *********************************** */
yyc_b:
	if ((YYLIMIT - YYCURSOR) < 2) YYFILL(2);
	yych = *YYCURSOR;
	switch (yych) {
	case 'a':	goto yy10;
	default:	goto yy9;
	}
yy9:
yy10:
	yych = *++YYCURSOR;
	switch (yych) {
	case 'b':	goto yy11;
	default:	goto yy9;
	}
yy11:
	++YYCURSOR;
#line 3 "condition_01.c.re"
	{ }
#line 51 "<stdout>"
}
#line 5 "condition_01.c.re"

