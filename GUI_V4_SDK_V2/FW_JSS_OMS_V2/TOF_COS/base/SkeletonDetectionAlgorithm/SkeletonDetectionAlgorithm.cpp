/***
 * Copyright (C) 2019 Espros Photonics Corporation
 *
 * @addtogroup edge_filter
 */
#include <stdlib.h>
#include <math.h>
#include <SkeletonDetectionAlgorithm/SkeletonDetectionAlgorithm.h>
/**
 * @brief Constructor
 *
 */
SkeletonDetectionAlgorithm::SkeletonDetectionAlgorithm()
{
enable = false;
}

bool SkeletonDetectionAlgorithm::isEnabled() const
{
return enable;
}


uint16_t SkeletonDetectionAlgorithm::calcPixelValue(const uint32_t pixel_value, uint32_t index)
{
//Skeleton Detection code
}
