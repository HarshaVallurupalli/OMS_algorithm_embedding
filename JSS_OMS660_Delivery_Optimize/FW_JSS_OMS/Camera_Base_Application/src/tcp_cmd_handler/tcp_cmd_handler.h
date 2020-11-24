/**
 * Copyright (C) 2017 Espros Photonics Corporation
 *
 * @defgroup tcp_cmd_handler TCP Command Handler
 *
 * @brief Executes commands received over tcp connection
 *
 * @{
 */
#ifndef SRC_TCP_CMD_HANDLER_TCP_CMD_HANDLER_H_
#define SRC_TCP_CMD_HANDLER_TCP_CMD_HANDLER_H_

int32_t tcpCmdHandlerStart(const uint16_t port);
bool tcpCmdHandlerProcess(void);
bool tcpCmdHandlerConnectionIsOpen(void);

#endif /* SRC_TCP_CMD_HANDLER_TCP_CMD_HANDLER_H_ */

/** @} */
