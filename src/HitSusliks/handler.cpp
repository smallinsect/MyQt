#include "handler.h"

Handler *Handler::handler = new Handler();

Handler *Handler::getInstance()
{
    return handler;
}

void Handler::addScore()
{
    emit beatMouse();
}

Handler::Handler(QObject *parent) : QObject(parent)
{

}
