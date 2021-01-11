//
// Created by olcay on 2.05.2019.
//

#include "SentenceAutoNER.h"

/**
 * The main method to automatically detect named entities in a sentence. The algorithm
 * 1. Detects PERSON(s).
 * 2. Detects LOCATION(s).
 * 3. Detects ORGANIZATION(s).
 * 4. Detects MONEY.
 * 5. Detects TIME.
 * For not detected words, the algorithm sets the named entity "NONE".
 * @param sentence The sentence for which named entities checked.
 */
void SentenceAutoNER::autoNER(AnnotatedSentence *sentence) {
    autoDetectPerson(sentence);
    autoDetectLocation(sentence);
    autoDetectOrganization(sentence);
    autoDetectMoney(sentence);
    autoDetectTime(sentence);
    for (int i = 0; i < sentence->wordCount(); i++){
        auto* word = (AnnotatedWord*) sentence->getWord(i);
        if (word->getNamedEntity() == nullptr){
            word->setNamedEntityType("NONE");
        }
    }
}
