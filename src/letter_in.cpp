#include "letter_in.h"

letter_in::letter_in()
{
    _doc_out_number = "";
    _send_rec = "";
    _content = "";
    _worker = "";
    _sys_data.currentDate();
    _fix = false;
    _col = 8;
    _doc_in_number = "";
    _in_date = QDate(0,0,0);
    _recipient = "";
    _reception_date = QDate(0,0,0);
    _control = false;
    //_image_list() = QList<doc_image*>();
}
letter_in::letter_in(const letter_in &arg)
{
    _doc_out_number = arg.get_doc_out_number();
    _send_rec = arg.get_send_rec();
    _content = arg.get_content();
    _worker = arg.get_worker();
    _sys_data = arg.get_sys_data();
    _fix = arg.is_fix();
    _col = arg.get_col();
    _doc_in_number = arg.get_doc_in_number();
    _in_date = arg.get_in_date();
    _recipient = arg.get_recipient();
    _reception_date = arg.get_reception_date();
    _control = arg.is_control();
    _hash_label = arg.get_inv();
    _image_list = arg.get_images_list();
}
letter_in &letter_in::operator=(const letter_in &arg)
{
    _doc_out_number = arg.get_doc_out_number();
    _send_rec = arg.get_send_rec();
    _content = arg.get_content();
    _worker = arg.get_worker();
    _sys_data = arg.get_sys_data();
    _fix = arg.is_fix();
    _col = arg.get_col();
    _doc_in_number = arg.get_doc_in_number();
    _in_date = arg.get_in_date();
    _recipient = arg.get_recipient();
    _reception_date = arg.get_reception_date();
    _hash_label = arg.get_inv();
    _image_list = arg.get_images_list();
    return *this;
}
QString letter_in::get_doc_in_number() const
{
    return _doc_in_number;
}
void letter_in::set_doc_in_number(QString arg)
{
    if (!_fix) {
        _doc_in_number = arg;
    }
}
QDate letter_in::get_in_date() const
{
    return _in_date;
}
void letter_in::set_in_date(QDate arg)
{
    if (!_fix) {
        _in_date = arg;
    }
}
QString letter_in::get_recipient() const
{
    return _recipient;
}
void letter_in::set_recipient(QString arg)
{
    if (!_fix) {
        _recipient = arg;
    }
}
QDate letter_in::get_reception_date() const
{
    return _reception_date;
}
void letter_in::set_reception_date(QDate arg)
{
    if (!_fix) {
        _reception_date = arg;
    }
}
bool letter_in::is_control() const
{
    return _control;
}
void letter_in::set_control(bool arg)
{
    _control = arg;
}

