/*
*File Name: hbd_ctrl.h
************************************************************************
*
* Copyright 2018-2020 All rights reserved. Goodix Inc.
*
* Description: GH30x sensor control library header.
* Note:	
* Identifier abbreviation:  Wnd - Window
*                           Msg - Message
* MODIFICATION HISTORY
**********************************************************************/

#ifndef __HBD_CTRL_H__
#define __HBD_CTRL_H__

typedef unsigned char GU8;
typedef signed char GS8;
typedef unsigned short GU16;
typedef signed short GS16;
typedef long int GS32;
typedef unsigned long int GU32;
typedef float GF32;

#define HBD_EXAMPLE_CODE_EN (1)
#define NEW_SOFT_AUTOLED (1)

/*Hbd Lib Verision*/
#define HBD_BAND_VERSION "LibHBD_Band_v3.3.0"
#define HBD_EP_VERSION "LibHBD_Ep_v3.3.0"

/* virtual addr. */
#define COMM_ALGORITHM_VIRTUAL_ADDR (0x2000)

/************************************************************************
*   Macro Definitions
************************************************************************/
#define HB_SAMPLING_RATE_SETTING (25)    // sample rate set 25Hz
#define HRV_SAMPLING_RATE_SETTING (100)  // sample rate set 100Hz
#define SPO2_SAMPLING_RATE_SETTING (100) // sample rate set 100Hz

/*indedx of fifo thr config. */
#define HBD_FIFO_THR_CONFIG_HRV_INDEX (0u)
#define HBD_FIFO_THR_CONFIG_HB_INDEX (1u)
#define HBD_FIFO_THR_CONFIG_SpO2_INDEX (2u)
#define HBD_FIFO_THR_CONFIG_NUM (3u)

/* auto led mcaro */
#define HBD_AUTO_LED_CHECK_MAX_SUM (40) // max

#if !NEW_SOFT_AUTOLED
#define HBD_HB_AUTO_LED_CHECK_SUM (5)   // hb
#define HBD_HRV_AUTO_LED_CHECK_SUM (20) // hrv

#define HBD_AUTO_LED_TRIGER_FLAG_CH1 (1 << 0)
#define HBD_AUTO_LED_TRIGER_FLAG_CH2 (1 << 1)
#define HBD_AUTO_LED_TRIGER_FLAG_BG_UP (1 << 2)
#define HBD_AUTO_LED_TRIGER_FLAG_BG_LOW (1 << 3)
#else
#define HBD_AUTO_LED_TRIGER_FLAG_CH1 (1 << 0)
#define HBD_AUTO_LED_TRIGER_FLAG_CH2 (1 << 1)
#define HBD_AUTO_LED_TRIGER_FLAG_BG_WeakStronglight (1 << 2)
#define HBD_AUTO_LED_TRIGER_FLAG_BG_Stronglight (1 << 3)
#endif

/* Hbd commhandler return value type. */
typedef enum
{
    COMM_CMD_ALGO_IN_MCU_HB_START = 0,
    COMM_CMD_ALGO_IN_MCU_HB_STOP,
    COMM_CMD_ALGO_IN_APP_HB_START,
    COMM_CMD_ALGO_IN_APP_HB_STOP,
    COMM_CMD_ALGO_IN_MCU_HRV_START,
    COMM_CMD_ALGO_IN_MCU_HRV_STOP,
    COMM_CMD_ALGO_IN_APP_HRV_START,
    COMM_CMD_ALGO_IN_APP_HRV_STOP,
    COMM_CMD_ADT_SINGLE_MODE_START,
    COMM_CMD_ADT_SINGLE_MODE_STOP,
    COMM_CMD_ADT_CONTINUOUS_MODE_START,
    COMM_CMD_ADT_CONTINUOUS_MODE_STOP,
    COMM_CMD_ALGO_IN_MCU_SPO2_START,
    COMM_CMD_ALGO_IN_MCU_SPO2_STOP,
    COMM_CMD_ALGO_IN_APP_SPO2_START,
    COMM_CMD_ALGO_IN_APP_SPO2_STOP,
    COMM_CMD_INVALID,
} EM_COMM_CMD_TYPE;
typedef enum
{
    AUTO_LED_BG_STATE_NORMAL = 0,    //NORMAL
    AUTO_LED_BG_STATE_UNCERTAIN = 1, //����ǿ��
    AUTO_LED_BG_STATE_STRONG = 2,    //ǿ��ģʽ
    AUTO_LED_BG_STATE_WEAK = 3,      //��ǿ��ģʽ(bg < 5, ���ǵ���ʧ��)
    AUTO_LED_BG_STATE_NUM
} EM_AUTO_LED_BG_STATE;

#define AUTO_LED_BG_THR_HIGH 5
#define AUTO_LED_BG_THR_LOW 4
#define AUTO_LED_BG_STATE_WEAK_CNT 200 //500

/* Hbd functiional state enum. */
typedef enum
{
    HBD_FUNCTIONAL_STATE_DISABLE = 0,
    HBD_FUNCTIONAL_STATE_ENABLE = 1,
} EM_HBD_FUNCTIONAL_STATE;

/* Hb sample rate enum. */
enum EM_HB_SAMPLING_RATE
{
    HB_SAMPLING_RATE_25HZ = 25,
    HB_SAMPLING_RATE_40HZ = 40,
    HB_SAMPLING_RATE_INVALID,
};

/* Hrv sample rate enum. */
enum EM_HRV_SAMPLING_RATE
{
    HRV_SAMPLING_RATE_100HZ = 100,
    HRV_SAMPLING_RATE_200HZ = 200,
    HRV_SAMPLING_RATE_INVALID,
};

/* SpO2 sample rate enum. */
enum EM_SPO2_SAMPLING_RATE
{
    SPO2_SAMPLING_RATE_100HZ = 100,
    SPO2_SAMPLING_RATE_200HZ = 200,
    SPO2_SAMPLING_RATE_INVALID,
};

/* Int status enum. */
enum EM_INT_STATUS
{
    INT_STATUS_CHIP_RESET = 0,
    INT_STATUS_NEW_DATA,
    INT_STATUS_FIFO_WATERMARK,
    INT_STATUS_FIFO_FULL,
    INT_STATUS_WEAR_DETECTED,
    INT_STATUS_UNWEAR_DETECTED,
    INT_STATUS_INVALID,
};

