#ifndef __protocol_h
#define __protocol_h
 typedef struct PROTOCOL
 {
    int type;
    char name[20];
    char passwd[20];
    //  
 }protocol;
#define TYPE_REG 1
#define TYPE_LOGIN 2
#define TYPE_EXIT 0
#define TYPE_OK  8
#define TYPE_ERR 9
#endif
