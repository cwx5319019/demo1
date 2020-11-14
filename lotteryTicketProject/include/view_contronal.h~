#ifndef VIEW_CONTRONAL_H_
#define VIEW_CONTRONAL_H_
#include"view.h"
#include"user_link.h"
#include"user_lottery.h"
#include"issue_link.h"

//主界面控制
void main_view_contronal(user_t* head_user,char* ptr,lot_t* head_lot,iss_t* head_iss);

//用户界面控制
void user_view_contronal(user_t* head_user,char* ptr,lot_t* head_lot,iss_t* head_iss);

//管理员界面控制
void admin_view_contronal(iss_t* head_iss,user_t* head_user,char* ptr,lot_t* head_lot);

//公证员界面控制
void worker_view_contronal(iss_t* head_iss,lot_t* head_lot,user_t* head_user);

//用户手动下注
void choice_lot_hand(lot_t* head_lot,lot_t* newlot,iss_t* q);

//用户机器下注
void choice_lot_machine(lot_t* head_lot,lot_t* newlot,iss_t* q);

//用户下注
void choice_lot(lot_t* head_lot,char* ptr,iss_t* head_iss,user_t* head_user,void (*choice_lot_all)(lot_t*,lot_t*,iss_t*));

//比较彩民号码是否中奖
void compare_iss(iss_t* head_iss,lot_t* head_lot,user_t* head_user);

//公证员发布出奖号码
void draw_lot_worker(iss_t* head_iss,lot_t* head_lot);

//公证员手动出奖
void draw(iss_t* head_iss,lot_t* head_lot);

//骰子游戏
void game_dice();

//注销用户
int delete_user(user_t* head_user,char* ptr,lot_t* head_lot );

//释放所有空间
void free_all(user_t* head_user,iss_t* head_iss,lot_t* head_lot);

//保存所有数据
void save_all(user_t* head_user,iss_t* head_iss,lot_t* head_lot);

//加载所有数据
void load_all(user_t* head_user,iss_t* head_iss,lot_t* head_lot);







#endif

