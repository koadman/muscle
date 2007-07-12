// source code generated by dimer.py

static SCORE GapScoreMM(const ProfPos &PPA, const ProfPos &PPB)
	{
	return
	  g_scoreGapOpen.get()*(PPA.m_LL*PPB.m_LG + PPA.m_LG*PPB.m_LL + PPA.m_LG*PPB.m_GL + PPA.m_GL*PPB.m_LG) +
	  g_scoreGapExtend.get()*(PPA.m_LL*PPB.m_GG + PPA.m_GG*PPB.m_LL) +
	  g_scoreGapAmbig.get()*(PPA.m_GL*PPB.m_GG + PPA.m_GG*PPB.m_GL);
	}

static SCORE GapScoreMD(const ProfPos &PPA, const ProfPos &PPB)
	{
	return
	  g_scoreGapOpen.get()*(PPA.m_LL*PPB.m_LL + PPA.m_LL*PPB.m_GL + PPA.m_GL*PPB.m_LL + PPA.m_GL*PPB.m_GL) +
	  g_scoreGapExtend.get()*(PPA.m_LL*PPB.m_LG + PPA.m_LL*PPB.m_GG) +
	  g_scoreGapAmbig.get()*(PPA.m_GL*PPB.m_LG + PPA.m_GL*PPB.m_GG);
	}

static SCORE GapScoreMI(const ProfPos &PPA, const ProfPos &PPB)
	{
	return
	  g_scoreGapOpen.get()*(PPA.m_LL*PPB.m_LL + PPA.m_LL*PPB.m_GL + PPA.m_GL*PPB.m_LL + PPA.m_GL*PPB.m_GL) +
	  g_scoreGapExtend.get()*(PPA.m_LG*PPB.m_LL + PPA.m_GG*PPB.m_LL) +
	  g_scoreGapAmbig.get()*(PPA.m_LG*PPB.m_GL + PPA.m_GG*PPB.m_GL);
	}

static SCORE GapScoreDM(const ProfPos &PPA, const ProfPos &PPB)
	{
	return
	  g_scoreGapOpen.get()*(PPA.m_LG*PPB.m_LL + PPA.m_LG*PPB.m_GL) +
	  g_scoreGapExtend.get()*(PPA.m_LL*PPB.m_LG + PPA.m_LL*PPB.m_GG) +
	  g_scoreGapAmbig.get()*(PPA.m_GL*PPB.m_LG + PPA.m_GL*PPB.m_GG + PPA.m_GG*PPB.m_LL + PPA.m_GG*PPB.m_GL);
	}

static SCORE GapScoreDD(const ProfPos &PPA, const ProfPos &PPB)
	{
	return
	  g_scoreGapExtend.get()*(PPA.m_LL*PPB.m_LL + PPA.m_LL*PPB.m_LG + PPA.m_LL*PPB.m_GL + PPA.m_LL*PPB.m_GG) +
	  g_scoreGapAmbig.get()*(PPA.m_GL*PPB.m_LL + PPA.m_GL*PPB.m_LG + PPA.m_GL*PPB.m_GL + PPA.m_GL*PPB.m_GG);
	}

static SCORE GapScoreDI(const ProfPos &PPA, const ProfPos &PPB)
	{
	return
	  g_scoreGapOpen.get()*(PPA.m_LL*PPB.m_LL + PPA.m_LL*PPB.m_GL + PPA.m_GL*PPB.m_LL + PPA.m_GL*PPB.m_GL) +
	  g_scoreGapAmbig.get()*(PPA.m_LG*PPB.m_LL + PPA.m_LG*PPB.m_GL + PPA.m_GG*PPB.m_LL + PPA.m_GG*PPB.m_GL);
	}

static SCORE GapScoreIM(const ProfPos &PPA, const ProfPos &PPB)
	{
	return
	  g_scoreGapOpen.get()*(PPA.m_LL*PPB.m_LG + PPA.m_GL*PPB.m_LG) +
	  g_scoreGapExtend.get()*(PPA.m_LG*PPB.m_LL + PPA.m_GG*PPB.m_LL) +
	  g_scoreGapAmbig.get()*(PPA.m_LL*PPB.m_GG + PPA.m_LG*PPB.m_GL + PPA.m_GL*PPB.m_GG + PPA.m_GG*PPB.m_GL);
	}

static SCORE GapScoreID(const ProfPos &PPA, const ProfPos &PPB)
	{
	return
	  g_scoreGapOpen.get()*(PPA.m_LL*PPB.m_LL + PPA.m_LL*PPB.m_GL + PPA.m_GL*PPB.m_LL + PPA.m_GL*PPB.m_GL) +
	  g_scoreGapAmbig.get()*(PPA.m_LL*PPB.m_LG + PPA.m_LL*PPB.m_GG + PPA.m_GL*PPB.m_LG + PPA.m_GL*PPB.m_GG);
	}

static SCORE GapScoreII(const ProfPos &PPA, const ProfPos &PPB)
	{
	return
	  g_scoreGapExtend.get()*(PPA.m_LL*PPB.m_LL + PPA.m_LG*PPB.m_LL + PPA.m_GL*PPB.m_LL + PPA.m_GG*PPB.m_LL) +
	  g_scoreGapAmbig.get()*(PPA.m_LL*PPB.m_GL + PPA.m_LG*PPB.m_GL + PPA.m_GL*PPB.m_GL + PPA.m_GG*PPB.m_GL);
	}
