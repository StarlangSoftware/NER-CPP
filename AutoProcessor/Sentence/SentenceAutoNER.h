//
// Created by olcay on 2.05.2019.
//

#ifndef ANNOTATEDSENTENCE_SENTENCEAUTONER_H
#define ANNOTATEDSENTENCE_SENTENCEAUTONER_H

#include "AutoNER.h"
#include "AnnotatedSentence.h"

/**
 * Abstract class to detect named entities in a sentence automatically. By implementing 5 abstract methods,
 * the class can detect (i) Person, (ii) Location, (iii) Organization, (iv) Money, (v) Time.
 * Each method tries to detect those named entities and if successful, sets the correct named entity for the word.
 * Anything that is denoted by a proper name, i. e., for instance, a person, a location, or an organization,
 * is considered to be a named entity. In addition, named entities also include things like dates, times,
 * or money. Here is a sample text with named entities marked:
 * [$_{ORG}$ Türk Hava Yolları] bu [$_{TIME}$ Pazartesi'den] itibaren [$_{LOC}$ İstanbul] [$_{LOC}$ Ankara]
 * güzergahı için indirimli satışlarını [$_{MONEY}$ 90 TL'den] başlatacağını açıkladı.
 * This sentence contains 5 named entities including 3 words labeled as ORGANIZATION, 2 words labeled as
 * LOCATION, 1 word labeled as TIME, and 1 word labeled as MONEY.
 * */
class SentenceAutoNER : public AutoNER {
protected:
    /**
     * The written method should detect PERSON named entities. PERSON corresponds to people or
     * characters. Example: {\bf Atatürk} yurdu düşmanlardan kurtardı.
     * @param sentence The sentence for which PERSON named entities checked.
     */
    virtual void autoDetectPerson(AnnotatedSentence* sentence) = 0;

    /**
     * The written method should detect LOCATION named entities. LOCATION corresponds to regions,
     * mountains, seas. Example: Ülkemizin başkenti {\bf Ankara'dır}.
     * @param sentence The sentence for which LOCATION named entities checked.
     */
    virtual void autoDetectLocation(AnnotatedSentence* sentence) = 0;

    /**
     * The written method should detect ORGANIZATION named entities. ORGANIZATION corresponds to companies,
     * teams etc. Example:  {\bf IMKB} günü 60 puan yükselerek kapattı.
     * @param sentence The sentence for which ORGANIZATION named entities checked.
     */
    virtual void autoDetectOrganization(AnnotatedSentence* sentence) = 0;

    /**
     * The written method should detect MONEY named entities. MONEY corresponds to monetarial
     * expressions. Example: Geçen gün {\bf 3000 TL} kazandık.
     * @param sentence The sentence for which MONEY named entities checked.
     */
    virtual void autoDetectMoney(AnnotatedSentence* sentence) = 0;

    /**
     * The written method should detect TIME named entities. TIME corresponds to time
     * expressions. Example: {\bf Cuma günü} tatil yapacağım.
     * @param sentence The sentence for which MONEY named entities checked.
     */
    virtual void autoDetectTime(AnnotatedSentence* sentence) = 0;

public:
    void autoNER(AnnotatedSentence* sentence);
};


#endif //ANNOTATEDSENTENCE_SENTENCEAUTONER_H
