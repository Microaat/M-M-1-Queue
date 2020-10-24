#ifndef SAVEFILEMANAGER_H
#define SAVEFILEMANAGER_H

#include <QString>
#include <QFile>
#include <QHash>
#include <QVariant>

class SaveFileManager {

public:
    enum Data {
        TIME_UNIT,
        MAX_ITERATIONS,
        RAND_SEED,
        FIXED_LAMBDA,
        FIXED_MU,
        LAMBDA_MEAN,
        LAMBDA_STDDEV,
        MU_MEAN,
        MU_STDDEV
    };

    typedef QHash<SaveFileManager::Data, QVariant> SaveDataHash;

    SaveFileManager();
    SaveFileManager(const QString &filename);

    bool setFilename(const QString &filename);
    QString getFilename() const;

    //! Returns true if file is open, otherwise returns false.
    bool fileStatus() const { return mSaveFile.isOpen(); }

    bool save();
    bool load();

    //! Clears all items in
    void reset();
    void setItem(Data key, const QVariant &value);
    QVariant getItem(Data key) const { return mSaveData.value(key); }
    const SaveDataHash& getItems() const { return mSaveData; }

private:
    static QHash<SaveFileManager::Data, QString> mDataString;
    static QHash<QString, SaveFileManager::Data> mStringData;

    QFile mSaveFile;
    SaveDataHash mSaveData;
};

#endif // SAVEFILEMANAGER_H
