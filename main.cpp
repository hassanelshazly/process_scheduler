#include <QApplication>
#include <QQuickView>
#include <QQuickItem>
#include <QDebug>

#include "model/job.h"
#include "model/timeline.h"

int main(int argc, char *argv[])
{
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif

    QApplication app(argc, argv);

    TimelineModel timelineModel;
    JobModel jobModel;

    QQuickView view;
    view.setResizeMode(QQuickView::SizeRootObjectToView);
    view.setInitialProperties({{"timelineModel", QVariant::fromValue(&timelineModel)},
                               {"jobModel", QVariant::fromValue(&jobModel)}});
    view.setSource(QUrl(QStringLiteral("qrc:main.qml")));

    //    QObject *item = view.rootObject();
    //    QObject::connect(item, SIGNAL(addSignal()),
    //                     &job_controller, SLOT(addSlot()));

    view.show();
    return app.exec();
}
