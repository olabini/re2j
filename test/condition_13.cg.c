/* Generated by re2j */
#line 1 "condition_13.cg.re"

#line 5 "<stdout>"
{
	YYCTYPE yych;
	static void *yyctable[3] = {
		&&yyc_0,
		&&yyc_r1,
		&&yyc_r2,
	};
	goto *yyctable[YYGETCONDITION()];
/* *********************************** */
yyc_0:
	YYSETCONDITION(yycr1);
#line 3 "condition_13.cg.re"
	goto yyc_r1;
#line 19 "<stdout>"
/* *********************************** */
yyc_r1:
	if (YYLIMIT <= YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
	if (yych <= '2') {
		if (yych <= '0') goto yy6;
		if (yych <= '1') goto yy9;
		goto yy7;
	} else {
		if (yych <= '`') goto yy6;
		if (yych <= 'a') goto yy11;
		if (yych <= 'b') goto yy13;
	}
yy6:
yy7:
	++YYCURSOR;
#line 5 "condition_13.cg.re"
	goto yyc_r1;
#line 38 "<stdout>"
yy9:
	++YYCURSOR;
#line 4 "condition_13.cg.re"
	goto yyc_r1;
#line 43 "<stdout>"
yy11:
	++YYCURSOR;
	YYSETCONDITION(yycr2);
#line 6 "condition_13.cg.re"
	goto yyc_r2;
#line 49 "<stdout>"
yy13:
	++YYCURSOR;
	YYSETCONDITION(yycr2);
#line 7 "condition_13.cg.re"
	goto yyc_r2;
#line 55 "<stdout>"
/* *********************************** */
yyc_r2:
	if (YYLIMIT <= YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
	if (yych <= '2') {
		if (yych <= '0') goto yy17;
		if (yych <= '1') goto yy20;
		goto yy18;
	} else {
		if (yych == 'b') goto yy22;
	}
yy17:
yy18:
	++YYCURSOR;
	YYSETCONDITION(yycr1);
#line 5 "condition_13.cg.re"
	goto yyc_r1;
#line 73 "<stdout>"
yy20:
	++YYCURSOR;
	YYSETCONDITION(yycr1);
#line 4 "condition_13.cg.re"
	goto yyc_r1;
#line 79 "<stdout>"
yy22:
	++YYCURSOR;
#line 7 "condition_13.cg.re"
	goto yyc_r2;
#line 84 "<stdout>"
}
#line 9 "condition_13.cg.re"

