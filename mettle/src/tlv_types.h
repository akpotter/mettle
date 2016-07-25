/**
 * Copyright 2015 Rapid7
 * @brief Meterpreter-style TLV types
 * @file tlv_types.h
 */

#ifndef _TLV_TYPES_H_
#define _TLV_TYPES_H_

#define TLV_PACKET_TYPE_REQUEST  0
#define TLV_PACKET_TYPE_RESPONSE 1

#define TLV_RESULT_SUCCESS 0
#define TLV_RESULT_FAILURE 1
#define TLV_RESULT_ENOMEM  12
#define TLV_RESULT_EINVAL  22

#define TLV_CHANNEL_CLASS_BUFFERED 0
#define TLV_CHANNEL_CLASS_STREAM   1
#define TLV_CHANNEL_CLASS_DATAGRAM 2
#define TLV_CHANNEL_CLASS_POOL     3

/*
 * TLV Meta Types
 */
#define TLV_META_TYPE_NONE         0
#define TLV_META_TYPE_STRING       (1 << 16)
#define TLV_META_TYPE_UINT         (1 << 17)
#define TLV_META_TYPE_RAW          (1 << 18)
#define TLV_META_TYPE_BOOL         (1 << 19)
#define TLV_META_TYPE_QWORD        (1 << 20)
#define TLV_META_TYPE_COMPRESSED   (1 << 29)
#define TLV_META_TYPE_GROUP        (1 << 30)
#define TLV_META_TYPE_COMPLEX      (1 << 31)

#define TLV_META_TYPE_MASK         0xffff0000

/*
 * TLV base starting points
 */
#define TLV_RESERVED     0
#define TLV_EXTENSIONS   20000
#define TLV_USER         40000
#define TLV_TEMP         60000

/*
 * TLV Specific Types
 */
#define TLV_TYPE_ANY                   (TLV_META_TYPE_NONE    | 0)
#define TLV_TYPE_METHOD                (TLV_META_TYPE_STRING  | 1)
#define TLV_TYPE_REQUEST_ID            (TLV_META_TYPE_STRING  | 2)
#define TLV_TYPE_EXCEPTION             (TLV_META_TYPE_GROUP   | 3)
#define TLV_TYPE_RESULT                (TLV_META_TYPE_UINT    | 4)

#define TLV_TYPE_STRING                (TLV_META_TYPE_STRING  | 10)
#define TLV_TYPE_UINT                  (TLV_META_TYPE_UINT    | 11)
#define TLV_TYPE_BOOL                  (TLV_META_TYPE_BOOL    | 12)

#define TLV_TYPE_LENGTH                (TLV_META_TYPE_UINT    | 25)
#define TLV_TYPE_DATA                  (TLV_META_TYPE_RAW     | 26)
#define TLV_TYPE_FLAGS                 (TLV_META_TYPE_UINT    | 27)

#define TLV_TYPE_CHANNEL_ID            (TLV_META_TYPE_UINT    | 50)
#define TLV_TYPE_CHANNEL_TYPE          (TLV_META_TYPE_STRING  | 51)
#define TLV_TYPE_CHANNEL_DATA          (TLV_META_TYPE_RAW     | 52)
#define TLV_TYPE_CHANNEL_DATA_GROUP    (TLV_META_TYPE_GROUP   | 53)
#define TLV_TYPE_CHANNEL_CLASS         (TLV_META_TYPE_UINT    | 54)
#define TLV_TYPE_CHANNEL_PARENTID      (TLV_META_TYPE_UINT    | 55)

#define TLV_TYPE_SEEK_WHENCE           (TLV_META_TYPE_UINT    | 70)
#define TLV_TYPE_SEEK_OFFSET           (TLV_META_TYPE_UINT    | 71)
#define TLV_TYPE_SEEK_POS              (TLV_META_TYPE_UINT    | 72)

#define TLV_TYPE_EXCEPTION_CODE        (TLV_META_TYPE_UINT    | 300)
#define TLV_TYPE_EXCEPTION_STRING      (TLV_META_TYPE_STRING  | 301)

#define TLV_TYPE_LIBRARY_PATH          (TLV_META_TYPE_STRING  | 400)
#define TLV_TYPE_TARGET_PATH           (TLV_META_TYPE_STRING  | 401)
#define TLV_TYPE_MIGRATE_PID           (TLV_META_TYPE_UINT    | 402)
#define TLV_TYPE_MIGRATE_LEN           (TLV_META_TYPE_UINT    | 403)

#define TLV_TYPE_MACHINE_ID            (TLV_META_TYPE_STRING  | 460)

#define TLV_TYPE_CIPHER_NAME           (TLV_META_TYPE_STRING  | 500)
#define TLV_TYPE_CIPHER_PARAMETERS     (TLV_META_TYPE_GROUP   | 501)

