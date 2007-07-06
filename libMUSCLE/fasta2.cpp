#include "muscle.h"
#include <stdio.h>
#include <errno.h>

const int BUFFER_BYTES = 16*1024;
const int CR = '\r';
const int NL = '\n';

#define ADD(c)															\
		{																\
		if (Pos >= BufferLength)										\
			{															\
			const int NewBufferLength = BufferLength + BUFFER_BYTES;	\
			char *NewBuffer	= new char[NewBufferLength];				\
			memcpy(NewBuffer, Buffer, BufferLength);					\
			delete[] Buffer;											\
			Buffer = NewBuffer;											\
			BufferLength = NewBufferLength;								\
			}															\
		Buffer[Pos++] = c;												\
		}

// Get next sequence from file.
char *GetFastaSeq(FILE *f, unsigned *ptrSeqLength, char **ptrLabel, bool DeleteGaps)
	{
	unsigned BufferLength = 0;
	unsigned Pos = 0;
	char *Buffer = 0;

	int c = fgetc(f);
	if (EOF == c)
		return 0;
	// = on a line by itself indicates the end of a Multi-FastA entry in an eXtended Multi-FastA file
	if ('=' == c)
	{
		int c = fgetc(f);
		if (NL == c)
			return 0;
		if (CR == c)
		{
			c = fgetc(f);
			if (NL == c)
				return 0;
		}
		Quit("Invalid file format, '=' may only be used on a line by itself to indicate the end of a MFA entry in an XMFA");
	}

	if ('>' != c)
		Quit("Invalid file format, expected '>' to start FASTA label");

	for (;;)
		{
		int c = fgetc(f);
		if (EOF == c)
			Quit("End-of-file or input error in FASTA label");

	// Ignore CR (discard, do not include in label)
		if (CR == c)
			continue;

	// NL terminates label
		if (NL == c)
			break;

	// All other characters added to label
		ADD(c)
		}

// Nul-terminate label
	ADD(0)
	*ptrLabel = Buffer;

	BufferLength = 0;
	Pos = 0;
	Buffer = 0;
	int PreviousChar = NL;
	for (;;)
		{
		int c = fgetc(f);
		if( '=' == c && NL == PreviousChar )
		{
			ungetc(c, f);
			break;	// use = on a line by itself to signify the end of a multi-fasta entry
		}
		if (EOF == c)
			{
			if (feof(f))
				break;
			else if (ferror(f))
				Quit("Error reading FASTA file, ferror=TRUE feof=FALSE errno=%d %s",
				  errno, strerror(errno));
			else
				Quit("Error reading FASTA file, fgetc=EOF feof=FALSE ferror=FALSE errno=%d %s",
				  errno, strerror(errno));
			}

		if ('>' == c)
			{
			if (NL == PreviousChar)
				{
				ungetc(c, f);
				break;
				}
			else
				Quit("Unexpected '>' in FASTA sequence data");
			}
		else if (isspace(c))
			;
		else if (IsGapChar(c))
			{
			if (!DeleteGaps)
				ADD(c)
			}
		else if (isalpha(c))
			{
			c = toupper(c);
			ADD(c)
			}
		else if (isprint(c))
			{
			Warning("Invalid character '%c' in FASTA sequence data, ignored", c);
			continue;
			}
		else
			{
			Warning("Invalid byte hex %02x in FASTA sequence data, ignored", (unsigned char) c);
			continue;
			}
		PreviousChar = c;
		}

	if (0 == Pos)
		return GetFastaSeq(f, ptrSeqLength, ptrLabel, DeleteGaps);

	*ptrSeqLength = Pos;
	return Buffer;
	}