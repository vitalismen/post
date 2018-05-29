#include "browser_letter_out.h"

browser_letter_out::browser_letter_out(letter_out *arg, QWidget *parent) : QDialog(parent)
{
    this->setWindowTitle("Исходящий документ:");
    this->setWindowIcon(QIcon(":/images/KlogoS.png"));
    _data =arg;
    QBoxLayout* main_lay = new QBoxLayout(QBoxLayout::TopToBottom);
    QString data_d_o_number = "Исходящий № док-та: " + _data->get_doc_out_number();
    QLabel* d_o_number = new QLabel(data_d_o_number);      // Исходящий № док-та
    QString data_send_rec = "Корреспондент (кому направлен): " + _data->get_send_rec();
    QLabel* send_rec = new QLabel(data_send_rec);        // Корреспондент (откуда поступил документ)
    QString data_cont = "Краткое содержание: " + _data->get_content();
    QLabel* cont = new QLabel(data_cont);            // Краткое содержание
    QString data_work = "Ответственный исполнитель: " + _data->get_worker();
    QLabel* work = new QLabel(data_work);            // Ответственный исполнитель
    QString date_reg_date = "Дата Регистрации: " + _data->get_sys_data().toString();
    QLabel* reg_date = new QLabel(date_reg_date);
    QString data_blank_number = "Номер фирменного бланка: " + _data->get_blank_number();
    QLabel* blank_number = new QLabel(data_blank_number);            // Номер фирменного бланка
    QString data_notice = "Примечание: " + _data->get_notice();
    QLabel* notice = new QLabel(data_notice);            // Примечание

    QBoxLayout* one_lay = new QBoxLayout(QBoxLayout::LeftToRight);
    QBoxLayout* three_lay = new QBoxLayout(QBoxLayout::LeftToRight);
    one_lay->addWidget(blank_number);
    one_lay->addWidget(d_o_number);
// Кнопка просмотра изображений
        QPushButton *image_key = new QPushButton("Изображения...");
        QObject::connect(image_key, SIGNAL(clicked()), this, SLOT(slot_list_images()));
// Финальные кнопочки
        QPushButton *ok_key = new QPushButton("Готово");
        QObject::connect(ok_key, SIGNAL(clicked()), this, SLOT(slot_save())); 
        three_lay->addWidget(ok_key);
        three_lay->addSpacing(100);
        three_lay->addWidget(image_key);
    main_lay->addLayout(one_lay);
    main_lay->addWidget(send_rec);
    main_lay->addWidget(reg_date);
    main_lay->addWidget(cont);
    main_lay->addWidget(notice);
    main_lay->addWidget(work);
    main_lay->addLayout(three_lay);
    this->setLayout(main_lay);
}
letter_out* browser_letter_out::result() const
{
    return _data;
}
void browser_letter_out::slot_save()
{
    emit accept();
}
void browser_letter_out::slot_list_images()
{
    images_browser* imed = new images_browser(_data->get_images_list(), _data->get_inv(), img_status::out_foto);
    if (imed->exec() == QDialog::Accepted){
     _data->set_images_list(imed->result());
    }
}
