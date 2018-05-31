#ifndef SETTINGS_H
#define SETTINGS_H

#include <QString>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QFile>
#include <QDir>
#include <QMessageBox>
#include <QFileDialog>
#include <QTextStream>

class settings
{
public:
    static settings& getInatance(){
        static settings _instance;
        return _instance;
    }
    QString get_img_dir() const;
    QString get_db_dir() const;
    QSqlDatabase& get_db();
private:
    settings();
    settings(const settings&);
    settings& operator=(settings&);
    void create_base();
    QString choise_set_path();
    // Переменные для хранения разных настроек
    QString _images_dir;
    QString _db_dir;
    QString set_path;
    QString db_path;
    QSqlDatabase _db;
};

#endif // SETTINGS_H
