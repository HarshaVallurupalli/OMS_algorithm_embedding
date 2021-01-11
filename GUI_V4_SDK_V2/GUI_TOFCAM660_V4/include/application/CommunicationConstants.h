/**************************************************************************************
* Copyright (C) 2019 Espros Photonics Corporation
*
* Open Source Software used:
* - Qt5: Copyright (C) 2019 The Qt Company
***************************************************************************************/

/**
 * Copyright (C) 2018 Espros Photonics Corporation
 *
 * @defgroup communication_constants Communication Constants
 * @ingroup communication
 *
 * @brief Constants needed for communication on the firmware and on the PC.
 *
 * @{
 */
#ifndef COMMUNICATION_CONSTANTS_H_
#define COMMUNICATION_CONSTANTS_H_

#include <stdint.h>

//! Communication constants
/*!
 * Constants needed for communication on the firmware and on the PC.
 */
namespace CommunicationConstants
{
  namespace CommandList
  {
    const uint16_t COMMAND_SET_ROI = 0;                                            ///<Set the ROI
    const uint16_t COMMAND_SET_INT_TIMES = 1;                                      ///<Set the integration times (all at once)
    const uint16_t COMMAND_GET_DISTANCE_AMPLITUDE = 2;                             ///<Get distance and amplitude (single or stream)
    const uint16_t COMMAND_GET_DISTANCE = 3;                                       ///<Get distance (single or stream)
    const uint16_t COMMAND_GET_GRAYSCALE = 5;                                      ///<Get grayscale (single or stream)
    const uint16_t COMMAND_STOP_STREAM = 6;                                        ///<Stop the stream
    const uint16_t COMMAND_GET_CAM1_DATA = 8;//EDIT
    const uint16_t COMMAND_GET_CAM2_DATA = 9;
    const uint16_t COMMAND_GET_CAM3_DATA = 10;
    const uint16_t COMMAND_GET_CAM4_DATA = 11;
    const uint16_t COMMAND_STREAM_USING_TCP_IP = 13;//EDIT
    const uint16_t COMMAND_STREAM_USING_UDP_IP = 14;
    const uint16_t COMMAND_SET_OFFSET = 20;                                        ///<Set the offset
    const uint16_t COMMAND_SET_MIN_AMPLITUDE = 21;                                 ///<Set the minimal amplitude
    const uint16_t COMMAND_SET_FILTER = 22;                                        ///<Set the filter settings (all at once)
    const uint16_t COMMAND_SET_ALGORITHM = 4;                                      ///<Set the Algorithm settings (all at once)
    const uint16_t COMMAND_SET_MODULATION = 23;                                    ///<Set the modulation settings
    const uint16_t COMMAND_SET_BINNING = 24;                                       ///<Set the binning settings
    const uint16_t COMMAND_SET_HDR = 25;                                           ///<Set the HDR settings
    const uint16_t COMMAND_SET_SHUTTER_MODE = 26;                                  ///<Set the shutter mode
    const uint16_t COMMAND_SET_ABS = 27;                                           ///<Set the ABS (enable/disable)
    const uint16_t COMMAND_SET_COMPENSATION = 28;                                  ///<Set the compensations (enable/disable)
    const uint16_t COMMAND_SET_DLL_STEP = 29;                                      ///<Set the DLL step
    const uint16_t COMMAND_SHUTTER = 100;                                          ///<Force a shutter (in case of external shutter)
    const uint16_t COMMAND_CALIBRATE = 30;                                         ///<Calibrate DRNU
    const uint16_t COMMAND_CALIBRATE_PRODUCTION = 31;                              ///<Calibrate for production
    const uint16_t COMMAND_DELETE_CALIBRATION = 32;                                ///<Delete the calibration data
    const uint16_t COMMAND_DEBUG = 33;                                             ///<Debug command with different sub commands
    const uint16_t COMMAND_CALIBRATE_GRAYSCALE = 34;                               ///<Calibrate Grayscale
    const uint16_t COMMAND_CALIBRATE_AMBIENT_LIGHT = 35;                           ///<Calibrate Ambient Light
    const uint16_t COMMAND_GET_CHIP_INFORMATION= 36;                               ///<Read chip ID and wafer ID
    const uint16_t COMMAND_GET_FIRMWARE_RELEASE = 37;                              ///<Read firmware release
    const uint16_t COMMAND_SET_DATA_IP_ADDRESS = 38;                               ///<Set data ip address
  }

  namespace DataType
  {
    const uint16_t DATA_DISTANCE_AMPLITUDE = 0;
    const uint16_t DATA_DISTANCE = 1;
    const uint16_t DATA_AMPLITUDE = 2;
    const uint16_t DATA_GRAYSCALE = 3;
  }