/* Hb start mode enum. */
enum EM_HB_START_MODE
{
    HB_START_MODE_HB = 0,
    HB_START_MODE_HRV,
    HB_START_MODE_SPO2,
    HB_START_MODE_INVAILD,
};

/* Adt start mode enum. */
enum EM_ADT_START_MODE
{
    ADT_START_MODE_WEAR_DETECT = 0,
    ADT_START_MODE_UNWEAR_DETECT,
    ADT_START_MODE_INVALID,
};

/* Adt mode flag enum. */
enum EM_HBD_ADT_MODE
{
    HBD_ADT_MODE_SINGLE = 0,
    HBD_ADT_MODE_CONTINUOUS,
    HBD_ADT_MODE_INVALID,
};

/* I2c Low Two bit select enum. */
enum EM_HBD_I2C_ID_SEL
{
    HBD_I2C_ID_SEL_1L0L = 0,
    HBD_I2C_ID_SEL_1L0H,
    HBD_I2C_ID_SEL_1H0L,
    HBD_I2C_ID_SEL_1H0H,
    HBD_I2C_ID_INVALID,
};

/* Led pd select enum. */
typedef enum
{
    HBD_LED_PD_SEL_INTERNAL = 0,
    HBD_LED_PD_SEL_EXTERNAL,
} EM_HBD_LED_PD_SEL;

/* Led logic channel map to hw led enum. */
typedef enum
{
    HBD_LED_LOGIC_CHANNEL_MAP_PHY012 = 0,
    HBD_LED_LOGIC_CHANNEL_MAP_PHY021,
    HBD_LED_LOGIC_CHANNEL_MAP_PHY102,
    HBD_LED_LOGIC_CHANNEL_MAP_PHY120,
    HBD_LED_LOGIC_CHANNEL_MAP_PHY201,
    HBD_LED_LOGIC_CHANNEL_MAP_PHY210,
} EM_HBD_LED_LOGIC_CHANNEL_MAP;

/* Led Logic Channel1 & led2 mode. */
typedef enum
{
    HBD_LOGIC_CHANNEL1_2_MODE_NORMAL = 0,
    HBD_LOGIC_CHANNEL1_2_MODE_SYNC,
    HBD_LOGIC_CHANNEL1_2_MODE_SHARE_CONFIG,
    HBD_LOGIC_CHANNEL1_2_MODE_SYNC_SHARE_CONFIG,
} EM_HBD_LOGIC_CHANNEL1_2_MODE;

/* sample time enum. */
typedef enum
{
    HBD_SAMPLE_TIME_32CYCLES = 0,
    HBD_SAMPLE_TIME_64CYCLES,
    HBD_SAMPLE_TIME_128CYCLES,
    HBD_SAMPLE_TIME_256CYCLES,
    HBD_SAMPLE_TIME_512CYCLES,
    HBD_SAMPLE_TIME_1024CYCLES,
    HBD_SAMPLE_TIME_2048CYCLES,
} EM_HBD_SAMPLE_TIME;

/* tia gain enum. */
typedef enum
{
    HBD_TIA_GAIN_0 = 0,
    HBD_TIA_GAIN_1,
    HBD_TIA_GAIN_2,
    HBD_TIA_GAIN_3,
    HBD_TIA_GAIN_4,
    HBD_TIA_GAIN_5,
    HBD_TIA_GAIN_6,
    HBD_TIA_GAIN_7,
} EM_HBD_TIA_GAIN;

/* G-sensor sensitivity(counts/g) enum. */
typedef enum
{
    HBD_GSENSOR_SENSITIVITY_512_COUNTS_PER_G = 0,
    HBD_GSENSOR_SENSITIVITY_1024_COUNTS_PER_G,
    HBD_GSENSOR_SENSITIVITY_2048_COUNTS_PER_G,
    HBD_GSENSOR_SENSITIVITY_4096_COUNTS_PER_G,
    HBD_GSENSOR_SENSITIVITY_8192_COUNTS_PER_G,
} EM_HBD_GSENSOR_SENSITIVITY;

/* max current range enum. */
typedef enum
{
    HBD_MAX_CURRENT_RANGE_40MA = 0x2D,
    HBD_MAX_CURRENT_RANGE_60MA = 0x4D,
    HBD_MAX_CURRENT_RANGE_100MA = 0x8D,
} EM_HBD_MAX_CURRENT_RANGE;

/* bg cancel mode enum. */
typedef enum
{
    HBD_BG_CANCEL_MODE_OFF = 0,
    HBD_BG_CANCEL_MODE_AUTO,
    HBD_BG_CANCEL_MODE_BY_OUSIDE,
} EM_HBD_BG_CANCEL_MODE;

/* Hb config struct type. */
typedef struct
{
    EM_HBD_FUNCTIONAL_STATE emHbModeFifoEnable;   // HB fifo enable flag
    GU16 usHbModeSampleRate;                      // HB sample rate
    EM_HBD_FUNCTIONAL_STATE emHrvModeFifoEnable;  // HRV fifo enable flag
    GU16 usHrvModeSampleRate;                     // HRV sample rate
    EM_HBD_FUNCTIONAL_STATE emSpO2ModeFifoEnable; // HRV fifo enable flag
    GU16 usSpO2ModeSampleRate;                    // HRV sample rate
} ST_HB_CONFIG_TYPE;

/* Adt config struct type. Notes: only logic channel0 & channel1 valid in adt mode. */
typedef struct
{
    EM_HBD_FUNCTIONAL_STATE emGINTEnable;              // GINT enable flag
    EM_HBD_LED_LOGIC_CHANNEL_MAP emLedLogicChannelMap; // Logic map
    EM_HBD_LED_PD_SEL emLogicChannel0PDSelect;         // Logic Channel0 PD select
    EM_HBD_LED_PD_SEL emLogicChannel1PDSelect;         // Logic Channel1 PD select
    GU8 uchLogicChannel0Current;                       // Logic Channel0 current cofig(1 step = 400uA)
    GU8 uchLogicChannel1Current;                       // Logic Channel1 current cofig(1 step = 400uA)
    EM_HBD_TIA_GAIN emLogicChannel0TiaGain;            // Logic Channel0 tia gain(valid value:0-7)
    EM_HBD_TIA_GAIN emLogicChannel1TiaGain;            // Logic Channel1 tia gain(valid value:0-7)
    EM_HBD_SAMPLE_TIME emSampleTime;                   // Sample time
} ST_ADT_CONFIG_TYPE;

