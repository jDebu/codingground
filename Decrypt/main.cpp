#include <iostream>
#include <stdio.h>
#include <cstring>
#include <ctype.h>
using namespace std;

struct Frequent{
    char letter[30];
    int repetition[30];
    char pattern[30];    
};
struct Message{
    char encrypt[1023];
    char decrypt[1023];
};

class OrderedChange{
    public:
    void setFrequent(){
        for(int i=0;i<strlen(message.encrypt);i++){
            for (int j=0;j<strlen(frequent.letter);j++){
                if(message.encrypt[i]==frequent.letter[j]){
                    frequent.repetition[j]+=1;    
                }
            }
        }
    }
    void ordered(){
        int step = 0;
        int comparate = 0;
        bool change = true;
        for (int i=0;change ;i++){
            step++;
            change=false;
            for (int j=0;j<strlen(frequent.letter)-1;j++){
                comparate++;
                if(frequent.repetition[j]<frequent.repetition[j+1]){
                    exchange(j);
                    change=true;
                }
            }
        }
    }
    
    void exchange(int i){
        char tmp=frequent.letter[i];
        frequent.letter[i]=frequent.letter[i+1];
        frequent.letter[i+1] = tmp;
        int tmp2=frequent.repetition[i];
        frequent.repetition[i]=frequent.repetition[i+1];
        frequent.repetition[i+1] = tmp2;
    }
    void decryptMessage(){
        strcpy(message.decrypt,"");
        bool change;
        for(int i=0;i<strlen(message.encrypt);i++){
            change=true;
            for (int j=0;j<strlen(frequent.pattern);j++){
                if(message.encrypt[i]==frequent.letter[j]){
                    //frequent.pattern[j]
                    message.decrypt[i]=frequent.pattern[j];
                    change=false;
                    if(change==false)
                        break;
                }else{
                    message.decrypt[i]=message.encrypt[i];
                }
            }
            
        }
        
    }
    public: struct Frequent frequent; struct Message message;
};


int main(){
    /*char orderedChange.message.encrypt[]="uid nx, aex jcdjipx iu wzux zp, ta wxtpa jtdaws, ai etkx vis.\n";
    Segmentation fault (core dumped)
    */
    OrderedChange orderedChange;
    strcpy(orderedChange.frequent.letter,"abcdefghijklmnopqrstuvwxyz");
    char freqLang[30];
    strcpy(freqLang,("TEOIARNSHLMYUCWDGPFBVKJ"));
    for(int i=0;i<strlen(freqLang);i++){
        orderedChange.frequent.pattern[i]=tolower(freqLang[i]);
    }
    
    for(int i=0;i<26;i++){
        orderedChange.frequent.repetition[i]=0;
    }
    strcpy(orderedChange.message.encrypt,"uid nx, aex jcdjipx iu wzux zp, ta wxtpa jtdaws, ai etkx vis.\n");
    strcat(orderedChange.message.encrypt,"dcos zyexdzaxr aex jxdw jezwipijes iu etkzyg nidx aety iyx hts\n");
    strcat(orderedChange.message.encrypt,"ai ri aex ptnx aezyg. z zyexdzaxr aeta jezwipijes udin wtdds htww,\n");
    strcat(orderedChange.message.encrypt,"hei zp ns exdi tqactwws. z htya ai ntfx dcos cpxdp udxx. z htya ai\n");
    strcat(orderedChange.message.encrypt,"gzkx aexn aex udxxrin ai qeiipx. jxijwx tdx rzuuxdxya. jxijwx qeiipx\n");
    strcat(orderedChange.message.encrypt,"rzuuxdxya qdzaxdzt. oca zu aexdx zp t oxaaxd hts tniyg ntys\n");
    strcat(orderedChange.message.encrypt,"twaxdytazkxp, z htya ai xyqicdtgx aeta hts os ntfzyg za qinuidatowx.\n");
    strcat(orderedChange.message.encrypt,"pi aeta'p heta z'kx adzxr ai ri.\n");
    strcat(orderedChange.message.encrypt,"z htya ai piwkx jdiowxnp z nxxa zy aex rtzws wzux os cpzyg qinjcaxdp,\n");
    strcat(orderedChange.message.encrypt,"pi z yxxr ai hdzax jdigdtnp. os cpzyg dcos, z htya ai qiyqxyadtax aex\n");
    strcat(orderedChange.message.encrypt,"aezygp z ri, yia aex ntgzqtw dcwxp iu aex wtygctgx, wzfx patdazyg hzae\n");
    strcat(orderedChange.message.encrypt,"jcowzq kizr  pinxaezyg pinxaezyg pinxaezyg ai pts,");
    strcat(orderedChange.message.encrypt,"\"jdzya exwwi hidwr.");
    strcat(orderedChange.message.encrypt,"\nz vcpa htya ai pts,"); 
    strcat(orderedChange.message.encrypt,"\"jdzya aezp!\" "); 
    strcat(orderedChange.message.encrypt,"z riy'a htya tww aex pcddicyrzyg\n");
    strcat(orderedChange.message.encrypt,"ntgzq fxshidrp. z vcpa htya ai qiyqxyadtax iy aex atpf. aeta'p aex otpzq\n");
    strcat(orderedChange.message.encrypt,"zrxt. pi z etkx adzxr ai ntfx dcos qirx qiyqzpx tyr pcqqzyqa.\n");
    strcat(orderedChange.message.encrypt,"scfzezdi ntapcniai. (hhh.tdaznt.qin/zyak/dcos)");

    
    orderedChange.setFrequent();
    orderedChange.ordered();
    /*
    for(int i=0;i<strlen(orderedChange.frequent.letter);i++){
        printf(" %c ",orderedChange.frequent.letter[i]);
    }
    printf("\n");
    for(int i=0;i<strlen(orderedChange.frequent.letter);i++){
        printf(" %d ",orderedChange.frequent.repetition[i]);
    }
    printf("\n");
    orderedChange.ordered();
    for(int i=0;i<strlen(orderedChange.frequent.letter);i++){
        printf(" %c ",orderedChange.frequent.letter[i]);
    }
    printf("\n");
    for(int i=0;i<strlen(orderedChange.frequent.letter);i++){
        printf(" %d ",orderedChange.frequent.repetition[i]);
    }
    printf("\n");
    for(int i=0;i<strlen(orderedChange.frequent.pattern);i++){
        printf(" %c ",orderedChange.frequent.pattern[i]);
    }*/
    printf("\n\n");
    orderedChange.decryptMessage();
    printf("**Message Encrypt**\n\n");
    printf("%s",orderedChange.message.encrypt);
    printf("\n\n");
    printf("***Message Decrypt***\n\n");
    for(int i=0;i<strlen(orderedChange.message.decrypt)-5;i++){
        printf("%c",orderedChange.message.decrypt[i]);
    }
    printf("\n");
    return 0;
}

