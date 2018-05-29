#include "letter_out.h"

letter_out::letter_out()
{
    _blank_number = "";
    _notice = "";
    _doc_out_number = "";
    _send_rec = "";
    _content = "";
    _worker = "";
    _sys_data = QDate::currentDate();
    _fix = false;
    _col = 6;
    _image_list = QList<doc_image*>();
}
letter_out::letter_out(const letter_out &arg)
{
    _blank_number = arg.get_blank_number();
    _notice = arg.get_notice();
    _doc_out_number = arg.get_doc_out_number();
    _send_rec = arg.get_send_rec();
    _content = arg.get_content();
    _worker = arg.get_worker();
    _sys_data = arg.get_sys_data();
    _fix = arg.is_fix();
    _col = arg.get_col();
    _hash_label = arg.get_inv();
    _image_list = arg.get_images_list();
}
letter_out &letter_out::operator=(const letter_out &arg)
{
    _blank_number = arg.get_blank_number();
    _notice = arg.get_notice();
    _doc_out_number = arg.get_doc_out_number();
    _send_rec = arg.get_send_rec();
    _content = arg.get_content();
    _worker = arg.get_worker();
    _sys_data = arg.get_sys_data();
    _fix = arg.is_fix();
    _col = arg.get_col();
    _hash_label = arg.get_inv();
    _image_list = arg.get_images_list();
    return *this;
}
QString letter_out::get_blank_number() const
{
    return _blank_number;
}
void letter_out::set_blank_number(QString arg)
{
    if (!_fix) {
        _blank_number = arg;
    }
}
QString letter_out::get_notice() const
{
    return _notice;
}
void letter_out::set_notice(QString arg)
{
    if (!_fix) {
        _notice = arg;
    }
}

