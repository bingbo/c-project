#include <stdio.h>
#include "model/user.h"
#include "db/connection.h"

int main(int argc, char *argv[])
{
    
    char *sql = "select * from user";

    Connection *conn = malloc(sizeof(Connection));
    conn->host = "127.0.0.1";
    conn->port = 3306;
    conn->user = "root";
    conn->password = "";
    conn->database = "test";
    conn->init = conn_init;
    conn->query = conn_query;
    conn->free = conn_free;
    conn->close = conn_close;
    conn->fetch_result = conn_fetch_result;

    conn->init(conn);
    conn->query(sql);
    User users[7];
    conn->fetch_result();
    conn->free();
    conn->close();


    return 0;

}
