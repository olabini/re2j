/* Generated by re2j */
#line 1 "main.b.re"
/* re2j lesson 001_upn_calculator, main.b.re, (c) M. Boerger, L. Allan 2006 */
#line 43 "main.b.re"

#define VC_EXTRALEAN		// Exclude rarely-used stuff from Windows headers

#if _MSC_VER > 1200
#define WINVER 0x0400   // Change this to the appropriate value to target Windows 98 and Windows 2000 or later.
#endif                  // Prevents warning from vc7.1 complaining about redefinition

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <windows.h>
#include "HiResTimer.h"

static char gTestBuf[1000] = "";

/**
 * @brief Setup HiResolution timer and confirm it is working ok
 */
void InitHiResTimerAndVerifyWorking(void)
{
   double elapsed;
   HrtInit();
   HrtSetPriority(ABOVE_NORMAL_PRIORITY_CLASS);
   HrtStart();
   Sleep(100);
   elapsed = HrtElapsedMillis();
   if ((elapsed < 90) || (elapsed > 110)) {
      printf("HiResTimer misbehaving: %f\n", elapsed);
      exit(2);
   }
}

/**
 * @brief Scan for numbers in different formats
 */
int ScanFullSpeed(char *pzStrToScan, size_t lenStrToScan)
{
	unsigned char *pzCurScanPos = (unsigned char*)pzStrToScan;
	unsigned char *pzBacktrackInfo = 0;
#define YYCTYPE         unsigned char
#define YYCURSOR        pzCurScanPos
#define YYLIMIT         (pzStrToScan+lenStrToScan)
#define YYMARKER        pzBacktrackInfo
#define YYFILL(n)
	
	for(;;)
	{

#line 55 "<stdout>"
		{
			YYCTYPE yych;
			static const unsigned char yybm[] = {
				  0,   0,   0,   0,   0,   0,   0,   0, 
				  0,   0,   0,   0,   0,   0,   0,   0, 
				  0,   0,   0,   0,   0,   0,   0,   0, 
				  0,   0,   0,   0,   0,   0,   0,   0, 
				  0,   0,   0,   0,   0,   0,   0,   0, 
				  0,   0,   0,   0,   0,   0,   0,   0, 
				128, 128, 128, 128, 128, 128, 128, 128, 
				128, 128,   0,   0,   0,   0,   0,   0, 
				  0,   0,   0,   0,   0,   0,   0,   0, 
				  0,   0,   0,   0,   0,   0,   0,   0, 
				  0,   0,   0,   0,   0,   0,   0,   0, 
				  0,   0,   0,   0,   0,   0,   0,   0, 
				  0,   0,   0,   0,   0,   0,   0,   0, 
				  0,   0,   0,   0,   0,   0,   0,   0, 
				  0,   0,   0,   0,   0,   0,   0,   0, 
				  0,   0,   0,   0,   0,   0,   0,   0, 
				  0,   0,   0,   0,   0,   0,   0,   0, 
				  0,   0,   0,   0,   0,   0,   0,   0, 
				  0,   0,   0,   0,   0,   0,   0,   0, 
				  0,   0,   0,   0,   0,   0,   0,   0, 
				  0,   0,   0,   0,   0,   0,   0,   0, 
				  0,   0,   0,   0,   0,   0,   0,   0, 
				  0,   0,   0,   0,   0,   0,   0,   0, 
				  0,   0,   0,   0,   0,   0,   0,   0, 
				  0,   0,   0,   0,   0,   0,   0,   0, 
				  0,   0,   0,   0,   0,   0,   0,   0, 
				  0,   0,   0,   0,   0,   0,   0,   0, 
				  0,   0,   0,   0,   0,   0,   0,   0, 
				  0,   0,   0,   0,   0,   0,   0,   0, 
				  0,   0,   0,   0,   0,   0,   0,   0, 
				  0,   0,   0,   0,   0,   0,   0,   0, 
				  0,   0,   0,   0,   0,   0,   0,   0, 
			};

			if ((YYLIMIT - YYCURSOR) < 2) YYFILL(2);
			yych = *YYCURSOR;
			if (yych <= ',') {
				if (yych <= 0x00) goto yy10;
				if (yych == '+') goto yy6;
				goto yy12;
			} else {
				if (yych <= '/') {
					if (yych <= '-') goto yy8;
					goto yy12;
				} else {
					if (yych <= '0') goto yy4;
					if (yych >= ':') goto yy12;
				}
			}
			++YYCURSOR;
			yych = *YYCURSOR;
			goto yy17;
yy3:
#line 93 "main.b.re"
			{ continue; }
#line 114 "<stdout>"
yy4:
			++YYCURSOR;
			if (yybm[0+(yych = *YYCURSOR)] & 128) {
				goto yy13;
			}
yy5:
#line 98 "main.b.re"
			{ return 1; }
#line 123 "<stdout>"
yy6:
			++YYCURSOR;
#line 95 "main.b.re"
			{ continue; }
#line 128 "<stdout>"
yy8:
			++YYCURSOR;
#line 96 "main.b.re"
			{ continue; }
#line 133 "<stdout>"
yy10:
			++YYCURSOR;
#line 97 "main.b.re"
			{ return 0; }
#line 138 "<stdout>"
yy12:
			yych = *++YYCURSOR;
			goto yy5;
yy13:
			++YYCURSOR;
			if (YYLIMIT <= YYCURSOR) YYFILL(1);
			yych = *YYCURSOR;
			if (yybm[0+yych] & 128) {
				goto yy13;
			}
#line 94 "main.b.re"
			{ continue; }
#line 151 "<stdout>"
yy16:
			++YYCURSOR;
			if (YYLIMIT <= YYCURSOR) YYFILL(1);
			yych = *YYCURSOR;
yy17:
			if (yych <= '/') goto yy3;
			if (yych <= '9') goto yy16;
			goto yy3;
		}
#line 99 "main.b.re"

	}
}

