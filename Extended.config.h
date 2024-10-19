/* ---------------------------------------------------------------------------------------------------------------------------------
 * Extended configuration for OnStepX INFREQUENTLY USED options
 *
 *          For more information on setting OnStep up see http://www.stellarjourney.com/index.php?r=site/equipment_onstep 
 *                      and join the OnStep Groups.io at https://groups.io/g/onstep
 * 
 *           *** Read the compiler warnings and errors, they are there to help guard against invalid configurations ***
 *
 * ---------------------------------------------------------------------------------------------------------------------------------
 * ADJUST THE FOLLOWING TO CONFIGURE YOUR CONTROLLER FEATURES ----------------------------------------------------------------------
 * <-Req'd = always must set, <-Often = usually must set, Option = optional, Adjust = adjust as req'd, Infreq = infrequently changed
*/
//      Parameter Name              Value   Default  Notes                                                                      Hint

// =================================================================================================================================
// CONTROLLER ======================================================================================================================

// DEBUG ---------------------------------------------------------------------------------------------------------------------------
// Enables additional debugging and/or status messages on the specified SERIAL_DEBUG port (be sure to disable when done!)
// Note: The SERIAL_DEBUG port is often (almost always) attached to the same SERIAL_A port so it cannot be used for normal
//       LX200 protocol communications.  If this is the case set both to the same (faster) baud rate specified below.
#define DEBUG                         OFF //    OFF, Use ON for background error messages only, use VERBOSE for all           Infreq
                                          //         error and status messages, use CONSOLE for VT100 debug console,
                                          //         or use PROFILER for VT100 task profiler.
#define DEBUG_SERVO                   OFF //    OFF, n. Where n=1 to 9 as the designated axis for logging servo activity.     Option
#define DEBUG_ECHO_COMMANDS           OFF //    OFF, Use ON or ERRORS_ONLY to log commands to the debug serial port.          Option
#define SERIAL_DEBUG               Serial // Serial, Use any available h/w serial port. Serial1 or Serial2, etc.              Option
#define SERIAL_DEBUG_BAUD          230400 // 230400, n. Where n=9600,19200,57600,115200,230400,460800 (common baud rates.)    Option

// NON-VOLATILE STORAGE ------------------------------------------------------------------------------------------------------------
#define NV_WIPE                       OFF //         OFF, Causes the defaults to be written back into NV (FLASH,EEPROM,etc.)  Infreq
                                          //              ***     IMPORTANT: ENABLE THIS OPTION THEN UPLOAD, WAIT A MINUTE    ***
// Warning --->                           //              ***     OR TWO THEN SET THIS OPTION TO OFF AND UPLOAD AGAIN.        ***
                                          //              ***     LEAVING THIS OPTION ENABLED CAN CAUSE EXCESSIVE NV          ***
                                          //              ***     WEAR AND DAMAGE THE MICROCONTROLLER NV SUBSYSTEM !!!        ***

// ESP32 VIRTUAL SERIAL BLUETOOTH AND IP COMMAND CHANNELS --------------------------------------------------------------------------
#define SERIAL_BT_MODE                SLAVE //    OFF, Use SLAVE to enable the interface (ESP32 only.)                          Option
#define SERIAL_BT_NAME          "Askar" //         "OnStepX", Bluetooth device name.                                        Adjust
// #define SERIAL_BT_NAME          "OnStepX Celestron 8" //         "OnStepX", Bluetooth device name.                                        Adjust
#define SERIAL_IP_MODE                OFF //    OFF, WIFI_ACCESS_POINT or WIFI_STATION enables interface (ESP32 only.)        Option
#define MDNS_NAME               "onstepx" //    "onstepx", mDNS device name.                                                  Adjust
#define WEB_SERVER                    OFF //    OFF, ON enables Webserver (for Website plugin.)                               Option

// EXTERNAL GPIO SUPPORT -----------------------------------------------------------------------------------------------------------
#define GPIO_DEVICE                   OFF //    OFF, DS2413: for 2-ch or 4-ch using 1-wire gpio's (one or two devices.)       Option
                                          //         SWS: for 8-ch Serial gpio (normally 4 unused encoder pins.)
                                          //         MCP23008: for 8-ch I2C gpio.
                                          //         MCP23017, X9555, or X8575: for 16-ch I2C gpio.
                                          //         SSR74HC595: for up to 32-ch gpio (serial shift register, output only.)
                                          //         Works w/most OnStep features, channels assigned in order pin# 512 and up.

// ---------------------------------------------------------------------------------------------------------------------------------

// #define AXIS2_HOME_DEFAULT -90