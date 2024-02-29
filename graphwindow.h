#ifndef GRAPHWINDOW_H
#define GRAPHWINDOW_H

#include <QDialog>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; class GraphWindow;}
QT_END_NAMESPACE

class GraphWindow : public QDialog
{
    Q_OBJECT

public:
    explicit GraphWindow(QWidget *parent = nullptr);
    ~GraphWindow();
    Ui::GraphWindow *ui;
};

#endif // GRAPHWINDOW_H