/**
 * @brief Scan for numbers in different formats
 */
int scan(char *pzStrToScan, size_t lenStrToScan)
{
	unsigned char *pzCurScanPos = (unsigned char*)pzStrToScan;
	unsigned char *pzBacktrackInfo = 0;
#define YYCTYPE         unsigned char
#define YYCURSOR        pzCurScanPos
#define YYLIMIT         (pzStrToScan+lenStrToScan)
#define YYMARKER        pzBacktrackInfo
#define YYFILL(n)
	
	for(;;)
	{

#line 182 "<stdout>"
		{
			YYCTYPE yych;
			static const unsigned char yybm[] = {
				  0,   0,   0,   0,   0,   0,   0,   0, 
				  0,   0,   0,   0,   0,   0,   0,   0, 
				  0,   0,   0,   0,   0,   0,   0,   0, 
				  0,   0,   0,   0,   0,   0,   0,   0, 
				  0,   0,   0,   0,   0,   0,   0,   0, 
				  0,   0,   0,   0,   0,   0,   0,   0, 
				128, 128, 128, 128, 128, 128, 128, 128, 
				128, 128,   0,   0,   0,   0,   0,   0, 
				  0,   0,   0,   0,   0,   0,   0,   0, 
				  0,   0,   0,   0,   0,   0,   0,   0, 
				  0,   0,   0,   0,   0,   0,   0,   0, 
				  0,   0,   0,   0,   0,   0,   0,   0, 
				  0,   0,   0,   0,   0,   0,   0,   0, 
				  0,   0,   0,   0,   0,   0,   0,   0, 
				  0,   0,   0,   0,   0,   0,   0,   0, 
				  0,   0,   0,   0,   0,   0,   0,   0, 
				  0,   0,   0,   0,   0,   0,   0,   0, 
				  0,   0,   0,   0,   0,   0,   0,   0, 
				  0,   0,   0,   0,   0,   0,   0,   0, 
				  0,   0,   0,   0,   0,   0,   0,   0, 
				  0,   0,   0,   0,   0,   0,   0,   0, 
				  0,   0,   0,   0,   0,   0,   0,   0, 
				  0,   0,   0,   0,   0,   0,   0,   0, 
				  0,   0,   0,   0,   0,   0,   0,   0, 
				  0,   0,   0,   0,   0,   0,   0,   0, 
				  0,   0,   0,   0,   0,   0,   0,   0, 
				  0,   0,   0,   0,   0,   0,   0,   0, 
				  0,   0,   0,   0,   0,   0,   0,   0, 
				  0,   0,   0,   0,   0,   0,   0,   0, 
				  0,   0,   0,   0,   0,   0,   0,   0, 
				  0,   0,   0,   0,   0,   0,   0,   0, 
				  0,   0,   0,   0,   0,   0,   0,   0, 
			};
			if ((YYLIMIT - YYCURSOR) < 2) YYFILL(2);
			yych = *YYCURSOR;
			if (yych <= ',') {
				if (yych <= 0x00) goto yy28;
				if (yych == '+') goto yy24;
				goto yy30;
			} else {
				if (yych <= '/') {
					if (yych <= '-') goto yy26;
					goto yy30;
				} else {
					if (yych <= '0') goto yy22;
					if (yych >= ':') goto yy30;
				}
			}
			++YYCURSOR;
			yych = *YYCURSOR;
			goto yy35;
yy21:
#line 120 "main.b.re"
			{ printf("Num\n"); strcat(gTestBuf, "Num "); continue; }
#line 240 "<stdout>"
yy22:
			++YYCURSOR;
			if (yybm[0+(yych = *YYCURSOR)] & 128) {
				goto yy31;
			}
yy23:
#line 125 "main.b.re"
			{ printf("ERR\n"); strcat(gTestBuf, "ERR "); return 1; }
#line 249 "<stdout>"
yy24:
			++YYCURSOR;
#line 122 "main.b.re"
			{ printf("+\n");   strcat(gTestBuf, "+ ");   continue; }
#line 254 "<stdout>"
yy26:
			++YYCURSOR;
#line 123 "main.b.re"
			{ printf("-\n");   strcat(gTestBuf, "- ");   continue; }
#line 259 "<stdout>"
yy28:
			++YYCURSOR;
#line 124 "main.b.re"
			{ printf("EOF\n");                           return 0; }
#line 264 "<stdout>"
yy30:
			yych = *++YYCURSOR;
			goto yy23;
yy31:
			++YYCURSOR;
			if (YYLIMIT <= YYCURSOR) YYFILL(1);
			yych = *YYCURSOR;
			if (yybm[0+yych] & 128) {
				goto yy31;
			}
#line 121 "main.b.re"
			{ printf("Oct\n"); strcat(gTestBuf, "Oct "); continue; }
#line 277 "<stdout>"
yy34:
			++YYCURSOR;
			if (YYLIMIT <= YYCURSOR) YYFILL(1);
			yych = *YYCURSOR;
yy35:
			if (yych <= '/') goto yy21;
			if (yych <= '9') goto yy34;
			goto yy21;
		}
#line 126 "main.b.re"

	}
}

