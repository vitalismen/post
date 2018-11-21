#ifndef LETTER_H
#define LETTER_H

#include <QString>
#include <QDate>
#include <QVariant>
#include <QImage>
#include <QList>
#include <QFile>
#include <QMessageBox>
#include <random>
#include <memory>
#include "settings.h"
#include "doc_image.h"

class letter
{
public:
    letter();
    letter(const letter& arg);
    letter(const letter&& arg);
    letter& operator=(const letter&);
    letter& operator=(letter&&);
    QString get_doc_out_number() const;
    void set_doc_out_number(const QString& arg);
    QString get_send_rec() const;
    void set_send_rec(const QString& arg);
    QString get_content()const;
    void set_content(const QString& arg);
    QString get_worker() const;
    void set_worker(const QString &arg);
    QDate get_sys_data() const;
    void set_sys_data(QDate arg);
    void set_fix();
    bool is_fix() const;
    int get_col() const;
    void add_images(doc_image* arg);
    void clear_images_list();
    QList<doc_image*> get_images_list() const;
    void set_images_list(QList<doc_image*> arg);
    QString get_inv() const;  //Эта функция возвращает уникальной для данного вида писем поле
    void set_inv(const QString& arg);
protected:
    QString _doc_out_number; // Исходящий  № док-та
    QString _send_rec;       // Корреспондент (кому направлен / откуда поступил документ)
    QString _content;        // Краткое содержание
    QString _worker;         // Ответственный исполнитель
    QDate _sys_data;         // Системная отметка времени
    QString _hash_label;     // Уникальная метка
    bool _fix;               // Можно ли редактировать докмент ("проведён" ли он, после фиксации редактировать нельзя)
    int _col;                // Колличество колонок (будет разное у разных дочерних классов)
    QList<doc_image*> _image_list; // Сканы документов.
};
Q_DECLARE_METATYPE(letter*)
#endif // LETTER_H
