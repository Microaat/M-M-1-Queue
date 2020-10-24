#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDebug>
#include <QRandomGenerator>
#include <QTime>
#include <QIntValidator>
#include <QStringList>
#include <QFileDialog>
#include <QDir>

#include <QtCharts/QLineSeries>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QLegend>
#include <QtCharts/QBarCategoryAxis>

QT_CHARTS_USE_NAMESPACE

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    mHelpDialog(new HelpDialog)
{
    ui->setupUi(this);

    generateSeed();
    QValidator *intVal = new QIntValidator(1, 9999999999L, this);
    ui->txtSeed->setValidator(intVal);

    ui->chartResult->setChart(mChart.getChart());
}

MainWindow::~MainWindow(){ delete ui; }

void MainWindow::clearResults(){
    ui->tblResults->setRowCount(0);
}


// Getters
MainWindow::Tab MainWindow::getTab() const {
    return static_cast<Tab>(ui->tabRateTypes->currentIndex());
}

int MainWindow::getQueueSize() const { return ui->spnQueueSize->value(); }
int MainWindow::getMaxIterations() const { return ui->spnMaxIterations->value(); }
double MainWindow::getLambda() const { return ui->spnLambda->value(); }
double MainWindow::getMu() const { return ui->spnMu->value(); }
int MainWindow::getRandSeed() const { return ui->txtSeed->text().toInt(); }
int MainWindow::getTimeUnit() const { return ui->cmbTimeUnits->currentIndex(); }

double MainWindow::getLambdaMean() const { return ui->spnLambdaMean->value(); }
double MainWindow::getLambdaStdDev() const { return ui->spnLambdaStdDev->value(); }
double MainWindow::getMuMean() const { return ui->spnMuMean->value(); }
double MainWindow::getMuStdDev() const { return ui->spnMuStdDev->value(); }
int MainWindow::getLambdaPop() const { return ui->spnLambdaPop->value(); }
int MainWindow::getMuPop() const { return ui->spnMuPop->value(); }


// Setters
void MainWindow::setChartData(const ResultsChart::SetData &data){
    mChart.setSetData(data);
    mChart.createChart();
}


void MainWindow::setSimTotals(int arrivals, int a_arrivals, int r_arrivals, int total_served,
                              int total_depart, int queue_size, int queue_empty){

    // Using fixed rates
    double lambda;
    double mu;
    if(ui->tabRateTypes->currentIndex() == 0){
        lambda = getLambda();
        mu = getMu();
    } else {
        lambda = getLambdaMean();
        mu = getMuMean();
    }
    ui->lblUtilization->setText(QString::number((lambda / mu) * 100.0).append(" %"));

    ui->lblTotalArrivals->setText(QString::number(arrivals));
    ui->lblTotalArrivalsAccepted->setText(QString::number(a_arrivals));
    ui->lblTotalArrivalsRejected->setText(QString::number(r_arrivals));
    ui->lblTotalServed->setText(QString::number(total_served));
    ui->lblTotalDepartures->setText(QString::number(total_depart));
    ui->lblTotalQueueSize->setText(QString::number(queue_size));
    ui->lblTotalQueueEmpty->setText(QString::number(queue_empty));
}

void MainWindow::setSimTimeTotals(double system_wait, double queue_wait, double service_time){
    ui->lblTotalWaitTime->setText(QString::number(system_wait));
    ui->lblQueueWaitTime->setText(QString::number(queue_wait));
    ui->lblServingDuration->setText(QString::number(service_time));
}
void MainWindow::setSimAvg(double queue_size, double queue_wait, double service_time, double wait_time){
    ui->lblMeanQueueSize->setText(QString::number(queue_size));
    ui->lblMeanQueueWait->setText(QString::number(queue_wait));
    ui->lblMeanServingDuration->setText(QString::number(service_time));
    ui->lblMeanWaitTime->setText(QString::number(wait_time));
}


