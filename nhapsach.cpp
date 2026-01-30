#include <stdio.h>

typedef struct SACH{
	char ISBN[11]; 
	char tieude[110]; 
	char tacgia[30]; 
	char NXB[110]; 
	char loaisach[50];
	int NPH, sotrang;
	long long giaban;

}SA;
	
void nhap(SA *a);
void xuat(SA a);
void nhapn(SA a[], int n);
void xuatn(SA a[], int n);
void nhapnfile(SA a[], int n);
void xuatnfile(SA a[], int n);

int main(){
	SA a[10];
	int n = 2;
	nhapnfile(a,n);
	xuatnfile(a,n);
	return 0;
}

void nhap(SA *a){
	printf("\nHay nhap ma so sach: ");
	fflush(stdin);
	scanf("%s", &a->ISBN);
	printf("\nHay nhap tieu de sach:");
	fflush(stdin);
	gets(a->tieude);
	printf("\nHay nhap tac gia cua sach:");
	fflush(stdin);
	gets(a->tacgia);
	printf("\nHay nhap nam xuat ban:");
	fflush(stdin);
	scanf("%d", &a->NPH);
	printf("\nHay nhap gia ban:");
	fflush(stdin);
	scanf("%lf", &a->giaban);
	printf("\nHay nhap so trang:");
	fflush(stdin);
	scanf("%d", &a->sotrang);
	printf("\nHay nhap nha xuat ban:");
	fflush(stdin);
	gets(a->NXB);
	printf("\nHay nhap loai sach:");
	fflush(stdin);
	gets(a->loaisach);
}

void xuat(SA a){
	printf("%s\t%s\t%s\t%d\t%.1lf\t%d\t%s\t%s\n",a.ISBN, a.tieude, a.tacgia, a.NPH, a.giaban, a.sotrang, a.NXB, a.loaisach);
}

void nhapn(SA a[], int n){
	int i;
	for(i = 1; i <= n; i++){
		printf("\nNhap thong tin sach %d: \n", i);
		nhap(&a[i]);
	}
}

void xuatn(SA a[], int n){
	int i;
	for(i = 1; i <= n; i++){
		printf("\nXuat thong tin sach %d: \n", i);
		xuat(a[i]);
	}
}

void nhapnfile(SA a[], int n){
	nhapn(a, n);

    FILE *fp = fopen("dss.out", "wb");
    if (fp != NULL) {
        fwrite(a, sizeof(SA), n, fp);
        fclose(fp);
    }else{
    	printf("Loi mo file");
    }


}
void xuatnfile(SA a[], int n){
    FILE *fp = fopen("dss.out", "rb");
    if (fp != NULL) {
        fread(a, sizeof(SA), n, fp);
        fclose(fp);
        printf("\nDu lieu tu file dssv.out: \n");
        xuatn(a, n);
    }else{
    	printf("Loi mo file");
    }
}