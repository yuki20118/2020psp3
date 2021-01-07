#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>

typedef struct {
    int id;
    char name[19];  //  市の名前、UTF-8対応
    float members;  //  世帯人員
    int total;      //  食料合計
    int grain;      //  穀類
    int seafood;    //  魚介類
    int meat;       //  肉類
    int milk;       //  乳卵類
    int vegetable;  //  野菜類
    int fruit;      //  果物
    int seasoning;  //  調味料
    int snack;      //  菓子類
    int cocking;    //  調理料理
    int drink;      //  飲料
    int liquor;     //  酒類
    int eatout;     //  外食
} City;

#define DEBUG
#define MAX_CITY    47


void PrintCity(City city)
{
    printf("%d, %s, %.2f, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d\n", 
        city.id, city.name, city.members, city.total, 
        city.grain, city.seafood, city.meat, city.milk, city.vegetable, city.fruit,
        city.seasoning, city.snack, city.cocking, city.drink, city.liquor, city.eatout);
}

void PrintArray(City city[], int size)
{
    int i;

    for (i=0; i<size; i++) {
        PrintCity(city[i]);
    }
}

int LoadData(City arrayCity[])
{
    char buf[256];
    FILE* fp;

    fp = fopen("consumption.csv","r");
    if(fp==NULL){
        fputs("File open error\n",stderr);
        return -1;
    }

    int cn = 0; // 市の数
    while(fgets(buf,sizeof(buf),fp) != NULL){
        sscanf(buf,"%d,%[^,],%f,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d", 
            &(arrayCity[cn].id), arrayCity[cn].name, &(arrayCity[cn].members), &(arrayCity[cn].total), 
            &(arrayCity[cn].grain),  &(arrayCity[cn].seafood),  &(arrayCity[cn].meat), &(arrayCity[cn].milk), 
            &(arrayCity[cn].vegetable),  &(arrayCity[cn].fruit),  &(arrayCity[cn].seasoning),  &(arrayCity[cn].snack),
            &(arrayCity[cn].cocking),  &(arrayCity[cn].drink),  &(arrayCity[cn].liquor),  &(arrayCity[cn].eatout));
#ifdef DEBUG
        PrintCity(arrayCity[cn]);
#endif
        cn++;
    }

    if(fclose(fp) == EOF){
        fputs("file close error\n",stderr);
        return -1;
    }

    return cn;
}


void BubbleSort(City arrayCity[], int size)
{
    //  ここを実装する
    int cnt=1;        
    int pos;
    City tmp;
    
    while(cnt!=0){
        cnt=0;
        for(pos=0; pos<size-1; pos++){
            if(arrayCity[pos].total > arrayCity[pos+1].total){
                tmp = arrayCity[pos];
                arrayCity[pos] = arrayCity[pos+1];
                arrayCity[pos+1] = tmp;
                cnt++;
            }
        }
    }
}


void QuickSort(City arrayCity[], int left, int right)
{
    //  ここを実装する
    int i, j;
    int pivot;
    City tmp;

    //要素数が1以上
    if(left < right){
        i=left;
        j=right;
        pivot = arrayCity[left].seafood;

        while(1){

            //左から順番にpivotより大きな値を探す
            for(i=left; i<=right; i++){
                if(pivot < arrayCity[i].seafood){
                    i = arrayCity[i].seafood;
                    break;
                }
                
            }
            
            //右から順番にpivot以下の値を探す
            for(j=right; j>left; j--){
                if(pivot >= arrayCity[j].seafood){
                    j = arrayCity[j].seafood;
                    break;
                }
                
            }


            if(i>=j){
                break;
            }else{
                //iの場所の値とjの場所の値を入れ替える
                tmp = arrayCity[i];         
                arrayCity[i] = arrayCity[j];
                arrayCity[j] = tmp; 
            }

        }

    //pivotの値とjの場所の値を入れ替える
        tmp = arrayCity[left];
        arrayCity[left] = arrayCity[j];
        arrayCity[j] = tmp;

    //左側でQuickSortを再起呼び出しする
        right=j-1;
        QuickSort(arrayCity, left, right);

    //右側も。
        left=j+1;
        QuickSort(arrayCity, left, right);
    }

}



void HeapSort(City arrayCity[], int size)
{
    //  チャレンジ問題(1)
    //  ここを実装する

}


void MergeSort(City arrayCity[], int left, int right)
{
    //  チャレンジ問題2
    //  ここを実装する

}

int main(void)
{
 
    //  事前準備。データの読み込み、配列の作成
    City* arrayCity;
    int cn;
    arrayCity = (City*)malloc(sizeof(City) * MAX_CITY);
    cn = LoadData(arrayCity);
    if (cn == -1) {
        exit(EXIT_FAILURE);
    }

    //  食料品合計で並び替え
    printf("===== Sorted by total =====\n");
    BubbleSort(arrayCity, MAX_CITY);
    PrintArray(arrayCity, MAX_CITY);

    //  魚介類で並び替え   
    printf("===== Sorted by seafood =====\n");
    QuickSort(arrayCity, 0, MAX_CITY - 1);
    PrintArray(arrayCity, MAX_CITY);
   
//    MergeSort(arrayCity, 0, MAX_CITY - 1);
//    HeapSort(arrayCity, MAX_CITY);
//    PrintArray(arrayCity, MAX_CITY);



    //  後処理
    free(arrayCity);

    return 0;
}