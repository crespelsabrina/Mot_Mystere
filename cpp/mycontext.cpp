#include "mycontext.h"
#include "utile.h"

#include <QApplication>
#include <QPushButton>
#include <QDebug>
#include <iostream>
#include <string>
#include <vector>
#include <QDir>


using namespace std;


MyContext::MyContext(QObject *parent) : QObject(parent)
{
    m_mm = new MM(this);
}

void MyContext::updateWordList()
{
    // Send the data to Qml
    if( m_context!= nullptr )
        m_context->setContextProperty("modeleWords", QVariant::fromValue( m_wordList ));
    else
        qDebug() << "Context non instancié";
}

/* *** Fonctions QML -> CPP et CPP -> QML *** */

void MyContext::test(int texte)
{
    qDebug() << "test ok";
    qDebug() << QString::number(m_mm->getDifficulty());
}

MM *MyContext::getMm() const
{
    qDebug() << "MyContext::GETMm";
    return m_mm;
}

QString MyContext::getScore() const
{
    return m_score;
}

void MyContext::receivedFromQMl(QString texte)
{
    qDebug() << texte;
}

void MyContext::setMm(MM *mm)
{
    qDebug() << "MyContext::setMm";
    if (m_mm == mm)
        return;

    m_mm = mm;
    emit mMChanged(m_mm);
}

QString MyContext::openDico()
{
    m_mm->setAttempt(7);
    QStringList listmodif;
    setWordList( listmodif );

    QString url;
    int indiceDifficulty = m_mm->getDifficulty();
    url = getRepertoireProjet(0);

    if(indiceDifficulty == 0)
    {
        url += "/files/Dico_Facile.txt";
    }
    else if(indiceDifficulty == 1)
    {
        url += "/files/Dico_Moyen.txt";
        cout << "rrr dicomoytest" << endl;
    }
    else if(indiceDifficulty == 2)
    {
        url += "/files/Dico_Difficile.txt";
    }
    else
    {
        url += "/files/Dico_Expert.txt";
    }

    qDebug() << url << endl;
    QStringList dico;

    dico = Utile::getLinesFromFile(url);
    wordSelected = m_mm->getWordFromDico( dico );

    QString shuffleWord = m_mm->melangerLettres(wordSelected);
    qDebug() << wordSelected << endl;
    qDebug() << shuffleWord << endl;

    return shuffleWord;
}

QString MyContext::check(QString submitWord)
{
    QString etatPartie = "In Progress";
    submitWord = submitWord.toUpper();
    qDebug() << submitWord << endl;
    qDebug() << wordSelected << endl;
    int score = m_mm->getAttempt();

    QStringList listmodif = m_wordList;
    listmodif << submitWord;
    setWordList( listmodif );

    if(wordSelected != submitWord )
    {
        score--;

        m_score = QString::number( score );
        if ( score < 1)
        {
            etatPartie = " Loose : " + wordSelected;
        }
    }
    else
    {
        etatPartie = " Win ";
        score = 7;
        m_score = QString::number( 7 );
    }
    m_mm->setAttempt( score );

    return etatPartie;
}

void MyContext::setScore(QString score)
{
    if (m_score == score)
        return;

    m_score = score;
    emit scoreChanged(m_score);
}

void MyContext::setWordList(QStringList wordList)
{

    if (m_wordList == wordList)
        return;

    m_wordList = wordList;
    emit wordListChanged(m_wordList);
}

QString MyContext::getRepertoireProjet(bool trace)//false
{
    QString repertoireduFichierApplication( qApp->applicationFilePath() );
    if( trace)
        std::cout << "qApp->applicationFilePath() = "<< repertoireduFichierApplication.toLatin1().constData() << std::endl;

    QDir fichier(repertoireduFichierApplication);
    fichier.cdUp() ;
    fichier.cdUp() ;
    if( trace)
        std::cout << "qApp->applicationName() = "<< qApp->applicationName().toLatin1().constData() << std::endl;

    fichier.cd(qApp->applicationName());
    QString repertoireProjet  = fichier.absolutePath() ;
    if( trace)
        std::cout  << "repertoireProjet : " << repertoireProjet.toLatin1().constData() << std::endl;

    return repertoireProjet;
}

QString MyContext::getWordSelected() const
{
    return wordSelected;
}

QStringList MyContext::getWordList() const
{
    return m_wordList;
}

bool MyContext::isWin(QString text)
{

    qDebug() << text;
    return ( text == wordSelected )? true: false;
}




