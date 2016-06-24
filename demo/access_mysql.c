#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include "mysql/include/mysql.h"
#include "model/user.h"

#define MAX_COLUMN_LEN 32

int main(int argc, char *argv[])
{
    MYSQL my_connection;
    MYSQL_RES *result;
    MYSQL_ROW sql_row;
    MYSQL_FIELD *field;
    char column[MAX_COLUMN_LEN];
    int res;
    int i=0;
    User users[7], *user;
    //User *users[7], *user;

    mysql_init(&my_connection);

    if(mysql_real_connect(&my_connection, "127.0.01","root","","test",3306,NULL,0)){
        printf("Connection success......\n");
        res = mysql_query(&my_connection, "select * from user");
        if(!res){
            result = mysql_store_result(&my_connection);
            if(result){
                printf("have data \n");

                printf("the result number is %lu\n",(unsigned long)mysql_num_rows(result));

                while((field = mysql_fetch_field(result))){
                    printf("%s\t",field->name);
                }
                printf("\n");

                while((sql_row=mysql_fetch_row(result))){
                    user = malloc(sizeof(struct user));
                    /*
                    user->id = sql_row[0];
                    user->name = sql_row[1];
                    user->password = sql_row[2];
                    user->email = sql_row[3];
                    */
                    strcpy(users[i].id,sql_row[0]);
                    strcpy(users[i].name,sql_row[1]);
                    strcpy(users[i].password,sql_row[2]);
                    strcpy(users[i].email,sql_row[3]);
                    //users[i] = user;
                    fprintf(stdout,"%s\t%s\t%s\t%s\n",sql_row[0],sql_row[1],sql_row[2],sql_row[3]);
                    i++;
                }
            }else{
                printf("no data\n");
            }
        }else{
            printf("query fail\n");
        }
    }else{
        fprintf(stderr, "Connection failed......%d:%s\n", errno, strerror(errno));
    }

    printf("id\tname\tpassword\temail\n");
    for(;i>=0;i--){
        printf("%s\t%s\t%s\t%s\n",users[i].id,users[i].name,users[i].password,users[i].email);
    }
    mysql_free_result(result);
    mysql_close(&my_connection);
}
