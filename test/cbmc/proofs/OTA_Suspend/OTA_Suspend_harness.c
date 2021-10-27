/*
 * AWS IoT Over-the-air Update v3.0.0
 * Copyright (C) 2020 Amazon.com, Inc. or its affiliates.  All Rights Reserved.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy of
 * this software and associated documentation files (the "Software"), to deal in
 * the Software without restriction, including without limitation the rights to
 * use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
 * the Software, and to permit persons to whom the Software is furnished to do so,
 * subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
 * FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
 * COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
 * IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 */
/**
 * @file OTA_Suspend_harness.c
 * @brief Implements the proof harness for OTA_Suspend function.
 */
/*  Ota Agent includes. */
#include "ota.h"
#include "ota_cbmc.h"

OtaAgentContext_t otaAgent = 
    {
        OtaAgentStateStopped, /* state */
        { 0 },                /* pThingName */
        { 0 },                /* fileContext */
        0,                    /* fileIndex */
        0,                    /* serverFileID */
        { 0 },                /* pActiveJobName */
        NULL,                 /* pClientTokenFromJob */
        0,                    /* timestampFromJob */
        OtaImageStateUnknown, /* imageState */
        1,                    /* numOfBlocksToReceive */
        { 0 },                /* statistics */
        0,                    /* requestMomentum */
        NULL,                 /* pOtaInterface */
        NULL,                 /* OtaAppCallback */
        1                     /* unsubscribe flag */
    };

OtaOsStatus_t Timerstop(OtaTimerId_t otaTimerId)
{
    OtaOsStatus_t status;

    __CPROVER_assume( (status >= OtaOsSuccess) && (status <= OtaOsTimerDeleteFailed));
}

void OTA_Suspend_harness()
{   
    OtaInterfaces_t otaInterface; 
    otaInterface.os.timer.stop = Timerstop;

    otaAgent.pOtaInterface = &otaInterface;

    __CPROVER_assume((otaAgent.state >= OtaAgentStateNoTransition ) && (otaAgent.state <= OtaAgentStateAll));
    OTA_Suspend();
}