/* Hbd init config struct type. */
typedef struct
{
    ST_HB_CONFIG_TYPE stHbInitConfig;
    ST_ADT_CONFIG_TYPE stAdtInitConfig;
} ST_HBD_INIT_CONFIG_TYPE;

/* Gsensor data struct type. */
typedef struct
{
    GS16 sXAxisVal; // X-Axis Value
    GS16 sYAxisVal; // Y-Axis Value
    GS16 sZAxisVal; // Z-Axis Value
} ST_GS_DATA_TYPE;

/* register struct. */
typedef struct
{
    GU16 usRegAddr;
    GU16 usRegData;
} ST_REGISTER;

/* fifo thr config . */
typedef struct
{
    GU8 uchFifoThrCntConfigByFunc; // Fifo threshold set by function
    GU16 usFifoThrCntConfigVal;    // Fifo threshold cnt
} ST_FIFO_THR_CONFIG;

/* autoled  channel struct. */
typedef struct
{
    GU32 unTrigerUpperThr;
    GU32 unTrigerLowerThr;

    GU32 unTargetUpperThr;
    GU32 unTargetLowerThr;
    GU32 unLightLeakLowerThr;
    GU8 uchGainLimitThr;                               //Gain Max 7,will be changed if strong light
    GU8 uchCurrentLimit;                               //Energy Saving Setting,Can be changed by diffrent mode such as HB SPO2
    EM_HBD_FUNCTIONAL_STATE emAutoledSaveEnergyEnable; //If Enable,AutoLED will start from little current, The value changed by Reg 0x2A19
    EM_HBD_FUNCTIONAL_STATE emAutoledEnable;
} ST_AUTO_LED_CH_CONFIG;

/* soft autoled struct. */
typedef struct
{
    ST_AUTO_LED_CH_CONFIG stAutoLedChannel[2];
    GU8 uchBgStrongLightThr; //Default 5
    GU8 uchBgUpperThr;
    GU8 uchgLowerThr;
} ST_AUTO_LED_CONFIG;

/* soft autoled rawdata buffer struct. */
typedef struct
{
    GU32 unRawdataBuffer[HBD_AUTO_LED_CHECK_MAX_SUM];
} ST_AUTO_LED_RAWDATA;

/* logic channel autoled config struct type. */
typedef struct
{
    EM_HBD_FUNCTIONAL_STATE emAutoLedCurrentAdjustEnable; // auto led current adjust enable flag
    EM_HBD_FUNCTIONAL_STATE emAutoLedGainAdjustEnable;    // auto led gain adjust enable flag
} ST_LOGIC_CHANNEL_AUTOLED_CONFIG_TYPE;

/* Hbd function return code definitions list. */
#define HBD_RET_OK (0)                         /**< There is no error */
#define HBD_RET_GENERIC_ERROR (-1)             /**< A generic error happens */
#define HBD_RET_PARAMETER_ERROR (-2)           /**< Parameter error */
#define HBD_RET_COMM_NOT_REGISTERED_ERROR (-3) /**< I2c/Spi communication interface not registered error */
#define HBD_RET_COMM_ERROR (-4)                /**< I2c/Spi Communication error */
#define HBD_RET_RESOURCE_ERROR (-5)            /**< Resource full or not available error */
#define HBD_RET_NO_INITED_ERROR (-6)           /**< No inited error */
#define HBD_RET_LED_CONFIG_ALL_OFF_ERROR (-7)  /**< Led config all off error */

/******* hbd init default config ****************
 * stHbInitConfig = { HBD_FUNCTIONAL_STATE_ENABLE,          /// hb mode fifo enable 
 *                    HB_SAMPLING_RATE_25HZ,                /// hb mode sample rate
 *                    HBD_FUNCTIONAL_STATE_ENABLE,          /// hrv mode fifo enable 
 *                    HRV_SAMPLING_RATE_100HZ,              /// hrv mode sample rate
 *                  }
 * stAdtInitConfig = { HBD_FUNCTIONAL_STATE_DISABLE,        /// GINT disable
 *                     HBD_LED_LOGIC_CHANNEL_MAP_PHY012,    /// Logic map
 *                     HBD_LED_PD_SEL_INTERNAL,             /// Logic Channel0 PD select
 *                     HBD_LED_PD_SEL_INTERNAL,             /// Logic Channel1 PD select
 *                     0x19,                                /// Logic Channel0 current 10mA (1 step = 400uA)
 *                     0x19,                                /// Logic Channel1 current 10mA (1 step = 400uA)
 *                     HBD_TIA_GAIN_3,                      /// Logic Channel0 tia gain
 *                     HBD_TIA_GAIN_3,                      /// Logic Channel1 tia gain
 *                     HBD_SAMPLE_TIME_128CYCLES,           /// sample time
 *                   }
 */
#define HBD_INIT_CONFIG_DEFAULT_DEF(var) ST_HBD_INIT_CONFIG_TYPE var = {                                                                                 \
                                             {HBD_FUNCTIONAL_STATE_ENABLE, HB_SAMPLING_RATE_25HZ, HBD_FUNCTIONAL_STATE_ENABLE, HRV_SAMPLING_RATE_100HZ}, \
                                             {HBD_FUNCTIONAL_STATE_DISABLE,                                                                              \
                                              HBD_LED_LOGIC_CHANNEL_MAP_PHY012,                                                                          \
                                              HBD_LED_PD_SEL_INTERNAL,                                                                                   \
                                              HBD_LED_PD_SEL_INTERNAL,                                                                                   \
                                              0x19, 0x19, HBD_TIA_GAIN_3, HBD_TIA_GAIN_3, HBD_SAMPLE_TIME_128CYCLES}}

