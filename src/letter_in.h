#ifndef LETTER_IN_H
#define LETTER_IN_H

#include <QString>
#include <QDate>
#include <QVariant>
#include "letter.h"

class letter_in : public letter
{
public:
    letter_in();
    letter_in(const letter_in &arg);
    letter_in &operator=(const letter_in &arg);
    QString get_doc_in_number() const;
    void set_doc_in_number(QString arg);
    QDate get_in_date() const;
    void set_in_date(QDate arg);
    QString get_recipient() const;
    void set_recipient(QString arg);
    QDate get_reception_date() const;
    void set_reception_date(QDate arg);
    bool is_control() const;
    void set_control(bool arg) ;
private:
    QString _doc_in_number;   // Входящий номер документа
    QDate _in_date;           // Дата поступившего документа
    QString _recipient;       // Кому передан документ
    QDate _reception_date;    // Дата получения
    bool _control;            // Взятие на контроль/снятие с контроля

};
Q_DECLARE_METATYPE(letter_in*)
Q_DECLARE_METATYPE(letter_in)
#endif // LETTER_IN_H
