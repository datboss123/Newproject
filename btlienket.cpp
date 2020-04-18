#include<iostream>
using namespace std;
struct nut{
	int info;
	nut *next;
};
nut ds[100];
nut *TaoNut(){
	nut *tam;
	tam= new nut;
	printf("Nhap diem:");
	int k;
	scanf("%d",&k);
	tam->info =k;
	tam->next =NULL;
	return tam;
}
nut *TaoNode(int value){
	nut *node = new nut;
	node->info = value;
	node->next=NULL;
	return node;
}
nut *AddHead(nut *head,int value){
	nut *temp = TaoNode(value);
	if(head==NULL){
		head=temp;
	}
	else{
		temp->next=head;
		head=temp;
	}
	return head;
}
nut *themtruoc(nut *head,int value1,int info2){
	nut *q = head;
	int k=0;
	if(q->info==info2){
		nut *temp = TaoNode(value1);
		temp->next=q;
		q=temp;
		return temp;
	}else{
	
	while(q!=NULL && k!=info2){
		q=q->next;
		++k;
		if(q->info==info2) {	
		
		break;
	}
    }
    
	
	nut *r=head;
	int k1=0;
	while(r!=NULL && k1!=k)
	{   
	    if(k1==k-1) {
			break;
		}
		r=r->next;
		++k1;
		
	}
	
	nut *real_q = TaoNode(value1);
	real_q->next=r->next;
	r->next=real_q;
	
	return real_q;
}
}

/*void ThemXY(nut *head,int X, int Y)

{           //1. Kh?i  t?o nút m?i

nut  *q = new nut(); //T?o 1 nút m?i q

            //if(q==NULL)  // N?u h?t b?n nh?

            //{           cout<<"danh sach day"; return; } // Thông báo ra màn hình và k?t thúc.

            q->info =  X; // gán  thông tin cho  nút  q

             q->next=NULL;//2. 1  Tìm nút  có tru?ng info là Y

            nut *q1 = head;

            int k = 0;

            while((q1  != NULL)&&(k != Y)){ // Duy?t cho d?n khi tìm  

                        q1 = q1->next ;


++k;                               // th?y Y hay k?t thúc ds.

            if(q1->info == Y)   //  Tìm th?y nút có  info = Y  

            {          

                      break;

}
}
nut *r = head;

int k1=0;

while((r!=NULL)&&(k1!=k)){

               r=r->next;

               ++k1;

               if(k1==k-1){

                              break;}}

q->next = r-> next;

r->next = q;
}
*/
nut *themsau(int value,nut *r){
	nut *r1 =new nut;
	r1->info=value;
	r1->next=r->next;
	r->next=r1;
	return r1;
}

int main() {
   	nut *first =NULL,*L;
   	int i,n;
   	printf("Nhap so phan tu");
   	scanf("%d",&n);
   	for(i=0;i<n;i++){
   		if(first==NULL){
   			first=TaoNut();
   		}else{
   			L=first;
   			while(L->next!=NULL){
   				L=L->next;

   			}
   			L->next=TaoNut();
   		}
   	}
   	
   	nut *head= themtruoc(first,5,6);
   	nut *head1=themsau(2,head);
   	nut *dau = AddHead(first,3);
   	//nut *head1=AddHead(first,3);
   	//ThemXY(first,5,6);
   	for(nut *p=dau;p!=NULL;p=p->next){
   		printf("%d",p->info);
   	}
	
}