/**
 * @brief Show high resolution elapsed time for 10,000 and 100,000 loops
 */
void DoTimingsOfStrnCmp(void)
{
   char testStr[] = "Hello, world";
   int totLoops = 10000;
   int totFoundCount = 0;
   int foundCount = 0;
   int loop;
   int rc;
   const int progressAnd = 0xFFFFF000;
   double elapsed;

   printf("\n\n%d loops with * every %d loops to confirm\n", totLoops, ((~progressAnd) + 1));

   HrtStart();
   for (loop = 0; loop < totLoops; ++loop) {
      foundCount = 0;
      rc = strncmp(testStr, "Hello", 5);
      if (rc == 0) {
         foundCount++;
         totFoundCount++;
         if ((totFoundCount & progressAnd) == totFoundCount) {
            printf("*");
         }
      }
   }
   elapsed = HrtElapsedMillis();
   printf("\nstrncmp Elapsed for %7d loops milliseconds: %7.3f\n", totLoops, elapsed);
   printf("FoundCount each loop: %d\n", foundCount);
   printf("TotalFoundCount for all loops: %d\n", totFoundCount);

   totLoops = 100000;
   HrtStart();
   for (loop = 0; loop < totLoops; ++loop) {
      foundCount = 0;
      rc = strncmp(testStr, "Hello", 5);
      if (rc == 0) {
         foundCount++;
         totFoundCount++;
         if ((totFoundCount & progressAnd) == totFoundCount) {
            printf("*");
         }
      }
   }
   elapsed = HrtElapsedMillis();
   printf("\nstrncmp Elapsed for %7d loops milliseconds: %7.3f\n", totLoops, elapsed);
   printf("FoundCount each loop: %d\n", foundCount);
   printf("TotalFoundCount for all loops: %d\n", totFoundCount);
}

