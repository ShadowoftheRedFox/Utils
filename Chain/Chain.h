#ifndef HEADER_CHAIN_HANDOUT
#define HEADER_CHAIN_HANDOUT

// replace it with your wanted type
typedef int ChaineElement;
// TODO error if chain element is not defined by user
// TODO check if function in args are defined

typedef enum Bool {
    false, true
} Bool;

typedef struct Chain {
    ChaineElement v;
    struct Chain* next;
} Chain;

/**
 *@brief Create a Chain object
 *
 * @param a value to set
 * @param setFunction the function that set the source inside the dest
 * @return Chain*
 */
Chain* createChain(ChaineElement a, void (*setFunction)(ChaineElement* dest, ChaineElement* source));
/**
 *@brief insert at the start of the chain
 *
 * @param chain chain to add
 * @param a element to add
 * @param setFunction the function that set the source inside the dest
 * @return Chain*
 */
Chain* insertStart(Chain* chain, ChaineElement a, void (*setFunction)(ChaineElement* dest, ChaineElement* source));
/**
 *@brief insert at the end of the chain
 *
 * @param chain chain to add
 * @param a element to add
 * @param setFunction the function that set the source inside the dest
 * @return Chain*
 */
Chain* insertEnd(Chain* chain, ChaineElement a, void (*setFunction)(ChaineElement* dest, ChaineElement* source));
/**
 *@brief insert at the given position of the chain
 *
 * @param chain chain where we insert in
 * @param a element to add
 * @param pos position to add the element
 * @param setFunction the function that set the source inside the dest
 * @return Chain*
 */
Chain* insertPos(Chain* chain, ChaineElement a, unsigned int pos, void (*setFunction)(ChaineElement* dest, ChaineElement* source));
/**
 *@brief insert in a sorted way, defined by the strictSupCmpFct
 *
 * @param chain insert in the sorted order ("from tiny to big")
 * @param a element to add
 * @param setFunction the function that set the source inside the dest
 * @param strictSupCmpFct the function that return true if sup > inf
 * @return Chain*
 */
Chain* insertSorted(Chain* chain, ChaineElement a, void (*setFunction)(ChaineElement* dest, ChaineElement* source), Bool(*strictSupCmpFct)(ChaineElement sup, ChaineElement inf));
/**
 *@brief remove all element matching in the chain
 *
 * @param chain chain we look at
 * @param t target to remove
 * @param equalCmpFct function that compare is the two element are equal
 * @return Chain*
 */
Chain* removeAll(Chain* chain, ChaineElement t, Bool(*equalCmpFct)(ChaineElement, ChaineElement));
/**
 *@brief remove the first element that match
 *
 * @param chain chain we look at
 * @param a target to remove
 * @param equalCmpFct function that compare is the two element are equal
 * @return Chain*
 */
Chain* removeOne(Chain* chain, ChaineElement a, Bool(*equalCmpFct)(ChaineElement, ChaineElement));
/**
 *@brief invert the order of the chain
 *
 * @param chain target
 * @return Chain*
 */
Chain* invertChain(Chain* chain);
/**
 *@brief show the chain in the console
 *
 * @param chain target
 * @param typePrint function that prints the current element
 */
void showChain(Chain* chain, void (*typePrint)(ChaineElement));
/**
 *@brief free the whole chain from memory
 *
 * @param chain target
 */
void freeChain(Chain* chain);
#endif