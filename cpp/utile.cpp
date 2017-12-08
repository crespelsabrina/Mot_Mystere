#include "utile.h"

#include <QFile>
#include <QDir>
#include <QTextStream>

#include <QDebug>
#include <iostream>

using namespace std;

// Fonction d'écriture de QStringList (une ligne par QString) dans un fichier.
// Fonction qui génère un nouveau fichier lorsqu'il n'existe pas, ou l'écrase lorsqu'il est présent.
void Utile::setLinesInFile (const QString &url, const QStringList &sl)
{
    QFile saveFile(url);

    if (!saveFile.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        qDebug() << "Ouverture Impossible" << url << "n'a pas pu être ouvert";
    }
    else
    {
        // Création d'un objet QTextStream à partir de notre objet QFile
        QTextStream fluxEcriture( &saveFile );

        // On choisit le codec correspondant au jeu de caractères que l'on souhaite ; ici, UTF-8
        fluxEcriture.setCodec("UTF-8");

        // Écriture des différentes lignes dans le fichier
        for ( QString ligne : sl )
        {
            fluxEcriture << ligne << endl;
        }

        qDebug() << "Save in :" << url;
    }
}

// Fonction de récupération des lignes d'un fichier dans une QStringList.
QStringList Utile::getLinesFromFile(const QString &url)
{
    QStringList sl;

    QFile loadFile (url);

    if (loadFile.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QTextStream fluxLecture(&loadFile);

        while ( !fluxLecture.atEnd() )
        {
            sl << fluxLecture.readLine();
        }
        loadFile.close();
    }
    else
    {
        qDebug() << "Erreur : ouverture du fichier impossible";
    }

    return sl;
}

// Liste les fichiers d'un directory, avec un filtre possible (tout par défaut)
QStringList Utile::listFiles(QString dirname, QString filter /*= "*.*"*/)
{
    QStringList filenameList;

    QDir dir(dirname);

    dir.setNameFilters(QStringList() << filter);

    QFileInfoList list = dir.entryInfoList(QDir::NoDotAndDotDot | QDir::AllEntries);

    for (int i = 0; i < list.size(); ++i)
    {
        QFileInfo fileInfo = list.at(i);

        filenameList << fileInfo.absoluteFilePath();
    }

    return filenameList;
}

// La même chose, avec une url issue d'un FileDialog en QML
QStringList Utile::listFilesFromFileDialog(QString dirname, QString filter /*= "*.*"*/)
{
    dirname.remove(0, 8);
    return listFiles(dirname, filter);
}

// Afficher un tableau d'entiers
void Utile::affichageTab(const vector<int>& tab)
{
    for( auto v : tab)
    {
        cout << v << " ";
    }
    cout << endl;
}

// Afficher un tableau de tableau d'entiers
void Utile::afficheTabTab (const vector<vector<int>>& tab)
{
    for (vector<int> ligneVal : tab)
    {
        for (int val : ligneVal)
        {
            cout << val << " ";
        }
        cout << endl;
    }
}
