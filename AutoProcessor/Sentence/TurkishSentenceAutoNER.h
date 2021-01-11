//
// Created by olcay on 2.05.2019.
//

#ifndef ANNOTATEDSENTENCE_TURKISHSENTENCEAUTONER_H
#define ANNOTATEDSENTENCE_TURKISHSENTENCEAUTONER_H

#include "SentenceAutoNER.h"

class TurkishSentenceAutoNER : public SentenceAutoNER{
protected:
    void autoDetectPerson(AnnotatedSentence* sentence) override;
    void autoDetectLocation(AnnotatedSentence* sentence) override;
    void autoDetectOrganization(AnnotatedSentence* sentence) override;
    void autoDetectTime(AnnotatedSentence* sentence) override;
    void autoDetectMoney(AnnotatedSentence* sentence) override;
};


#endif //ANNOTATEDSENTENCE_TURKISHSENTENCEAUTONER_H
