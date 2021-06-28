// SDM_ACT2.C
// Use this light version (only SDM enemies) if KEEP_SODFULL is not defined

#include "VERSION.H"


#ifdef KEEP_SODFULL
	#include "WL_ACT2.C"
#else

#include "WL_DEF.H"
#pragma hdrstop


/*
=============================================================================

						 GLOBAL VARIABLES

=============================================================================
*/


statetype s_deathdie1;
statetype s_willdie1;
statetype s_uberdie0;
statetype s_transdie0;
statetype s_angeldie1;
statetype s_spectredie1;
statetype s_dogdie1;
statetype s_mutdie1;
statetype s_ofcdie1;
statetype s_mutpain1;
statetype s_mutpain;
statetype s_ofcpain1;
statetype s_ofcpain;
statetype s_deathchase1;
statetype s_willchase1;
statetype s_uberchase1;
statetype s_transchase1;
statetype s_angelchase1;
statetype s_spectrechase1;
statetype s_dogchase1;
statetype s_mutchase1;
statetype s_ofcchase1;

#if 0
void SpawnTrans (int tilex, int tiley)   { tiley = tilex; tilex = tiley; };
void SpawnUber (int tilex, int tiley)    { tiley = tilex; tilex = tiley; };
void SpawnWill (int tilex, int tiley)    { tiley = tilex; tilex = tiley; };
void SpawnDeath (int tilex, int tiley)   { tiley = tilex; tilex = tiley; };
void SpawnAngel (int tilex, int tiley)   { tiley = tilex; tilex = tiley; };
void SpawnSpectre (int tilex, int tiley) { tiley = tilex; tilex = tiley; };
#endif


/*
=============================================================================

						 LOCAL VARIABLES

=============================================================================
*/


int	starthitpoints[3] =
	 {25,	// guards
	  0,
	  100	// SS
	  };

void	T_Path (objtype *ob);
void	T_Shoot (objtype *ob);
void	T_Chase (objtype *ob);
void	T_Stand (objtype *ob);

void A_DeathScream (objtype *ob);



/*
=============================================================================

							GUARD

=============================================================================
*/

//
// guards
//

extern	statetype s_grdstand;

extern	statetype s_grdpath1;
extern	statetype s_grdpath1s;
extern	statetype s_grdpath2;
extern	statetype s_grdpath3;
extern	statetype s_grdpath3s;
extern	statetype s_grdpath4;

extern	statetype s_grdpain;
// *** PRE-V1.4 APOGEE RESTORATION ***
#ifndef GAMEVER_RESTORATION_ANY_APO_PRE14
extern	statetype s_grdpain1;
#endif

extern	statetype s_grdgiveup;

extern	statetype s_grdshoot1;
extern	statetype s_grdshoot2;
extern	statetype s_grdshoot3;
extern	statetype s_grdshoot4;

extern	statetype s_grdchase1;
extern	statetype s_grdchase1s;
extern	statetype s_grdchase2;
extern	statetype s_grdchase3;
extern	statetype s_grdchase3s;
extern	statetype s_grdchase4;

extern	statetype s_grddie1;
extern	statetype s_grddie1d;
extern	statetype s_grddie2;
extern	statetype s_grddie3;
extern	statetype s_grddie4;

statetype s_grdstand	= {true,SPR_GRD_S_1,0,T_Stand,NULL,&s_grdstand};

statetype s_grdpath1 	= {true,SPR_GRD_W1_1,20,T_Path,NULL,&s_grdpath1s};
statetype s_grdpath1s 	= {true,SPR_GRD_W1_1,5,NULL,NULL,&s_grdpath2};
statetype s_grdpath2 	= {true,SPR_GRD_W2_1,15,T_Path,NULL,&s_grdpath3};
statetype s_grdpath3 	= {true,SPR_GRD_W3_1,20,T_Path,NULL,&s_grdpath3s};
statetype s_grdpath3s 	= {true,SPR_GRD_W3_1,5,NULL,NULL,&s_grdpath4};
statetype s_grdpath4 	= {true,SPR_GRD_W4_1,15,T_Path,NULL,&s_grdpath1};

