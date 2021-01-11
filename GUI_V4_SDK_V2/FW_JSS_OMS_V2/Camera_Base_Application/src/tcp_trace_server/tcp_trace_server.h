/**
 * Copyright (C) 2018 Espros Photonics Corporation
 *
 * @defgroup tcp_trace_server TCP Trace Server
 *
 * @brief Sends trace commands to the host over TCP
 *
 * @{
 */
#ifndef TCP_TRACE_SERVER_H_
#define TCP_TRACE_SERVER_H_

int tcpTraceServerStart(const uint16_t port);
void tcpTraceServerSend(const char *format, ...);

#endif /* TCP_TRACE_SERVER_H_ */

/** @} */
