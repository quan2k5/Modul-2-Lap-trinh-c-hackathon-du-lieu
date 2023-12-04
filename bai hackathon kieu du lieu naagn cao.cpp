#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct  contact{
	int id;
	char name[50];
	char phone[50];
	char address[50];
	int status;
};
void outputContact(struct contact arr[100],int currentSize){
	fflush(stdin);
	for(int i=0;i<currentSize;i++){
	printf("%d \t %s \t %s \t %s \t %d",arr[i].id,arr[i].name,arr[i].phone,arr[i].address,arr[i].status);
	printf("\n");
    }  
}
void bubbleSortIncrease(struct contact arr[100],int currentSize){
	for(int i=0;i<currentSize-1;i++){
		for(int j=0;j<currentSize-i-1;j++){
			if(strcmp(arr[j].name,arr[j+1].name)>0){
				contact k=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=k;
			}
		}
	}
}
void search(struct contact ct){
	printf("%d \t %s \t %s \t %s \t %d",ct.id,ct.name,ct.phone,ct.address,ct.status);
	printf("\n");
}
int main(){
	struct contact contact1={17,"le anh quan","0915199074","ha noi",1};
	struct contact contact2={29,"dinh trong","09236786576","hoa binh",0};
	struct contact contactList[100]={contact1,contact2};
	int currentSize=2;
	do{
		printf("\n1.in toan bo danh sach tren cung 1 hang");
		printf("\n2.thuc hiem chuc nang them moi contact vao vi tri cuoi cung cua contact ");
		printf("\n3.cap nhat thong tin theo ten");
		printf("\n4.xoa thong tin theo ten");
		printf("\n5.sap xep theo thuat toan noi bot tagn dan theo ten");
		printf("\n6.thuc hien chuc nang tim kiem theo ten nhi phan va in ra thong ti tren 1 hang");
		printf("\n7.thuc hien chuc nang tim kiem tuyen tinh theo struct va in ra thong tin tren cung 1 hang");
		printf("\n8.thoat");
		printf("\nnhap lua chon cua ban");
		int choice;
		fflush(stdin);
		char findName[100];
		scanf("%d",&choice);
		int updateIndex;
		int erraseIndex;
		int findStatus;
		switch(choice){
			case 1:
				outputContact(contactList,currentSize);
				break;
			case 2:
				struct contact newContact;
				fflush(stdin);
				
				printf("\nnhap vao ma id ");
				scanf("%d",&newContact.id);
				printf("\nnhap vao ten ");
				fflush(stdin);
				gets(newContact.name);
				printf("\nnhap vao so dien thoai ");
				gets(newContact.phone);
				printf("\nnhap dia chi ");
				gets(newContact.address);
				fflush(stdin);
				printf("\nnhap trang thai hoat dong ");
				scanf("%d",&newContact.status);
				contactList[currentSize]=newContact;
				currentSize++;
				break;
			case 3:
				fflush(stdin);
				printf("nhap ten ban muon cap nhat ");
				gets(findName);
				updateIndex=-1;
				for(int i=0;i<currentSize;i++){
					if(strcmp (contactList[i].name,findName)==0){
						updateIndex=i;
					}
				}
				if(updateIndex!=-1){
					printf("\ncap nhat lai ten");
					gets(contactList[updateIndex].name);
					printf("\ncap nhat lai so dien thoai");
					gets(contactList[updateIndex].phone);
					printf("\ncap nhay lai dia chi");
					gets(contactList[updateIndex].address);
					printf("\ncap nhat lai trang thai hoat dong");
					scanf("%d",&contactList[updateIndex].status);
					fflush(stdin);
				}else{
					printf("khong tim thay ten");
				}
				break;
			case 4:
				fflush(stdin);
				printf("nhap ten ban muon xoa ");
				gets(findName);
				erraseIndex=-1;
				for(int i=0;i<currentSize;i++){
					if(strcmp(contactList[i].name,findName)==0){
						erraseIndex=i;
					}
				}
				if(erraseIndex!=-1){
					for(int i=erraseIndex;i<currentSize;i++){
						contactList[i]=contactList[i+1];
					}
					currentSize--;
				}else{
					printf("khong tim thay ten");
				}
				break;
			case 5:
				bubbleSortIncrease(contactList,currentSize);
				break;
			case 7:
				printf("nhap status can tim kiem");
				fflush(stdin);
				scanf("%d",&findStatus);
				if(findStatus==1||findStatus==0){
				    for(int i=0;i<currentSize;i++){
					    if(findStatus==contactList[i].status){
						    search(contactList[i]);
					    }    
				    }
			    }else{
			    	printf("\nkhong hop le");
				}
				break;
			case 8:
				exit(0);
			default:
				printf("vui long nhap lai tu 1 den 8");	
		}	
	}while(1==1);
}