statetype s_grdpain 	= {2,SPR_GRD_PAIN_1,10,NULL,NULL,&s_grdchase1};
// *** PRE-V1.4 APOGEE RESTORATION ***
#ifndef GAMEVER_RESTORATION_ANY_APO_PRE14
statetype s_grdpain1 	= {2,SPR_GRD_PAIN_2,10,NULL,NULL,&s_grdchase1};
#endif

statetype s_grdshoot1 	= {false,SPR_GRD_SHOOT1,20,NULL,NULL,&s_grdshoot2};
statetype s_grdshoot2 	= {false,SPR_GRD_SHOOT2,20,NULL,T_Shoot,&s_grdshoot3};
statetype s_grdshoot3 	= {false,SPR_GRD_SHOOT3,20,NULL,NULL,&s_grdchase1};

statetype s_grdchase1 	= {true,SPR_GRD_W1_1,10,T_Chase,NULL,&s_grdchase1s};
statetype s_grdchase1s 	= {true,SPR_GRD_W1_1,3,NULL,NULL,&s_grdchase2};
statetype s_grdchase2 	= {true,SPR_GRD_W2_1,8,T_Chase,NULL,&s_grdchase3};
statetype s_grdchase3 	= {true,SPR_GRD_W3_1,10,T_Chase,NULL,&s_grdchase3s};
statetype s_grdchase3s 	= {true,SPR_GRD_W3_1,3,NULL,NULL,&s_grdchase4};
statetype s_grdchase4 	= {true,SPR_GRD_W4_1,8,T_Chase,NULL,&s_grdchase1};

statetype s_grddie1		= {false,SPR_GRD_DIE_1,15,NULL,A_DeathScream,&s_grddie2};
statetype s_grddie2		= {false,SPR_GRD_DIE_2,15,NULL,NULL,&s_grddie3};
statetype s_grddie3		= {false,SPR_GRD_DIE_3,15,NULL,NULL,&s_grddie4};
statetype s_grddie4		= {false,SPR_GRD_DEAD,0,NULL,NULL,&s_grddie4};


//
// SS
//

extern	statetype s_ssstand;

extern	statetype s_sspath1;
extern	statetype s_sspath1s;
extern	statetype s_sspath2;
extern	statetype s_sspath3;
extern	statetype s_sspath3s;
extern	statetype s_sspath4;

extern	statetype s_sspain;
// *** PRE-V1.4 APOGEE RESTORATION ***
#ifndef GAMEVER_RESTORATION_ANY_APO_PRE14
extern	statetype s_sspain1;
#endif

extern	statetype s_ssshoot1;
extern	statetype s_ssshoot2;
extern	statetype s_ssshoot3;
extern	statetype s_ssshoot4;
extern	statetype s_ssshoot5;
extern	statetype s_ssshoot6;
extern	statetype s_ssshoot7;
extern	statetype s_ssshoot8;
extern	statetype s_ssshoot9;

extern	statetype s_sschase1;
extern	statetype s_sschase1s;
extern	statetype s_sschase2;
extern	statetype s_sschase3;
extern	statetype s_sschase3s;
extern	statetype s_sschase4;

extern	statetype s_ssdie1;
extern	statetype s_ssdie2;
extern	statetype s_ssdie3;
extern	statetype s_ssdie4;

statetype s_ssstand	= {true,SPR_SS_S_1,0,T_Stand,NULL,&s_ssstand};

statetype s_sspath1 	= {true,SPR_SS_W1_1,20,T_Path,NULL,&s_sspath1s};
statetype s_sspath1s 	= {true,SPR_SS_W1_1,5,NULL,NULL,&s_sspath2};
statetype s_sspath2 	= {true,SPR_SS_W2_1,15,T_Path,NULL,&s_sspath3};
statetype s_sspath3 	= {true,SPR_SS_W3_1,20,T_Path,NULL,&s_sspath3s};
statetype s_sspath3s 	= {true,SPR_SS_W3_1,5,NULL,NULL,&s_sspath4};
statetype s_sspath4 	= {true,SPR_SS_W4_1,15,T_Path,NULL,&s_sspath1};