/****************************************************************
* Description: set i2c operation function
* Input:  uchI2cIdLowTwoBitsSelect: i2c low two bits addr selected, see EM_HBD_I2C_ID_SEL
          pI2cWriteFunc: i2c write function pointer
          pI2cReadFunc: i2c read function pointer
* Return: HBD_RET_PARAMETER_ERROR: function pointer parameter set null error,
          HBD_RET_OK: register success
******************************************************************/
GS8 HBD_SetI2cRW(GU8 uchI2cIdLowTwoBitsSelect,
                 GU8 (*pI2cWriteFunc)(GU8 uchDeviceId, const GU8 uchWriteBytesArr[], GU16 usWriteLen),
                 GU8 (*pI2cReadFunc)(GU8 uchDeviceId, const GU8 uchCmddBytesArr[], GU16 usCmddLen, GU8 uchReadBytesArr[], GU16 usMaxReadLen));

/****************************************************************
* Description: set spi operation function
* Input:  pSpiWriteFunc: spi write function pointer
          pSpiReadFunc: spi read function pointer
          pSpiCSCtrlFunc: spi cs operation function pointer
* Return: HBD_RET_PARAMETER_ERROR: function pointer parameter set null error,
          HBD_RET_OK: register success
******************************************************************/
GS8 HBD_SetSpiRW(GU8 (*pSpiWriteFunc)(GU8 uchWriteBytesArr[], GU16 usWriteLen),
                 GU8 (*pSpiReadFunc)(GU8 uchReadBytesArr[], GU16 usMaxReadLen),
                 void (*pSpiCSCtrlFunc)(GU8 uchCsLevelHigh));

/****************************************************************
* Description: set delay function callback
* Input:  pDelayUsFunc:delay function callback
* Return: None
******************************************************************/
void HBD_SetDelayUsCallback(void (*pDelayUsFunc)(GU16 usUsec));

/****************************************************************
* Description: Set storage ctrl function
* Input:    pStorageWriteFunc: storage data write func ptr,
            pStorageReadFunc: storage data read func ptr,
            unConfigStorageAddr: sotrage addr,
* Return: None
******************************************************************/
void HBD_SetConfigStorageFunc(void (*pStorageWriteFunc)(GU32 unStoreAddr, GU8 uchBufferArr[], GU16 usLength),
                              void (*pStorageReadFunc)(GU32 unStoreAddr, GU8 uchBufferArr[], GU16 usLength),
                              GU32 unConfigStorageAddr);

/****************************************************************
* Description: load new GH30x config
* Input:    uchNewConfigArr: config array ,
            uchForceUpdateConfig: 1:force update, 0:auto select, 
* Return: HBD_RET_OK:use new config arr, HBD_RET_GENERIC_ERROR:use the storage config arr,
******************************************************************/
GS8 HBD_LoadNewConfig(GU8 uchNewConfigArr[], GU8 uchForceUpdateConfig);

/****************************************************************
* Description: load new GH30x reg config array
* Input:    stRegConfigArr: reg config array ,
            usRegConfigLen: reg config array len, 
* Return: HBD_RET_OK:load config success, HBD_RET_COMM_ERROR: load config error,
******************************************************************/
GS8 HBD_LoadNewRegConfigArr(const ST_REGISTER stRegConfigArr[], GU16 usRegConfigLen);

/****************************************************************
* Description: Communication operation interface confirm.
* Output:  None
* Return: HBD_RET_OK=GH30x comunicate ok, 
          HBD_RET_COMM_ERROR=GH30x comunicate error,
          HBD_RET_COMM_NOT_REGISTERED_ERROR=GH30x i2c/spi interface not registered,
******************************************************************/
GS8 HBD_CommunicationInterfaceConfirm(void);

/****************************************************************
* Description: init hbd configure parameters
* Input:    stHbInitConfigParam: Init Config struct ,see ST_HBD_INIT_CONFIG_TYPE,
* Return: HBD_RET_OK=success, 
          HBD_RET_PARAMETER_ERROR=paramters error,
          HBD_RET_COMM_ERROR=GH30x comunicate error, 
          HBD_RET_COMM_NOT_REGISTERED_ERROR=GH30x i2c/spi interface not registered
******************************************************************/
GS8 HBD_Init(ST_HBD_INIT_CONFIG_TYPE *stHbdInitConfigParam);

/****************************************************************
* Description: start hbd
* Input:  uchStartMode: HB_START_MODE_HB: Hb mode, HB_START_MODE_HRV: Hrv Mode, 
* Return: HBD_RET_OK=success, 
          HBD_RET_NO_INITED_ERROR=not inited,
          HBD_RET_LED_CONFIG_ALL_OFF_ERROR=all Led disable error,
          HBD_RET_PARAMETER_ERROR=start mode parameter error, 
******************************************************************/
GS8 HBD_HbStart(GU8 uchStartMode);

/****************************************************************
* Description: start wear detect
* Input:  uchStartMode: ADT_START_MODE_WEAR_DETECT: Wear detect mode, 
                        ADT_START_MODE_UNWEAR_DETECT: Unwear detect Mode, 
          uchAdtMode: HBD_ADT_MODE_SINGLE:single mode, 
                      HBD_ADT_MODE_CONTINUOUS: continuous mode
* Return: HBD_RET_OK=success, 
          HBD_RET_NO_INITED_ERROR=fail:don't init success 
          HBD_RET_PARAMETER_ERROR=fail:parameter error
******************************************************************/
GS8 HBD_AdtStart(GU8 uchStartMode, GU8 uchAdtMode);

/****************************************************************
* Description: stop all start mode
* Input:  None
* Return: HBD_RET_OK=success, HBD_RET_NO_INITED_ERROR=fail:don't init success 
******************************************************************/
GS8 HBD_Stop(void);

/****************************************************************
* Description: get Int status 
* Input:  None
* Return: Status, see EM_INT_STATUS
******************************************************************/
GU8 HBD_GetIntStatus(void);

/****************************************************************
* Description: Pack rawdata package, if want get static state value, 
               param [stGsAxisValue]could set NULL 
* Input:  stGsAxisValue: acc value, see ST_GS_DATA_TYPE
          emGsensorSensitivity: G-sensor sensitivity (counts/g), see EM_HBD_GSENSOR_SENSITIVITY
* Return: rawdata package count
******************************************************************/
GU16 HBD_PollWithGSensor(ST_GS_DATA_TYPE *stGsAxisValue, EM_HBD_GSENSOR_SENSITIVITY emGsensorSensitivity);