void MainWindow::setMaxIterations(int value){ ui->spnMaxIterations->setValue(value); }
void MainWindow::setLambda(double value){ ui->spnLambda->setValue(value); }
void MainWindow::setMu(double value){ ui->spnMu->setValue(value); }
void MainWindow::setRandSeed(int value){ ui->txtSeed->setText(QString::number(value)); }

void MainWindow::setLambdaMean(double value){ ui->spnLambdaMean->setValue(value); }
void MainWindow::setLambdaStdDev(double value){ ui->spnLambdaStdDev->setValue(value); }
void MainWindow::setMuMean(double value){ ui->spnMuMean->setValue(value); }
void MainWindow::setMuStdDev(double value){ ui->spnMuStdDev->setValue(value); }
void MainWindow::setLambdaPop(int value){ ui->spnLambdaPop->setValue(value); }
void MainWindow::setMuPop(int value){ ui->spnMuPop->setValue(value); }

void MainWindow::addRowResultTable(const QStringList & r){
    ui->tblResults->setRowCount(ui->tblResults->rowCount() + 1);

    auto col = 0;
    auto curr_row = ui->tblResults->rowCount() - 1;

    for(auto iter = r.begin(); iter != r.end(); ++iter ){
        if(col >= ui->tblResults->columnCount()){
            qDebug() << "Number of columns greater than table columns. Skipping";
            break;
        }

        // Create a table widget item to be inserted to the result table.
        QTableWidgetItem *cell = new QTableWidgetItem(*iter);
        cell->setTextAlignment(Qt::AlignHCenter | Qt::AlignCenter);

        // Check if it's an even row. If so, then change the background color.
        if(!(curr_row & 1)) cell->setBackground(QBrush(QColor("#F7F7F7")));

        ui->tblResults->setItem(curr_row, col++, cell);
    }
}

// Slots
void MainWindow::on_spnLambda_valueChanged(double arg1){ ui->sldLambda->setValue(static_cast<int>(arg1)); }
void MainWindow::on_spnMu_valueChanged(double arg1){ ui->sldMu->setValue(static_cast<int>(arg1)); }
void MainWindow::on_sldLambda_sliderMoved(int position){ ui->spnLambda->setValue(position); }
void MainWindow::on_sldMu_sliderMoved(int position){ ui->spnMu->setValue(position); }

void MainWindow::on_btnRun_pressed(){
    // Check if we need to generate a random number.
    if(ui->checkNewSeed->isChecked()) generateSeed();

    emit run();
}
void MainWindow::on_btnReset_pressed(){
    setLambda(0.0);
    setMu(0.0);
    setMaxIterations(1);

    setLambdaMean(0.0);
    setLambdaStdDev(0.0);
    setMuMean(0.0);
    setMuStdDev(0.0);

    setLambdaPop(1);
    setMuPop(1);

    emit formReset();
}

// Closes the program
void MainWindow::on_action_Quit_triggered(){ close(); }
void MainWindow::generateSeed(){
    // When the program starts, generate a seed to use for the random number generator.
    ui->txtSeed->setText(QString::number(QRandomGenerator::global()->generate()));
}

// Actions
void MainWindow::on_actionContents_triggered(){ mHelpDialog->show(); }
void MainWindow::on_actionOpen_triggered(){
    QString filename = QFileDialog::getOpenFileName(
        this, tr("Open File"),
        QDir::currentPath(),
        tr("JSON File (*.json)")
    );
    qDebug() << filename;
    emit saveAs(filename);

    emit open(filename);
}
void MainWindow::on_actionSave_triggered(){ emit save(); }
void MainWindow::on_actionSave_As_triggered(){
    QString filename = QFileDialog::getSaveFileName(
        this, tr("Save As"),
        QDir::currentPath(),
        tr("JSON File (*.json)")
    );
    qDebug() << filename;
    emit saveAs(filename);
}

void MainWindow::on_action_New_triggered(){
    QString filename = QFileDialog::getSaveFileName(
        this, tr("New File"),
        QDir::currentPath(),
        tr("JSON File (*.json)")
    );
    emit newFile(filename);
}
