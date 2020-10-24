#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>
#include <QtCharts/QChart>

#include "helpdialog.h"
#include "Widgets/resultschart.h"

namespace Ui {
    class MainWindow;
}

QT_CHARTS_USE_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

    Ui::MainWindow *ui;
    HelpDialog *mHelpDialog;
    ResultsChart mChart;
    void generateSeed();

public:
    enum Tab {
        FIXED_RATE,
        VARIATING_RATE
    };

    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void clearResults();
    void resetSettings();

    // Getters
    MainWindow::Tab getTab() const;

    int getQueueSize() const;
    int getMaxIterations() const;
    double getLambda() const;
    double getMu() const;
    int getRandSeed() const;
    int getTimeUnit() const;

    double getLambdaMean() const;
    double getLambdaStdDev() const;
    double getMuMean() const;
    double getMuStdDev() const;
    int getLambdaPop() const;
    int getMuPop() const;

    // Setters
    void setChartData(const ResultsChart::SetData &);
    void setSimTotals(int arrivals, int a_arrivals, int r_arrivals, int total_served,
                      int total_depart, int queue_size, int queue_empty);
    void setSimTimeTotals(double system_wait, double queue_wait, double service_time);
    void setSimAvg(double queue_size, double queue_wait, double service_time, double wait_time);

    void setMaxIterations(int);
    void setLambda(double);
    void setMu(double);
    void setRandSeed(int);
    void addRowResultTable(const QStringList&);

    void setLambdaMean(double);
    void setLambdaStdDev(double);
    void setMuMean(double);
    void setMuStdDev(double);
    void setLambdaPop(int);
    void setMuPop(int);

private slots:
    void on_btnRun_pressed();
    void on_btnReset_pressed();
    void on_action_Quit_triggered();

    void on_spnLambda_valueChanged(double arg1);
    void on_spnMu_valueChanged(double arg1);
    void on_sldLambda_sliderMoved(int position);
    void on_sldMu_sliderMoved(int position);

    void on_actionContents_triggered();
    void on_actionOpen_triggered();
    void on_actionSave_triggered();
    void on_actionSave_As_triggered();
    void on_action_New_triggered();

signals:
    void run();
    void formReset();
    void newFile(QString);
    void open(QString);
    void save();
    void saveAs(QString);
};

#endif // MAINWINDOW_H