/****************************************************************
* Description: pack rawdata package with gsensor buffer, if want get static state value, 
               param [stGsAxisValue]could set NULL, or param [usGsDataNum] set less than freq
* Input:  stGsAxisValue: gsensor buffer data
          usGsDataNum: gsensor buffer len, must greater than hbd freq
          emGsensorSensitivity: G-sensor sensitivity (counts/g), see EM_HBD_GSENSOR_SENSITIVITY
* Return: rawdata package count
******************************************************************/
GU16 HBD_PollWithGSensorBuffer(ST_GS_DATA_TYPE stGsAxisValue[], GU16 usGsDataNum, EM_HBD_GSENSOR_SENSITIVITY emGsensorSensitivity);

/****************************************************************
* Description: restart hbd if read done stop, must use with HBD_PollWithGSensorBuffer_Ex
* Input:  none, 
* Return: HBD_RET_OK=success, 
          HBD_RET_NO_INITED_ERROR=not inited,
          HBD_RET_LED_CONFIG_ALL_OFF_ERROR=all Led disable error,
******************************************************************/
GS8 HBD_HbRestart_Ex(void);

/****************************************************************
* Description: pack rawdata with gsensor buffer, when read done hbd stop, 
               must use with HBD_HbRestart_Ex
* Input:  stGsAxisValue: gsensor buffer data
          usGsDataNum: gsensor buffer len, must greater than hbd freq
          emGsensorSensitivity: G-sensor sensitivity (counts/g), see EM_HBD_GSENSOR_SENSITIVITY
          puchReadingFlag: ptr of reading data flag 
          puchTimeoutFlag: ptr of timer timeout flag
* Return: rawdata package count
******************************************************************/
GU16 HBD_PollWithGSensorBuffer_Ex(ST_GS_DATA_TYPE stGsAxisValue[], GU16 usGsDataNum, EM_HBD_GSENSOR_SENSITIVITY emGsensorSensitivity, GU8 *puchReadingFlag, GU8 *puchTimeoutFlag);

/****************************************************************
* Description: pack rawdata with gsensor buffer, when read done hbd stop, 
               must use with HBD_HbRestart_Ex
* Input:  stGsAxisValue: gsensor buffer data
          usGsDataNum: gsensor buffer len, must greater than hbd freq
          emGsensorSensitivity: G-sensor sensitivity (counts/g), see EM_HBD_GSENSOR_SENSITIVITY
          puchReadingFlag: ptr of reading data flag 
          puchTimeoutFlag: ptr of timer timeout flag
* Return: rawdata package count
******************************************************************/
GU16 HBD_PollWithGSensorBuffer_Ex2(ST_GS_DATA_TYPE stGsAxisValue[], GU16 usGsDataNum, EM_HBD_GSENSOR_SENSITIVITY emGsensorSensitivity, GU8 *puchReadingFlag, GU8 *puchTimeoutFlag);

/****************************************************************
* Description: hb rawdata pack
* Input:  None
* Return: length
******************************************************************/
GU16 HBD_HbRawdataPack(void);

/****************************************************************
* Description: hb fifo rawdata pack
* Input:  None
* Return: length
******************************************************************/
GU16 HBD_HbFifoRawdataPack(void);

/****************************************************************
* Description: hrv rawdata pack
* Input:  None
* Return: length
******************************************************************/
GU16 HBD_HrvRawdataPack(void);

/****************************************************************
* Description: hrv fifo rawdata pack
* Input:  None
* Return: length
******************************************************************/
GU16 HBD_HrvFifoRawdataPack(void);

/****************************************************************
* Description: hb rawdata pack
* Input:  None
* Return: length
******************************************************************/
GU16 HBD_HbRawdataAutoLedPack(void);

/****************************************************************
* Description: hb fifo rawdata pack
* Input:  None
* Return: length
******************************************************************/
GU16 HBD_HbFifoRawdataAutoLedPack(void);

/****************************************************************
* Description: hrv rawdata pack
* Input:  None
* Return: length
******************************************************************/
GU16 HBD_HrvRawdataAutoLedPack(void);

/****************************************************************
* Description: hrv fifo rawdata pack
* Input:  None
* Return: length
******************************************************************/
GU16 HBD_HrvFifoRawdataAutoLedPack(void);

/****************************************************************
* Description: get rawdata package.
* Output:   pnRawDataBuffer[0]: gh30x ppg1 data
            pnRawDataBuffer[1]: gh30x ppg2 data, if enable one channel, same as ppg1
            pnRawDataBuffer[2]: gsensor x-axis data 
            pnRawDataBuffer[3]: gsensor y-axis data 
            pnRawDataBuffer[4]: gsensor z-axis data 
            pnRawDataBuffer[5]: package index(0-255) 
* Return: HBD_RET_OK:success to get raw data, HBD_RET_RESOURCE_ERROR:fail.
******************************************************************/
GS8 HBD_GetRawDataPackage(GS32 *pnRawDataBuffer);

/****************************************************************
* Description: get rawdata package with flags.
* Output:   pnRawDataBuffer[0]: gh30x ppg1 flags, bit 0: autoled flag
            pnRawDataBuffer[1]: gh30x ppg1 data
            pnRawDataBuffer[2]: gh30x ppg2 flags, bit 0: autoled flag.if enable one channel, same as ppg1 flags
            pnRawDataBuffer[3]: gh30x ppg2 data. if enable one channel, same as ppg1 data
            pnRawDataBuffer[4]: gsensor x-axis data 
            pnRawDataBuffer[5]: gsensor y-axis data 
            pnRawDataBuffer[6]: gsensor z-axis data 
            pnRawDataBuffer[7]: package index(0-255) 
* Return: HBD_RET_OK:success to get raw data, HBD_RET_RESOURCE_ERROR:fail.
******************************************************************/
GS8 HBD_GetRawDataWithFlagsPackage(GS32 *pnRawDataBuffer);

/****************************************************************
* Description: Get version
* Input:    None,
* Return: library Hbd ctrl version
******************************************************************/
GS8 *HBD_GetHbdVersion(void);

/****************************************************************
* Description: Reset chip
* Input:  None
* Return: HBD_RET_OK=success, 
          HBD_RET_COMM_NOT_REGISTERED_ERROR=GH30x i2c/spi interface not registered
******************************************************************/
GS8 HBD_ChipReset(void);

