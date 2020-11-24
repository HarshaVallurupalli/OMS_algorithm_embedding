/**
 * Copyright (C) 2019 Espros Photonics Corporation
 *
 * @defgroup queue Queue
 * @brief Generic queue for different data types
 * @ingroup application
 *
 * @{
 */
#ifndef QUEUE_H_
#define QUEUE_H_

#include <stdint.h>

template <class T>
class Queue
{
	public:
		static const uint8_t NUM_ELEMENTS = 8;
		Queue()
		{
			indexPush = 0;
			indexPop = 0;
		}
		bool empty();
		T pop();
		void push(T dataToPush);

	private:
		void incIndex(uint32_t &index);

		T data[NUM_ELEMENTS];
		uint32_t indexPush;
		uint32_t indexPop;
};

#include "Queue.tpp"

#endif /* QUEUE_H_ */

/** @} */
