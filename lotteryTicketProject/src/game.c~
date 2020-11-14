#include"game.h"
void game_dice(){
	system("clear");
	int score = 50;
	int res = 0;
	
	FILE* fp = fopen("./doc/game.txt","r");
	//if(fp == NULL){return;}
	if(fp !=NULL){
		while(1){
			res = fread(&score,sizeof(score),1,fp);
			if(res == 0 )break;
		}
		fclose(fp);
	}
	
	srand(time(0));
	int ch = 0;
	printf("***********************\n");
	printf("*  欢迎来到骰子游戏!  *\n");
	printf("***********************\n");
	while(1){
		printf("\n");
		printf("*********************\n");
		printf("* 1 -> 开 始 游 戏  *\n");
		printf("* 2 -> 充 值 积 分  *\n");
		printf("* 3 -> 查 看 积 分  *\n");
		printf("* 0 -> 退 出 游 戏  *\n");
		printf("*********************\n");
		printf("请选择：");
		int cho = 0;
		scanf("%d",&cho);
		while(getchar()!= 10);
		if(cho == 1){
			if(score>=5){
				while(1){
				int num_1 = rand()%6+1;
				int num_2 = rand()%6+1;
				int num_3 = rand()%6+1;
				int res = num_1 + num_2 + num_3;
				int ret = (num_1==num_2) + (num_2==num_3) + (num_1==num_3);
				system("clear");
				printf("\n");
				printf("*********************\n");
				printf("*   1 -> 压 大      *\n");
				printf("*   2 -> 压 小      *\n");	
				printf("*   3 -> 豹 子      *\n");
				printf("*   0 -> 退 出      *\n");
				printf("*********************\n");
				printf("请选择：\n");
				scanf("%d",&ch);
				while(getchar() != 10);
				if(ch == 0)break;
				switch(ch){
					case 1 :
						if(res >10 && ret != 3){
							printf("\033[33m恭喜你，猜中了！ +10分\033[0m\n");
							score += 10;
						}else{
							printf("\033[31m很遗憾，猜错了！ -5分\033[0m\n");
							score -= 5;
						}
						break;
					case 2 :
						if(res <10 && ret != 3){
							printf("\033[33m恭喜你，猜中了！ +10分\033[0m\n");
							score += 10;
						}else{
							printf("\033[31m很遗憾，猜错了！ -5分\033[0m\n");
							score -= 5;
						}
						break;
					case 3 :
						if(ret == 3){
							printf("\033[33m恭喜你，猜中了！ +10分\033[0m\n");
							score += 10;
						}else{
							printf("\033[31m很遗憾，猜错了！ -5分\033[0m\n");
							score -= 5;
						}
						break;
					default:
						printf("\033[32m输入错误，请重新输入！\033[0m\n");
						break;
		
					}
					printf("\n按回车继续:");
					while(getchar()!= 10);
				}
			}else{
				printf("\033[32m积分不足,请先充值！\033[0m\n");
			}
		}else if(cho == 2){
			printf("请输入充值金额\n");
			int num_4 = 0;
			scanf("%d",&num_4);
			while(getchar()!= 10);
			if(num_4>0){
				score += num_4;
				printf("\033[33m充值成功！\033[0m\n");
			}else{
				printf("\033[33m充值失败！\033[0m\n");
			}
			clear();
		}else if (cho == 3){
			printf("积分余额：%d 分\n",score);
			
			clear();
		}else if (cho == 0){
			FILE* fp_1 = fopen ("./doc/game.txt","w");
			fwrite(&score,sizeof(score),1,fp_1);
			fclose(fp_1);
			system("clear");
			return ;
		}else{}
	}
		
}

