statetype s_sspain 		= {2,SPR_SS_PAIN_1,10,NULL,NULL,&s_sschase1};
// *** PRE-V1.4 APOGEE RESTORATION ***
#ifndef GAMEVER_RESTORATION_ANY_APO_PRE14
statetype s_sspain1 	= {2,SPR_SS_PAIN_2,10,NULL,NULL,&s_sschase1};
#endif

statetype s_ssshoot1 	= {false,SPR_SS_SHOOT1,20,NULL,NULL,&s_ssshoot2};
statetype s_ssshoot2 	= {false,SPR_SS_SHOOT2,20,NULL,T_Shoot,&s_ssshoot3};
statetype s_ssshoot3 	= {false,SPR_SS_SHOOT3,10,NULL,NULL,&s_ssshoot4};
statetype s_ssshoot4 	= {false,SPR_SS_SHOOT2,10,NULL,T_Shoot,&s_ssshoot5};
statetype s_ssshoot5 	= {false,SPR_SS_SHOOT3,10,NULL,NULL,&s_ssshoot6};
statetype s_ssshoot6 	= {false,SPR_SS_SHOOT2,10,NULL,T_Shoot,&s_ssshoot7};
statetype s_ssshoot7  	= {false,SPR_SS_SHOOT3,10,NULL,NULL,&s_ssshoot8};
statetype s_ssshoot8  	= {false,SPR_SS_SHOOT2,10,NULL,T_Shoot,&s_ssshoot9};
statetype s_ssshoot9  	= {false,SPR_SS_SHOOT3,10,NULL,NULL,&s_sschase1};

statetype s_sschase1 	= {true,SPR_SS_W1_1,10,T_Chase,NULL,&s_sschase1s};
statetype s_sschase1s 	= {true,SPR_SS_W1_1,3,NULL,NULL,&s_sschase2};
statetype s_sschase2 	= {true,SPR_SS_W2_1,8,T_Chase,NULL,&s_sschase3};
statetype s_sschase3 	= {true,SPR_SS_W3_1,10,T_Chase,NULL,&s_sschase3s};
statetype s_sschase3s 	= {true,SPR_SS_W3_1,3,NULL,NULL,&s_sschase4};
statetype s_sschase4 	= {true,SPR_SS_W4_1,8,T_Chase,NULL,&s_sschase1};

statetype s_ssdie1		= {false,SPR_SS_DIE_1,15,NULL,A_DeathScream,&s_ssdie2};
statetype s_ssdie2		= {false,SPR_SS_DIE_2,15,NULL,NULL,&s_ssdie3};
statetype s_ssdie3		= {false,SPR_SS_DIE_3,15,NULL,NULL,&s_ssdie4};
statetype s_ssdie4		= {false,SPR_SS_DEAD,0,NULL,NULL,&s_ssdie4};



/*
===============
=
= SpawnStand
=
===============
*/

void SpawnStand (enemy_t which, int tilex, int tiley, int dir)
{
	unsigned	far *map,tile;

	switch (which)
	{
	case en_guard:
		SpawnNewObj (tilex,tiley,&s_grdstand);
		new->speed = SPDPATROL;
		if (!loadedgame)
		  gamestate.killtotal++;
		break;

	case en_ss:
		SpawnNewObj (tilex,tiley,&s_ssstand);
		new->speed = SPDPATROL;
		if (!loadedgame)
		  gamestate.killtotal++;
		break;
	}


	map = mapsegs[0]+farmapylookup[tiley]+tilex;
	if (*map == AMBUSHTILE)
	{
		tilemap[tilex][tiley] = 0;

		if (*(map+1) >= AREATILE)
			tile = *(map+1);
		if (*(map-mapwidth) >= AREATILE)
			tile = *(map-mapwidth);
		if (*(map+mapwidth) >= AREATILE)
			tile = *(map+mapwidth);
		if ( *(map-1) >= AREATILE)
			tile = *(map-1);

		*map = tile;
		new->areanumber = tile-AREATILE;

		new->flags |= FL_AMBUSH;
	}

	new->obclass = guardobj+which;
	new->hitpoints = starthitpoints[which];
	new->dir = dir*2;
	new->flags |= FL_SHOOTABLE;
}



