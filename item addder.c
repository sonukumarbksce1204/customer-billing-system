//customer billing system
#include<stdio.h>
#include<string.h>
#include "dicount.h"
#include "reward.h"
struct items{
    int product_no,qty;
    char product_name[30];
    float msp,gst,price;
    
};
struct customer{
	int custid,phoneno;
	char name[20],address[50];
};

int main() {
	int ch,f=0,try=1,n=0;
    FILE *fw;
    fw=fopen("TotalBill.doc","w");
    float total=0,disont=0,rew=0;
    struct items i[50];
	while(1){
		printf("Enter your choice\n 1.Customer Registration\n 2.Items add\n 3. Discount \n 4.Generate bill\n ");
		scanf("%d",&ch);
		if(ch==1){
			FILE *fw2;
			fw2=fopen("customer.dat","w");
			struct customer p;
			printf("Enter the details:\n");
			printf("custid\t name\t address\t phoneno \n");
			scanf("%d%s%s%ld",&p.custid,p.name,p.address,&p.phoneno);
			fwrite(&p,sizeof(p),1,fw2);		
			fclose(fw2);
		}
		else if(ch==2){
    		printf("Enter the details of products\n");
    		char cont='y';
    		while(n<=50){
    			if(try==1){
        			printf("Product_no   Product_name Qty  Price\t");
        			scanf("%d%s%d%f",&i[n].product_no,i[n].product_name,&i[n].qty,&i[n].msp);
        			i[n].gst=i[n].msp*0.18;
        			i[n].price=(i[n].msp+i[n].gst)*i[n].qty;
        			n++;
        			printf("Do you want add more items\n 1.YES \n 2. NO");
					int trytemp;
					scanf("%d",&trytemp);
					try=trytemp;
        		}
        		else{
        			break;
				}}
			while(f<n){
        			total=total+i[f].price;
        			disont=total;//try
					f++;
    			}
			}
		else if(ch==3){
			int flag=0;
    		printf("\nApply discount \n 1.YES \n 2. NO");
    		scanf("%d",&flag);
    		if(flag==1){
				disont=discount(total);
			}
			else{
				disont=total;
			}
		}
		else if(ch==4){
			f=0;
			f=0;
			FILE *fr2;
			struct customer sr;
			fr2=fopen("customer.dat","r");
			if(fr2==NULL){
				printf("file canot open\n");
			}
			else{
				printf("Detail of customer\n");
				int x=1;
				fread(&sr,sizeof(sr),1,fr2);
				//printf("%d\t%s\t%s\t%ld\n",sr.custid,sr.name,sr.address,sr.phoneno);
				}
    		printf("No\tname\tQty\tMsp\tGST\tTotal\n");
    		fprintf(fw,"\t\tCustomer Billing\n");
    		fprintf(fw,"\n--------------------------------------------------\n");
    		fprintf(fw,"Cust Id: %d\t",sr.custid);
    		fprintf(fw,"   Name: %s\n",sr.name);
    		fprintf(fw,"Address: %s\t",sr.address);
    		fprintf(fw,"   PhoneNo: %ld\n",sr.phoneno);
    		printf("No\tname\tQty\tMsp\tGST\tTotal\n");
    		fprintf(fw,"\nNo\tname\tQty\tMsp\t\tGST\t\tTotal\n");
    		
    		FILE *fr;
			struct customer sr1;
			fr=fopen("customer.dat","r");
			if(fr==NULL){
				printf("file canot open\n");
			}
			else{
				printf("Detail of customer\n");
				int x=1;
				fread(&sr,sizeof(sr),1,fr);
				//printf("%d\t%s\t%s\t%ld\n",sr1.custid,sr1.name,sr1.address,sr1.phoneno);
			}
    		
    		while(f<n){
				printf("%d\t%s\t%d\t%0.2f\t%0.2f\t%0.2f\n",i[f].product_no,i[f].product_name,i[f].qty,i[f].msp,i[f].gst,i[f].price);
				fprintf(fw,"%d\t",i[f].product_no);
        		fprintf(fw,i[f].product_name);
        		fprintf(fw,"\t%d\t",i[f].qty);
        		fprintf(fw,"%0.2f\t",i[f].msp);
        		fprintf(fw,"%0.2f\t",i[f].gst);
        		fprintf(fw,"\t%0.2f\n",i[f].price);
				f++;
			}
			printf("\nTotal amount need to pay with discount is %0.2f\n\n",disont);
			rew=reward(disont);
			fprintf(fw,"\nTotal amount need to pay with discount is: ");
			fprintf(fw,"\t%0.2f\n",disont);
			fprintf(fw,"Total Reward Point You earned %0.2f\n",rew);
			fprintf(fw,"\n\n\t\tTHANK YOU \n");
			fclose(fw);
		}
		else{
			break;
		}
	
    
	
}
}
