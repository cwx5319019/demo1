#include"view_contronal.h"


/*
	函数名：main_view_contronal
	返回值：无
	函数功能：主界面控制
*/
void main_view_contronal(user_t* head_user,char* ptr,lot_t* head_lot,iss_t* head_iss){
	system("clear");
	load_all(head_user,head_iss,head_lot);
	char num_1 =0;
	int res = 0;
	while(1){
		main_view(); //主界面
		scanf("%c",&num_1);
		while(getchar() != 10);
		if(num_1 == '0'){ //退出
			save_all(head_user,head_iss,head_lot);
			free_all(head_user,head_iss,head_lot);
			printf("\033[31m已退出！\033[0m\n\n");
			return ;
		}
		switch(num_1){
			case '1': //登录
				res = login(head_user,ptr);
				if(res == 1){ //管理员界面
					admin_view_contronal(head_iss,head_user,ptr,head_lot);
				}else if(res == 2 ){ //公证员界面
					worker_view_contronal(head_iss,head_lot,head_user);
				}else if (res == 3){ //用户界面
					user_view_contronal( head_user,ptr,head_lot,head_iss); 	
				}else{
					
				}
				break;
			case '2'://注册
				insert_user_node(head_user);
				break;
			default :
				printf("\033[31m输入有误，请重新输入!\n\n\033[0m");
				
				clear();
				break;
		}
	}
}


/*
	函数名：user_view_contronal
	返回值：无
	函数功能：用户界面控制
*/
void user_view_contronal(user_t* head_user,char* ptr,lot_t* head_lot,iss_t* head_iss){
	system("clear");
	int num = 0,res = 0,ret = 0;
	while(1){
		user_view(); //用户界面
		scanf("%d",&num);
		while(getchar() != 10);
		if(num == 0){
			system("clear");
			break;
		}//返回上一级
		switch(num){
			case 1://查看个人信息
				print_user(head_user,ptr);
				break;
			case 2://修改个人密码				
				ret = updata_user_code(head_user,ptr);	
				if(ret == 1){
					return ;
				}	
				break;
			case 3://注销个人信息
				res = delete_user(head_user,ptr,head_lot);
				if(res == 1){
					return ;
				}
				break;
			case 4://充值
				recharge_user(head_user,ptr);
				break;
			case 5://查询中奖记录
				find_lot( head_lot,ptr,recode_draw,head_draw);
				break;
			case 6://手动下注
				choice_lot(head_lot,ptr,head_iss,head_user,choice_lot_hand);
				break;
			case 7://机器下注
				choice_lot(head_lot,ptr,head_iss,head_user,choice_lot_machine);
				break;
			case 8://查询个人购票记录
				find_lot(head_lot,ptr,recode_purchase,head_purchase);
				break;
			case 9://游戏
				game_dice();
				break;
			default :
				printf("\033[31m选择错误！\n\033[0m");
				break;		
		}
	}
}


/*
	函数名：admin_view_contronal
	返回值：无
	函数功能：管理员界面控制
*/
void admin_view_contronal(iss_t* head_iss,user_t* head_user,char* ptr,lot_t* head_lot){
	system("clear");
	int num = 0;
	while(1){
		admin_view();//管理员界面
		scanf("%d",&num);
		while(getchar() != 10);
		if(num == 0){
			system("clear");
			break;
		}
		switch(num){
			case 1://发行彩票
				issue_link(head_iss);
				break;
			case 2: //输出用户信息
				admin_find_user(head_user);
				break;
			case 3: //按照用户余额排序
				bubble_user(head_user);
				break;
			case 4:
				//查询所有用户信息
				print(head_user); 
				break;
			case 5://查询所有用户购票记录
				 lot_print(head_lot);
				break;
			case 6://每期彩票信息
				print_iss_link(head_iss);
				break;
			default:
				printf("输入错误，请重输入！\n");
				break;
		}
	}
}

//公证员界面控制
void worker_view_contronal(iss_t* head_iss,lot_t* head_lot,user_t* head_user){
	system("clear");
	int num = 0;
	while(1){
	worker_view(); //公证员界面
	scanf("%d",&num);
	while(getchar() != 10);
	if(num == 0){
		system("clear");
		break;
	} 
		switch(num){
			case 1: //机器开奖
				draw_lot_worker(head_iss,head_lot);
				compare_iss(head_iss,head_lot,head_user);
				break;
			case 2: //手动开奖
				draw(head_iss,head_lot);
				compare_iss(head_iss,head_lot,head_user);
				break;
			case 3://查看历史发布
				print_iss_link(head_iss);
				break;
			default:
				printf("输入错误，请重新输入!\n");
				break;
		}
	}
}

























