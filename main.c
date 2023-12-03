//Cifrario di Vigenere

#include <stdio.h>
#include <string.h>

void passwordInsensitive(char *password){
    //trasforma la password tutta maiuscola
    for(int i=0; i<strlen(password); i++){
        if(password[i]>=97) {
            //se la lettera è minuscola, sottrai 32 per avere la lettera corrispondente maiuscola
            password[i] -= 32;
        }
    }
}

int offset(char lettera){
    //data la password maiuscola, sottrai 65 per avere il numero corrispondente:
    //A=65 -> offset di 0
    //Z=90 -> offset di 25
    return lettera-65;
}

char cambioLettera(char lettera, int offset){

    int lm=lettera+offset;

    if(lettera>='A' && lettera<='Z'){
        if(lm<'A'){
            return 'Z'-('A'-lm)+1;
        }else{
            if(lm>'Z'){
                return 'A'+lm-'Z'-1;
            }else{
                return lm;
            }
        }
    }else{
        if(lm<'a'){
            return 'z'-('a'-lm)+1;
        }else{
            if(lm>'z'){
                return 'a'+lm-'z'-1;
            }else{
                return lm;
            }
        }
    }
}

void cripta(int coefficiente){
    char parola[1024];
    char password[1024];
    char tipologia[12];

    if(coefficiente==1){
        strcpy(tipologia, "da criptare");
    }else{
        strcpy(tipologia, "criptata");
    }
    printf("Inserisci la parola %s\n", tipologia);
    //per pulire il buffer
    fflush(stdin);
    //fgets per leggere le stringhe con gli spazi
    //scanf(%s, stringa) per leggere le stringhe senza spazi
    fgets(parola, 1024, stdin);

    printf("Inserisci la password:");
    //per pulire il buffer
    fflush(stdin);
    fgets(password, 1024, stdin);

    //cambio maiuscole/minuscole, trasformo tutto maiuscolo
    passwordInsensitive(password);

    //variabile d'appoggio per lo shift delle lettere
    int offsetNum=0;

    //contatore del numero degli spazi, perché quando c'è uno spazio nella parola da cifrare la password non va scalata
    int numeroSpazi=0;
    for(int i=0; i< strlen(parola)-1; i++){

        if(parola[i]!=' ') {
            //se la lettera non è uno spazio:
            //calcolo l'offset numerico;
            //(i-numeroSpazi) % (strlen(password) - 1) serve per non uscire dai limiti dell'array
            offsetNum = (coefficiente)*offset(password[(i-numeroSpazi) % (strlen(password) - 1)]);

            //cambio la lettera i-esima considerando che z+1=a ed Z+1=A
            parola[i] = cambioLettera(parola[i], offsetNum);
        }else{
            //se la lettera è uno spazio aumento il contatore degli spazi
            numeroSpazi++;
        }
    }
    printf("Il messaggio diventa: %s", parola);
}

int main() {
    int scelta = 0;
    do {
        printf("Seleziona:\n (1)\tper criptare il messaggio\n (2)\tDecriptare il messaggio\n (3)\tUscire\n");
        scanf("%d", &scelta);

        switch (scelta) {
            case 1: {
                //caso di criptazione
                cripta(1);
                break;
            }
            case 2: {
                //caso di decriptazione
                cripta(-1);
                break;
            }
            case 3: break;
            default: {
                printf("Errore!\n");
            }
        }
    }while(scelta!=3);
    return 0;
}