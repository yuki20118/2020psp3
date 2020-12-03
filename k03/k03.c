#include <stdio.h>

#define DEBUG

#define ALPHABET_LEN    255

char StrOriginal[] = "On a dark deseart highway, cool wind in my hair.";
char StrKey[] = "wind";

char* ForceSearch(char text[], char key[])
{
    int start = 0;
    int pos = 0;
    int text_len=0,key_len=0,i=0;

    for(i=0; text[i]!='\0'; i++){        
        text_len++;
    }

    for(i=0; key[i]!='\0'; i++){         
        key_len++;
    }

    printf("text_len=%d\n", text_len);
    printf("key_len=%d\n", key_len);

    for(start=0; start <= text_len; start++){
        for(pos=0; pos <= key_len; pos++){
            if(text[start + pos]== key[pos]){   //ある文字が一致の処理
                if(pos==key_len-1){             //全てが一致の処理
                    return &text[start];
                }
            }
            else{                               //不一致の処理
                break;
            }    
        }    
    }
    return NULL;
}

char* BMSearch(char text[], char key[])
{

    int index = 0;
    int key_index = 0;
    int text_len=0,key_len=0,i=0;
    int table[256];

    for(i=0; i<=256; i++){      //はじめに全ての文字を4にする
        table[i]=4;
    }
    table[119]=3;   //w
    table[105]=2;   //i
    table[110]=1;   //n
    table[100]=0;   //d

    for(i=0; text[i]!='\0'; i++){        
        text_len++;
    }

    for(i=0; key[i]!='\0'; i++){         
        key_len++;
    }

    index=key_len-1;
    while(index <= text_len) {                              //indexが最後尾より前
        for (index=key_len-1;key_index<=0;key--) {          //キーの最後の⽂字から、1⽂字ずつ前
            if (text[index] == key[key_index]){
                                                            //⼀致した時の処理
                                                           
                if(index==key[key_index]){                  //キーが全部⼀致
                    return &text[index];                    //⾒つかった
                }
            }else{
                index=index+table[text[index]];             //不⼀致しなかった時の処理
                break;                                      
            }
        }
    }
    
    return NULL;

}

int main(void)
{
    char*   str;
    str = ForceSearch(StrOriginal, StrKey);
    printf("Force Search. Find keyword at:%s\n", str);

    str = BMSearch(StrOriginal, StrKey);
    printf("BM Search. Find keyword at:%s\n", str);

    return 0;
}