/****************************************************************
* Description: change Hb config
* Input:  uchMode: 0:Hrv reconfig, else Hb reconfig
* Return: HBD_RET_OK=success, 
          HBD_RET_PARAMETER_ERROR=fail:parameter error,
******************************************************************/
GS8 HBD_ChangeHbConfig(GU8 uchMode, EM_HBD_FUNCTIONAL_STATE emFifoEnable, GU16 usSampleRate);

/****************************************************************
* Description: set irq pluse width 
* Input:  uchIrqPluseWidth: irq width(us) setting (not allow set 0 ),  
* Return: HBD_RET_OK=success, 
          HBD_RET_PARAMETER_ERROR=fail:parameter error
******************************************************************/
GS8 HBD_SetIrqPluseWidth(GU8 uchIrqPluseWidth);

/****************************************************************
* Description: parse communicate receive data
* Input:    uchCommInterFaceId: this id from HBD_SetSendDataFunc return,
            uchDataBuffArr: data buff ptr of receive data,
			uchLen: data len of receive data,
* Return: see EM_COMM_CMD_TYPE typedef
******************************************************************/

EM_COMM_CMD_TYPE HBD_CommParseHandler(GU8 uchCommInterFaceId, GU8 uchDataBuffArr[], GU8 uchLen);

/****************************************************************
* Description: Set send data function
* Input:    pSendDataFunc: send data func ptr,
* Return: val > 0:communication interface id,
          HBD_RET_RESOURCE_ERROR: have no resource,
******************************************************************/
GS8 HBD_SetSendDataFunc(void (*pSendDataFunc)(GU8 uchDataBuffArr[], GU8 uchLen));

/****************************************************************
* Description: send Package 
* Input:    None,
* Return: None
******************************************************************/
void HBD_SendPackage(void);

/****************************************************************
* Description: Pack rawdata and current package, if want get static state value, 
               param [stGsAxisValue]could set NULL 
* Input:  stGsAxisValue: acc value, see ST_GS_DATA_TYPE
          emGsensorSensitivity: G-sensor sensitivity (counts/g), see EM_HBD_GSENSOR_SENSITIVITY
* Return: rawdata package count
******************************************************************/
GU16 HBD_PollWithGSensorAndCurrent(ST_GS_DATA_TYPE *stGsAxisValue, EM_HBD_GSENSOR_SENSITIVITY emGsensorSensitivity);

/****************************************************************
* Description: pack rawdata and current package with gsensor buffer, if want get static state value, 
               param [stGsAxisValue]could set NULL, or param [usGsDataNum] set less than freq
* Input:  stGsAxisValue: gsensor buffer data
          usGsDataNum: gsensor buffer len, must greater than hbd freq
          emGsensorSensitivity: G-sensor sensitivity (counts/g), see EM_HBD_GSENSOR_SENSITIVITY
* Return: rawdata package count
******************************************************************/
GU16 HBD_PollWithGSensorAndCurrentBuffer(ST_GS_DATA_TYPE stGsAxisValue[], GU16 usGsDataNum, EM_HBD_GSENSOR_SENSITIVITY emGsensorSensitivity);

/****************************************************************
* Description: Pack rawdata package, if want get static state value, 
               param [stGsAxisValue]could set NULL 
* Input:  stGsAxisValue: acc value, see ST_GS_DATA_TYPE
          emGsensorSensitivity:　G-sensor sensitivity (counts/g), see EM_HBD_GSENSOR_SENSITIVITY
* Return: rawdata package count
******************************************************************/
GU16 HBD_PollWithGSensorAutoLed(ST_GS_DATA_TYPE *stGsAxisValue, EM_HBD_GSENSOR_SENSITIVITY emGsensorSensitivity);

/****************************************************************
* Description: pack rawdata package with gsensor buffer, if want get static state value, 
               param [stGsAxisValue]could set NULL, or param [usGsDataNum] set less than freq
* Input:  stGsAxisValue: gsensor buffer data
          usGsDataNum: gsensor buffer len, must greater than hbd freq
          emGsensorSensitivity:　G-sensor sensitivity (counts/g), see EM_HBD_GSENSOR_SENSITIVITY
* Return: rawdata package count
******************************************************************/
GU16 HBD_PollWithGSensorBufferAutoLed(ST_GS_DATA_TYPE stGsAxisValue[], GU16 usGsDataNum, EM_HBD_GSENSOR_SENSITIVITY emGsensorSensitivity);

/****************************************************************
* Description: Set Current And Gain, if only one channel, 
               ch2 must set as same chn1
* Input:  uchCh1Current : chn1 current
          uchCh2Current : chn2 current
          uchCh1Gain : chn1 gain
          uchCh2Gain : chn2 gain
* Return: HBD_RET_OK=success, 
          HBD_RET_PARAMETER_ERROR=fail:parameter error
******************************************************************/
GS8 HBD_SetCurrentAndGain(GU8 uchCh1Current, GU8 uchCh2Current, GU8 uchCh1Gain, GU8 uchCh2Gain);

/****************************************************************
* Description: get rawdata package.
* Output:   pnRawDataBuffer[0]: gh30x ppg1 data
            pnRawDataBuffer[1]: gh30x ppg2 data, if enable one channel, same as ppg1
            pnRawDataBuffer[2]: gh30x chn1 gain
            pnRawDataBuffer[3]: gh30x chn2 gain, if enable one channel, same as ppg1            
            pnRawDataBuffer[4]: gsensor x-axis data 
            pnRawDataBuffer[5]: gsensor y-axis data 
            pnRawDataBuffer[6]: gsensor z-axis data 
            pnRawDataBuffer[7]: gh30x chn1 current
            pnRawDataBuffer[8]: gh30x chn2 current, if enable one channel, same as ppg1
            pnRawDataBuffer[9]: package index(0-255) 
* Return: HBD_RET_OK:success to get raw data, HBD_RET_RESOURCE_ERROR:fail.
******************************************************************/
GS8 HBD_GetRawDataWithGainAndCurrentPackage(GS32 *pnRawDataBuffer);

/****************************************************************
* Description: Send Cmd Resume
* Input:  None
* Return: HBD_RET_OK=success, 
******************************************************************/
GS8 HBD_SendCmdResume(void);

