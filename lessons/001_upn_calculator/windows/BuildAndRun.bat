@echo OFF
goto Start
rem BuildAndRun.bat  06-Apr-15  lda
rem Assumes re2j.exe findable with PATH or . or .. or ..\.. or $(RE2C_HOME)
rem Assumes cl.exe findable with PATH or VcToolKit2003 installed

:Start
if exist %RE2C_HOME%\re2j.exe goto ProceedWithGenerate
if exist .\re2j.exe set RE2C_HOME=.
if exist ..\re2j.exe set RE2C_HOME=..
if exist ..\..\re2j.exe set RE2C_HOME=..\..
if exist ..\..\..\re2j.exe set RE2C_HOME=..\..\..
if exist ..\..\..\Release\re2j.exe set RE2C_HOME=..\..\..\Release
if exist ..\..\..\Release-2005\re2j.exe set RE2C_HOME=..\..\..\Release-2005
if not exist %RE2C_HOME%\re2j.exe goto ReportSetupError

:ProceedWithGenerate
set BASE_FILE_NAME=main
%RE2C_HOME%\re2j -b -o%BASE_FILE_NAME%.c %BASE_FILE_NAME%.re
rem echo ErrorLevel is set to %ERRORLEVEL% after re2j
IF ERRORLEVEL 1 goto ReportRe2cError

rem (to test) set path=
cl 1>nul 2>nul
IF ERRORLEVEL 1 goto AttemptToSetupCompiler
goto ProceedWithCompile

:AttemptToSetupCompiler
echo ErrorLevel is set to %ERRORLEVEL% after blank cl command line
call %VCToolkitInstallDir%\vcvars32.bat 1>nul 2>nul
cl 1>nul 2>nul
IF ERRORLEVEL 1 goto ReportClError

:ProceedWithCompile
cl -O2 /DNDEBUG /D_CONSOLE /DWIN32 %BASE_FILE_NAME%.c
rem echo ErrorLevel is set to %ERRORLEVEL% after cl
IF ERRORLEVEL 1 goto ReportClError
%BASE_FILE_NAME%
goto AllDone

:ReportSetupError
echo re2j.exe not found in ., .., ..\.., ..\..\.., ..\..\..\Release 
echo or ..\..\..\Release-2005 Environment variable RE2C_HOME invalid or not set? 

:ReportClError
:ReportRe2cError
:AllDone
pause
