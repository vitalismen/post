#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include <QString>
#include <QImage>
namespace my {
QString base64_plus(const QString&);
QString base64_minus(const QString&);
QString base64_plus(QString&&);
QString base64_minus(QString&&);
QString im_hash(const QImage&);
}
#endif // FUNCTIONS_H
