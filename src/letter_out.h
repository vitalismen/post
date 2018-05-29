#ifndef LETTER_OUT_H
#define LETTER_OUT_H

#include <QString>
#include <QDate>
#include <QVariant>
#include "letter.h"

class letter_out : public letter
{
public:
    letter_out();
    letter_out(const letter_out &arg);
    letter_out& operator=(const letter_out &arg);
    QString get_blank_number() const;
    void set_blank_number(QString arg);
    QString get_notice() const;
    void set_notice(QString arg);
private:
    QString _blank_number; // Номер фирменного бланка
    QString _notice;       // Примечание
};
Q_DECLARE_METATYPE(letter_out*)
Q_DECLARE_METATYPE(letter_out)
#endif // LETTER_OUT_H
