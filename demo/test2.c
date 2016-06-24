/*
 * name: test.c
 * purpose: for study
 * author: bing
 * */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define STR_LEN 20

typedef struct user {
    int id;
    char *name;
    char *password;
    char *email;
    struct user *next;
    struct user *prev;
} User;

User *first, *last, *root;
/**
 * show person
 */
void display(void){
    User *list = first;
    printf("id\tname\tpassword\temail\n");
    while(list){
        printf("%d\t%s\t%s\t%s\n",list->id,list->name,list->password,list->email);
        list = list->next;
    }
}



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


/*
 * 添加
 */
void insert(void){
    User *user = malloc(sizeof(struct user));

    user->name = malloc(STR_LEN * sizeof(char));
    user->password = malloc(STR_LEN * sizeof(char));
    user->email = malloc(STR_LEN * sizeof(char));
    user->next = NULL;

    printf("input your id: ");
    scanf("%d",&user->id);
    printf("input your name: ");
    readline(user->name,STR_LEN);
    printf("input your password: ");
    readline(user->password,STR_LEN);
    printf("input your email: ");
    readline(user->email,STR_LEN);

    last->next = user;
    user->prev = last;
    last = user;
    
    printf("add student successfully!!!\n");
}



/*
 * 查找
 */
void search(void){
    int id;
    printf("input your seach id: ");
    scanf("%d",&id);

    if(id < 0){
        printf("invalid,input your seach id again: ");
        scanf("%d",&id);
    }

    User *list = first;
    while(list){
        if(id == list->id){
            printf("%d\t%s\t%s\t%s\n",list->id,list->name,list->password,list->email);
            break;
        }
        list = list->next;
    }
    if(list == NULL){ 
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

    if(id < 0){
        printf("invalid,input your delete id again: ");
        scanf("%d",&id);
    }

    User *list = first;
    while(list){
        if(id == list->id){
            printf("%d\t%s\t%s\t%s\n",list->id,list->name,list->password,list->email);
            list->prev->next = list->next;
            list->next->prev = list->prev;
            break;
        }
        list = list->next;
    }
    if(list == NULL){ 
        printf("have no this person\n");
    }
}

//主入口
int main(void){



    root = malloc(sizeof(User));

    root->id=1;
    root->name="bill";
    root->password="11111";
    root->email="bill@12.com";
    root->next=NULL;
    root->prev=NULL;

    first = last = root;

    printf("select operations : q[quit]|i[insert]|p[print]|s[search]|d[delete]\n");
    char ch;
    for(;;){
        printf("enter your operation\n");
        scanf("%c",&ch); 
        switch(ch){
            case 'i':
                insert();
                break;
            case 'p':
                display();
                break;
            case 's':
                search();
                break;
            case 'd':
                delete();
                break;
            case 'q':
                exit(0);
                break;
            default:
                printf("invalid operation\n");
        }
        printf("\n");
    }
    return 0;
}

