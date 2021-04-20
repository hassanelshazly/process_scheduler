import QtQuick 2.15
import QtQuick.Layouts 1.15
import QtQuick.Controls 1.4
import QtQuick.Controls 2.15
import QtCharts 2.3

Item {
    id: root
    width: 800
    height: 600

    property var jobModel
    property var timelineModel

    GridLayout {
        anchors.fill: parent

        rows: 2
        columns: 2

        TableView {
            Layout.row: 0
            Layout.column: 0
            Layout.rowSpan: 2
            Layout.fillHeight: true
            Layout.fillWidth: true
            Layout.margins: 8

            TableViewColumn {
                role: "label"
                title: "Job"
                width: 64
            }
            TableViewColumn {
                role: "startTime"
                title: "Start Time"
                width: 96
            }
            TableViewColumn {
                role: "duration"
                title: "Duration"
                width: 96
            }

            model: root.jobModel
        }

        Flickable {
            id: charFlickabe
            width: root.width * 3/4
            height: root.height / 2

            Layout.row: 1
            Layout.column: 1
            Layout.fillWidth: true
            Layout.margins: 8

            clip: true

            contentWidth: timelineChart.width
            contentHeight: timelineChart.height

            ChartView {
                id: timelineChart

                width: 1080
                height: parent.height

                antialiasing: true
                animationOptions: ChartView.AllAnimations
                theme: ChartView.ChartThemeBrownSand
                legend.alignment: Qt.AlignBottom

                ValueAxis {
                    id: timeAxis
                    tickType: ValueAxis.TicksDynamic
                    tickInterval: 5
                }

                HorizontalStackedBarSeries {
                    id: ganttSeries

                    axisX: timeAxis
                    axisY: BarCategoryAxis { categories: ["Timeline"] }

                    labelsVisible: true
                    labelsPosition: AbstractBarSeries.LabelsCenter

                    HBarModelMapper {
                        model: root.timelineModel
                        firstBarSetRow: 0
                        lastBarSetRow: 11
                        firstColumn: 0
                        columnCount: 1

                        Component.onCompleted: {
                            const labels = root.timelineModel.labels()
                            let colorMap = {}
                            for (let i = 0; i < ganttSeries.count; i++) {
                                if (colorMap[labels[i]] === undefined) {
                                    colorMap[labels[i]] = ganttSeries.at(i).color
                                } else {
                                    ganttSeries.at(i).color = colorMap[labels[i]];
                                }
                            }
                        }
                    }
                }
            }

            ScrollBar.horizontal: ScrollBar {
                hoverEnabled: true
                active: hovered || pressed
                orientation: Qt.Horizontal
            }
        }
    }
}
