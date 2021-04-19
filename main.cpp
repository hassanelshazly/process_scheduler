#include <QGuiApplication>
#include <QQuickView>
#include <QQuickItem>
#include <iostream>

#include "model.h"
#include "controller.h"
#include "scheduler.h"

void test_algorthim() {
    Scheduler sc;

    Job j1("A", 0, 7, 1, 0);
    Job j2("D", 0, 2, 4, 0);
    Job j3("B", 0, 4, 2, 0);
    Job j4("C", 0, 1, 3, 0);

    QList<Job> input = {j1, j2, j3, j4};
    sc.add_job(j1).add_job(j2).add_job(j3).add_job(j4);

    QList<Job> output = sc.sjf_preemptive();

    std::cout << "Input Jobs\n";
    for(Job& j : input)
        std::cout << j << std::endl;

    std::cout << "Output Jobs\n";
    for(Job& j : output)
        std::cout << j << std::endl;
    std::cout << sc.average_waiting_time(output) << std::endl;
}

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
    test_algorthim();

    view.show();
    return app.exec();
}
