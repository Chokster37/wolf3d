
// ***************************
// *** SOME MEMORY DEFINES ***
// ***************************

#define W3D_DEBUGPARM "goobers"

#define KEEP_WOLFWL6	// Keep stuff that Wolf WL3 doesn't need
#define KEEP_DEBUG	// Tab keys, demorecord, MLI/BAT, tedlevel (+1106)

  #define MORE_STUFF	// Toggle ON to redirect Max values below

	#ifdef MORE_STUFF
	    #if (defined KEEP_WOLFWL6) || (defined KEEP_DEBUG)
		#define MAXACTORS       261     // 44 bytes each (60)
		#define MAXSTATS        821     //  8 bytes each
	    #else
		#define MAXACTORS       281
		#define MAXSTATS        1010
	    #endif
		#define MAXVISABLE      250     //  6 bytes each
	#endif

#define MAXDOORS        127     // 10 bytes each (12)

