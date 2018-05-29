#ifndef BROWSER_LETTER_OUT_H
#define BROWSER_LETTER_OUT_H

#include <QObject>
#include <QWidget>
#include <QDialog>
#include <QCheckBox>
#include <QLabel>
#include <QBoxLayout>
#include <QPushButton>
#include "images_browser.h"
#include "letter_out.h"
#include "declaration.h"

class browser_letter_out : public QDialog
{
    Q_OBJECT
public:
    browser_letter_out(letter_out *arg, QWidget *parent = nullptr);
    letter_out* result() const;
public slots:
    void slot_save();
    void slot_list_images();
private:
    letter_out* _data;           // Данные
};

#endif // BROWSER_LETTER_OUT_H
