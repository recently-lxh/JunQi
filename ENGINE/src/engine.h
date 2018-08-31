/*
 * engin.h
 *
 *  Created on: Aug 18, 2018
 *      Author: Administrator
 */

#ifndef ENGIN_H_
#define ENGIN_H_
#include "type.h"
#include <unistd.h>
#include <fcntl.h>

enum MoveEvent{
	GONGB_EVENT,
	DARK_EVENT,
	CAMP_EVENT,
	EAT_EVENT,
	BOMB_EVENT
};

#define ENGINE_DIR   1

extern u8 aEventBit[100];

typedef struct ENGINE
{
	Junqi *pJunqi;
	BoardChess *pCamp[2];
	BoardChess *pBomb[2];
	BoardChess *pEat[2];
	u16 eventId;
    u8  eventFlag;
}Engine;

typedef struct EventHandle
{
	u8 (*xEventFun)(Engine *pEngine);
	u16  eventId;
}EventHandle;


pthread_t CreatEngineThread(Junqi* pJunqi);
void SendEvent(Junqi* pJunqi, int iDir, u8 event);
Engine *OpneEnigne(Junqi *pJunqi);
void CloseEngine(Engine *pEngine);

#endif /* ENGIN_H_ */
