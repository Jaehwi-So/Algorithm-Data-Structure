#pragma once

//====================
typedef struct set
{
	int data[1024];
	int length;
}SET;
//====================

SET* Create(void);
int IsMember(SET* set, int element);
int Size(SET* set);
void Add(SET* set, int element);
void Remove(SET* set, int element);
void Print(SET* set);
//====================