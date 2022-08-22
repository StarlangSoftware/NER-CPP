//
// Created by olcay on 2.05.2019.
//

#include "TurkishSentenceAutoNER.h"

/**
 * The method assigns the words "bay" and "bayan" PERSON tag. The method also checks the PERSON gazetteer, and if
 * the word exists in the gazetteer, it assigns PERSON tag.
 * @param sentence The sentence for which PERSON named entities checked.
 */
void TurkishSentenceAutoNER::autoDetectPerson(AnnotatedSentence *sentence) {
    for (int i = 0; i < sentence->wordCount(); i++){
        auto* word = (AnnotatedWord*) sentence->getWord(i);
        if (word->getNamedEntity() == nullptr && word->getParse() != nullptr){
            if (Word::isHonorific(word->getName())){
                word->setNamedEntityType("PERSON");
            }
            word->checkGazetteer(personGazetteer);
        }
    }
}

/**
 * The method checks the LOCATION gazettteer, and if the word exists in the gazetteer, it assigns the LOCATION tag.
 * @param sentence The sentence for which LOCATION named entities checked.
 */
void TurkishSentenceAutoNER::autoDetectLocation(AnnotatedSentence *sentence) {
    for (int i = 0; i < sentence->wordCount(); i++){
        auto* word = (AnnotatedWord*) sentence->getWord(i);
        if (word->getNamedEntity() == nullptr && word->getParse() != nullptr){
            word->checkGazetteer(locationGazetteer);
        }
    }
}

/**
 * The method assigns the words "corp.", "inc.", and "co" ORGANIZATION tag. The method also checks the
 * ORGANIZATION gazetteer, and if the word exists in the gazetteer, it assigns ORGANIZATION tag.
 * @param sentence The sentence for which ORGANIZATION named entities checked.
 */
void TurkishSentenceAutoNER::autoDetectOrganization(AnnotatedSentence *sentence) {
    for (int i = 0; i < sentence->wordCount(); i++){
        auto* word = (AnnotatedWord*) sentence->getWord(i);
        if (word->getNamedEntity() == nullptr && word->getParse() != nullptr){
            if (Word::isOrganization(word->getName())){
                word->setNamedEntityType("ORGANIZATION");
            }
            word->checkGazetteer(organizationGazetteer);
        }
    }
}

/**
 * The method checks for the TIME entities using regular expressions. After that, if the expression is a TIME
 * expression, it also assigns the previous texts, which are numbers, TIME tag.
 * @param sentence The sentence for which TIME named entities checked.
 */
void TurkishSentenceAutoNER::autoDetectTime(AnnotatedSentence *sentence) {
    for (int i = 0; i < sentence->wordCount(); i++){
        auto* word = (AnnotatedWord*) sentence->getWord(i);
        string wordLowercase = Word::toLowerCase(word->getName());
        if (word->getNamedEntity() == nullptr && word->getParse() != nullptr){
            if (Word::isTime(wordLowercase)){
                word->setNamedEntityType("TIME");
                if (i > 0){
                    auto* previous = (AnnotatedWord*) sentence->getWord(i - 1);
                    if (previous->getParse()->containsTag(MorphologicalTag::CARDINAL)){
                        previous->setNamedEntityType("TIME");
                    }
                }
            }
        }
    }
}

/**
 * The method checks for the MONEY entities using regular expressions. After that, if the expression is a MONEY
 * expression, it also assigns the previous text, which may included numbers or some monetarial texts, MONEY tag.
 * @param sentence The sentence for which MONEY named entities checked.
 */
void TurkishSentenceAutoNER::autoDetectMoney(AnnotatedSentence *sentence) {
    for (int i = 0; i < sentence->wordCount(); i++){
        auto* word = (AnnotatedWord*) sentence->getWord(i);
        string wordLowercase = Word::toLowerCase(word->getName());
        if (word->getNamedEntity() == nullptr && word->getParse() != nullptr){
            if (Word::isMoney(wordLowercase)) {
                word->setNamedEntityType("MONEY");
                int j = i - 1;
                while (j >= 0){
                    auto* previous = (AnnotatedWord*) sentence->getWord(j);
                    if (previous->getParse() != nullptr && (previous->getName() == "amerikan" || previous->getParse()->containsTag(MorphologicalTag::REAL) || previous->getParse()->containsTag(MorphologicalTag::CARDINAL) || previous->getParse()->containsTag(MorphologicalTag::NUMBER))){
                        previous->setNamedEntityType("MONEY");
                    } else {
                        break;
                    }
                    j--;
                }
            }
        }
    }

}
