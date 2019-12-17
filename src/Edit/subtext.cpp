#include "subtext.h"

SubText::SubText(QWidget *parent) : QTextEdit(parent)
{
    file = new QFile(this);
}

void SubText::setCodecName(const QString &codecName)
{
    this->codecName = codecName;
}

void SubText::newFile()
{
    static int icnt = 0;
    QString title = QString("未命名文件[%1][*]").arg(icnt++);
    setWindowTitle(title);

    //处于编辑后，启用星号
    connect(document(), SIGNAL(contentsChanged()),
            this, SLOT(onContentsChanged()));
}

void SubText::openFile()
{
    QString fileName = QFileDialog::getOpenFileName(this, "获取文本文件", ".", "Text(*.cpp *.h *.txt)");
    if(fileName.isEmpty()){
        return ;
    }
    this->fileName = fileName;
    //第一种获取文件名的方式
//    QStringList list = fileName.split("/");
//    QString title = list.last();
    //第二种获取文件名方式
    QFileInfo info(fileName);
    QString title = info.fileName();
    setWindowTitle(title);
    //对文件进行操作
    file->setFileName(fileName);
    int iret = file->open(QIODevice::ReadWrite);
    if(!iret){
        QMessageBox::warning(this, "提示", "打开文件失败");
        return ;
    }

    QTextStream stream(file);
    //设置打开流的文件编码
    stream.setCodec(codecName.toLocal8Bit().data());
    while(!stream.atEnd()){
        append(stream.readLine());
    }
    file->close();
}

void SubText::onContentsChanged()
{
    setWindowModified(true);
}