/**
 * @brief Show high resolution elapsed time for 10,000 and 100,000 loops
 */
void DoTimingsOfRe2c(void)
{
   char* testStrings[] = { "123", "1234", "+123", "01234", "-04321", "abc", "123abc" };
   const int testCount = sizeof(testStrings) / sizeof(testStrings[0]);
   int i;
   int totLoops = 10000 / testCount;  // Doing more than one per loop
   int totFoundCount = 0;
   int foundCount = 0;
   int loop;
   int rc;
   const int progressAnd = 0xFFFFF000;
   double elapsed;

   printf("\n\n%d loops with * every %d loops to confirm\n", totLoops, ((~progressAnd) + 1));

   HrtStart();
   for (loop = 0; loop < totLoops; ++loop) {
      foundCount = 0;
      strcpy(gTestBuf, "");   
      for (i = 0; i < testCount; ++i) {
         char* pzCurStr = testStrings[i];
         size_t len = strlen(pzCurStr);  // Calc of strlen slows things down ... std::string?
         rc = ScanFullSpeed(pzCurStr, len);
         if (rc == 0) {
            foundCount++;
            totFoundCount++;
            if ((totFoundCount & progressAnd) == totFoundCount) {
               printf("*");
            }
         }
      }
   }
   elapsed = HrtElapsedMillis();
   printf("\nRe2c Elapsed for %7d loops milliseconds: %7.3f\n", totLoops, elapsed);
   printf("FoundCount each loop: %d\n", foundCount);
   printf("TotalFoundCount for all loops: %d\n", totFoundCount);

   totLoops = 100000 / testCount;
   printf("\n\n%d loops with * every %d loops to confirm\n", totLoops, ((~progressAnd) + 1));

   HrtStart();
   for (loop = 0; loop < totLoops; ++loop) {
      foundCount = 0;
      strcpy(gTestBuf, "");   
      for (i = 0; i < testCount; ++i) {
         char* pzCurStr = testStrings[i];
         size_t len = strlen(pzCurStr);  // Calc of strlen slows things down ... std::string?
         rc = ScanFullSpeed(pzCurStr, len);
         if (rc == 0) {
            foundCount++;
            totFoundCount++;
            if ((totFoundCount & progressAnd) == totFoundCount) {
               printf("*");
            }
         }
      }
   }
   elapsed = HrtElapsedMillis();
   printf("\nRe2c Elapsed for %7d loops milliseconds: %7.3f\n", totLoops, elapsed);
   printf("FoundCount each loop: %d\n", foundCount);
   printf("TotalFoundCount for all loops: %d\n", totFoundCount);
}

/**
 * @brief Entry point for console app
 */
int main(int argc, char **argv)
{
   char  testStr_A[] = "123";
   char* testStr_B   = "456";
   char* testStrings[] = { "123", "1234", "+123", "01234", "-04321", "abc", "123abc" };
   const int testCount = sizeof(testStrings) / sizeof(testStrings[0]);
   int i;
   
   int rc = scan(testStr_A, 3);
   printf("rc: %d\n", rc);

   rc = scan(testStr_B, 3);
   printf("rc: %d\n", rc);

   rc = scan("789", 3);
   printf("rc: %d\n", rc);

   strcpy(gTestBuf, "");   
   for (i = 0; i < testCount; ++i) {
      char* pzCurStr = testStrings[i];
      size_t len = strlen(pzCurStr);
      scan(pzCurStr, len);
   }
   printf("%s\n", gTestBuf);
   rc = strcmp(gTestBuf, "Num Num + Num Oct - Oct ERR Num ERR ");
   if (rc == 0) {
      printf("Success\n");
   }
   else {
      printf("Failure\n");
   }
   assert(0 == rc); // Doesn't work with Release build
   
   InitHiResTimerAndVerifyWorking();

   DoTimingsOfStrnCmp();
   
   DoTimingsOfRe2c();
   
   return 0;
}