  namespace AnswerType
  {
    const uint32_t INDEX = 0;
    const uint8_t ANSWER_ACK = 0;
    const uint8_t ANSWER_ERROR = 1;
    const uint8_t ANSWER_FIRMWARE_RELEASE = 2;
    const uint8_t ANSWER_CHIP_INFORMATION = 3;
  }

  namespace Answer
  {
    const uint32_t SIZE = 1;
  }

  namespace Command
  {
    const uint32_t INDEX = 0;                                                      ///<Index of the commands
    const uint32_t SIZE = 2;                                                       ///<Size of the commands
    const uint32_t INDEX_DATA = 2;                                                 ///<Index where the data of the command starts
  }

  namespace CommandData
  {
    namespace Filter
    {
      const uint32_t INDEX_TEMPORAL_FILTER_FACTOR = 2;                               ///<Factor for the temporal filter
      const uint32_t INDEX_TEMPORAL_FILTER_THRESHOLD = 4;                            ///<Threshold for the temporal filter
      const uint32_t INDEX_MEDIAN_FILTER_ENABLED = 6;                                ///<Flag to enable/disable the median filter
      const uint32_t INDEX_AVERAGE_FILTER_ENABLED = 7;                               ///<Flag to enable/disable the average filter
      const uint32_t INDEX_EDGE_DETECTION_THRESHOLD = 8;                             ///<Threshold to setup the edge detection
      const uint32_t INDEX_INTERFERENCE_DETECTION_USE_LAST_VALUE = 10;               ///<Flag to select if the last valid value should be used in case of interference
      const uint32_t INDEX_INTERFERENCE_DETECTION_LIMIT = 11;                        ///<Interference detection limit
      const uint32_t INDEX_TEMPORAL_EDGE_FILTER_THRESHOLD_LOW = 13;                  ///<Lower threshold for temporal edge filter
      const uint32_t INDEX_TEMPORAL_EDGE_FILTER_THRESHOLD_HIGH = 15;                 ///<Higher threshold for temporal edge filter
      const uint32_t SIZE = 15;                                                      ///<Size of the data
    }
    namespace Algorithm
    {
    const uint32_t INDEX_SKELETON_DETECTION_ENABLED = 2;
    const uint32_t INDEX_MOVEMENT_DETECTION_WINDOW_SIZE = 3;
    const uint32_t INDEX_MOVEMENT_DETECTION_IMAGE_TYPE = 5;
    const uint32_t SIZE = 6;                                                       ///<Size of the data

    }
    namespace Modulation
    {
      const uint32_t INDEX_FREQUENCY= 2;                                             ///<Index for the modulation frequency
      const uint8_t VALUE_12MHZ = 0;                                                 ///<Value for 12MHz for command "COMMAND_SET_MODULATION"
      const uint8_t VALUE_24MHZ = 1;                                                 ///<Value for 24MHz for command "COMMAND_SET_MODULATION"
      const uint8_t VALUE_6MHZ = 2;                                                  ///<Value for 6MHz for command "COMMAND_SET_MODULATION"
      const uint8_t VALUE_3MHZ = 3;                                                  ///<Value for 3MHz for command "COMMAND_SET_MODULATION"
      const uint8_t VALUE_1_5MHZ = 4;                                                ///<Value for 1.5MHz for command "COMMAND_SET_MODULATION"
      const uint8_t VALUE_0_75MHZ = 5;                                               ///<Value for 0.75MHz for command "COMMAND_SET_MODULATION"
      const uint8_t VALUE_UNKNOWN = 0xFF;                                            ///<Value for unknown modulation frequency
      const uint32_t INDEX_CHANNEL = 3;                                              ///<Index for the modulation channel
      const uint32_t INDEX_CHANNEL_HOPPING = 4;                                      ///<Index for the Channel automatic hopping
      const uint32_t SIZE = 3;                                                       ///<Size of the data
    }

    namespace Binning
    {
      const uint32_t INDEX = 2;                                                      ///<Index of the binning enum
      const uint32_t VALUE_NO_BINNING = 0;                                           ///<Enum value for no binning
      const uint32_t VALUE_BINNING_VERTICAL = 1;                                     ///<Enum value for vertical binning
      const uint32_t VALUE_BINNING_HORIZONTAL = 2;                                   ///<Enum value for horizontal binning
      const uint32_t VALUE_BINNING_BOTH = 3;                                         ///<Enum value for horizontal and vertical binning
      const uint32_t SIZE = 1;                                                       ///<Size of the data
    }

    namespace Hdr
    {
      const uint32_t INDEX = 2;                                                      ///<Index of the HDR enum
      const uint32_t SIZE = 1;                                                       ///<Size of the data
    }

