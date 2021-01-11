/**
 * Copyright (C) 2018 Espros Photonics Corporation
 *
 * @addtogroup queue
 */
template<class T>
bool Queue<T>::empty()
{
	if (indexPush == indexPop)
	{
		return true;
	}

	return false;
}

template<class T>
T Queue<T>::pop()
{
	T toReturn = data[indexPop];
	incIndex (indexPop);
	return toReturn;
}

template<class T>
void Queue<T>::push(T dataToPush)
{
	data[indexPush] = dataToPush;
	incIndex (indexPush);
}

template<class T>
void Queue<T>::incIndex(uint32_t &index)
{
	index++;
	if (index >= NUM_ELEMENTS)
	{
		index = 0;
	}
}

/** @} */
