#ifndef MM_H
#define MM_H

#include <QObject>



class MM : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString motMystere READ getMotMystere WRITE setMotMystere NOTIFY motMystereChanged)
    Q_PROPERTY(QStringList wordAlreadyPlayed READ getWordAlreadyPlayed WRITE setWordAlreadyPlayed NOTIFY wordAlreadyPlayedChanged)
    Q_PROPERTY(QString wordProposed READ getWordProposed WRITE setWordProposed NOTIFY wordProposedChanged)
    Q_PROPERTY(int difficulty READ getDifficulty WRITE setDifficulty NOTIFY difficultyChanged)
    Q_PROPERTY(QString shuffleWord READ getShuffleWord WRITE setShuffleWord NOTIFY shuffleWordChanged)
    Q_PROPERTY(int attempt READ getAttempt WRITE setAttempt NOTIFY attemptChanged)


    QStringList m_alreadyPlayed;

    QString m_wordProposed;

    int m_difficulty;

    QString m_shuffleWord;

    QString m_motMystere;

    int m_attempt;


public:
    MM(QObject *parent = nullptr);

    QStringList getWordAlreadyPlayed() const;
    QString getWordProposed() const;
    int getDifficulty() const;
    QString getShuffleWord() const;
    QString getMotMystere() const;
    int getAttempt() const;

    QString getWordFromDico( const QStringList &dico );

    // fonctions principales
    QString getWordSelected() const;
    QString melangerLettres(QString mot);

signals:
    void wordAlreadyPlayedChanged(QStringList alreadyPlayed);

    void wordProposedChanged(QString wordProposed);

    void difficultyChanged(int difficulty);

    void shuffleWordChanged(QString shuffleWord);

    void motMystereChanged(QString motMystere);

    void attemptChanged(int attempt);

public slots:

    void setWordAlreadyPlayed(QStringList alreadyPlayed);
    void setWordProposed(QString wordProposed);
    void setDifficulty(int difficulty);
    void setShuffleWord(QString shuffleWord);
    void setMotMystere(QString motMystere);
    void setAttempt(int attempt);

private :
    QString wordSelected;
};

#endif // MM_H
