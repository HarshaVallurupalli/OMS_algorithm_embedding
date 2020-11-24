/**
 * Copyright (C) 2018 Espros Photonics Corporation
 *
 *
 * @addtogroup quicksort
 *
 * @{
 */
#include "QuickSort.h"

/**
 * @brief Sort array
 *
 *
 * @param arr Array to sort
 * @param elements Number of elements in the array
 * @retval true All values sorted
 * @retval false Not all values sorted
 * @return Values sorted or not
 */
bool QuickSort::quickSort(uint32_t *arr, uint32_t elements)
{

#define  MAX_LEVELS  16

	int32_t piv, beg[MAX_LEVELS], end[MAX_LEVELS], i = 0, L, R;

	beg[0] = 0;
	end[0] = elements;
	while (i >= 0)
	{
		L = beg[i];
		R = end[i] - 1;
		if (L < R)
		{
			piv = arr[L];
			if (i == MAX_LEVELS - 1)
			{
				return false;
			}
			while (L < R)
			{
				while (arr[R] >= piv && L < R)
				{
					R--;
				}
				if (L < R)
				{
					arr[L++] = arr[R];
				}
				while (arr[L] <= piv && L < R)
				{
					L++;
				}
				if (L < R)
				{
					arr[R--] = arr[L];
				}
			}
			arr[L] = piv;
			beg[i + 1] = L + 1;
			end[i + 1] = end[i];
			end[i++] = L;
		}
		else
		{
			i--;
		}
	}
	return true;
}

/** @} */
