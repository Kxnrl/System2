/**
* -----------------------------------------------------
* File        ExecuteCallbackHandler.h
* Authors     David Ordnung
* License     GPLv3
* Web         http://dordnung.de
* -----------------------------------------------------
*
* Copyright (C) 2013-2020 David Ordnung
*
* This program is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
* any later version.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with this program. If not, see <http://www.gnu.org/licenses/>
*/

#ifndef _SYSTEM2_EXECUTE_CALLBACK_HANDLER_H_
#define _SYSTEM2_EXECUTE_CALLBACK_HANDLER_H_

#include "Handler.h"
#include "ExecuteCallback.h"

class ExecuteCallbackHandler : public Handler {
private:
    HandleType_t handleType;

public:
    ExecuteCallbackHandler();

    virtual void Initialize();
    virtual void Shutdown();

    Handle_t CreateHandle(ExecuteCallback* callback, IdentityToken_t* owner);
    HandleError ReadHandle(Handle_t hndl, IdentityToken_t* owner, ExecuteCallback** callback);

    virtual void OnHandleDestroy(HandleType_t type, void* object);
};

extern ExecuteCallbackHandler executeCallbackHandler;

#endif