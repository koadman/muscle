#include "muscle.h"
#include "msa.h"
#include "textfile.h"
#include <time.h>
#include "threadstorage.h"

TLS<MSA *> ptrBestMSA;
static TLS<const char *> pstrOutputFileName;

void SetOutputFileName(const char *out)
	{
	pstrOutputFileName.get() = out;
	}

void SetCurrentAlignment(MSA &msa)
	{
	ptrBestMSA.get() = &msa;
	}

void SaveCurrentAlignment()
	{
	static TLS<bool> bCalled(false);
	if (bCalled.get())
		{
		fprintf(stderr,
		  "\nRecursive call to SaveCurrentAlignment, giving up attempt to save.\n");
		exit(EXIT_FatalError);
		}

	if (0 == ptrBestMSA.get())
		{
		fprintf(stderr, "\nAlignment not completed, cannot save.\n");
		Log("Alignment not completed, cannot save.\n");
		exit(EXIT_FatalError);
		}

	if (0 == pstrOutputFileName.get())
		{
		fprintf(stderr, "\nOutput file name not specified, cannot save.\n");
		exit(EXIT_FatalError);
		}

	fprintf(stderr, "\nSaving current alignment ...\n");

	TextFile fileOut(pstrOutputFileName.get(), true);
	ptrBestMSA.get()->ToFASTAFile(fileOut);

	fprintf(stderr, "Current alignment saved to \"%s\".\n", pstrOutputFileName);
	Log("Current alignment saved to \"%s\".\n", pstrOutputFileName);
	}

void CheckMaxTime()
	{
	if (0 == g_ulMaxSecs.get())
		return;

	time_t Now = time(0);
	time_t ElapsedSecs = Now - GetStartTime();
	if (ElapsedSecs <= (time_t) g_ulMaxSecs.get())
		return;

	Log("Max time %s exceeded, elapsed seconds = %ul\n",
	  MaxSecsToStr(), ElapsedSecs);

	SaveCurrentAlignment();
	exit(EXIT_Success);
	}