/*
 * General
 */
#define TLV_TYPE_HANDLE                (TLV_META_TYPE_QWORD   | 600)
#define TLV_TYPE_INHERIT               (TLV_META_TYPE_BOOL    | 601)
#define TLV_TYPE_PROCESS_HANDLE        (TLV_META_TYPE_QWORD   | 630)
#define TLV_TYPE_THREAD_HANDLE         (TLV_META_TYPE_QWORD   | 631)

/*
 * Fs
 */
#define TLV_TYPE_DIRECTORY_PATH        (TLV_META_TYPE_STRING  | 1200)
#define TLV_TYPE_FILE_NAME             (TLV_META_TYPE_STRING  | 1201)
#define TLV_TYPE_FILE_PATH             (TLV_META_TYPE_STRING  | 1202)
#define TLV_TYPE_FILE_MODE             (TLV_META_TYPE_STRING  | 1203)
#define TLV_TYPE_FILE_SIZE             (TLV_META_TYPE_UINT    | 1204)
#define TLV_TYPE_FILE_HASH             (TLV_META_TYPE_RAW     | 1206)

#define TLV_TYPE_STAT_BUF              (TLV_META_TYPE_COMPLEX | 1220)

#define TLV_TYPE_SEARCH_RECURSE        (TLV_META_TYPE_BOOL    | 1230)
#define TLV_TYPE_SEARCH_GLOB           (TLV_META_TYPE_STRING  | 1231)
#define TLV_TYPE_SEARCH_ROOT           (TLV_META_TYPE_STRING  | 1232)
#define TLV_TYPE_SEARCH_RESULTS        (TLV_META_TYPE_GROUP   | 1233)

/*
 * Net
 */
#define TLV_TYPE_HOST_NAME             (TLV_META_TYPE_STRING  | 1400)
#define TLV_TYPE_PORT                  (TLV_META_TYPE_UINT    | 1401)
#define TLV_TYPE_INTERFACE_MTU         (TLV_META_TYPE_UINT    | 1402)
#define TLV_TYPE_INTERFACE_FLAGS       (TLV_META_TYPE_STRING  | 1403)
#define TLV_TYPE_INTERFACE_INDEX       (TLV_META_TYPE_UINT    | 1404)

#define TLV_TYPE_SUBNET                (TLV_META_TYPE_RAW     | 1420)
#define TLV_TYPE_NETMASK               (TLV_META_TYPE_RAW     | 1421)
#define TLV_TYPE_GATEWAY               (TLV_META_TYPE_RAW     | 1422)
#define TLV_TYPE_NETWORK_ROUTE         (TLV_META_TYPE_GROUP   | 1423)
#define TLV_TYPE_IP_PREFIX             (TLV_META_TYPE_UINT    | 1424)
#define TLV_TYPE_ARP_ENTRY             (TLV_META_TYPE_GROUP   | 1425)

#define TLV_TYPE_IP                    (TLV_META_TYPE_RAW     | 1430)
#define TLV_TYPE_MAC_ADDRESS           (TLV_META_TYPE_RAW     | 1431)
#define TLV_TYPE_MAC_NAME              (TLV_META_TYPE_STRING  | 1432)
#define TLV_TYPE_NETWORK_INTERFACE     (TLV_META_TYPE_GROUP   | 1433)
#define TLV_TYPE_IP6_SCOPE             (TLV_META_TYPE_RAW     | 1434)

#define TLV_TYPE_SUBNET_STRING         (TLV_META_TYPE_STRING  | 1440)
#define TLV_TYPE_NETMASK_STRING        (TLV_META_TYPE_STRING  | 1441)
#define TLV_TYPE_GATEWAY_STRING        (TLV_META_TYPE_STRING  | 1442)
#define TLV_TYPE_ROUTE_METRIC          (TLV_META_TYPE_UINT    | 1443)
#define TLV_TYPE_ADDR_TYPE             (TLV_META_TYPE_UINT    | 1444)

#define TLV_TYPE_PROXY_CFG_AUTODETECT    (TLV_META_TYPE_BOOL  | 1445)
#define TLV_TYPE_PROXY_CFG_AUTOCONFIGURL (TLV_META_TYPE_STRING| 1446)
#define TLV_TYPE_PROXY_CFG_PROXY         (TLV_META_TYPE_STRING| 1447)
#define TLV_TYPE_PROXY_CFG_PROXYBYPASS   (TLV_META_TYPE_STRING| 1448)

/*
 * Socket
 */
