#include "ota.h"

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