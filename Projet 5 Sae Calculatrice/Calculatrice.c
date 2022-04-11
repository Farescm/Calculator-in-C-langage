#include <stdio.h>

void addition(int res[], int nb1[], int nb2[], int taille);

char flush_space(){
    char c;
    scanf("%c", &c);
    while(c==' ')
        scanf("%c", &c);
    return c;
}
void shift(int tab[], int taille_tab, int taille_nb){
    int i;
    for(i=0; i<taille_nb; i++){
        tab[taille_tab-i-1]=tab[taille_nb-i-1];
        tab[taille_nb-i-1]=0;
    }
}
int is_num(char c){
    return c>='0' && c<='9';
}
int convert(char c){
    return c-'0';                    
}
char lire_nombre(int tab[], int taille){
    char cur=0; int minus=0; int i=0;
    cur=flush_space();
    if(cur=='-'){
        minus=1;
        cur=flush_space();
    }
    tab[0]=minus ?-convert(cur) : convert(cur);
    scanf("%c", &cur);
    for(i=1; is_num(cur);i++){
        tab[i]=convert(cur);
        scanf("%c", &cur);
    }
    shift(tab, taille, i);
    if(cur==' ')
        return flush_space();
    else 
        return cur;
}
void display(int tab[], int taille){
    int i=0;
    for(i=0; i<taille && tab[i]==0; i++);
    for(;i<taille;i++)
        printf("%d", tab[i]);
    printf("\n");
}
int degresnb(int tab[], int tailletab){
    int i;
    for(i=0; i<tailletab; i++){
        if (tab[i]!=0){
            return i;
        }
    }
}
void conversion(int nb[], int taille){
    int degres = degresnb(nb, 1000);
    nb[degres]=nb[degres]*-1;
}
int is_negatif(int nb[], int taille){
    int i;
    for (i=0; i<taille; i++){
        if (nb[i]<0){
            return 1;
        }
    }
    return 0;
}
int comparaison(int nb1[], int nb2[], int taille){
    int i;
    int res=0;
    int is_negatif1 = is_negatif(nb1, 1000);
    int is_negatif2 = is_negatif(nb2, 1000);
    if (is_negatif(nb1, 1000) == 1 && is_negatif(nb2, 1000) == 0){
        return 2;
    }
    else if (is_negatif(nb1, 1000)==0 && is_negatif(nb2, 1000)==1){
        return 1;
    }
    else if ((is_negatif(nb1, 1000)==0 && is_negatif(nb2, 1000)==0) || (is_negatif(nb1, 1000)==1 && is_negatif(nb2, 1000)==1)){
        for (i=0; i<taille; i++){
            if (nb1[i]>nb2[i]){
                return 1;
            }
            else if (nb1[i]<nb2[i]){
                return 2;
            }
        }
    }
    return 3;
}
void soustractionnormal(int res[], int nb1[], int nb2[], int taille){
    int i = 0;
    int cur = 0;

    if(is_negatif(nb1, 1000) == 0 && is_negatif(nb2, 1000) == 0){
            for(i=0; i<taille; i++){
            if (nb1[taille-i-1]<nb2[taille-i-1]){
                nb1[taille-i-1]=nb1[taille-i-1]+10;
                nb2[taille-i-2]=nb2[taille-i-2]+1;
                cur=nb1[taille-i-1]-nb2[taille-i-1];
            }
            else {
                cur=nb1[taille-i-1]-nb2[taille-i-1];
            }
            res[taille-i-1]=cur;
    } 
    } 
        else if(is_negatif(nb1, 1000) == 0 && is_negatif(nb2, 1000) == 1){  
            conversion(nb2, taille);
            addition(res, nb1, nb2, taille);
           // conversion(res, 1000);
    }
        else if(is_negatif(nb1, 1000) == 1 && is_negatif(nb2, 1000) == 1){  
        conversion(nb2, taille);
        addition(res, nb1, nb2, taille);
    }
}
void soustractioncontraire(int res[], int nb1[], int nb2[], int taille){
    
    int i = 0;
    int cur=0;
    
    if(is_negatif(nb1, 1000) == 0 && is_negatif(nb2, 1000) == 0){
        for(i=0; i<taille; i++){
        if (nb2[taille-i-1]<nb1[taille-i-1]){
            nb2[taille-i-1]=nb2[taille-i-1]+10;
            nb1[taille-i-2]=nb1[taille-i-2]+1;
            cur=nb2[taille-i-1]-nb1[taille-i-1];
        }
        else {
            cur=nb2[taille-i-1]-nb1[taille-i-1];
        }
        res[taille-i-1]=cur;
    }
    conversion(res, 1000);
    }
    else if(is_negatif(nb1, 1000) == 1 && is_negatif(nb2, 1000) == 0){  
      conversion(nb1, taille);
      addition(res, nb1, nb2, taille);
      conversion(res, 1000);
    }

    else if(is_negatif(nb1, 1000) == 1 && is_negatif(nb2, 1000) == 1){
        conversion(nb2, taille);
        addition(res, nb1, nb2, taille);
    }
  
}
void soustraction(int res[], int nb1[], int nb2[], int taille){

    if ( comparaison(nb1, nb2, 1000) == 1){

        soustractionnormal(res, nb1, nb2, taille);
    }
        
    else if(comparaison(nb1, nb2, 1000) == 2){
      
    soustractioncontraire(res, nb1, nb2, taille);
    
    }
}
void addition(int res[], int nb1[], int nb2[], int taille){
    int i=0;
    int ret=0;
    int cur=0;
    int dizaine;
    int unite;
    int is_negatif1 = is_negatif(nb1, 1000);
    int is_negatif2 = is_negatif(nb2, 1000);
    int comparaisontch = comparaison(nb1, nb2, 1000);
    if (is_negatif1==0 && is_negatif2==1){
        conversion(nb2, 1000);
        soustraction(res, nb1, nb2, 1000);
    }
    else if (is_negatif1==1 && is_negatif2==0){
        conversion(nb1, 1000);
        soustraction(res, nb2, nb1, 1000);
    }
    else if (is_negatif1==1 && is_negatif2==1){
        conversion(nb2, 1000);
        soustraction(res, nb1, nb2, 1000);
    }
    else {
    for(i=0; i<taille; i++){
        cur=nb1[taille-i-1]+nb2[taille-i-1]+ret;
        dizaine=cur/10;
        unite=cur%10;
        res[taille-i-1]=unite;
        ret=dizaine;
    }
    }
}
int nombrechiffres(int tab[], int tailletab){
    int i;
    for(i=0; i<tailletab && tab[i]==0; i++);
    return tailletab-i;
}
void decale(int nb[1000], int decalage){
    int i;
    int degresnb = nombrechiffres(nb, 1000);
    for (i=0; i<=degresnb; i++){
        nb[1000-degresnb-decalage+i]=nb[1000-degresnb+i];
    }
    for (i=0; i<decalage; i++){
        nb[1000-i-1]=0;
    }
}
void multip(int resf[], int nb1[], int nb2[], int taille){
    int i;
    int j;
    int degresnb = nombrechiffres(nb2, taille);
    for (i=0; i<degresnb; i++){
        int rest[1000] = {0};
        for (j=1; j<=nb2[taille-i-1]; j++){
            addition(rest, rest, nb1, 1000);
        }
        decale(rest, i);
        addition(resf, resf, rest, 1000);
    }

}
void multiplication(int resf[], int nb1[], int nb2[], int taille){
    int i;
    int j;
    int degresnb = nombrechiffres(nb2, taille);

    if(is_negatif(nb1,1000) == 0 && is_negatif(nb2,1000) == 0){
        multip(resf, nb1, nb2, 1000);
    }

    else if(is_negatif(nb1,1000) == 1 && is_negatif(nb2,1000) == 0){
        conversion(nb1, 1000);
        
        multip(resf, nb1, nb2, 1000); 
        conversion(resf, 1000);
    }
    
    

    else if(is_negatif(nb1, 1000) == 0 && is_negatif(nb2,1000) == 1){
        conversion(nb2, 1000);
        
        multip(resf, nb1, nb2, 1000);  
        conversion(resf, 1000);
    }
    
    

    else if(is_negatif(nb1, 1000) == 1 && is_negatif(nb2, 1000) == 1){
        conversion(nb1, 1000);
        conversion(nb2, 1000);
        
        multip(resf, nb1, nb2, 1000); 

    }
}
void soustractiondivision(int res[], int nb1[], int nb2[], int taille){

    int i = 0;

    int cur = 0, chiffre1 = 0, chiffre2 = 0, ret = 0;

    for(i = 0; i < taille; i++){
        chiffre1 = nb1[taille-i-1];
        chiffre2 = nb2[taille-i-1]+ret;

        if (chiffre1 < chiffre2){
            ret = 1;
            cur = 10+chiffre1-chiffre2;
        }

        else{
            ret = 0;
            cur = chiffre1 - chiffre2;
        }
        res[taille-i-1]=cur;


    }


}
void the_division(int res[], int nb1[], int nb2[], int taille){
    int i, j;
    int compa = 0;
    int unite[1000] = {0}; 
    int tabo[1000]= {0}; 
    int resf[1000]= {0};
    unite[999] = 1;
    int nc1 = nombrechiffres(nb1, 1000);
    int nc2 = nombrechiffres(nb2, 1000);
    int ecart = nc1 - nc2 ;
    
    for (i=0; i<taille; i++){
        tabo[i]=nb2[i];
    }
    for(i=ecart; i >= 0; i--){
      decale(nb2,i);
      compa = comparaison(nb1, nb2, 1000);
      for (j=0; j<taille; j++) resf[j]=0;

      while (compa == 1 || compa==3){
            soustractiondivision(nb1, nb1, nb2, 1000);
            addition(resf, resf, unite, 1000);
            compa = comparaison(nb1, nb2, 1000);
       }
        decale(resf,i);
        addition(res, res, resf, 1000);
        for (j=0; j<taille; j++){
            nb2[j]=tabo[j];
        } 

 }
}
void division(int res[], int nb1[], int nb2[], int taille){
    
    int negatifnb1 = is_negatif(nb1, 1000);
    int negatifnb2 = is_negatif(nb2, 1000);
    if (negatifnb1==1 && negatifnb2==0){
    conversion(nb1, 1000);
    the_division(res, nb1, nb2, taille);
    conversion(res, 1000);
    }
    
    
    else if (negatifnb1==0 && negatifnb2==1){
        conversion(nb2, 1000);
        the_division(res, nb1, nb2, taille);
        conversion(res, 1000);
    }

    
    else if (negatifnb1==1 && negatifnb2==1){
        conversion(nb1, 1000);
        conversion(nb2, 1000);
        the_division(res, nb1, nb2, taille) ;   
    }
    
    else {
        the_division(res, nb1, nb2, taille);
    }
}
void modulom(int res[], int nb1[], int nb2[], int taille){
    int i = 0;
    int res1[1000]={0};
    int res2[1000]={0};
    int vidage[1000] = {0};

    for (i=0; i<taille; i++){
        vidage[i]=nb1[i]; }

    division(res1, nb1, nb2, 1000);
    multiplication(res2, res1, nb2, 1000);
    soustraction(res, vidage, res2, 1000);
}
void modulo(int res[], int nb1[], int nb2[], int taille){

    if(is_negatif(nb1,1000) == 1 && is_negatif(nb2,1000) == 0){
        conversion(nb1, 1000);
        modulom(res, nb1, nb2, 1000);
        conversion(res, 1000);
    }
    else if (is_negatif(nb1,1000) == 0 && is_negatif(nb2,1000) == 1){
        conversion(nb2,1000);
        modulom(res, nb1, nb2, 1000);
    }
    else if(is_negatif(nb1,1000) == 1 && is_negatif(nb2,1000) == 1){
        conversion(nb1,1000);
        conversion(nb2,1000);
        modulom(res, nb1, nb2, 1000);
        conversion(res,1000);
    }
    else{
        modulom(res, nb1, nb2, 1000);
    }
}
void Ensemble_vide(int res[], int taille){

    int i;
    int vide[1000] = {0};

    for(i = 0; i < taille; i++){
        if(comparaison(vide, res, 1000) == 3){
            printf("0");
            break;
        }
    }
}

