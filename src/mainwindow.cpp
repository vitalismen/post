#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    this->resize(1300, 700);
    this->setWindowTitle("Регистрация входящих и исходящих писем");
        this->setWindowIcon(QIcon(":/images/KlogoS.png"));
    settings& set = settings::getInatance();
        QSqlDatabase& db = set.get_db();

    _prin = new proxy_in(&db);
    _prout = new proxy_out(&db);
    _inmodel = new my_model_in(_prin);
    _outmodel = new my_model_out(_prout);
    _main_area = new QMdiArea(this);
    QMdiSubWindow* in_sub = new QMdiSubWindow(_main_area);
    QMdiSubWindow* out_sub = new QMdiSubWindow(_main_area);
    _inview = new my_view(in_sub);
    _inview->setWindowTitle("Входящие документы");
    _outview = new my_view(out_sub);
    _outview->setWindowTitle("Исходящие документы");
    QSortFilterProxyModel *in_pr_model = new QSortFilterProxyModel();
    QSortFilterProxyModel *out_pr_model = new QSortFilterProxyModel();
    in_pr_model->setSourceModel(_inmodel);
    out_pr_model->setSourceModel(_outmodel);
    _inview->setModel(in_pr_model);
    _outview->setModel(out_pr_model);
    _inview->setSortingEnabled(true);
    _outview->setSortingEnabled(true);
    this->setCentralWidget(_main_area);
    in_sub->setWidget(_inview);
    out_sub->setWidget(_outview);
    in_sub->setWindowTitle("Входящие документы");
    out_sub->setWindowTitle("Исходящие документы");
    _main_area->setViewMode(QMdiArea::TabbedView);
    _main_area->addSubWindow(in_sub);
    _main_area->addSubWindow(out_sub);

    QList<QMdiSubWindow*> tmp_window = _main_area->subWindowList();
    tmp_window.at(0)->setWindowIcon(QIcon(":/images/cloud_upload.png"));
    tmp_window.at(1)->setWindowIcon(QIcon(":/images/cloud_download.png"));
    _inview->setColumnWidth(0, 130);
    _inview->setColumnWidth(1, 130);
    _inview->setColumnWidth(2, 100);
    _inview->setColumnWidth(3, 200);
    _inview->setColumnWidth(4, 170);
    _inview->setColumnWidth(5, 170);
    _inview->setColumnWidth(6, 100);
    _inview->setColumnWidth(7, 170);
    _inview->horizontalHeader()->setStretchLastSection(true);
    _outview->setColumnWidth(0, 160);
    _outview->setColumnWidth(1, 160);
    _outview->setColumnWidth(2, 220);
    _outview->setColumnWidth(3, 200);
    _outview->setColumnWidth(4, 200);
    _outview->setColumnWidth(5, 200);
    _outview->horizontalHeader()->setStretchLastSection(true);
    QObject::connect(_main_area, SIGNAL(subWindowActivated(QMdiSubWindow*)), this, SLOT(slot_active_window()));

    _act_add = new QAction(nullptr);
    _act_filtr = new QAction(nullptr);
    _act_about = new QAction(nullptr);
    _act_print = new QAction(nullptr);
    _act_close_filtr = new QAction(nullptr);
    _act_add->setIcon(QIcon(":/images/folder-add.png"));
    _act_add->setToolTip("Добавить документ");
    _act_filtr->setIcon(QIcon(":/images/zoom.png"));
    _act_filtr->setToolTip("Найти");
    _act_close_filtr->setIcon(QIcon(":/images/times.png"));
    _act_close_filtr->setToolTip("Сбросить фильтр");
    _act_about->setIcon(QIcon(":/images/info-large.png"));
    _act_about->setToolTip("О программе");
    _act_print->setIcon(QIcon(":/images/printer.png"));
    _act_print->setToolTip("Печать");

    QObject::connect(_act_about, SIGNAL(triggered(bool)), this, SLOT(slot_about()));
    QObject::connect(_act_add, SIGNAL(triggered(bool)), this, SLOT(slot_add()));
    QObject::connect(_act_filtr, SIGNAL(triggered(bool)), this, SLOT(slot_filtr()));
    QObject::connect(_act_print, SIGNAL(triggered(bool)), this, SLOT(slot_print()));
    QObject::connect(_act_close_filtr, SIGNAL(triggered(bool)), this, SLOT(slot_close_filtr()));

    _in_work_panel = new QToolBar();
    _out_work_panel = new QToolBar();
    this->addToolBar(_in_work_panel);
    this->addToolBar(_out_work_panel);
    _in_work_panel->hide();
    _out_work_panel->hide();
    _in_work_panel->addSeparator();
    _in_work_panel->addAction(_act_add);
    _in_work_panel->addSeparator();
    _in_work_panel->addAction(_act_filtr);
    _in_work_panel->addSeparator();
    _in_work_panel->addAction(_act_close_filtr);
    _in_work_panel->addSeparator();
    _in_work_panel->addAction(_act_print);
    _in_work_panel->addSeparator();
    _in_work_panel->addAction(_act_about);
    _in_work_panel->addSeparator();
    _out_work_panel->addSeparator();
    _out_work_panel->addAction(_act_add);
    _out_work_panel->addSeparator();
    _out_work_panel->addAction(_act_filtr);
    _out_work_panel->addSeparator();
    _out_work_panel->addAction(_act_close_filtr);
    _out_work_panel->addSeparator();
    _out_work_panel->addAction(_act_print);
    _out_work_panel->addSeparator();
    _out_work_panel->addAction(_act_about);
    _out_work_panel->addSeparator();

  _inview->scrollToBottom();
  _outview->scrollToBottom();
}
MainWindow::~MainWindow()
{
    delete _prin;
    delete _prout;
    delete _inmodel;
    delete _outmodel;
    delete _inview;
    delete _outview;
  //  delete _main_area;
    delete _act_add;
    delete _act_filtr;
    delete _act_close_filtr;
    delete _act_print;
    delete _act_about;
    delete _in_work_panel;
    delete _out_work_panel;
}
void MainWindow::slot_active_window()
{
    if (_main_area->activeSubWindow() == nullptr || _main_area->activeSubWindow() == 0) return;
    if (_main_area->activeSubWindow()->windowTitle() == "Входящие документы") {
        _out_work_panel->hide();
        _in_work_panel->show();
        _type_view = "in";
    } else if (_main_area->activeSubWindow()->windowTitle() == "Исходящие документы") {
        _in_work_panel->hide();
        _out_work_panel->show();
        _type_view = "out";
    }
}
void MainWindow::slot_add()
{
    if (_type_view == "in"){
        _inview->slot_add();
    } else if (_type_view == "out"){
        _outview->slot_add();
    }
    this->slot_close_filtr();
}
void MainWindow::slot_filtr()
{
    QSortFilterProxyModel *main_filtr_model = new QSortFilterProxyModel();
    filtr* my_filter = new filtr("in");
    if (_type_view == "in"){
        my_filter->set_def("in");
        }  else if (_type_view == "out"){
                 my_filter->set_def("out");
    } else {QMessageBox::information(nullptr, "Внимание", "Не получается создать окошко фильтра");}
    if (my_filter->exec() == QDialog::Accepted){
        QRegExp my_reg_string = my_filter->result_obj_reg();
// Создаём модели посредники для поиска и сортировки
        if (my_filter->result_type() == "in"){
            main_filtr_model->setSourceModel(_inmodel);
// Модель будет для входящих
         if (my_filter->result_focus_str()){
            QString fld = my_filter->result_field();
// "Вход. Номер" - "in_nom"
            if (fld == "in_nom"){main_filtr_model->setFilterKeyColumn(0);}
// "Исх. номер" - "out_nom"
            if (fld == "out_nom"){main_filtr_model->setFilterKeyColumn(1);}
// "Отправитель" - "sender"
            if (fld == "sender"){main_filtr_model->setFilterKeyColumn(3);}
// "Содержание" - "content"
            if (fld == "content"){main_filtr_model->setFilterKeyColumn(4);}
// "Кому передан" - "recipient"
            if (fld == "recipient"){main_filtr_model->setFilterKeyColumn(5);}
// "Отв. исполнитель" - "worker"
            if (fld == "worker"){main_filtr_model->setFilterKeyColumn(7);}
         }
        main_filtr_model->setFilterRegExp(my_reg_string);

    if (!my_filter->result_focus_date()) {_inview->setModel(main_filtr_model);}
        }
     else if (my_filter->result_type() == "out") {
            main_filtr_model->setSourceModel(_outmodel);
// Модель будет для исходящих
         if (my_filter->result_focus_str()) {
            QString fld = my_filter->result_field();
// "№ фирм. бланка" - "blank"
            if (fld == "blank"){main_filtr_model->setFilterKeyColumn(0);}
// "Исх. номер" - "out_nom"
            if (fld == "out_nom"){main_filtr_model->setFilterKeyColumn(1);}
// "Адресат" - "recipient"
            if (fld == "recipient"){main_filtr_model->setFilterKeyColumn(2);}
// "Содержание" - "content"
            if (fld == "content"){main_filtr_model->setFilterKeyColumn(3);}
// "Отв. исполнитель" - "worker"
            if (fld == "worker"){main_filtr_model->setFilterKeyColumn(4);}
// "Примечание" - "notice"
            if (fld == "notice"){main_filtr_model->setFilterKeyColumn(5);}
         }
         main_filtr_model->setFilterRegExp(my_reg_string);

    if (!my_filter->result_focus_date()) {_outview->setModel(main_filtr_model);}
        }
    }
    delete my_filter;
}
void MainWindow::slot_about()
{
    QMessageBox about;
    about.setText("Регистрация документов 0.9.7 <br> Программу разработал Евгений Королёв <br> Cайт: http://kyrych.ru/44-dev/app/158-post <br> E-mail: root@kyrych.ru <br> XMPP: kyrych@xmpp.ru");
    about.setWindowIcon(QIcon(":/images/KlogoS.png"));
    about.setWindowTitle("О программе:");
    about.exec();
}
void MainWindow::slot_close_filtr()
{
    QSortFilterProxyModel *in_pr_model = new QSortFilterProxyModel();
    QSortFilterProxyModel *out_pr_model = new QSortFilterProxyModel();
    in_pr_model->setSourceModel(_inmodel);
    out_pr_model->setSourceModel(_outmodel);
    _inview->setModel(in_pr_model);
    _outview->setModel(out_pr_model);
    _inview->scrollToBottom();
    _outview->scrollToBottom();
}
void MainWindow::slot_print()
{
    my_view* view_tmp;
    if (_type_view == "in"){
        view_tmp = _inview;
    } else if (_type_view == "out"){
        view_tmp = _outview;
    } else return;

    QString strStream;
        QTextStream out(&strStream);

        const int rowCount = view_tmp->model()->rowCount();
        const int columnCount = view_tmp->model()->columnCount();

        out <<  "<html>\n"
            "<head>\n"
            "<meta Content=\"Text/html; charset=Windows-1251\">\n"
            <<  QString("<title>%1</title>\n").arg("strTitle")
            <<  "</head>\n"
            "<body bgcolor=#ffffff link=#5000A0>\n"
            "<table border=1 cellspacing=0 cellpadding=2>\n";

        // headers
        out << "<thead><tr bgcolor=#f0f0f0>";
        for (int column = 0; column < columnCount; column++)
            if (!view_tmp->isColumnHidden(column))
                out << QString("<th>%1</th>").arg(view_tmp->model()->headerData(column, Qt::Horizontal).toString());
        out << "</tr></thead>\n";

        // data table
        for (int row = 0; row < rowCount; row++) {
            out << "<tr>";
            for (int column = 0; column < columnCount; column++) {
                if (!view_tmp->isColumnHidden(column)) {
                    QString data = view_tmp->model()->data(view_tmp->model()->index(row, column)).toString().simplified();
                    out << QString("<td bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));
                }
            }
            out << "</tr>\n";
        }
        out <<  "</table>\n"
            "</body>\n"
            "</html>\n";

        QTextDocument *document = new QTextDocument();
        document->setHtml(strStream);

        QPrinter printer;

        QPrintDialog *dialog = new QPrintDialog(&printer, nullptr);
        if (dialog->exec() == QDialog::Accepted) {
            document->print(&printer);
        }
        delete document;
}
