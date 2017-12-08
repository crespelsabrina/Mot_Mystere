#ifndef UTILE_H
#define UTILE_H

#include <QStringList>
#include <vector>

class Utile
{
    // Pas besoin de constructeurs puisque tous les membres son statiques

public:
    // 3 - Récupération de lignes d'un fichier
    static void setLinesInFile (const QString &url, const QStringList &sl);
    static QStringList getLinesFromFile(const QString &url);

    // 2 - Récupération de fichier d'un dossier
    static QStringList listFiles(QString dirname, QString filter = "*.*");
    static QStringList listFilesFromFileDialog(QString dirname, QString filter = "*.*");

    // 1 - Debug initiaux de tableaux d'entiers
    static void affichageTab(const std::vector<int>& tab);
    static void afficheTabTab (const std::vector<std::vector<int>>& tab);
};

#endif // UTILE_H