int main(){
    int nb1[1000]={0};
    int nb2[1000]={0};
    int nb3[1000]={0}; 
    int res1[1000]={0};
    int res2[1000]={0};
    char op1, op2;
    op1=lire_nombre(nb1, 1000);
    op2=lire_nombre(nb2, 1000);
    if(op2 =='\n'){

        if(op1 == '+'){
            addition(res1, nb1, nb2, 1000);
            Ensemble_vide(res1, 1000);
        }

        else if(op1 == '-'){
            soustraction(res1, nb1, nb2, 1000);
            Ensemble_vide(res1, 1000);
        }
        
        else if(op1 == '*'){
            multiplication(res1, nb1, nb2, 1000);
            Ensemble_vide(res1, 1000);
        }
        
        else if(op1 == '/'){
            division(res1, nb1, nb2, 1000);
            Ensemble_vide(res1, 1000);
        }
        
        else if(op1 == '%'){
            modulo(res1, nb1, nb2, 1000);
            Ensemble_vide(res1, 1000);
        }
        
    display(res1, 1000); 
    }



    if(op2!='\n'){
        lire_nombre(nb3, 1000);

    if (op1 == '%' && op2 == '*'){
        modulo(res1,nb1,nb2,1000);
        multiplication(res2, res1, nb3, 1000);
        Ensemble_vide(res2, 1000);
    }

    else if (op1 == '*' && op2 == '%'){
        multiplication(res1,nb1,nb2,1000);
        modulo(res2, res1, nb3, 1000);
        Ensemble_vide(res2, 1000);
    }

    else if ( op1 == '%' && op2 == '/'){
        modulo(res1,nb1,nb2,1000);
        division(res2, res1, nb3, 1000);
        Ensemble_vide(res2, 1000);
    }

    else if (op1 == '/' && op2 == '%'){
        division(res1,nb1,nb2,1000);
        modulo(res2, res1, nb3, 1000);
        Ensemble_vide(res2, 1000);
    }

    else if ( op1 == '%' && op2 == '+'){
        modulo(res1,nb1,nb2,1000);
        addition(res2, res1, nb3, 1000);
        Ensemble_vide(res2, 1000);
    }

    else if ( op1 == '+' && op2 == '%'){
        modulo(res1,nb2,nb3,1000);
        addition(res2, res1, nb1, 1000);
        Ensemble_vide(res2, 1000);
    }

    else if ( op1 == '%' && op2 == '-'){
        modulo(res1,nb1,nb2,1000);
        soustraction(res2, res1, nb3, 1000);
        Ensemble_vide(res2, 1000);
    }

    else if ( op1 == '-' && op2 == '%'){
        modulo(res1,nb2,nb3,1000);
        soustraction(res2, nb1, res1, 1000);
        Ensemble_vide(res2, 1000);
    }
    else if(op1 == '%' && op2 == '%'){
        modulo(res1,nb1,nb2,1000);
        modulo(res2,res1,nb3,1000);
        Ensemble_vide(res2, 1000);

    }

    else if(op1 == '/' && op2 == '*'){
        division(res1, nb1, nb2, 1000);
        multiplication(res2, res1, nb3, 1000);
        Ensemble_vide(res2, 1000);

    }

    else if ( op1 == '/' && op2 == '/'){
        division(res1, nb1, nb2, 1000);
        division(res2, res1, nb3, 1000);
        Ensemble_vide(res2, 1000);

    }

    else if (op1 == '*' && op2 == '/'){
        multiplication(res1, nb1, nb2, 1000);
        division(res2, res1, nb3, 1000);
        Ensemble_vide(res2, 1000);

    }
    else if ( op1 == '/' && op2 == '+'){
        division(res1, nb1, nb2, 1000);
        addition(res2, res1, nb3, 1000);
        Ensemble_vide(res2, 1000);
    }

    else if(op1 == '+' && op2 == '/'){
        division(res1, nb2, nb3, 1000);
        addition(res2, nb1, res1, 1000);
        Ensemble_vide(res2, 1000);
    }
    else if ( op1 == '/' && op2 == '-'){
        division(res1, nb1, nb2, 1000);
        soustraction(res2, res1, nb3, 1000);
        Ensemble_vide(res2, 1000);
    }

    else if(op1 == '-' && op2 == '/'){
        division(res1, nb2, nb3, 1000);
        soustraction(res2, nb1, res1, 1000);
        Ensemble_vide(res2, 1000);
    }
    
    else if(op1 == '+' && op2 == '*'){
        multiplication(res1, nb2, nb3, 1000);
        addition(res2, nb1, res1, 1000);
        Ensemble_vide(res2, 1000);
    }

    else if(op1 == '*' && op2 == '+'){
        multiplication(res1, nb1, nb2, 1000);
        addition(res2, res1, nb3, 1000);
        Ensemble_vide(res2, 1000);
    }

    else if(op1 == '-' && op2 == '*'){
        multiplication(res1, nb2, nb3, 1000);
        soustraction(res2, nb1, res1, 1000);
        Ensemble_vide(res2, 1000);
    }

    else if(op1 == '*' && op2 == '-'){
        multiplication(res1, nb1, nb2, 1000);
        soustraction(res2, res1, nb3, 1000);
        Ensemble_vide(res2, 1000);
    }

    else if(op1 == '-' && op2 == '+'){
        soustraction(res1, nb1, nb2, 1000);
        addition(res2, res1, nb3, 1000);
        Ensemble_vide(res2, 1000);
    }

    else if(op1 == '+' && op2 == '-'){
        addition(res1, nb1, nb2, 1000);
        soustraction(res2, res1, nb3, 1000);
        Ensemble_vide(res2, 1000);
    }

    else if(op1 == '*' && op2 == '*'){
        multiplication(res1, nb1, nb2, 1000);
        multiplication(res2, res1, nb3, 1000);
        Ensemble_vide(res2, 1000);
    }

    else if(op1 == '+' && op2 == '+'){
        addition(res1, nb1, nb2, 1000);
        addition(res2, res1, nb3, 1000);
        Ensemble_vide(res2, 1000);
    }

    else if(op1 == '-' && op2 == '-'){
        soustraction(res1, nb1, nb2, 1000);
        soustraction(res2, res1, nb3, 1000);
        Ensemble_vide(res2, 1000);
    }

    display(res2, 1000); 
    }

    return 0;
}