#define TLV_TYPE_PEER_HOST             (TLV_META_TYPE_STRING  | 1500)
#define TLV_TYPE_PEER_PORT             (TLV_META_TYPE_UINT    | 1501)
#define TLV_TYPE_LOCAL_HOST            (TLV_META_TYPE_STRING  | 1502)
#define TLV_TYPE_LOCAL_PORT            (TLV_META_TYPE_UINT    | 1503)
#define TLV_TYPE_CONNECT_RETRIES       (TLV_META_TYPE_UINT    | 1504)
#define TLV_TYPE_NETSTAT_ENTRY         (TLV_META_TYPE_GROUP   | 1505)
#define TLV_TYPE_PEER_HOST_RAW         (TLV_META_TYPE_RAW     | 1506)
#define TLV_TYPE_LOCAL_HOST_RAW        (TLV_META_TYPE_RAW     | 1507)

#define TLV_TYPE_SHUTDOWN_HOW          (TLV_META_TYPE_UINT    | 1530)

/*
 * Registry
 */
#define TLV_TYPE_HKEY                  (TLV_META_TYPE_QWORD   | 1000)
#define TLV_TYPE_ROOT_KEY              (TLV_TYPE_HKEY)
#define TLV_TYPE_BASE_KEY              (TLV_META_TYPE_STRING  | 1001)
#define TLV_TYPE_PERMISSION            (TLV_META_TYPE_UINT    | 1002)
#define TLV_TYPE_KEY_NAME              (TLV_META_TYPE_STRING  | 1003)
#define TLV_TYPE_VALUE_NAME            (TLV_META_TYPE_STRING  | 1010)
#define TLV_TYPE_VALUE_TYPE            (TLV_META_TYPE_UINT    | 1011)
#define TLV_TYPE_VALUE_DATA            (TLV_META_TYPE_RAW     | 1012)
#define TLV_TYPE_TARGET_HOST           (TLV_META_TYPE_STRING  | 1013)

/*
 * Config
 */
#define TLV_TYPE_COMPUTER_NAME         (TLV_META_TYPE_STRING  | 1040)
#define TLV_TYPE_OS_NAME               (TLV_META_TYPE_STRING  | 1041)
#define TLV_TYPE_USER_NAME             (TLV_META_TYPE_STRING  | 1042)
#define TLV_TYPE_ARCHITECTURE          (TLV_META_TYPE_STRING  | 1043)
#define TLV_TYPE_SID                   (TLV_META_TYPE_STRING  | 1045)

/*
 * Environment
 */
#define TLV_TYPE_ENV_VARIABLE          (TLV_META_TYPE_STRING  | 1100)
#define TLV_TYPE_ENV_VALUE             (TLV_META_TYPE_STRING  | 1101)
#define TLV_TYPE_ENV_GROUP             (TLV_META_TYPE_GROUP   | 1102)

#define DELETE_KEY_FLAG_RECURSIVE      (1 << 0)

/*
 * Process
 */
#define TLV_TYPE_BASE_ADDRESS          (TLV_META_TYPE_QWORD   | 2000)
#define TLV_TYPE_ALLOCATION_TYPE       (TLV_META_TYPE_UINT    | 2001)
#define TLV_TYPE_PROTECTION            (TLV_META_TYPE_UINT    | 2002)
#define TLV_TYPE_PROCESS_PERMS         (TLV_META_TYPE_UINT    | 2003)
#define TLV_TYPE_PROCESS_MEMORY        (TLV_META_TYPE_RAW     | 2004)
#define TLV_TYPE_ALLOC_BASE_ADDRESS    (TLV_META_TYPE_QWORD   | 2005)
#define TLV_TYPE_MEMORY_STATE          (TLV_META_TYPE_UINT    | 2006)
#define TLV_TYPE_MEMORY_TYPE           (TLV_META_TYPE_UINT    | 2007)
#define TLV_TYPE_ALLOC_PROTECTION      (TLV_META_TYPE_UINT    | 2008)
#define TLV_TYPE_PID                   (TLV_META_TYPE_UINT    | 2300)
#define TLV_TYPE_PROCESS_NAME          (TLV_META_TYPE_STRING  | 2301)
#define TLV_TYPE_PROCESS_PATH          (TLV_META_TYPE_STRING  | 2302)
#define TLV_TYPE_PROCESS_GROUP         (TLV_META_TYPE_GROUP   | 2303)
#define TLV_TYPE_PROCESS_FLAGS         (TLV_META_TYPE_UINT    | 2304)
#define TLV_TYPE_PROCESS_ARGUMENTS     (TLV_META_TYPE_STRING  | 2305)
#define TLV_TYPE_PROCESS_ARCH          (TLV_META_TYPE_UINT    | 2306)
#define TLV_TYPE_PARENT_PID            (TLV_META_TYPE_UINT    | 2307)
#define TLV_TYPE_PROCESS_ARCH_NAME     (TLV_META_TYPE_STRING  | 2309)