    namespace Roi
    {
      const uint32_t INDEX_X0 = 2;                                                   ///<Index of the x0 coordinate
      const uint32_t INDEX_Y0 = 4;                                                   ///<Index of the y0 coordinate
      const uint32_t INDEX_X1 = 6;                                                   ///<Index of the x1 coordinate
      const uint32_t INDEX_Y1 = 8;                                                   ///<Index of the y1 coordinate
      const uint32_t SIZE = 8;                                                       ///<Size of the data
    }

    namespace ShutterMode
    {
      const uint32_t INDEX = 2;                                                      ///<Index of the shutter mode byte
      const uint32_t SIZE = 1;                                                       ///<Size of the data
    }

    namespace Abs
    {
      const uint32_t INDEX = 2;                                                      ///<Index of the ABS flag byte
      const uint32_t SIZE = 1;                                                       ///<Size of the data
    }

    namespace Amplitude
    {
      const uint32_t INDEX_AMPLITUDE_0 = 2;                                          ///<Index of the minimal amplitude
      const uint32_t SIZE = 2;                                                       ///<Size of the data
    }

    namespace IntegrationTime
    {
      const uint32_t INDEX_INTEGRATION_TIME_3D = 2;                                  ///<Index (start index) of the integration time 3D
      const uint32_t INDEX_INTEGRATION_TIME_GRAYACALE = 8;                           ///<Index of the integration time
      const uint32_t SIZE = 8;                                                       ///<Size of the data
    }

    namespace Offset
    {
      const uint32_t INDEX_OFFSET = 2;                                               ///<Index of the offset
      const uint32_t SIZE = 2;                                                       ///<Size of the data
    }

    namespace DrnuCalibration
    {
      const uint32_t INDEX_VALIDATE_ONLY = 2;                                        ///<Index for flag validate only
      const uint32_t INDEX_OFFSET_ONLY = 3;                                          ///<Index for flag offset only
      const uint32_t INDEX_CALIBRATION_INDEX = 4;                                    ///<Index for calibration index
    }

    namespace Compensation
    {
      const uint32_t INDEX_DRNU_COMPENSATION_ENABLED = 2;                            ///<Index for flag drnu compensation enabled
      const uint32_t INDEX_TEMPERATURE_COMPENSATION_ENABLED = 3;                     ///<Index for flag temperature compensation enabled
      const uint32_t INDEX_AMBIENT_LIGHT_COMPENSATION_ENABLED = 4;                   ///<Index for flag ambient light compensation enabled
      const uint32_t INDEX_GRAYSCALE_COMPENSATION_ENABLED = 5;                       ///<Index for flag grayscale compensation enabled
      const uint32_t SIZE = 4;
    }

    namespace DllStep
    {
      const uint32_t INDEX = 2;                                                      ///<Index of the DLL step
      const uint32_t SIZE = 1;                                                       ///<Size of the data
    }
	}

  namespace AnswerData
  {
    namespace Acknowledge
    {
      const uint32_t SIZE = 0;
    }

    namespace Error
    {
      const uint32_t INDEX = 1;
      const uint32_t SIZE = 2;
    }

    namespace FirmwareRelease
    {
      const uint32_t INDEX = 1;
      const uint32_t SIZE = 4;
    }

    namespace ChipInformation
    {
      const uint32_t INDEX_WAFER_ID = 1;
      const uint32_t INDEX_CHIP_ID = 3;
      const uint32_t SIZE = 4;
    }
  }

  namespace Header
  {
    const uint32_t SIZE = 80;                                                      ///<Number of bytes for the header
    const uint32_t INDEX_VERSION = 0;                                              ///<Index of the header version
    const uint32_t INDEX_TYPE = 1;                                                 ///<Index of the data type
    const uint32_t INDEX_WIDTH = 3;                                                ///<Index of the width
    const uint32_t INDEX_HEIGHT = 5;                                               ///<Index of the height
    const uint32_t INDEX_ORIGIN_X = 7;                                             ///<Index of the origin X
    const uint32_t INDEX_ORIGIN_Y = 9;                                             ///<Index of the origin y
    const uint32_t INDEX_INTEGRATION_TIME_3D_0 = 15;                               ///<Index of the integration time 3D 0
    const uint32_t INDEX_INTEGRATION_TIME_3D_1 = 17;                               ///<Index of the integration time 3D 1
    const uint32_t INDEX_DATA_OFFSET = 23;                                         ///<Index of the data offset = offset where the measurement data starts
    const uint32_t INDEX_USER_DATA = 25;                                           ///<Index of the user data
  }
};

#endif /* COMMUNICATION_CONSTANTS_H_ */
