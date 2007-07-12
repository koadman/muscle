#include "muscle.h"
#include "msa.h"
#include "params.h"
#include "textfile.h"

static void DoOutput(MSA &msa)
	{
	bool AnyOutput = false;

// Flag options, at most one used (because only one -out filename)
	TextFile fileOut(g_pstrOutFileName.get(), true);
	if (g_bFASTA.get())
		{
		msa.ToFASTAFile(fileOut);
		AnyOutput = true;
		}
	else if (g_bMSF.get())
		{
		msa.ToMSFFile(fileOut);
		AnyOutput = true;
		}
	else if (g_bAln.get())
		{
		msa.ToAlnFile(fileOut);
		AnyOutput = true;
		}
	else if (g_bHTML.get())
		{
		msa.ToHTMLFile(fileOut);
		AnyOutput = true;
		}
	else if (g_bPHYI.get())
		{
		msa.ToPhyInterleavedFile(fileOut);
		AnyOutput = true;
		}
	else if (g_bPHYS.get())
		{
		msa.ToPhySequentialFile(fileOut);
		AnyOutput = true;
		}

// If -out option was given but no flags, output as FASTA
	if (!AnyOutput && strcmp(g_pstrOutFileName.get(), "-") != 0)
		msa.ToFASTAFile(fileOut);
	
	fileOut.Close();

// Value options
	if (g_pstrFASTAOutFileName.get())
		{
		TextFile File(g_pstrFASTAOutFileName.get(), true);
		msa.ToFASTAFile(File);
		}

	if (g_pstrMSFOutFileName.get())
		{
		TextFile File(g_pstrMSFOutFileName.get(), true);
		msa.ToMSFFile(File);
		}

	if (g_pstrClwOutFileName.get())
		{
		TextFile File(g_pstrClwOutFileName.get(), true);
		msa.ToAlnFile(File);
		}

	if (g_pstrClwStrictOutFileName.get())
		{
		g_bClwStrict.get() = true;
		TextFile File(g_pstrClwStrictOutFileName.get(), true);
		msa.ToAlnFile(File);
		}

	if (g_pstrHTMLOutFileName.get())
		{
		TextFile File(g_pstrHTMLOutFileName.get(), true);
		msa.ToHTMLFile(File);
		}

	if (g_pstrPHYIOutFileName.get())
		{
		TextFile File(g_pstrPHYIOutFileName.get(), true);
		msa.ToPhySequentialFile(File);
		}

	if (g_pstrPHYSOutFileName.get())
		{
		TextFile File(g_pstrPHYSOutFileName.get(), true);
		msa.ToPhySequentialFile(File);
		}

	if (0 != g_pstrScoreFileName.get())
		WriteScoreFile(msa);
	}

void MuscleOutput(MSA &msa)
	{
	if( strcmp(g_pstrOutFileName.get(),"-")==0 )
		g_bFASTA.get() = true;
	MHackEnd(msa);
	if (g_bStable.get())
		{
		MSA msaStable;
		Stabilize(msa, msaStable);
		msa.Clear();	// save memory
		DoOutput(msaStable);
		}
	else
		DoOutput(msa);
	}
