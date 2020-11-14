
	int i = 0, j = 0;
	int res = 0;
	for(i=0;i<5;i++){
		for(j=0;j<5;j++){
			if(i==j||i+j==4){
				res = res + arr[i][j];
			}
		}
	}
	printf("res = %d\n",res);
	res = 0;
	for(i=0;i<5;i++){
		for(j=0;j<5;j++){
			if(i==0||i==4||j==0||j==4){
				res = res + arr[i][j];
			}
		}
	}
	printf("res = %d\n",res);

