#include "settings.h"
settings::settings()
{
    _images_dir = "docs/";
    _db_dir = "data/data.db3";
    QFile tester(_db_dir);
    if (!tester.exists()){ create_base();}
    _db = QSqlDatabase::addDatabase("QSQLITE");
    _db.setDatabaseName(_db_dir);
    if(!_db.open()){ QMessageBox::information(nullptr, "Внимание", "База данных не открывается data.db3");}
}
QString settings::get_img_dir() const
{
    return _images_dir;
}
QString settings::get_db_dir() const
{
    return _db_dir;
}
QSqlDatabase& settings::get_db()
{
    return _db;
}
void settings::create_base()
{
    QDir my_dir;
    QString upatch = QDir::homePath();
    my_dir.mkdir("docs");
    my_dir.mkdir("data");
    QSqlDatabase temp_db = QSqlDatabase::addDatabase("QSQLITE");
    temp_db.setDatabaseName("data/data.db3");
    if(!temp_db.open()){ QMessageBox::information(nullptr, "Внимание", "База данных не открывается data.db3");}
    QSqlQuery query;
    QString prep = "CREATE TABLE out_data (doc_out_number TEXT UNIQUE NOT NULL, send_rec TEXT, content TEXT, worker TEXT, sys_data INTEGER, fix TEXT, blank_number TEXT UNIQUE, notice TEXT, label_uniq TEXT UNIQUE NOT NULL, inq INTEGER PRIMARY KEY AUTOINCREMENT UNIQUE NOT NULL);";
        if (!query.exec(prep)) {
            QMessageBox::information(nullptr, "Внимание", "База данных пуста и не удается создать таблицу in_data");
        }
        prep = "CREATE TABLE in_data (doc_out_number TEXT, send_rec TEXT, content TEXT, worker TEXT, sys_data INTEGER, fix TEXT, doc_in_number TEXT UNIQUE NOT NULL, in_date INTEGER, recipient TEXT, reception_date INTEGER, control TEXT, label_uniq TEXT UNIQUE NOT NULL, inq INTEGER PRIMARY KEY AUTOINCREMENT UNIQUE NOT NULL);";
            if (!query.exec(prep)) {
                QMessageBox::information(nullptr, "Внимание", "База данных пуста и не удается создать таблицу out_data");
            }
// doc_out TEXT - номер документа, adr_str TEXT - имя файла, uniq_str - тип хранения (пока свободно), im_hash TEXT - хэш картинки
       QString prep2 = "CREATE TABLE out_foto (label_uniq TEXT, adr_str TEXT, uniq_str TEXT, im_hash TEXT, inq INTEGER PRIMARY KEY AUTOINCREMENT UNIQUE NOT NULL);";
            if (!query.exec(prep2)) {
                QMessageBox::information(nullptr, "Внимание", "База данных пуста и не удается создать таблицу out_foto");
            }
        prep2 = "CREATE TABLE in_foto (label_uniq TEXT, adr_str TEXT, uniq_str TEXT, im_hash TEXT, inq INTEGER PRIMARY KEY AUTOINCREMENT UNIQUE NOT NULL);";
            if (!query.exec(prep2)) {
                QMessageBox::information(nullptr, "Внимание", "База данных пуста и не удается создать таблицу in_foto");
            }
    temp_db.close();
}
