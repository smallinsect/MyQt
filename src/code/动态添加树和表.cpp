    QTreeWidget *tree = new QTreeWidget();
    tree->setHeaderLabels(QStringList()<<"标题"<<"描述");

    QTreeWidgetItem *title1 = new QTreeWidgetItem(QStringList()<<"斗神");
    QTreeWidgetItem *title2 = new QTreeWidgetItem(QStringList()<<"斗尊");
    tree->addTopLevelItem(title1);
    tree->addTopLevelItem(title2);

//    ui->mdiArea->addSubWindow(tree);
//    tree->show();

    QTableWidget *table = new QTableWidget();
    table->setColumnCount(2);
    table->setHorizontalHeaderLabels(QStringList()<<"斗帝"<<"斗者");

//    ui->mdiArea->addSubWindow(table);
//    table->show();

//    QMdiArea *sub = new QMdiArea();
//    sub->addSubWindow(tree);
//    sub->addSubWindow(table);

//    QHBoxLayout *hLayout = new QHBoxLayout();
//    hLayout->addWidget(tree);
//    hLayout->addWidget(table);

    QWidget *widget = new QWidget();
//    QFrame *frame = new QFrame();
    QHBoxLayout *hLayout = new QHBoxLayout();
    hLayout->addWidget(tree);
    hLayout->addWidget(table);
    widget->setLayout(hLayout);

    QMdiSubWindow *msub = ui->mdiArea->addSubWindow(widget);
    msub->show();
    tree->show();
    table->show();