/****************************************************************************
** Meta object code from reading C++ file 'picpro.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../picpro.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'picpro.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_picPro_t {
    QByteArrayData data[61];
    char stringdata[1342];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_picPro_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_picPro_t qt_meta_stringdata_picPro = {
    {
QT_MOC_LITERAL(0, 0, 6), // "picPro"
QT_MOC_LITERAL(1, 7, 12), // "harrisSignal"
QT_MOC_LITERAL(2, 20, 0), // ""
QT_MOC_LITERAL(3, 21, 5), // "value"
QT_MOC_LITERAL(4, 27, 27), // "on_CloseImageButton_clicked"
QT_MOC_LITERAL(5, 55, 23), // "OpenImageButton_clicked"
QT_MOC_LITERAL(6, 79, 23), // "on_actionOpen_triggered"
QT_MOC_LITERAL(7, 103, 25), // "on_actionCamera_triggered"
QT_MOC_LITERAL(8, 129, 23), // "on_actionSave_triggered"
QT_MOC_LITERAL(9, 153, 25), // "on_actionSaveAs_triggered"
QT_MOC_LITERAL(10, 179, 11), // "std::string"
QT_MOC_LITERAL(11, 191, 25), // "on_opSlider1_valueChanged"
QT_MOC_LITERAL(12, 217, 21), // "on_opText1_textEdited"
QT_MOC_LITERAL(13, 239, 25), // "on_opSlider2_valueChanged"
QT_MOC_LITERAL(14, 265, 21), // "on_opText2_textEdited"
QT_MOC_LITERAL(15, 287, 25), // "on_actionResize_triggered"
QT_MOC_LITERAL(16, 313, 4), // "flag"
QT_MOC_LITERAL(17, 318, 4), // "scal"
QT_MOC_LITERAL(18, 323, 27), // "on_actionRotation_triggered"
QT_MOC_LITERAL(19, 351, 5), // "angle"
QT_MOC_LITERAL(20, 357, 27), // "on_actionDilation_triggered"
QT_MOC_LITERAL(21, 385, 24), // "on_actionErode_triggered"
QT_MOC_LITERAL(22, 410, 23), // "on_actionBlur_triggered"
QT_MOC_LITERAL(23, 434, 31), // "on_actionGaussianBlur_triggered"
QT_MOC_LITERAL(24, 466, 29), // "on_actionMedianBlur_triggered"
QT_MOC_LITERAL(25, 496, 32), // "on_actionBilateralBlur_triggered"
QT_MOC_LITERAL(26, 529, 25), // "on_actionBinary_triggered"
QT_MOC_LITERAL(27, 555, 9), // "threshold"
QT_MOC_LITERAL(28, 565, 28), // "on_actionBinaryInv_triggered"
QT_MOC_LITERAL(29, 594, 24), // "on_actionTrunc_triggered"
QT_MOC_LITERAL(30, 619, 25), // "on_actionTozero_triggered"
QT_MOC_LITERAL(31, 645, 28), // "on_actionTozeroInv_triggered"
QT_MOC_LITERAL(32, 674, 32), // "on_actionAutoThreshold_triggered"
QT_MOC_LITERAL(33, 707, 24), // "on_actionSobel_triggered"
QT_MOC_LITERAL(34, 732, 26), // "on_actionLaplace_triggered"
QT_MOC_LITERAL(35, 759, 24), // "on_actionCanny_triggered"
QT_MOC_LITERAL(36, 784, 12), // "lowThreshold"
QT_MOC_LITERAL(37, 797, 25), // "on_actionHarris_triggered"
QT_MOC_LITERAL(38, 823, 6), // "thresh"
QT_MOC_LITERAL(39, 830, 28), // "on_actionShiTomasi_triggered"
QT_MOC_LITERAL(40, 859, 12), // "FeaturePoint"
QT_MOC_LITERAL(41, 872, 12), // "FeatureMatch"
QT_MOC_LITERAL(42, 885, 31), // "on_actionObjectDetect_triggered"
QT_MOC_LITERAL(43, 917, 25), // "on_actionHARRIS_triggered"
QT_MOC_LITERAL(44, 943, 23), // "on_actionSURF_triggered"
QT_MOC_LITERAL(45, 967, 23), // "on_actionSIFT_triggered"
QT_MOC_LITERAL(46, 991, 23), // "on_actionFAST_triggered"
QT_MOC_LITERAL(47, 1015, 22), // "on_actionORB_triggered"
QT_MOC_LITERAL(48, 1038, 23), // "on_actionMSER_triggered"
QT_MOC_LITERAL(49, 1062, 23), // "on_actionSTAR_triggered"
QT_MOC_LITERAL(50, 1086, 32), // "on_actionExtractorSIFT_triggered"
QT_MOC_LITERAL(51, 1119, 32), // "on_actionExtractorSURF_triggered"
QT_MOC_LITERAL(52, 1152, 29), // "on_actionFlannBased_triggered"
QT_MOC_LITERAL(53, 1182, 29), // "on_actionBruteForce_triggered"
QT_MOC_LITERAL(54, 1212, 28), // "on_actionBestMatch_triggered"
QT_MOC_LITERAL(55, 1241, 27), // "on_actionKnnMatch_triggered"
QT_MOC_LITERAL(56, 1269, 16), // "featureExtractor"
QT_MOC_LITERAL(57, 1286, 4), // "Mat&"
QT_MOC_LITERAL(58, 1291, 5), // "image"
QT_MOC_LITERAL(59, 1297, 31), // "on_actionTempletMatch_triggered"
QT_MOC_LITERAL(60, 1329, 12) // "featureMatch"

    },
    "picPro\0harrisSignal\0\0value\0"
    "on_CloseImageButton_clicked\0"
    "OpenImageButton_clicked\0on_actionOpen_triggered\0"
    "on_actionCamera_triggered\0"
    "on_actionSave_triggered\0"
    "on_actionSaveAs_triggered\0std::string\0"
    "on_opSlider1_valueChanged\0"
    "on_opText1_textEdited\0on_opSlider2_valueChanged\0"
    "on_opText2_textEdited\0on_actionResize_triggered\0"
    "flag\0scal\0on_actionRotation_triggered\0"
    "angle\0on_actionDilation_triggered\0"
    "on_actionErode_triggered\0"
    "on_actionBlur_triggered\0"
    "on_actionGaussianBlur_triggered\0"
    "on_actionMedianBlur_triggered\0"
    "on_actionBilateralBlur_triggered\0"
    "on_actionBinary_triggered\0threshold\0"
    "on_actionBinaryInv_triggered\0"
    "on_actionTrunc_triggered\0"
    "on_actionTozero_triggered\0"
    "on_actionTozeroInv_triggered\0"
    "on_actionAutoThreshold_triggered\0"
    "on_actionSobel_triggered\0"
    "on_actionLaplace_triggered\0"
    "on_actionCanny_triggered\0lowThreshold\0"
    "on_actionHarris_triggered\0thresh\0"
    "on_actionShiTomasi_triggered\0FeaturePoint\0"
    "FeatureMatch\0on_actionObjectDetect_triggered\0"
    "on_actionHARRIS_triggered\0"
    "on_actionSURF_triggered\0on_actionSIFT_triggered\0"
    "on_actionFAST_triggered\0on_actionORB_triggered\0"
    "on_actionMSER_triggered\0on_actionSTAR_triggered\0"
    "on_actionExtractorSIFT_triggered\0"
    "on_actionExtractorSURF_triggered\0"
    "on_actionFlannBased_triggered\0"
    "on_actionBruteForce_triggered\0"
    "on_actionBestMatch_triggered\0"
    "on_actionKnnMatch_triggered\0"
    "featureExtractor\0Mat&\0image\0"
    "on_actionTempletMatch_triggered\0"
    "featureMatch"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_picPro[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      67,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,  349,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    0,  352,    2, 0x08 /* Private */,
       5,    0,  353,    2, 0x08 /* Private */,
       6,    0,  354,    2, 0x08 /* Private */,
       7,    0,  355,    2, 0x08 /* Private */,
       8,    0,  356,    2, 0x08 /* Private */,
       9,    0,  357,    2, 0x08 /* Private */,
      11,    1,  358,    2, 0x08 /* Private */,
      12,    1,  361,    2, 0x08 /* Private */,
      13,    1,  364,    2, 0x08 /* Private */,
      14,    1,  367,    2, 0x08 /* Private */,
      15,    2,  370,    2, 0x08 /* Private */,
      15,    1,  375,    2, 0x28 /* Private | MethodCloned */,
      15,    0,  378,    2, 0x28 /* Private | MethodCloned */,
      18,    2,  379,    2, 0x08 /* Private */,
      18,    1,  384,    2, 0x28 /* Private | MethodCloned */,
      18,    0,  387,    2, 0x28 /* Private | MethodCloned */,
      20,    1,  388,    2, 0x08 /* Private */,
      20,    0,  391,    2, 0x28 /* Private | MethodCloned */,
      21,    1,  392,    2, 0x08 /* Private */,
      21,    0,  395,    2, 0x28 /* Private | MethodCloned */,
      22,    1,  396,    2, 0x08 /* Private */,
      22,    0,  399,    2, 0x28 /* Private | MethodCloned */,
      23,    1,  400,    2, 0x08 /* Private */,
      23,    0,  403,    2, 0x28 /* Private | MethodCloned */,
      24,    1,  404,    2, 0x08 /* Private */,
      24,    0,  407,    2, 0x28 /* Private | MethodCloned */,
      25,    1,  408,    2, 0x08 /* Private */,
      25,    0,  411,    2, 0x28 /* Private | MethodCloned */,
      26,    1,  412,    2, 0x08 /* Private */,
      26,    0,  415,    2, 0x28 /* Private | MethodCloned */,
      28,    1,  416,    2, 0x08 /* Private */,
      28,    0,  419,    2, 0x28 /* Private | MethodCloned */,
      29,    1,  420,    2, 0x08 /* Private */,
      29,    0,  423,    2, 0x28 /* Private | MethodCloned */,
      30,    1,  424,    2, 0x08 /* Private */,
      30,    0,  427,    2, 0x28 /* Private | MethodCloned */,
      31,    1,  428,    2, 0x08 /* Private */,
      31,    0,  431,    2, 0x28 /* Private | MethodCloned */,
      32,    0,  432,    2, 0x08 /* Private */,
      33,    0,  433,    2, 0x08 /* Private */,
      34,    0,  434,    2, 0x08 /* Private */,
      35,    1,  435,    2, 0x08 /* Private */,
      35,    0,  438,    2, 0x28 /* Private | MethodCloned */,
      37,    1,  439,    2, 0x08 /* Private */,
      37,    0,  442,    2, 0x28 /* Private | MethodCloned */,
      39,    0,  443,    2, 0x08 /* Private */,
      40,    0,  444,    2, 0x08 /* Private */,
      41,    0,  445,    2, 0x08 /* Private */,
      42,    0,  446,    2, 0x08 /* Private */,
      43,    0,  447,    2, 0x08 /* Private */,
      44,    0,  448,    2, 0x08 /* Private */,
      45,    0,  449,    2, 0x08 /* Private */,
      46,    0,  450,    2, 0x08 /* Private */,
      47,    0,  451,    2, 0x08 /* Private */,
      48,    0,  452,    2, 0x08 /* Private */,
      49,    0,  453,    2, 0x08 /* Private */,
      50,    0,  454,    2, 0x08 /* Private */,
      51,    0,  455,    2, 0x08 /* Private */,
      52,    0,  456,    2, 0x08 /* Private */,
      53,    0,  457,    2, 0x08 /* Private */,
      54,    0,  458,    2, 0x08 /* Private */,
      55,    0,  459,    2, 0x08 /* Private */,
      56,    1,  460,    2, 0x08 /* Private */,
      59,    0,  463,    2, 0x08 /* Private */,
      60,    1,  464,    2, 0x08 /* Private */,
      60,    0,  467,    2, 0x28 /* Private | MethodCloned */,

 // signals: parameters
    QMetaType::Void, QMetaType::Double,    3,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    0x80000000 | 10,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::Int, QMetaType::Double,   16,   17,
    QMetaType::Void, QMetaType::Int,   16,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Double, QMetaType::Double,   19,   17,
    QMetaType::Void, QMetaType::Double,   19,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   27,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   27,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   27,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   27,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   27,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   36,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   38,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 57,   58,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   16,
    QMetaType::Void,

       0        // eod
};

