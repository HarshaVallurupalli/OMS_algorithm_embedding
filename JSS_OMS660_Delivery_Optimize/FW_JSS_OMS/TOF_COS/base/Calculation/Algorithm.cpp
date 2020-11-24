#include <Calculation/Algorithm.h>
#include <MovementDetectionAlgorithm/MovementDetectionAlgorithm.h>


//Masks for the filter enable
const uint8_t MASK_MOVEMENT_DETECTION = 0x01;
const uint8_t MASK_Algorithm2 = 0x02;
const uint8_t MASK_Algorithm3 = 0x04;
const uint8_t MASK_Algorithm4 = 0x08;
const uint8_t MASK_Algorithm5 = 0x10;

///Helper enum to call the filter functions
enum
{
	NO_ALGORITHM,
	MOVEMENT_DETECTION_ALGORITHM = MASK_MOVEMENT_DETECTION,
	Algorithm2=MASK_Algorithm2,
	Algorithm3=MASK_Algorithm3,
	Algorithm4=MASK_Algorithm4,
	Algorithm5=MASK_Algorithm5,
};

Algorithm::Algorithm()
{
	enable=false;
	AlgorithmSelector = 0;
	interferenceUseLastValueEnabled = false;
}

void Algorithm::setMovementDetectionSettings(const uint16_t WindowSize)
{
	movementDetectionAlgorithm.setWindowSize(WindowSize);

	bool MovementDetectionAlgorithmEnabled = movementDetectionAlgorithm.isEnabled();
	if (MovementDetectionAlgorithmEnabled)
	{
		AlgorithmSelector |= MASK_MOVEMENT_DETECTION;
	}
	else
	{
		AlgorithmSelector &= ~MASK_MOVEMENT_DETECTION;
	}
}

bool Algorithm::getMovementDetectionEnabled() const
{
	return (AlgorithmSelector & MASK_MOVEMENT_DETECTION);
}


void Algorithm::processAlgorithm(PixelToF_Distance *pDistance, const PixelToF_Distance *pLastDistance, const CalculationParameters &parameters, CalculationResults &results)
{
	processAlgorithm<PixelToF_Distance>(pDistance, pLastDistance, parameters, results);
}


void Algorithm::processAlgorithm(PixelToF_DistanceAmplitude *pDistanceAmplitude, const PixelToF_DistanceAmplitude *pLastDistanceAmplitude, const CalculationParameters &parameters, CalculationResults &results)
{
	processAlgorithm<PixelToF_DistanceAmplitude>(pDistanceAmplitude, pLastDistanceAmplitude, parameters, results);
}

void Algorithm::processAlgorithm(PixelToF_DistanceGrayscale *pDistanceGrayscale, const PixelToF_DistanceGrayscale *pLastDistanceGrayscale, const CalculationParameters &parameters, CalculationResults &results)
{
	processAlgorithm<PixelToF_DistanceGrayscale>(pDistanceGrayscale, pLastDistanceGrayscale, parameters, results);
}


template <typename T> void Algorithm::processAlgorithm
(
  T *pData,
	const T *pLastData,
	const CalculationParameters &parameters,
	CalculationResults &results
)
{

	switch(AlgorithmSelector)
	{
	  case NO_ALGORITHM:
		  if (interferenceUseLastValueEnabled)
		  {
			  runInterferenceDetection(pData, pLastData, parameters, results);
		  }
		  break;
	  case MOVEMENT_DETECTION_ALGORITHM:
	  	  {
	  		  runMovementDetectionAlgorithm(pData, pLastData, parameters, results);
	  	  }
	  		  break;
	  case Algorithm2:
		  //run Algorithm 2
		  break;
	  case Algorithm3:
		  //run Algorithm 3
		  break;
	  case Algorithm4:
		  //run Algorithm 4
		  break;
	  case Algorithm5:
		  //run Algorithm 5
		  break;
	  default:
		  runGenericAlgorithm(pData, pLastData, parameters, results);
	  	break;
	}
}


template <typename T> void Algorithm::runMovementDetectionAlgorithm(T *pData, const T *pLastData, const CalculationParameters &parameters, CalculationResults &results)
{
  uint32_t numPixel = parameters.acquisitionInfo.getNumPixel();
  int32_t minDistance = 100000;

  for (uint32_t i = 0; i < numPixel; i++)
  {
		  uint16_t distance = pData[i].getDistance();

		  if (distance < TypePixelCode::PIXEL_CODE_LIMIT_FOR_VALID_DATA)
		  {
		  	distance = movementDetectionAlgorithm.calcPixelValue(distance,i);

			  pData[i].setDistance(distance);
		  }
		  else if (distance == TypePixelCode::PIXEL_CODE_INTERFERENCE)
			{
				if ((interferenceUseLastValueEnabled) && (pLastData[i].isInvalid() == false))
				{
					pData[i] = pLastData[i];
				}
			}

		  if (distance < minDistance)
			{
				minDistance = distance;
			}

	  }

	results.minDistance = minDistance;
}