/*
===============
=
= SpawnDeadGuard
=
===============
*/

void SpawnDeadGuard (int tilex, int tiley)
{
	SpawnNewObj (tilex,tiley,&s_grddie4);
	new->obclass = inertobj;
}


/*
===============
=
= SpawnPatrol
=
===============
*/

void SpawnPatrol (enemy_t which, int tilex, int tiley, int dir)
{
	switch (which)
	{
	case en_guard:
		SpawnNewObj (tilex,tiley,&s_grdpath1);
		new->speed = SPDPATROL;
		if (!loadedgame)
		  gamestate.killtotal++;
		break;

	case en_ss:
		SpawnNewObj (tilex,tiley,&s_sspath1);
		new->speed = SPDPATROL;
		if (!loadedgame)
		  gamestate.killtotal++;
		break;

	}

	new->obclass = guardobj+which;
	new->dir = dir*2;
	new->hitpoints = starthitpoints[which];
	new->distance = tileglobal;
	new->flags |= FL_SHOOTABLE;
	new->active = true;

	actorat[new->tilex][new->tiley] = NULL;		// don't use original spot

	switch (dir)
	{
	case 0:
		new->tilex++;
		break;
	case 1:
		new->tiley--;
		break;
	case 2:
		new->tilex--;
		break;
	case 3:
		new->tiley++;
		break;
	}

	actorat[new->tilex][new->tiley] = new;
}



/*
==================
=
= A_DeathScream
=
==================
*/

void A_DeathScream (objtype *ob)
{
	switch (ob->obclass)
	{
	case guardobj:
		{
		 int sounds[9]={ DEATHSCREAM1SND,
				 DEATHSCREAM2SND,
				 DEATHSCREAM3SND,
				 DEATHSCREAM4SND,
				 DEATHSCREAM5SND,
				 DEATHSCREAM7SND,
				 DEATHSCREAM8SND,
				 DEATHSCREAM9SND
				 };

		 #ifndef UPLOAD
		 PlaySoundLocActor(sounds[US_RndT()%8],ob);
		 #else
		 PlaySoundLocActor(sounds[US_RndT()%2],ob);
		 #endif
		}
		break;
	case ssobj:
		PlaySoundLocActor(LEBENSND,ob);	// JAB
		break;
	}
}



/*
============================================================================

							STAND

============================================================================
*/


/*
===============
=
= T_Stand
=
===============
*/

void T_Stand (objtype *ob)
{
	SightPlayer (ob);
}


/*
============================================================================

								CHASE

============================================================================
*/

/*
=================
=
= T_Chase
=
=================
*/

void T_Chase (objtype *ob)
{
	long move;
	int	dx,dy,dist,chance;
	boolean	dodge;

	if (gamestate.victoryflag)
		return;

	dodge = false;
	if (CheckLine(ob))	// got a shot at player?
	{
		dx = abs(ob->tilex - player->tilex);
		dy = abs(ob->tiley - player->tiley);
		dist = dx>dy ? dx : dy;
		if (!dist || (dist==1 && ob->distance<0x4000) )
			chance = 300;
		else
			chance = (tics<<4)/dist;

		if ( US_RndT()<chance)
		{
		//
		// go into attack frame
		//
			switch (ob->obclass)
			{
			case guardobj:
				NewState (ob,&s_grdshoot1);
				break;
			case ssobj:
				NewState (ob,&s_ssshoot1);
				break;
			}
			return;
		}
		dodge = true;
	}

	if (ob->dir == nodir)
	{
		if (dodge)
			SelectDodgeDir (ob);
		else
			SelectChaseDir (ob);
		if (ob->dir == nodir)
			return;							// object is blocked in
	}

	move = ob->speed*tics;

	while (move)
	{
		if (ob->distance < 0)
		{
		//
		// waiting for a door to open
		//
			OpenDoor (-ob->distance-1);
			if (doorobjlist[-ob->distance-1].action != dr_open)
				return;
			ob->distance = TILEGLOBAL;	// go ahead, the door is now opoen
		}

		if (move < ob->distance)
		{
			MoveObj (ob,move);
			break;
		}

		//
		// reached goal tile, so select another one
		//

		//
		// fix position to account for round off during moving
		//
		ob->x = ((long)ob->tilex<<TILESHIFT)+TILEGLOBAL/2;
		ob->y = ((long)ob->tiley<<TILESHIFT)+TILEGLOBAL/2;

		move -= ob->distance;

		if (dodge)
			SelectDodgeDir (ob);
		else
			SelectChaseDir (ob);

		if (ob->dir == nodir)
			return;							// object is blocked in
	}

}



