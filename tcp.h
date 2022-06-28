
/**
 *  @file  tcp.h
 *  @brief The header file include all functions used in program and some enums
 *
 */

#if !defined TCP_H_INCLUDED
#define TCP_H_INCLUDED

#include <stdio.h>


#define MAX_BUFFER_SIZE        1024   /**< max buffer size that server will receive by using recv() function */
#define MAX_UNSIGNED_SHORT_VAL 65535  /**< max unsigned short type value is 2 ^ 16 - 1 = 65535 */

#define DEFAULT_PROTOCOL       0 /**< used as third argument of  socket() function */
#define SEND_FLAGS             0 /**< flags used in send() function */
#define RECV_FLAGS             0 /**< flags used in recv() function */

#define DEFAULT_PORT 80              /**< default port value */
#define DEFAULT_IP   INADDR_LOOPBACK /**< default ip. INADDR_LOOPBACK is localhost ip. */


enum CLIENT_ERRORS {
        INCORRECT_ARG_NUM    = -5,  /**< return value of client_cli() or server_cli() if incorrect number
                                     * of arguments was passed */
        SERVER_ERROR         = -4,  /**< return value of server_start() if error was detected */
        INCORRECT_PORT       = -3,  /**< return value of client_cli() if incorrect port was passed */
        INCORRECT_IP         = -2,  /**< return value of client_cli() if incorrect ip was passed  */
        CLIENT_CONNECT_ERROR = -1,  /**< code of client error that will returned in client_connect() function */
        INCORRECT_SOCKET     = -1,  /**< if socket() function get error it return -1 */
};

enum CLI_ARGS_COUNT {
        USR_CLI_DEFAULT_IP_N_PORT = 2, /**< the value 2 is argument count passed through command line. If the
                                        * program work like a client, that it require 4 arguments (first 
                                        * argument - the executable name, second is flag to indetify, that 
                                        * program working as a client (--client), third - ip address, fourth -
                                        * port. But last two arguments can be omitted. The default ip address
                                        * 127.0.0.1 (localhost), default port - 80. */

        USR_CLI_DEFAULT_PORT      = 3, /**< 3 arguments passed, the only missing one in port.
                                        * Default port is 80. @see USR_CLI_DEFAULT_IP_N_PORT */
        USR_ALL_ARGS_PASSED       = 4, /**< 4 arguments passed, including ip address and port number. @see USR_CLI_DEFAULT_IP_N_PORT */
        SERVER_CLI_DEFAULT_PORT   = 2, /**< 2 arguments passed. If the program work as a server, that it require 3 arguments:
                                        *   first one is executable name, second is flag to indetify, that
                                        *   program working as a server (--server), third - port number. But last one can be ommited.
                                        *   The port will be set to default value - 80.
                                        */
        SERVER_ALL_ARGS_PASSED    = 3  /**< 3 arguments passed, including port number. @see SERVER_CLI_DEFAULT_PORT */
};



/** @brief function that use TCP protocol to connect to network with passed ip and port
 *  @param ip_addr ip address to connect
 *  @param port port number
 *  @return return CLIENT_CONNECT_ERROR if socket() or sendto() return error value 
 */

int client_connect(const int ip_addr, const int port);

/** @brief function that handle command line arguments and connect to network by using client_connect() if arguments
 *  is correct.
 *  @param argc argument count
 *  @param argv array of strings 
 *  @return return INCORRECT_PORT if port number is incorrect, INCORRRECT_IP if ip address is incorrect,
 *          INCORRECT_ARG_NUM if argument number is incorrect,
 *          CLIENT_CONNECT_ERROR if client_connect() return error, else return 0 
 */
int client_cli(const int argc, char* argv[]);

/** @brief start listen on chosen port through TCP protocol 
 *  @param port chosen port
 *  @return SERVER_ERROR if a server socket creating error or bind function error has occured
 */
int server_start(int port);

/** @brief function that handle command line arguments and start server by using server_start() if argument is correct
 * @param argc argument count
 * @param argv array of strings
 * @return return INCORRECT_PORT if port number is incorrect, INCORRECT_ARG_NUM if argument number is
 * incorrect, return SERVER_ERROR if server_start() return error, else return 0
 */

int server_cli(int argc, char* argv[]);


/** @brief write help if help flag is used (--help)
 */
void write_help();

#endif