/****************************************************************
* Description: Set Current 
* Input:  uchLogicChannel0Current : logic channel 0 current
          uchLogicChannel1Current : logic channel 1 current
          uchLogicChannel2Current : logic channel 2 current
* Return: HBD_RET_OK=success, 
******************************************************************/
GS8 HBD_SetLogicChannelCurrent(GU8 uchLogicChannel0Current, GU8 uchLogicChannel1Current, GU8 uchLogicChannel2Current);

/****************************************************************
* Description: Set Gain, 
* Input:  emLogicChannel0Gain : logic channel 0 gain
          emLogicChannel1Gain : logic channel 1 gain
          emLogicChannel2Gain : logic channel 2 gain
* Return: HBD_RET_OK=success, 
******************************************************************/
GS8 HBD_SetLogicChannelGain(EM_HBD_TIA_GAIN emLogicChannel0Gain, EM_HBD_TIA_GAIN emLogicChannel1Gain, EM_HBD_TIA_GAIN emLogicChannel2Gain);

/****************************************************************
* Description: Set max Current range
* Input:  emMaxCurrentRange : max current range val
* Return: HBD_RET_OK=success, 
******************************************************************/
GS8 HBD_SetMaxCurrentRange(EM_HBD_MAX_CURRENT_RANGE emMaxCurrentRange);

/****************************************************************
* Description: Set hbd sample time cycles
* Input:  emSampleTimeCycles : hbd sample time cycles
* Return: HBD_RET_OK=success, 
******************************************************************/
GS8 HBD_SetSampleTimeCycles(EM_HBD_SAMPLE_TIME emSampleTimeCycles);

/****************************************************************
* Description: Set logic channel autoled 
* Input:  stLogicChannel0Autoled : logic channel 0 autoled config
          stLogicChannel1Autoled : logic channel 1 autoled config
          stLogicChannel2Autoled : logic channel 2 autoled config
* Return: HBD_RET_OK=success, 
******************************************************************/
GS8 HBD_SetLogicChannelAutoLed(ST_LOGIC_CHANNEL_AUTOLED_CONFIG_TYPE stLogicChannel0Autoled, ST_LOGIC_CHANNEL_AUTOLED_CONFIG_TYPE stLogicChannel1Autoled,
                               ST_LOGIC_CHANNEL_AUTOLED_CONFIG_TYPE stLogicChannel2Autoled);

/****************************************************************
* Description: Set logic channel enable, 
* Input:  emLogicChannel0Enable : logic channel 0 enable
          emLogicChannel1Enable : logic channel 1 enable
          emLogicChannel2Enable : logic channel 2 enable
          emLogicChannel12SynthesisEnable: logic channel 1 & 2 Synthesis, enable when logic 1 & 2 enable
* Return: HBD_RET_OK=success, 
******************************************************************/
GS8 HBD_SetLogicChannelEnable(EM_HBD_FUNCTIONAL_STATE emLogicChannel0Enable, EM_HBD_FUNCTIONAL_STATE emLogicChannel1Enable, EM_HBD_FUNCTIONAL_STATE emLogicChannel2Enable,
                              EM_HBD_FUNCTIONAL_STATE emLogicChannel12SynthesisEnable);

/****************************************************************
* Description: Set Bg cancel 
* Input:  emBgCancelMode : Bg cancel mode
          uchBgCancelValByOuside : cancel value, valid when emBgCancelMode set HBD_BG_CANCEL_MODE_BY_OUSIDE
* Return: HBD_RET_OK=success, 
          HBD_RET_PARAMETER_ERROR=fail:parameter error
******************************************************************/
GS8 HBD_SetBgCancel(EM_HBD_BG_CANCEL_MODE emBgCancelMode, GU8 uchBgCancelValByOuside);

#if 1
/****************************************************************
* Description: config autoled channel
* Input:  stAutoLedChannelConfig: channal config
          uchChannel: channel index(1 or 2)
* Return: HBD_RET_OK=success, 
          HBD_RET_PARAMETER_ERROR=paramters error,
******************************************************************/
GS8 HBD_AutoLedChannelConfig(ST_AUTO_LED_CH_CONFIG stAutoLedChannelConfig, GU8 uchChannel);

/****************************************************************
* Description: config autoled bg thr 
* Input:  uchBgUpperThrConfig: bg upper thr config
          uchgLowerThrConfig: bg lower thr config 
* Return: HBD_RET_OK=success
******************************************************************/
GS8 HBD_AutoLedBgThrConfig(GU8 uchBgUpperThrConfig, GU8 uchgLowerThrConfig);

/****************************************************************
* Description: config autoled 
* Input:  stAutoLedCh1Config: channal 1 config
          stAutoLedCh2Config: channal 2 config
          uchBgUpperThrConfig: bg upper thr config
          uchgLowerThrConfig: bg lower thr config 
* Return: HBD_RET_OK=success, 
******************************************************************/
GS8 HBD_AutoLedConfig(ST_AUTO_LED_CH_CONFIG stAutoLedCh1Config, ST_AUTO_LED_CH_CONFIG stAutoLedCh2Config,
                      GU8 uchBgUpperThrConfig, GU8 uchgLowerThrConfig);

/****************************************************************
* Description: config autoled gain start val
* Input:  emUseConfigValEnable: set HBD_FUNCTIONAL_STATE_ENABLE, use uchGainVal,
                                else use default val;
          uchGainVal: gain val, only 0-7 valid,  
* Return: HBD_RET_OK=success, 
******************************************************************/
GS8 HBD_AutoLedGainModeConfig(EM_HBD_FUNCTIONAL_STATE emUseConfigValEnable, GU8 uchGainVal);

/****************************************************************
* Description: soft autoled reset
* Input:  None
* Return: HBD_RET_OK=success
******************************************************************/
GS8 HBD_AutoLedReset(GU8 uchMode);

