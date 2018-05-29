#include "items_fabrica.h"

items_fabrica::items_fabrica()
{
}
letter_in* items_fabrica::create_let_in()
{
    letter_in *ret = new letter_in();
    return ret;
}
letter_out* items_fabrica::create_let_out()
{
    letter_out *ret = new letter_out();
    return ret;
}
