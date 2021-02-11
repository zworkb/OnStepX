//--------------------------------------------------------------------------------------------------
// telescope control
#pragma once
#include <Arduino.h>
#include "../../Constants.h"
#include "../../Config.h"
#include "../../ConfigX.h"
#include "../HAL/HAL.h"
#include "../pinmaps/Models.h"
#include "../debug/Debug.h"

#include "Axis.h"
#include "Convert.h"
#include "../commands/ProcessCmds.h"
#include "../StepDrivers/StepDrivers.h"
#include "Transform.h"

#if (defined(AXIS1_DRIVER_MODEL) && AXIS1_DRIVER_MODEL != OFF) && (defined(AXIS2_DRIVER_MODEL) && AXIS2_DRIVER_MODEL != OFF)

typedef struct Limits {
  double horizon;
  double overhead;
  double pastMeridianE;
  double pastMeridianW;
} Limits;

enum MeridianFlip { MeridianFlipNever,  MeridianFlipAlign, MeridianFlipAlways };

class Mount {
  public:
    void init(int8_t mountType);

    // handle telescope commands
    bool command(char reply[], char command[], char parameter[], bool *supressFrame, bool *numericReply, CommandError *commandError);

    CommandError validateGoto();
    CommandError validateGotoCoords(Coordinate coords);

    CommandError syncEqu(Coordinate target);

  private:
    void updatePosition();
    Convert convert;
    Transform transform;
    Coordinate position, target;

    Limits limits = { degToRad(-10), degToRad(85), degToRad(15), degToRad(15) };
    uint8_t mountType = 0;
    bool tracking = false;
    bool atHome = true;
    bool safetyLimitsOn = false;
    bool syncToEncodersOnly = false;
    MeridianFlip meridianFlip = MeridianFlipAlways;

};

#endif