#include "etudiants.h"
#include <string.h>
#include <stdlib.h>

Etudiant* etudiant_creer(const char *nom, const char *prenom,
                         const char *motDePasse,
                        const char *cin,  const char *cne,
                        const char *etab, int anDiplome, int nbrAns,
                        Diplome diplome, float notes[8])
{
    Etudiant *etud = calloc(1, sizeof(Etudiant));

    strcpy(etud->nom, nom);
    strcpy(etud->prenom, prenom);
    strcpy(etud->motDePasse, motDePasse);

    strcpy(etud->cin,cin);
    strcpy(etud->cne,cne);

    strcpy(etud->etab, etab);

    etud->anDiplome = anDiplome;
    etud->nbrAns = nbrAns;
    etud->diplome = diplome;

    memcpy(etud->notes, notes, sizeof(float) * 8);

    return etud;
}

int nombre_notes_diplome(Diplome dip)
{
    switch (dip)
    {
    case CPGE: return 1;
    case DUT:
    case DEUG:
    case DEUST:
        return 4;
    case LICENCE:
        return 6;
    case MASTER:
        return 10;
    case MAITRISE:
        return 8;
    }
    return 0;
}

Diplome convertir_diplome(const char *diplome)
{
    if(strcmp("DUT", diplome)) return DUT;
    else if(strcmp("DEUG", diplome)) return DEUG;
    else if(strcmp("DEUST", diplome)) return DEUST;

    else if(strcmp("LICENCE", diplome)) return LICENCE;
    else if(strcmp("MAITRISE", diplome)) return MAITRISE;
    else if(strcmp("MAITRISE", diplome)) return MASTER;

    else return CPGE;
}

const char* diplome_to_char (Diplome diplome)
{
    switch (diplome) {
    case DUT: return "DUT";
    case DEUG: return "DEUG";
    case DEUST: return "DEUST";

    case MAITRISE : return "MAITRISE";
    case LICENCE : return "LICENCE";
    case MASTER : return "MASTER";

    case CPGE : return "CPGE";
    }
    return "";
}

gboolean etudiant_egaux(const void *etud1, const void *etud2)
{
    Etudiant *etudiant1 = (Etudiant*) etud1, *etudiant2 = (Etudiant*) etud2;
    return strcmp(etudiant1->cne, etudiant2->cne) == 0;
}

void etudiant_detruire(void* etudiant)
{
  free(etudiant);
}