#define TLV_TYPE_IMAGE_FILE            (TLV_META_TYPE_STRING  | 2400)
#define TLV_TYPE_IMAGE_FILE_PATH       (TLV_META_TYPE_STRING  | 2401)
#define TLV_TYPE_PROCEDURE_NAME        (TLV_META_TYPE_STRING  | 2402)
#define TLV_TYPE_PROCEDURE_ADDRESS     (TLV_META_TYPE_QWORD   | 2403)
#define TLV_TYPE_IMAGE_BASE            (TLV_META_TYPE_QWORD   | 2404)
#define TLV_TYPE_IMAGE_GROUP           (TLV_META_TYPE_GROUP   | 2405)
#define TLV_TYPE_IMAGE_NAME            (TLV_META_TYPE_STRING  | 2406)

#define TLV_TYPE_THREAD_ID             (TLV_META_TYPE_UINT    | 2500)
#define TLV_TYPE_THREAD_PERMS          (TLV_META_TYPE_UINT    | 2502)
#define TLV_TYPE_EXIT_CODE             (TLV_META_TYPE_UINT    | 2510)
#define TLV_TYPE_ENTRY_POINT           (TLV_META_TYPE_QWORD   | 2511)
#define TLV_TYPE_ENTRY_PARAMETER       (TLV_META_TYPE_QWORD   | 2512)
#define TLV_TYPE_CREATION_FLAGS        (TLV_META_TYPE_UINT    | 2513)

#define TLV_TYPE_REGISTER_NAME         (TLV_META_TYPE_STRING  | 2540)
#define TLV_TYPE_REGISTER_SIZE         (TLV_META_TYPE_UINT    | 2541)
#define TLV_TYPE_REGISTER_VALUE_32     (TLV_META_TYPE_UINT    | 2542)
#define TLV_TYPE_REGISTER              (TLV_META_TYPE_GROUP   | 2550)

/*
 * Ui
 */
#define TLV_TYPE_IDLE_TIME             (TLV_META_TYPE_UINT    | 3000)
#define TLV_TYPE_KEYS_DUMP             (TLV_META_TYPE_STRING  | 3001)
#define TLV_TYPE_DESKTOP               (TLV_META_TYPE_STRING  | 3002)

/*
 * Event Log
 */
#define TLV_TYPE_EVENT_SOURCENAME      (TLV_META_TYPE_STRING  | 4000)
#define TLV_TYPE_EVENT_HANDLE          (TLV_META_TYPE_QWORD   | 4001)
#define TLV_TYPE_EVENT_NUMRECORDS      (TLV_META_TYPE_UINT    | 4002)

#define TLV_TYPE_EVENT_READFLAGS       (TLV_META_TYPE_UINT    | 4003)
#define TLV_TYPE_EVENT_RECORDOFFSET    (TLV_META_TYPE_UINT    | 4004)

#define TLV_TYPE_EVENT_RECORDNUMBER    (TLV_META_TYPE_UINT    | 4006)
#define TLV_TYPE_EVENT_TIMEGENERATED   (TLV_META_TYPE_UINT    | 4007)
#define TLV_TYPE_EVENT_TIMEWRITTEN     (TLV_META_TYPE_UINT    | 4008)
#define TLV_TYPE_EVENT_ID              (TLV_META_TYPE_UINT    | 4009)
#define TLV_TYPE_EVENT_TYPE            (TLV_META_TYPE_UINT    | 4010)
#define TLV_TYPE_EVENT_CATEGORY        (TLV_META_TYPE_UINT    | 4011)
#define TLV_TYPE_EVENT_STRING          (TLV_META_TYPE_STRING  | 4012)
#define TLV_TYPE_EVENT_DATA            (TLV_META_TYPE_RAW     | 4013)

/*
 * Power
 */
#define TLV_TYPE_POWER_FLAGS           (TLV_META_TYPE_UINT    | 4100)
#define TLV_TYPE_POWER_REASON          (TLV_META_TYPE_UINT    | 4101)

/*
 * Sys
 */
#define PROCESS_EXECUTE_FLAG_HIDDEN            (1 << 0)
#define PROCESS_EXECUTE_FLAG_CHANNELIZED       (1 << 1)
#define PROCESS_EXECUTE_FLAG_SUSPENDED         (1 << 2)
#define PROCESS_EXECUTE_FLAG_USE_THREAD_TOKEN  (1 << 3)

#define PROCESS_ARCH_UNKNOWN    0
#define PROCESS_ARCH_X86        1
#define PROCESS_ARCH_X64        2
#define PROCESS_ARCH_IA64       3

#endif
