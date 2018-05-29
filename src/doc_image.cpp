#include "doc_image.h"

doc_image::doc_image(img_status ims)
{
    set_type(ims);
    _uniq_str = "";
    _adr_str = "";
    number_doc = "";
}
doc_image::doc_image(const QImage &arg, const QString& adr, const QString& arg_number, img_status ims)
{
    set_type(ims);
    QString tmp1;
    tmp1.append(adr.at(0));
    tmp1.append(adr.at(1));
    QString tmp2;
    tmp2.append(type.at(0));
    tmp2.append(type.at(1));
    if (tmp1 == tmp2){
        _adr_str = adr;
    } else {
        _adr_str = type + "_" + adr;
    }
    number_doc = arg_number;
    settings& setd = settings::getInatance();
    QSqlDatabase& my_db = setd.get_db();
    QSqlQuery query(my_db);
    QString tmp_query;
        _uniq_str = "file";
        arg.save("docs/" + _adr_str + ".png", "png");
        if (type == "out"){
            tmp_query = "INSERT INTO out_foto(label_uniq, adr_str, uniq_str, im_hash) VALUES('" + number_doc + "', '" + _adr_str + "', '" + _uniq_str + "', '__" + "');";
        } else if (type == "in"){
            tmp_query = "INSERT INTO in_foto(label_uniq, adr_str, uniq_str, im_hash) VALUES('" + number_doc + "', '" + _adr_str + "', '" + _uniq_str + "', '__" + "');";
        }
        if (!query.exec(tmp_query)){
            QMessageBox::information(0, "Внимание", "Что-то не то с сохранением doc_image");
        }
}
bool doc_image::set_image(const QImage& arg, const QString& adr, const QString& number, img_status ims)
{
    set_type(ims);
    QString tmp1;
    tmp1.append(adr.at(0));
    tmp1.append(adr.at(1));
    QString tmp2;
    tmp2.append(type.at(0));
    tmp2.append(type.at(1));
    if (tmp1 == tmp2){
        _adr_str = adr;
    } else {
        _adr_str = type + "_" + adr;
    }
    number_doc = number;
    settings& setd = settings::getInatance();
    QSqlDatabase& my_db = setd.get_db();
    QSqlQuery query(my_db);
    _uniq_str = "file";
    QString tmp_query;
    arg.save("docs/" + _adr_str + ".png", "png");
    if (type == "out"){
        tmp_query = "INSERT INTO out_foto(label_uniq TEXT, adr_str TEXT, uniq_str TEXT, im_hash TEXT) VALUES ('" + number_doc + "', '" +
                _adr_str + "', '" + _uniq_str + "', '__" + "');";
    } else if (type == "in"){
        tmp_query = "INSERT INTO in_foto(label_uniq TEXT, adr_str TEXT, uniq_str TEXT, im_hash TEXT) VALUES ('" + number_doc + "', '" +
                   _adr_str + "', '" + _uniq_str + "', '__" + "');";
    }
    if (!query.exec(tmp_query)){
        QMessageBox::information(0, "Внимание", "Что-то не то с сохранением img_set");
        return false;
    }
    return true;
}
QImage doc_image::get_image() const
{
    return QImage("docs/" + _adr_str + ".png", "png");
}
void doc_image::del_image()
{
    if (_uniq_str == ""){
        throw "I don't know what type";
    } else if (_uniq_str == "file"){
        QFile del_fail("docs/" + _adr_str + ".png");
        del_fail.remove();
        del_fail.close();
        settings& setd = settings::getInatance();
        QSqlDatabase& my_db = setd.get_db();
        QSqlQuery query(my_db);
        if (type == "out"){
            query.exec("DELETE FROM out_foto WHERE adr_str = '" + _adr_str + "';");
        } else if (type == "in"){
            query.exec("DELETE FROM in_foto WHERE adr_str = '" + _adr_str + "';");
        }
        _uniq_str = "";
        _adr_str ="";
        type = "del";
    }
}
void doc_image::set_type(img_status ims)
{
    if (ims == img_status::in_foto){
        type = "in";
    } else if (ims == img_status::out_foto) {
        type = "out";
    } else {
        throw "you cannot create a picture without a type";
    }
}
void im_type_set(QImage& arg)
{

}
void im_hash(QImage& arg)
{

}
void doc_image::set_number_doc(const QString& arg)
{
    number_doc = arg;
}
QString doc_image::get_type() const
{
    return type;
}
QString doc_image::get_number_doc() const
{
    return number_doc;
}
void doc_image::set_uniq(const QString& arg)
{
    _uniq_str = arg;
}
void doc_image::set_adr(const QString& arg)
{
    QString tmp1;
    tmp1.append(arg.at(0));
    tmp1.append(arg.at(1));
    QString tmp2;
    tmp2.append(type.at(0));
    tmp2.append(type.at(1));
    if (tmp1 == tmp2){
        _adr_str = arg;
    } else {
        _adr_str = type + "_" + arg;
    }
}
QString doc_image::get_adr() const
{
    return _adr_str;
}
QString doc_image::get_uniq() const
{
    return _uniq_str;
}