/*
============================================================================

								PATH

============================================================================
*/


/*
===============
=
= SelectPathDir
=
===============
*/

void SelectPathDir (objtype *ob)
{
	unsigned spot;

	spot = MAPSPOT(ob->tilex,ob->tiley,1)-ICONARROWS;

	if (spot<8)
	{
	// new direction
		ob->dir = spot;
	}

	ob->distance = TILEGLOBAL;

	if (!TryWalk (ob))
		ob->dir = nodir;
}


/*
===============
=
= T_Path
=
===============
*/

void T_Path (objtype *ob)
{
	long 	move;
	long 	deltax,deltay,size;

	if (SightPlayer (ob))
		return;

	if (ob->dir == nodir)
	{
		SelectPathDir (ob);
		if (ob->dir == nodir)
			return;					// all movement is blocked
	}


	move = ob->speed*tics;

	while (move)
	{
		if (ob->distance < 0)
		{
		//
		// waiting for a door to open
		//
			OpenDoor (-ob->distance-1);
			if (doorobjlist[-ob->distance-1].action != dr_open)
				return;
			ob->distance = TILEGLOBAL;	// go ahead, the door is now opoen
		}

		if (move < ob->distance)
		{
			MoveObj (ob,move);
			break;
		}

		if (ob->tilex>MAPSIZE || ob->tiley>MAPSIZE)
		{
			sprintf (str,"T_Path hit a wall at %u,%u, dir %u"
			,ob->tilex,ob->tiley,ob->dir);
			Quit (str);
		}



		ob->x = ((long)ob->tilex<<TILESHIFT)+TILEGLOBAL/2;
		ob->y = ((long)ob->tiley<<TILESHIFT)+TILEGLOBAL/2;
		move -= ob->distance;

		SelectPathDir (ob);

		if (ob->dir == nodir)
			return;					// all movement is blocked
	}
}


/*
=============================================================================

								FIGHT

=============================================================================
*/


/*
===============
=
= T_Shoot
=
= Try to damage the player, based on skill level and player's speed
=
===============
*/

void T_Shoot (objtype *ob)
{
	int	dx,dy,dist;
	int	hitchance,damage;

	hitchance = 128;

	if (!areabyplayer[ob->areanumber])
		return;

	if (!CheckLine (ob))			// player is behind a wall
	  return;

	dx = abs(ob->tilex - player->tilex);
	dy = abs(ob->tiley - player->tiley);
	dist = dx>dy ? dx:dy;

	if (ob->obclass == ssobj || ob->obclass == bossobj)
		dist = dist*2/3;					// ss are better shots

	if (thrustspeed >= RUNSPEED)
	{
		if (ob->flags&FL_VISABLE)
			hitchance = 160-dist*16;		// player can see to dodge
		else
			hitchance = 160-dist*8;
	}
	else
	{
		if (ob->flags&FL_VISABLE)
			hitchance = 256-dist*16;		// player can see to dodge
		else
			hitchance = 256-dist*8;
	}

// see if the shot was a hit

	if (US_RndT()<hitchance)
	{
		if (dist<2)
			damage = US_RndT()>>2;
		else if (dist<4)
			damage = US_RndT()>>3;
		else
			damage = US_RndT()>>4;

		TakeDamage (damage,ob);
	}

	switch(ob->obclass)
	{
	 case ssobj:
	   PlaySoundLocActor(SSFIRESND,ob);
	   break;
	 default:
	   PlaySoundLocActor(NAZIFIRESND,ob);
	}

}

#endif