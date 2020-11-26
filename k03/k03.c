#include <stdio.h>

#define DEBUG

#define ALPHABET_LEN    255

char StrOriginal[] = "On a dark deseart highway, cool wind in my hair.";
char StrKey[] = "wind";

char* ForceSearch(char text[], char key[])
{
    //  ここを実装する
    int start = 0;
    int pos = 0;
    int text_len=0,key_len=0,i;

    for(i=0; text[i]="\0"; i++){
        text_len++;
    }

    for(i=0; key[i]="\0"; i++){
        key_len++;
    }

    printf("text_len=%d\n", text_len);
    printf("key_len=%d\n", key_len);


    for(start=0; start <= text_len; start++){
        for(pos=0; pos <= key_len; pos++){
            if(text[start + pos]==key[pos]){
                pos++;
            }
            else{
                pos = 0;
            }    
        }
        
        
    }
    
    return text+start;
}

char* BMSearch(char text[], char key[])
{
    //  ここを実装する
    /*index = index + table[text[index]]; //ずらし量



    
    printf("%s\n", text);               //動作確認
    for(i=0; i < index - key_len + 1;i++){
        printf(" ");
    }
    printf("%s\n",key);*/
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