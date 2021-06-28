// *** VERSIONS RESTORATION ***
#define ARTSEXTERN
#define DEMOSEXTERN

#ifndef GAMEVER_RESTORATION_WL1_APO10
#define CARMACIZED
#endif

#if (defined GAMEVER_RESTORATION_WL1_APO10) || (defined GAMEVER_RESTORATION_WL1_APO11) || (defined GAMEVER_RESTORATION_WL1_APO12) || (defined GAMEVER_RESTORATION_WL1_APO14)
#define UPLOAD
#elif (defined GAMEVER_RESTORATION_WL6_APO11) || (defined GAMEVER_RESTORATION_WL6_APO12) || (defined GAMEVER_RESTORATION_WL6_APO14)
// Nothing to add in such a case
#elif (defined GAMEVER_RESTORATION_WL6_ID14) || (defined GAMEVER_RESTORATION_WL6_GT114) || (defined GAMEVER_RESTORATION_WL6_GT214) || (defined GAMEVER_RESTORATION_WL6_ACT14)
#define GOODTIMES
#elif defined GAMEVER_RESTORATION_SDM_FOR10
#define SPEAR
#define SPEARDEMO
#elif (defined GAMEVER_RESTORATION_SOD_FOR10) || (defined GAMEVER_RESTORATION_SOD_FOR14)
#define SPEAR
#elif defined GAMEVER_RESTORATION_SOD_ACT14
#define SPEAR
#define GOODTIMES
#else
#error "No proper game version restoration macro is defined!"
#endif

// Additional convenience macros
#if (defined GAMEVER_RESTORATION_WL1_APO10)
#define GAMEVER_RESTORATION_ANY_APO10
#endif
#if (defined GAMEVER_RESTORATION_WL1_APO11) || (defined GAMEVER_RESTORATION_WL6_APO11)
#define GAMEVER_RESTORATION_ANY_APO11
#endif
#if (defined GAMEVER_RESTORATION_WL1_APO12) || (defined GAMEVER_RESTORATION_WL6_APO12)
#define GAMEVER_RESTORATION_ANY_APO12
#endif
#if (defined GAMEVER_RESTORATION_WL1_APO14) || (defined GAMEVER_RESTORATION_WL6_APO14)
#define GAMEVER_RESTORATION_ANY_APO14
#endif

#if (defined GAMEVER_RESTORATION_ANY_APO10) || (defined GAMEVER_RESTORATION_ANY_APO11) || (defined GAMEVER_RESTORATION_ANY_APO12)
#define GAMEVER_RESTORATION_ANY_APO_PRE14
#endif

#if (defined GAMEVER_RESTORATION_SDM_FOR10) || (defined GAMEVER_RESTORATION_SOD_FOR10)
#define GAMEVER_RESTORATION_ANY_FOR10
#endif

#if (defined GAMEVER_RESTORATION_ANY_APO_PRE14) || (defined GAMEVER_RESTORATION_ANY_FOR10)
#define GAMEVER_RESTORATION_ANY_ALL_PRE14
#endif

#if (defined GAMEVER_RESTORATION_WL6_ACT14) || (defined GAMEVER_RESTORATION_SOD_ACT14)
#define GAMEVER_RESTORATION_ANY_ACT14
#endif

#if (defined GAMEVER_RESTORATION_WL6_GT214) || (defined GAMEVER_RESTORATION_WL6_ACT14) || (defined GAMEVER_RESTORATION_SOD_ACT14)
#define GAMEVER_RESTORATION_ANY_POST_GT114
#endif

// This doesn't cover the SOD case of the debug keys, just Wolf3D v1.0 vs the later releases
#ifdef GAMEVER_RESTORATION_WL1_APO10
#define GAMEVER_RESTORATION_W3D_DEBUGPARM "next"
#define GAMEVER_RESTORATION_CONDFARPTR
#define GAMEVER_RESTORATION_CONDFARSTRCPY strcpy
#else
#define GAMEVER_RESTORATION_W3D_DEBUGPARM "goobers"
#define GAMEVER_RESTORATION_CONDFARPTR far
#define GAMEVER_RESTORATION_CONDFARSTRCPY _fstrcpy
#endif

//#define MYPROFILE
//#define DEBCHECK


// **************************************
// *** SOME BUGFIX AND MEMORY DEFINES ***
// **************************************


