#ifndef BROWSER_LETTER_IN_H
#define BROWSER_LETTER_IN_H

#include <QObject>
#include <QWidget>
#include <QDialog>
#include <QCheckBox>
#include <QLabel>
#include <QBoxLayout>
#include <QPushButton>
#include "images_browser.h"
#include "letter_in.h"
#include "declaration.h"
// Класс который выводит в окошке информацию о входящем документе.
class browser_letter_in : public QDialog
{
    Q_OBJECT
public:
    browser_letter_in(letter_in *arg, QWidget *parent = nullptr);
    letter_in* result() const;
private:
    letter_in* _data;            // Данные
    QCheckBox* _controlbox;      // Поставлен ли на контроль
public slots:
    void slot_save();
    void slot_list_images();
};

#endif // BROWSER_LETTER_IN_H
