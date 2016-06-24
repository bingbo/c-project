#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

/*
typedef enum sex {
    MALE,
    FEMALE
} SEX;
*/
typedef struct user{
    int id;
    char *name;
    char *password;
    char *email;
    /*
    enum { MALE, FEMALE } sex;
    */
    void (*getName)(struct user *);
    void (*getEmail)(struct user *);
    void (*getPassword)(struct user *);
} User;

void getName(User *user){
    printf("this user's name is: %s\n",user->name);
}
void getPassword(User *user){
    printf("this user's password is: %s\n",user->password);
}
void getEmail(User *user){
    printf("this user's email is: %s\n",user->email);
}


int main(void){
    /*
    User *u = malloc(sizeof(User));
    u->id = 1;
    u->name = "bill";
    u->password = "1111";
    u->email = "bill@126.com";
    u->getName = getName;
    u->getEmail = getEmail;
    u->getPassword = getPassword;

    u->getName(u);
    u->getPassword(u);
    u->getEmail(u);
    char str[10];
    scanf("%s",str);
    puts(str);
    puts("hell\\\\");
    */
    return 0;
}
