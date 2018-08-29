#include "stdafx.h"
#include "status.h"

int currentStatus = TitleScreenState;
void setStatus(int status)
{
	currentStatus = status;
}

int getStatus()
{
	return currentStatus;
}
