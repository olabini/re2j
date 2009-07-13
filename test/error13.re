/*!max:re2j */

/*!re2j
	"ABC"		{ return 1; }
	"ABD"		{ return 2; }
	[^]			{ return 0; }
*/
