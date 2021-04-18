#include <QGuiApplication>
#include <QQuickView>
#include <QQuickItem>

#include "model.h"
#include "controller.h"

int main(int argc, char *argv[])
{
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif

    QGuiApplication app(argc, argv);

    JobController job_controller;

    QQuickView view;
    view.setResizeMode(QQuickView::SizeRootObjectToView);
    view.setInitialProperties({{"model", QVariant::fromValue(job_controller.model())}});
    view.setSource(QUrl(QStringLiteral("qrc:main.qml")));

    QObject *item = view.rootObject();
    QObject::connect(item, SIGNAL(addSignal()),
                     &job_controller, SLOT(addSlot()));


    view.show();
    return app.exec();
}