template <typename T> void Algorithm::runGenericAlgorithm(T *pData, const T *pLastData, const CalculationParameters &parameters, CalculationResults &results)
{
	uint16_t width = parameters.acquisitionInfo.getWidth();
	uint16_t height = parameters.acquisitionInfo.getFinalHeight();
	int32_t minDistance = 100000;
	int32_t indexList[9];


	uint32_t index = 0;
	initIndexes(indexList, width);

  for (uint16_t y = 0; y < height; y++)
  {
  	for (uint16_t x = 0; x < width; x++)
		{
  		uint32_t distance = pData[index].getDistance();
  		uint32_t lastDistance = pLastData[index].getDistance();


  		//Check again because the temporal edge filter may remove the pixel
  		if (distance < TypePixelCode::PIXEL_CODE_LIMIT_FOR_VALID_DATA)
  		{
  			if (AlgorithmSelector & MASK_MOVEMENT_DETECTION)
  		  {
  			  	distance = movementDetectionAlgorithm.calcPixelValue(distance,index);
  		  }

  		  if (AlgorithmSelector & MASK_Algorithm2)
		  {
  			  //run Algorithm 2
		  }

  		  if (AlgorithmSelector & MASK_Algorithm3)
  		  {
  			  //run Algorithm 3
  		  }

  		  if (AlgorithmSelector & MASK_Algorithm4)
  		  {
  			  //run Algorithm 4
  		  }

			  pData[index].setDistance(distance);
		  }
  		else if (distance == TypePixelCode::PIXEL_CODE_INTERFERENCE)
  		{
  		  if ((interferenceUseLastValueEnabled) && (pLastData[index].isInvalid() == false))
  		  {
  			  pData[index] = pLastData[index];
  			}
  		}

  		if (distance < minDistance)
  		{
  		  minDistance = distance;
  		}

		  incIndexes(indexList);

		  index++;
	  }
  }

	results.minDistance = minDistance;
}

template <typename T> void Algorithm::runInterferenceDetection(T *pData, const T *pLastData, const CalculationParameters &parameters, CalculationResults &results)
{
	uint16_t width = parameters.acquisitionInfo.getWidth();
	uint16_t height = parameters.acquisitionInfo.getFinalHeight();
	int32_t minDistance = 100000;


  uint32_t index = 0;

  for (uint16_t y = 0; y < height; y++)
  {
  	for (uint16_t x = 0; x < width; x++)
		{
  		uint32_t distance = pData[index].getDistance();

  		if (distance == TypePixelCode::PIXEL_CODE_INTERFERENCE)
  		{
  		  if (pLastData[index].isInvalid() == false)
  		  {
  			  pData[index] = pLastData[index];
  			}
  		}

  		if (distance < minDistance)
  		{
  		  minDistance = distance;
  		}

		  index++;
	  }
  }

	results.minDistance = minDistance;
}

/**
 * @brief Create an index list for all filters.
 *
 *
 * The index list is like this:
 *     |0|1|2|
 *     |3|4|5|
 *     |6|7|8|
 *
 * It contains the indexes for 9 Pixels. The current pixel is the middle one (number 4)
 * - Median filter uses all of them
 * - Average filter uses 4, 5, 7, 8
 * - Edge filter uses 4, 5, 7
 *
 * On the rows/columns at the border of the image not all filters are possible, e.g. at pixel 0 values 0, 1, 2, 3, 6 are not available.
 * It's the responsibility of the filter function to handle these situations. Here just the indexes are filled and in such situations they
 * can get negative.
 *
 * The purpose of this is to reuse the indexes for all filters.
 *
 * @param pIndexList Pointer to the index list array, always 9 elements
 * @param width Width of the image
 */
void Algorithm::initIndexes(int32_t *pIndexList, const uint32_t width)
{
	pIndexList[0] = -(width) - 1;
	pIndexList[1] = -(width);
	pIndexList[2] = -(width) + 1;
	pIndexList[3] = -1;
	pIndexList[4] = 0;
	pIndexList[5] = 1;
	pIndexList[6] = width - 1;
	pIndexList[7] = width;
	pIndexList[8] = width + 1;
}

/**
 * @brief Increment all indexes
 *
 * To be called after every filter loop. Increments each of the indexes in the index list.
 *
 * @param pIndexList Pointer to the index list array, always 9 elements
 */
void Algorithm::incIndexes(int32_t *pIndexList)
{
  for (uint8_t i = 0; i < 9; i++)
	{
  	pIndexList[i]++;
	}
}



/** @} */
