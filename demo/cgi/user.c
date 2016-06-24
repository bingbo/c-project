#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void){
    typedef struct{
        int id;
        char *username;
        int age;
    } user;
    
    //=====================data===================
    user users[] = {
        {},
        {
            1,
            "bingbing.zhang",
            18
        }
    };
    //=====================data===================
    
    char * query_string;
    int id;
    //获取环境变量
    query_string = getenv("QUERY_STRING");
    puts(query_string);

    if(query_string == NULL){
        printf("no data");
    }else if(sscanf(query_string, "id=%d", &id) != 1){
        printf("no id");
    }else{
        printf("用户信息查询<br>学号：%d<br>姓名：%s<br>年龄：%d", id, users[id].username, users[id].age);
    }

    return 0;


}
