#ifndef MYCONTEXT_H
#define MYCONTEXT_H

#include <QObject>
#include <QString>
#include <QDebug>
#include <QQmlContext>
#include "MM.h"

class MyContext : public QObject
{
    Q_OBJECT
    Q_PROPERTY(MM* mm READ getMm WRITE setMm NOTIFY mMChanged)
    Q_PROPERTY(QString score READ getScore WRITE setScore NOTIFY scoreChanged)
    Q_PROPERTY(QStringList wordList READ getWordList WRITE setWordList NOTIFY wordListChanged)


public:

    explicit MyContext(QObject *parent = nullptr);

    /* *** fonctions de liasion CPP -> QML *** */
    Q_INVOKABLE void test (int texte);
    void updateWordList();

    MM *getMm() const;

    QString getScore() const;
    QString getWordSelected() const;
    QStringList getWordList() const;

signals:

    void sendtoQML (QString texte);
    void mMChanged(MM* mm);
    void scoreChanged(QString score);
    void wordListChanged(QStringList wordList);

private:

    MM* m_mm;

    QString getRepertoireProjet(bool trace);
    QString m_score;
    QString wordSelected;
    QStringList m_wordList;

    QQmlContext* m_context;


public slots:

    /* *** fonctions de liaison QML -> CPP *** */
    void receivedFromQMl(QString texte);
    void setMm(MM* mm);
    void setScore(QString score);
    void setWordList(QStringList wordList);

    bool isWin(QString text);
    QString openDico();
    QString check(QString submitWord);

};

#endif // MYCONTEXT_H
