#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include "mysql/include/mysql.h"
#include "connection.h"
#include "../model/user.h"

#define MAX_COLUMN_LEN 32

MYSQL my_connection;
MYSQL_RES *result;
MYSQL_ROW sql_row;
MYSQL_FIELD *field;

/**
 * 初始化连接
 */
void conn_init(Connection *conn){
    mysql_init(&my_connection);
    if(mysql_real_connect(&my_connection, conn->host, conn->user, conn->password, conn->database, conn->port, NULL, 0)){
        printf("Connection success......\n");
    }else{
        printf("Connection fail......\n");
    }
}

/**
 * 查询数据
 */
void conn_query(char *sql){
    int res_num = mysql_query(&my_connection, sql);
    if(!res_num){
        result = mysql_store_result(&my_connection);
    }
}

/**
 * 获取数据
 */
void conn_fetch_result(void){
    if(result){
        printf("have data \n");

        int count = mysql_num_rows(result);
        printf("the result number is %d\n",count);

        while((field = mysql_fetch_field(result))){
            printf("%s\t",field->name);
        }
        printf("\n");

        int i=0;
        User users[count];
        while((sql_row=mysql_fetch_row(result))){
            users[i].id = malloc(sizeof(char) * 10);
            users[i].name = malloc(sizeof(char) * 20);
            users[i].password = malloc(sizeof(char) * 20);
            users[i].email = malloc(sizeof(char) * 20);
            strcpy(users[i].id, sql_row[0]);
            strcpy(users[i].name, sql_row[1]);
            strcpy(users[i].password, sql_row[2]);
            strcpy(users[i].email, sql_row[3]);
            i++;
            fprintf(stdout,"%s\t%s\t%s\t%s\n",sql_row[0],sql_row[1],sql_row[2],sql_row[3]);
        }
    }else{
        printf("no data\n");
    }
}
/**
 * 释放数据
 */
void conn_free(void){
    mysql_free_result(result);
}

/**
 * 关闭链接
 */
void conn_close(void){
    mysql_close(&my_connection);
}


