#include "browser_letter_in.h"

browser_letter_in::browser_letter_in(letter_in *arg, QWidget *parent) : QDialog(parent)
{
    this->setWindowTitle("Входящий документ:");
    this->setWindowIcon(QIcon(":/images/KlogoS.png"));
    _data =arg;
    QBoxLayout* main_lay = new QBoxLayout(QBoxLayout::TopToBottom);
    QString data_doc_in_number = "Входящий номер документа: " + _data->get_doc_in_number();
    QLabel* doc_in_number = new QLabel(data_doc_in_number);   // Входящий номер документа
    QString data_d_o_number = "Исходящий № док-та: " + _data->get_doc_out_number();
    QLabel* d_o_number = new QLabel(data_d_o_number);      // Исходящий № док-та
    QString data_in_date = "Дата поступившего документа: " + _data->get_in_date().toString();
    QLabel* in_date = new QLabel(data_in_date);         // Дата поступившего документа
    QString data_send_rec = "Корреспондент (откуда поступил документ): " + _data->get_send_rec();
    QLabel* send_rec = new QLabel(data_send_rec);        // Корреспондент (откуда поступил документ)
    QString data_cont = "Краткое содержание: " + _data->get_content();
    QLabel* cont = new QLabel(data_cont);            // Краткое содержание
    QString data_recipient = "Кому передан документ: " + _data->get_recipient();
    QLabel* recipient = new QLabel(data_recipient);       // Кому передан документ
    QString data_reception_date = "Дата получения: " + _data->get_reception_date().toString();
    QLabel* reception_date = new QLabel(data_reception_date);  // Дата получения
    QString data_work = "Ответственный исполнитель: " + _data->get_worker();
    QLabel* work = new QLabel(data_work);            // Ответственный исполнитель
    QString date_reg_date = "Дата Регистрации: " + _data->get_sys_data().toString();
    QLabel* reg_date = new QLabel(date_reg_date);

    QLabel *controllab = new QLabel("На контроле:");
    _controlbox = new QCheckBox();      // Поставлен ли на контроль
    if (_data->is_control()){
        _controlbox->setCheckState(Qt::Checked);
    }
    QBoxLayout* one_lay = new QBoxLayout(QBoxLayout::LeftToRight);
    QBoxLayout* two_lay = new QBoxLayout(QBoxLayout::LeftToRight);
    QBoxLayout* three_lay = new QBoxLayout(QBoxLayout::LeftToRight);
    one_lay->addWidget(doc_in_number);
    one_lay->addWidget(d_o_number);
    two_lay->addWidget(in_date);
    two_lay->addWidget(reception_date);
    three_lay->addWidget(controllab);
    three_lay->addWidget(_controlbox);
// Кнопка просмотра изображений
        QPushButton *image_key = new QPushButton("Изображения...");
        QObject::connect(image_key, SIGNAL(clicked()), this, SLOT(slot_list_images()));
        three_lay->addSpacing(100);
        three_lay->addWidget(image_key);
// Финальные кнопочки
        QPushButton *ok_key = new QPushButton("Готово");
        QObject::connect(ok_key, SIGNAL(clicked()), this, SLOT(slot_save()));
    main_lay->addLayout(one_lay);
    main_lay->addLayout(two_lay);
    main_lay->addWidget(send_rec);
    main_lay->addWidget(reg_date);
    main_lay->addWidget(cont);
    main_lay->addWidget(recipient);
    main_lay->addWidget(work);
    main_lay->addLayout(three_lay);
    main_lay->addWidget(ok_key);
    this->setLayout(main_lay);
}
letter_in* browser_letter_in::result() const
{
    return _data;
}
void browser_letter_in::slot_save()
{
    if (Qt::Checked == _controlbox->checkState()){  // Поставлен ли на контроль
        _data->set_control(true);
    } else {
        _data->set_control(false);
    }
    emit accept();
}
void browser_letter_in::slot_list_images()
{
    images_browser* imed = new images_browser(_data->get_images_list(), _data->get_inv(), img_status::in_foto);
    if (imed->exec() == QDialog::Accepted){
     _data->set_images_list(imed->result());
    }
}