/****************************************************************
* Description: soft autoled get current and gain 
* Input:  uchFlag: flag of HBD_AutoLedCalcTriger function output 
          puchGainArr: ptr of gain output
          puchGainShiftArr: ptr of gain shift output
          pusLastGainMsk: ptr of gain mask output
          puchCurrentArr: ptr of current output
          puchCurrentShift: ptr of current shift output
          punLastCurrentMsk: ptr of current mask output
* Return: None
******************************************************************/
void HBD_AutoLedGetCurrentAndGain(GU8 uchLen, GU8 *puchGainArr, GU8 *puchGainShiftArr, GU16 *pusLastGainMsk,
                                  GU8 *puchCurrentArr, GU8 *puchCurrentShift, GU32 *punLastCurrentMsk);

/****************************************************************
* Description: save gain value to gain buffer 
* Input:  
* Return: None
******************************************************************/
void HBD_AutoLedSaveGainBuffer(GU8 uchLen, GU8 *puchGainArr);

/****************************************************************
* Description: soft autoled strong bg judge
* Input:   
* Return: strong flag 0: false 1: true
******************************************************************/
GS8 HBD_AutoLedStrongBgJudge(GU8 uchChannelIndex, GU8 uchLen);

/****************************************************************
* Description: 
* Input:   
* Return: 
******************************************************************/
GS8 HBD_AutoLedStrongBgThrAdjust(GU8 uchChannelIndex, GU8 uchLen);

/****************************************************************
* Description: soft autoled clac triger
* Input:  unRawdata: rawdata 
          uchLen: calc len 
          punRawdataAvgArr: ptr of avgvalue output 
* Return: triger flag, bit 0: PPG1, bit 1: PPG2, bit 2: bg > upper, bit 3: bg < lower
******************************************************************/
GU8 HBD_AutoLedCalcTriger(GU32 unRawdata[2], GU8 uchLen, GU32 *punRawdataAvgArr);

/****************************************************************
* Description: soft autoled clac calc gain current
* Input:  None
* Return: triger flag
******************************************************************/
GU8 HBD_AutoLedCalcGainCurrent(GU8 uchFlag, GU8 uchGainArr[2], GU8 uchGainShiftArr[2], GU16 usLastGainMsk,
                               GU8 uchCurrentArr[2], GU8 uchCurrentShift[2], GU32 unLastCurrentMsk, GU32 unRawdataAvgArr[2]);

/****************************************************************
* Description: soft autoled by new data
* Input:  unRawdata rawdata
* Return: autoled success or error
******************************************************************/
GU8 HBD_AutoLedbyNewDataInt(GU32 unRawdata[2]);

/****************************************************************
* Description: soft autoled by fifo int
* Input:  puchDataBuffer: fifo buffer
          usRawdatabufferCnt: rawdata cnt
* Return: autoled success or error
******************************************************************/
GU8 HBD_AutoLedbyFifoInt(GU8 *puchDataBuffer, GU16 usRawdatabufferCnt);

/****************************************************************
* Description: soft autoled clac calc gain current
* Input:  None
* Return: Bg flag
******************************************************************/
GS8 HBD_AutoLedGetStrongBgFlag(GU8 uchIdx, GU8 *puchStrongBgFlag);
#else

#endif
/****************************************************************
* Description: send sampling trg cmd, must in manual mode
* Input:  None
* Return: Bg flag
******************************************************************/
GS8 HBD_SendSamplingTrgCmd(void);

/****************************************************************
* Description: read GH30x register via i2c or spi
* Output: usAddr:register addr
* Return: register data
******************************************************************/
GU16 HBD_ReadReg(GU16 usAddr);

/****************************************************************
* Description: set HbMode fifo enable or disable
* Input:  EM_HBD_FUNCTIONAL_STATE
* Return: none
******************************************************************/
void HBD_SetHbFifoEnFlag(EM_HBD_FUNCTIONAL_STATE emHbFifoEnFlag);

/****************************************************************
* Description: set HrvMode fifo enable or disable
* Input:  EM_HBD_FUNCTIONAL_STATE
* Return: none
******************************************************************/
void HBD_SetHrvFifoEnFlag(EM_HBD_FUNCTIONAL_STATE emHrvFifoEnFlag);

/****************************************************************
* Description: set SpO2Mode fifo enable or disable
* Input:  EM_HBD_FUNCTIONAL_STATE
* Return: none
******************************************************************/
void HBD_SetSpO2FifoEnFlag(EM_HBD_FUNCTIONAL_STATE emSpO2FifoEnFlag);

/****************************************************************
* Description: Output the packaged raw data to the application
* Output:   nRawdataOut:  one frames data include: PPG1\PPG2\ACCX\ACCY\ACCZ\SN
            pusRawdataOutLen: frames of nRawdataOut
* Return: none
******************************************************************/
GS8 HBD_ExtractDebugOutputDataByFifoInt(GS32 nRawdataOut[][6], GU16 *pusRawdataOutLen);

/****************************************************************
* Description: get autoled status
* Input:  none
* Return: 1:AutoLed Fail  0: AutoLed Success
******************************************************************/
GU8 HBD_AutoLedErrorFlag(void);

extern void example_dbg_log(char *log_string);
#define HBD_LIB_DEBUG_LOG_LVL 0
#define HBD_LIB_DEBUG_LOG_SUP_LEN 256
/* debug log control, if enable debug, example_dbg_log must define in platforms code */
#if (HBD_LIB_DEBUG_LOG_LVL) // debug level > 0
/// lv1 log string
#define HBD_DEBUG_LOG_L1(...)                               \
    do                                                      \
    {                                                       \
        char dbg_log_str1[HBD_LIB_DEBUG_LOG_SUP_LEN] = {0}; \
        snprintf(dbg_log_str1, HBD_LIB_DEBUG_LOG_SUP_LEN,   \
                 "[gh30xLib]:"__VA_ARGS__);                 \
        example_dbg_log(dbg_log_str1);                      \
    } while (0)
#if (HBD_LIB_DEBUG_LOG_LVL > 1) // debug level > 1
/// lv2 log string
#define HBD_DEBUG_LOG_L2(...)          \
    {                                  \
        HBD_DEBUG_LOG_L1(__VA_ARGS__); \
    }
#else
#define HBD_DEBUG_LOG_L2(...)
#endif
#else // debug level <= 0
#define HBD_DEBUG_LOG_L1(...)
#define HBD_DEBUG_LOG_L2(...)
#endif

#endif /* __HBD_CTRL_H__ */

/********END OF FILE********* (C) COPYRIGHT 2018 .********/
