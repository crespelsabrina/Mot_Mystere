#include "MM.h"
#include <iostream>
#include <fstream>
#include <ctime>
#include <cstdlib>
#include <QDebug>

using namespace std;


/*-------------------------------------------------------------------*/

MM::MM(QObject *parent): QObject(parent), m_attempt(7)
{
    srand( time(NULL) * clock() );
}

QStringList MM::getWordAlreadyPlayed() const
{
    return m_alreadyPlayed;
}

QString MM::getWordProposed() const
{
    return m_wordProposed;
}

/*------------------------------------------------------------------*/

int MM::getDifficulty() const
{
    return m_difficulty;
}

void MM::setDifficulty(int difficulty)
{
    if (m_difficulty == difficulty)
        return;

    m_difficulty = difficulty;
    emit difficultyChanged(m_difficulty);
}

/*-------------------------------------------------------------------*/

void MM::setWordAlreadyPlayed(QStringList alreadyPlayed)
{
    if (m_alreadyPlayed == alreadyPlayed)
        return;

    m_alreadyPlayed = alreadyPlayed;
    emit wordAlreadyPlayedChanged(m_alreadyPlayed);
}

void MM::setWordProposed(QString wordProposed)
{
    if (m_wordProposed == wordProposed)
        return;

    m_wordProposed = wordProposed;
    emit wordProposedChanged(m_wordProposed);
}

/*-------------------------------------------------------------------*/

void MM::setShuffleWord(QString shuffleWord)
{
    if (m_shuffleWord == shuffleWord)
        return;

    m_shuffleWord = shuffleWord;
    emit shuffleWordChanged(m_shuffleWord);
}

QString MM::getShuffleWord() const
{
    return m_shuffleWord;
}

/*-------------------------------------------------------------------*/

QString MM::getMotMystere() const
{
    return m_motMystere;
}

void MM::setMotMystere(QString motMystere)
{
    if (m_motMystere == motMystere)
        return;

    m_motMystere = motMystere;
    emit motMystereChanged(m_motMystere);
}

/*-------------------------------------------------------------------*/

int MM::getAttempt() const
{
    return m_attempt;
}

QString MM::getWordFromDico(const QStringList &dico)
{
    long i_WordSeleted;
    int selectParsed;
    int parsedDico = (dico.size() - 1) / RAND_MAX;

    //On test si on a besoin de decouper le dico en segments de randmax.
    if (parsedDico > 1)
    {
        int lastParsed = (dico.size() - 1) % RAND_MAX;
        // si on a pas de reste dans notre découpage
        if ( lastParsed == 0 )
        {
            parsedDico--;
            selectParsed = rand() % parsedDico;

            i_WordSeleted = selectParsed * RAND_MAX + rand();
            // On choisi un mot aléatoirement dans un segment selectionné aléatoiremment
        }
        else
        {
            selectParsed = rand() % parsedDico;

            // Si on est pas sur le dernier segment
            if ( selectParsed < parsedDico )
            {
                i_WordSeleted = selectParsed * RAND_MAX + rand();
                // On choisi un mot aléatoirement dans un segment selectionné aléatoiremment, sauf le dernier
            }

            else
            {
                // On choisi un mot aléatoirement dans le dernier segment
                i_WordSeleted = selectParsed * RAND_MAX + rand() % lastParsed;
            }
        }
    }

    else
    {
        i_WordSeleted = rand() % ( dico.size() - 1 );
        //cas normal
    }
    wordSelected = dico[ i_WordSeleted ];
    return wordSelected;
}

QString MM::melangerLettres(QString mot)
{
    QString melange;
    int i(0);

    //Tant qu'on n'a pas extrait toutes les lettres du mot
    while (mot.size() > 0)
    {
        //On choisit un numéro de lettre au hasard dans le mot
        i = rand() % ( mot.size() );
        //On ajoute la lettre dans le mot mélangé
        melange += mot[ i ];
        //On retire cette lettre du mot mystère pour ne pas la prendre une deuxième fois
        mot.remove( i, 1 );
    }
    //On renvoie le mot mélangé
    return melange;
}

void MM::setAttempt(int attempt)
{
    if (m_attempt == attempt)
        return;

    m_attempt = attempt;
    emit attemptChanged(m_attempt);
}

QString MM::getWordSelected() const
{
    return wordSelected;
}



