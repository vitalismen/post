#ifndef ITEMS_FABRICA_H
#define ITEMS_FABRICA_H
#include <QList>
#include "letter_in.h"
#include "letter_out.h"

class items_fabrica
{
public:
    items_fabrica();
    letter_in* create_let_in();
    letter_out* create_let_out();
};

#endif // ITEMS_FABRICA_H
