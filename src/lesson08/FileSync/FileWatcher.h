#ifndef FILEWATCHER_H
#define FILEWATCHER_H

#include <QDir>
#include <QDebug>
#include <QObject>
#include <QFileSystemWatcher>

class FileWatcher : public QObject
{
    Q_OBJECT
public:
    explicit FileWatcher(QObject *parent = 0);
    void setWatchPath(const QString &path);
private:
    QStringList files();

signals:
    void doFileAdded(const QString &file);
    void doFileRemoved(const QString &file);
    void doFileChanged(const QString &file);
    void doFileRenamed(const QString &oldName, const QString &newName);
public slots:
    void onDirectoryChanged(const QString &path);
    void onFileChanged(const QString &path);

private:
    QFileSystemWatcher watcher;
    QString pathWatch;
};

#endif // FILEWATCHER_H
