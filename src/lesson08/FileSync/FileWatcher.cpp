#include "FileWatcher.h"

FileWatcher::FileWatcher(QObject *parent) : QObject(parent)
{

    connect(&watcher, SIGNAL(directoryChanged(QString)),
            this, SLOT(onDirectoryChanged(QString)));
    connect(&watcher, SIGNAL(fileChanged(QString)),
            this, SLOT(onFileChanged(QString)));
}

void FileWatcher::setWatchPath(const QString &path)
{
    pathWatch = path;
    watcher.addPath(path);
}

QStringList FileWatcher::files()
{

    QDir dir(path);
    QFileInfoList infoList = dir.entryInfoList(QDir::Files);
    QString ret;

    foreach (QFileInfo info, infoList) {

    }
}

void FileWatcher::onDirectoryChanged(const QString &path)
{
    qDebug() << "directory changed" << path;
}

void FileWatcher::onFileChanged(const QString &path)
{
    qDebug() << "file changed" << path;
}
