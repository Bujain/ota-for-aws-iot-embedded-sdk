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
 * @file otaTimerCallback_harness.c
 * @brief Implements the proof harness for otaTimerCallback function.
 */
/*  Ota Agent includes for OTA library. */
#include "ota.h"
#include "ota.c"

void __CPROVER_file_local_ota_c_otaTimerCallback(OtaTimerId_t otaTimerId);

/* Stub to simulate the behavior of Malloc in FreeRTOS. */
bool OTA_SignalEvent( const OtaEventMsg_t* const pEventMsg )
{
    bool status;
    return status;
}

OtaPalStatus_t reset ( OtaFileContext_t fileCtx){
    OtaPalStatus_t status;
    return status;
}

void otaTimerCallback_harness()
{
    OtaTimerId_t otaTimerId;
    OtaInterfaces_t otaInterface; 
    OtaAppBuffer_t otaBuffer;
    uint8_t* pThingName;
    OtaAppCallback_t otaAppCallback;

    otaInterface.pal.reset = reset;

    OTA_Init(&otaBuffer,&otaInterface,pThingName,otaAppCallback);
    
    __CPROVER_assume(otaTimerId == OtaRequestTimer || otaTimerId == OtaSelfTestTimer);
    __CPROVER_file_local_ota_c_otaTimerCallback( otaTimerId );
}
