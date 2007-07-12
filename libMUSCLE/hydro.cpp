#include "muscle.h"
#include "profile.h"

// Apply hydrophobicity heuristic to a profile
void Hydro(ProfPos *Prof, unsigned uLength)
	{
	if (0 == g_uHydrophobicRunLength.get())
		return;

	unsigned uRunLength = 0;
	for (unsigned uColIndex = 0; uColIndex < uLength; ++uColIndex)
		{
		ProfPos &PP = Prof[uColIndex];
		bool bHydro = (PP.m_fOcc > 0.999 && IsHydrophobic(PP.m_fcCounts));
		if (bHydro)
			{
			++uRunLength;
			if (uRunLength > g_uHydrophobicRunLength.get())
				{
				PP.m_scoreGapOpen *= (SCORE) g_dHydroFactor.get();
				PP.m_scoreGapClose *= (SCORE) g_dHydroFactor.get();
				}
			else if (uRunLength == g_uHydrophobicRunLength.get())
				{
				for (unsigned n = uColIndex - g_uHydrophobicRunLength.get() - 1;
				  n <= uColIndex; ++n)
					{
					ProfPos &PP = Prof[n];
					PP.m_scoreGapOpen *= (SCORE) g_dHydroFactor.get();
					PP.m_scoreGapClose *= (SCORE) g_dHydroFactor.get();
					}
				}
			}
		else
			uRunLength = 0;
		}
	}