#define WL6APO12	// Include C0.ASM, ID_VL_A.ASM
#define WL6MAX12	// Savegames will use new segment:offset

#define KEEP_WOLFWL6	// Keep stuff that Wolf WL3 doesn't need

#ifndef SPEARDEMO
#define KEEP_SODFULL	// Keep stuff that SOD Demo doesn't need
#endif


#if defined(WL6APO12) || defined(WL6MAX12)

  #define BUGFIX_01	// Pushwall always move 2 tiles fix
  #define BUGFIX_02	// v1.1 - PC13 shows red on right edge fix
  #define BUGFIX_03	// v1.1 - Mutants set to Patrol actually Patrol fix
  #define BUGFIX_04	// Died: ClearMemory and parameter to ignore mem Fix
  #define BUGFIX_05	// A_Hitler_Morph: Hitler stuck beside wall fix
  #define BUGFIX_06	// Remove "Gray flickering line during damage flash"
  #define BUGFIX_07	// DrawPlayBorderSides: Don't flash 2 colors fix
  #define BUGFIX_08	// v1.1 - Boss "Walk: Bad Dir" in tight corners fix
  #define BUGFIX_09	// v1.1 - Moving pushwall gets stuck when saving fix


#endif


#ifndef WL6MAX12

  #define KEEP_UNUSED	// Toggle OFF to raise Near Memory (2757 -> 6439)
  #define KEEP_STRUCT	// Toggle OFF to raise even more   (6439 -> 8083)
  #define KEEP_DUBMIX	// Cut out duplicate mixtable data         (+736)
  #define KEEP_STRING	// Calculate ParTime string from the float (+416)
  #define KEEP_NOTICE	// The red "This is NOT shareware" screens  (+96)
  #define KEEP_PTABLE	// Replace Pc Speaker tables with asm code (+766)
			// ^ Also comment PTABLE = 0 in ID_SD.ASM

#else

  #define BUGFIX_51	// v1.1 - Can "save the demo" after dying last man
  #define BUGFIX_52	// Walls change to Gray Stone player->arenumber fix
  #define BUGFIX_53	// "Door Side shows/vanishes where it shouldn't" fix
  #define BUGFIX_54	// v1.1 - BJ points to Dogs and Ghosts when killed
  #define BUGFIX_55	// Invisible dog in doorways + backwards pickup fix
  #define BUGFIX_56	// v1.1 - Died: Clear 0s if score was over 1 million
  #define BUGFIX_57	// VgaClearScreen/WallRefresh: Screen fixes (Ripper)
  #define BUGFIX_58	// See the quit messages that happen before preload
  #define BUGFIX_59	// FakeHitler shoots faster at high fps fix (WSJ)
  #define BUGFIX_60	// Two dead spots and jumping Hitler fix (Aryan)
  #define BUGFIX_61	// Invisible door fix (Aryan) and ambush tile fixes
  #define BUGFIX_62	// Player can collect bonuses during death spin fix
  #define BUGFIX_63	// Player can walk into enemies door/space fixes
  #define BUGFIX_64	// Diagonal backwards enemies were always alerted
  #define BUGFIX_65	// Make corner-stabbing range similar for enemies


  #ifdef KEEP_WOLFWL6
    #define KEEP_DEBUG	// Tab keys, demorecord, MLI/BAT, tedlevel (+1106)
  #endif

  #define MORE_STUFF	// Toggle ON to redirect Max values below
  #define MORE_DOORS	// Toggle ON to enable 64+ doors (up to 127)
			// ^ Also comment MORE_DOORS = 1 in WL_DR_A.ASM


	#ifdef MORE_STUFF
	    #ifdef KEEP_WOLFWL6
		#define MAXACTORS       261     // 44 bytes each (60)
		#define MAXSTATS        821     //  8 bytes each
	    #else
		#define MAXACTORS       281
		#define MAXSTATS        1010
	    #endif
		#define MAXVISABLE      250     //  6 bytes each
	#endif

	#ifdef MORE_DOORS
		#define MAXDOORS        127     // 10 bytes each (12)
	#endif


	//    Compatible:   -900 for 150 actors, 400 stats, 200 visible
	//  +Keep_Unused:  -6360 for 200 act, 700 st, 200 vis, 100 doors

#endif
