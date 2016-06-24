/*
 * name: test.c
 * purpose: for study
 * author: bing
 * */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define VERSION "1.0"
#define N 10
#define STR_LEN 20
#define NUM 10

typedef struct user {
    int id;
    char *name;
    char *password;
    char *email;
} User;

int total = 0;
int top = 0;
int size = 10;
User **users;
/*
 * 读入字符串
 */
void readline(char *str, int len){
    int i=0;
    char ch;
    while(isspace(ch = getchar()))
        ;
    while(i<len-1 && ch != '\n' && ch != EOF){
        str[i++] = ch;
        ch = getchar();
    }
    str[i] = '\0';
}

/**
 * show person
 */
void display(User *user){
    printf("id\tname\tpassword\temail\n");
    printf("%d\t%s\t%s\t%s\n",user->id,user->name,user->password,user->email);
}

/*
 * 添加
 */
void insert(void){
    User *user = malloc(sizeof(struct user));

    user->id=++top;
    user->name = malloc(STR_LEN * sizeof(char));
    user->password = malloc(STR_LEN * sizeof(char));
    user->email = malloc(STR_LEN * sizeof(char));

    printf("input your name: ");
    readline(user->name,STR_LEN);
    printf("input your password: ");
    readline(user->password,STR_LEN);
    printf("input your email: ");
    readline(user->email,STR_LEN);

    users[total++] = user;
    printf("add student successfully!!!\n");
}

/*
 * 查找
 */
void search(){
    int id,index = -1;
    printf("input your seach id: ");
    scanf("%d",&id);

    if(id < 0){
        printf("invalid,input your seach id again: ");
        scanf("%d",&id);
    }
    for(int i=0;i<total;i++){
        if(users[i]->id == id){
            index = i;
        }
    }
    if(index != -1){ 
        display(users[index]);
    }else{
        printf("don't find this person\n");
    }
}

/**
 * 删除
 */
void delete(){
    int id;
    printf("input your seach id: ");
    scanf("%d",&id);

    if(id < 1 || id > total){
        printf("invalid,input your seach id again: ");
        scanf("%d",&id);
    }
    int index = id -1;

    free(users[index]->name);
    free(users[index]->password);
    free(users[index]->email);
    free(users[index]);
    total--;
}

/**
 * 弹出一个人
 */
void pop(){
    if(top>0){
        display(users[top-1]);
        free(users[top-1]->name);
        free(users[top-1]->password);
        free(users[top-1]->email);
        free(users[top-1]);
        total--;   
        top--;
    }
}


//主入口
int main(void){


    users = malloc(NUM * sizeof(struct user));

    printf("you are operating the student database,please select your operations: i|s|d|p|q\n");
    char menu;
    for(;;){
        printf("enter your operation: ");
        scanf(" %c", &menu);
        switch(menu){
            case 'i':
                insert();
                break;
            case 's':
                search();
                break;
            case 'd':
                delete();
                break;
            case 'p':
                pop();
                break;
            case 'q':
                exit(0);
                break;
            default:
                printf("illegal operation\n");
        }
        printf("\n");
    }



    return 0;
}
