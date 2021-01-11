/**
 * Copyright (C) 2016 Espros Photonics Corporation
 *
 * @defgroup io_if Interface
 * @ingroup io
 *
 * @brief Interface for the IO class
 *
 * @{
 */
#ifndef IO_IF_H_
#define IO_IF_H_

//! IO Interface
/*!
 * Interface for the IO class
 */
class IO_IF
{
	public:
    virtual void setPowerEnabled(const bool enabled) = 0;
    virtual void PoweronDaughterBoardPort(const uint8_t port) = 0;

};

#endif /* IO_IF_H_ */

/** @} */
