#include "savefilemanager.h"

#include <QDebug>
#include <QJsonDocument>
#include <QJsonObject>
#include <QVariantHash>

QHash<SaveFileManager::Data, QString> SaveFileManager::mDataString = {
    {SaveFileManager::TIME_UNIT, "time_unit"},
    {SaveFileManager::MAX_ITERATIONS, "max_iterations"},
    {SaveFileManager::RAND_SEED, "rand_seed"},
    {SaveFileManager::FIXED_LAMBDA, "fixed_lambda"},
    {SaveFileManager::FIXED_MU, "fixed_mu"},
    {SaveFileManager::LAMBDA_MEAN, "lambda_mean"},
    {SaveFileManager::LAMBDA_STDDEV, "lambda_stddev"},
    {SaveFileManager::MU_MEAN, "mu_mean"},
    {SaveFileManager::MU_STDDEV, "mu_stddev"}
};
QHash<QString, SaveFileManager::Data> SaveFileManager::mStringData = {
    {"time_unit", SaveFileManager::TIME_UNIT},
    {"max_iterations", SaveFileManager::MAX_ITERATIONS},
    {"rand_seed", SaveFileManager::RAND_SEED},
    {"fixed_lambda", SaveFileManager::FIXED_LAMBDA},
    {"fixed_mu", SaveFileManager::FIXED_MU},
    {"lambda_mean", SaveFileManager::LAMBDA_MEAN},
    {"lambda_stddev", SaveFileManager::LAMBDA_STDDEV},
    {"mu_mean", SaveFileManager::MU_MEAN},
    {"mu_stddev", SaveFileManager::MU_STDDEV}
};

SaveFileManager::SaveFileManager()
{}
SaveFileManager::SaveFileManager(const QString &filename):
    mSaveFile(filename)
{}

bool SaveFileManager::setFilename(const QString& filename){
    if(mSaveFile.isOpen()) mSaveFile.close();

    mSaveFile.setFileName(filename);
    return mSaveFile.open(QIODevice::ReadWrite);
}
QString SaveFileManager::getFilename() const {
    return mSaveFile.fileName();
}

bool SaveFileManager::save(){
    if(!mSaveFile.isOpen()) return false;

    QVariantHash jData;

    for(auto iter = mSaveData.constKeyValueBegin();
        iter != mSaveData.constKeyValueEnd(); ++iter){

        jData.insert(mDataString.value((*iter).first), (*iter).second);
    }

    QJsonDocument jDoc;
    jDoc.setObject(QJsonObject::fromVariantHash(jData));
    qDebug() << "Writing: " << jDoc.toJson();
    mSaveFile.write(jDoc.toJson());

    return true;
}

bool SaveFileManager::load(){
    reset();
    if(!mSaveFile.isOpen()) return false;

    QJsonObject jObj = QJsonDocument::fromJson(mSaveFile.readAll()).object();
    QVariantHash jData = jObj.toVariantHash();

    for(auto iter = jData.constKeyValueBegin();
        iter != jData.constKeyValueEnd(); ++iter){

        mSaveData.insert(mStringData.value((*iter).first), (*iter).second);
    }

    qDebug() << "Load: " << mSaveData;
    return true;
}

void SaveFileManager::reset(){ mSaveData.clear(); }
void SaveFileManager::setItem(SaveFileManager::Data key, const QVariant &value){
    mSaveData.insert(key, value);
}

