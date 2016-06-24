#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "../model/user.h"

#ifndef CONNECTION_H
#define CONNECTION_H

typedef struct connection{
    char *host;
    int port;
    char *user;
    char *password;
    char *database;
    void (*init)(struct connection *);
    void (*query)(char *sql);
    void (*free)(void);
    void (*close)(void);
    void (*fetch_result)(void);
} Connection;

void conn_init(Connection *conn);
void conn_query(char *sql);
void conn_free(void);
void conn_close(void);
void conn_fetch_result(void);

#endif
