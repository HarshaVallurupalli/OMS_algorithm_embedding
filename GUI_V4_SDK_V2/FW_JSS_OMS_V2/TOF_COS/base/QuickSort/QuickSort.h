/**
 * Copyright (C) 2019 Espros Photonics Corporation
 *
 * @defgroup quicksort Quicksort
 * @ingroup tof_cos
 *
 * @brief Quicksort without recursion on uint32_t array
 *
 * @{
 */
#ifndef QUICKSORT_H_
#define QUICKSORT_H_

#include <stdint.h>

class QuickSort
{
	public:
		static bool quickSort(uint32_t *arr, uint32_t elements);
};

#endif /* QUICKSORT_H_ */

/** @} */
