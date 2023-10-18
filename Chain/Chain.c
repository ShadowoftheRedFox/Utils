#include "Chain.h"
#include <stdlib.h>
#include <stdio.h>

Chain* createChain(ChainElement a, void (*setFunction)(ChainElement*, ChainElement*)) {
    Chain* c = malloc(sizeof(Chain));
    if (c == NULL) {
        exit(-1);
    }

    // c->v = a; is an equivalent of
    setFunction(&(c->v), &a);
    c->next = NULL;
    return c;
}

Chain* insertStart(Chain* chain, ChainElement a, void (*setFunction)(ChainElement*, ChainElement*)) {
    if (chain == NULL) {
        return createChain(a, setFunction);
    }
    Chain* new = createChain(a, setFunction);
    new->next = chain;
    return new;
}

Chain* insertEnd(Chain* chain, ChainElement a, void (*setFunction)(ChainElement*, ChainElement*)) {
    if (chain == NULL) {
        return createChain(a, setFunction);
    }
    Chain* new = createChain(a, setFunction);
    Chain* c = chain;
    while (c->next != NULL) {
        c = c->next;
    }
    c->next = new;
    return chain;
}

void showChain(Chain* chain, void (*typePrint)(ChainElement)) {
    if (chain == NULL) {
        printf("Chain is corrupted.\n");
        return;
    }
    while (chain->next != NULL) {
        typePrint(chain->v);
        chain = chain->next;
    }
    typePrint(chain->v);
}

Chain* insertPos(Chain* chain, ChainElement a, unsigned int pos, void (*setFunction)(ChainElement*, ChainElement*)) {
    if (chain == NULL) {
        chain = insertStart(chain, a, setFunction);
    } else {
        Chain* c = chain;
        Chain* new = createChain(a, setFunction);
        for (unsigned int i = 0; i < pos; i++) {
            if (c == NULL) {
                exit(1);
                break;
            } else {
                c = c->next;
            }
        }
        new->next = c->next;
        c->next = new;
    }

    return chain;
}

Chain* insertSorted(Chain* chain, ChainElement a, void (*setFunction)(ChainElement*, ChainElement*), Bool(*strictSupCmpFct)(ChainElement inf, ChainElement sup)) {
    if (chain == NULL) {
        return createChain(a, setFunction);
    }
    Chain* c = chain;
    unsigned int pos = 0;
    while (c->next != NULL) {
        if (strictSupCmpFct(c->v, a)) {
            insertPos(chain, a, pos - 1, setFunction);
            break;
        }
        c = c->next;
        pos++;
    }
    return chain;
}

Chain* removeAll(Chain* chain, ChainElement t, Bool(*equalCmpFct)(ChainElement, ChainElement)) // c pour chaine, t pour "target" (cible)
{
    if (chain == NULL) {
        return NULL;
    }

    Chain* temp = NULL; // temporaire
    Chain* n = chain;       // n pour new
    Chain* p = NULL;    // p pour "previous" (précédent)
    int pos = 0;          // position actuel que l'on regarde
    while (n->next != NULL) {
        if (pos == 0 && equalCmpFct(n->v, t)) {
            temp = n;
            n = n->next;
            // on bouge aussi la tete de chaine
            chain = n;
            free(temp);
            // pas de pos++ car on est toujours en début de tete
        } else {
            // on bouge la position
            pos++;
            if (equalCmpFct(n->v, t)) {
                // on est au milieu de chaine
                temp = n;
                p->next = n->next; // on pointe le précédent sur le next vu qu'on efface l'actuel Chain
                n = p->next;
                free(temp);
            } else {
                // on passe au next seulement si le v est différent de la cible
                p = n;
                n = n->next;
            }
        }
    }

    // on est en fin de chaine
    if (equalCmpFct(n->v, t)) {
        // si tout les Chains ont 2, cela cause une erreur, car on a "free" l'endroit où pointe p
        if (p != NULL) {
            p->next = NULL;
            free(n);
        } else {
            // mettre un code spécial si c'est la cas
            n->v = -1;
            // ou mettre free n aussi, mais gérer ce cas dans l'affichage de la chaine
        }
    }
    return chain;
}

Chain* removeOne(Chain* chain, ChainElement a, Bool(*equalCmpFct)(ChainElement, ChainElement)) {
    if (chain == NULL) {
        return NULL;
    }
    Chain* c = chain;
    Chain* p = NULL;

    while (c->next != NULL) {
        if (equalCmpFct(c->v, a)) {
            break;
        } else {
            p = c;
            c = c->next;
        }
    }

    if (equalCmpFct(c->v, a)) {
        if (p == NULL) {
            chain = c->next;
            free(c);
            return chain;
        } else if (c->next == NULL) {
            p->next = NULL;
            free(c);
            return chain;
        } else {
            p->next = c->next;
            free(c);
            return chain;
        }
    }

    return chain;
}

Chain* invertChain(Chain* chain) {
    if (chain == NULL) {
        return NULL;
    }
    Chain* c = chain;
    Chain* p = c;
    Chain* h = c;

    while (c->next != NULL) {
        p = c;
        c->next = h;
        h = c;
        c = p->next;
    }

    c->next = h;
    h = c;
    chain->next = NULL;
    return h;
}

void freeChain(Chain* chain) {
    if (chain == NULL) { return; }
    Chain* c = chain;
    while (chain->next != NULL) {
        c = chain;
        chain = chain->next;
        free(c);
    }
    free(chain);
}