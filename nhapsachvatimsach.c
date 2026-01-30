#include <stdio.h>
#include <string.h>

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
void timsach(SA a[], int n, char masach[]);
int main(){
	SA a[10];
	int n = 2;
	nhapnfile(a,n);
	xuatnfile(a,n);
	char masach[11];
	
    printf("\nNhap ma sach can tim: ");
    scanf("%10s", masach);

    timsach(a, n, masach);
}
void nhap(SA *a){
	printf("\nHay nhap ma so sach: ");
	fflush(stdin);
	scanf("%s", &a->ISBN);
	printf("\nHay nhap tieu de sach:");
	fflush(stdin);
    fgets(a->tieude, sizeof(a->tieude), stdin);
	printf("\nHay nhap tac gia cua sach:");
	fflush(stdin);
    fgets(a->tacgia, sizeof(a->tacgia), stdin);
	printf("\nHay nhap nam xuat ban:");
	fflush(stdin);
	scanf("%d", &a->NPH);
	printf("\nHay nhap gia ban:");
	fflush(stdin);
	scanf("%lld", &a->giaban);
	printf("\nHay nhap so trang:");
	fflush(stdin);
	scanf("%d", &a->sotrang);
	printf("\nHay nhap nha xuat ban:");
	fflush(stdin);
    fgets(a->NXB, sizeof(a->NXB), stdin);
	printf("\nHay nhap loai sach:");
	fflush(stdin);
    fgets(a->loaisach, sizeof(a->loaisach), stdin);
}

void xuat(SA a){
	printf("%s\t%s\t%s\t%d\t%.1lld\t%d\t%s\t%s\n",a.ISBN, a.tieude, a.tacgia, a.NPH, a.giaban, a.sotrang, a.NXB, a.loaisach);
}

void nhapn(SA a[], int n){
    for(int i = 0; i < n; i++){
        printf("\nNhap thong tin sach %d:\n", i + 1);
        nhap(&a[i]);
    }
}

void xuatn(SA a[], int n){
    for(int i = 0; i < n; i++){
        printf("\nThong tin sach %d:\n", i + 1);
        xuat(a[i]);
    }
}


void nhapnfile(SA a[], int n){
	printf("\nNhap du lieu vao file dssv.out\n");
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

void timsach(SA a[], int n, char masach[]){
    int found = 0;
    for(int i = 0; i < n; i++){
        if(strstr(a[i].ISBN, masach) != NULL){
            printf("\nTim thay sach:\n");
            xuat(a[i]);
            found = 1;
        }
    }
    if(!found){
        printf("\nKhong tim thay sach co ISBN chua \"%s\"\n", masach);
    }
}
