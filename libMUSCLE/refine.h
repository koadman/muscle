#ifndef Refine_h
#define Refine_h


struct Range
	{
	unsigned m_uBestColLeft;
	unsigned m_uBestColRight;
	};

void ListVertSavings(unsigned uColCount, unsigned uAnchorColCount,
  const Range *Ranges, unsigned uRangeCount);

void ColsToRanges(const unsigned BestCols[], unsigned uBestColCount,
  unsigned uColCount, Range Ranges[]);


#endif // Refine_h
