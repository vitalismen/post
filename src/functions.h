#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include <QString>
namespace my {
QString base64_plus(QString& arg);
QString base64_minus(QString& arg);
QString base64_plus(QString&& arg);
QString base64_minus(QString&& arg);
}
#endif // FUNCTIONS_H
