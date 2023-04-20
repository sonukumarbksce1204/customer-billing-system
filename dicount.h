//dicount
/*
type 1  5% discount
type 2  10% discount
type 3   15% discount */
float discount(float amount){
	float disc_amount;
	int type;
	printf("Type of discount need to apply\n");
    printf("1. 5%\n");
    printf("2. 10%\n");
	printf("3. 15%\n");
	printf("\n");
	scanf("%d",&type);
	if(type==1){
		disc_amount=amount-(amount*0.05);
	}
	else if(type==2){
		disc_amount=amount-amount*0.10;
	}
	else{
		disc_amount=amount-amount*0.15;
	}
	return disc_amount;
}
