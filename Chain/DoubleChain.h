#ifndef HEADER_CHAIN_DOUBLE_HANDOUT
#define HEADER_CHAIN_DOUBLE_HANDOUT

// replace it with your wanted type
typedef int ChainDoubleElement;
// TODO check if function in args are defined

typedef enum Bool {
    false, true
} Bool;

typedef struct ChainDouble {
    ChainDoubleElement v;
    struct ChainDouble* next;
    struct ChainDouble* previous;
} ChainDouble;

/**
 *@brief Create a ChainDouble object
 *
 * @param a value to set
 * @param setFunction the function that set the source inside the dest
 * @return ChainDouble*
 */
ChainDouble* createChainDouble(ChainDoubleElement a, void (*setFunction)(ChainDoubleElement* dest, ChainDoubleElement* source));
/**
 *@brief insert at the start of the chainDouble
 *
 * @param chainDouble chainDouble to add
 * @param a element to add
 * @param setFunction the function that set the source inside the dest
 * @return ChainDouble*
 */
ChainDouble* insertStart(ChainDouble* chainDouble, ChainDoubleElement a, void (*setFunction)(ChainDoubleElement* dest, ChainDoubleElement* source));
/**
 *@brief insert at the end of the chainDouble
 *
 * @param chainDouble chainDouble to add
 * @param a element to add
 * @param setFunction the function that set the source inside the dest
 * @return ChainDouble*
 */
ChainDouble* insertEnd(ChainDouble* chainDouble, ChainDoubleElement a, void (*setFunction)(ChainDoubleElement* dest, ChainDoubleElement* source));
/**
 *@brief insert at the given position of the chainDouble
 *
 * @param chainDouble chainDouble where we insert in
 * @param a element to add
 * @param setFunction the function that set the source inside the dest
 * @return ChainDouble*
 */
ChainDouble* insert(ChainDouble* chainDouble, ChainDoubleElement a, void (*setFunction)(ChainDoubleElement* dest, ChainDoubleElement* source));
/**
 *@brief insert in a sorted way, defined by the strictSupCmpFct
 *
 * @param chainDouble insert in the sorted order ("from tiny to big")
 * @param a element to add
 * @param setFunction the function that set the source inside the dest
 * @param strictSupCmpFct the function that return true if sup > inf
 * @return ChainDouble*
 */
ChainDouble* insertSorted(ChainDouble* chainDouble, ChainDoubleElement a, void (*setFunction)(ChainDoubleElement* dest, ChainDoubleElement* source), Bool(*strictSupCmpFct)(ChainDoubleElement sup, ChainDoubleElement inf));
/**
 *@brief remove all element matching in the chainDouble
 *
 * @param chainDouble chainDouble we look at
 * @param t target to remove
 * @param equalCmpFct function that compare is the two element are equal
 * @return ChainDouble*
 */
ChainDouble* removeAll(ChainDouble* chainDouble, ChainDoubleElement t, Bool(*equalCmpFct)(ChainDoubleElement, ChainDoubleElement));
/**
 *@brief remove the first element that match
 *
 * @param chainDouble chainDouble we look at
 * @param a target to remove
 * @param equalCmpFct function that compare is the two element are equal
 * @return ChainDouble*
 */
ChainDouble* removeOne(ChainDouble* chainDouble, ChainDoubleElement a, Bool(*equalCmpFct)(ChainDoubleElement, ChainDoubleElement));
/**
 *@brief show the chainDouble in the console
 *
 * @param chainDouble target
 * @param typePrint function that prints the current element
 */
void showChainDouble(ChainDouble* chainDouble, void (*typePrint)(ChainDoubleElement));
/**
 *@brief free the whole chainDouble from memory
 *
 * @param chainDouble target
 */
void freeChainDouble(ChainDouble* chainDouble);
#endif