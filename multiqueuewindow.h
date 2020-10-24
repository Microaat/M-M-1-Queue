#ifndef MULTIQUEUEWINDOW_H
#define MULTIQUEUEWINDOW_H

#include <QMainWindow>

namespace Ui {
class MultiQueueWindow;
}

class MultiQueueWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MultiQueueWindow(QWidget *parent = 0);
    ~MultiQueueWindow();

private:
    Ui::MultiQueueWindow *ui;
};

#endif // MULTIQUEUEWINDOW_H
