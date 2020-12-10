#include <stdio.h>

#define DEBUG

#define ALPHABET_LEN    255

char StrOriginal[] = "On a dark deseart highway, cool wind in my hair.";
char StrKey[] = "wind";

char* ForceSearch(char text[], char key[])
{
    int start = 0;
    int pos = 0;
    int text_len=0, key_len=0, i=0;

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
            if(text[start + pos]== key[pos]){   
                if(pos==key_len-1){             
                    return &text[start];
                }
            }else{                               
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
    int text_len=0,key_len=0,i=0,tmp;
    int table[ALPHABET_LEN];

    for(i=0; text[i]!='\0'; i++){        
        text_len++;
    }

    for(i=0; key[i]!='\0'; i++){         
        key_len++;
    }

    printf("text_len=%d\n", text_len);
    printf("key_len=%d\n", key_len);

    for(i=0; i<ALPHABET_LEN; i++){      
        table[i]=key_len;
    }

    for(i=0; i<key_len-1; i++){
        table[key[i]]=key_len-i-1;
    }

    index=key_len-1;

    while(index <= text_len) {
        key_index=key_len-1;
        tmp=index;                        
        while (text[index] == key[key_index]){                                                 
            if(key_index==0){                       
                return &text[index];                
            }else{
                index--;
                key_index--;                                                              
            }
        } 
        index=index+table[text[index]];
        if(index < tmp){
            index++;
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