void picPro::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        picPro *_t = static_cast<picPro *>(_o);
        switch (_id) {
        case 0: _t->harrisSignal((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 1: _t->on_CloseImageButton_clicked(); break;
        case 2: _t->OpenImageButton_clicked(); break;
        case 3: _t->on_actionOpen_triggered(); break;
        case 4: _t->on_actionCamera_triggered(); break;
        case 5: _t->on_actionSave_triggered(); break;
        case 6: { std::string _r = _t->on_actionSaveAs_triggered();
            if (_a[0]) *reinterpret_cast< std::string*>(_a[0]) = _r; }  break;
        case 7: _t->on_opSlider1_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: _t->on_opText1_textEdited((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 9: _t->on_opSlider2_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 10: _t->on_opText2_textEdited((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 11: _t->on_actionResize_triggered((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2]))); break;
        case 12: _t->on_actionResize_triggered((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 13: _t->on_actionResize_triggered(); break;
        case 14: _t->on_actionRotation_triggered((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2]))); break;
        case 15: _t->on_actionRotation_triggered((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 16: _t->on_actionRotation_triggered(); break;
        case 17: _t->on_actionDilation_triggered((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 18: _t->on_actionDilation_triggered(); break;
        case 19: _t->on_actionErode_triggered((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 20: _t->on_actionErode_triggered(); break;
        case 21: _t->on_actionBlur_triggered((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 22: _t->on_actionBlur_triggered(); break;
        case 23: _t->on_actionGaussianBlur_triggered((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 24: _t->on_actionGaussianBlur_triggered(); break;
        case 25: _t->on_actionMedianBlur_triggered((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 26: _t->on_actionMedianBlur_triggered(); break;
        case 27: _t->on_actionBilateralBlur_triggered((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 28: _t->on_actionBilateralBlur_triggered(); break;
        case 29: _t->on_actionBinary_triggered((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 30: _t->on_actionBinary_triggered(); break;
        case 31: _t->on_actionBinaryInv_triggered((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 32: _t->on_actionBinaryInv_triggered(); break;
        case 33: _t->on_actionTrunc_triggered((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 34: _t->on_actionTrunc_triggered(); break;
        case 35: _t->on_actionTozero_triggered((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 36: _t->on_actionTozero_triggered(); break;
        case 37: _t->on_actionTozeroInv_triggered((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 38: _t->on_actionTozeroInv_triggered(); break;
        case 39: _t->on_actionAutoThreshold_triggered(); break;
        case 40: _t->on_actionSobel_triggered(); break;
        case 41: _t->on_actionLaplace_triggered(); break;
        case 42: _t->on_actionCanny_triggered((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 43: _t->on_actionCanny_triggered(); break;
        case 44: _t->on_actionHarris_triggered((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 45: _t->on_actionHarris_triggered(); break;
        case 46: _t->on_actionShiTomasi_triggered(); break;
        case 47: _t->FeaturePoint(); break;
        case 48: _t->FeatureMatch(); break;
        case 49: _t->on_actionObjectDetect_triggered(); break;
        case 50: _t->on_actionHARRIS_triggered(); break;
        case 51: _t->on_actionSURF_triggered(); break;
        case 52: _t->on_actionSIFT_triggered(); break;
        case 53: _t->on_actionFAST_triggered(); break;
        case 54: _t->on_actionORB_triggered(); break;
        case 55: _t->on_actionMSER_triggered(); break;
        case 56: _t->on_actionSTAR_triggered(); break;
        case 57: _t->on_actionExtractorSIFT_triggered(); break;
        case 58: _t->on_actionExtractorSURF_triggered(); break;
        case 59: _t->on_actionFlannBased_triggered(); break;
        case 60: _t->on_actionBruteForce_triggered(); break;
        case 61: _t->on_actionBestMatch_triggered(); break;
        case 62: _t->on_actionKnnMatch_triggered(); break;
        case 63: _t->featureExtractor((*reinterpret_cast< Mat(*)>(_a[1]))); break;
        case 64: _t->on_actionTempletMatch_triggered(); break;
        case 65: _t->featureMatch((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 66: _t->featureMatch(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (picPro::*_t)(double );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&picPro::harrisSignal)) {
                *result = 0;
            }
        }
    }
}

const QMetaObject picPro::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_picPro.data,
      qt_meta_data_picPro,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *picPro::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *picPro::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_picPro.stringdata))
        return static_cast<void*>(const_cast< picPro*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int picPro::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 67)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 67;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 67)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 67;
    }
    return _id;
}

// SIGNAL 0
void picPro::harrisSignal(double _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
